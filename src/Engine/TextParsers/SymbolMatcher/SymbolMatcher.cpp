//
// THIS FILE IS GENERATED
//
#include "SymbolMatcher.hpp"

namespace SymbolMatcher::DFA
{
    static constexpr inline char Charset0[6] = { 9,10,11,12,13,32 };
    static constexpr inline char Charset1[1] = { 44 };
    static constexpr inline char Charset2[1] = { 43 };
    static constexpr inline char Charset3[2] = { 81,113 };
    static constexpr inline char Charset4[1] = { 34 };
    static constexpr inline char Charset5[2] = { 84,116 };
    static constexpr inline char Charset6[2] = { 88,120 };
    static constexpr inline char Charset7[2] = { 89,121 };
    static constexpr inline char Charset8[10] = { 48,49,50,51,52,53,54,55,56,57 };
    static constexpr inline char Charset9[2] = { 65,97 };
    static constexpr inline char Charset10[2] = { 66,98 };
    static constexpr inline char Charset11[2] = { 67,99 };
    static constexpr inline char Charset12[2] = { 68,100 };
    static constexpr inline char Charset13[2] = { 69,101 };
    static constexpr inline char Charset14[2] = { 70,102 };
    static constexpr inline char Charset15[2] = { 71,103 };
    static constexpr inline char Charset16[2] = { 72,104 };
    static constexpr inline char Charset17[2] = { 73,105 };
    static constexpr inline char Charset18[2] = { 76,108 };
    static constexpr inline char Charset19[2] = { 77,109 };
    static constexpr inline char Charset20[2] = { 78,110 };
    static constexpr inline char Charset21[2] = { 80,112 };
    static constexpr inline char Charset22[2] = { 82,114 };
    static constexpr inline char Charset23[2] = { 83,115 };
    static constexpr inline char Charset24[2] = { 85,117 };
    static constexpr inline char Charset25[2] = { 87,119 };
    static constexpr inline char Charset26[2] = { 79,111 };
    static constexpr inline char Charset27[1] = { 32 };
    static constexpr inline char Charset28[1] = { 45 };
    static constexpr inline char Charset29[1] = { 37 };
    static constexpr inline char Charset30[2] = { 75,107 };
    static constexpr inline char Charset31[2] = { 86,118 };
    static constexpr inline char Charset32[2] = { 90,122 };
    static constexpr inline char Charset33[1] = { 49 };
    static constexpr inline char Charset34[1] = { 50 };
    static constexpr inline char Charset35[1] = { 51 };

    template <std::size_t N>
    constexpr inline bool MatchCharset(char c, const char (&charset)[N]) requires (N > 0)
    {
        if (c < charset[0])
            return false;
        if (c > charset[N - 1])
            return false;
        auto it = std::lower_bound(std::begin(charset), std::end(charset), c);
        if (it == std::end(charset))
            return false;
        return *it == c;
    }

    int Match(int& state, const char* (&it), const char* const (&it_end))
    {
        for (bool end = false; !end; )
        {
            if (it == it_end)
                end = true;

            switch (state)
            {
            case 0:
                if (MatchCharset(*it, Charset0)) { state = 1; ++it; continue; }
                if (MatchCharset(*it, Charset1)) { state = 2; ++it; continue; }
                if (MatchCharset(*it, Charset2)) { state = 3; ++it; continue; }
                if (MatchCharset(*it, Charset3)) { state = 4; ++it; continue; }
                if (MatchCharset(*it, Charset4)) { state = 10; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 11; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 22; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 25; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 26; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 38; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 103; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 153; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 201; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 288; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 309; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 335; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 364; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 410; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 437; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 473; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 519; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 525; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 624; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 648; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 742; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 755; ++it; continue; }
                return -1;
            case 1:
                if (MatchCharset(*it, Charset0)) { state = 1; ++it; continue; }
                return 2;
            case 2:
                return 40;
            case 3:
                return 128;
            case 4:
                if (MatchCharset(*it, Charset24)) { state = 5; ++it; continue; }
                return -1;
            case 5:
                if (MatchCharset(*it, Charset9)) { state = 6; ++it; continue; }
                return -1;
            case 6:
                if (MatchCharset(*it, Charset22)) { state = 7; ++it; continue; }
                return -1;
            case 7:
                if (MatchCharset(*it, Charset22)) { state = 8; ++it; continue; }
                return -1;
            case 8:
                if (MatchCharset(*it, Charset7)) { state = 9; ++it; continue; }
                return -1;
            case 9:
                return 138;
            case 10:
                return 139;
            case 11:
                if (MatchCharset(*it, Charset26)) { state = 12; ++it; continue; }
                return -1;
            case 12:
                if (MatchCharset(*it, Charset6)) { state = 13; ++it; continue; }
                return -1;
            case 13:
                if (MatchCharset(*it, Charset17)) { state = 14; ++it; continue; }
                return -1;
            case 14:
                if (MatchCharset(*it, Charset11)) { state = 15; ++it; continue; }
                return -1;
            case 15:
                if (MatchCharset(*it, Charset27)) { state = 16; ++it; continue; }
                return -1;
            case 16:
                if (MatchCharset(*it, Charset11)) { state = 17; ++it; continue; }
                return -1;
            case 17:
                if (MatchCharset(*it, Charset18)) { state = 18; ++it; continue; }
                return -1;
            case 18:
                if (MatchCharset(*it, Charset26)) { state = 19; ++it; continue; }
                return -1;
            case 19:
                if (MatchCharset(*it, Charset24)) { state = 20; ++it; continue; }
                return -1;
            case 20:
                if (MatchCharset(*it, Charset12)) { state = 21; ++it; continue; }
                return -1;
            case 21:
                return 166;
            case 22:
                if (MatchCharset(*it, Charset0)) { state = 23; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 24; ++it; continue; }
                return -1;
            case 23:
                if (MatchCharset(*it, Charset0)) { state = 23; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 24; ++it; continue; }
                return -1;
            case 24:
                if (MatchCharset(*it, Charset8)) { state = 24; ++it; continue; }
                return 178;
            case 25:
                return 179;
            case 26:
                if (MatchCharset(*it, Charset28)) { state = 27; ++it; continue; }
                if (MatchCharset(*it, Charset1)) { state = 29; ++it; continue; }
                if (MatchCharset(*it, Charset29)) { state = 31; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 26; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 32; ++it; continue; }
                return 100;
            case 27:
                if (MatchCharset(*it, Charset8)) { state = 28; ++it; continue; }
                return -1;
            case 28:
                if (MatchCharset(*it, Charset8)) { state = 28; ++it; continue; }
                return 66;
            case 29:
                if (MatchCharset(*it, Charset8)) { state = 30; ++it; continue; }
                return -1;
            case 30:
                if (MatchCharset(*it, Charset8)) { state = 30; ++it; continue; }
                return 76;
            case 31:
                return 167;
            case 32:
                if (MatchCharset(*it, Charset8)) { state = 33; ++it; continue; }
                return -1;
            case 33:
                if (MatchCharset(*it, Charset18)) { state = 34; ++it; continue; }
                if (MatchCharset(*it, Charset2)) { state = 36; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 33; ++it; continue; }
                return 48;
            case 34:
                if (MatchCharset(*it, Charset8)) { state = 35; ++it; continue; }
                return -1;
            case 35:
                if (MatchCharset(*it, Charset8)) { state = 35; ++it; continue; }
                return 50;
            case 36:
                if (MatchCharset(*it, Charset8)) { state = 37; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 34; ++it; continue; }
                return -1;
            case 37:
                if (MatchCharset(*it, Charset8)) { state = 37; ++it; continue; }
                return 49;
            case 38:
                if (MatchCharset(*it, Charset11)) { state = 39; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 48; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 53; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 55; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 59; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 64; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 69; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 78; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 80; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 87; ++it; continue; }
                return 3;
            case 39:
                if (MatchCharset(*it, Charset17)) { state = 40; ++it; continue; }
                return -1;
            case 40:
                if (MatchCharset(*it, Charset12)) { state = 41; ++it; continue; }
                return -1;
            case 41:
                if (MatchCharset(*it, Charset27)) { state = 42; ++it; continue; }
                return -1;
            case 42:
                if (MatchCharset(*it, Charset10)) { state = 43; ++it; continue; }
                return -1;
            case 43:
                if (MatchCharset(*it, Charset24)) { state = 44; ++it; continue; }
                return -1;
            case 44:
                if (MatchCharset(*it, Charset22)) { state = 45; ++it; continue; }
                return -1;
            case 45:
                if (MatchCharset(*it, Charset23)) { state = 46; ++it; continue; }
                return -1;
            case 46:
                if (MatchCharset(*it, Charset5)) { state = 47; ++it; continue; }
                return -1;
            case 47:
                return 4;
            case 48:
                if (MatchCharset(*it, Charset22)) { state = 49; ++it; continue; }
                return -1;
            case 49:
                if (MatchCharset(*it, Charset9)) { state = 50; ++it; continue; }
                return -1;
            case 50:
                if (MatchCharset(*it, Charset17)) { state = 51; ++it; continue; }
                return -1;
            case 51:
                if (MatchCharset(*it, Charset12)) { state = 52; ++it; continue; }
                return -1;
            case 52:
                return 5;
            case 53:
                if (MatchCharset(*it, Charset22)) { state = 54; ++it; continue; }
                return -1;
            case 54:
                return 8;
            case 55:
                if (MatchCharset(*it, Charset18)) { state = 56; ++it; continue; }
                return -1;
            case 56:
                if (MatchCharset(*it, Charset13)) { state = 57; ++it; continue; }
                return -1;
            case 57:
                if (MatchCharset(*it, Charset7)) { state = 58; ++it; continue; }
                return -1;
            case 58:
                return 9;
            case 59:
                if (MatchCharset(*it, Charset24)) { state = 60; ++it; continue; }
                return -1;
            case 60:
                if (MatchCharset(*it, Charset18)) { state = 61; ++it; continue; }
                return -1;
            case 61:
                if (MatchCharset(*it, Charset13)) { state = 62; ++it; continue; }
                return -1;
            case 62:
                if (MatchCharset(*it, Charset5)) { state = 63; ++it; continue; }
                return -1;
            case 63:
                return 10;
            case 64:
                if (MatchCharset(*it, Charset18)) { state = 65; ++it; continue; }
                return -1;
            case 65:
                if (MatchCharset(*it, Charset13)) { state = 66; ++it; continue; }
                return -1;
            case 66:
                if (MatchCharset(*it, Charset13)) { state = 67; ++it; continue; }
                return -1;
            case 67:
                if (MatchCharset(*it, Charset21)) { state = 68; ++it; continue; }
                return -1;
            case 68:
                return 15;
            case 69:
                if (MatchCharset(*it, Charset12)) { state = 70; ++it; continue; }
                return -1;
            case 70:
                if (MatchCharset(*it, Charset17)) { state = 71; ++it; continue; }
                return -1;
            case 71:
                if (MatchCharset(*it, Charset5)) { state = 72; ++it; continue; }
                return -1;
            case 72:
                if (MatchCharset(*it, Charset26)) { state = 73; ++it; continue; }
                return -1;
            case 73:
                if (MatchCharset(*it, Charset22)) { state = 74; ++it; continue; }
                return -1;
            case 74:
                if (MatchCharset(*it, Charset17)) { state = 75; ++it; continue; }
                return -1;
            case 75:
                if (MatchCharset(*it, Charset24)) { state = 76; ++it; continue; }
                return -1;
            case 76:
                if (MatchCharset(*it, Charset19)) { state = 77; ++it; continue; }
                return -1;
            case 77:
                return 16;
            case 78:
                if (MatchCharset(*it, Charset13)) { state = 79; ++it; continue; }
                return -1;
            case 79:
                return 17;
            case 80:
                if (MatchCharset(*it, Charset13)) { state = 81; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 82; ++it; continue; }
                return -1;
            case 81:
                return 6;
            case 82:
                if (MatchCharset(*it, Charset22)) { state = 83; ++it; continue; }
                return -1;
            case 83:
                if (MatchCharset(*it, Charset13)) { state = 84; ++it; continue; }
                return -1;
            case 84:
                if (MatchCharset(*it, Charset23)) { state = 85; ++it; continue; }
                return -1;
            case 85:
                if (MatchCharset(*it, Charset23)) { state = 86; ++it; continue; }
                return -1;
            case 86:
                return 7;
            case 87:
                if (MatchCharset(*it, Charset13)) { state = 88; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 91; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 94; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 97; ++it; continue; }
                return -1;
            case 88:
                if (MatchCharset(*it, Charset20)) { state = 89; ++it; continue; }
                return -1;
            case 89:
                if (MatchCharset(*it, Charset9)) { state = 90; ++it; continue; }
                return -1;
            case 90:
                return 11;
            case 91:
                if (MatchCharset(*it, Charset26)) { state = 92; ++it; continue; }
                return -1;
            case 92:
                if (MatchCharset(*it, Charset22)) { state = 93; ++it; continue; }
                return -1;
            case 93:
                return 12;
            case 94:
                if (MatchCharset(*it, Charset26)) { state = 95; ++it; continue; }
                return -1;
            case 95:
                if (MatchCharset(*it, Charset25)) { state = 96; ++it; continue; }
                return -1;
            case 96:
                return 13;
            case 97:
                if (MatchCharset(*it, Charset17)) { state = 98; ++it; continue; }
                return -1;
            case 98:
                if (MatchCharset(*it, Charset14)) { state = 99; ++it; continue; }
                return -1;
            case 99:
                if (MatchCharset(*it, Charset9)) { state = 100; ++it; continue; }
                return -1;
            case 100:
                if (MatchCharset(*it, Charset11)) { state = 101; ++it; continue; }
                return -1;
            case 101:
                if (MatchCharset(*it, Charset5)) { state = 102; ++it; continue; }
                return -1;
            case 102:
                return 14;
            case 103:
                if (MatchCharset(*it, Charset9)) { state = 104; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 111; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 114; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 126; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 136; ++it; continue; }
                return 18;
            case 104:
                if (MatchCharset(*it, Charset5)) { state = 105; ++it; continue; }
                return -1;
            case 105:
                if (MatchCharset(*it, Charset16)) { state = 106; ++it; continue; }
                return -1;
            case 106:
                if (MatchCharset(*it, Charset22)) { state = 107; ++it; continue; }
                return -1;
            case 107:
                if (MatchCharset(*it, Charset26)) { state = 108; ++it; continue; }
                return -1;
            case 108:
                if (MatchCharset(*it, Charset26)) { state = 109; ++it; continue; }
                return -1;
            case 109:
                if (MatchCharset(*it, Charset19)) { state = 110; ++it; continue; }
                return -1;
            case 110:
                return 19;
            case 111:
                if (MatchCharset(*it, Charset18)) { state = 112; ++it; continue; }
                return -1;
            case 112:
                if (MatchCharset(*it, Charset5)) { state = 113; ++it; continue; }
                return -1;
            case 113:
                return 20;
            case 114:
                if (MatchCharset(*it, Charset13)) { state = 115; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 118; ++it; continue; }
                return -1;
            case 115:
                if (MatchCharset(*it, Charset23)) { state = 116; ++it; continue; }
                return -1;
            case 116:
                if (MatchCharset(*it, Charset23)) { state = 117; ++it; continue; }
                return -1;
            case 117:
                return 23;
            case 118:
                if (MatchCharset(*it, Charset12)) { state = 119; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 122; ++it; continue; }
                return -1;
            case 119:
                if (MatchCharset(*it, Charset13)) { state = 120; ++it; continue; }
                return -1;
            case 120:
                if (MatchCharset(*it, Charset23)) { state = 121; ++it; continue; }
                return -1;
            case 121:
                return 21;
            case 122:
                if (MatchCharset(*it, Charset5)) { state = 123; ++it; continue; }
                return -1;
            case 123:
                if (MatchCharset(*it, Charset13)) { state = 124; ++it; continue; }
                return -1;
            case 124:
                if (MatchCharset(*it, Charset22)) { state = 125; ++it; continue; }
                return -1;
            case 125:
                return 22;
            case 126:
                if (MatchCharset(*it, Charset5)) { state = 127; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 131; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 132; ++it; continue; }
                return -1;
            case 127:
                if (MatchCharset(*it, Charset5)) { state = 128; ++it; continue; }
                return -1;
            case 128:
                if (MatchCharset(*it, Charset18)) { state = 129; ++it; continue; }
                return -1;
            case 129:
                if (MatchCharset(*it, Charset13)) { state = 130; ++it; continue; }
                return -1;
            case 130:
                return 26;
            case 131:
                return 27;
            case 132:
                if (MatchCharset(*it, Charset30)) { state = 133; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 134; ++it; continue; }
                return -1;
            case 133:
                return 24;
            case 134:
                if (MatchCharset(*it, Charset23)) { state = 135; ++it; continue; }
                return -1;
            case 135:
                return 25;
            case 136:
                if (MatchCharset(*it, Charset30)) { state = 137; ++it; continue; }
                return -1;
            case 137:
                if (MatchCharset(*it, Charset9)) { state = 138; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 143; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 147; ++it; continue; }
                return -1;
            case 138:
                if (MatchCharset(*it, Charset22)) { state = 139; ++it; continue; }
                return -1;
            case 139:
                if (MatchCharset(*it, Charset19)) { state = 140; ++it; continue; }
                return -1;
            case 140:
                if (MatchCharset(*it, Charset26)) { state = 141; ++it; continue; }
                return -1;
            case 141:
                if (MatchCharset(*it, Charset22)) { state = 142; ++it; continue; }
                return -1;
            case 142:
                return 28;
            case 143:
                if (MatchCharset(*it, Charset5)) { state = 144; ++it; continue; }
                return -1;
            case 144:
                if (MatchCharset(*it, Charset13)) { state = 145; ++it; continue; }
                return -1;
            case 145:
                if (MatchCharset(*it, Charset19)) { state = 146; ++it; continue; }
                return -1;
            case 146:
                return 29;
            case 147:
                if (MatchCharset(*it, Charset13)) { state = 148; ++it; continue; }
                return -1;
            case 148:
                if (MatchCharset(*it, Charset9)) { state = 149; ++it; continue; }
                return -1;
            case 149:
                if (MatchCharset(*it, Charset21)) { state = 150; ++it; continue; }
                return -1;
            case 150:
                if (MatchCharset(*it, Charset26)) { state = 151; ++it; continue; }
                return -1;
            case 151:
                if (MatchCharset(*it, Charset20)) { state = 152; ++it; continue; }
                return -1;
            case 152:
                return 30;
            case 153:
                if (MatchCharset(*it, Charset16)) { state = 154; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 158; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 161; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 165; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 183; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 189; ++it; continue; }
                return 31;
            case 154:
                if (MatchCharset(*it, Charset9)) { state = 155; ++it; continue; }
                return -1;
            case 155:
                if (MatchCharset(*it, Charset17)) { state = 156; ++it; continue; }
                return -1;
            case 156:
                if (MatchCharset(*it, Charset20)) { state = 157; ++it; continue; }
                return -1;
            case 157:
                return 35;
            case 158:
                if (MatchCharset(*it, Charset5)) { state = 159; ++it; continue; }
                return -1;
            case 159:
                if (MatchCharset(*it, Charset7)) { state = 160; ++it; continue; }
                return -1;
            case 160:
                return 36;
            case 161:
                if (MatchCharset(*it, Charset22)) { state = 162; ++it; continue; }
                return -1;
            case 162:
                if (MatchCharset(*it, Charset23)) { state = 163; ++it; continue; }
                return -1;
            case 163:
                if (MatchCharset(*it, Charset13)) { state = 164; ++it; continue; }
                return -1;
            case 164:
                return 42;
            case 165:
                if (MatchCharset(*it, Charset21)) { state = 166; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 168; ++it; continue; }
                if (MatchCharset(*it, Charset31)) { state = 181; ++it; continue; }
                return -1;
            case 166:
                if (MatchCharset(*it, Charset13)) { state = 167; ++it; continue; }
                return -1;
            case 167:
                return 32;
            case 168:
                if (MatchCharset(*it, Charset21)) { state = 169; ++it; continue; }
                return -1;
            case 169:
                if (MatchCharset(*it, Charset13)) { state = 170; ++it; continue; }
                return -1;
            case 170:
                if (MatchCharset(*it, Charset5)) { state = 171; ++it; continue; }
                return -1;
            case 171:
                if (MatchCharset(*it, Charset13)) { state = 172; ++it; continue; }
                return -1;
            case 172:
                if (MatchCharset(*it, Charset12)) { state = 173; ++it; continue; }
                return -1;
            case 173:
                if (MatchCharset(*it, Charset16)) { state = 174; ++it; continue; }
                return -1;
            case 174:
                if (MatchCharset(*it, Charset9)) { state = 175; ++it; continue; }
                return -1;
            case 175:
                if (MatchCharset(*it, Charset18)) { state = 176; ++it; continue; }
                return -1;
            case 176:
                if (MatchCharset(*it, Charset18)) { state = 177; ++it; continue; }
                return -1;
            case 177:
                if (MatchCharset(*it, Charset25)) { state = 178; ++it; continue; }
                return -1;
            case 178:
                if (MatchCharset(*it, Charset9)) { state = 179; ++it; continue; }
                return -1;
            case 179:
                if (MatchCharset(*it, Charset7)) { state = 180; ++it; continue; }
                return -1;
            case 180:
                return 33;
            case 181:
                if (MatchCharset(*it, Charset13)) { state = 182; ++it; continue; }
                return -1;
            case 182:
                return 34;
            case 183:
                if (MatchCharset(*it, Charset26)) { state = 184; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 187; ++it; continue; }
                return -1;
            case 184:
                if (MatchCharset(*it, Charset9)) { state = 185; ++it; continue; }
                return -1;
            case 185:
                if (MatchCharset(*it, Charset30)) { state = 186; ++it; continue; }
                return -1;
            case 186:
                return 37;
            case 187:
                if (MatchCharset(*it, Charset10)) { state = 188; ++it; continue; }
                return -1;
            case 188:
                return 38;
            case 189:
                if (MatchCharset(*it, Charset18)) { state = 190; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 192; ++it; continue; }
                return -1;
            case 190:
                if (MatchCharset(*it, Charset12)) { state = 191; ++it; continue; }
                return -1;
            case 191:
                return 39;
            case 192:
                if (MatchCharset(*it, Charset11)) { state = 193; ++it; continue; }
                return -1;
            case 193:
                if (MatchCharset(*it, Charset13)) { state = 194; ++it; continue; }
                return -1;
            case 194:
                if (MatchCharset(*it, Charset22)) { state = 195; ++it; continue; }
                return -1;
            case 195:
                if (MatchCharset(*it, Charset5)) { state = 196; ++it; continue; }
                return -1;
            case 196:
                if (MatchCharset(*it, Charset16)) { state = 197; ++it; continue; }
                return -1;
            case 197:
                if (MatchCharset(*it, Charset9)) { state = 198; ++it; continue; }
                return -1;
            case 198:
                if (MatchCharset(*it, Charset18)) { state = 199; ++it; continue; }
                return -1;
            case 199:
                if (MatchCharset(*it, Charset18)) { state = 200; ++it; continue; }
                return -1;
            case 200:
                return 41;
            case 201:
                if (MatchCharset(*it, Charset13)) { state = 202; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 205; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 227; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 265; ++it; continue; }
                return 43;
            case 202:
                if (MatchCharset(*it, Charset9)) { state = 203; ++it; continue; }
                return -1;
            case 203:
                if (MatchCharset(*it, Charset12)) { state = 204; ++it; continue; }
                return -1;
            case 204:
                return 47;
            case 205:
                if (MatchCharset(*it, Charset15)) { state = 206; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 210; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 212; ++it; continue; }
                return -1;
            case 206:
                if (MatchCharset(*it, Charset15)) { state = 207; ++it; continue; }
                return -1;
            case 207:
                if (MatchCharset(*it, Charset13)) { state = 208; ++it; continue; }
                return -1;
            case 208:
                if (MatchCharset(*it, Charset22)) { state = 209; ++it; continue; }
                return -1;
            case 209:
                return 44;
            case 210:
                if (MatchCharset(*it, Charset30)) { state = 211; ++it; continue; }
                return -1;
            case 211:
                return 45;
            case 212:
                if (MatchCharset(*it, Charset27)) { state = 213; ++it; continue; }
                return -1;
            case 213:
                if (MatchCharset(*it, Charset26)) { state = 214; ++it; continue; }
                return -1;
            case 214:
                if (MatchCharset(*it, Charset14)) { state = 215; ++it; continue; }
                return -1;
            case 215:
                if (MatchCharset(*it, Charset27)) { state = 216; ++it; continue; }
                return -1;
            case 216:
                if (MatchCharset(*it, Charset21)) { state = 217; ++it; continue; }
                return -1;
            case 217:
                if (MatchCharset(*it, Charset22)) { state = 218; ++it; continue; }
                return -1;
            case 218:
                if (MatchCharset(*it, Charset26)) { state = 219; ++it; continue; }
                return -1;
            case 219:
                if (MatchCharset(*it, Charset5)) { state = 220; ++it; continue; }
                return -1;
            case 220:
                if (MatchCharset(*it, Charset13)) { state = 221; ++it; continue; }
                return -1;
            case 221:
                if (MatchCharset(*it, Charset11)) { state = 222; ++it; continue; }
                return -1;
            case 222:
                if (MatchCharset(*it, Charset5)) { state = 223; ++it; continue; }
                return -1;
            case 223:
                if (MatchCharset(*it, Charset17)) { state = 224; ++it; continue; }
                return -1;
            case 224:
                if (MatchCharset(*it, Charset26)) { state = 225; ++it; continue; }
                return -1;
            case 225:
                if (MatchCharset(*it, Charset20)) { state = 226; ++it; continue; }
                return -1;
            case 226:
                return 46;
            case 227:
                if (MatchCharset(*it, Charset32)) { state = 228; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 231; ++it; continue; }
                return -1;
            case 228:
                if (MatchCharset(*it, Charset32)) { state = 229; ++it; continue; }
                return -1;
            case 229:
                if (MatchCharset(*it, Charset7)) { state = 230; ++it; continue; }
                return -1;
            case 230:
                return 58;
            case 231:
                if (MatchCharset(*it, Charset21)) { state = 232; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 241; ++it; continue; }
                return -1;
            case 232:
                if (MatchCharset(*it, Charset13)) { state = 233; ++it; continue; }
                return -1;
            case 233:
                if (MatchCharset(*it, Charset18)) { state = 234; ++it; continue; }
                return -1;
            case 234:
                if (MatchCharset(*it, Charset27)) { state = 235; ++it; continue; }
                return -1;
            case 235:
                if (MatchCharset(*it, Charset19)) { state = 236; ++it; continue; }
                return -1;
            case 236:
                if (MatchCharset(*it, Charset9)) { state = 237; ++it; continue; }
                return -1;
            case 237:
                if (MatchCharset(*it, Charset15)) { state = 238; ++it; continue; }
                return -1;
            case 238:
                if (MatchCharset(*it, Charset17)) { state = 239; ++it; continue; }
                return -1;
            case 239:
                if (MatchCharset(*it, Charset11)) { state = 240; ++it; continue; }
                return -1;
            case 240:
                return 57;
            case 241:
                if (MatchCharset(*it, Charset9)) { state = 242; ++it; continue; }
                return -1;
            case 242:
                if (MatchCharset(*it, Charset23)) { state = 243; ++it; continue; }
                return -1;
            case 243:
                if (MatchCharset(*it, Charset13)) { state = 244; ++it; continue; }
                return -1;
            case 244:
                if (MatchCharset(*it, Charset33)) { state = 245; ++it; continue; }
                if (MatchCharset(*it, Charset34)) { state = 246; ++it; continue; }
                if (MatchCharset(*it, Charset35)) { state = 247; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 248; ++it; continue; }
                return -1;
            case 245:
                return 54;
            case 246:
                return 55;
            case 247:
                return 56;
            case 248:
                if (MatchCharset(*it, Charset19)) { state = 249; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 255; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 261; ++it; continue; }
                return -1;
            case 249:
                if (MatchCharset(*it, Charset13)) { state = 250; ++it; continue; }
                return -1;
            case 250:
                if (MatchCharset(*it, Charset12)) { state = 251; ++it; continue; }
                return -1;
            case 251:
                if (MatchCharset(*it, Charset17)) { state = 252; ++it; continue; }
                return -1;
            case 252:
                if (MatchCharset(*it, Charset24)) { state = 253; ++it; continue; }
                return -1;
            case 253:
                if (MatchCharset(*it, Charset19)) { state = 254; ++it; continue; }
                return -1;
            case 254:
                return 51;
            case 255:
                if (MatchCharset(*it, Charset13)) { state = 256; ++it; continue; }
                return -1;
            case 256:
                if (MatchCharset(*it, Charset31)) { state = 257; ++it; continue; }
                return -1;
            case 257:
                if (MatchCharset(*it, Charset13)) { state = 258; ++it; continue; }
                return -1;
            case 258:
                if (MatchCharset(*it, Charset22)) { state = 259; ++it; continue; }
                return -1;
            case 259:
                if (MatchCharset(*it, Charset13)) { state = 260; ++it; continue; }
                return -1;
            case 260:
                return 52;
            case 261:
                if (MatchCharset(*it, Charset13)) { state = 262; ++it; continue; }
                return -1;
            case 262:
                if (MatchCharset(*it, Charset9)) { state = 263; ++it; continue; }
                return -1;
            case 263:
                if (MatchCharset(*it, Charset30)) { state = 264; ++it; continue; }
                return -1;
            case 264:
                return 53;
            case 265:
                if (MatchCharset(*it, Charset9)) { state = 266; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 281; ++it; continue; }
                return -1;
            case 266:
                if (MatchCharset(*it, Charset15)) { state = 267; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 277; ++it; continue; }
                return -1;
            case 267:
                if (MatchCharset(*it, Charset26)) { state = 268; ++it; continue; }
                return -1;
            case 268:
                if (MatchCharset(*it, Charset20)) { state = 269; ++it; continue; }
                return -1;
            case 269:
                if (MatchCharset(*it, Charset27)) { state = 270; ++it; continue; }
                return -1;
            case 270:
                if (MatchCharset(*it, Charset10)) { state = 271; ++it; continue; }
                return -1;
            case 271:
                if (MatchCharset(*it, Charset22)) { state = 272; ++it; continue; }
                return -1;
            case 272:
                if (MatchCharset(*it, Charset13)) { state = 273; ++it; continue; }
                return -1;
            case 273:
                if (MatchCharset(*it, Charset9)) { state = 274; ++it; continue; }
                return -1;
            case 274:
                if (MatchCharset(*it, Charset5)) { state = 275; ++it; continue; }
                return -1;
            case 275:
                if (MatchCharset(*it, Charset16)) { state = 276; ++it; continue; }
                return -1;
            case 276:
                return 59;
            case 277:
                if (MatchCharset(*it, Charset20)) { state = 278; ++it; continue; }
                return -1;
            case 278:
                if (MatchCharset(*it, Charset23)) { state = 279; ++it; continue; }
                return -1;
            case 279:
                if (MatchCharset(*it, Charset21)) { state = 280; ++it; continue; }
                return -1;
            case 280:
                return 60;
            case 281:
                if (MatchCharset(*it, Charset15)) { state = 282; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 286; ++it; continue; }
                return -1;
            case 282:
                if (MatchCharset(*it, Charset15)) { state = 283; ++it; continue; }
                return -1;
            case 283:
                if (MatchCharset(*it, Charset13)) { state = 284; ++it; continue; }
                return -1;
            case 284:
                if (MatchCharset(*it, Charset12)) { state = 285; ++it; continue; }
                return -1;
            case 285:
                return 61;
            case 286:
                if (MatchCharset(*it, Charset30)) { state = 287; ++it; continue; }
                return -1;
            case 287:
                return 62;
            case 288:
                if (MatchCharset(*it, Charset9)) { state = 289; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 293; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 294; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 298; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 304; ++it; continue; }
                return 63;
            case 289:
                if (MatchCharset(*it, Charset22)) { state = 290; ++it; continue; }
                return -1;
            case 290:
                if (MatchCharset(*it, Charset5)) { state = 291; ++it; continue; }
                return -1;
            case 291:
                if (MatchCharset(*it, Charset16)) { state = 292; ++it; continue; }
                return -1;
            case 292:
                return 64;
            case 293:
                if (MatchCharset(*it, Charset8)) { state = 293; ++it; continue; }
                return 65;
            case 294:
                if (MatchCharset(*it, Charset22)) { state = 295; ++it; continue; }
                return -1;
            case 295:
                if (MatchCharset(*it, Charset9)) { state = 296; ++it; continue; }
                return -1;
            case 296:
                if (MatchCharset(*it, Charset12)) { state = 297; ++it; continue; }
                return -1;
            case 297:
                return 69;
            case 298:
                if (MatchCharset(*it, Charset21)) { state = 299; ++it; continue; }
                return -1;
            case 299:
                if (MatchCharset(*it, Charset18)) { state = 300; ++it; continue; }
                return -1;
            case 300:
                if (MatchCharset(*it, Charset26)) { state = 301; ++it; continue; }
                return -1;
            case 301:
                if (MatchCharset(*it, Charset12)) { state = 302; ++it; continue; }
                return -1;
            case 302:
                if (MatchCharset(*it, Charset13)) { state = 303; ++it; continue; }
                return -1;
            case 303:
                return 70;
            case 304:
                if (MatchCharset(*it, Charset13)) { state = 305; ++it; continue; }
                return -1;
            case 305:
                if (MatchCharset(*it, Charset22)) { state = 306; ++it; continue; }
                return -1;
            case 306:
                if (MatchCharset(*it, Charset15)) { state = 307; ++it; continue; }
                return 67;
            case 307:
                if (MatchCharset(*it, Charset7)) { state = 308; ++it; continue; }
                return -1;
            case 308:
                return 68;
            case 309:
                if (MatchCharset(*it, Charset9)) { state = 310; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 313; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 318; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 321; ++it; continue; }
                return -1;
            case 310:
                if (MatchCharset(*it, Charset5)) { state = 311; ++it; continue; }
                return -1;
            case 311:
                if (MatchCharset(*it, Charset13)) { state = 312; ++it; continue; }
                return -1;
            case 312:
                return 71;
            case 313:
                if (MatchCharset(*it, Charset22)) { state = 314; ++it; continue; }
                return -1;
            case 314:
                if (MatchCharset(*it, Charset13)) { state = 315; ++it; continue; }
                return -1;
            case 315:
                if (MatchCharset(*it, Charset23)) { state = 316; ++it; continue; }
                return -1;
            case 316:
                if (MatchCharset(*it, Charset5)) { state = 317; ++it; continue; }
                return -1;
            case 317:
                return 77;
            case 318:
                if (MatchCharset(*it, Charset13)) { state = 319; ++it; continue; }
                return -1;
            case 319:
                if (MatchCharset(*it, Charset13)) { state = 320; ++it; continue; }
                return -1;
            case 320:
                return 78;
            case 321:
                if (MatchCharset(*it, Charset22)) { state = 322; ++it; continue; }
                return -1;
            case 322:
                if (MatchCharset(*it, Charset13)) { state = 323; ++it; continue; }
                return -1;
            case 323:
                if (MatchCharset(*it, Charset27)) { state = 324; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 329; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 331; ++it; continue; }
                return 72;
            case 324:
                if (MatchCharset(*it, Charset10)) { state = 325; ++it; continue; }
                return -1;
            case 325:
                if (MatchCharset(*it, Charset26)) { state = 326; ++it; continue; }
                return -1;
            case 326:
                if (MatchCharset(*it, Charset18)) { state = 327; ++it; continue; }
                return -1;
            case 327:
                if (MatchCharset(*it, Charset5)) { state = 328; ++it; continue; }
                return -1;
            case 328:
                return 73;
            case 329:
                if (MatchCharset(*it, Charset22)) { state = 330; ++it; continue; }
                return -1;
            case 330:
                return 74;
            case 331:
                if (MatchCharset(*it, Charset9)) { state = 332; ++it; continue; }
                return -1;
            case 332:
                if (MatchCharset(*it, Charset18)) { state = 333; ++it; continue; }
                return -1;
            case 333:
                if (MatchCharset(*it, Charset18)) { state = 334; ++it; continue; }
                return -1;
            case 334:
                return 75;
            case 335:
                if (MatchCharset(*it, Charset9)) { state = 336; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 344; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 349; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 352; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 357; ++it; continue; }
                return 79;
            case 336:
                if (MatchCharset(*it, Charset24)) { state = 337; ++it; continue; }
                return -1;
            case 337:
                if (MatchCharset(*it, Charset20)) { state = 338; ++it; continue; }
                return -1;
            case 338:
                if (MatchCharset(*it, Charset5)) { state = 339; ++it; continue; }
                return -1;
            case 339:
                if (MatchCharset(*it, Charset18)) { state = 340; ++it; continue; }
                return -1;
            case 340:
                if (MatchCharset(*it, Charset13)) { state = 341; ++it; continue; }
                return -1;
            case 341:
                if (MatchCharset(*it, Charset5)) { state = 342; ++it; continue; }
                return -1;
            case 342:
                if (MatchCharset(*it, Charset23)) { state = 343; ++it; continue; }
                return -1;
            case 343:
                return 80;
            case 344:
                if (MatchCharset(*it, Charset26)) { state = 345; ++it; continue; }
                return -1;
            case 345:
                if (MatchCharset(*it, Charset10)) { state = 346; ++it; continue; }
                return -1;
            case 346:
                if (MatchCharset(*it, Charset9)) { state = 347; ++it; continue; }
                return -1;
            case 347:
                if (MatchCharset(*it, Charset18)) { state = 348; ++it; continue; }
                return -1;
            case 348:
                return 83;
            case 349:
                if (MatchCharset(*it, Charset18)) { state = 350; ++it; continue; }
                return -1;
            case 350:
                if (MatchCharset(*it, Charset12)) { state = 351; ++it; continue; }
                return -1;
            case 351:
                return 84;
            case 352:
                if (MatchCharset(*it, Charset26)) { state = 353; ++it; continue; }
                return -1;
            case 353:
                if (MatchCharset(*it, Charset24)) { state = 354; ++it; continue; }
                return -1;
            case 354:
                if (MatchCharset(*it, Charset20)) { state = 355; ++it; continue; }
                return -1;
            case 355:
                if (MatchCharset(*it, Charset12)) { state = 356; ++it; continue; }
                return -1;
            case 356:
                return 85;
            case 357:
                if (MatchCharset(*it, Charset19)) { state = 358; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 359; ++it; continue; }
                return -1;
            case 358:
                return 81;
            case 359:
                if (MatchCharset(*it, Charset13)) { state = 360; ++it; continue; }
                return -1;
            case 360:
                if (MatchCharset(*it, Charset22)) { state = 361; ++it; continue; }
                return -1;
            case 361:
                if (MatchCharset(*it, Charset17)) { state = 362; ++it; continue; }
                return -1;
            case 362:
                if (MatchCharset(*it, Charset11)) { state = 363; ++it; continue; }
                return -1;
            case 363:
                return 82;
            case 364:
                if (MatchCharset(*it, Charset26)) { state = 365; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 377; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 401; ++it; continue; }
                return -1;
            case 365:
                if (MatchCharset(*it, Charset24)) { state = 366; ++it; continue; }
                return -1;
            case 366:
                if (MatchCharset(*it, Charset22)) { state = 367; ++it; continue; }
                return -1;
            case 367:
                if (MatchCharset(*it, Charset27)) { state = 368; ++it; continue; }
                return -1;
            case 368:
                if (MatchCharset(*it, Charset26)) { state = 369; ++it; continue; }
                return -1;
            case 369:
                if (MatchCharset(*it, Charset14)) { state = 370; ++it; continue; }
                return -1;
            case 370:
                if (MatchCharset(*it, Charset27)) { state = 371; ++it; continue; }
                return -1;
            case 371:
                if (MatchCharset(*it, Charset21)) { state = 372; ++it; continue; }
                return -1;
            case 372:
                if (MatchCharset(*it, Charset26)) { state = 373; ++it; continue; }
                return -1;
            case 373:
                if (MatchCharset(*it, Charset25)) { state = 374; ++it; continue; }
                return -1;
            case 374:
                if (MatchCharset(*it, Charset13)) { state = 375; ++it; continue; }
                return -1;
            case 375:
                if (MatchCharset(*it, Charset22)) { state = 376; ++it; continue; }
                return -1;
            case 376:
                return 94;
            case 377:
                if (MatchCharset(*it, Charset18)) { state = 378; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 383; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 392; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 396; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 398; ++it; continue; }
                return -1;
            case 378:
                if (MatchCharset(*it, Charset18)) { state = 379; ++it; continue; }
                return -1;
            case 379:
                if (MatchCharset(*it, Charset25)) { state = 380; ++it; continue; }
                return -1;
            case 380:
                if (MatchCharset(*it, Charset9)) { state = 381; ++it; continue; }
                return -1;
            case 381:
                if (MatchCharset(*it, Charset7)) { state = 382; ++it; continue; }
                return -1;
            case 382:
                return 86;
            case 383:
                if (MatchCharset(*it, Charset19)) { state = 384; ++it; continue; }
                return -1;
            case 384:
                if (MatchCharset(*it, Charset13)) { state = 385; ++it; continue; }
                return -1;
            case 385:
                if (MatchCharset(*it, Charset22)) { state = 386; ++it; continue; }
                return -1;
            case 386:
                if (MatchCharset(*it, Charset16)) { state = 387; ++it; continue; }
                return -1;
            case 387:
                if (MatchCharset(*it, Charset9)) { state = 388; ++it; continue; }
                return -1;
            case 388:
                if (MatchCharset(*it, Charset20)) { state = 389; ++it; continue; }
                return -1;
            case 389:
                if (MatchCharset(*it, Charset12)) { state = 390; ++it; continue; }
                return -1;
            case 390:
                if (MatchCharset(*it, Charset23)) { state = 391; ++it; continue; }
                return -1;
            case 391:
                return 87;
            case 392:
                if (MatchCharset(*it, Charset15)) { state = 393; ++it; continue; }
                return -1;
            case 393:
                if (MatchCharset(*it, Charset9)) { state = 394; ++it; continue; }
                return -1;
            case 394:
                if (MatchCharset(*it, Charset22)) { state = 395; ++it; continue; }
                return -1;
            case 395:
                return 88;
            case 396:
                if (MatchCharset(*it, Charset19)) { state = 397; ++it; continue; }
                return -1;
            case 397:
                return 89;
            case 398:
                if (MatchCharset(*it, Charset5)) { state = 399; ++it; continue; }
                return -1;
            case 399:
                if (MatchCharset(*it, Charset13)) { state = 400; ++it; continue; }
                return -1;
            case 400:
                return 90;
            case 401:
                if (MatchCharset(*it, Charset18)) { state = 402; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 404; ++it; continue; }
                return -1;
            case 402:
                if (MatchCharset(*it, Charset19)) { state = 403; ++it; continue; }
                return -1;
            case 403:
                return 91;
            case 404:
                if (MatchCharset(*it, Charset10)) { state = 405; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 406; ++it; continue; }
                return -1;
            case 405:
                return 92;
            case 406:
                if (MatchCharset(*it, Charset17)) { state = 407; ++it; continue; }
                return -1;
            case 407:
                if (MatchCharset(*it, Charset23)) { state = 408; ++it; continue; }
                return -1;
            case 408:
                if (MatchCharset(*it, Charset19)) { state = 409; ++it; continue; }
                return -1;
            case 409:
                return 93;
            case 410:
                if (MatchCharset(*it, Charset19)) { state = 411; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 413; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 424; ++it; continue; }
                return -1;
            case 411:
                if (MatchCharset(*it, Charset19)) { state = 412; ++it; continue; }
                return -1;
            case 412:
                return 97;
            case 413:
                if (MatchCharset(*it, Charset13)) { state = 414; ++it; continue; }
                return -1;
            case 414:
                if (MatchCharset(*it, Charset27)) { state = 415; ++it; continue; }
                return -1;
            case 415:
                if (MatchCharset(*it, Charset10)) { state = 416; ++it; continue; }
                return -1;
            case 416:
                if (MatchCharset(*it, Charset18)) { state = 417; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 421; ++it; continue; }
                return -1;
            case 417:
                if (MatchCharset(*it, Charset9)) { state = 418; ++it; continue; }
                return -1;
            case 418:
                if (MatchCharset(*it, Charset23)) { state = 419; ++it; continue; }
                return -1;
            case 419:
                if (MatchCharset(*it, Charset5)) { state = 420; ++it; continue; }
                return -1;
            case 420:
                return 95;
            case 421:
                if (MatchCharset(*it, Charset18)) { state = 422; ++it; continue; }
                return -1;
            case 422:
                if (MatchCharset(*it, Charset5)) { state = 423; ++it; continue; }
                return -1;
            case 423:
                return 96;
            case 424:
                if (MatchCharset(*it, Charset11)) { state = 425; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 433; ++it; continue; }
                return -1;
            case 425:
                if (MatchCharset(*it, Charset17)) { state = 426; ++it; continue; }
                return -1;
            case 426:
                if (MatchCharset(*it, Charset20)) { state = 427; ++it; continue; }
                return -1;
            case 427:
                if (MatchCharset(*it, Charset13)) { state = 428; ++it; continue; }
                return -1;
            case 428:
                if (MatchCharset(*it, Charset22)) { state = 429; ++it; continue; }
                return -1;
            case 429:
                if (MatchCharset(*it, Charset9)) { state = 430; ++it; continue; }
                return -1;
            case 430:
                if (MatchCharset(*it, Charset5)) { state = 431; ++it; continue; }
                return -1;
            case 431:
                if (MatchCharset(*it, Charset13)) { state = 432; ++it; continue; }
                return -1;
            case 432:
                return 98;
            case 433:
                if (MatchCharset(*it, Charset9)) { state = 434; ++it; continue; }
                return -1;
            case 434:
                if (MatchCharset(*it, Charset20)) { state = 435; ++it; continue; }
                return -1;
            case 435:
                if (MatchCharset(*it, Charset13)) { state = 436; ++it; continue; }
                return -1;
            case 436:
                return 99;
            case 437:
                if (MatchCharset(*it, Charset13)) { state = 438; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 444; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 447; ++it; continue; }
                return -1;
            case 438:
                if (MatchCharset(*it, Charset9)) { state = 439; ++it; continue; }
                return -1;
            case 439:
                if (MatchCharset(*it, Charset5)) { state = 440; ++it; continue; }
                return -1;
            case 440:
                if (MatchCharset(*it, Charset16)) { state = 441; ++it; continue; }
                return -1;
            case 441:
                if (MatchCharset(*it, Charset13)) { state = 442; ++it; continue; }
                return -1;
            case 442:
                if (MatchCharset(*it, Charset22)) { state = 443; ++it; continue; }
                return -1;
            case 443:
                return 101;
            case 444:
                if (MatchCharset(*it, Charset20)) { state = 445; ++it; continue; }
                return -1;
            case 445:
                if (MatchCharset(*it, Charset15)) { state = 446; ++it; continue; }
                return -1;
            case 446:
                return 106;
            case 447:
                if (MatchCharset(*it, Charset31)) { state = 448; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 456; ++it; continue; }
                return -1;
            case 448:
                if (MatchCharset(*it, Charset17)) { state = 449; ++it; continue; }
                return -1;
            case 449:
                if (MatchCharset(*it, Charset20)) { state = 450; ++it; continue; }
                return -1;
            case 450:
                if (MatchCharset(*it, Charset15)) { state = 451; ++it; continue; }
                return -1;
            case 451:
                if (MatchCharset(*it, Charset22)) { state = 452; ++it; continue; }
                return -1;
            case 452:
                if (MatchCharset(*it, Charset26)) { state = 453; ++it; continue; }
                return -1;
            case 453:
                if (MatchCharset(*it, Charset26)) { state = 454; ++it; continue; }
                return -1;
            case 454:
                if (MatchCharset(*it, Charset19)) { state = 455; ++it; continue; }
                return -1;
            case 455:
                return 105;
            case 456:
                if (MatchCharset(*it, Charset16)) { state = 457; ++it; continue; }
                return -1;
            case 457:
                if (MatchCharset(*it, Charset5)) { state = 458; ++it; continue; }
                return -1;
            case 458:
                if (MatchCharset(*it, Charset27)) { state = 459; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 464; ++it; continue; }
                return 102;
            case 459:
                if (MatchCharset(*it, Charset10)) { state = 460; ++it; continue; }
                return -1;
            case 460:
                if (MatchCharset(*it, Charset26)) { state = 461; ++it; continue; }
                return -1;
            case 461:
                if (MatchCharset(*it, Charset18)) { state = 462; ++it; continue; }
                return -1;
            case 462:
                if (MatchCharset(*it, Charset5)) { state = 463; ++it; continue; }
                return -1;
            case 463:
                return 103;
            case 464:
                if (MatchCharset(*it, Charset17)) { state = 465; ++it; continue; }
                return -1;
            case 465:
                if (MatchCharset(*it, Charset20)) { state = 466; ++it; continue; }
                return -1;
            case 466:
                if (MatchCharset(*it, Charset15)) { state = 467; ++it; continue; }
                return -1;
            case 467:
                if (MatchCharset(*it, Charset27)) { state = 468; ++it; continue; }
                return -1;
            case 468:
                if (MatchCharset(*it, Charset10)) { state = 469; ++it; continue; }
                return -1;
            case 469:
                if (MatchCharset(*it, Charset26)) { state = 470; ++it; continue; }
                return -1;
            case 470:
                if (MatchCharset(*it, Charset18)) { state = 471; ++it; continue; }
                return -1;
            case 471:
                if (MatchCharset(*it, Charset5)) { state = 472; ++it; continue; }
                return -1;
            case 472:
                return 104;
            case 473:
                if (MatchCharset(*it, Charset9)) { state = 474; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 477; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 478; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 485; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 491; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 504; ++it; continue; }
                return 107;
            case 474:
                if (MatchCharset(*it, Charset11)) { state = 475; ++it; continue; }
                return -1;
            case 475:
                if (MatchCharset(*it, Charset13)) { state = 476; ++it; continue; }
                return -1;
            case 476:
                return 108;
            case 477:
                if (MatchCharset(*it, Charset8)) { state = 477; ++it; continue; }
                return 114;
            case 478:
                if (MatchCharset(*it, Charset24)) { state = 479; ++it; continue; }
                return -1;
            case 479:
                if (MatchCharset(*it, Charset20)) { state = 480; ++it; continue; }
                return -1;
            case 480:
                if (MatchCharset(*it, Charset5)) { state = 481; ++it; continue; }
                return -1;
            case 481:
                if (MatchCharset(*it, Charset9)) { state = 482; ++it; continue; }
                return -1;
            case 482:
                if (MatchCharset(*it, Charset17)) { state = 483; ++it; continue; }
                return -1;
            case 483:
                if (MatchCharset(*it, Charset20)) { state = 484; ++it; continue; }
                return -1;
            case 484:
                return 115;
            case 485:
                if (MatchCharset(*it, Charset11)) { state = 486; ++it; continue; }
                return -1;
            case 486:
                if (MatchCharset(*it, Charset22)) { state = 487; ++it; continue; }
                return -1;
            case 487:
                if (MatchCharset(*it, Charset26)) { state = 488; ++it; continue; }
                return -1;
            case 488:
                if (MatchCharset(*it, Charset18)) { state = 489; ++it; continue; }
                return -1;
            case 489:
                if (MatchCharset(*it, Charset18)) { state = 490; ++it; continue; }
                return -1;
            case 490:
                return 116;
            case 491:
                if (MatchCharset(*it, Charset12)) { state = 492; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 493; ++it; continue; }
                return -1;
            case 492:
                return 109;
            case 493:
                if (MatchCharset(*it, Charset13)) { state = 494; ++it; continue; }
                return -1;
            case 494:
                if (MatchCharset(*it, Charset26)) { state = 495; ++it; continue; }
                return -1;
            case 495:
                if (MatchCharset(*it, Charset22)) { state = 496; ++it; continue; }
                return -1;
            case 496:
                if (MatchCharset(*it, Charset27)) { state = 497; ++it; continue; }
                return -1;
            case 497:
                if (MatchCharset(*it, Charset23)) { state = 498; ++it; continue; }
                return -1;
            case 498:
                if (MatchCharset(*it, Charset16)) { state = 499; ++it; continue; }
                return -1;
            case 499:
                if (MatchCharset(*it, Charset26)) { state = 500; ++it; continue; }
                return -1;
            case 500:
                if (MatchCharset(*it, Charset25)) { state = 501; ++it; continue; }
                return -1;
            case 501:
                if (MatchCharset(*it, Charset13)) { state = 502; ++it; continue; }
                return -1;
            case 502:
                if (MatchCharset(*it, Charset22)) { state = 503; ++it; continue; }
                return -1;
            case 503:
                return 110;
            case 504:
                if (MatchCharset(*it, Charset20)) { state = 505; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 513; ++it; continue; }
                return -1;
            case 505:
                if (MatchCharset(*it, Charset12)) { state = 506; ++it; continue; }
                return -1;
            case 506:
                if (MatchCharset(*it, Charset27)) { state = 507; ++it; continue; }
                return -1;
            case 507:
                if (MatchCharset(*it, Charset10)) { state = 508; ++it; continue; }
                return -1;
            case 508:
                if (MatchCharset(*it, Charset18)) { state = 509; ++it; continue; }
                return -1;
            case 509:
                if (MatchCharset(*it, Charset9)) { state = 510; ++it; continue; }
                return -1;
            case 510:
                if (MatchCharset(*it, Charset23)) { state = 511; ++it; continue; }
                return -1;
            case 511:
                if (MatchCharset(*it, Charset5)) { state = 512; ++it; continue; }
                return -1;
            case 512:
                return 111;
            case 513:
                if (MatchCharset(*it, Charset11)) { state = 514; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 515; ++it; continue; }
                return -1;
            case 514:
                return 112;
            case 515:
                if (MatchCharset(*it, Charset17)) { state = 516; ++it; continue; }
                return -1;
            case 516:
                if (MatchCharset(*it, Charset18)) { state = 517; ++it; continue; }
                return -1;
            case 517:
                if (MatchCharset(*it, Charset13)) { state = 518; ++it; continue; }
                return -1;
            case 518:
                return 113;
            case 519:
                if (MatchCharset(*it, Charset26)) { state = 520; ++it; continue; }
                return 117;
            case 520:
                if (MatchCharset(*it, Charset22)) { state = 521; ++it; continue; }
                return 118;
            case 521:
                if (MatchCharset(*it, Charset19)) { state = 522; ++it; continue; }
                return -1;
            case 522:
                if (MatchCharset(*it, Charset9)) { state = 523; ++it; continue; }
                return -1;
            case 523:
                if (MatchCharset(*it, Charset18)) { state = 524; ++it; continue; }
                return -1;
            case 524:
                return 119;
            case 525:
                if (MatchCharset(*it, Charset9)) { state = 526; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 561; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 568; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 575; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 608; ++it; continue; }
                return -1;
            case 526:
                if (MatchCharset(*it, Charset12)) { state = 527; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 535; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 548; ++it; continue; }
                return -1;
            case 527:
                if (MatchCharset(*it, Charset12)) { state = 528; ++it; continue; }
                return -1;
            case 528:
                if (MatchCharset(*it, Charset13)) { state = 529; ++it; continue; }
                return -1;
            case 529:
                if (MatchCharset(*it, Charset12)) { state = 530; ++it; continue; }
                return -1;
            case 530:
                if (MatchCharset(*it, Charset11)) { state = 531; ++it; continue; }
                return -1;
            case 531:
                if (MatchCharset(*it, Charset13)) { state = 532; ++it; continue; }
                return -1;
            case 532:
                if (MatchCharset(*it, Charset18)) { state = 533; ++it; continue; }
                return -1;
            case 533:
                if (MatchCharset(*it, Charset18)) { state = 534; ++it; continue; }
                return -1;
            case 534:
                return 120;
            case 535:
                if (MatchCharset(*it, Charset20)) { state = 536; ++it; continue; }
                return -1;
            case 536:
                if (MatchCharset(*it, Charset27)) { state = 537; ++it; continue; }
                return -1;
            case 537:
                if (MatchCharset(*it, Charset22)) { state = 538; ++it; continue; }
                return -1;
            case 538:
                if (MatchCharset(*it, Charset13)) { state = 539; ++it; continue; }
                return -1;
            case 539:
                if (MatchCharset(*it, Charset14)) { state = 540; ++it; continue; }
                return -1;
            case 540:
                if (MatchCharset(*it, Charset18)) { state = 541; ++it; continue; }
                return -1;
            case 541:
                if (MatchCharset(*it, Charset13)) { state = 542; ++it; continue; }
                return -1;
            case 542:
                if (MatchCharset(*it, Charset11)) { state = 543; ++it; continue; }
                return -1;
            case 543:
                if (MatchCharset(*it, Charset5)) { state = 544; ++it; continue; }
                return -1;
            case 544:
                if (MatchCharset(*it, Charset17)) { state = 545; ++it; continue; }
                return -1;
            case 545:
                if (MatchCharset(*it, Charset26)) { state = 546; ++it; continue; }
                return -1;
            case 546:
                if (MatchCharset(*it, Charset20)) { state = 547; ++it; continue; }
                return -1;
            case 547:
                return 121;
            case 548:
                if (MatchCharset(*it, Charset9)) { state = 549; ++it; continue; }
                if (MatchCharset(*it, Charset30)) { state = 554; ++it; continue; }
                return -1;
            case 549:
                if (MatchCharset(*it, Charset18)) { state = 550; ++it; continue; }
                return -1;
            case 550:
                if (MatchCharset(*it, Charset7)) { state = 551; ++it; continue; }
                return -1;
            case 551:
                if (MatchCharset(*it, Charset32)) { state = 552; ++it; continue; }
                return -1;
            case 552:
                if (MatchCharset(*it, Charset13)) { state = 553; ++it; continue; }
                return -1;
            case 553:
                return 122;
            case 554:
                if (MatchCharset(*it, Charset17)) { state = 555; ++it; continue; }
                return -1;
            case 555:
                if (MatchCharset(*it, Charset20)) { state = 556; ++it; continue; }
                return -1;
            case 556:
                if (MatchCharset(*it, Charset15)) { state = 557; ++it; continue; }
                return -1;
            case 557:
                if (MatchCharset(*it, Charset18)) { state = 558; ++it; continue; }
                return -1;
            case 558:
                if (MatchCharset(*it, Charset26)) { state = 559; ++it; continue; }
                return -1;
            case 559:
                if (MatchCharset(*it, Charset5)) { state = 560; ++it; continue; }
                return -1;
            case 560:
                return 123;
            case 561:
                if (MatchCharset(*it, Charset7)) { state = 562; ++it; continue; }
                return -1;
            case 562:
                if (MatchCharset(*it, Charset23)) { state = 563; ++it; continue; }
                return -1;
            case 563:
                if (MatchCharset(*it, Charset17)) { state = 564; ++it; continue; }
                return 124;
            case 564:
                if (MatchCharset(*it, Charset11)) { state = 565; ++it; continue; }
                return -1;
            case 565:
                if (MatchCharset(*it, Charset9)) { state = 566; ++it; continue; }
                return -1;
            case 566:
                if (MatchCharset(*it, Charset18)) { state = 567; ++it; continue; }
                return -1;
            case 567:
                return 125;
            case 568:
                if (MatchCharset(*it, Charset9)) { state = 569; ++it; continue; }
                return -1;
            case 569:
                if (MatchCharset(*it, Charset17)) { state = 570; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 573; ++it; continue; }
                return -1;
            case 570:
                if (MatchCharset(*it, Charset20)) { state = 571; ++it; continue; }
                return -1;
            case 571:
                if (MatchCharset(*it, Charset23)) { state = 572; ++it; continue; }
                return -1;
            case 572:
                return 126;
            case 573:
                if (MatchCharset(*it, Charset13)) { state = 574; ++it; continue; }
                return -1;
            case 574:
                return 127;
            case 575:
                if (MatchCharset(*it, Charset25)) { state = 576; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 584; ++it; continue; }
                return -1;
            case 576:
                if (MatchCharset(*it, Charset13)) { state = 577; ++it; continue; }
                return -1;
            case 577:
                if (MatchCharset(*it, Charset22)) { state = 578; ++it; continue; }
                return -1;
            case 578:
                if (MatchCharset(*it, Charset27)) { state = 579; ++it; continue; }
                return -1;
            case 579:
                if (MatchCharset(*it, Charset11)) { state = 580; ++it; continue; }
                return -1;
            case 580:
                if (MatchCharset(*it, Charset24)) { state = 581; ++it; continue; }
                return -1;
            case 581:
                if (MatchCharset(*it, Charset22)) { state = 582; ++it; continue; }
                return -1;
            case 582:
                if (MatchCharset(*it, Charset13)) { state = 583; ++it; continue; }
                return -1;
            case 583:
                return 135;
            case 584:
                if (MatchCharset(*it, Charset23)) { state = 585; ++it; continue; }
                return -1;
            case 585:
                if (MatchCharset(*it, Charset26)) { state = 586; ++it; continue; }
                return -1;
            case 586:
                if (MatchCharset(*it, Charset20)) { state = 587; ++it; continue; }
                return -1;
            case 587:
                if (MatchCharset(*it, Charset33)) { state = 588; ++it; continue; }
                if (MatchCharset(*it, Charset34)) { state = 589; ++it; continue; }
                if (MatchCharset(*it, Charset35)) { state = 590; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 591; ++it; continue; }
                return -1;
            case 588:
                return 132;
            case 589:
                return 133;
            case 590:
                return 134;
            case 591:
                if (MatchCharset(*it, Charset19)) { state = 592; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 598; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 604; ++it; continue; }
                return -1;
            case 592:
                if (MatchCharset(*it, Charset13)) { state = 593; ++it; continue; }
                return -1;
            case 593:
                if (MatchCharset(*it, Charset12)) { state = 594; ++it; continue; }
                return -1;
            case 594:
                if (MatchCharset(*it, Charset17)) { state = 595; ++it; continue; }
                return -1;
            case 595:
                if (MatchCharset(*it, Charset24)) { state = 596; ++it; continue; }
                return -1;
            case 596:
                if (MatchCharset(*it, Charset19)) { state = 597; ++it; continue; }
                return -1;
            case 597:
                return 129;
            case 598:
                if (MatchCharset(*it, Charset13)) { state = 599; ++it; continue; }
                return -1;
            case 599:
                if (MatchCharset(*it, Charset31)) { state = 600; ++it; continue; }
                return -1;
            case 600:
                if (MatchCharset(*it, Charset13)) { state = 601; ++it; continue; }
                return -1;
            case 601:
                if (MatchCharset(*it, Charset22)) { state = 602; ++it; continue; }
                return -1;
            case 602:
                if (MatchCharset(*it, Charset13)) { state = 603; ++it; continue; }
                return -1;
            case 603:
                return 130;
            case 604:
                if (MatchCharset(*it, Charset13)) { state = 605; ++it; continue; }
                return -1;
            case 605:
                if (MatchCharset(*it, Charset9)) { state = 606; ++it; continue; }
                return -1;
            case 606:
                if (MatchCharset(*it, Charset30)) { state = 607; ++it; continue; }
                return -1;
            case 607:
                return 131;
            case 608:
                if (MatchCharset(*it, Charset7)) { state = 609; ++it; continue; }
                return -1;
            case 609:
                if (MatchCharset(*it, Charset11)) { state = 610; ++it; continue; }
                return -1;
            case 610:
                if (MatchCharset(*it, Charset16)) { state = 611; ++it; continue; }
                return -1;
            case 611:
                if (MatchCharset(*it, Charset17)) { state = 612; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 620; ++it; continue; }
                return -1;
            case 612:
                if (MatchCharset(*it, Charset11)) { state = 613; ++it; continue; }
                return -1;
            case 613:
                if (MatchCharset(*it, Charset27)) { state = 614; ++it; continue; }
                return -1;
            case 614:
                if (MatchCharset(*it, Charset23)) { state = 615; ++it; continue; }
                return -1;
            case 615:
                if (MatchCharset(*it, Charset16)) { state = 616; ++it; continue; }
                return -1;
            case 616:
                if (MatchCharset(*it, Charset26)) { state = 617; ++it; continue; }
                return -1;
            case 617:
                if (MatchCharset(*it, Charset11)) { state = 618; ++it; continue; }
                return -1;
            case 618:
                if (MatchCharset(*it, Charset30)) { state = 619; ++it; continue; }
                return -1;
            case 619:
                return 136;
            case 620:
                if (MatchCharset(*it, Charset5)) { state = 621; ++it; continue; }
                return -1;
            case 621:
                if (MatchCharset(*it, Charset17)) { state = 622; ++it; continue; }
                return -1;
            case 622:
                if (MatchCharset(*it, Charset11)) { state = 623; ++it; continue; }
                return -1;
            case 623:
                return 137;
            case 624:
                if (MatchCharset(*it, Charset17)) { state = 625; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 628; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 637; ++it; continue; }
                return -1;
            case 625:
                if (MatchCharset(*it, Charset20)) { state = 626; ++it; continue; }
                return -1;
            case 626:
                if (MatchCharset(*it, Charset15)) { state = 627; ++it; continue; }
                return -1;
            case 627:
                return 142;
            case 628:
                if (MatchCharset(*it, Charset9)) { state = 629; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 634; ++it; continue; }
                return -1;
            case 629:
                if (MatchCharset(*it, Charset15)) { state = 630; ++it; continue; }
                return -1;
            case 630:
                if (MatchCharset(*it, Charset13)) { state = 631; ++it; continue; }
                return -1;
            case 631:
                if (MatchCharset(*it, Charset20)) { state = 632; ++it; continue; }
                return -1;
            case 632:
                if (MatchCharset(*it, Charset5)) { state = 633; ++it; continue; }
                return -1;
            case 633:
                return 140;
            case 634:
                if (MatchCharset(*it, Charset17)) { state = 635; ++it; continue; }
                return -1;
            case 635:
                if (MatchCharset(*it, Charset11)) { state = 636; ++it; continue; }
                return -1;
            case 636:
                return 141;
            case 637:
                if (MatchCharset(*it, Charset11)) { state = 638; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 646; ++it; continue; }
                return -1;
            case 638:
                if (MatchCharset(*it, Charset30)) { state = 639; ++it; continue; }
                return -1;
            case 639:
                if (MatchCharset(*it, Charset27)) { state = 640; ++it; continue; }
                return -1;
            case 640:
                if (MatchCharset(*it, Charset10)) { state = 641; ++it; continue; }
                return -1;
            case 641:
                if (MatchCharset(*it, Charset18)) { state = 642; ++it; continue; }
                return -1;
            case 642:
                if (MatchCharset(*it, Charset9)) { state = 643; ++it; continue; }
                return -1;
            case 643:
                if (MatchCharset(*it, Charset23)) { state = 644; ++it; continue; }
                return -1;
            case 644:
                if (MatchCharset(*it, Charset5)) { state = 645; ++it; continue; }
                return -1;
            case 645:
                return 143;
            case 646:
                if (MatchCharset(*it, Charset19)) { state = 647; ++it; continue; }
                return -1;
            case 647:
                return 144;
            case 648:
                if (MatchCharset(*it, Charset11)) { state = 649; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 654; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 662; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 663; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 669; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 673; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 690; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 702; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 731; ++it; continue; }
                return -1;
            case 649:
                if (MatchCharset(*it, Charset22)) { state = 650; ++it; continue; }
                return -1;
            case 650:
                if (MatchCharset(*it, Charset26)) { state = 651; ++it; continue; }
                return -1;
            case 651:
                if (MatchCharset(*it, Charset18)) { state = 652; ++it; continue; }
                return -1;
            case 652:
                if (MatchCharset(*it, Charset18)) { state = 653; ++it; continue; }
                return -1;
            case 653:
                return 145;
            case 654:
                if (MatchCharset(*it, Charset25)) { state = 655; ++it; continue; }
                return -1;
            case 655:
                if (MatchCharset(*it, Charset13)) { state = 656; ++it; continue; }
                return -1;
            case 656:
                if (MatchCharset(*it, Charset22)) { state = 657; ++it; continue; }
                return -1;
            case 657:
                if (MatchCharset(*it, Charset21)) { state = 658; ++it; continue; }
                return -1;
            case 658:
                if (MatchCharset(*it, Charset17)) { state = 659; ++it; continue; }
                return -1;
            case 659:
                if (MatchCharset(*it, Charset21)) { state = 660; ++it; continue; }
                return -1;
            case 660:
                if (MatchCharset(*it, Charset13)) { state = 661; ++it; continue; }
                return -1;
            case 661:
                return 146;
            case 662:
                if (MatchCharset(*it, Charset8)) { state = 662; ++it; continue; }
                return 151;
            case 663:
                if (MatchCharset(*it, Charset11)) { state = 664; ++it; continue; }
                return -1;
            case 664:
                if (MatchCharset(*it, Charset22)) { state = 665; ++it; continue; }
                return -1;
            case 665:
                if (MatchCharset(*it, Charset26)) { state = 666; ++it; continue; }
                return -1;
            case 666:
                if (MatchCharset(*it, Charset18)) { state = 667; ++it; continue; }
                return -1;
            case 667:
                if (MatchCharset(*it, Charset18)) { state = 668; ++it; continue; }
                return -1;
            case 668:
                return 155;
            case 669:
                if (MatchCharset(*it, Charset26)) { state = 670; ++it; continue; }
                return -1;
            case 670:
                if (MatchCharset(*it, Charset22)) { state = 671; ++it; continue; }
                return -1;
            case 671:
                if (MatchCharset(*it, Charset12)) { state = 672; ++it; continue; }
                return -1;
            case 672:
                return 165;
            case 673:
                if (MatchCharset(*it, Charset17)) { state = 674; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 678; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 686; ++it; continue; }
                return -1;
            case 674:
                if (MatchCharset(*it, Charset13)) { state = 675; ++it; continue; }
                return -1;
            case 675:
                if (MatchCharset(*it, Charset18)) { state = 676; ++it; continue; }
                return -1;
            case 676:
                if (MatchCharset(*it, Charset12)) { state = 677; ++it; continue; }
                return -1;
            case 677:
                return 147;
            case 678:
                if (MatchCharset(*it, Charset9)) { state = 679; ++it; continue; }
                return -1;
            case 679:
                if (MatchCharset(*it, Charset21)) { state = 680; ++it; continue; }
                return -1;
            case 680:
                if (MatchCharset(*it, Charset19)) { state = 681; ++it; continue; }
                return -1;
            case 681:
                if (MatchCharset(*it, Charset13)) { state = 682; ++it; continue; }
                return -1;
            case 682:
                if (MatchCharset(*it, Charset5)) { state = 683; ++it; continue; }
                return -1;
            case 683:
                if (MatchCharset(*it, Charset9)) { state = 684; ++it; continue; }
                return -1;
            case 684:
                if (MatchCharset(*it, Charset18)) { state = 685; ++it; continue; }
                return -1;
            case 685:
                return 150;
            case 686:
                if (MatchCharset(*it, Charset22)) { state = 687; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 689; ++it; continue; }
                return -1;
            case 687:
                if (MatchCharset(*it, Charset5)) { state = 688; ++it; continue; }
                return -1;
            case 688:
                return 148;
            case 689:
                return 149;
            case 690:
                if (MatchCharset(*it, Charset9)) { state = 691; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 695; ++it; continue; }
                return -1;
            case 691:
                if (MatchCharset(*it, Charset22)) { state = 692; ++it; continue; }
                return -1;
            case 692:
                if (MatchCharset(*it, Charset30)) { state = 693; ++it; continue; }
                return -1;
            case 693:
                if (MatchCharset(*it, Charset23)) { state = 694; ++it; continue; }
                return -1;
            case 694:
                return 152;
            case 695:
                if (MatchCharset(*it, Charset9)) { state = 696; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 698; ++it; continue; }
                return -1;
            case 696:
                if (MatchCharset(*it, Charset22)) { state = 697; ++it; continue; }
                return -1;
            case 697:
                return 153;
            case 698:
                if (MatchCharset(*it, Charset17)) { state = 699; ++it; continue; }
                return -1;
            case 699:
                if (MatchCharset(*it, Charset9)) { state = 700; ++it; continue; }
                return -1;
            case 700:
                if (MatchCharset(*it, Charset18)) { state = 701; ++it; continue; }
                return -1;
            case 701:
                return 154;
            case 702:
                if (MatchCharset(*it, Charset13)) { state = 703; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 706; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 711; ++it; continue; }
                return -1;
            case 703:
                if (MatchCharset(*it, Charset9)) { state = 704; ++it; continue; }
                return -1;
            case 704:
                if (MatchCharset(*it, Charset18)) { state = 705; ++it; continue; }
                return -1;
            case 705:
                return 158;
            case 706:
                if (MatchCharset(*it, Charset14)) { state = 707; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 709; ++it; continue; }
                return -1;
            case 707:
                if (MatchCharset(*it, Charset14)) { state = 708; ++it; continue; }
                return -1;
            case 708:
                return 156;
            case 709:
                if (MatchCharset(*it, Charset12)) { state = 710; ++it; continue; }
                return -1;
            case 710:
                return 157;
            case 711:
                if (MatchCharset(*it, Charset20)) { state = 712; ++it; continue; }
                return -1;
            case 712:
                if (MatchCharset(*it, Charset13)) { state = 713; ++it; continue; }
                return -1;
            case 713:
                if (MatchCharset(*it, Charset27)) { state = 714; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 719; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 727; ++it; continue; }
                return 159;
            case 714:
                if (MatchCharset(*it, Charset23)) { state = 715; ++it; continue; }
                return -1;
            case 715:
                if (MatchCharset(*it, Charset30)) { state = 716; ++it; continue; }
                return -1;
            case 716:
                if (MatchCharset(*it, Charset17)) { state = 717; ++it; continue; }
                return -1;
            case 717:
                if (MatchCharset(*it, Charset20)) { state = 718; ++it; continue; }
                return -1;
            case 718:
                return 160;
            case 719:
                if (MatchCharset(*it, Charset26)) { state = 720; ++it; continue; }
                return -1;
            case 720:
                if (MatchCharset(*it, Charset22)) { state = 721; ++it; continue; }
                return -1;
            case 721:
                if (MatchCharset(*it, Charset22)) { state = 722; ++it; continue; }
                return -1;
            case 722:
                if (MatchCharset(*it, Charset17)) { state = 723; ++it; continue; }
                return -1;
            case 723:
                if (MatchCharset(*it, Charset12)) { state = 724; ++it; continue; }
                return -1;
            case 724:
                if (MatchCharset(*it, Charset26)) { state = 725; ++it; continue; }
                return -1;
            case 725:
                if (MatchCharset(*it, Charset22)) { state = 726; ++it; continue; }
                return -1;
            case 726:
                return 161;
            case 727:
                if (MatchCharset(*it, Charset26)) { state = 728; ++it; continue; }
                return -1;
            case 728:
                if (MatchCharset(*it, Charset26)) { state = 729; ++it; continue; }
                return -1;
            case 729:
                if (MatchCharset(*it, Charset19)) { state = 730; ++it; continue; }
                return -1;
            case 730:
                return 162;
            case 731:
                if (MatchCharset(*it, Charset17)) { state = 732; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 738; ++it; continue; }
                return -1;
            case 732:
                if (MatchCharset(*it, Charset11)) { state = 733; ++it; continue; }
                return -1;
            case 733:
                if (MatchCharset(*it, Charset17)) { state = 734; ++it; continue; }
                return -1;
            case 734:
                if (MatchCharset(*it, Charset12)) { state = 735; ++it; continue; }
                return -1;
            case 735:
                if (MatchCharset(*it, Charset9)) { state = 736; ++it; continue; }
                return -1;
            case 736:
                if (MatchCharset(*it, Charset18)) { state = 737; ++it; continue; }
                return -1;
            case 737:
                return 163;
            case 738:
                if (MatchCharset(*it, Charset19)) { state = 739; ++it; continue; }
                return -1;
            case 739:
                if (MatchCharset(*it, Charset26)) { state = 740; ++it; continue; }
                return -1;
            case 740:
                if (MatchCharset(*it, Charset20)) { state = 741; ++it; continue; }
                return -1;
            case 741:
                return 164;
            case 742:
                if (MatchCharset(*it, Charset20)) { state = 743; ++it; continue; }
                return -1;
            case 743:
                if (MatchCharset(*it, Charset11)) { state = 744; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 747; ++it; continue; }
                return -1;
            case 744:
                if (MatchCharset(*it, Charset26)) { state = 745; ++it; continue; }
                return -1;
            case 745:
                if (MatchCharset(*it, Charset20)) { state = 746; ++it; continue; }
                return -1;
            case 746:
                return 168;
            case 747:
                if (MatchCharset(*it, Charset13)) { state = 748; ++it; continue; }
                return -1;
            case 748:
                if (MatchCharset(*it, Charset22)) { state = 749; ++it; continue; }
                return -1;
            case 749:
                if (MatchCharset(*it, Charset25)) { state = 750; ++it; continue; }
                return -1;
            case 750:
                if (MatchCharset(*it, Charset9)) { state = 751; ++it; continue; }
                return -1;
            case 751:
                if (MatchCharset(*it, Charset5)) { state = 752; ++it; continue; }
                return -1;
            case 752:
                if (MatchCharset(*it, Charset13)) { state = 753; ++it; continue; }
                return -1;
            case 753:
                if (MatchCharset(*it, Charset22)) { state = 754; ++it; continue; }
                return -1;
            case 754:
                return 169;
            case 755:
                if (MatchCharset(*it, Charset17)) { state = 756; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 759; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 765; ++it; continue; }
                return -1;
            case 756:
                if (MatchCharset(*it, Charset19)) { state = 757; ++it; continue; }
                return -1;
            case 757:
                if (MatchCharset(*it, Charset21)) { state = 758; ++it; continue; }
                return -1;
            case 758:
                return 177;
            case 759:
                if (MatchCharset(*it, Charset20)) { state = 760; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 762; ++it; continue; }
                return -1;
            case 760:
                if (MatchCharset(*it, Charset12)) { state = 761; ++it; continue; }
                return -1;
            case 761:
                return 170;
            case 762:
                if (MatchCharset(*it, Charset13)) { state = 763; ++it; continue; }
                return -1;
            case 763:
                if (MatchCharset(*it, Charset22)) { state = 764; ++it; continue; }
                return -1;
            case 764:
                return 171;
            case 765:
                if (MatchCharset(*it, Charset9)) { state = 766; ++it; continue; }
                return -1;
            case 766:
                if (MatchCharset(*it, Charset30)) { state = 767; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 768; ++it; continue; }
                return -1;
            case 767:
                return 172;
            case 768:
                if (MatchCharset(*it, Charset26)) { state = 769; ++it; continue; }
                return -1;
            case 769:
                if (MatchCharset(*it, Charset20)) { state = 770; ++it; continue; }
                return -1;
            case 770:
                if (MatchCharset(*it, Charset33)) { state = 771; ++it; continue; }
                if (MatchCharset(*it, Charset34)) { state = 775; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 776; ++it; continue; }
                return 173;
            case 771:
                if (MatchCharset(*it, Charset26)) { state = 772; ++it; continue; }
                return -1;
            case 772:
                if (MatchCharset(*it, Charset22)) { state = 773; ++it; continue; }
                return -1;
            case 773:
                if (MatchCharset(*it, Charset34)) { state = 774; ++it; continue; }
                return -1;
            case 774:
                return 174;
            case 775:
                return 175;
            case 776:
                return 176;
            default:
                return -1;
            }
        }

        // TODO: EOF?
        return -1;
    }
}
