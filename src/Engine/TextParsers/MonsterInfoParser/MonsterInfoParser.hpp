#pragma once

#include "MonsterInfoParser/MonsterInfoParserGrammar.hpp"

#include "Engine/Objects/Monsters.h"
#include "Strings.h"

namespace MonsterInfoParser
{
	namespace
	{
		static const std::regex re_token_separator(R"(\t|"|\r\n|\r|\n)", std::regex::optimize);
	}

	struct Token
	{
		int Symbol = -1;
		int Rule = -1;
		std::string_view Value;
		std::vector<Token> SubTokens;
	};

	class ParserCore
	{
	public:
		bool IsEndOfStream() const
		{
			return !(_data_next < _data_end);
		}

		bool Parse(const std::string_view& data)
		{
			_token_read = false;
			_error = false;
			_error_recovery = false;
			_accept = false;

			_tokens.clear();

			_states.clear();
			_states.push_back(LALR::InitialState);

			_data = data;
			_data_next = std::begin(_data);
			_data_prev = _data_next;
			_data_end = std::end(_data);

			// TODO: initially empty stream should be OK
			if (IsEndOfStream())
				return true;

			while (!_error && !_accept)
			{
				if (!_token_read)
				{
					ReadToken();
				}

				if (!_error)
				{
					assert(_token_read);

					if (IsNoiseToken())
						DropToken();
					else
						ProcessToken();
				}
			}

			return _accept;
		}
	protected:
		using TokenSpan = std::span<Token>;

		void ReadToken()
		{
			if (IsEndOfStream())
			{
				_token = { Symbols::S_EOF, {} };
				_token_read = true;
				return;
			}

			int state = DFA::InitialState;
			auto cursor = _data_next;

			const int accept = DFA::Match(state, cursor);

			assert(cursor <= _data_end);

			if (accept < 0)
			{
				if (_error_recovery)
				{
					_error = true;
				}
				else
				{
					_error_recovery = true;

					_token = { Symbols::S_LexicalError, -1, { _data_next, cursor } };
					_token_read = true;
				}
			}
			else
			{
				_token = { accept, -1, { _data_next, cursor } };
				_token_read = true;
				_data_next = cursor;
				_error_recovery = false;
			}
		}

		void DropToken()
		{
			_token_read = false;
			_error_recovery = false;
			_data_prev = _data_next;
		}

		void ProcessToken()
		{
			const auto& state = LALR::States[_states.back()];

			auto it_action = state.find(_token.Symbol);
			if (it_action == std::end(state))
			{
				assert(_token_read);

				if (_error_recovery)
				{
					_error = true;
					__debugbreak();
				}
				else
				{
					_error_recovery = true;

					_token.Symbol = Symbols::S_LexicalError;
					_data_next = _data_prev;
				}

				return;
			}

			_error_recovery = false;
			_data_prev = _data_next;

			const auto& action = it_action->second;

			switch (action.Type)
			{
			case LALR::Action::Shift:
				Shift(action.Target);
				break;
			case LALR::Action::Reduce:
				Reduce(action.Target);
				break;
			case LALR::Action::Goto:
				// shouldn't be triggered normally
				__debugbreak();
				Goto(action.Target);
				break;
			case LALR::Action::Accept:
				Accept();
				break;
			}
		}

		void Shift(const int target)
		{
			_token_read = false;
			_states.push_back(target);
			_tokens.emplace_back(std::move(_token));
		}

		void Reduce(const int target)
		{
			const auto& rule = Rules::Rules[target];

			Token reduced
			{
				.Symbol = rule.Head,
				.Rule = target,
			};

			if (rule.SymbolCount > 0)
			{
				const TokenSpan reduce_tokens{ TokenSpan(_tokens).last(rule.SymbolCount) };

				const bool tokens_consumed = OnPreReduce(target, rule.Head, reduce_tokens);

				if (!tokens_consumed)
				{
					std::move(std::begin(reduce_tokens), std::end(reduce_tokens), std::back_inserter(reduced.SubTokens));
				}

				// hacky
				reduced.Value = { reduce_tokens.front().Value.data(), reduce_tokens.back().Value.data() + reduce_tokens.back().Value.size() };

				_tokens.resize(_tokens.size() - rule.SymbolCount);
				_states.resize(_states.size() - rule.SymbolCount);
			}
			else
			{
				assert(_token_read);

				reduced.Value = { std::begin(_token.Value), std::begin(_token.Value) };
			}

			_tokens.emplace_back(std::move(reduced));

			{
				const auto& state = LALR::States[_states.back()];

				auto it_action = state.find(rule.Head);

				assert(it_action != std::end(state));

				const auto& action = it_action->second;

				assert(action.Type == LALR::Action::Goto);

				Goto(action.Target);
			}

			const TokenSpan reduced_token{ TokenSpan(_tokens).last<1>() };

			OnPostReduce(target, rule.Head, reduced_token);
		}

		void Goto(const int target)
		{
			_states.push_back(target);
		}

		void Accept()
		{
			_accept = true;
		}

		bool IsNoiseToken() const
		{
			switch (_token.Symbol)
			{
			case Symbols::S_Q:
			case Symbols::S_Whitespace:
				return true;
			default:
				return false;
			}
		}

		virtual bool OnPreReduce(const int rule, const int symbol, const TokenSpan& tokens)
		{
			return false;
		}

		virtual void OnPostReduce(const int rule, const int symbol, const TokenSpan& tokens)
		{
		}
	protected:
		std::string_view _data;

		std::string_view::iterator _data_prev;
		std::string_view::iterator _data_next;
		std::string_view::iterator _data_end;

		std::vector<Token> _tokens;
		std::vector<int> _states;

		bool _token_read = false;
		bool _error = false;
		bool _error_recovery = false;
		bool _accept = false;

		Token _token;
	};

	class Parser final : public ParserCore
	{
	public:
		using MonsterStatsReadyDelegate = std::function<void(MonsterInfo&&)>;

		explicit Parser(MonsterStatsReadyDelegate delegate)
			: _delegate { delegate }
		{
		}
	protected:
		virtual bool OnPreReduce(const int rule, const int symbol, const TokenSpan& tokens) override
		{
#define ACTION(S, Action) case S: Action(rule, symbol, tokens); return true
#define IGNORE(S) case S: return true

			switch (symbol)
			{

			IGNORE(Symbols::S_AIType);
			ACTION(Symbols::S_AttackDesc, OnAttackDesc);
			ACTION(Symbols::S_AttackPreference, OnAttackPreference);
			IGNORE(Symbols::S_Boolean);
			IGNORE(Symbols::S_DamageType);
			IGNORE(Symbols::S_MissileType);
			IGNORE(Symbols::S_MovementType);
			ACTION(Symbols::S_Resistance, OnResistance);
			IGNORE(Symbols::S_Resistances);
			IGNORE(Symbols::S_SkillMastery);
			IGNORE(Symbols::S_SpecialAttack);
			ACTION(Symbols::S_SpecialAttackType, OnSpecialAttackType);
			IGNORE(Symbols::S_Spell);
			IGNORE(Symbols::S_String2);
			ACTION(Symbols::S_TreasureChance, OnTreasureChance);
			ACTION(Symbols::S_TreasureDice, OnTreasureDice);
			IGNORE(Symbols::S_TreasureInfo);
			ACTION(Symbols::S_TreasureType, OnTreasureType);

			default:
				break;
			}

			switch (rule)
			{

			ACTION(Rules::R_SpecialAttack_x_Integer, OnSpecialAttackBonus);
			ACTION(Rules::R_TreasureItem_l_Integer , OnTreasureItem);
			ACTION(Rules::R_TreasureItem_l_Integer2, OnTreasureItem);
			IGNORE(Rules::R_TreasureInfo_Integer);
			IGNORE(Rules::R_DamageDice_Integer);
			ACTION(Rules::R_SpellAttack_Comma_Integer, OnSpellAttack);
			IGNORE(Rules::R_SpellAttack_Integer);
			IGNORE(Rules::R_Number_Integer);
			ACTION(Rules::R_MiscSpecial_explode_Comma_Comma, OnSpecialAbilityExplode);
			ACTION(Rules::R_MiscSpecial_shot_Comma_x_Integer, OnSpecialAbilityShot);
			ACTION(Rules::R_MiscSpecial_summon_Comma_Comma, OnSpecialAbilitySummon);
			IGNORE(Rules::R_MiscSpecial_Integer);
			IGNORE(Rules::R_nl_NewLine);
			IGNORE(Rules::R_nl_NewLine2);
			IGNORE(Rules::R_nlOpt_NewLine);
			IGNORE(Rules::R_nlOpt);
			IGNORE(Rules::R_Start);
			IGNORE(Rules::R_StatementList);
			IGNORE(Rules::R_StatementList2);

			default:
				break;
			}

#undef ACTION
#undef IGNORE

			return ParserCore::OnPreReduce(rule, symbol, tokens);
		}

		virtual void OnPostReduce(const int rule, const int symbol, const TokenSpan& tokens) override
		{
			switch (symbol)
			{
			case Symbols::S_StringPlaceholder:
				assert(_token_read);
				assert(_token.Symbol == Symbols::S_LexicalError);
				_error_recovery = false;
				_token_read = false;
				_tokens.pop_back();
				_states.pop_back();
				InjectString();
				break;
			case Symbols::S_Statement:
				Interpret();
				break;
			}

			ParserCore::OnPostReduce(rule, symbol, tokens);
		}
	private:
		template <class ValueType>
		static void ToNumber(const std::string_view& view, ValueType& value)
		{
			std::from_chars(std::to_address(std::begin(view)), std::to_address(std::end(view)), value);
		}

		template <class ValueType>
		static void ToNumber(const std::string_view& view, ValueType& value) requires (std::is_enum_v<ValueType>)
		{
			std::underlying_type_t<ValueType> raw_value;
			ToNumber(view, raw_value);
			value = static_cast<ValueType>(raw_value);
		}

		template <class ValueType>
		static void ToNumber(const Token& token, ValueType& value)
		{
			ToNumber(token.Value, value);
		}

		template <class ValueType>
		static void ToNumberEx(const Token& token, ValueType& value) requires (!std::is_enum_v<ValueType>)
		{
			if (token.Symbol == Symbols::S_Integer || token.Rule == Rules::R_Number_Integer)
			{
				ToNumber(token.Value, value);
				return;
			}

			if (token.Rule == Rules::R_Number_Integer_Comma_Integer)
			{
				ValueType a;
				ValueType b;

				ToNumber(token.SubTokens[0].Value, a);
				ToNumber(token.SubTokens[2].Value, b);

				value = a * 1000 + b;
			}
		}

		static void ToBoolean(const Token& token, uint8_t& value)
		{
			switch (token.Rule)
			{
			case Rules::R_Boolean_y:
				value = 1;
				break;
			case Rules::R_Boolean_n:
				value = 0;
				break;
			case Rules::R_Boolean_Integer:
				ToNumber(token, value);
				if (value > 0)
					value = 1;
				break;
			}
		}

		static void ToBoolean(const Token& token, bool& value)
		{
			uint8_t temp = 0;

			switch (token.Rule)
			{
			case Rules::R_Boolean_y:
				value = true;
				break;
			case Rules::R_Boolean_n:
				value = false;
				break;
			case Rules::R_Boolean_Integer:
				ToNumber(token, temp);
				if (temp > 0)
					value = true;
				else
					value = false;
				break;
			}
		}

		static void ToAttackPreferences(const Token& token, uint32_t& flags, uint8_t& number)
		{
			for (const char& c : token.Value)
			{
				switch (::tolower(c))
				{
				case '0':
					flags |= 0x0004;
					break;
				case '2':
					number = 2;
					break;
				case '3':
					number = 3;
					break;
				case '4':
					number = 4;
					break;
				case 'a':
					// TODO: ???
					break;
				case 'c':
					flags |= 0x0010;
					break;
				case 'd':
					flags |= 0x0008;
					break;
				case 'e':
					flags |= 0x1000;
					break;
				case 'f':
					flags |= 0x0400;
					break;
				case 'g':
					// TODO: ???
					break;
				case 'h':
					flags |= 0x0800;
					break;
				case 'k':
					flags |= 0x0001;
					break;
				case 'm':
					flags |= 0x0100;
					break;
				case 'o':
					flags |= 0x0400;
					break;
				case 'p':
					flags |= 0x0002;
					break;
				case 'r':
					flags |= 0x0040;
					break;
				case 's':
					flags |= 0x0020;
					break;
				case 't':
					flags |= 0x0080;
					break;
				case 'w':
					flags |= 0x2000;
					break;
				case 'x':
					flags |= 0x0200;
					break;
				default:
					__debugbreak();
					break;
				}
			}
		}

		static void ToTreasureType(const Token& token, uint8_t& value)
		{
			switch (token.Rule)
			{
			case Rules::R_TreasureType_weapon:
				value = 20;
				break;
			case Rules::R_TreasureType_armor:
				value = 21;
				break;
			case Rules::R_TreasureType_misc:
				value = 22;
				break;
			case Rules::R_TreasureType_sword:
				value = 23;
				break;
			case Rules::R_TreasureType_dagger:
				value = 24;
				break;
			case Rules::R_TreasureType_axe:
				value = 25;
				break;
			case Rules::R_TreasureType_spear:
				value = 26;
				break;
			case Rules::R_TreasureType_bow:
				value = 27;
				break;
			case Rules::R_TreasureType_mace:
				value = 28;
				break;
			case Rules::R_TreasureType_club:
				value = 29;
				break;
			case Rules::R_TreasureType_staff:
				value = 30;
				break;
			case Rules::R_TreasureType_leather:
				value = 31;
				break;
			case Rules::R_TreasureType_chain:
				value = 32;
				break;
			case Rules::R_TreasureType_plate:
				value = 33;
				break;
			case Rules::R_TreasureType_shield:
				value = 34;
				break;
			case Rules::R_TreasureType_helm:
				value = 35;
				break;
			case Rules::R_TreasureType_belt:
				value = 36;
				break;
			case Rules::R_TreasureType_cape:
				value = 37;
				break;
			case Rules::R_TreasureType_gauntlets:
				value = 38;
				break;
			case Rules::R_TreasureType_boots:
				value = 39;
				break;
			case Rules::R_TreasureType_ring:
				value = 40;
				break;
			case Rules::R_TreasureType_amulet:
				value = 41;
				break;
			case Rules::R_TreasureType_wand:
				value = 42;
				break;
			case Rules::R_TreasureType_scroll:
				value = 43;
				break;
			case Rules::R_TreasureType_gem:
				value = 46;
				break;
			}
		}

		template <typename ValueType>
		static void ToDamageType(const Token& token, ValueType& value)
		{
			switch (token.Rule)
			{
			case Rules::R_DamageType_fire:
				value = DAMAGE_TYPE::DMGT_FIRE;
				break;
			case Rules::R_DamageType_air:
				value = DAMAGE_TYPE::DMGT_ELECTR;
				break;
			case Rules::R_DamageType_water:
				value = DAMAGE_TYPE::DMGT_COLD;
				break;
			case Rules::R_DamageType_earth:
				value = DAMAGE_TYPE::DMGT_EARTH;
				break;
			case Rules::R_DamageType_phys:
			case Rules::R_DamageType_physical:
				value = DAMAGE_TYPE::DMGT_PHISYCAL;
				break;
			case Rules::R_DamageType_light:
				value = DAMAGE_TYPE::DMGT_LIGHT;
				break;
			case Rules::R_DamageType_dark:
				value = DAMAGE_TYPE::DMGT_DARK;
				break;
			case Rules::R_DamageType_cold:
				value = DAMAGE_TYPE::DMGT_COLD;
				break;
			case Rules::R_DamageType_ener:
			case Rules::R_DamageType_energy:
				value = DAMAGE_TYPE::DMGT_MAGICAL;
				break;
			default:
				break;
			}
		}

		static void ToDamageDice(const Token& token, uint8_t& rolls, uint8_t& sides, uint8_t& bonus)
		{
			if (token.Rule == Rules::R_DamageDice_Integer)
				return;

			ToNumber(token.SubTokens[0], rolls);
			ToNumber(token.SubTokens[2], sides);

			if (token.Rule == Rules::R_DamageDice_Integer_d_Integer_Plus_Integer)
			{
				ToNumber(token.SubTokens.back(), bonus);
			}
		}

		static void ToMissileType(const Token& token, uint8_t& value)
		{
			switch (token.Rule)
			{
			case Rules::R_MissileType_fire:
				value = 3;
				break;
			case Rules::R_MissileType_firear:
				value = 2;
				break;
			case Rules::R_MissileType_air:
				value = 4;
				break;
			case Rules::R_MissileType_water:
				value = 5;
				break;
			case Rules::R_MissileType_earth:
				value = 6;
				break;
			case Rules::R_MissileType_light:
				value = 10;
				break;
			case Rules::R_MissileType_dark:
				value = 11;
				break;
			case Rules::R_MissileType_arrow:
				value = 1;
				break;
			case Rules::R_MissileType_ener:
			case Rules::R_MissileType_energy:
				value = 13;
				break;
			case Rules::R_MissileType_Integer:
				value = 0;
				break;
			default:
				break;
			}
		}

		static void ToMovementType(const Token& token, MONSTER_MOVEMENT_TYPE& value)
		{
			switch (token.Rule)
			{
			case Rules::R_MovementType_stand:
				value = MONSTER_MOVEMENT_TYPE_STATIONARY;
				break;
			case Rules::R_MovementType_short:
				value = MONSTER_MOVEMENT_TYPE_SHORT;
				break;
			case Rules::R_MovementType_med:
				value = MONSTER_MOVEMENT_TYPE_MEDIUM;
				break;
			case Rules::R_MovementType_long:
				value = MONSTER_MOVEMENT_TYPE_LONG;
				break;
			case Rules::R_MovementType_global:
				value = MONSTER_MOVEMENT_TYPE_GLOBAL;
				break;
			case Rules::R_MovementType_free:
				value = MONSTER_MOVEMENT_TYPE_FREE;
				break;
			default:
				break;
			}
		}

		static void ToAIType(const Token& token, MONSTER_AI_TYPE& value)
		{
			switch (token.Rule)
			{
			case Rules::R_AIType_suicidal:
				value = MONSTER_AI_SUICIDAL;
				break;
			case Rules::R_AIType_wimp:
				value = MONSTER_AI_WIMP;
				break;
			case Rules::R_AIType_normal:
				value = MONSTER_AI_NORMAL;
				break;
			case Rules::R_AIType_aggress:
				value = MONSTER_AI_AGGRESSIVE;
				break;
			default:
				break;
			}
		}

		static void ToSpecialAttackType(const Token& token, SPECIAL_ATTACK_TYPE& value)
		{
			switch (token.Rule)
			{
			case Rules::R_SpecialAttackType_curse:
				value = SPECIAL_ATTACK_CURSE;
				break;
			case Rules::R_SpecialAttackType_weak:
				value = SPECIAL_ATTACK_WEAK;
				break;
			case Rules::R_SpecialAttackType_asleep:
				value = SPECIAL_ATTACK_SLEEP;
				break;
			case Rules::R_SpecialAttackType_drunk:
				value = SPECIAL_ATTACK_DRUNK;
				break;
			case Rules::R_SpecialAttackType_insane:
				value = SPECIAL_ATTACK_INSANE;
				break;
			case Rules::R_SpecialAttackType_poison1:
			case Rules::R_SpecialAttackType_poisonweak:
				value = SPECIAL_ATTACK_POISON_WEAK;
				break;
			case Rules::R_SpecialAttackType_poison2:
			case Rules::R_SpecialAttackType_poisonmedium:
				value = SPECIAL_ATTACK_POISON_MEDIUM;
				break;
			case Rules::R_SpecialAttackType_poison3:
			case Rules::R_SpecialAttackType_poisonsevere:
				value = SPECIAL_ATTACK_POISON_SEVERE;
				break;
			case Rules::R_SpecialAttackType_disease1:
			case Rules::R_SpecialAttackType_diseaseweak:
				value = SPECIAL_ATTACK_DISEASE_WEAK;
				break;
			case Rules::R_SpecialAttackType_disease2:
			case Rules::R_SpecialAttackType_diseasemedium:
				value = SPECIAL_ATTACK_DISEASE_MEDIUM;
				break;
			case Rules::R_SpecialAttackType_disease3:
			case Rules::R_SpecialAttackType_diseasesevere:
				value = SPECIAL_ATTACK_DISEASE_SEVERE;
				break;
			case Rules::R_SpecialAttackType_paralyze:
				value = SPECIAL_ATTACK_PARALYZED;
				break;
			case Rules::R_SpecialAttackType_uncon:
				value = SPECIAL_ATTACK_UNCONSCIOUS;
				break;
			case Rules::R_SpecialAttackType_dead:
				value = SPECIAL_ATTACK_DEAD;
				break;
			case Rules::R_SpecialAttackType_stone:
				value = SPECIAL_ATTACK_PETRIFIED;
				break;
			case Rules::R_SpecialAttackType_errad:
				value = SPECIAL_ATTACK_ERADICATED;
				break;
			case Rules::R_SpecialAttackType_brkitem:
				value = SPECIAL_ATTACK_BREAK_ANY;
				break;
			case Rules::R_SpecialAttackType_brkarmor:
				value = SPECIAL_ATTACK_BREAK_ARMOR;
				break;
			case Rules::R_SpecialAttackType_brkweapon:
				value = SPECIAL_ATTACK_BREAK_WEAPON;
				break;
			case Rules::R_SpecialAttackType_steal:
				value = SPECIAL_ATTACK_STEAL;
				break;
			case Rules::R_SpecialAttackType_age:
				value = SPECIAL_ATTACK_AGING;
				break;
			case Rules::R_SpecialAttackType_drainsp:
				value = SPECIAL_ATTACK_MANA_DRAIN;
				break;
			case Rules::R_SpecialAttackType_afraid:
				value = SPECIAL_ATTACK_FEAR;
				break;
			default:
				break;
			}
		}

		static void ToSpellAttack(const TokenSpan& tokens, SPELL_TYPE& spell, uint16_t& skill_level_and_mastery)
		{
			switch (tokens[0].Rule)
			{
			case Rules::R_Spell_acidburst:
				spell = SPELL_WATER_ACID_BURST;
				break;
			case Rules::R_Spell_blades:
				spell = SPELL_EARTH_BLADES;
				break;
			case Rules::R_Spell_bless:
				spell = SPELL_SPIRIT_BLESS;
				break;
			case Rules::R_Spell_dayofprotection:
				spell = SPELL_LIGHT_DAY_OF_PROTECTION;
				break;
			case Rules::R_Spell_dispelmagic:
				spell = SPELL_LIGHT_DISPEL_MAGIC;
				break;
			case Rules::R_Spell_dragonbreath:
				spell = SPELL_DARK_DRAGON_BREATH;
				break;
			case Rules::R_Spell_fate:
				spell = SPELL_SPIRIT_FATE;
				break;
			case Rules::R_Spell_firebolt:
				spell = SPELL_FIRE_FIRE_BOLT;
				break;
			case Rules::R_Spell_fireball:
				spell = SPELL_FIRE_FIREBALL;
				break;
			case Rules::R_Spell_hammerhands:
				spell = SPELL_BODY_HAMMERHANDS;
				break;
			case Rules::R_Spell_harm:
				spell = SPELL_BODY_HARM;
				break;
			case Rules::R_Spell_haste:
				spell = SPELL_FIRE_HASTE;
				break;
			case Rules::R_Spell_heroism:
				spell = SPELL_SPIRIT_HEROISM;
				break;
			case Rules::R_Spell_hourofpower:
				spell = SPELL_LIGHT_HOUR_OF_POWER;
				break;
			case Rules::R_Spell_iceblast:
				spell = SPELL_WATER_ICE_BLAST;
				break;
			case Rules::R_Spell_icebolt:
				spell = SPELL_WATER_ICE_BOLT;
				break;
			case Rules::R_Spell_incinerate:
				spell = SPELL_FIRE_INCINERATE;
				break;
			case Rules::R_Spell_lightbolt:
				spell = SPELL_LIGHT_LIGHT_BOLT;
				break;
			case Rules::R_Spell_lightningbolt:
				spell = SPELL_AIR_LIGHTNING_BOLT;
				break;
			case Rules::R_Spell_meteorshower:
				spell = SPELL_FIRE_METEOR_SHOWER;
				break;
			case Rules::R_Spell_mindblast:
				spell = SPELL_MIND_MIND_BLAST;
				break;
			case Rules::R_Spell_painreflection:
				spell = SPELL_DARK_PAIN_REFLECTION;
				break;
			case Rules::R_Spell_powercure:
				spell = SPELL_BODY_POWER_CURE;
				break;
			case Rules::R_Spell_psychicshock:
				spell = SPELL_MIND_PSYCHIC_SHOCK;
				break;
			case Rules::R_Spell_rockblast:
				spell = SPELL_EARTH_ROCK_BLAST;
				break;
			case Rules::R_Spell_shield:
				spell = SPELL_AIR_SHIELD;
				break;
			case Rules::R_Spell_shrapmetal:
				spell = SPELL_DARK_SHARPMETAL;
				break;
			case Rules::R_Spell_sparks:
				spell = SPELL_AIR_SPARKS;
				break;
			case Rules::R_Spell_stoneskin:
				spell = SPELL_EARTH_STONESKIN;
				break;
			case Rules::R_Spell_toxiccloud:
				spell = SPELL_DARK_TOXIC_CLOUD;
				break;
			default:
				break;
			}

			switch (tokens[2].Rule)
			{
			case Rules::R_SkillMastery_n:
				skill_level_and_mastery |= 0x0000;
				break;
			case Rules::R_SkillMastery_e:
				skill_level_and_mastery |= 0x0040;
				break;
			case Rules::R_SkillMastery_m:
				skill_level_and_mastery |= 0x0080;
				break;
			case Rules::R_SkillMastery_g:
				skill_level_and_mastery |= 0x0100;
				break;
			default:
				break;
			}

			uint8_t skill_level = 0;

			ToNumber(tokens.back(), skill_level);

			skill_level_and_mastery |= skill_level & 0x3F;
		}

		void ToResistance(const Token& token, uint8_t& value)
		{
			switch (token.Symbol)
			{
			case Symbols::S_Integer:
				ToNumber(token, value);
				break;
			case Symbols::S_imm:
				value = 200;
				break;
			default:
				break;
			}
		}

		void InjectString()
		{
			using sv_regex_iterator = std::regex_iterator<std::string_view::iterator>;
			using sv_match_results = std::match_results<std::string_view::iterator>;

			auto it = sv_regex_iterator(_data_next, _data_end, re_token_separator);

			const auto& value = it->prefix();

			_token = { Symbols::S_String, -1, { value.first, value.second } };
			_token_read = true;
			_data_next = value.second;
		}

		void Interpret()
		{
			const auto& line = _tokens.back();

			ToNumber(line.SubTokens[0], _mi.uID);
			_mi.pName.assign(line.SubTokens[2].Value);
			_mi.pPictureName.assign(line.SubTokens[4].Value);
			ToNumber(line.SubTokens[6], _mi.uLevel);
			ToNumberEx(line.SubTokens[8], _mi.uHP);
			ToNumber(line.SubTokens[10], _mi.uAC);
			ToNumberEx(line.SubTokens[12], _mi.uExp);
			ToBoolean(line.SubTokens[16], _mi.bBloodSplatOnDeath);
			ToBoolean(line.SubTokens[18], _mi.uFlying);
			ToMovementType(line.SubTokens[20], _mi.uMovementType);
			ToAIType(line.SubTokens[22], _mi.uAIType);
			ToNumber(line.SubTokens[24], _mi.uHostilityType);
			ToNumber(line.SubTokens[26], _mi.uBaseSpeed);
			ToNumber(line.SubTokens[28], _mi.uRecoveryTime);
			ToNumber(line.SubTokens[36], _mi.uAttack2Chance);

			if (_delegate)
				_delegate(std::move(_mi));

			_mi = {};
			_mi_attack_desc = 0;
			_mi_spell_attack_desc = 0;
			_mi_resistance = 0;
		}

		void OnAttackDesc(const int rule, const int symbol, const TokenSpan& tokens)
		{
			assert(_mi_attack_desc < 2);

			switch (_mi_attack_desc)
			{
			case 0:
				ToDamageType(tokens[0], _mi.uAttack1Type);
				ToDamageDice(tokens[2], _mi.uAttack1DamageDiceRolls, _mi.uAttack1DamageDiceSides, _mi.uAttack1DamageBonus);
				ToMissileType(tokens[4], _mi.uMissleAttack1Type);
				break;
			case 1:
				ToDamageType(tokens[0], _mi.uAttack2Type);
				ToDamageDice(tokens[2], _mi.uAttack2DamageDiceRolls, _mi.uAttack2DamageDiceSides, _mi.uAttack2DamageBonus);
				ToMissileType(tokens[4], _mi.uMissleAttack2Type);
				break;
			default:
				break;
			}

			++_mi_attack_desc;
		}

		void OnAttackPreference(const int rule, const int symbol, const TokenSpan& tokens)
		{
			ToAttackPreferences(tokens[0], _mi.uAttackPreference, _mi.uNumCharactersAttackedPerSpecialAbility);
		}

		void OnSpecialAbilityShot(const int rule, const int symbol, const TokenSpan& tokens)
		{
			_mi.uSpecialAbilityType = MONSTER_SPECIAL_ABILITY_SHOT;

			ToNumber(tokens.back(), _mi.uSpecialAbilityDamageDiceBonus);
		}

		void OnSpecialAbilitySummon(const int rule, const int symbol, const TokenSpan& tokens)
		{
			_mi.uSpecialAbilityType = MONSTER_SPECIAL_ABILITY_SUMMON;

			switch (tokens[2].Rule)
			{
			case Rules::R_MiscSummonSpawn_ground:
				_mi.uSpecialAbilityDamageDiceSides = 1;
				break;
			default:
				_mi.uSpecialAbilityDamageDiceSides = 0;
				break;
			}

			switch (::tolower(tokens[4].Value.back()))
			{
			case 'a':
				_mi.uSpecialAbilityDamageDiceRolls = 1;
				break;
			case 'b':
				_mi.uSpecialAbilityDamageDiceRolls = 2;
				break;
			case 'c':
				_mi.uSpecialAbilityDamageDiceRolls = 3;
				break;
			default:
				_mi.uSpecialAbilityDamageDiceRolls = 0;
				break;
			}

			if (!pMonsterList->pMonsters.empty())
			{
				auto it = std::find_if(std::begin(pMonsterList->pMonsters), std::end(pMonsterList->pMonsters), [&](const auto& monster_desc) -> bool
					{
						return iequals(monster_desc.pMonsterName, tokens[4].Value);
					});
				if (it == std::end(pMonsterList->pMonsters))
				{
					__debugbreak();

					_mi.uSpecialAbilityType = MONSTER_SPECIAL_ABILITY_NONE;
				}
				else
				{
					_mi.field_3C_some_special_attack = std::distance(std::begin(pMonsterList->pMonsters), it) + 1;
				}
			}

			_mi.field_3C_some_special_attack = -1;
		}

		void OnSpecialAbilityExplode(const int rule, const int symbol, const TokenSpan& tokens)
		{
			_mi.uSpecialAbilityType = MONSTER_SPECIAL_ABILITY_EXPLODE;

			ToDamageDice(tokens[2], _mi.uSpecialAbilityDamageDiceRolls, _mi.uSpecialAbilityDamageDiceSides, _mi.uSpecialAbilityDamageDiceBonus);

			DAMAGE_TYPE dt;

			ToDamageType(tokens[4], dt);

			_mi.field_3C_some_special_attack = std::to_underlying(dt);
		}

		void OnResistance(const int rule, const int symbol, const TokenSpan& tokens)
		{
			static const std::array<uint8_t MonsterInfo::*, 10> ResistanceFields =
			{
				&MonsterInfo::uResFire,
				&MonsterInfo::uResAir,
				&MonsterInfo::uResWater,
				&MonsterInfo::uResEarth,
				&MonsterInfo::uResMind,
				&MonsterInfo::uResSpirit,
				&MonsterInfo::uResBody,
				&MonsterInfo::uResLight,
				&MonsterInfo::uResDark,
				&MonsterInfo::uResPhysical,
			};

			assert(_mi_resistance < std::size(ResistanceFields));

			ToResistance(tokens[0], _mi.*(ResistanceFields[_mi_resistance]));

			++_mi_resistance;
		}

		void OnSpecialAttackType(const int rule, const int symbol, const TokenSpan& tokens)
		{
			ToSpecialAttackType(tokens[0], _mi.uSpecialAttackType);
		}

		void OnSpecialAttackBonus(const int rule, const int symbol, const TokenSpan& tokens)
		{
			ToNumber(tokens.back(), _mi.uSpecialAttackLevel);
		}

		void OnSpellAttack(const int rule, const int symbol, const TokenSpan& tokens)
		{
			assert(_mi_spell_attack_desc < 2);

			switch (_mi_spell_attack_desc)
			{
			case 0:
				ToSpellAttack(tokens, _mi.uSpell1ID, _mi.uSpellSkillAndMastery1);
				break;
			case 1:
				ToSpellAttack(tokens, _mi.uSpell2ID, _mi.uSpellSkillAndMastery2);
				break;
			}
		}

		void OnSpellAttackDesc(const int rule, const int symbol, const TokenSpan& tokens)
		{
			assert(_mi_spell_attack_desc < 2);

			switch (_mi_spell_attack_desc)
			{
			case 0:
				ToNumber(tokens[0], _mi.uSpell1UseChance);
				break;
			case 1:
				ToNumber(tokens[0], _mi.uSpell2UseChance);
				break;
			}

			++_mi_spell_attack_desc;
		}

		void OnTreasureChance(const int rule, const int symbol, const TokenSpan& tokens)
		{
			ToNumber(tokens[0], _mi.uTreasureDropChance);
		}

		void OnTreasureDice(const int rule, const int symbol, const TokenSpan& tokens)
		{
			ToNumber(tokens[0], _mi.uTreasureDiceRolls);
			ToNumber(tokens[2], _mi.uTreasureDiceSides);
		}

		void OnTreasureItem(const int rule, const int symbol, const TokenSpan& tokens)
		{
			ToNumber(tokens[1], _mi.uTreasureLevel);
		}

		void OnTreasureType(const int rule, const int symbol, const TokenSpan& tokens)
		{
			ToTreasureType(tokens.back(), _mi.uTreasureType);
		}

		MonsterInfo _mi;

		std::size_t _mi_attack_desc = 0;
		std::size_t _mi_spell_attack_desc = 0;
		std::size_t _mi_resistance = 0;

		MonsterStatsReadyDelegate _delegate;
	};
}
