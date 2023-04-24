//
// THIS FILE IS GENERATED
//
#pragma once

namespace MonsterInfoParser
{
    namespace Symbols
    {
        enum
        {
            S_EOF = 0, // (EOF)
            S_Error = 1, // (Error)
            S_Q = 2, // Q
            S_Whitespace = 3, // Whitespace
            S_Percent = 4, // '%'
            S_Plus = 5, // '+'
            S_Comma = 6, // ','
            S_acidburst = 7, // 'acid burst'
            S_afraid = 8, // afraid
            S_age = 9, // age
            S_aggress = 10, // aggress
            S_air = 11, // air
            S_amulet = 12, // amulet
            S_armor = 13, // armor
            S_arrow = 14, // arrow
            S_asleep = 15, // asleep
            S_axe = 16, // axe
            S_belt = 17, // belt
            S_blades = 18, // blades
            S_bless = 19, // bless
            S_boots = 20, // boots
            S_bow = 21, // bow
            S_brkarmor = 22, // brkarmor
            S_brkitem = 23, // brkitem
            S_brkweapon = 24, // brkweapon
            S_cape = 25, // cape
            S_chain = 26, // chain
            S_club = 27, // club
            S_cold = 28, // cold
            S_curse = 29, // curse
            S_d = 30, // d
            S_dagger = 31, // dagger
            S_dark = 32, // dark
            S_dayofprotection = 33, // 'day of protection'
            S_dead = 34, // dead
            S_diseasemedium = 35, // 'disease medium'
            S_diseasesevere = 36, // 'disease severe'
            S_diseaseweak = 37, // 'disease weak'
            S_disease1 = 38, // 'disease1'
            S_disease2 = 39, // 'disease2'
            S_disease3 = 40, // 'disease3'
            S_dispelmagic = 41, // 'dispel magic'
            S_dragonbreath = 42, // 'dragon breath'
            S_drainsp = 43, // drainsp
            S_drunk = 44, // drunk
            S_e = 45, // e
            S_earth = 46, // earth
            S_ener = 47, // ener
            S_energy = 48, // energy
            S_errad = 49, // errad
            S_explode = 50, // explode
            S_fate = 51, // fate
            S_fire = 52, // fire
            S_firebolt = 53, // 'fire bolt'
            S_firear = 54, // firear
            S_fireball = 55, // fireball
            S_free = 56, // free
            S_g = 57, // g
            S_gauntlets = 58, // gauntlets
            S_gem = 59, // gem
            S_global = 60, // global
            S_ground = 61, // ground
            S_hammerhands = 62, // hammerhands
            S_harm = 63, // harm
            S_haste = 64, // haste
            S_helm = 65, // helm
            S_heroism = 66, // heroism
            S_hourofpower = 67, // 'hour of power'
            S_iceblast = 68, // 'ice blast'
            S_icebolt = 69, // 'ice bolt'
            S_imm = 70, // imm
            S_incinerate = 71, // incinerate
            S_insane = 72, // insane
            S_Integer = 73, // Integer
            S_l = 74, // l
            S_leather = 75, // leather
            S_LexicalError = 76, // LexicalError
            S_light = 77, // light
            S_lightbolt = 78, // 'light bolt'
            S_lightningbolt = 79, // 'lightning bolt'
            S_long = 80, // long
            S_m = 81, // m
            S_mace = 82, // mace
            S_med = 83, // med
            S_meteorshower = 84, // 'meteor shower'
            S_mindblast = 85, // 'mind blast'
            S_misc = 86, // misc
            S_n = 87, // n
            S_NewLine = 88, // NewLine
            S_normal = 89, // normal
            S_painreflection = 90, // 'pain reflection'
            S_paralyze = 91, // paralyze
            S_phys = 92, // phys
            S_physical = 93, // physical
            S_plate = 94, // plate
            S_poisonmedium = 95, // 'poison medium'
            S_poisonsevere = 96, // 'poison severe'
            S_poisonweak = 97, // 'poison weak'
            S_poison1 = 98, // 'poison1'
            S_poison2 = 99, // 'poison2'
            S_poison3 = 100, // 'poison3'
            S_powercure = 101, // 'power cure'
            S_psychicshock = 102, // 'psychic shock'
            S_ring = 103, // ring
            S_rockblast = 104, // 'rock blast'
            S_S = 105, // S
            S_scroll = 106, // scroll
            S_shield = 107, // shield
            S_short = 108, // short
            S_shot = 109, // shot
            S_shrapmetal = 110, // shrapmetal
            S_sparks = 111, // sparks
            S_spear = 112, // spear
            S_staff = 113, // staff
            S_stand = 114, // stand
            S_steal = 115, // steal
            S_stone = 116, // stone
            S_stoneskin = 117, // 'stone skin'
            S_String = 118, // String
            S_suicidal = 119, // suicidal
            S_summon = 120, // summon
            S_sword = 121, // sword
            S_toxiccloud = 122, // 'toxic cloud'
            S_uncon = 123, // uncon
            S_wand = 124, // wand
            S_water = 125, // water
            S_weak = 126, // weak
            S_weapon = 127, // weapon
            S_wimp = 128, // wimp
            S_x = 129, // x
            S_y = 130, // y
            S_AIType = 131, // <AI Type>
            S_AttackDesc = 132, // <Attack Desc>
            S_AttackPreference = 133, // <Attack Preference>
            S_Boolean = 134, // <Boolean>
            S_CommaOpt = 135, // <Comma Opt>
            S_DamageDice = 136, // <Damage Dice>
            S_DamageType = 137, // <Damage Type>
            S_MiscSpecial = 138, // <Misc Special>
            S_MiscSummonSpawn = 139, // <Misc Summon Spawn>
            S_MissileType = 140, // <Missile Type>
            S_MovementType = 141, // <Movement Type>
            S_nl = 142, // <nl>
            S_nlOpt = 143, // <nl Opt>
            S_Number = 144, // <Number>
            S_PlusOpt = 145, // <Plus Opt>
            S_Resistance = 146, // <Resistance>
            S_Resistances = 147, // <Resistances>
            S_SkillMastery = 148, // <Skill Mastery>
            S_SpecialAttack = 149, // <Special Attack>
            S_SpecialAttackType = 150, // <Special Attack Type>
            S_Spell = 151, // <Spell>
            S_SpellAttack = 152, // <Spell Attack>
            S_SpellAttackDesc = 153, // <Spell Attack Desc>
            S_Start = 154, // <Start>
            S_Statement = 155, // <Statement>
            S_StatementList = 156, // <Statement List>
            S_String2 = 157, // <String>
            S_StringPlaceholder = 158, // <String Placeholder>
            S_TreasureChance = 159, // <Treasure Chance>
            S_TreasureDice = 160, // <Treasure Dice>
            S_TreasureInfo = 161, // <Treasure Info>
            S_TreasureItem = 162, // <Treasure Item>
            S_TreasureType = 163  // <Treasure Type>
        };
    }

    namespace Rules
    {
        struct Rule
        {
            const int Head;
            const int SymbolCount;
        };

        enum
        {
            R_PlusOpt_Plus = 0, // <Plus Opt> ::= '+'
            R_PlusOpt = 1, // <Plus Opt> ::= 
            R_CommaOpt_Comma = 2, // <Comma Opt> ::= ','
            R_CommaOpt = 3, // <Comma Opt> ::= 
            R_SpecialAttackType_curse = 4, // <Special Attack Type> ::= curse
            R_SpecialAttackType_weak = 5, // <Special Attack Type> ::= weak
            R_SpecialAttackType_asleep = 6, // <Special Attack Type> ::= asleep
            R_SpecialAttackType_drunk = 7, // <Special Attack Type> ::= drunk
            R_SpecialAttackType_insane = 8, // <Special Attack Type> ::= insane
            R_SpecialAttackType_poison1 = 9, // <Special Attack Type> ::= 'poison1'
            R_SpecialAttackType_poisonweak = 10, // <Special Attack Type> ::= 'poison weak'
            R_SpecialAttackType_poison2 = 11, // <Special Attack Type> ::= 'poison2'
            R_SpecialAttackType_poisonmedium = 12, // <Special Attack Type> ::= 'poison medium'
            R_SpecialAttackType_poison3 = 13, // <Special Attack Type> ::= 'poison3'
            R_SpecialAttackType_poisonsevere = 14, // <Special Attack Type> ::= 'poison severe'
            R_SpecialAttackType_disease1 = 15, // <Special Attack Type> ::= 'disease1'
            R_SpecialAttackType_diseaseweak = 16, // <Special Attack Type> ::= 'disease weak'
            R_SpecialAttackType_disease2 = 17, // <Special Attack Type> ::= 'disease2'
            R_SpecialAttackType_diseasemedium = 18, // <Special Attack Type> ::= 'disease medium'
            R_SpecialAttackType_disease3 = 19, // <Special Attack Type> ::= 'disease3'
            R_SpecialAttackType_diseasesevere = 20, // <Special Attack Type> ::= 'disease severe'
            R_SpecialAttackType_paralyze = 21, // <Special Attack Type> ::= paralyze
            R_SpecialAttackType_uncon = 22, // <Special Attack Type> ::= uncon
            R_SpecialAttackType_dead = 23, // <Special Attack Type> ::= dead
            R_SpecialAttackType_stone = 24, // <Special Attack Type> ::= stone
            R_SpecialAttackType_errad = 25, // <Special Attack Type> ::= errad
            R_SpecialAttackType_brkitem = 26, // <Special Attack Type> ::= brkitem
            R_SpecialAttackType_brkarmor = 27, // <Special Attack Type> ::= brkarmor
            R_SpecialAttackType_brkweapon = 28, // <Special Attack Type> ::= brkweapon
            R_SpecialAttackType_steal = 29, // <Special Attack Type> ::= steal
            R_SpecialAttackType_age = 30, // <Special Attack Type> ::= age
            R_SpecialAttackType_drainsp = 31, // <Special Attack Type> ::= drainsp
            R_SpecialAttackType_afraid = 32, // <Special Attack Type> ::= afraid
            R_SpecialAttack_x_Integer = 33, // <Special Attack> ::= <Special Attack Type> <Comma Opt> x Integer
            R_SpecialAttack = 34, // <Special Attack> ::= <Special Attack Type>
            R_SpecialAttack_Integer = 35, // <Special Attack> ::= Integer
            R_TreasureType_weapon = 36, // <Treasure Type> ::= weapon
            R_TreasureType_armor = 37, // <Treasure Type> ::= armor
            R_TreasureType_misc = 38, // <Treasure Type> ::= misc
            R_TreasureType_sword = 39, // <Treasure Type> ::= sword
            R_TreasureType_dagger = 40, // <Treasure Type> ::= dagger
            R_TreasureType_axe = 41, // <Treasure Type> ::= axe
            R_TreasureType_spear = 42, // <Treasure Type> ::= spear
            R_TreasureType_bow = 43, // <Treasure Type> ::= bow
            R_TreasureType_mace = 44, // <Treasure Type> ::= mace
            R_TreasureType_club = 45, // <Treasure Type> ::= club
            R_TreasureType_staff = 46, // <Treasure Type> ::= staff
            R_TreasureType_leather = 47, // <Treasure Type> ::= leather
            R_TreasureType_chain = 48, // <Treasure Type> ::= chain
            R_TreasureType_plate = 49, // <Treasure Type> ::= plate
            R_TreasureType_shield = 50, // <Treasure Type> ::= shield
            R_TreasureType_helm = 51, // <Treasure Type> ::= helm
            R_TreasureType_belt = 52, // <Treasure Type> ::= belt
            R_TreasureType_cape = 53, // <Treasure Type> ::= cape
            R_TreasureType_gauntlets = 54, // <Treasure Type> ::= gauntlets
            R_TreasureType_boots = 55, // <Treasure Type> ::= boots
            R_TreasureType_ring = 56, // <Treasure Type> ::= ring
            R_TreasureType_amulet = 57, // <Treasure Type> ::= amulet
            R_TreasureType_wand = 58, // <Treasure Type> ::= wand
            R_TreasureType_scroll = 59, // <Treasure Type> ::= scroll
            R_TreasureType_gem = 60, // <Treasure Type> ::= gem
            R_TreasureChance_Integer_Percent = 61, // <Treasure Chance> ::= Integer '%'
            R_TreasureDice_Integer_d_Integer = 62, // <Treasure Dice> ::= Integer d Integer
            R_TreasureItem_l_Integer = 63, // <Treasure Item> ::= l Integer <Treasure Type>
            R_TreasureItem_l_Integer2 = 64, // <Treasure Item> ::= l Integer
            R_TreasureInfo = 65, // <Treasure Info> ::= <Treasure Chance> <Treasure Dice> <Plus Opt> <Treasure Item>
            R_TreasureInfo2 = 66, // <Treasure Info> ::= <Treasure Chance> <Treasure Dice>
            R_TreasureInfo3 = 67, // <Treasure Info> ::= <Treasure Chance> <Plus Opt> <Treasure Item>
            R_TreasureInfo4 = 68, // <Treasure Info> ::= <Treasure Dice> <Plus Opt> <Treasure Item>
            R_TreasureInfo5 = 69, // <Treasure Info> ::= <Treasure Dice>
            R_TreasureInfo6 = 70, // <Treasure Info> ::= <Treasure Item>
            R_TreasureInfo_Integer = 71, // <Treasure Info> ::= Integer
            R_MovementType_stand = 72, // <Movement Type> ::= stand
            R_MovementType_short = 73, // <Movement Type> ::= short
            R_MovementType_med = 74, // <Movement Type> ::= med
            R_MovementType_long = 75, // <Movement Type> ::= long
            R_MovementType_global = 76, // <Movement Type> ::= global
            R_MovementType_free = 77, // <Movement Type> ::= free
            R_AIType_suicidal = 78, // <AI Type> ::= suicidal
            R_AIType_wimp = 79, // <AI Type> ::= wimp
            R_AIType_normal = 80, // <AI Type> ::= normal
            R_AIType_aggress = 81, // <AI Type> ::= aggress
            R_DamageType_fire = 82, // <Damage Type> ::= fire
            R_DamageType_air = 83, // <Damage Type> ::= air
            R_DamageType_water = 84, // <Damage Type> ::= water
            R_DamageType_earth = 85, // <Damage Type> ::= earth
            R_DamageType_phys = 86, // <Damage Type> ::= phys
            R_DamageType_physical = 87, // <Damage Type> ::= physical
            R_DamageType_light = 88, // <Damage Type> ::= light
            R_DamageType_dark = 89, // <Damage Type> ::= dark
            R_DamageType_cold = 90, // <Damage Type> ::= cold
            R_DamageType_ener = 91, // <Damage Type> ::= ener
            R_DamageType_energy = 92, // <Damage Type> ::= energy
            R_DamageType_Integer = 93, // <Damage Type> ::= Integer
            R_DamageDice_Integer_d_Integer_Plus_Integer = 94, // <Damage Dice> ::= Integer d Integer '+' Integer
            R_DamageDice_Integer_d_Integer = 95, // <Damage Dice> ::= Integer d Integer
            R_DamageDice_Integer = 96, // <Damage Dice> ::= Integer
            R_MissileType_fire = 97, // <Missile Type> ::= fire
            R_MissileType_firear = 98, // <Missile Type> ::= firear
            R_MissileType_air = 99, // <Missile Type> ::= air
            R_MissileType_water = 100, // <Missile Type> ::= water
            R_MissileType_earth = 101, // <Missile Type> ::= earth
            R_MissileType_light = 102, // <Missile Type> ::= light
            R_MissileType_dark = 103, // <Missile Type> ::= dark
            R_MissileType_arrow = 104, // <Missile Type> ::= arrow
            R_MissileType_ener = 105, // <Missile Type> ::= ener
            R_MissileType_energy = 106, // <Missile Type> ::= energy
            R_MissileType_Integer = 107, // <Missile Type> ::= Integer
            R_Spell_acidburst = 108, // <Spell> ::= 'acid burst'
            R_Spell_blades = 109, // <Spell> ::= blades
            R_Spell_bless = 110, // <Spell> ::= bless
            R_Spell_dayofprotection = 111, // <Spell> ::= 'day of protection'
            R_Spell_dispelmagic = 112, // <Spell> ::= 'dispel magic'
            R_Spell_dragonbreath = 113, // <Spell> ::= 'dragon breath'
            R_Spell_fate = 114, // <Spell> ::= fate
            R_Spell_firebolt = 115, // <Spell> ::= 'fire bolt'
            R_Spell_fireball = 116, // <Spell> ::= fireball
            R_Spell_hammerhands = 117, // <Spell> ::= hammerhands
            R_Spell_harm = 118, // <Spell> ::= harm
            R_Spell_haste = 119, // <Spell> ::= haste
            R_Spell_heroism = 120, // <Spell> ::= heroism
            R_Spell_hourofpower = 121, // <Spell> ::= 'hour of power'
            R_Spell_iceblast = 122, // <Spell> ::= 'ice blast'
            R_Spell_icebolt = 123, // <Spell> ::= 'ice bolt'
            R_Spell_incinerate = 124, // <Spell> ::= incinerate
            R_Spell_lightbolt = 125, // <Spell> ::= 'light bolt'
            R_Spell_lightningbolt = 126, // <Spell> ::= 'lightning bolt'
            R_Spell_meteorshower = 127, // <Spell> ::= 'meteor shower'
            R_Spell_mindblast = 128, // <Spell> ::= 'mind blast'
            R_Spell_painreflection = 129, // <Spell> ::= 'pain reflection'
            R_Spell_powercure = 130, // <Spell> ::= 'power cure'
            R_Spell_psychicshock = 131, // <Spell> ::= 'psychic shock'
            R_Spell_rockblast = 132, // <Spell> ::= 'rock blast'
            R_Spell_shield = 133, // <Spell> ::= shield
            R_Spell_shrapmetal = 134, // <Spell> ::= shrapmetal
            R_Spell_sparks = 135, // <Spell> ::= sparks
            R_Spell_stoneskin = 136, // <Spell> ::= 'stone skin'
            R_Spell_toxiccloud = 137, // <Spell> ::= 'toxic cloud'
            R_SkillMastery_n = 138, // <Skill Mastery> ::= n
            R_SkillMastery_e = 139, // <Skill Mastery> ::= e
            R_SkillMastery_m = 140, // <Skill Mastery> ::= m
            R_SkillMastery_g = 141, // <Skill Mastery> ::= g
            R_SpellAttack_Comma_Integer = 142, // <Spell Attack> ::= <Spell> ',' <Skill Mastery> <Comma Opt> Integer
            R_SpellAttack_Integer = 143, // <Spell Attack> ::= Integer
            R_Boolean_y = 144, // <Boolean> ::= y
            R_Boolean_n = 145, // <Boolean> ::= n
            R_Boolean_Integer = 146, // <Boolean> ::= Integer
            R_Number_Integer = 147, // <Number> ::= Integer
            R_Number_Integer_Comma_Integer = 148, // <Number> ::= Integer ',' Integer
            R_Resistance_Integer = 149, // <Resistance> ::= Integer
            R_Resistance_imm = 150, // <Resistance> ::= imm
            R_AttackDesc_S_S = 151, // <Attack Desc> ::= <Damage Type> S <Damage Dice> S <Missile Type>
            R_SpellAttackDesc_Integer_S = 152, // <Spell Attack Desc> ::= Integer S <Spell Attack>
            R_Resistances_S_S_S_S_S_S_S_S_S = 153, // <Resistances> ::= <Resistance> S <Resistance> S <Resistance> S <Resistance> S <Resistance> S <Resistance> S <Resistance> S <Resistance> S <Resistance> S <Resistance>
            R_MiscSummonSpawn_air = 154, // <Misc Summon Spawn> ::= air
            R_MiscSummonSpawn_ground = 155, // <Misc Summon Spawn> ::= ground
            R_StringPlaceholder = 156, // <String Placeholder> ::= 
            R_String_LexicalError = 157, // <String> ::= <String Placeholder> LexicalError
            R_String_String = 158, // <String> ::= String
            R_AttackPreference = 159, // <Attack Preference> ::= <String>
            R_AttackPreference_Integer = 160, // <Attack Preference> ::= Integer
            R_MiscSpecial_explode_Comma_Comma = 161, // <Misc Special> ::= explode ',' <Damage Dice> ',' <Damage Type>
            R_MiscSpecial_shot_Comma_x_Integer = 162, // <Misc Special> ::= shot ',' x Integer
            R_MiscSpecial_summon_Comma_Comma = 163, // <Misc Special> ::= summon ',' <Misc Summon Spawn> ',' <String>
            R_MiscSpecial_Integer = 164, // <Misc Special> ::= Integer
            R_nl_NewLine = 165, // <nl> ::= NewLine <nl>
            R_nl_NewLine2 = 166, // <nl> ::= NewLine
            R_nlOpt_NewLine = 167, // <nl Opt> ::= NewLine <nl Opt>
            R_nlOpt = 168, // <nl Opt> ::= 
            R_Start = 169, // <Start> ::= <Statement List> <nl Opt>
            R_Statement_Integer_S_S_S_Integer_S_S_Integer_S_S_S_S_S_S_S_Integer_S_Integer_S_Integer_S_S_S_S_Integer_S_S_S_S_S = 170, // <Statement> ::= Integer S <String> S <String> S Integer S <Number> S Integer S <Number> S <Treasure Info> S <Boolean> S <Boolean> S <Movement Type> S <AI Type> S Integer S Integer S Integer S <Attack Preference> S <Special Attack> S <Attack Desc> S Integer S <Attack Desc> S <Spell Attack Desc> S <Spell Attack Desc> S <Resistances> S <Misc Special>
            R_StatementList = 171, // <Statement List> ::= <Statement List> <nl> <Statement>
            R_StatementList2 = 172, // <Statement List> ::= <Statement>
            R_StatementList3 = 173  // <Statement List> ::= 
        };

        static constexpr Rule Rules[174] =
        {
            { 145, 1 },
            { 145, 0 },
            { 135, 1 },
            { 135, 0 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 150, 1 },
            { 149, 4 },
            { 149, 1 },
            { 149, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 163, 1 },
            { 159, 2 },
            { 160, 3 },
            { 162, 3 },
            { 162, 2 },
            { 161, 4 },
            { 161, 2 },
            { 161, 3 },
            { 161, 3 },
            { 161, 1 },
            { 161, 1 },
            { 161, 1 },
            { 141, 1 },
            { 141, 1 },
            { 141, 1 },
            { 141, 1 },
            { 141, 1 },
            { 141, 1 },
            { 131, 1 },
            { 131, 1 },
            { 131, 1 },
            { 131, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 137, 1 },
            { 136, 5 },
            { 136, 3 },
            { 136, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 140, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 151, 1 },
            { 148, 1 },
            { 148, 1 },
            { 148, 1 },
            { 148, 1 },
            { 152, 5 },
            { 152, 1 },
            { 134, 1 },
            { 134, 1 },
            { 134, 1 },
            { 144, 1 },
            { 144, 3 },
            { 146, 1 },
            { 146, 1 },
            { 132, 5 },
            { 153, 3 },
            { 147, 19 },
            { 139, 1 },
            { 139, 1 },
            { 158, 0 },
            { 157, 2 },
            { 157, 1 },
            { 133, 1 },
            { 133, 1 },
            { 138, 5 },
            { 138, 4 },
            { 138, 5 },
            { 138, 1 },
            { 142, 2 },
            { 142, 1 },
            { 143, 2 },
            { 143, 0 },
            { 154, 2 },
            { 155, 47 },
            { 156, 3 },
            { 156, 1 },
            { 156, 0 } 
        };
    }

    namespace DFA
    {
        static constexpr inline int InitialState = 0;

        static constexpr inline char Charset0[1] = { 34 };
        static constexpr inline char Charset1[3] = { 11,12,32 };
        static constexpr inline char Charset2[1] = { 37 };
        static constexpr inline char Charset3[1] = { 43 };
        static constexpr inline char Charset4[1] = { 44 };
        static constexpr inline char Charset5[10] = { 48,49,50,51,52,53,54,55,56,57 };
        static constexpr inline char Charset6[1] = { 10 };
        static constexpr inline char Charset7[2] = { 84,116 };
        static constexpr inline char Charset8[2] = { 85,117 };
        static constexpr inline char Charset9[2] = { 88,120 };
        static constexpr inline char Charset10[2] = { 89,121 };
        static constexpr inline char Charset11[1] = { 9 };
        static constexpr inline char Charset12[1] = { 13 };
        static constexpr inline char Charset13[2] = { 65,97 };
        static constexpr inline char Charset14[2] = { 66,98 };
        static constexpr inline char Charset15[2] = { 67,99 };
        static constexpr inline char Charset16[2] = { 68,100 };
        static constexpr inline char Charset17[2] = { 69,101 };
        static constexpr inline char Charset18[2] = { 70,102 };
        static constexpr inline char Charset19[2] = { 71,103 };
        static constexpr inline char Charset20[2] = { 72,104 };
        static constexpr inline char Charset21[2] = { 73,105 };
        static constexpr inline char Charset22[2] = { 76,108 };
        static constexpr inline char Charset23[2] = { 77,109 };
        static constexpr inline char Charset24[2] = { 78,110 };
        static constexpr inline char Charset25[2] = { 80,112 };
        static constexpr inline char Charset26[2] = { 82,114 };
        static constexpr inline char Charset27[2] = { 83,115 };
        static constexpr inline char Charset28[2] = { 87,119 };
        static constexpr inline char Charset29[4] = { 9,11,12,32 };
        static constexpr inline char Charset30[2] = { 79,111 };
        static constexpr inline char Charset31[1] = { 32 };
        static constexpr inline char Charset32[2] = { 75,107 };
        static constexpr inline char Charset33[1] = { 49 };
        static constexpr inline char Charset34[1] = { 50 };
        static constexpr inline char Charset35[1] = { 51 };
        static constexpr inline char Charset36[2] = { 86,118 };
        static constexpr inline char Charset37[2] = { 90,122 };

        template <std::size_t N>
        static constexpr inline bool MatchCharset(char c, const char (&charset)[N]) requires (N > 0)
        {
    #if 1
            if (c < charset[0])
                return false;
            if (c > charset[N - 1])
                return false;
            auto it = std::lower_bound(std::begin(charset), std::end(charset), c);
            if (it == std::end(charset))
                return false;
            return *it == c;
    #else
            return charset.find(c) != std::string_view::npos;
    #endif
        }

        static int Match(int& state, std::string_view::iterator& c)
        {
            while (true)
                switch (state)
                {
                case 0:
                    if (MatchCharset(*c, Charset0)) { state = 1; ++c; continue; }
                    if (MatchCharset(*c, Charset1)) { state = 2; ++c; continue; }
                    if (MatchCharset(*c, Charset2)) { state = 3; ++c; continue; }
                    if (MatchCharset(*c, Charset3)) { state = 4; ++c; continue; }
                    if (MatchCharset(*c, Charset4)) { state = 5; ++c; continue; }
                    if (MatchCharset(*c, Charset5)) { state = 6; ++c; continue; }
                    if (MatchCharset(*c, Charset6)) { state = 7; ++c; continue; }
                    if (MatchCharset(*c, Charset7)) { state = 8; ++c; continue; }
                    if (MatchCharset(*c, Charset8)) { state = 19; ++c; continue; }
                    if (MatchCharset(*c, Charset9)) { state = 24; ++c; continue; }
                    if (MatchCharset(*c, Charset10)) { state = 25; ++c; continue; }
                    if (MatchCharset(*c, Charset11)) { state = 26; ++c; continue; }
                    if (MatchCharset(*c, Charset12)) { state = 27; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 29; ++c; continue; }
                    if (MatchCharset(*c, Charset14)) { state = 72; ++c; continue; }
                    if (MatchCharset(*c, Charset15)) { state = 106; ++c; continue; }
                    if (MatchCharset(*c, Charset16)) { state = 124; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 204; ++c; continue; }
                    if (MatchCharset(*c, Charset18)) { state = 224; ++c; continue; }
                    if (MatchCharset(*c, Charset19)) { state = 245; ++c; continue; }
                    if (MatchCharset(*c, Charset20)) { state = 266; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 302; ++c; continue; }
                    if (MatchCharset(*c, Charset22)) { state = 329; ++c; continue; }
                    if (MatchCharset(*c, Charset23)) { state = 357; ++c; continue; }
                    if (MatchCharset(*c, Charset24)) { state = 385; ++c; continue; }
                    if (MatchCharset(*c, Charset25)) { state = 391; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 468; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 481; ++c; continue; }
                    if (MatchCharset(*c, Charset28)) { state = 544; ++c; continue; }
                    return -1;

                case 1:
                    return 2;

                case 2:
                    if (MatchCharset(*c, Charset29)) { state = 2; ++c; continue; }
                    return 3;

                case 3:
                    return 4;

                case 4:
                    return 5;

                case 5:
                    return 6;

                case 6:
                    if (MatchCharset(*c, Charset5)) { state = 6; ++c; continue; }
                    return 73;

                case 7:
                    return 88;

                case 8:
                    if (MatchCharset(*c, Charset30)) { state = 9; ++c; continue; }
                    return -1;

                case 9:
                    if (MatchCharset(*c, Charset9)) { state = 10; ++c; continue; }
                    return -1;

                case 10:
                    if (MatchCharset(*c, Charset21)) { state = 11; ++c; continue; }
                    return -1;

                case 11:
                    if (MatchCharset(*c, Charset15)) { state = 12; ++c; continue; }
                    return -1;

                case 12:
                    if (MatchCharset(*c, Charset31)) { state = 13; ++c; continue; }
                    return -1;

                case 13:
                    if (MatchCharset(*c, Charset15)) { state = 14; ++c; continue; }
                    return -1;

                case 14:
                    if (MatchCharset(*c, Charset22)) { state = 15; ++c; continue; }
                    return -1;

                case 15:
                    if (MatchCharset(*c, Charset30)) { state = 16; ++c; continue; }
                    return -1;

                case 16:
                    if (MatchCharset(*c, Charset8)) { state = 17; ++c; continue; }
                    return -1;

                case 17:
                    if (MatchCharset(*c, Charset16)) { state = 18; ++c; continue; }
                    return -1;

                case 18:
                    return 122;

                case 19:
                    if (MatchCharset(*c, Charset24)) { state = 20; ++c; continue; }
                    return -1;

                case 20:
                    if (MatchCharset(*c, Charset15)) { state = 21; ++c; continue; }
                    return -1;

                case 21:
                    if (MatchCharset(*c, Charset30)) { state = 22; ++c; continue; }
                    return -1;

                case 22:
                    if (MatchCharset(*c, Charset24)) { state = 23; ++c; continue; }
                    return -1;

                case 23:
                    return 123;

                case 24:
                    return 129;

                case 25:
                    return 130;

                case 26:
                    if (MatchCharset(*c, Charset29)) { state = 2; ++c; continue; }
                    return 105;

                case 27:
                    if (MatchCharset(*c, Charset6)) { state = 28; ++c; continue; }
                    return 88;

                case 28:
                    return 88;

                case 29:
                    if (MatchCharset(*c, Charset15)) { state = 30; ++c; continue; }
                    if (MatchCharset(*c, Charset18)) { state = 39; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 44; ++c; continue; }
                    if (MatchCharset(*c, Charset23)) { state = 46; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 51; ++c; continue; }
                    if (MatchCharset(*c, Charset9)) { state = 56; ++c; continue; }
                    if (MatchCharset(*c, Charset19)) { state = 58; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 65; ++c; continue; }
                    return -1;

                case 30:
                    if (MatchCharset(*c, Charset21)) { state = 31; ++c; continue; }
                    return -1;

                case 31:
                    if (MatchCharset(*c, Charset16)) { state = 32; ++c; continue; }
                    return -1;

                case 32:
                    if (MatchCharset(*c, Charset31)) { state = 33; ++c; continue; }
                    return -1;

                case 33:
                    if (MatchCharset(*c, Charset14)) { state = 34; ++c; continue; }
                    return -1;

                case 34:
                    if (MatchCharset(*c, Charset8)) { state = 35; ++c; continue; }
                    return -1;

                case 35:
                    if (MatchCharset(*c, Charset26)) { state = 36; ++c; continue; }
                    return -1;

                case 36:
                    if (MatchCharset(*c, Charset27)) { state = 37; ++c; continue; }
                    return -1;

                case 37:
                    if (MatchCharset(*c, Charset7)) { state = 38; ++c; continue; }
                    return -1;

                case 38:
                    return 7;

                case 39:
                    if (MatchCharset(*c, Charset26)) { state = 40; ++c; continue; }
                    return -1;

                case 40:
                    if (MatchCharset(*c, Charset13)) { state = 41; ++c; continue; }
                    return -1;

                case 41:
                    if (MatchCharset(*c, Charset21)) { state = 42; ++c; continue; }
                    return -1;

                case 42:
                    if (MatchCharset(*c, Charset16)) { state = 43; ++c; continue; }
                    return -1;

                case 43:
                    return 8;

                case 44:
                    if (MatchCharset(*c, Charset26)) { state = 45; ++c; continue; }
                    return -1;

                case 45:
                    return 11;

                case 46:
                    if (MatchCharset(*c, Charset8)) { state = 47; ++c; continue; }
                    return -1;

                case 47:
                    if (MatchCharset(*c, Charset22)) { state = 48; ++c; continue; }
                    return -1;

                case 48:
                    if (MatchCharset(*c, Charset17)) { state = 49; ++c; continue; }
                    return -1;

                case 49:
                    if (MatchCharset(*c, Charset7)) { state = 50; ++c; continue; }
                    return -1;

                case 50:
                    return 12;

                case 51:
                    if (MatchCharset(*c, Charset22)) { state = 52; ++c; continue; }
                    return -1;

                case 52:
                    if (MatchCharset(*c, Charset17)) { state = 53; ++c; continue; }
                    return -1;

                case 53:
                    if (MatchCharset(*c, Charset17)) { state = 54; ++c; continue; }
                    return -1;

                case 54:
                    if (MatchCharset(*c, Charset25)) { state = 55; ++c; continue; }
                    return -1;

                case 55:
                    return 15;

                case 56:
                    if (MatchCharset(*c, Charset17)) { state = 57; ++c; continue; }
                    return -1;

                case 57:
                    return 16;

                case 58:
                    if (MatchCharset(*c, Charset17)) { state = 59; ++c; continue; }
                    if (MatchCharset(*c, Charset19)) { state = 60; ++c; continue; }
                    return -1;

                case 59:
                    return 9;

                case 60:
                    if (MatchCharset(*c, Charset26)) { state = 61; ++c; continue; }
                    return -1;

                case 61:
                    if (MatchCharset(*c, Charset17)) { state = 62; ++c; continue; }
                    return -1;

                case 62:
                    if (MatchCharset(*c, Charset27)) { state = 63; ++c; continue; }
                    return -1;

                case 63:
                    if (MatchCharset(*c, Charset27)) { state = 64; ++c; continue; }
                    return -1;

                case 64:
                    return 10;

                case 65:
                    if (MatchCharset(*c, Charset23)) { state = 66; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 69; ++c; continue; }
                    return -1;

                case 66:
                    if (MatchCharset(*c, Charset30)) { state = 67; ++c; continue; }
                    return -1;

                case 67:
                    if (MatchCharset(*c, Charset26)) { state = 68; ++c; continue; }
                    return -1;

                case 68:
                    return 13;

                case 69:
                    if (MatchCharset(*c, Charset30)) { state = 70; ++c; continue; }
                    return -1;

                case 70:
                    if (MatchCharset(*c, Charset28)) { state = 71; ++c; continue; }
                    return -1;

                case 71:
                    return 14;

                case 72:
                    if (MatchCharset(*c, Charset17)) { state = 73; ++c; continue; }
                    if (MatchCharset(*c, Charset22)) { state = 76; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 84; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 89; ++c; continue; }
                    return -1;

                case 73:
                    if (MatchCharset(*c, Charset22)) { state = 74; ++c; continue; }
                    return -1;

                case 74:
                    if (MatchCharset(*c, Charset7)) { state = 75; ++c; continue; }
                    return -1;

                case 75:
                    return 17;

                case 76:
                    if (MatchCharset(*c, Charset13)) { state = 77; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 81; ++c; continue; }
                    return -1;

                case 77:
                    if (MatchCharset(*c, Charset16)) { state = 78; ++c; continue; }
                    return -1;

                case 78:
                    if (MatchCharset(*c, Charset17)) { state = 79; ++c; continue; }
                    return -1;

                case 79:
                    if (MatchCharset(*c, Charset27)) { state = 80; ++c; continue; }
                    return -1;

                case 80:
                    return 18;

                case 81:
                    if (MatchCharset(*c, Charset27)) { state = 82; ++c; continue; }
                    return -1;

                case 82:
                    if (MatchCharset(*c, Charset27)) { state = 83; ++c; continue; }
                    return -1;

                case 83:
                    return 19;

                case 84:
                    if (MatchCharset(*c, Charset30)) { state = 85; ++c; continue; }
                    if (MatchCharset(*c, Charset28)) { state = 88; ++c; continue; }
                    return -1;

                case 85:
                    if (MatchCharset(*c, Charset7)) { state = 86; ++c; continue; }
                    return -1;

                case 86:
                    if (MatchCharset(*c, Charset27)) { state = 87; ++c; continue; }
                    return -1;

                case 87:
                    return 20;

                case 88:
                    return 21;

                case 89:
                    if (MatchCharset(*c, Charset32)) { state = 90; ++c; continue; }
                    return -1;

                case 90:
                    if (MatchCharset(*c, Charset13)) { state = 91; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 96; ++c; continue; }
                    if (MatchCharset(*c, Charset28)) { state = 100; ++c; continue; }
                    return -1;

                case 91:
                    if (MatchCharset(*c, Charset26)) { state = 92; ++c; continue; }
                    return -1;

                case 92:
                    if (MatchCharset(*c, Charset23)) { state = 93; ++c; continue; }
                    return -1;

                case 93:
                    if (MatchCharset(*c, Charset30)) { state = 94; ++c; continue; }
                    return -1;

                case 94:
                    if (MatchCharset(*c, Charset26)) { state = 95; ++c; continue; }
                    return -1;

                case 95:
                    return 22;

                case 96:
                    if (MatchCharset(*c, Charset7)) { state = 97; ++c; continue; }
                    return -1;

                case 97:
                    if (MatchCharset(*c, Charset17)) { state = 98; ++c; continue; }
                    return -1;

                case 98:
                    if (MatchCharset(*c, Charset23)) { state = 99; ++c; continue; }
                    return -1;

                case 99:
                    return 23;

                case 100:
                    if (MatchCharset(*c, Charset17)) { state = 101; ++c; continue; }
                    return -1;

                case 101:
                    if (MatchCharset(*c, Charset13)) { state = 102; ++c; continue; }
                    return -1;

                case 102:
                    if (MatchCharset(*c, Charset25)) { state = 103; ++c; continue; }
                    return -1;

                case 103:
                    if (MatchCharset(*c, Charset30)) { state = 104; ++c; continue; }
                    return -1;

                case 104:
                    if (MatchCharset(*c, Charset24)) { state = 105; ++c; continue; }
                    return -1;

                case 105:
                    return 24;

                case 106:
                    if (MatchCharset(*c, Charset13)) { state = 107; ++c; continue; }
                    if (MatchCharset(*c, Charset20)) { state = 110; ++c; continue; }
                    if (MatchCharset(*c, Charset22)) { state = 114; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 117; ++c; continue; }
                    if (MatchCharset(*c, Charset8)) { state = 120; ++c; continue; }
                    return -1;

                case 107:
                    if (MatchCharset(*c, Charset25)) { state = 108; ++c; continue; }
                    return -1;

                case 108:
                    if (MatchCharset(*c, Charset17)) { state = 109; ++c; continue; }
                    return -1;

                case 109:
                    return 25;

                case 110:
                    if (MatchCharset(*c, Charset13)) { state = 111; ++c; continue; }
                    return -1;

                case 111:
                    if (MatchCharset(*c, Charset21)) { state = 112; ++c; continue; }
                    return -1;

                case 112:
                    if (MatchCharset(*c, Charset24)) { state = 113; ++c; continue; }
                    return -1;

                case 113:
                    return 26;

                case 114:
                    if (MatchCharset(*c, Charset8)) { state = 115; ++c; continue; }
                    return -1;

                case 115:
                    if (MatchCharset(*c, Charset14)) { state = 116; ++c; continue; }
                    return -1;

                case 116:
                    return 27;

                case 117:
                    if (MatchCharset(*c, Charset22)) { state = 118; ++c; continue; }
                    return -1;

                case 118:
                    if (MatchCharset(*c, Charset16)) { state = 119; ++c; continue; }
                    return -1;

                case 119:
                    return 28;

                case 120:
                    if (MatchCharset(*c, Charset26)) { state = 121; ++c; continue; }
                    return -1;

                case 121:
                    if (MatchCharset(*c, Charset27)) { state = 122; ++c; continue; }
                    return -1;

                case 122:
                    if (MatchCharset(*c, Charset17)) { state = 123; ++c; continue; }
                    return -1;

                case 123:
                    return 29;

                case 124:
                    if (MatchCharset(*c, Charset17)) { state = 125; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 128; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 150; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 185; ++c; continue; }
                    return 30;

                case 125:
                    if (MatchCharset(*c, Charset13)) { state = 126; ++c; continue; }
                    return -1;

                case 126:
                    if (MatchCharset(*c, Charset16)) { state = 127; ++c; continue; }
                    return -1;

                case 127:
                    return 34;

                case 128:
                    if (MatchCharset(*c, Charset19)) { state = 129; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 133; ++c; continue; }
                    if (MatchCharset(*c, Charset10)) { state = 135; ++c; continue; }
                    return -1;

                case 129:
                    if (MatchCharset(*c, Charset19)) { state = 130; ++c; continue; }
                    return -1;

                case 130:
                    if (MatchCharset(*c, Charset17)) { state = 131; ++c; continue; }
                    return -1;

                case 131:
                    if (MatchCharset(*c, Charset26)) { state = 132; ++c; continue; }
                    return -1;

                case 132:
                    return 31;

                case 133:
                    if (MatchCharset(*c, Charset32)) { state = 134; ++c; continue; }
                    return -1;

                case 134:
                    return 32;

                case 135:
                    if (MatchCharset(*c, Charset31)) { state = 136; ++c; continue; }
                    return -1;

                case 136:
                    if (MatchCharset(*c, Charset30)) { state = 137; ++c; continue; }
                    return -1;

                case 137:
                    if (MatchCharset(*c, Charset18)) { state = 138; ++c; continue; }
                    return -1;

                case 138:
                    if (MatchCharset(*c, Charset31)) { state = 139; ++c; continue; }
                    return -1;

                case 139:
                    if (MatchCharset(*c, Charset25)) { state = 140; ++c; continue; }
                    return -1;

                case 140:
                    if (MatchCharset(*c, Charset26)) { state = 141; ++c; continue; }
                    return -1;

                case 141:
                    if (MatchCharset(*c, Charset30)) { state = 142; ++c; continue; }
                    return -1;

                case 142:
                    if (MatchCharset(*c, Charset7)) { state = 143; ++c; continue; }
                    return -1;

                case 143:
                    if (MatchCharset(*c, Charset17)) { state = 144; ++c; continue; }
                    return -1;

                case 144:
                    if (MatchCharset(*c, Charset15)) { state = 145; ++c; continue; }
                    return -1;

                case 145:
                    if (MatchCharset(*c, Charset7)) { state = 146; ++c; continue; }
                    return -1;

                case 146:
                    if (MatchCharset(*c, Charset21)) { state = 147; ++c; continue; }
                    return -1;

                case 147:
                    if (MatchCharset(*c, Charset30)) { state = 148; ++c; continue; }
                    return -1;

                case 148:
                    if (MatchCharset(*c, Charset24)) { state = 149; ++c; continue; }
                    return -1;

                case 149:
                    return 33;

                case 150:
                    if (MatchCharset(*c, Charset27)) { state = 151; ++c; continue; }
                    return -1;

                case 151:
                    if (MatchCharset(*c, Charset25)) { state = 152; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 161; ++c; continue; }
                    return -1;

                case 152:
                    if (MatchCharset(*c, Charset17)) { state = 153; ++c; continue; }
                    return -1;

                case 153:
                    if (MatchCharset(*c, Charset22)) { state = 154; ++c; continue; }
                    return -1;

                case 154:
                    if (MatchCharset(*c, Charset31)) { state = 155; ++c; continue; }
                    return -1;

                case 155:
                    if (MatchCharset(*c, Charset23)) { state = 156; ++c; continue; }
                    return -1;

                case 156:
                    if (MatchCharset(*c, Charset13)) { state = 157; ++c; continue; }
                    return -1;

                case 157:
                    if (MatchCharset(*c, Charset19)) { state = 158; ++c; continue; }
                    return -1;

                case 158:
                    if (MatchCharset(*c, Charset21)) { state = 159; ++c; continue; }
                    return -1;

                case 159:
                    if (MatchCharset(*c, Charset15)) { state = 160; ++c; continue; }
                    return -1;

                case 160:
                    return 41;

                case 161:
                    if (MatchCharset(*c, Charset13)) { state = 162; ++c; continue; }
                    return -1;

                case 162:
                    if (MatchCharset(*c, Charset27)) { state = 163; ++c; continue; }
                    return -1;

                case 163:
                    if (MatchCharset(*c, Charset17)) { state = 164; ++c; continue; }
                    return -1;

                case 164:
                    if (MatchCharset(*c, Charset33)) { state = 165; ++c; continue; }
                    if (MatchCharset(*c, Charset34)) { state = 166; ++c; continue; }
                    if (MatchCharset(*c, Charset35)) { state = 167; ++c; continue; }
                    if (MatchCharset(*c, Charset31)) { state = 168; ++c; continue; }
                    return -1;

                case 165:
                    return 38;

                case 166:
                    return 39;

                case 167:
                    return 40;

                case 168:
                    if (MatchCharset(*c, Charset23)) { state = 169; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 175; ++c; continue; }
                    if (MatchCharset(*c, Charset28)) { state = 181; ++c; continue; }
                    return -1;

                case 169:
                    if (MatchCharset(*c, Charset17)) { state = 170; ++c; continue; }
                    return -1;

                case 170:
                    if (MatchCharset(*c, Charset16)) { state = 171; ++c; continue; }
                    return -1;

                case 171:
                    if (MatchCharset(*c, Charset21)) { state = 172; ++c; continue; }
                    return -1;

                case 172:
                    if (MatchCharset(*c, Charset8)) { state = 173; ++c; continue; }
                    return -1;

                case 173:
                    if (MatchCharset(*c, Charset23)) { state = 174; ++c; continue; }
                    return -1;

                case 174:
                    return 35;

                case 175:
                    if (MatchCharset(*c, Charset17)) { state = 176; ++c; continue; }
                    return -1;

                case 176:
                    if (MatchCharset(*c, Charset36)) { state = 177; ++c; continue; }
                    return -1;

                case 177:
                    if (MatchCharset(*c, Charset17)) { state = 178; ++c; continue; }
                    return -1;

                case 178:
                    if (MatchCharset(*c, Charset26)) { state = 179; ++c; continue; }
                    return -1;

                case 179:
                    if (MatchCharset(*c, Charset17)) { state = 180; ++c; continue; }
                    return -1;

                case 180:
                    return 36;

                case 181:
                    if (MatchCharset(*c, Charset17)) { state = 182; ++c; continue; }
                    return -1;

                case 182:
                    if (MatchCharset(*c, Charset13)) { state = 183; ++c; continue; }
                    return -1;

                case 183:
                    if (MatchCharset(*c, Charset32)) { state = 184; ++c; continue; }
                    return -1;

                case 184:
                    return 37;

                case 185:
                    if (MatchCharset(*c, Charset8)) { state = 186; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 189; ++c; continue; }
                    return -1;

                case 186:
                    if (MatchCharset(*c, Charset24)) { state = 187; ++c; continue; }
                    return -1;

                case 187:
                    if (MatchCharset(*c, Charset32)) { state = 188; ++c; continue; }
                    return -1;

                case 188:
                    return 44;

                case 189:
                    if (MatchCharset(*c, Charset19)) { state = 190; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 200; ++c; continue; }
                    return -1;

                case 190:
                    if (MatchCharset(*c, Charset30)) { state = 191; ++c; continue; }
                    return -1;

                case 191:
                    if (MatchCharset(*c, Charset24)) { state = 192; ++c; continue; }
                    return -1;

                case 192:
                    if (MatchCharset(*c, Charset31)) { state = 193; ++c; continue; }
                    return -1;

                case 193:
                    if (MatchCharset(*c, Charset14)) { state = 194; ++c; continue; }
                    return -1;

                case 194:
                    if (MatchCharset(*c, Charset26)) { state = 195; ++c; continue; }
                    return -1;

                case 195:
                    if (MatchCharset(*c, Charset17)) { state = 196; ++c; continue; }
                    return -1;

                case 196:
                    if (MatchCharset(*c, Charset13)) { state = 197; ++c; continue; }
                    return -1;

                case 197:
                    if (MatchCharset(*c, Charset7)) { state = 198; ++c; continue; }
                    return -1;

                case 198:
                    if (MatchCharset(*c, Charset20)) { state = 199; ++c; continue; }
                    return -1;

                case 199:
                    return 42;

                case 200:
                    if (MatchCharset(*c, Charset24)) { state = 201; ++c; continue; }
                    return -1;

                case 201:
                    if (MatchCharset(*c, Charset27)) { state = 202; ++c; continue; }
                    return -1;

                case 202:
                    if (MatchCharset(*c, Charset25)) { state = 203; ++c; continue; }
                    return -1;

                case 203:
                    return 43;

                case 204:
                    if (MatchCharset(*c, Charset13)) { state = 205; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 209; ++c; continue; }
                    if (MatchCharset(*c, Charset9)) { state = 213; ++c; continue; }
                    if (MatchCharset(*c, Charset24)) { state = 219; ++c; continue; }
                    return 45;

                case 205:
                    if (MatchCharset(*c, Charset26)) { state = 206; ++c; continue; }
                    return -1;

                case 206:
                    if (MatchCharset(*c, Charset7)) { state = 207; ++c; continue; }
                    return -1;

                case 207:
                    if (MatchCharset(*c, Charset20)) { state = 208; ++c; continue; }
                    return -1;

                case 208:
                    return 46;

                case 209:
                    if (MatchCharset(*c, Charset26)) { state = 210; ++c; continue; }
                    return -1;

                case 210:
                    if (MatchCharset(*c, Charset13)) { state = 211; ++c; continue; }
                    return -1;

                case 211:
                    if (MatchCharset(*c, Charset16)) { state = 212; ++c; continue; }
                    return -1;

                case 212:
                    return 49;

                case 213:
                    if (MatchCharset(*c, Charset25)) { state = 214; ++c; continue; }
                    return -1;

                case 214:
                    if (MatchCharset(*c, Charset22)) { state = 215; ++c; continue; }
                    return -1;

                case 215:
                    if (MatchCharset(*c, Charset30)) { state = 216; ++c; continue; }
                    return -1;

                case 216:
                    if (MatchCharset(*c, Charset16)) { state = 217; ++c; continue; }
                    return -1;

                case 217:
                    if (MatchCharset(*c, Charset17)) { state = 218; ++c; continue; }
                    return -1;

                case 218:
                    return 50;

                case 219:
                    if (MatchCharset(*c, Charset17)) { state = 220; ++c; continue; }
                    return -1;

                case 220:
                    if (MatchCharset(*c, Charset26)) { state = 221; ++c; continue; }
                    return -1;

                case 221:
                    if (MatchCharset(*c, Charset19)) { state = 222; ++c; continue; }
                    return 47;

                case 222:
                    if (MatchCharset(*c, Charset10)) { state = 223; ++c; continue; }
                    return -1;

                case 223:
                    return 48;

                case 224:
                    if (MatchCharset(*c, Charset13)) { state = 225; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 228; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 231; ++c; continue; }
                    return -1;

                case 225:
                    if (MatchCharset(*c, Charset7)) { state = 226; ++c; continue; }
                    return -1;

                case 226:
                    if (MatchCharset(*c, Charset17)) { state = 227; ++c; continue; }
                    return -1;

                case 227:
                    return 51;

                case 228:
                    if (MatchCharset(*c, Charset17)) { state = 229; ++c; continue; }
                    return -1;

                case 229:
                    if (MatchCharset(*c, Charset17)) { state = 230; ++c; continue; }
                    return -1;

                case 230:
                    return 56;

                case 231:
                    if (MatchCharset(*c, Charset26)) { state = 232; ++c; continue; }
                    return -1;

                case 232:
                    if (MatchCharset(*c, Charset17)) { state = 233; ++c; continue; }
                    return -1;

                case 233:
                    if (MatchCharset(*c, Charset31)) { state = 234; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 239; ++c; continue; }
                    if (MatchCharset(*c, Charset14)) { state = 241; ++c; continue; }
                    return 52;

                case 234:
                    if (MatchCharset(*c, Charset14)) { state = 235; ++c; continue; }
                    return -1;

                case 235:
                    if (MatchCharset(*c, Charset30)) { state = 236; ++c; continue; }
                    return -1;

                case 236:
                    if (MatchCharset(*c, Charset22)) { state = 237; ++c; continue; }
                    return -1;

                case 237:
                    if (MatchCharset(*c, Charset7)) { state = 238; ++c; continue; }
                    return -1;

                case 238:
                    return 53;

                case 239:
                    if (MatchCharset(*c, Charset26)) { state = 240; ++c; continue; }
                    return -1;

                case 240:
                    return 54;

                case 241:
                    if (MatchCharset(*c, Charset13)) { state = 242; ++c; continue; }
                    return -1;

                case 242:
                    if (MatchCharset(*c, Charset22)) { state = 243; ++c; continue; }
                    return -1;

                case 243:
                    if (MatchCharset(*c, Charset22)) { state = 244; ++c; continue; }
                    return -1;

                case 244:
                    return 55;

                case 245:
                    if (MatchCharset(*c, Charset13)) { state = 246; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 254; ++c; continue; }
                    if (MatchCharset(*c, Charset22)) { state = 256; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 261; ++c; continue; }
                    return 57;

                case 246:
                    if (MatchCharset(*c, Charset8)) { state = 247; ++c; continue; }
                    return -1;

                case 247:
                    if (MatchCharset(*c, Charset24)) { state = 248; ++c; continue; }
                    return -1;

                case 248:
                    if (MatchCharset(*c, Charset7)) { state = 249; ++c; continue; }
                    return -1;

                case 249:
                    if (MatchCharset(*c, Charset22)) { state = 250; ++c; continue; }
                    return -1;

                case 250:
                    if (MatchCharset(*c, Charset17)) { state = 251; ++c; continue; }
                    return -1;

                case 251:
                    if (MatchCharset(*c, Charset7)) { state = 252; ++c; continue; }
                    return -1;

                case 252:
                    if (MatchCharset(*c, Charset27)) { state = 253; ++c; continue; }
                    return -1;

                case 253:
                    return 58;

                case 254:
                    if (MatchCharset(*c, Charset23)) { state = 255; ++c; continue; }
                    return -1;

                case 255:
                    return 59;

                case 256:
                    if (MatchCharset(*c, Charset30)) { state = 257; ++c; continue; }
                    return -1;

                case 257:
                    if (MatchCharset(*c, Charset14)) { state = 258; ++c; continue; }
                    return -1;

                case 258:
                    if (MatchCharset(*c, Charset13)) { state = 259; ++c; continue; }
                    return -1;

                case 259:
                    if (MatchCharset(*c, Charset22)) { state = 260; ++c; continue; }
                    return -1;

                case 260:
                    return 60;

                case 261:
                    if (MatchCharset(*c, Charset30)) { state = 262; ++c; continue; }
                    return -1;

                case 262:
                    if (MatchCharset(*c, Charset8)) { state = 263; ++c; continue; }
                    return -1;

                case 263:
                    if (MatchCharset(*c, Charset24)) { state = 264; ++c; continue; }
                    return -1;

                case 264:
                    if (MatchCharset(*c, Charset16)) { state = 265; ++c; continue; }
                    return -1;

                case 265:
                    return 61;

                case 266:
                    if (MatchCharset(*c, Charset30)) { state = 267; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 279; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 294; ++c; continue; }
                    return -1;

                case 267:
                    if (MatchCharset(*c, Charset8)) { state = 268; ++c; continue; }
                    return -1;

                case 268:
                    if (MatchCharset(*c, Charset26)) { state = 269; ++c; continue; }
                    return -1;

                case 269:
                    if (MatchCharset(*c, Charset31)) { state = 270; ++c; continue; }
                    return -1;

                case 270:
                    if (MatchCharset(*c, Charset30)) { state = 271; ++c; continue; }
                    return -1;

                case 271:
                    if (MatchCharset(*c, Charset18)) { state = 272; ++c; continue; }
                    return -1;

                case 272:
                    if (MatchCharset(*c, Charset31)) { state = 273; ++c; continue; }
                    return -1;

                case 273:
                    if (MatchCharset(*c, Charset25)) { state = 274; ++c; continue; }
                    return -1;

                case 274:
                    if (MatchCharset(*c, Charset30)) { state = 275; ++c; continue; }
                    return -1;

                case 275:
                    if (MatchCharset(*c, Charset28)) { state = 276; ++c; continue; }
                    return -1;

                case 276:
                    if (MatchCharset(*c, Charset17)) { state = 277; ++c; continue; }
                    return -1;

                case 277:
                    if (MatchCharset(*c, Charset26)) { state = 278; ++c; continue; }
                    return -1;

                case 278:
                    return 67;

                case 279:
                    if (MatchCharset(*c, Charset23)) { state = 280; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 289; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 291; ++c; continue; }
                    return -1;

                case 280:
                    if (MatchCharset(*c, Charset23)) { state = 281; ++c; continue; }
                    return -1;

                case 281:
                    if (MatchCharset(*c, Charset17)) { state = 282; ++c; continue; }
                    return -1;

                case 282:
                    if (MatchCharset(*c, Charset26)) { state = 283; ++c; continue; }
                    return -1;

                case 283:
                    if (MatchCharset(*c, Charset20)) { state = 284; ++c; continue; }
                    return -1;

                case 284:
                    if (MatchCharset(*c, Charset13)) { state = 285; ++c; continue; }
                    return -1;

                case 285:
                    if (MatchCharset(*c, Charset24)) { state = 286; ++c; continue; }
                    return -1;

                case 286:
                    if (MatchCharset(*c, Charset16)) { state = 287; ++c; continue; }
                    return -1;

                case 287:
                    if (MatchCharset(*c, Charset27)) { state = 288; ++c; continue; }
                    return -1;

                case 288:
                    return 62;

                case 289:
                    if (MatchCharset(*c, Charset23)) { state = 290; ++c; continue; }
                    return -1;

                case 290:
                    return 63;

                case 291:
                    if (MatchCharset(*c, Charset7)) { state = 292; ++c; continue; }
                    return -1;

                case 292:
                    if (MatchCharset(*c, Charset17)) { state = 293; ++c; continue; }
                    return -1;

                case 293:
                    return 64;

                case 294:
                    if (MatchCharset(*c, Charset22)) { state = 295; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 297; ++c; continue; }
                    return -1;

                case 295:
                    if (MatchCharset(*c, Charset23)) { state = 296; ++c; continue; }
                    return -1;

                case 296:
                    return 65;

                case 297:
                    if (MatchCharset(*c, Charset30)) { state = 298; ++c; continue; }
                    return -1;

                case 298:
                    if (MatchCharset(*c, Charset21)) { state = 299; ++c; continue; }
                    return -1;

                case 299:
                    if (MatchCharset(*c, Charset27)) { state = 300; ++c; continue; }
                    return -1;

                case 300:
                    if (MatchCharset(*c, Charset23)) { state = 301; ++c; continue; }
                    return -1;

                case 301:
                    return 66;

                case 302:
                    if (MatchCharset(*c, Charset23)) { state = 303; ++c; continue; }
                    if (MatchCharset(*c, Charset15)) { state = 305; ++c; continue; }
                    if (MatchCharset(*c, Charset24)) { state = 316; ++c; continue; }
                    return -1;

                case 303:
                    if (MatchCharset(*c, Charset23)) { state = 304; ++c; continue; }
                    return -1;

                case 304:
                    return 70;

                case 305:
                    if (MatchCharset(*c, Charset17)) { state = 306; ++c; continue; }
                    return -1;

                case 306:
                    if (MatchCharset(*c, Charset31)) { state = 307; ++c; continue; }
                    return -1;

                case 307:
                    if (MatchCharset(*c, Charset14)) { state = 308; ++c; continue; }
                    return -1;

                case 308:
                    if (MatchCharset(*c, Charset22)) { state = 309; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 313; ++c; continue; }
                    return -1;

                case 309:
                    if (MatchCharset(*c, Charset13)) { state = 310; ++c; continue; }
                    return -1;

                case 310:
                    if (MatchCharset(*c, Charset27)) { state = 311; ++c; continue; }
                    return -1;

                case 311:
                    if (MatchCharset(*c, Charset7)) { state = 312; ++c; continue; }
                    return -1;

                case 312:
                    return 68;

                case 313:
                    if (MatchCharset(*c, Charset22)) { state = 314; ++c; continue; }
                    return -1;

                case 314:
                    if (MatchCharset(*c, Charset7)) { state = 315; ++c; continue; }
                    return -1;

                case 315:
                    return 69;

                case 316:
                    if (MatchCharset(*c, Charset15)) { state = 317; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 325; ++c; continue; }
                    return -1;

                case 317:
                    if (MatchCharset(*c, Charset21)) { state = 318; ++c; continue; }
                    return -1;

                case 318:
                    if (MatchCharset(*c, Charset24)) { state = 319; ++c; continue; }
                    return -1;

                case 319:
                    if (MatchCharset(*c, Charset17)) { state = 320; ++c; continue; }
                    return -1;

                case 320:
                    if (MatchCharset(*c, Charset26)) { state = 321; ++c; continue; }
                    return -1;

                case 321:
                    if (MatchCharset(*c, Charset13)) { state = 322; ++c; continue; }
                    return -1;

                case 322:
                    if (MatchCharset(*c, Charset7)) { state = 323; ++c; continue; }
                    return -1;

                case 323:
                    if (MatchCharset(*c, Charset17)) { state = 324; ++c; continue; }
                    return -1;

                case 324:
                    return 71;

                case 325:
                    if (MatchCharset(*c, Charset13)) { state = 326; ++c; continue; }
                    return -1;

                case 326:
                    if (MatchCharset(*c, Charset24)) { state = 327; ++c; continue; }
                    return -1;

                case 327:
                    if (MatchCharset(*c, Charset17)) { state = 328; ++c; continue; }
                    return -1;

                case 328:
                    return 72;

                case 329:
                    if (MatchCharset(*c, Charset17)) { state = 330; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 336; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 339; ++c; continue; }
                    return 74;

                case 330:
                    if (MatchCharset(*c, Charset13)) { state = 331; ++c; continue; }
                    return -1;

                case 331:
                    if (MatchCharset(*c, Charset7)) { state = 332; ++c; continue; }
                    return -1;

                case 332:
                    if (MatchCharset(*c, Charset20)) { state = 333; ++c; continue; }
                    return -1;

                case 333:
                    if (MatchCharset(*c, Charset17)) { state = 334; ++c; continue; }
                    return -1;

                case 334:
                    if (MatchCharset(*c, Charset26)) { state = 335; ++c; continue; }
                    return -1;

                case 335:
                    return 75;

                case 336:
                    if (MatchCharset(*c, Charset24)) { state = 337; ++c; continue; }
                    return -1;

                case 337:
                    if (MatchCharset(*c, Charset19)) { state = 338; ++c; continue; }
                    return -1;

                case 338:
                    return 80;

                case 339:
                    if (MatchCharset(*c, Charset19)) { state = 340; ++c; continue; }
                    return -1;

                case 340:
                    if (MatchCharset(*c, Charset20)) { state = 341; ++c; continue; }
                    return -1;

                case 341:
                    if (MatchCharset(*c, Charset7)) { state = 342; ++c; continue; }
                    return -1;

                case 342:
                    if (MatchCharset(*c, Charset31)) { state = 343; ++c; continue; }
                    if (MatchCharset(*c, Charset24)) { state = 348; ++c; continue; }
                    return 77;

                case 343:
                    if (MatchCharset(*c, Charset14)) { state = 344; ++c; continue; }
                    return -1;

                case 344:
                    if (MatchCharset(*c, Charset30)) { state = 345; ++c; continue; }
                    return -1;

                case 345:
                    if (MatchCharset(*c, Charset22)) { state = 346; ++c; continue; }
                    return -1;

                case 346:
                    if (MatchCharset(*c, Charset7)) { state = 347; ++c; continue; }
                    return -1;

                case 347:
                    return 78;

                case 348:
                    if (MatchCharset(*c, Charset21)) { state = 349; ++c; continue; }
                    return -1;

                case 349:
                    if (MatchCharset(*c, Charset24)) { state = 350; ++c; continue; }
                    return -1;

                case 350:
                    if (MatchCharset(*c, Charset19)) { state = 351; ++c; continue; }
                    return -1;

                case 351:
                    if (MatchCharset(*c, Charset31)) { state = 352; ++c; continue; }
                    return -1;

                case 352:
                    if (MatchCharset(*c, Charset14)) { state = 353; ++c; continue; }
                    return -1;

                case 353:
                    if (MatchCharset(*c, Charset30)) { state = 354; ++c; continue; }
                    return -1;

                case 354:
                    if (MatchCharset(*c, Charset22)) { state = 355; ++c; continue; }
                    return -1;

                case 355:
                    if (MatchCharset(*c, Charset7)) { state = 356; ++c; continue; }
                    return -1;

                case 356:
                    return 79;

                case 357:
                    if (MatchCharset(*c, Charset13)) { state = 358; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 361; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 374; ++c; continue; }
                    return 81;

                case 358:
                    if (MatchCharset(*c, Charset15)) { state = 359; ++c; continue; }
                    return -1;

                case 359:
                    if (MatchCharset(*c, Charset17)) { state = 360; ++c; continue; }
                    return -1;

                case 360:
                    return 82;

                case 361:
                    if (MatchCharset(*c, Charset16)) { state = 362; ++c; continue; }
                    if (MatchCharset(*c, Charset7)) { state = 363; ++c; continue; }
                    return -1;

                case 362:
                    return 83;

                case 363:
                    if (MatchCharset(*c, Charset17)) { state = 364; ++c; continue; }
                    return -1;

                case 364:
                    if (MatchCharset(*c, Charset30)) { state = 365; ++c; continue; }
                    return -1;

                case 365:
                    if (MatchCharset(*c, Charset26)) { state = 366; ++c; continue; }
                    return -1;

                case 366:
                    if (MatchCharset(*c, Charset31)) { state = 367; ++c; continue; }
                    return -1;

                case 367:
                    if (MatchCharset(*c, Charset27)) { state = 368; ++c; continue; }
                    return -1;

                case 368:
                    if (MatchCharset(*c, Charset20)) { state = 369; ++c; continue; }
                    return -1;

                case 369:
                    if (MatchCharset(*c, Charset30)) { state = 370; ++c; continue; }
                    return -1;

                case 370:
                    if (MatchCharset(*c, Charset28)) { state = 371; ++c; continue; }
                    return -1;

                case 371:
                    if (MatchCharset(*c, Charset17)) { state = 372; ++c; continue; }
                    return -1;

                case 372:
                    if (MatchCharset(*c, Charset26)) { state = 373; ++c; continue; }
                    return -1;

                case 373:
                    return 84;

                case 374:
                    if (MatchCharset(*c, Charset24)) { state = 375; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 383; ++c; continue; }
                    return -1;

                case 375:
                    if (MatchCharset(*c, Charset16)) { state = 376; ++c; continue; }
                    return -1;

                case 376:
                    if (MatchCharset(*c, Charset31)) { state = 377; ++c; continue; }
                    return -1;

                case 377:
                    if (MatchCharset(*c, Charset14)) { state = 378; ++c; continue; }
                    return -1;

                case 378:
                    if (MatchCharset(*c, Charset22)) { state = 379; ++c; continue; }
                    return -1;

                case 379:
                    if (MatchCharset(*c, Charset13)) { state = 380; ++c; continue; }
                    return -1;

                case 380:
                    if (MatchCharset(*c, Charset27)) { state = 381; ++c; continue; }
                    return -1;

                case 381:
                    if (MatchCharset(*c, Charset7)) { state = 382; ++c; continue; }
                    return -1;

                case 382:
                    return 85;

                case 383:
                    if (MatchCharset(*c, Charset15)) { state = 384; ++c; continue; }
                    return -1;

                case 384:
                    return 86;

                case 385:
                    if (MatchCharset(*c, Charset30)) { state = 386; ++c; continue; }
                    return 87;

                case 386:
                    if (MatchCharset(*c, Charset26)) { state = 387; ++c; continue; }
                    return -1;

                case 387:
                    if (MatchCharset(*c, Charset23)) { state = 388; ++c; continue; }
                    return -1;

                case 388:
                    if (MatchCharset(*c, Charset13)) { state = 389; ++c; continue; }
                    return -1;

                case 389:
                    if (MatchCharset(*c, Charset22)) { state = 390; ++c; continue; }
                    return -1;

                case 390:
                    return 89;

                case 391:
                    if (MatchCharset(*c, Charset22)) { state = 392; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 396; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 408; ++c; continue; }
                    if (MatchCharset(*c, Charset20)) { state = 428; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 435; ++c; continue; }
                    return -1;

                case 392:
                    if (MatchCharset(*c, Charset13)) { state = 393; ++c; continue; }
                    return -1;

                case 393:
                    if (MatchCharset(*c, Charset7)) { state = 394; ++c; continue; }
                    return -1;

                case 394:
                    if (MatchCharset(*c, Charset17)) { state = 395; ++c; continue; }
                    return -1;

                case 395:
                    return 94;

                case 396:
                    if (MatchCharset(*c, Charset10)) { state = 397; ++c; continue; }
                    return -1;

                case 397:
                    if (MatchCharset(*c, Charset15)) { state = 398; ++c; continue; }
                    return -1;

                case 398:
                    if (MatchCharset(*c, Charset20)) { state = 399; ++c; continue; }
                    return -1;

                case 399:
                    if (MatchCharset(*c, Charset21)) { state = 400; ++c; continue; }
                    return -1;

                case 400:
                    if (MatchCharset(*c, Charset15)) { state = 401; ++c; continue; }
                    return -1;

                case 401:
                    if (MatchCharset(*c, Charset31)) { state = 402; ++c; continue; }
                    return -1;

                case 402:
                    if (MatchCharset(*c, Charset27)) { state = 403; ++c; continue; }
                    return -1;

                case 403:
                    if (MatchCharset(*c, Charset20)) { state = 404; ++c; continue; }
                    return -1;

                case 404:
                    if (MatchCharset(*c, Charset30)) { state = 405; ++c; continue; }
                    return -1;

                case 405:
                    if (MatchCharset(*c, Charset15)) { state = 406; ++c; continue; }
                    return -1;

                case 406:
                    if (MatchCharset(*c, Charset32)) { state = 407; ++c; continue; }
                    return -1;

                case 407:
                    return 102;

                case 408:
                    if (MatchCharset(*c, Charset21)) { state = 409; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 422; ++c; continue; }
                    return -1;

                case 409:
                    if (MatchCharset(*c, Charset24)) { state = 410; ++c; continue; }
                    return -1;

                case 410:
                    if (MatchCharset(*c, Charset31)) { state = 411; ++c; continue; }
                    return -1;

                case 411:
                    if (MatchCharset(*c, Charset26)) { state = 412; ++c; continue; }
                    return -1;

                case 412:
                    if (MatchCharset(*c, Charset17)) { state = 413; ++c; continue; }
                    return -1;

                case 413:
                    if (MatchCharset(*c, Charset18)) { state = 414; ++c; continue; }
                    return -1;

                case 414:
                    if (MatchCharset(*c, Charset22)) { state = 415; ++c; continue; }
                    return -1;

                case 415:
                    if (MatchCharset(*c, Charset17)) { state = 416; ++c; continue; }
                    return -1;

                case 416:
                    if (MatchCharset(*c, Charset15)) { state = 417; ++c; continue; }
                    return -1;

                case 417:
                    if (MatchCharset(*c, Charset7)) { state = 418; ++c; continue; }
                    return -1;

                case 418:
                    if (MatchCharset(*c, Charset21)) { state = 419; ++c; continue; }
                    return -1;

                case 419:
                    if (MatchCharset(*c, Charset30)) { state = 420; ++c; continue; }
                    return -1;

                case 420:
                    if (MatchCharset(*c, Charset24)) { state = 421; ++c; continue; }
                    return -1;

                case 421:
                    return 90;

                case 422:
                    if (MatchCharset(*c, Charset13)) { state = 423; ++c; continue; }
                    return -1;

                case 423:
                    if (MatchCharset(*c, Charset22)) { state = 424; ++c; continue; }
                    return -1;

                case 424:
                    if (MatchCharset(*c, Charset10)) { state = 425; ++c; continue; }
                    return -1;

                case 425:
                    if (MatchCharset(*c, Charset37)) { state = 426; ++c; continue; }
                    return -1;

                case 426:
                    if (MatchCharset(*c, Charset17)) { state = 427; ++c; continue; }
                    return -1;

                case 427:
                    return 91;

                case 428:
                    if (MatchCharset(*c, Charset10)) { state = 429; ++c; continue; }
                    return -1;

                case 429:
                    if (MatchCharset(*c, Charset27)) { state = 430; ++c; continue; }
                    return -1;

                case 430:
                    if (MatchCharset(*c, Charset21)) { state = 431; ++c; continue; }
                    return 92;

                case 431:
                    if (MatchCharset(*c, Charset15)) { state = 432; ++c; continue; }
                    return -1;

                case 432:
                    if (MatchCharset(*c, Charset13)) { state = 433; ++c; continue; }
                    return -1;

                case 433:
                    if (MatchCharset(*c, Charset22)) { state = 434; ++c; continue; }
                    return -1;

                case 434:
                    return 93;

                case 435:
                    if (MatchCharset(*c, Charset28)) { state = 436; ++c; continue; }
                    if (MatchCharset(*c, Charset21)) { state = 444; ++c; continue; }
                    return -1;

                case 436:
                    if (MatchCharset(*c, Charset17)) { state = 437; ++c; continue; }
                    return -1;

                case 437:
                    if (MatchCharset(*c, Charset26)) { state = 438; ++c; continue; }
                    return -1;

                case 438:
                    if (MatchCharset(*c, Charset31)) { state = 439; ++c; continue; }
                    return -1;

                case 439:
                    if (MatchCharset(*c, Charset15)) { state = 440; ++c; continue; }
                    return -1;

                case 440:
                    if (MatchCharset(*c, Charset8)) { state = 441; ++c; continue; }
                    return -1;

                case 441:
                    if (MatchCharset(*c, Charset26)) { state = 442; ++c; continue; }
                    return -1;

                case 442:
                    if (MatchCharset(*c, Charset17)) { state = 443; ++c; continue; }
                    return -1;

                case 443:
                    return 101;

                case 444:
                    if (MatchCharset(*c, Charset27)) { state = 445; ++c; continue; }
                    return -1;

                case 445:
                    if (MatchCharset(*c, Charset30)) { state = 446; ++c; continue; }
                    return -1;

                case 446:
                    if (MatchCharset(*c, Charset24)) { state = 447; ++c; continue; }
                    return -1;

                case 447:
                    if (MatchCharset(*c, Charset33)) { state = 448; ++c; continue; }
                    if (MatchCharset(*c, Charset34)) { state = 449; ++c; continue; }
                    if (MatchCharset(*c, Charset35)) { state = 450; ++c; continue; }
                    if (MatchCharset(*c, Charset31)) { state = 451; ++c; continue; }
                    return -1;

                case 448:
                    return 98;

                case 449:
                    return 99;

                case 450:
                    return 100;

                case 451:
                    if (MatchCharset(*c, Charset23)) { state = 452; ++c; continue; }
                    if (MatchCharset(*c, Charset27)) { state = 458; ++c; continue; }
                    if (MatchCharset(*c, Charset28)) { state = 464; ++c; continue; }
                    return -1;

                case 452:
                    if (MatchCharset(*c, Charset17)) { state = 453; ++c; continue; }
                    return -1;

                case 453:
                    if (MatchCharset(*c, Charset16)) { state = 454; ++c; continue; }
                    return -1;

                case 454:
                    if (MatchCharset(*c, Charset21)) { state = 455; ++c; continue; }
                    return -1;

                case 455:
                    if (MatchCharset(*c, Charset8)) { state = 456; ++c; continue; }
                    return -1;

                case 456:
                    if (MatchCharset(*c, Charset23)) { state = 457; ++c; continue; }
                    return -1;

                case 457:
                    return 95;

                case 458:
                    if (MatchCharset(*c, Charset17)) { state = 459; ++c; continue; }
                    return -1;

                case 459:
                    if (MatchCharset(*c, Charset36)) { state = 460; ++c; continue; }
                    return -1;

                case 460:
                    if (MatchCharset(*c, Charset17)) { state = 461; ++c; continue; }
                    return -1;

                case 461:
                    if (MatchCharset(*c, Charset26)) { state = 462; ++c; continue; }
                    return -1;

                case 462:
                    if (MatchCharset(*c, Charset17)) { state = 463; ++c; continue; }
                    return -1;

                case 463:
                    return 96;

                case 464:
                    if (MatchCharset(*c, Charset17)) { state = 465; ++c; continue; }
                    return -1;

                case 465:
                    if (MatchCharset(*c, Charset13)) { state = 466; ++c; continue; }
                    return -1;

                case 466:
                    if (MatchCharset(*c, Charset32)) { state = 467; ++c; continue; }
                    return -1;

                case 467:
                    return 97;

                case 468:
                    if (MatchCharset(*c, Charset21)) { state = 469; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 472; ++c; continue; }
                    return -1;

                case 469:
                    if (MatchCharset(*c, Charset24)) { state = 470; ++c; continue; }
                    return -1;

                case 470:
                    if (MatchCharset(*c, Charset19)) { state = 471; ++c; continue; }
                    return -1;

                case 471:
                    return 103;

                case 472:
                    if (MatchCharset(*c, Charset15)) { state = 473; ++c; continue; }
                    return -1;

                case 473:
                    if (MatchCharset(*c, Charset32)) { state = 474; ++c; continue; }
                    return -1;

                case 474:
                    if (MatchCharset(*c, Charset31)) { state = 475; ++c; continue; }
                    return -1;

                case 475:
                    if (MatchCharset(*c, Charset14)) { state = 476; ++c; continue; }
                    return -1;

                case 476:
                    if (MatchCharset(*c, Charset22)) { state = 477; ++c; continue; }
                    return -1;

                case 477:
                    if (MatchCharset(*c, Charset13)) { state = 478; ++c; continue; }
                    return -1;

                case 478:
                    if (MatchCharset(*c, Charset27)) { state = 479; ++c; continue; }
                    return -1;

                case 479:
                    if (MatchCharset(*c, Charset7)) { state = 480; ++c; continue; }
                    return -1;

                case 480:
                    return 104;

                case 481:
                    if (MatchCharset(*c, Charset15)) { state = 482; ++c; continue; }
                    if (MatchCharset(*c, Charset28)) { state = 487; ++c; continue; }
                    if (MatchCharset(*c, Charset20)) { state = 491; ++c; continue; }
                    if (MatchCharset(*c, Charset25)) { state = 508; ++c; continue; }
                    if (MatchCharset(*c, Charset7)) { state = 516; ++c; continue; }
                    if (MatchCharset(*c, Charset8)) { state = 533; ++c; continue; }
                    return -1;

                case 482:
                    if (MatchCharset(*c, Charset26)) { state = 483; ++c; continue; }
                    return -1;

                case 483:
                    if (MatchCharset(*c, Charset30)) { state = 484; ++c; continue; }
                    return -1;

                case 484:
                    if (MatchCharset(*c, Charset22)) { state = 485; ++c; continue; }
                    return -1;

                case 485:
                    if (MatchCharset(*c, Charset22)) { state = 486; ++c; continue; }
                    return -1;

                case 486:
                    return 106;

                case 487:
                    if (MatchCharset(*c, Charset30)) { state = 488; ++c; continue; }
                    return -1;

                case 488:
                    if (MatchCharset(*c, Charset26)) { state = 489; ++c; continue; }
                    return -1;

                case 489:
                    if (MatchCharset(*c, Charset16)) { state = 490; ++c; continue; }
                    return -1;

                case 490:
                    return 121;

                case 491:
                    if (MatchCharset(*c, Charset21)) { state = 492; ++c; continue; }
                    if (MatchCharset(*c, Charset26)) { state = 496; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 504; ++c; continue; }
                    return -1;

                case 492:
                    if (MatchCharset(*c, Charset17)) { state = 493; ++c; continue; }
                    return -1;

                case 493:
                    if (MatchCharset(*c, Charset22)) { state = 494; ++c; continue; }
                    return -1;

                case 494:
                    if (MatchCharset(*c, Charset16)) { state = 495; ++c; continue; }
                    return -1;

                case 495:
                    return 107;

                case 496:
                    if (MatchCharset(*c, Charset13)) { state = 497; ++c; continue; }
                    return -1;

                case 497:
                    if (MatchCharset(*c, Charset25)) { state = 498; ++c; continue; }
                    return -1;

                case 498:
                    if (MatchCharset(*c, Charset23)) { state = 499; ++c; continue; }
                    return -1;

                case 499:
                    if (MatchCharset(*c, Charset17)) { state = 500; ++c; continue; }
                    return -1;

                case 500:
                    if (MatchCharset(*c, Charset7)) { state = 501; ++c; continue; }
                    return -1;

                case 501:
                    if (MatchCharset(*c, Charset13)) { state = 502; ++c; continue; }
                    return -1;

                case 502:
                    if (MatchCharset(*c, Charset22)) { state = 503; ++c; continue; }
                    return -1;

                case 503:
                    return 110;

                case 504:
                    if (MatchCharset(*c, Charset26)) { state = 505; ++c; continue; }
                    if (MatchCharset(*c, Charset7)) { state = 507; ++c; continue; }
                    return -1;

                case 505:
                    if (MatchCharset(*c, Charset7)) { state = 506; ++c; continue; }
                    return -1;

                case 506:
                    return 108;

                case 507:
                    return 109;

                case 508:
                    if (MatchCharset(*c, Charset13)) { state = 509; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 513; ++c; continue; }
                    return -1;

                case 509:
                    if (MatchCharset(*c, Charset26)) { state = 510; ++c; continue; }
                    return -1;

                case 510:
                    if (MatchCharset(*c, Charset32)) { state = 511; ++c; continue; }
                    return -1;

                case 511:
                    if (MatchCharset(*c, Charset27)) { state = 512; ++c; continue; }
                    return -1;

                case 512:
                    return 111;

                case 513:
                    if (MatchCharset(*c, Charset13)) { state = 514; ++c; continue; }
                    return -1;

                case 514:
                    if (MatchCharset(*c, Charset26)) { state = 515; ++c; continue; }
                    return -1;

                case 515:
                    return 112;

                case 516:
                    if (MatchCharset(*c, Charset17)) { state = 517; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 520; ++c; continue; }
                    if (MatchCharset(*c, Charset30)) { state = 525; ++c; continue; }
                    return -1;

                case 517:
                    if (MatchCharset(*c, Charset13)) { state = 518; ++c; continue; }
                    return -1;

                case 518:
                    if (MatchCharset(*c, Charset22)) { state = 519; ++c; continue; }
                    return -1;

                case 519:
                    return 115;

                case 520:
                    if (MatchCharset(*c, Charset18)) { state = 521; ++c; continue; }
                    if (MatchCharset(*c, Charset24)) { state = 523; ++c; continue; }
                    return -1;

                case 521:
                    if (MatchCharset(*c, Charset18)) { state = 522; ++c; continue; }
                    return -1;

                case 522:
                    return 113;

                case 523:
                    if (MatchCharset(*c, Charset16)) { state = 524; ++c; continue; }
                    return -1;

                case 524:
                    return 114;

                case 525:
                    if (MatchCharset(*c, Charset24)) { state = 526; ++c; continue; }
                    return -1;

                case 526:
                    if (MatchCharset(*c, Charset17)) { state = 527; ++c; continue; }
                    return -1;

                case 527:
                    if (MatchCharset(*c, Charset31)) { state = 528; ++c; continue; }
                    return 116;

                case 528:
                    if (MatchCharset(*c, Charset27)) { state = 529; ++c; continue; }
                    return -1;

                case 529:
                    if (MatchCharset(*c, Charset32)) { state = 530; ++c; continue; }
                    return -1;

                case 530:
                    if (MatchCharset(*c, Charset21)) { state = 531; ++c; continue; }
                    return -1;

                case 531:
                    if (MatchCharset(*c, Charset24)) { state = 532; ++c; continue; }
                    return -1;

                case 532:
                    return 117;

                case 533:
                    if (MatchCharset(*c, Charset21)) { state = 534; ++c; continue; }
                    if (MatchCharset(*c, Charset23)) { state = 540; ++c; continue; }
                    return -1;

                case 534:
                    if (MatchCharset(*c, Charset15)) { state = 535; ++c; continue; }
                    return -1;

                case 535:
                    if (MatchCharset(*c, Charset21)) { state = 536; ++c; continue; }
                    return -1;

                case 536:
                    if (MatchCharset(*c, Charset16)) { state = 537; ++c; continue; }
                    return -1;

                case 537:
                    if (MatchCharset(*c, Charset13)) { state = 538; ++c; continue; }
                    return -1;

                case 538:
                    if (MatchCharset(*c, Charset22)) { state = 539; ++c; continue; }
                    return -1;

                case 539:
                    return 119;

                case 540:
                    if (MatchCharset(*c, Charset23)) { state = 541; ++c; continue; }
                    return -1;

                case 541:
                    if (MatchCharset(*c, Charset30)) { state = 542; ++c; continue; }
                    return -1;

                case 542:
                    if (MatchCharset(*c, Charset24)) { state = 543; ++c; continue; }
                    return -1;

                case 543:
                    return 120;

                case 544:
                    if (MatchCharset(*c, Charset21)) { state = 545; ++c; continue; }
                    if (MatchCharset(*c, Charset13)) { state = 548; ++c; continue; }
                    if (MatchCharset(*c, Charset17)) { state = 554; ++c; continue; }
                    return -1;

                case 545:
                    if (MatchCharset(*c, Charset23)) { state = 546; ++c; continue; }
                    return -1;

                case 546:
                    if (MatchCharset(*c, Charset25)) { state = 547; ++c; continue; }
                    return -1;

                case 547:
                    return 128;

                case 548:
                    if (MatchCharset(*c, Charset24)) { state = 549; ++c; continue; }
                    if (MatchCharset(*c, Charset7)) { state = 551; ++c; continue; }
                    return -1;

                case 549:
                    if (MatchCharset(*c, Charset16)) { state = 550; ++c; continue; }
                    return -1;

                case 550:
                    return 124;

                case 551:
                    if (MatchCharset(*c, Charset17)) { state = 552; ++c; continue; }
                    return -1;

                case 552:
                    if (MatchCharset(*c, Charset26)) { state = 553; ++c; continue; }
                    return -1;

                case 553:
                    return 125;

                case 554:
                    if (MatchCharset(*c, Charset13)) { state = 555; ++c; continue; }
                    return -1;

                case 555:
                    if (MatchCharset(*c, Charset32)) { state = 556; ++c; continue; }
                    if (MatchCharset(*c, Charset25)) { state = 557; ++c; continue; }
                    return -1;

                case 556:
                    return 126;

                case 557:
                    if (MatchCharset(*c, Charset30)) { state = 558; ++c; continue; }
                    return -1;

                case 558:
                    if (MatchCharset(*c, Charset24)) { state = 559; ++c; continue; }
                    return -1;

                case 559:
                    return 127;

                default:
                    return -1;
                }
        }
    }

    namespace LALR
    {
        struct Action
        {
            enum
            {
                Shift = 1,
                Reduce = 2,
                Goto = 3,
                Accept = 4,
            };

            const int Type;
            const int Target;
        };

        using StateActions = std::map<int, Action>;

        static constexpr inline int InitialState = 0;

        static const StateActions States[271] =
        {
            {
                { 73, { 1, 1 } },
                { 154, { 3, 2 } },
                { 155, { 3, 3 } },
                { 156, { 3, 4 } },
                { 0, { 2, 173 } },
                { 88, { 2, 173 } },
            },
            {
                { 105, { 1, 5 } },
            },
            {
                { 0, { 4, 0 } },
            },
            {
                { 0, { 2, 172 } },
                { 88, { 2, 172 } },
            },
            {
                { 88, { 1, 6 } },
                { 142, { 3, 7 } },
                { 143, { 3, 8 } },
                { 0, { 2, 168 } },
            },
            {
                { 118, { 1, 9 } },
                { 157, { 3, 10 } },
                { 158, { 3, 11 } },
                { 76, { 2, 156 } },
            },
            {
                { 88, { 1, 6 } },
                { 142, { 3, 12 } },
                { 143, { 3, 13 } },
                { 0, { 2, 168 } },
                { 73, { 2, 166 } },
            },
            {
                { 73, { 1, 1 } },
                { 155, { 3, 14 } },
            },
            {
                { 0, { 2, 169 } },
            },
            {
                { 0, { 2, 158 } },
                { 88, { 2, 158 } },
                { 105, { 2, 158 } },
            },
            {
                { 105, { 1, 15 } },
            },
            {
                { 76, { 1, 16 } },
            },
            {
                { 73, { 2, 165 } },
            },
            {
                { 0, { 2, 167 } },
            },
            {
                { 0, { 2, 171 } },
                { 88, { 2, 171 } },
            },
            {
                { 118, { 1, 9 } },
                { 157, { 3, 17 } },
                { 158, { 3, 11 } },
                { 76, { 2, 156 } },
            },
            {
                { 0, { 2, 157 } },
                { 88, { 2, 157 } },
                { 105, { 2, 157 } },
            },
            {
                { 105, { 1, 18 } },
            },
            {
                { 73, { 1, 19 } },
            },
            {
                { 105, { 1, 20 } },
            },
            {
                { 73, { 1, 21 } },
                { 144, { 3, 22 } },
            },
            {
                { 6, { 1, 23 } },
                { 105, { 2, 147 } },
            },
            {
                { 105, { 1, 24 } },
            },
            {
                { 73, { 1, 25 } },
            },
            {
                { 73, { 1, 26 } },
            },
            {
                { 105, { 2, 148 } },
            },
            {
                { 105, { 1, 27 } },
            },
            {
                { 73, { 1, 21 } },
                { 144, { 3, 28 } },
            },
            {
                { 105, { 1, 29 } },
            },
            {
                { 73, { 1, 30 } },
                { 74, { 1, 31 } },
                { 159, { 3, 32 } },
                { 160, { 3, 33 } },
                { 161, { 3, 34 } },
                { 162, { 3, 35 } },
            },
            {
                { 4, { 1, 36 } },
                { 30, { 1, 37 } },
                { 105, { 2, 71 } },
            },
            {
                { 73, { 1, 38 } },
            },
            {
                { 5, { 1, 39 } },
                { 73, { 1, 40 } },
                { 145, { 3, 41 } },
                { 160, { 3, 42 } },
                { 74, { 2, 1 } },
            },
            {
                { 5, { 1, 39 } },
                { 145, { 3, 43 } },
                { 74, { 2, 1 } },
                { 105, { 2, 69 } },
            },
            {
                { 105, { 1, 44 } },
            },
            {
                { 105, { 2, 70 } },
            },
            {
                { 5, { 2, 61 } },
                { 73, { 2, 61 } },
                { 74, { 2, 61 } },
            },
            {
                { 73, { 1, 45 } },
            },
            {
                { 12, { 1, 46 } },
                { 13, { 1, 47 } },
                { 16, { 1, 48 } },
                { 17, { 1, 49 } },
                { 20, { 1, 50 } },
                { 21, { 1, 51 } },
                { 25, { 1, 52 } },
                { 26, { 1, 53 } },
                { 27, { 1, 54 } },
                { 31, { 1, 55 } },
                { 58, { 1, 56 } },
                { 59, { 1, 57 } },
                { 65, { 1, 58 } },
                { 75, { 1, 59 } },
                { 82, { 1, 60 } },
                { 86, { 1, 61 } },
                { 94, { 1, 62 } },
                { 103, { 1, 63 } },
                { 106, { 1, 64 } },
                { 107, { 1, 65 } },
                { 112, { 1, 66 } },
                { 113, { 1, 67 } },
                { 121, { 1, 68 } },
                { 124, { 1, 69 } },
                { 127, { 1, 70 } },
                { 163, { 3, 71 } },
                { 105, { 2, 64 } },
            },
            {
                { 74, { 2, 0 } },
            },
            {
                { 30, { 1, 37 } },
            },
            {
                { 74, { 1, 31 } },
                { 162, { 3, 72 } },
            },
            {
                { 5, { 1, 39 } },
                { 145, { 3, 73 } },
                { 74, { 2, 1 } },
                { 105, { 2, 66 } },
            },
            {
                { 74, { 1, 31 } },
                { 162, { 3, 74 } },
            },
            {
                { 73, { 1, 75 } },
                { 87, { 1, 76 } },
                { 130, { 1, 77 } },
                { 134, { 3, 78 } },
            },
            {
                { 5, { 2, 62 } },
                { 74, { 2, 62 } },
                { 105, { 2, 62 } },
            },
            {
                { 105, { 2, 57 } },
            },
            {
                { 105, { 2, 37 } },
            },
            {
                { 105, { 2, 41 } },
            },
            {
                { 105, { 2, 52 } },
            },
            {
                { 105, { 2, 55 } },
            },
            {
                { 105, { 2, 43 } },
            },
            {
                { 105, { 2, 53 } },
            },
            {
                { 105, { 2, 48 } },
            },
            {
                { 105, { 2, 45 } },
            },
            {
                { 105, { 2, 40 } },
            },
            {
                { 105, { 2, 54 } },
            },
            {
                { 105, { 2, 60 } },
            },
            {
                { 105, { 2, 51 } },
            },
            {
                { 105, { 2, 47 } },
            },
            {
                { 105, { 2, 44 } },
            },
            {
                { 105, { 2, 38 } },
            },
            {
                { 105, { 2, 49 } },
            },
            {
                { 105, { 2, 56 } },
            },
            {
                { 105, { 2, 59 } },
            },
            {
                { 105, { 2, 50 } },
            },
            {
                { 105, { 2, 42 } },
            },
            {
                { 105, { 2, 46 } },
            },
            {
                { 105, { 2, 39 } },
            },
            {
                { 105, { 2, 58 } },
            },
            {
                { 105, { 2, 36 } },
            },
            {
                { 105, { 2, 63 } },
            },
            {
                { 105, { 2, 67 } },
            },
            {
                { 74, { 1, 31 } },
                { 162, { 3, 79 } },
            },
            {
                { 105, { 2, 68 } },
            },
            {
                { 105, { 2, 146 } },
            },
            {
                { 105, { 2, 145 } },
            },
            {
                { 105, { 2, 144 } },
            },
            {
                { 105, { 1, 80 } },
            },
            {
                { 105, { 2, 65 } },
            },
            {
                { 73, { 1, 75 } },
                { 87, { 1, 76 } },
                { 130, { 1, 77 } },
                { 134, { 3, 81 } },
            },
            {
                { 105, { 1, 82 } },
            },
            {
                { 56, { 1, 83 } },
                { 60, { 1, 84 } },
                { 80, { 1, 85 } },
                { 83, { 1, 86 } },
                { 108, { 1, 87 } },
                { 114, { 1, 88 } },
                { 141, { 3, 89 } },
            },
            {
                { 105, { 2, 77 } },
            },
            {
                { 105, { 2, 76 } },
            },
            {
                { 105, { 2, 75 } },
            },
            {
                { 105, { 2, 74 } },
            },
            {
                { 105, { 2, 73 } },
            },
            {
                { 105, { 2, 72 } },
            },
            {
                { 105, { 1, 90 } },
            },
            {
                { 10, { 1, 91 } },
                { 89, { 1, 92 } },
                { 119, { 1, 93 } },
                { 128, { 1, 94 } },
                { 131, { 3, 95 } },
            },
            {
                { 105, { 2, 81 } },
            },
            {
                { 105, { 2, 80 } },
            },
            {
                { 105, { 2, 78 } },
            },
            {
                { 105, { 2, 79 } },
            },
            {
                { 105, { 1, 96 } },
            },
            {
                { 73, { 1, 97 } },
            },
            {
                { 105, { 1, 98 } },
            },
            {
                { 73, { 1, 99 } },
            },
            {
                { 105, { 1, 100 } },
            },
            {
                { 73, { 1, 101 } },
            },
            {
                { 105, { 1, 102 } },
            },
            {
                { 73, { 1, 103 } },
                { 118, { 1, 9 } },
                { 133, { 3, 104 } },
                { 157, { 3, 105 } },
                { 158, { 3, 11 } },
                { 76, { 2, 156 } },
            },
            {
                { 105, { 2, 160 } },
            },
            {
                { 105, { 1, 106 } },
            },
            {
                { 105, { 2, 159 } },
            },
            {
                { 8, { 1, 107 } },
                { 9, { 1, 108 } },
                { 15, { 1, 109 } },
                { 22, { 1, 110 } },
                { 23, { 1, 111 } },
                { 24, { 1, 112 } },
                { 29, { 1, 113 } },
                { 34, { 1, 114 } },
                { 35, { 1, 115 } },
                { 36, { 1, 116 } },
                { 37, { 1, 117 } },
                { 38, { 1, 118 } },
                { 39, { 1, 119 } },
                { 40, { 1, 120 } },
                { 43, { 1, 121 } },
                { 44, { 1, 122 } },
                { 49, { 1, 123 } },
                { 72, { 1, 124 } },
                { 73, { 1, 125 } },
                { 91, { 1, 126 } },
                { 95, { 1, 127 } },
                { 96, { 1, 128 } },
                { 97, { 1, 129 } },
                { 98, { 1, 130 } },
                { 99, { 1, 131 } },
                { 100, { 1, 132 } },
                { 115, { 1, 133 } },
                { 116, { 1, 134 } },
                { 123, { 1, 135 } },
                { 126, { 1, 136 } },
                { 149, { 3, 137 } },
                { 150, { 3, 138 } },
            },
            {
                { 6, { 2, 32 } },
                { 105, { 2, 32 } },
                { 129, { 2, 32 } },
            },
            {
                { 6, { 2, 30 } },
                { 105, { 2, 30 } },
                { 129, { 2, 30 } },
            },
            {
                { 6, { 2, 6 } },
                { 105, { 2, 6 } },
                { 129, { 2, 6 } },
            },
            {
                { 6, { 2, 27 } },
                { 105, { 2, 27 } },
                { 129, { 2, 27 } },
            },
            {
                { 6, { 2, 26 } },
                { 105, { 2, 26 } },
                { 129, { 2, 26 } },
            },
            {
                { 6, { 2, 28 } },
                { 105, { 2, 28 } },
                { 129, { 2, 28 } },
            },
            {
                { 6, { 2, 4 } },
                { 105, { 2, 4 } },
                { 129, { 2, 4 } },
            },
            {
                { 6, { 2, 23 } },
                { 105, { 2, 23 } },
                { 129, { 2, 23 } },
            },
            {
                { 6, { 2, 18 } },
                { 105, { 2, 18 } },
                { 129, { 2, 18 } },
            },
            {
                { 6, { 2, 20 } },
                { 105, { 2, 20 } },
                { 129, { 2, 20 } },
            },
            {
                { 6, { 2, 16 } },
                { 105, { 2, 16 } },
                { 129, { 2, 16 } },
            },
            {
                { 6, { 2, 15 } },
                { 105, { 2, 15 } },
                { 129, { 2, 15 } },
            },
            {
                { 6, { 2, 17 } },
                { 105, { 2, 17 } },
                { 129, { 2, 17 } },
            },
            {
                { 6, { 2, 19 } },
                { 105, { 2, 19 } },
                { 129, { 2, 19 } },
            },
            {
                { 6, { 2, 31 } },
                { 105, { 2, 31 } },
                { 129, { 2, 31 } },
            },
            {
                { 6, { 2, 7 } },
                { 105, { 2, 7 } },
                { 129, { 2, 7 } },
            },
            {
                { 6, { 2, 25 } },
                { 105, { 2, 25 } },
                { 129, { 2, 25 } },
            },
            {
                { 6, { 2, 8 } },
                { 105, { 2, 8 } },
                { 129, { 2, 8 } },
            },
            {
                { 105, { 2, 35 } },
            },
            {
                { 6, { 2, 21 } },
                { 105, { 2, 21 } },
                { 129, { 2, 21 } },
            },
            {
                { 6, { 2, 12 } },
                { 105, { 2, 12 } },
                { 129, { 2, 12 } },
            },
            {
                { 6, { 2, 14 } },
                { 105, { 2, 14 } },
                { 129, { 2, 14 } },
            },
            {
                { 6, { 2, 10 } },
                { 105, { 2, 10 } },
                { 129, { 2, 10 } },
            },
            {
                { 6, { 2, 9 } },
                { 105, { 2, 9 } },
                { 129, { 2, 9 } },
            },
            {
                { 6, { 2, 11 } },
                { 105, { 2, 11 } },
                { 129, { 2, 11 } },
            },
            {
                { 6, { 2, 13 } },
                { 105, { 2, 13 } },
                { 129, { 2, 13 } },
            },
            {
                { 6, { 2, 29 } },
                { 105, { 2, 29 } },
                { 129, { 2, 29 } },
            },
            {
                { 6, { 2, 24 } },
                { 105, { 2, 24 } },
                { 129, { 2, 24 } },
            },
            {
                { 6, { 2, 22 } },
                { 105, { 2, 22 } },
                { 129, { 2, 22 } },
            },
            {
                { 6, { 2, 5 } },
                { 105, { 2, 5 } },
                { 129, { 2, 5 } },
            },
            {
                { 105, { 1, 139 } },
            },
            {
                { 6, { 1, 140 } },
                { 135, { 3, 141 } },
                { 105, { 2, 34 } },
                { 129, { 2, 3 } },
            },
            {
                { 11, { 1, 142 } },
                { 28, { 1, 143 } },
                { 32, { 1, 144 } },
                { 46, { 1, 145 } },
                { 47, { 1, 146 } },
                { 48, { 1, 147 } },
                { 52, { 1, 148 } },
                { 73, { 1, 149 } },
                { 77, { 1, 150 } },
                { 92, { 1, 151 } },
                { 93, { 1, 152 } },
                { 125, { 1, 153 } },
                { 132, { 3, 154 } },
                { 137, { 3, 155 } },
            },
            {
                { 73, { 2, 2 } },
                { 129, { 2, 2 } },
            },
            {
                { 129, { 1, 156 } },
            },
            {
                { 0, { 2, 83 } },
                { 88, { 2, 83 } },
                { 105, { 2, 83 } },
            },
            {
                { 0, { 2, 90 } },
                { 88, { 2, 90 } },
                { 105, { 2, 90 } },
            },
            {
                { 0, { 2, 89 } },
                { 88, { 2, 89 } },
                { 105, { 2, 89 } },
            },
            {
                { 0, { 2, 85 } },
                { 88, { 2, 85 } },
                { 105, { 2, 85 } },
            },
            {
                { 0, { 2, 91 } },
                { 88, { 2, 91 } },
                { 105, { 2, 91 } },
            },
            {
                { 0, { 2, 92 } },
                { 88, { 2, 92 } },
                { 105, { 2, 92 } },
            },
            {
                { 0, { 2, 82 } },
                { 88, { 2, 82 } },
                { 105, { 2, 82 } },
            },
            {
                { 0, { 2, 93 } },
                { 88, { 2, 93 } },
                { 105, { 2, 93 } },
            },
            {
                { 0, { 2, 88 } },
                { 88, { 2, 88 } },
                { 105, { 2, 88 } },
            },
            {
                { 0, { 2, 86 } },
                { 88, { 2, 86 } },
                { 105, { 2, 86 } },
            },
            {
                { 0, { 2, 87 } },
                { 88, { 2, 87 } },
                { 105, { 2, 87 } },
            },
            {
                { 0, { 2, 84 } },
                { 88, { 2, 84 } },
                { 105, { 2, 84 } },
            },
            {
                { 105, { 1, 157 } },
            },
            {
                { 105, { 1, 158 } },
            },
            {
                { 73, { 1, 159 } },
            },
            {
                { 73, { 1, 160 } },
            },
            {
                { 73, { 1, 161 } },
                { 136, { 3, 162 } },
            },
            {
                { 105, { 2, 33 } },
            },
            {
                { 105, { 1, 163 } },
            },
            {
                { 30, { 1, 164 } },
                { 6, { 2, 96 } },
                { 105, { 2, 96 } },
            },
            {
                { 105, { 1, 165 } },
            },
            {
                { 11, { 1, 142 } },
                { 28, { 1, 143 } },
                { 32, { 1, 144 } },
                { 46, { 1, 145 } },
                { 47, { 1, 146 } },
                { 48, { 1, 147 } },
                { 52, { 1, 148 } },
                { 73, { 1, 149 } },
                { 77, { 1, 150 } },
                { 92, { 1, 151 } },
                { 93, { 1, 152 } },
                { 125, { 1, 153 } },
                { 132, { 3, 166 } },
                { 137, { 3, 155 } },
            },
            {
                { 73, { 1, 167 } },
            },
            {
                { 11, { 1, 168 } },
                { 14, { 1, 169 } },
                { 32, { 1, 170 } },
                { 46, { 1, 171 } },
                { 47, { 1, 172 } },
                { 48, { 1, 173 } },
                { 52, { 1, 174 } },
                { 54, { 1, 175 } },
                { 73, { 1, 176 } },
                { 77, { 1, 177 } },
                { 125, { 1, 178 } },
                { 140, { 3, 179 } },
            },
            {
                { 105, { 1, 180 } },
            },
            {
                { 5, { 1, 181 } },
                { 6, { 2, 95 } },
                { 105, { 2, 95 } },
            },
            {
                { 105, { 2, 99 } },
            },
            {
                { 105, { 2, 104 } },
            },
            {
                { 105, { 2, 103 } },
            },
            {
                { 105, { 2, 101 } },
            },
            {
                { 105, { 2, 105 } },
            },
            {
                { 105, { 2, 106 } },
            },
            {
                { 105, { 2, 97 } },
            },
            {
                { 105, { 2, 98 } },
            },
            {
                { 105, { 2, 107 } },
            },
            {
                { 105, { 2, 102 } },
            },
            {
                { 105, { 2, 100 } },
            },
            {
                { 105, { 2, 151 } },
            },
            {
                { 73, { 1, 182 } },
                { 153, { 3, 183 } },
            },
            {
                { 73, { 1, 184 } },
            },
            {
                { 105, { 1, 185 } },
            },
            {
                { 105, { 1, 186 } },
            },
            {
                { 6, { 2, 94 } },
                { 105, { 2, 94 } },
            },
            {
                { 7, { 1, 187 } },
                { 18, { 1, 188 } },
                { 19, { 1, 189 } },
                { 33, { 1, 190 } },
                { 41, { 1, 191 } },
                { 42, { 1, 192 } },
                { 51, { 1, 193 } },
                { 53, { 1, 194 } },
                { 55, { 1, 195 } },
                { 62, { 1, 196 } },
                { 63, { 1, 197 } },
                { 64, { 1, 198 } },
                { 66, { 1, 199 } },
                { 67, { 1, 200 } },
                { 68, { 1, 201 } },
                { 69, { 1, 202 } },
                { 71, { 1, 203 } },
                { 73, { 1, 204 } },
                { 78, { 1, 205 } },
                { 79, { 1, 206 } },
                { 84, { 1, 207 } },
                { 85, { 1, 208 } },
                { 90, { 1, 209 } },
                { 101, { 1, 210 } },
                { 102, { 1, 211 } },
                { 104, { 1, 212 } },
                { 107, { 1, 213 } },
                { 110, { 1, 214 } },
                { 111, { 1, 215 } },
                { 117, { 1, 216 } },
                { 122, { 1, 217 } },
                { 151, { 3, 218 } },
                { 152, { 3, 219 } },
            },
            {
                { 73, { 1, 182 } },
                { 153, { 3, 220 } },
            },
            {
                { 6, { 2, 108 } },
            },
            {
                { 6, { 2, 109 } },
            },
            {
                { 6, { 2, 110 } },
            },
            {
                { 6, { 2, 111 } },
            },
            {
                { 6, { 2, 112 } },
            },
            {
                { 6, { 2, 113 } },
            },
            {
                { 6, { 2, 114 } },
            },
            {
                { 6, { 2, 115 } },
            },
            {
                { 6, { 2, 116 } },
            },
            {
                { 6, { 2, 117 } },
            },
            {
                { 6, { 2, 118 } },
            },
            {
                { 6, { 2, 119 } },
            },
            {
                { 6, { 2, 120 } },
            },
            {
                { 6, { 2, 121 } },
            },
            {
                { 6, { 2, 122 } },
            },
            {
                { 6, { 2, 123 } },
            },
            {
                { 6, { 2, 124 } },
            },
            {
                { 105, { 2, 143 } },
            },
            {
                { 6, { 2, 125 } },
            },
            {
                { 6, { 2, 126 } },
            },
            {
                { 6, { 2, 127 } },
            },
            {
                { 6, { 2, 128 } },
            },
            {
                { 6, { 2, 129 } },
            },
            {
                { 6, { 2, 130 } },
            },
            {
                { 6, { 2, 131 } },
            },
            {
                { 6, { 2, 132 } },
            },
            {
                { 6, { 2, 133 } },
            },
            {
                { 6, { 2, 134 } },
            },
            {
                { 6, { 2, 135 } },
            },
            {
                { 6, { 2, 136 } },
            },
            {
                { 6, { 2, 137 } },
            },
            {
                { 6, { 1, 221 } },
            },
            {
                { 105, { 2, 152 } },
            },
            {
                { 105, { 1, 222 } },
            },
            {
                { 45, { 1, 223 } },
                { 57, { 1, 224 } },
                { 81, { 1, 225 } },
                { 87, { 1, 226 } },
                { 148, { 3, 227 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 230 } },
                { 147, { 3, 231 } },
            },
            {
                { 6, { 2, 139 } },
                { 73, { 2, 139 } },
            },
            {
                { 6, { 2, 141 } },
                { 73, { 2, 141 } },
            },
            {
                { 6, { 2, 140 } },
                { 73, { 2, 140 } },
            },
            {
                { 6, { 2, 138 } },
                { 73, { 2, 138 } },
            },
            {
                { 6, { 1, 140 } },
                { 135, { 3, 232 } },
                { 73, { 2, 3 } },
            },
            {
                { 105, { 2, 150 } },
            },
            {
                { 105, { 2, 149 } },
            },
            {
                { 105, { 1, 233 } },
            },
            {
                { 105, { 1, 234 } },
            },
            {
                { 73, { 1, 235 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 236 } },
            },
            {
                { 50, { 1, 237 } },
                { 73, { 1, 238 } },
                { 109, { 1, 239 } },
                { 120, { 1, 240 } },
                { 138, { 3, 241 } },
            },
            {
                { 105, { 2, 142 } },
            },
            {
                { 105, { 1, 242 } },
            },
            {
                { 6, { 1, 243 } },
            },
            {
                { 0, { 2, 164 } },
                { 88, { 2, 164 } },
            },
            {
                { 6, { 1, 244 } },
            },
            {
                { 6, { 1, 245 } },
            },
            {
                { 0, { 2, 170 } },
                { 88, { 2, 170 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 246 } },
            },
            {
                { 73, { 1, 161 } },
                { 136, { 3, 247 } },
            },
            {
                { 129, { 1, 248 } },
            },
            {
                { 11, { 1, 249 } },
                { 61, { 1, 250 } },
                { 139, { 3, 251 } },
            },
            {
                { 105, { 1, 252 } },
            },
            {
                { 6, { 1, 253 } },
            },
            {
                { 73, { 1, 254 } },
            },
            {
                { 6, { 2, 154 } },
            },
            {
                { 6, { 2, 155 } },
            },
            {
                { 6, { 1, 255 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 256 } },
            },
            {
                { 11, { 1, 142 } },
                { 28, { 1, 143 } },
                { 32, { 1, 144 } },
                { 46, { 1, 145 } },
                { 47, { 1, 146 } },
                { 48, { 1, 147 } },
                { 52, { 1, 148 } },
                { 73, { 1, 149 } },
                { 77, { 1, 150 } },
                { 92, { 1, 151 } },
                { 93, { 1, 152 } },
                { 125, { 1, 153 } },
                { 137, { 3, 257 } },
            },
            {
                { 0, { 2, 162 } },
                { 88, { 2, 162 } },
            },
            {
                { 118, { 1, 9 } },
                { 157, { 3, 258 } },
                { 158, { 3, 11 } },
                { 76, { 2, 156 } },
            },
            {
                { 105, { 1, 259 } },
            },
            {
                { 0, { 2, 161 } },
                { 88, { 2, 161 } },
            },
            {
                { 0, { 2, 163 } },
                { 88, { 2, 163 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 260 } },
            },
            {
                { 105, { 1, 261 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 262 } },
            },
            {
                { 105, { 1, 263 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 264 } },
            },
            {
                { 105, { 1, 265 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 266 } },
            },
            {
                { 105, { 1, 267 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 268 } },
            },
            {
                { 105, { 1, 269 } },
            },
            {
                { 70, { 1, 228 } },
                { 73, { 1, 229 } },
                { 146, { 3, 270 } },
            },
            {
                { 105, { 2, 153 } },
            },
        };
    }
}
