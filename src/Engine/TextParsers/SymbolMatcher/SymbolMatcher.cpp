//
// THIS FILE IS GENERATED
//
#include "SymbolMatcher.hpp"

namespace SymbolMatcher::DFA
{
    static constexpr inline char Charset0[6] = { 9,10,11,12,13,32 };
    static constexpr inline char Charset1[1] = { 44 };
    static constexpr inline char Charset2[1] = { 43 };
    static constexpr inline char Charset3[1] = { 34 };
    static constexpr inline char Charset4[2] = { 88,120 };
    static constexpr inline char Charset5[2] = { 89,121 };
    static constexpr inline char Charset6[10] = { 48,49,50,51,52,53,54,55,56,57 };
    static constexpr inline char Charset7[2] = { 65,97 };
    static constexpr inline char Charset8[2] = { 66,98 };
    static constexpr inline char Charset9[2] = { 67,99 };
    static constexpr inline char Charset10[2] = { 68,100 };
    static constexpr inline char Charset11[2] = { 69,101 };
    static constexpr inline char Charset12[2] = { 70,102 };
    static constexpr inline char Charset13[2] = { 71,103 };
    static constexpr inline char Charset14[2] = { 72,104 };
    static constexpr inline char Charset15[2] = { 73,105 };
    static constexpr inline char Charset16[2] = { 76,108 };
    static constexpr inline char Charset17[2] = { 77,109 };
    static constexpr inline char Charset18[2] = { 78,110 };
    static constexpr inline char Charset19[2] = { 80,112 };
    static constexpr inline char Charset20[2] = { 81,113 };
    static constexpr inline char Charset21[2] = { 82,114 };
    static constexpr inline char Charset22[2] = { 83,115 };
    static constexpr inline char Charset23[2] = { 84,116 };
    static constexpr inline char Charset24[2] = { 85,117 };
    static constexpr inline char Charset25[2] = { 87,119 };
    static constexpr inline char Charset26[1] = { 45 };
    static constexpr inline char Charset27[1] = { 37 };
    static constexpr inline char Charset28[2] = { 79,111 };
    static constexpr inline char Charset29[1] = { 32 };
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
                if (MatchCharset(*it, Charset4)) { state = 5; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 8; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 9; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 21; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 124; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 186; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 262; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 359; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 399; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 441; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 486; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 552; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 592; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 635; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 704; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 718; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 843; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 858; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 882; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1007; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 1038; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1051; ++it; continue; }
                return -1;
            case 1:
                if (MatchCharset(*it, Charset0)) { state = 1; ++it; continue; }
                return 2;
            case 2:
                return 53;
            case 3:
                return 168;
            case 4:
                return 183;
            case 5:
                if (MatchCharset(*it, Charset0)) { state = 6; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 7; ++it; continue; }
                return -1;
            case 6:
                if (MatchCharset(*it, Charset0)) { state = 6; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 7; ++it; continue; }
                return -1;
            case 7:
                if (MatchCharset(*it, Charset6)) { state = 7; ++it; continue; }
                return 236;
            case 8:
                return 237;
            case 9:
                if (MatchCharset(*it, Charset26)) { state = 10; ++it; continue; }
                if (MatchCharset(*it, Charset1)) { state = 12; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 14; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 9; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 15; ++it; continue; }
                return 131;
            case 10:
                if (MatchCharset(*it, Charset6)) { state = 11; ++it; continue; }
                return -1;
            case 11:
                if (MatchCharset(*it, Charset6)) { state = 11; ++it; continue; }
                return 83;
            case 12:
                if (MatchCharset(*it, Charset6)) { state = 13; ++it; continue; }
                return -1;
            case 13:
                if (MatchCharset(*it, Charset6)) { state = 13; ++it; continue; }
                return 97;
            case 14:
                return 222;
            case 15:
                if (MatchCharset(*it, Charset6)) { state = 16; ++it; continue; }
                return -1;
            case 16:
                if (MatchCharset(*it, Charset16)) { state = 17; ++it; continue; }
                if (MatchCharset(*it, Charset2)) { state = 19; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 16; ++it; continue; }
                return 62;
            case 17:
                if (MatchCharset(*it, Charset6)) { state = 18; ++it; continue; }
                return -1;
            case 18:
                if (MatchCharset(*it, Charset6)) { state = 18; ++it; continue; }
                return 64;
            case 19:
                if (MatchCharset(*it, Charset6)) { state = 20; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 17; ++it; continue; }
                return -1;
            case 20:
                if (MatchCharset(*it, Charset6)) { state = 20; ++it; continue; }
                return 63;
            case 21:
                if (MatchCharset(*it, Charset12)) { state = 22; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 27; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 29; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 34; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 39; ++it; continue; }
                if (MatchCharset(*it, Charset4)) { state = 48; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 50; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 64; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 71; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 82; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 99; ++it; continue; }
                return 3;
            case 22:
                if (MatchCharset(*it, Charset21)) { state = 23; ++it; continue; }
                return -1;
            case 23:
                if (MatchCharset(*it, Charset7)) { state = 24; ++it; continue; }
                return -1;
            case 24:
                if (MatchCharset(*it, Charset15)) { state = 25; ++it; continue; }
                return -1;
            case 25:
                if (MatchCharset(*it, Charset10)) { state = 26; ++it; continue; }
                return -1;
            case 26:
                return 6;
            case 27:
                if (MatchCharset(*it, Charset21)) { state = 28; ++it; continue; }
                return -1;
            case 28:
                return 9;
            case 29:
                if (MatchCharset(*it, Charset24)) { state = 30; ++it; continue; }
                return -1;
            case 30:
                if (MatchCharset(*it, Charset16)) { state = 31; ++it; continue; }
                return -1;
            case 31:
                if (MatchCharset(*it, Charset11)) { state = 32; ++it; continue; }
                return -1;
            case 32:
                if (MatchCharset(*it, Charset23)) { state = 33; ++it; continue; }
                return -1;
            case 33:
                return 12;
            case 34:
                if (MatchCharset(*it, Charset16)) { state = 35; ++it; continue; }
                return -1;
            case 35:
                if (MatchCharset(*it, Charset11)) { state = 36; ++it; continue; }
                return -1;
            case 36:
                if (MatchCharset(*it, Charset11)) { state = 37; ++it; continue; }
                return -1;
            case 37:
                if (MatchCharset(*it, Charset19)) { state = 38; ++it; continue; }
                return -1;
            case 38:
                return 21;
            case 39:
                if (MatchCharset(*it, Charset10)) { state = 40; ++it; continue; }
                return -1;
            case 40:
                if (MatchCharset(*it, Charset15)) { state = 41; ++it; continue; }
                return -1;
            case 41:
                if (MatchCharset(*it, Charset23)) { state = 42; ++it; continue; }
                return -1;
            case 42:
                if (MatchCharset(*it, Charset28)) { state = 43; ++it; continue; }
                return -1;
            case 43:
                if (MatchCharset(*it, Charset21)) { state = 44; ++it; continue; }
                return -1;
            case 44:
                if (MatchCharset(*it, Charset15)) { state = 45; ++it; continue; }
                return -1;
            case 45:
                if (MatchCharset(*it, Charset24)) { state = 46; ++it; continue; }
                return -1;
            case 46:
                if (MatchCharset(*it, Charset17)) { state = 47; ++it; continue; }
                return -1;
            case 47:
                return 22;
            case 48:
                if (MatchCharset(*it, Charset11)) { state = 49; ++it; continue; }
                return -1;
            case 49:
                return 23;
            case 50:
                if (MatchCharset(*it, Charset15)) { state = 51; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 59; ++it; continue; }
                return -1;
            case 51:
                if (MatchCharset(*it, Charset10)) { state = 52; ++it; continue; }
                return -1;
            case 52:
                if (MatchCharset(*it, Charset29)) { state = 53; ++it; continue; }
                return -1;
            case 53:
                if (MatchCharset(*it, Charset8)) { state = 54; ++it; continue; }
                return -1;
            case 54:
                if (MatchCharset(*it, Charset24)) { state = 55; ++it; continue; }
                return -1;
            case 55:
                if (MatchCharset(*it, Charset21)) { state = 56; ++it; continue; }
                return -1;
            case 56:
                if (MatchCharset(*it, Charset22)) { state = 57; ++it; continue; }
                return -1;
            case 57:
                if (MatchCharset(*it, Charset23)) { state = 58; ++it; continue; }
                return -1;
            case 58:
                return 4;
            case 59:
                if (MatchCharset(*it, Charset16)) { state = 60; ++it; continue; }
                return -1;
            case 60:
                if (MatchCharset(*it, Charset5)) { state = 61; ++it; continue; }
                return -1;
            case 61:
                if (MatchCharset(*it, Charset23)) { state = 62; ++it; continue; }
                return -1;
            case 62:
                if (MatchCharset(*it, Charset11)) { state = 63; ++it; continue; }
                return -1;
            case 63:
                return 5;
            case 64:
                if (MatchCharset(*it, Charset11)) { state = 65; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 66; ++it; continue; }
                return -1;
            case 65:
                return 7;
            case 66:
                if (MatchCharset(*it, Charset21)) { state = 67; ++it; continue; }
                return -1;
            case 67:
                if (MatchCharset(*it, Charset11)) { state = 68; ++it; continue; }
                return -1;
            case 68:
                if (MatchCharset(*it, Charset22)) { state = 69; ++it; continue; }
                return -1;
            case 69:
                if (MatchCharset(*it, Charset22)) { state = 70; ++it; continue; }
                return -1;
            case 70:
                return 8;
            case 71:
                if (MatchCharset(*it, Charset9)) { state = 72; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 79; ++it; continue; }
                return -1;
            case 72:
                if (MatchCharset(*it, Charset14)) { state = 73; ++it; continue; }
                return -1;
            case 73:
                if (MatchCharset(*it, Charset11)) { state = 74; ++it; continue; }
                return -1;
            case 74:
                if (MatchCharset(*it, Charset17)) { state = 75; ++it; continue; }
                return -1;
            case 75:
                if (MatchCharset(*it, Charset15)) { state = 76; ++it; continue; }
                return -1;
            case 76:
                if (MatchCharset(*it, Charset22)) { state = 77; ++it; continue; }
                return -1;
            case 77:
                if (MatchCharset(*it, Charset23)) { state = 78; ++it; continue; }
                return -1;
            case 78:
                return 10;
            case 79:
                if (MatchCharset(*it, Charset11)) { state = 80; ++it; continue; }
                return -1;
            case 80:
                if (MatchCharset(*it, Charset5)) { state = 81; ++it; continue; }
                return -1;
            case 81:
                return 11;
            case 82:
                if (MatchCharset(*it, Charset28)) { state = 83; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 91; ++it; continue; }
                return -1;
            case 83:
                if (MatchCharset(*it, Charset23)) { state = 84; ++it; continue; }
                return -1;
            case 84:
                if (MatchCharset(*it, Charset14)) { state = 85; ++it; continue; }
                return -1;
            case 85:
                if (MatchCharset(*it, Charset11)) { state = 86; ++it; continue; }
                return -1;
            case 86:
                if (MatchCharset(*it, Charset9)) { state = 87; ++it; continue; }
                return -1;
            case 87:
                if (MatchCharset(*it, Charset7)) { state = 88; ++it; continue; }
                return -1;
            case 88:
                if (MatchCharset(*it, Charset21)) { state = 89; ++it; continue; }
                return -1;
            case 89:
                if (MatchCharset(*it, Charset5)) { state = 90; ++it; continue; }
                return -1;
            case 90:
                return 13;
            case 91:
                if (MatchCharset(*it, Charset21)) { state = 92; ++it; continue; }
                return -1;
            case 92:
                if (MatchCharset(*it, Charset11)) { state = 93; ++it; continue; }
                return -1;
            case 93:
                if (MatchCharset(*it, Charset18)) { state = 94; ++it; continue; }
                return -1;
            case 94:
                if (MatchCharset(*it, Charset23)) { state = 95; ++it; continue; }
                return -1;
            case 95:
                if (MatchCharset(*it, Charset15)) { state = 96; ++it; continue; }
                return -1;
            case 96:
                if (MatchCharset(*it, Charset9)) { state = 97; ++it; continue; }
                return -1;
            case 97:
                if (MatchCharset(*it, Charset11)) { state = 98; ++it; continue; }
                return -1;
            case 98:
                return 14;
            case 99:
                if (MatchCharset(*it, Charset11)) { state = 100; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 103; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 106; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 112; ++it; continue; }
                return -1;
            case 100:
                if (MatchCharset(*it, Charset18)) { state = 101; ++it; continue; }
                return -1;
            case 101:
                if (MatchCharset(*it, Charset7)) { state = 102; ++it; continue; }
                return -1;
            case 102:
                return 15;
            case 103:
                if (MatchCharset(*it, Charset28)) { state = 104; ++it; continue; }
                return -1;
            case 104:
                if (MatchCharset(*it, Charset25)) { state = 105; ++it; continue; }
                return -1;
            case 105:
                return 19;
            case 106:
                if (MatchCharset(*it, Charset15)) { state = 107; ++it; continue; }
                return -1;
            case 107:
                if (MatchCharset(*it, Charset12)) { state = 108; ++it; continue; }
                return -1;
            case 108:
                if (MatchCharset(*it, Charset7)) { state = 109; ++it; continue; }
                return -1;
            case 109:
                if (MatchCharset(*it, Charset9)) { state = 110; ++it; continue; }
                return -1;
            case 110:
                if (MatchCharset(*it, Charset23)) { state = 111; ++it; continue; }
                return -1;
            case 111:
                return 20;
            case 112:
                if (MatchCharset(*it, Charset22)) { state = 113; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 120; ++it; continue; }
                return -1;
            case 113:
                if (MatchCharset(*it, Charset17)) { state = 114; ++it; continue; }
                return -1;
            case 114:
                if (MatchCharset(*it, Charset7)) { state = 115; ++it; continue; }
                return -1;
            case 115:
                if (MatchCharset(*it, Charset22)) { state = 116; ++it; continue; }
                return -1;
            case 116:
                if (MatchCharset(*it, Charset23)) { state = 117; ++it; continue; }
                return -1;
            case 117:
                if (MatchCharset(*it, Charset11)) { state = 118; ++it; continue; }
                return -1;
            case 118:
                if (MatchCharset(*it, Charset21)) { state = 119; ++it; continue; }
                return -1;
            case 119:
                return 18;
            case 120:
                if (MatchCharset(*it, Charset21)) { state = 121; ++it; continue; }
                return -1;
            case 121:
                if (MatchCharset(*it, Charset11)) { state = 122; ++it; continue; }
                return 16;
            case 122:
                if (MatchCharset(*it, Charset21)) { state = 123; ++it; continue; }
                return -1;
            case 123:
                return 17;
            case 124:
                if (MatchCharset(*it, Charset11)) { state = 125; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 128; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 134; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 147; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 159; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 169; ++it; continue; }
                return 24;
            case 125:
                if (MatchCharset(*it, Charset16)) { state = 126; ++it; continue; }
                return -1;
            case 126:
                if (MatchCharset(*it, Charset23)) { state = 127; ++it; continue; }
                return -1;
            case 127:
                return 28;
            case 128:
                if (MatchCharset(*it, Charset21)) { state = 129; ++it; continue; }
                return -1;
            case 129:
                if (MatchCharset(*it, Charset13)) { state = 130; ++it; continue; }
                return -1;
            case 130:
                if (MatchCharset(*it, Charset16)) { state = 131; ++it; continue; }
                return -1;
            case 131:
                if (MatchCharset(*it, Charset7)) { state = 132; ++it; continue; }
                return -1;
            case 132:
                if (MatchCharset(*it, Charset21)) { state = 133; ++it; continue; }
                return -1;
            case 133:
                return 39;
            case 134:
                if (MatchCharset(*it, Charset18)) { state = 135; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 139; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 141; ++it; continue; }
                return -1;
            case 135:
                if (MatchCharset(*it, Charset30)) { state = 136; ++it; continue; }
                return -1;
            case 136:
                if (MatchCharset(*it, Charset11)) { state = 137; ++it; continue; }
                return -1;
            case 137:
                if (MatchCharset(*it, Charset21)) { state = 138; ++it; continue; }
                return -1;
            case 138:
                return 25;
            case 139:
                if (MatchCharset(*it, Charset10)) { state = 140; ++it; continue; }
                return -1;
            case 140:
                return 26;
            case 141:
                if (MatchCharset(*it, Charset14)) { state = 142; ++it; continue; }
                return -1;
            case 142:
                if (MatchCharset(*it, Charset21)) { state = 143; ++it; continue; }
                return -1;
            case 143:
                if (MatchCharset(*it, Charset28)) { state = 144; ++it; continue; }
                return -1;
            case 144:
                if (MatchCharset(*it, Charset28)) { state = 145; ++it; continue; }
                return -1;
            case 145:
                if (MatchCharset(*it, Charset17)) { state = 146; ++it; continue; }
                return -1;
            case 146:
                return 27;
            case 147:
                if (MatchCharset(*it, Charset11)) { state = 148; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 151; ++it; continue; }
                return -1;
            case 148:
                if (MatchCharset(*it, Charset22)) { state = 149; ++it; continue; }
                return -1;
            case 149:
                if (MatchCharset(*it, Charset22)) { state = 150; ++it; continue; }
                return -1;
            case 150:
                return 31;
            case 151:
                if (MatchCharset(*it, Charset10)) { state = 152; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 155; ++it; continue; }
                return -1;
            case 152:
                if (MatchCharset(*it, Charset11)) { state = 153; ++it; continue; }
                return -1;
            case 153:
                if (MatchCharset(*it, Charset22)) { state = 154; ++it; continue; }
                return -1;
            case 154:
                return 29;
            case 155:
                if (MatchCharset(*it, Charset23)) { state = 156; ++it; continue; }
                return -1;
            case 156:
                if (MatchCharset(*it, Charset11)) { state = 157; ++it; continue; }
                return -1;
            case 157:
                if (MatchCharset(*it, Charset21)) { state = 158; ++it; continue; }
                return -1;
            case 158:
                return 30;
            case 159:
                if (MatchCharset(*it, Charset23)) { state = 160; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 164; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 165; ++it; continue; }
                return -1;
            case 160:
                if (MatchCharset(*it, Charset23)) { state = 161; ++it; continue; }
                return -1;
            case 161:
                if (MatchCharset(*it, Charset16)) { state = 162; ++it; continue; }
                return -1;
            case 162:
                if (MatchCharset(*it, Charset11)) { state = 163; ++it; continue; }
                return -1;
            case 163:
                return 34;
            case 164:
                return 35;
            case 165:
                if (MatchCharset(*it, Charset30)) { state = 166; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 167; ++it; continue; }
                return -1;
            case 166:
                return 32;
            case 167:
                if (MatchCharset(*it, Charset22)) { state = 168; ++it; continue; }
                return -1;
            case 168:
                return 33;
            case 169:
                if (MatchCharset(*it, Charset30)) { state = 170; ++it; continue; }
                return -1;
            case 170:
                if (MatchCharset(*it, Charset7)) { state = 171; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 176; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 180; ++it; continue; }
                return -1;
            case 171:
                if (MatchCharset(*it, Charset21)) { state = 172; ++it; continue; }
                return -1;
            case 172:
                if (MatchCharset(*it, Charset17)) { state = 173; ++it; continue; }
                return -1;
            case 173:
                if (MatchCharset(*it, Charset28)) { state = 174; ++it; continue; }
                return -1;
            case 174:
                if (MatchCharset(*it, Charset21)) { state = 175; ++it; continue; }
                return -1;
            case 175:
                return 36;
            case 176:
                if (MatchCharset(*it, Charset23)) { state = 177; ++it; continue; }
                return -1;
            case 177:
                if (MatchCharset(*it, Charset11)) { state = 178; ++it; continue; }
                return -1;
            case 178:
                if (MatchCharset(*it, Charset17)) { state = 179; ++it; continue; }
                return -1;
            case 179:
                return 37;
            case 180:
                if (MatchCharset(*it, Charset11)) { state = 181; ++it; continue; }
                return -1;
            case 181:
                if (MatchCharset(*it, Charset7)) { state = 182; ++it; continue; }
                return -1;
            case 182:
                if (MatchCharset(*it, Charset19)) { state = 183; ++it; continue; }
                return -1;
            case 183:
                if (MatchCharset(*it, Charset28)) { state = 184; ++it; continue; }
                return -1;
            case 184:
                if (MatchCharset(*it, Charset18)) { state = 185; ++it; continue; }
                return -1;
            case 185:
                return 38;
            case 186:
                if (MatchCharset(*it, Charset15)) { state = 187; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 190; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 194; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 221; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 242; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 248; ++it; continue; }
                return 40;
            case 187:
                if (MatchCharset(*it, Charset23)) { state = 188; ++it; continue; }
                return -1;
            case 188:
                if (MatchCharset(*it, Charset5)) { state = 189; ++it; continue; }
                return -1;
            case 189:
                return 49;
            case 190:
                if (MatchCharset(*it, Charset21)) { state = 191; ++it; continue; }
                return -1;
            case 191:
                if (MatchCharset(*it, Charset22)) { state = 192; ++it; continue; }
                return -1;
            case 192:
                if (MatchCharset(*it, Charset11)) { state = 193; ++it; continue; }
                return -1;
            case 193:
                return 56;
            case 194:
                if (MatchCharset(*it, Charset19)) { state = 195; ++it; continue; }
                if (MatchCharset(*it, Charset31)) { state = 197; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 199; ++it; continue; }
                return -1;
            case 195:
                if (MatchCharset(*it, Charset11)) { state = 196; ++it; continue; }
                return -1;
            case 196:
                return 41;
            case 197:
                if (MatchCharset(*it, Charset11)) { state = 198; ++it; continue; }
                return -1;
            case 198:
                return 44;
            case 199:
                if (MatchCharset(*it, Charset19)) { state = 200; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 212; ++it; continue; }
                return -1;
            case 200:
                if (MatchCharset(*it, Charset11)) { state = 201; ++it; continue; }
                return -1;
            case 201:
                if (MatchCharset(*it, Charset23)) { state = 202; ++it; continue; }
                return -1;
            case 202:
                if (MatchCharset(*it, Charset11)) { state = 203; ++it; continue; }
                return -1;
            case 203:
                if (MatchCharset(*it, Charset10)) { state = 204; ++it; continue; }
                return -1;
            case 204:
                if (MatchCharset(*it, Charset14)) { state = 205; ++it; continue; }
                return -1;
            case 205:
                if (MatchCharset(*it, Charset7)) { state = 206; ++it; continue; }
                return -1;
            case 206:
                if (MatchCharset(*it, Charset16)) { state = 207; ++it; continue; }
                return -1;
            case 207:
                if (MatchCharset(*it, Charset16)) { state = 208; ++it; continue; }
                return -1;
            case 208:
                if (MatchCharset(*it, Charset25)) { state = 209; ++it; continue; }
                return -1;
            case 209:
                if (MatchCharset(*it, Charset7)) { state = 210; ++it; continue; }
                return -1;
            case 210:
                if (MatchCharset(*it, Charset5)) { state = 211; ++it; continue; }
                return -1;
            case 211:
                return 42;
            case 212:
                if (MatchCharset(*it, Charset28)) { state = 213; ++it; continue; }
                return -1;
            case 213:
                if (MatchCharset(*it, Charset13)) { state = 214; ++it; continue; }
                return -1;
            case 214:
                if (MatchCharset(*it, Charset21)) { state = 215; ++it; continue; }
                return -1;
            case 215:
                if (MatchCharset(*it, Charset7)) { state = 216; ++it; continue; }
                return -1;
            case 216:
                if (MatchCharset(*it, Charset19)) { state = 217; ++it; continue; }
                return -1;
            case 217:
                if (MatchCharset(*it, Charset14)) { state = 218; ++it; continue; }
                return -1;
            case 218:
                if (MatchCharset(*it, Charset11)) { state = 219; ++it; continue; }
                return -1;
            case 219:
                if (MatchCharset(*it, Charset21)) { state = 220; ++it; continue; }
                return -1;
            case 220:
                return 43;
            case 221:
                if (MatchCharset(*it, Charset11)) { state = 222; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 224; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 234; ++it; continue; }
                return -1;
            case 222:
                if (MatchCharset(*it, Charset12)) { state = 223; ++it; continue; }
                return -1;
            case 223:
                return 47;
            case 224:
                if (MatchCharset(*it, Charset17)) { state = 225; ++it; continue; }
                return -1;
            case 225:
                if (MatchCharset(*it, Charset18)) { state = 226; ++it; continue; }
                return -1;
            case 226:
                if (MatchCharset(*it, Charset11)) { state = 227; ++it; continue; }
                return -1;
            case 227:
                if (MatchCharset(*it, Charset5)) { state = 228; ++it; continue; }
                return -1;
            case 228:
                if (MatchCharset(*it, Charset22)) { state = 229; ++it; continue; }
                return -1;
            case 229:
                if (MatchCharset(*it, Charset25)) { state = 230; ++it; continue; }
                return -1;
            case 230:
                if (MatchCharset(*it, Charset11)) { state = 231; ++it; continue; }
                return -1;
            case 231:
                if (MatchCharset(*it, Charset11)) { state = 232; ++it; continue; }
                return -1;
            case 232:
                if (MatchCharset(*it, Charset19)) { state = 233; ++it; continue; }
                return -1;
            case 233:
                return 48;
            case 234:
                if (MatchCharset(*it, Charset15)) { state = 235; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 237; ++it; continue; }
                return -1;
            case 235:
                if (MatchCharset(*it, Charset18)) { state = 236; ++it; continue; }
                return -1;
            case 236:
                return 45;
            case 237:
                if (MatchCharset(*it, Charset16)) { state = 238; ++it; continue; }
                return -1;
            case 238:
                if (MatchCharset(*it, Charset7)) { state = 239; ++it; continue; }
                return -1;
            case 239:
                if (MatchCharset(*it, Charset15)) { state = 240; ++it; continue; }
                return -1;
            case 240:
                if (MatchCharset(*it, Charset18)) { state = 241; ++it; continue; }
                return -1;
            case 241:
                return 46;
            case 242:
                if (MatchCharset(*it, Charset28)) { state = 243; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 246; ++it; continue; }
                return -1;
            case 243:
                if (MatchCharset(*it, Charset7)) { state = 244; ++it; continue; }
                return -1;
            case 244:
                if (MatchCharset(*it, Charset30)) { state = 245; ++it; continue; }
                return -1;
            case 245:
                return 50;
            case 246:
                if (MatchCharset(*it, Charset8)) { state = 247; ++it; continue; }
                return -1;
            case 247:
                return 51;
            case 248:
                if (MatchCharset(*it, Charset16)) { state = 249; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 251; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 260; ++it; continue; }
                return -1;
            case 249:
                if (MatchCharset(*it, Charset10)) { state = 250; ++it; continue; }
                return -1;
            case 250:
                return 52;
            case 251:
                if (MatchCharset(*it, Charset9)) { state = 252; ++it; continue; }
                return -1;
            case 252:
                if (MatchCharset(*it, Charset11)) { state = 253; ++it; continue; }
                return -1;
            case 253:
                if (MatchCharset(*it, Charset21)) { state = 254; ++it; continue; }
                return -1;
            case 254:
                if (MatchCharset(*it, Charset23)) { state = 255; ++it; continue; }
                return -1;
            case 255:
                if (MatchCharset(*it, Charset14)) { state = 256; ++it; continue; }
                return -1;
            case 256:
                if (MatchCharset(*it, Charset7)) { state = 257; ++it; continue; }
                return -1;
            case 257:
                if (MatchCharset(*it, Charset16)) { state = 258; ++it; continue; }
                return -1;
            case 258:
                if (MatchCharset(*it, Charset16)) { state = 259; ++it; continue; }
                return -1;
            case 259:
                return 54;
            case 260:
                if (MatchCharset(*it, Charset30)) { state = 261; ++it; continue; }
                return -1;
            case 261:
                return 55;
            case 262:
                if (MatchCharset(*it, Charset11)) { state = 263; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 266; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 270; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 292; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 336; ++it; continue; }
                return 57;
            case 263:
                if (MatchCharset(*it, Charset7)) { state = 264; ++it; continue; }
                return -1;
            case 264:
                if (MatchCharset(*it, Charset10)) { state = 265; ++it; continue; }
                return -1;
            case 265:
                return 61;
            case 266:
                if (MatchCharset(*it, Charset19)) { state = 267; ++it; continue; }
                return -1;
            case 267:
                if (MatchCharset(*it, Charset11)) { state = 268; ++it; continue; }
                return -1;
            case 268:
                if (MatchCharset(*it, Charset21)) { state = 269; ++it; continue; }
                return -1;
            case 269:
                return 78;
            case 270:
                if (MatchCharset(*it, Charset13)) { state = 271; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 275; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 277; ++it; continue; }
                return -1;
            case 271:
                if (MatchCharset(*it, Charset13)) { state = 272; ++it; continue; }
                return -1;
            case 272:
                if (MatchCharset(*it, Charset11)) { state = 273; ++it; continue; }
                return -1;
            case 273:
                if (MatchCharset(*it, Charset21)) { state = 274; ++it; continue; }
                return -1;
            case 274:
                return 58;
            case 275:
                if (MatchCharset(*it, Charset30)) { state = 276; ++it; continue; }
                return -1;
            case 276:
                return 59;
            case 277:
                if (MatchCharset(*it, Charset29)) { state = 278; ++it; continue; }
                return -1;
            case 278:
                if (MatchCharset(*it, Charset28)) { state = 279; ++it; continue; }
                return -1;
            case 279:
                if (MatchCharset(*it, Charset12)) { state = 280; ++it; continue; }
                return -1;
            case 280:
                if (MatchCharset(*it, Charset29)) { state = 281; ++it; continue; }
                return -1;
            case 281:
                if (MatchCharset(*it, Charset19)) { state = 282; ++it; continue; }
                return -1;
            case 282:
                if (MatchCharset(*it, Charset21)) { state = 283; ++it; continue; }
                return -1;
            case 283:
                if (MatchCharset(*it, Charset28)) { state = 284; ++it; continue; }
                return -1;
            case 284:
                if (MatchCharset(*it, Charset23)) { state = 285; ++it; continue; }
                return -1;
            case 285:
                if (MatchCharset(*it, Charset11)) { state = 286; ++it; continue; }
                return -1;
            case 286:
                if (MatchCharset(*it, Charset9)) { state = 287; ++it; continue; }
                return -1;
            case 287:
                if (MatchCharset(*it, Charset23)) { state = 288; ++it; continue; }
                return -1;
            case 288:
                if (MatchCharset(*it, Charset15)) { state = 289; ++it; continue; }
                return -1;
            case 289:
                if (MatchCharset(*it, Charset28)) { state = 290; ++it; continue; }
                return -1;
            case 290:
                if (MatchCharset(*it, Charset18)) { state = 291; ++it; continue; }
                return -1;
            case 291:
                return 60;
            case 292:
                if (MatchCharset(*it, Charset19)) { state = 293; ++it; continue; }
                if (MatchCharset(*it, Charset32)) { state = 299; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 302; ++it; continue; }
                return -1;
            case 293:
                if (MatchCharset(*it, Charset16)) { state = 294; ++it; continue; }
                return -1;
            case 294:
                if (MatchCharset(*it, Charset28)) { state = 295; ++it; continue; }
                return -1;
            case 295:
                if (MatchCharset(*it, Charset17)) { state = 296; ++it; continue; }
                return -1;
            case 296:
                if (MatchCharset(*it, Charset7)) { state = 297; ++it; continue; }
                return -1;
            case 297:
                if (MatchCharset(*it, Charset23)) { state = 298; ++it; continue; }
                return -1;
            case 298:
                return 65;
            case 299:
                if (MatchCharset(*it, Charset32)) { state = 300; ++it; continue; }
                return -1;
            case 300:
                if (MatchCharset(*it, Charset5)) { state = 301; ++it; continue; }
                return -1;
            case 301:
                return 73;
            case 302:
                if (MatchCharset(*it, Charset19)) { state = 303; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 312; ++it; continue; }
                return -1;
            case 303:
                if (MatchCharset(*it, Charset11)) { state = 304; ++it; continue; }
                return -1;
            case 304:
                if (MatchCharset(*it, Charset16)) { state = 305; ++it; continue; }
                return -1;
            case 305:
                if (MatchCharset(*it, Charset29)) { state = 306; ++it; continue; }
                return -1;
            case 306:
                if (MatchCharset(*it, Charset17)) { state = 307; ++it; continue; }
                return -1;
            case 307:
                if (MatchCharset(*it, Charset7)) { state = 308; ++it; continue; }
                return -1;
            case 308:
                if (MatchCharset(*it, Charset13)) { state = 309; ++it; continue; }
                return -1;
            case 309:
                if (MatchCharset(*it, Charset15)) { state = 310; ++it; continue; }
                return -1;
            case 310:
                if (MatchCharset(*it, Charset9)) { state = 311; ++it; continue; }
                return -1;
            case 311:
                return 72;
            case 312:
                if (MatchCharset(*it, Charset7)) { state = 313; ++it; continue; }
                return -1;
            case 313:
                if (MatchCharset(*it, Charset22)) { state = 314; ++it; continue; }
                return -1;
            case 314:
                if (MatchCharset(*it, Charset11)) { state = 315; ++it; continue; }
                return -1;
            case 315:
                if (MatchCharset(*it, Charset33)) { state = 316; ++it; continue; }
                if (MatchCharset(*it, Charset34)) { state = 317; ++it; continue; }
                if (MatchCharset(*it, Charset35)) { state = 318; ++it; continue; }
                if (MatchCharset(*it, Charset29)) { state = 319; ++it; continue; }
                return -1;
            case 316:
                return 69;
            case 317:
                return 70;
            case 318:
                return 71;
            case 319:
                if (MatchCharset(*it, Charset17)) { state = 320; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 326; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 332; ++it; continue; }
                return -1;
            case 320:
                if (MatchCharset(*it, Charset11)) { state = 321; ++it; continue; }
                return -1;
            case 321:
                if (MatchCharset(*it, Charset10)) { state = 322; ++it; continue; }
                return -1;
            case 322:
                if (MatchCharset(*it, Charset15)) { state = 323; ++it; continue; }
                return -1;
            case 323:
                if (MatchCharset(*it, Charset24)) { state = 324; ++it; continue; }
                return -1;
            case 324:
                if (MatchCharset(*it, Charset17)) { state = 325; ++it; continue; }
                return -1;
            case 325:
                return 66;
            case 326:
                if (MatchCharset(*it, Charset11)) { state = 327; ++it; continue; }
                return -1;
            case 327:
                if (MatchCharset(*it, Charset31)) { state = 328; ++it; continue; }
                return -1;
            case 328:
                if (MatchCharset(*it, Charset11)) { state = 329; ++it; continue; }
                return -1;
            case 329:
                if (MatchCharset(*it, Charset21)) { state = 330; ++it; continue; }
                return -1;
            case 330:
                if (MatchCharset(*it, Charset11)) { state = 331; ++it; continue; }
                return -1;
            case 331:
                return 67;
            case 332:
                if (MatchCharset(*it, Charset11)) { state = 333; ++it; continue; }
                return -1;
            case 333:
                if (MatchCharset(*it, Charset7)) { state = 334; ++it; continue; }
                return -1;
            case 334:
                if (MatchCharset(*it, Charset30)) { state = 335; ++it; continue; }
                return -1;
            case 335:
                return 68;
            case 336:
                if (MatchCharset(*it, Charset7)) { state = 337; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 352; ++it; continue; }
                return -1;
            case 337:
                if (MatchCharset(*it, Charset13)) { state = 338; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 348; ++it; continue; }
                return -1;
            case 338:
                if (MatchCharset(*it, Charset28)) { state = 339; ++it; continue; }
                return -1;
            case 339:
                if (MatchCharset(*it, Charset18)) { state = 340; ++it; continue; }
                return -1;
            case 340:
                if (MatchCharset(*it, Charset29)) { state = 341; ++it; continue; }
                return -1;
            case 341:
                if (MatchCharset(*it, Charset8)) { state = 342; ++it; continue; }
                return -1;
            case 342:
                if (MatchCharset(*it, Charset21)) { state = 343; ++it; continue; }
                return -1;
            case 343:
                if (MatchCharset(*it, Charset11)) { state = 344; ++it; continue; }
                return -1;
            case 344:
                if (MatchCharset(*it, Charset7)) { state = 345; ++it; continue; }
                return -1;
            case 345:
                if (MatchCharset(*it, Charset23)) { state = 346; ++it; continue; }
                return -1;
            case 346:
                if (MatchCharset(*it, Charset14)) { state = 347; ++it; continue; }
                return -1;
            case 347:
                return 74;
            case 348:
                if (MatchCharset(*it, Charset18)) { state = 349; ++it; continue; }
                return -1;
            case 349:
                if (MatchCharset(*it, Charset22)) { state = 350; ++it; continue; }
                return -1;
            case 350:
                if (MatchCharset(*it, Charset19)) { state = 351; ++it; continue; }
                return -1;
            case 351:
                return 75;
            case 352:
                if (MatchCharset(*it, Charset13)) { state = 353; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 357; ++it; continue; }
                return -1;
            case 353:
                if (MatchCharset(*it, Charset13)) { state = 354; ++it; continue; }
                return -1;
            case 354:
                if (MatchCharset(*it, Charset11)) { state = 355; ++it; continue; }
                return -1;
            case 355:
                if (MatchCharset(*it, Charset10)) { state = 356; ++it; continue; }
                return -1;
            case 356:
                return 76;
            case 357:
                if (MatchCharset(*it, Charset30)) { state = 358; ++it; continue; }
                return -1;
            case 358:
                return 77;
            case 359:
                if (MatchCharset(*it, Charset7)) { state = 360; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 364; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 365; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 369; ++it; continue; }
                if (MatchCharset(*it, Charset4)) { state = 381; ++it; continue; }
                return 79;
            case 360:
                if (MatchCharset(*it, Charset21)) { state = 361; ++it; continue; }
                return -1;
            case 361:
                if (MatchCharset(*it, Charset23)) { state = 362; ++it; continue; }
                return -1;
            case 362:
                if (MatchCharset(*it, Charset14)) { state = 363; ++it; continue; }
                return -1;
            case 363:
                return 80;
            case 364:
                if (MatchCharset(*it, Charset6)) { state = 364; ++it; continue; }
                return 81;
            case 365:
                if (MatchCharset(*it, Charset21)) { state = 366; ++it; continue; }
                return -1;
            case 366:
                if (MatchCharset(*it, Charset7)) { state = 367; ++it; continue; }
                return -1;
            case 367:
                if (MatchCharset(*it, Charset10)) { state = 368; ++it; continue; }
                return -1;
            case 368:
                return 86;
            case 369:
                if (MatchCharset(*it, Charset9)) { state = 370; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 377; ++it; continue; }
                return -1;
            case 370:
                if (MatchCharset(*it, Charset14)) { state = 371; ++it; continue; }
                return -1;
            case 371:
                if (MatchCharset(*it, Charset7)) { state = 372; ++it; continue; }
                return -1;
            case 372:
                if (MatchCharset(*it, Charset18)) { state = 373; ++it; continue; }
                return -1;
            case 373:
                if (MatchCharset(*it, Charset23)) { state = 374; ++it; continue; }
                return -1;
            case 374:
                if (MatchCharset(*it, Charset11)) { state = 375; ++it; continue; }
                return -1;
            case 375:
                if (MatchCharset(*it, Charset21)) { state = 376; ++it; continue; }
                return -1;
            case 376:
                return 82;
            case 377:
                if (MatchCharset(*it, Charset21)) { state = 378; ++it; continue; }
                return -1;
            case 378:
                if (MatchCharset(*it, Charset13)) { state = 379; ++it; continue; }
                return 84;
            case 379:
                if (MatchCharset(*it, Charset5)) { state = 380; ++it; continue; }
                return -1;
            case 380:
                return 85;
            case 381:
                if (MatchCharset(*it, Charset19)) { state = 382; ++it; continue; }
                return -1;
            case 382:
                if (MatchCharset(*it, Charset11)) { state = 383; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 392; ++it; continue; }
                return -1;
            case 383:
                if (MatchCharset(*it, Charset21)) { state = 384; ++it; continue; }
                return -1;
            case 384:
                if (MatchCharset(*it, Charset23)) { state = 385; ++it; continue; }
                return -1;
            case 385:
                if (MatchCharset(*it, Charset14)) { state = 386; ++it; continue; }
                return -1;
            case 386:
                if (MatchCharset(*it, Charset11)) { state = 387; ++it; continue; }
                return -1;
            case 387:
                if (MatchCharset(*it, Charset7)) { state = 388; ++it; continue; }
                return -1;
            case 388:
                if (MatchCharset(*it, Charset16)) { state = 389; ++it; continue; }
                return -1;
            case 389:
                if (MatchCharset(*it, Charset11)) { state = 390; ++it; continue; }
                return -1;
            case 390:
                if (MatchCharset(*it, Charset21)) { state = 391; ++it; continue; }
                return -1;
            case 391:
                return 87;
            case 392:
                if (MatchCharset(*it, Charset28)) { state = 393; ++it; continue; }
                return -1;
            case 393:
                if (MatchCharset(*it, Charset10)) { state = 394; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 396; ++it; continue; }
                return -1;
            case 394:
                if (MatchCharset(*it, Charset11)) { state = 395; ++it; continue; }
                return -1;
            case 395:
                return 88;
            case 396:
                if (MatchCharset(*it, Charset11)) { state = 397; ++it; continue; }
                return -1;
            case 397:
                if (MatchCharset(*it, Charset21)) { state = 398; ++it; continue; }
                return -1;
            case 398:
                return 89;
            case 399:
                if (MatchCharset(*it, Charset21)) { state = 400; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 403; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 420; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 434; ++it; continue; }
                return -1;
            case 400:
                if (MatchCharset(*it, Charset11)) { state = 401; ++it; continue; }
                return -1;
            case 401:
                if (MatchCharset(*it, Charset11)) { state = 402; ++it; continue; }
                return -1;
            case 402:
                return 100;
            case 403:
                if (MatchCharset(*it, Charset9)) { state = 404; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 408; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 418; ++it; continue; }
                return -1;
            case 404:
                if (MatchCharset(*it, Charset23)) { state = 405; ++it; continue; }
                return -1;
            case 405:
                if (MatchCharset(*it, Charset28)) { state = 406; ++it; continue; }
                return -1;
            case 406:
                if (MatchCharset(*it, Charset21)) { state = 407; ++it; continue; }
                return -1;
            case 407:
                return 90;
            case 408:
                if (MatchCharset(*it, Charset16)) { state = 409; ++it; continue; }
                return -1;
            case 409:
                if (MatchCharset(*it, Charset11)) { state = 410; ++it; continue; }
                return -1;
            case 410:
                if (MatchCharset(*it, Charset18)) { state = 411; ++it; continue; }
                return -1;
            case 411:
                if (MatchCharset(*it, Charset25)) { state = 412; ++it; continue; }
                return -1;
            case 412:
                if (MatchCharset(*it, Charset15)) { state = 413; ++it; continue; }
                return -1;
            case 413:
                if (MatchCharset(*it, Charset32)) { state = 414; ++it; continue; }
                return -1;
            case 414:
                if (MatchCharset(*it, Charset7)) { state = 415; ++it; continue; }
                return -1;
            case 415:
                if (MatchCharset(*it, Charset21)) { state = 416; ++it; continue; }
                return -1;
            case 416:
                if (MatchCharset(*it, Charset10)) { state = 417; ++it; continue; }
                return -1;
            case 417:
                return 91;
            case 418:
                if (MatchCharset(*it, Charset11)) { state = 419; ++it; continue; }
                return -1;
            case 419:
                return 92;
            case 420:
                if (MatchCharset(*it, Charset21)) { state = 421; ++it; continue; }
                return -1;
            case 421:
                if (MatchCharset(*it, Charset11)) { state = 422; ++it; continue; }
                return -1;
            case 422:
                if (MatchCharset(*it, Charset29)) { state = 423; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 428; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 430; ++it; continue; }
                return 93;
            case 423:
                if (MatchCharset(*it, Charset8)) { state = 424; ++it; continue; }
                return -1;
            case 424:
                if (MatchCharset(*it, Charset28)) { state = 425; ++it; continue; }
                return -1;
            case 425:
                if (MatchCharset(*it, Charset16)) { state = 426; ++it; continue; }
                return -1;
            case 426:
                if (MatchCharset(*it, Charset23)) { state = 427; ++it; continue; }
                return -1;
            case 427:
                return 94;
            case 428:
                if (MatchCharset(*it, Charset21)) { state = 429; ++it; continue; }
                return -1;
            case 429:
                return 95;
            case 430:
                if (MatchCharset(*it, Charset7)) { state = 431; ++it; continue; }
                return -1;
            case 431:
                if (MatchCharset(*it, Charset16)) { state = 432; ++it; continue; }
                return -1;
            case 432:
                if (MatchCharset(*it, Charset16)) { state = 433; ++it; continue; }
                return -1;
            case 433:
                return 96;
            case 434:
                if (MatchCharset(*it, Charset28)) { state = 435; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 437; ++it; continue; }
                return -1;
            case 435:
                if (MatchCharset(*it, Charset16)) { state = 436; ++it; continue; }
                return -1;
            case 436:
                return 98;
            case 437:
                if (MatchCharset(*it, Charset11)) { state = 438; ++it; continue; }
                return -1;
            case 438:
                if (MatchCharset(*it, Charset22)) { state = 439; ++it; continue; }
                return -1;
            case 439:
                if (MatchCharset(*it, Charset23)) { state = 440; ++it; continue; }
                return -1;
            case 440:
                return 99;
            case 441:
                if (MatchCharset(*it, Charset16)) { state = 442; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 447; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 450; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 455; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 459; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 463; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 479; ++it; continue; }
                return 101;
            case 442:
                if (MatchCharset(*it, Charset28)) { state = 443; ++it; continue; }
                return -1;
            case 443:
                if (MatchCharset(*it, Charset8)) { state = 444; ++it; continue; }
                return -1;
            case 444:
                if (MatchCharset(*it, Charset7)) { state = 445; ++it; continue; }
                return -1;
            case 445:
                if (MatchCharset(*it, Charset16)) { state = 446; ++it; continue; }
                return -1;
            case 446:
                return 106;
            case 447:
                if (MatchCharset(*it, Charset16)) { state = 448; ++it; continue; }
                return -1;
            case 448:
                if (MatchCharset(*it, Charset10)) { state = 449; ++it; continue; }
                return -1;
            case 449:
                return 107;
            case 450:
                if (MatchCharset(*it, Charset28)) { state = 451; ++it; continue; }
                return -1;
            case 451:
                if (MatchCharset(*it, Charset24)) { state = 452; ++it; continue; }
                return -1;
            case 452:
                if (MatchCharset(*it, Charset18)) { state = 453; ++it; continue; }
                return -1;
            case 453:
                if (MatchCharset(*it, Charset10)) { state = 454; ++it; continue; }
                return -1;
            case 454:
                return 108;
            case 455:
                if (MatchCharset(*it, Charset15)) { state = 456; ++it; continue; }
                return -1;
            case 456:
                if (MatchCharset(*it, Charset10)) { state = 457; ++it; continue; }
                return -1;
            case 457:
                if (MatchCharset(*it, Charset11)) { state = 458; ++it; continue; }
                return -1;
            case 458:
                return 109;
            case 459:
                if (MatchCharset(*it, Charset19)) { state = 460; ++it; continue; }
                return -1;
            case 460:
                if (MatchCharset(*it, Charset22)) { state = 461; ++it; continue; }
                return -1;
            case 461:
                if (MatchCharset(*it, Charset5)) { state = 462; ++it; continue; }
                return -1;
            case 462:
                return 110;
            case 463:
                if (MatchCharset(*it, Charset23)) { state = 464; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 472; ++it; continue; }
                return -1;
            case 464:
                if (MatchCharset(*it, Charset11)) { state = 465; ++it; continue; }
                return -1;
            case 465:
                if (MatchCharset(*it, Charset17)) { state = 466; ++it; continue; }
                return -1;
            case 466:
                if (MatchCharset(*it, Charset7)) { state = 467; ++it; continue; }
                return -1;
            case 467:
                if (MatchCharset(*it, Charset22)) { state = 468; ++it; continue; }
                return -1;
            case 468:
                if (MatchCharset(*it, Charset23)) { state = 469; ++it; continue; }
                return -1;
            case 469:
                if (MatchCharset(*it, Charset11)) { state = 470; ++it; continue; }
                return -1;
            case 470:
                if (MatchCharset(*it, Charset21)) { state = 471; ++it; continue; }
                return -1;
            case 471:
                return 102;
            case 472:
                if (MatchCharset(*it, Charset18)) { state = 473; ++it; continue; }
                return -1;
            case 473:
                if (MatchCharset(*it, Charset23)) { state = 474; ++it; continue; }
                return -1;
            case 474:
                if (MatchCharset(*it, Charset16)) { state = 475; ++it; continue; }
                return -1;
            case 475:
                if (MatchCharset(*it, Charset11)) { state = 476; ++it; continue; }
                return -1;
            case 476:
                if (MatchCharset(*it, Charset23)) { state = 477; ++it; continue; }
                return -1;
            case 477:
                if (MatchCharset(*it, Charset22)) { state = 478; ++it; continue; }
                return -1;
            case 478:
                return 103;
            case 479:
                if (MatchCharset(*it, Charset17)) { state = 480; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 481; ++it; continue; }
                return -1;
            case 480:
                return 104;
            case 481:
                if (MatchCharset(*it, Charset11)) { state = 482; ++it; continue; }
                return -1;
            case 482:
                if (MatchCharset(*it, Charset21)) { state = 483; ++it; continue; }
                return -1;
            case 483:
                if (MatchCharset(*it, Charset15)) { state = 484; ++it; continue; }
                return -1;
            case 484:
                if (MatchCharset(*it, Charset9)) { state = 485; ++it; continue; }
                return -1;
            case 485:
                return 105;
            case 486:
                if (MatchCharset(*it, Charset24)) { state = 487; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 492; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 516; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 534; ++it; continue; }
                return -1;
            case 487:
                if (MatchCharset(*it, Charset18)) { state = 488; ++it; continue; }
                return -1;
            case 488:
                if (MatchCharset(*it, Charset23)) { state = 489; ++it; continue; }
                return -1;
            case 489:
                if (MatchCharset(*it, Charset11)) { state = 490; ++it; continue; }
                return -1;
            case 490:
                if (MatchCharset(*it, Charset21)) { state = 491; ++it; continue; }
                return -1;
            case 491:
                return 123;
            case 492:
                if (MatchCharset(*it, Charset16)) { state = 493; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 498; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 507; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 511; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 513; ++it; continue; }
                return -1;
            case 493:
                if (MatchCharset(*it, Charset16)) { state = 494; ++it; continue; }
                return -1;
            case 494:
                if (MatchCharset(*it, Charset25)) { state = 495; ++it; continue; }
                return -1;
            case 495:
                if (MatchCharset(*it, Charset7)) { state = 496; ++it; continue; }
                return -1;
            case 496:
                if (MatchCharset(*it, Charset5)) { state = 497; ++it; continue; }
                return -1;
            case 497:
                return 111;
            case 498:
                if (MatchCharset(*it, Charset17)) { state = 499; ++it; continue; }
                return -1;
            case 499:
                if (MatchCharset(*it, Charset11)) { state = 500; ++it; continue; }
                return -1;
            case 500:
                if (MatchCharset(*it, Charset21)) { state = 501; ++it; continue; }
                return -1;
            case 501:
                if (MatchCharset(*it, Charset14)) { state = 502; ++it; continue; }
                return -1;
            case 502:
                if (MatchCharset(*it, Charset7)) { state = 503; ++it; continue; }
                return -1;
            case 503:
                if (MatchCharset(*it, Charset18)) { state = 504; ++it; continue; }
                return -1;
            case 504:
                if (MatchCharset(*it, Charset10)) { state = 505; ++it; continue; }
                return -1;
            case 505:
                if (MatchCharset(*it, Charset22)) { state = 506; ++it; continue; }
                return -1;
            case 506:
                return 112;
            case 507:
                if (MatchCharset(*it, Charset13)) { state = 508; ++it; continue; }
                return -1;
            case 508:
                if (MatchCharset(*it, Charset7)) { state = 509; ++it; continue; }
                return -1;
            case 509:
                if (MatchCharset(*it, Charset21)) { state = 510; ++it; continue; }
                return -1;
            case 510:
                return 113;
            case 511:
                if (MatchCharset(*it, Charset17)) { state = 512; ++it; continue; }
                return -1;
            case 512:
                return 114;
            case 513:
                if (MatchCharset(*it, Charset23)) { state = 514; ++it; continue; }
                return -1;
            case 514:
                if (MatchCharset(*it, Charset11)) { state = 515; ++it; continue; }
                return -1;
            case 515:
                return 115;
            case 516:
                if (MatchCharset(*it, Charset7)) { state = 517; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 521; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 523; ++it; continue; }
                return -1;
            case 517:
                if (MatchCharset(*it, Charset16)) { state = 518; ++it; continue; }
                return -1;
            case 518:
                if (MatchCharset(*it, Charset11)) { state = 519; ++it; continue; }
                return -1;
            case 519:
                if (MatchCharset(*it, Charset21)) { state = 520; ++it; continue; }
                return -1;
            case 520:
                return 116;
            case 521:
                if (MatchCharset(*it, Charset17)) { state = 522; ++it; continue; }
                return -1;
            case 522:
                return 117;
            case 523:
                if (MatchCharset(*it, Charset28)) { state = 524; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 528; ++it; continue; }
                return -1;
            case 524:
                if (MatchCharset(*it, Charset15)) { state = 525; ++it; continue; }
                return -1;
            case 525:
                if (MatchCharset(*it, Charset22)) { state = 526; ++it; continue; }
                return -1;
            case 526:
                if (MatchCharset(*it, Charset17)) { state = 527; ++it; continue; }
                return -1;
            case 527:
                return 120;
            case 528:
                if (MatchCharset(*it, Charset7)) { state = 529; ++it; continue; }
                return 118;
            case 529:
                if (MatchCharset(*it, Charset16)) { state = 530; ++it; continue; }
                return -1;
            case 530:
                if (MatchCharset(*it, Charset15)) { state = 531; ++it; continue; }
                return -1;
            case 531:
                if (MatchCharset(*it, Charset22)) { state = 532; ++it; continue; }
                return -1;
            case 532:
                if (MatchCharset(*it, Charset23)) { state = 533; ++it; continue; }
                return -1;
            case 533:
                return 119;
            case 534:
                if (MatchCharset(*it, Charset21)) { state = 535; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 541; ++it; continue; }
                return -1;
            case 535:
                if (MatchCharset(*it, Charset22)) { state = 536; ++it; continue; }
                return -1;
            case 536:
                if (MatchCharset(*it, Charset11)) { state = 537; ++it; continue; }
                return -1;
            case 537:
                if (MatchCharset(*it, Charset17)) { state = 538; ++it; continue; }
                return -1;
            case 538:
                if (MatchCharset(*it, Charset7)) { state = 539; ++it; continue; }
                return -1;
            case 539:
                if (MatchCharset(*it, Charset18)) { state = 540; ++it; continue; }
                return -1;
            case 540:
                return 121;
            case 541:
                if (MatchCharset(*it, Charset21)) { state = 542; ++it; continue; }
                return -1;
            case 542:
                if (MatchCharset(*it, Charset29)) { state = 543; ++it; continue; }
                return -1;
            case 543:
                if (MatchCharset(*it, Charset28)) { state = 544; ++it; continue; }
                return -1;
            case 544:
                if (MatchCharset(*it, Charset12)) { state = 545; ++it; continue; }
                return -1;
            case 545:
                if (MatchCharset(*it, Charset29)) { state = 546; ++it; continue; }
                return -1;
            case 546:
                if (MatchCharset(*it, Charset19)) { state = 547; ++it; continue; }
                return -1;
            case 547:
                if (MatchCharset(*it, Charset28)) { state = 548; ++it; continue; }
                return -1;
            case 548:
                if (MatchCharset(*it, Charset25)) { state = 549; ++it; continue; }
                return -1;
            case 549:
                if (MatchCharset(*it, Charset11)) { state = 550; ++it; continue; }
                return -1;
            case 550:
                if (MatchCharset(*it, Charset21)) { state = 551; ++it; continue; }
                return -1;
            case 551:
                return 122;
            case 552:
                if (MatchCharset(*it, Charset17)) { state = 553; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 555; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 566; ++it; continue; }
                return -1;
            case 553:
                if (MatchCharset(*it, Charset17)) { state = 554; ++it; continue; }
                return -1;
            case 554:
                return 126;
            case 555:
                if (MatchCharset(*it, Charset11)) { state = 556; ++it; continue; }
                return -1;
            case 556:
                if (MatchCharset(*it, Charset29)) { state = 557; ++it; continue; }
                return -1;
            case 557:
                if (MatchCharset(*it, Charset8)) { state = 558; ++it; continue; }
                return -1;
            case 558:
                if (MatchCharset(*it, Charset16)) { state = 559; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 563; ++it; continue; }
                return -1;
            case 559:
                if (MatchCharset(*it, Charset7)) { state = 560; ++it; continue; }
                return -1;
            case 560:
                if (MatchCharset(*it, Charset22)) { state = 561; ++it; continue; }
                return -1;
            case 561:
                if (MatchCharset(*it, Charset23)) { state = 562; ++it; continue; }
                return -1;
            case 562:
                return 124;
            case 563:
                if (MatchCharset(*it, Charset16)) { state = 564; ++it; continue; }
                return -1;
            case 564:
                if (MatchCharset(*it, Charset23)) { state = 565; ++it; continue; }
                return -1;
            case 565:
                return 125;
            case 566:
                if (MatchCharset(*it, Charset9)) { state = 567; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 575; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 581; ++it; continue; }
                return -1;
            case 567:
                if (MatchCharset(*it, Charset15)) { state = 568; ++it; continue; }
                return -1;
            case 568:
                if (MatchCharset(*it, Charset18)) { state = 569; ++it; continue; }
                return -1;
            case 569:
                if (MatchCharset(*it, Charset11)) { state = 570; ++it; continue; }
                return -1;
            case 570:
                if (MatchCharset(*it, Charset21)) { state = 571; ++it; continue; }
                return -1;
            case 571:
                if (MatchCharset(*it, Charset7)) { state = 572; ++it; continue; }
                return -1;
            case 572:
                if (MatchCharset(*it, Charset23)) { state = 573; ++it; continue; }
                return -1;
            case 573:
                if (MatchCharset(*it, Charset11)) { state = 574; ++it; continue; }
                return -1;
            case 574:
                return 127;
            case 575:
                if (MatchCharset(*it, Charset23)) { state = 576; ++it; continue; }
                return -1;
            case 576:
                if (MatchCharset(*it, Charset15)) { state = 577; ++it; continue; }
                return -1;
            case 577:
                if (MatchCharset(*it, Charset7)) { state = 578; ++it; continue; }
                return -1;
            case 578:
                if (MatchCharset(*it, Charset23)) { state = 579; ++it; continue; }
                return -1;
            case 579:
                if (MatchCharset(*it, Charset11)) { state = 580; ++it; continue; }
                return -1;
            case 580:
                return 128;
            case 581:
                if (MatchCharset(*it, Charset7)) { state = 582; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 585; ++it; continue; }
                return -1;
            case 582:
                if (MatchCharset(*it, Charset18)) { state = 583; ++it; continue; }
                return -1;
            case 583:
                if (MatchCharset(*it, Charset11)) { state = 584; ++it; continue; }
                return -1;
            case 584:
                return 129;
            case 585:
                if (MatchCharset(*it, Charset21)) { state = 586; ++it; continue; }
                return -1;
            case 586:
                if (MatchCharset(*it, Charset24)) { state = 587; ++it; continue; }
                return -1;
            case 587:
                if (MatchCharset(*it, Charset9)) { state = 588; ++it; continue; }
                return -1;
            case 588:
                if (MatchCharset(*it, Charset23)) { state = 589; ++it; continue; }
                return -1;
            case 589:
                if (MatchCharset(*it, Charset28)) { state = 590; ++it; continue; }
                return -1;
            case 590:
                if (MatchCharset(*it, Charset21)) { state = 591; ++it; continue; }
                return -1;
            case 591:
                return 130;
            case 592:
                if (MatchCharset(*it, Charset11)) { state = 593; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 599; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 625; ++it; continue; }
                return -1;
            case 593:
                if (MatchCharset(*it, Charset7)) { state = 594; ++it; continue; }
                return -1;
            case 594:
                if (MatchCharset(*it, Charset23)) { state = 595; ++it; continue; }
                return -1;
            case 595:
                if (MatchCharset(*it, Charset14)) { state = 596; ++it; continue; }
                return -1;
            case 596:
                if (MatchCharset(*it, Charset11)) { state = 597; ++it; continue; }
                return -1;
            case 597:
                if (MatchCharset(*it, Charset21)) { state = 598; ++it; continue; }
                return -1;
            case 598:
                return 132;
            case 599:
                if (MatchCharset(*it, Charset31)) { state = 600; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 608; ++it; continue; }
                return -1;
            case 600:
                if (MatchCharset(*it, Charset15)) { state = 601; ++it; continue; }
                return -1;
            case 601:
                if (MatchCharset(*it, Charset18)) { state = 602; ++it; continue; }
                return -1;
            case 602:
                if (MatchCharset(*it, Charset13)) { state = 603; ++it; continue; }
                return -1;
            case 603:
                if (MatchCharset(*it, Charset21)) { state = 604; ++it; continue; }
                return -1;
            case 604:
                if (MatchCharset(*it, Charset28)) { state = 605; ++it; continue; }
                return -1;
            case 605:
                if (MatchCharset(*it, Charset28)) { state = 606; ++it; continue; }
                return -1;
            case 606:
                if (MatchCharset(*it, Charset17)) { state = 607; ++it; continue; }
                return -1;
            case 607:
                return 136;
            case 608:
                if (MatchCharset(*it, Charset14)) { state = 609; ++it; continue; }
                return -1;
            case 609:
                if (MatchCharset(*it, Charset23)) { state = 610; ++it; continue; }
                return -1;
            case 610:
                if (MatchCharset(*it, Charset29)) { state = 611; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 616; ++it; continue; }
                return 133;
            case 611:
                if (MatchCharset(*it, Charset8)) { state = 612; ++it; continue; }
                return -1;
            case 612:
                if (MatchCharset(*it, Charset28)) { state = 613; ++it; continue; }
                return -1;
            case 613:
                if (MatchCharset(*it, Charset16)) { state = 614; ++it; continue; }
                return -1;
            case 614:
                if (MatchCharset(*it, Charset23)) { state = 615; ++it; continue; }
                return -1;
            case 615:
                return 134;
            case 616:
                if (MatchCharset(*it, Charset15)) { state = 617; ++it; continue; }
                return -1;
            case 617:
                if (MatchCharset(*it, Charset18)) { state = 618; ++it; continue; }
                return -1;
            case 618:
                if (MatchCharset(*it, Charset13)) { state = 619; ++it; continue; }
                return -1;
            case 619:
                if (MatchCharset(*it, Charset29)) { state = 620; ++it; continue; }
                return -1;
            case 620:
                if (MatchCharset(*it, Charset8)) { state = 621; ++it; continue; }
                return -1;
            case 621:
                if (MatchCharset(*it, Charset28)) { state = 622; ++it; continue; }
                return -1;
            case 622:
                if (MatchCharset(*it, Charset16)) { state = 623; ++it; continue; }
                return -1;
            case 623:
                if (MatchCharset(*it, Charset23)) { state = 624; ++it; continue; }
                return -1;
            case 624:
                return 135;
            case 625:
                if (MatchCharset(*it, Charset9)) { state = 626; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 633; ++it; continue; }
                return -1;
            case 626:
                if (MatchCharset(*it, Charset30)) { state = 627; ++it; continue; }
                return -1;
            case 627:
                if (MatchCharset(*it, Charset22)) { state = 628; ++it; continue; }
                return -1;
            case 628:
                if (MatchCharset(*it, Charset17)) { state = 629; ++it; continue; }
                return -1;
            case 629:
                if (MatchCharset(*it, Charset15)) { state = 630; ++it; continue; }
                return -1;
            case 630:
                if (MatchCharset(*it, Charset23)) { state = 631; ++it; continue; }
                return -1;
            case 631:
                if (MatchCharset(*it, Charset14)) { state = 632; ++it; continue; }
                return -1;
            case 632:
                return 137;
            case 633:
                if (MatchCharset(*it, Charset13)) { state = 634; ++it; continue; }
                return -1;
            case 634:
                return 138;
            case 635:
                if (MatchCharset(*it, Charset6)) { state = 636; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 637; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 643; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 648; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 661; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 680; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 695; ++it; continue; }
                return 139;
            case 636:
                if (MatchCharset(*it, Charset6)) { state = 636; ++it; continue; }
                return 148;
            case 637:
                if (MatchCharset(*it, Charset9)) { state = 638; ++it; continue; }
                return -1;
            case 638:
                if (MatchCharset(*it, Charset21)) { state = 639; ++it; continue; }
                return -1;
            case 639:
                if (MatchCharset(*it, Charset28)) { state = 640; ++it; continue; }
                return -1;
            case 640:
                if (MatchCharset(*it, Charset16)) { state = 641; ++it; continue; }
                return -1;
            case 641:
                if (MatchCharset(*it, Charset16)) { state = 642; ++it; continue; }
                return -1;
            case 642:
                return 151;
            case 643:
                if (MatchCharset(*it, Charset22)) { state = 644; ++it; continue; }
                return -1;
            case 644:
                if (MatchCharset(*it, Charset23)) { state = 645; ++it; continue; }
                return -1;
            case 645:
                if (MatchCharset(*it, Charset15)) { state = 646; ++it; continue; }
                return -1;
            case 646:
                if (MatchCharset(*it, Charset9)) { state = 647; ++it; continue; }
                return -1;
            case 647:
                return 152;
            case 648:
                if (MatchCharset(*it, Charset9)) { state = 649; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 651; ++it; continue; }
                return -1;
            case 649:
                if (MatchCharset(*it, Charset11)) { state = 650; ++it; continue; }
                return -1;
            case 650:
                return 140;
            case 651:
                if (MatchCharset(*it, Charset23)) { state = 652; ++it; continue; }
                return -1;
            case 652:
                if (MatchCharset(*it, Charset11)) { state = 653; ++it; continue; }
                return -1;
            case 653:
                if (MatchCharset(*it, Charset21)) { state = 654; ++it; continue; }
                return -1;
            case 654:
                if (MatchCharset(*it, Charset14)) { state = 655; ++it; continue; }
                return -1;
            case 655:
                if (MatchCharset(*it, Charset11)) { state = 656; ++it; continue; }
                return -1;
            case 656:
                if (MatchCharset(*it, Charset7)) { state = 657; ++it; continue; }
                return -1;
            case 657:
                if (MatchCharset(*it, Charset16)) { state = 658; ++it; continue; }
                return -1;
            case 658:
                if (MatchCharset(*it, Charset11)) { state = 659; ++it; continue; }
                return -1;
            case 659:
                if (MatchCharset(*it, Charset21)) { state = 660; ++it; continue; }
                return -1;
            case 660:
                return 141;
            case 661:
                if (MatchCharset(*it, Charset10)) { state = 662; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 663; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 669; ++it; continue; }
                return -1;
            case 662:
                return 142;
            case 663:
                if (MatchCharset(*it, Charset9)) { state = 664; ++it; continue; }
                return -1;
            case 664:
                if (MatchCharset(*it, Charset14)) { state = 665; ++it; continue; }
                return -1;
            case 665:
                if (MatchCharset(*it, Charset7)) { state = 666; ++it; continue; }
                return -1;
            case 666:
                if (MatchCharset(*it, Charset18)) { state = 667; ++it; continue; }
                return -1;
            case 667:
                if (MatchCharset(*it, Charset23)) { state = 668; ++it; continue; }
                return -1;
            case 668:
                return 143;
            case 669:
                if (MatchCharset(*it, Charset11)) { state = 670; ++it; continue; }
                return -1;
            case 670:
                if (MatchCharset(*it, Charset28)) { state = 671; ++it; continue; }
                return -1;
            case 671:
                if (MatchCharset(*it, Charset21)) { state = 672; ++it; continue; }
                return -1;
            case 672:
                if (MatchCharset(*it, Charset29)) { state = 673; ++it; continue; }
                return -1;
            case 673:
                if (MatchCharset(*it, Charset22)) { state = 674; ++it; continue; }
                return -1;
            case 674:
                if (MatchCharset(*it, Charset14)) { state = 675; ++it; continue; }
                return -1;
            case 675:
                if (MatchCharset(*it, Charset28)) { state = 676; ++it; continue; }
                return -1;
            case 676:
                if (MatchCharset(*it, Charset25)) { state = 677; ++it; continue; }
                return -1;
            case 677:
                if (MatchCharset(*it, Charset11)) { state = 678; ++it; continue; }
                return -1;
            case 678:
                if (MatchCharset(*it, Charset21)) { state = 679; ++it; continue; }
                return -1;
            case 679:
                return 144;
            case 680:
                if (MatchCharset(*it, Charset18)) { state = 681; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 689; ++it; continue; }
                return -1;
            case 681:
                if (MatchCharset(*it, Charset10)) { state = 682; ++it; continue; }
                return -1;
            case 682:
                if (MatchCharset(*it, Charset29)) { state = 683; ++it; continue; }
                return -1;
            case 683:
                if (MatchCharset(*it, Charset8)) { state = 684; ++it; continue; }
                return -1;
            case 684:
                if (MatchCharset(*it, Charset16)) { state = 685; ++it; continue; }
                return -1;
            case 685:
                if (MatchCharset(*it, Charset7)) { state = 686; ++it; continue; }
                return -1;
            case 686:
                if (MatchCharset(*it, Charset22)) { state = 687; ++it; continue; }
                return -1;
            case 687:
                if (MatchCharset(*it, Charset23)) { state = 688; ++it; continue; }
                return -1;
            case 688:
                return 145;
            case 689:
                if (MatchCharset(*it, Charset9)) { state = 690; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 691; ++it; continue; }
                return -1;
            case 690:
                return 146;
            case 691:
                if (MatchCharset(*it, Charset15)) { state = 692; ++it; continue; }
                return -1;
            case 692:
                if (MatchCharset(*it, Charset16)) { state = 693; ++it; continue; }
                return -1;
            case 693:
                if (MatchCharset(*it, Charset11)) { state = 694; ++it; continue; }
                return -1;
            case 694:
                return 147;
            case 695:
                if (MatchCharset(*it, Charset18)) { state = 696; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 698; ++it; continue; }
                return -1;
            case 696:
                if (MatchCharset(*it, Charset30)) { state = 697; ++it; continue; }
                return -1;
            case 697:
                return 149;
            case 698:
                if (MatchCharset(*it, Charset18)) { state = 699; ++it; continue; }
                return -1;
            case 699:
                if (MatchCharset(*it, Charset23)) { state = 700; ++it; continue; }
                return -1;
            case 700:
                if (MatchCharset(*it, Charset7)) { state = 701; ++it; continue; }
                return -1;
            case 701:
                if (MatchCharset(*it, Charset15)) { state = 702; ++it; continue; }
                return -1;
            case 702:
                if (MatchCharset(*it, Charset18)) { state = 703; ++it; continue; }
                return -1;
            case 703:
                return 150;
            case 704:
                if (MatchCharset(*it, Charset7)) { state = 705; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 713; ++it; continue; }
                return 153;
            case 705:
                if (MatchCharset(*it, Charset31)) { state = 706; ++it; continue; }
                return -1;
            case 706:
                if (MatchCharset(*it, Charset15)) { state = 707; ++it; continue; }
                return -1;
            case 707:
                if (MatchCharset(*it, Charset13)) { state = 708; ++it; continue; }
                return -1;
            case 708:
                if (MatchCharset(*it, Charset7)) { state = 709; ++it; continue; }
                return -1;
            case 709:
                if (MatchCharset(*it, Charset23)) { state = 710; ++it; continue; }
                return -1;
            case 710:
                if (MatchCharset(*it, Charset28)) { state = 711; ++it; continue; }
                return -1;
            case 711:
                if (MatchCharset(*it, Charset21)) { state = 712; ++it; continue; }
                return -1;
            case 712:
                return 154;
            case 713:
                if (MatchCharset(*it, Charset21)) { state = 714; ++it; continue; }
                return 155;
            case 714:
                if (MatchCharset(*it, Charset17)) { state = 715; ++it; continue; }
                return -1;
            case 715:
                if (MatchCharset(*it, Charset7)) { state = 716; ++it; continue; }
                return -1;
            case 716:
                if (MatchCharset(*it, Charset16)) { state = 717; ++it; continue; }
                return -1;
            case 717:
                return 156;
            case 718:
                if (MatchCharset(*it, Charset21)) { state = 719; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 725; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 768; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 775; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 783; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 790; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 827; ++it; continue; }
                return -1;
            case 719:
                if (MatchCharset(*it, Charset11)) { state = 720; ++it; continue; }
                return -1;
            case 720:
                if (MatchCharset(*it, Charset16)) { state = 721; ++it; continue; }
                return -1;
            case 721:
                if (MatchCharset(*it, Charset7)) { state = 722; ++it; continue; }
                return -1;
            case 722:
                if (MatchCharset(*it, Charset23)) { state = 723; ++it; continue; }
                return -1;
            case 723:
                if (MatchCharset(*it, Charset11)) { state = 724; ++it; continue; }
                return -1;
            case 724:
                return 177;
            case 725:
                if (MatchCharset(*it, Charset10)) { state = 726; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 734; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 747; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 755; ++it; continue; }
                return -1;
            case 726:
                if (MatchCharset(*it, Charset10)) { state = 727; ++it; continue; }
                return -1;
            case 727:
                if (MatchCharset(*it, Charset11)) { state = 728; ++it; continue; }
                return -1;
            case 728:
                if (MatchCharset(*it, Charset10)) { state = 729; ++it; continue; }
                return -1;
            case 729:
                if (MatchCharset(*it, Charset9)) { state = 730; ++it; continue; }
                return -1;
            case 730:
                if (MatchCharset(*it, Charset11)) { state = 731; ++it; continue; }
                return -1;
            case 731:
                if (MatchCharset(*it, Charset16)) { state = 732; ++it; continue; }
                return -1;
            case 732:
                if (MatchCharset(*it, Charset16)) { state = 733; ++it; continue; }
                return -1;
            case 733:
                return 157;
            case 734:
                if (MatchCharset(*it, Charset18)) { state = 735; ++it; continue; }
                return -1;
            case 735:
                if (MatchCharset(*it, Charset29)) { state = 736; ++it; continue; }
                return -1;
            case 736:
                if (MatchCharset(*it, Charset21)) { state = 737; ++it; continue; }
                return -1;
            case 737:
                if (MatchCharset(*it, Charset11)) { state = 738; ++it; continue; }
                return -1;
            case 738:
                if (MatchCharset(*it, Charset12)) { state = 739; ++it; continue; }
                return -1;
            case 739:
                if (MatchCharset(*it, Charset16)) { state = 740; ++it; continue; }
                return -1;
            case 740:
                if (MatchCharset(*it, Charset11)) { state = 741; ++it; continue; }
                return -1;
            case 741:
                if (MatchCharset(*it, Charset9)) { state = 742; ++it; continue; }
                return -1;
            case 742:
                if (MatchCharset(*it, Charset23)) { state = 743; ++it; continue; }
                return -1;
            case 743:
                if (MatchCharset(*it, Charset15)) { state = 744; ++it; continue; }
                return -1;
            case 744:
                if (MatchCharset(*it, Charset28)) { state = 745; ++it; continue; }
                return -1;
            case 745:
                if (MatchCharset(*it, Charset18)) { state = 746; ++it; continue; }
                return -1;
            case 746:
                return 158;
            case 747:
                if (MatchCharset(*it, Charset14)) { state = 748; ++it; continue; }
                return -1;
            case 748:
                if (MatchCharset(*it, Charset12)) { state = 749; ++it; continue; }
                return -1;
            case 749:
                if (MatchCharset(*it, Charset15)) { state = 750; ++it; continue; }
                return -1;
            case 750:
                if (MatchCharset(*it, Charset18)) { state = 751; ++it; continue; }
                return -1;
            case 751:
                if (MatchCharset(*it, Charset10)) { state = 752; ++it; continue; }
                return -1;
            case 752:
                if (MatchCharset(*it, Charset11)) { state = 753; ++it; continue; }
                return -1;
            case 753:
                if (MatchCharset(*it, Charset21)) { state = 754; ++it; continue; }
                return -1;
            case 754:
                return 161;
            case 755:
                if (MatchCharset(*it, Charset7)) { state = 756; ++it; continue; }
                if (MatchCharset(*it, Charset30)) { state = 761; ++it; continue; }
                return -1;
            case 756:
                if (MatchCharset(*it, Charset16)) { state = 757; ++it; continue; }
                return -1;
            case 757:
                if (MatchCharset(*it, Charset5)) { state = 758; ++it; continue; }
                return -1;
            case 758:
                if (MatchCharset(*it, Charset32)) { state = 759; ++it; continue; }
                return -1;
            case 759:
                if (MatchCharset(*it, Charset11)) { state = 760; ++it; continue; }
                return -1;
            case 760:
                return 159;
            case 761:
                if (MatchCharset(*it, Charset15)) { state = 762; ++it; continue; }
                return -1;
            case 762:
                if (MatchCharset(*it, Charset18)) { state = 763; ++it; continue; }
                return -1;
            case 763:
                if (MatchCharset(*it, Charset13)) { state = 764; ++it; continue; }
                return -1;
            case 764:
                if (MatchCharset(*it, Charset16)) { state = 765; ++it; continue; }
                return -1;
            case 765:
                if (MatchCharset(*it, Charset28)) { state = 766; ++it; continue; }
                return -1;
            case 766:
                if (MatchCharset(*it, Charset23)) { state = 767; ++it; continue; }
                return -1;
            case 767:
                return 160;
            case 768:
                if (MatchCharset(*it, Charset5)) { state = 769; ++it; continue; }
                return -1;
            case 769:
                if (MatchCharset(*it, Charset22)) { state = 770; ++it; continue; }
                return -1;
            case 770:
                if (MatchCharset(*it, Charset15)) { state = 771; ++it; continue; }
                return 162;
            case 771:
                if (MatchCharset(*it, Charset9)) { state = 772; ++it; continue; }
                return -1;
            case 772:
                if (MatchCharset(*it, Charset7)) { state = 773; ++it; continue; }
                return -1;
            case 773:
                if (MatchCharset(*it, Charset16)) { state = 774; ++it; continue; }
                return -1;
            case 774:
                return 163;
            case 775:
                if (MatchCharset(*it, Charset19)) { state = 776; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 779; ++it; continue; }
                return -1;
            case 776:
                if (MatchCharset(*it, Charset11)) { state = 777; ++it; continue; }
                return -1;
            case 777:
                if (MatchCharset(*it, Charset21)) { state = 778; ++it; continue; }
                return -1;
            case 778:
                return 164;
            case 779:
                if (MatchCharset(*it, Charset7)) { state = 780; ++it; continue; }
                return -1;
            case 780:
                if (MatchCharset(*it, Charset23)) { state = 781; ++it; continue; }
                return -1;
            case 781:
                if (MatchCharset(*it, Charset11)) { state = 782; ++it; continue; }
                return -1;
            case 782:
                return 165;
            case 783:
                if (MatchCharset(*it, Charset7)) { state = 784; ++it; continue; }
                return -1;
            case 784:
                if (MatchCharset(*it, Charset15)) { state = 785; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 788; ++it; continue; }
                return -1;
            case 785:
                if (MatchCharset(*it, Charset18)) { state = 786; ++it; continue; }
                return -1;
            case 786:
                if (MatchCharset(*it, Charset22)) { state = 787; ++it; continue; }
                return -1;
            case 787:
                return 166;
            case 788:
                if (MatchCharset(*it, Charset11)) { state = 789; ++it; continue; }
                return -1;
            case 789:
                return 167;
            case 790:
                if (MatchCharset(*it, Charset21)) { state = 791; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 795; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 803; ++it; continue; }
                return -1;
            case 791:
                if (MatchCharset(*it, Charset23)) { state = 792; ++it; continue; }
                return -1;
            case 792:
                if (MatchCharset(*it, Charset11)) { state = 793; ++it; continue; }
                return -1;
            case 793:
                if (MatchCharset(*it, Charset21)) { state = 794; ++it; continue; }
                return -1;
            case 794:
                return 175;
            case 795:
                if (MatchCharset(*it, Charset11)) { state = 796; ++it; continue; }
                return -1;
            case 796:
                if (MatchCharset(*it, Charset21)) { state = 797; ++it; continue; }
                return -1;
            case 797:
                if (MatchCharset(*it, Charset29)) { state = 798; ++it; continue; }
                return -1;
            case 798:
                if (MatchCharset(*it, Charset9)) { state = 799; ++it; continue; }
                return -1;
            case 799:
                if (MatchCharset(*it, Charset24)) { state = 800; ++it; continue; }
                return -1;
            case 800:
                if (MatchCharset(*it, Charset21)) { state = 801; ++it; continue; }
                return -1;
            case 801:
                if (MatchCharset(*it, Charset11)) { state = 802; ++it; continue; }
                return -1;
            case 802:
                return 176;
            case 803:
                if (MatchCharset(*it, Charset22)) { state = 804; ++it; continue; }
                return -1;
            case 804:
                if (MatchCharset(*it, Charset28)) { state = 805; ++it; continue; }
                return -1;
            case 805:
                if (MatchCharset(*it, Charset18)) { state = 806; ++it; continue; }
                return -1;
            case 806:
                if (MatchCharset(*it, Charset33)) { state = 807; ++it; continue; }
                if (MatchCharset(*it, Charset34)) { state = 808; ++it; continue; }
                if (MatchCharset(*it, Charset35)) { state = 809; ++it; continue; }
                if (MatchCharset(*it, Charset29)) { state = 810; ++it; continue; }
                return -1;
            case 807:
                return 172;
            case 808:
                return 173;
            case 809:
                return 174;
            case 810:
                if (MatchCharset(*it, Charset17)) { state = 811; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 817; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 823; ++it; continue; }
                return -1;
            case 811:
                if (MatchCharset(*it, Charset11)) { state = 812; ++it; continue; }
                return -1;
            case 812:
                if (MatchCharset(*it, Charset10)) { state = 813; ++it; continue; }
                return -1;
            case 813:
                if (MatchCharset(*it, Charset15)) { state = 814; ++it; continue; }
                return -1;
            case 814:
                if (MatchCharset(*it, Charset24)) { state = 815; ++it; continue; }
                return -1;
            case 815:
                if (MatchCharset(*it, Charset17)) { state = 816; ++it; continue; }
                return -1;
            case 816:
                return 169;
            case 817:
                if (MatchCharset(*it, Charset11)) { state = 818; ++it; continue; }
                return -1;
            case 818:
                if (MatchCharset(*it, Charset31)) { state = 819; ++it; continue; }
                return -1;
            case 819:
                if (MatchCharset(*it, Charset11)) { state = 820; ++it; continue; }
                return -1;
            case 820:
                if (MatchCharset(*it, Charset21)) { state = 821; ++it; continue; }
                return -1;
            case 821:
                if (MatchCharset(*it, Charset11)) { state = 822; ++it; continue; }
                return -1;
            case 822:
                return 170;
            case 823:
                if (MatchCharset(*it, Charset11)) { state = 824; ++it; continue; }
                return -1;
            case 824:
                if (MatchCharset(*it, Charset7)) { state = 825; ++it; continue; }
                return -1;
            case 825:
                if (MatchCharset(*it, Charset30)) { state = 826; ++it; continue; }
                return -1;
            case 826:
                return 171;
            case 827:
                if (MatchCharset(*it, Charset5)) { state = 828; ++it; continue; }
                return -1;
            case 828:
                if (MatchCharset(*it, Charset9)) { state = 829; ++it; continue; }
                return -1;
            case 829:
                if (MatchCharset(*it, Charset14)) { state = 830; ++it; continue; }
                return -1;
            case 830:
                if (MatchCharset(*it, Charset28)) { state = 831; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 835; ++it; continue; }
                return -1;
            case 831:
                if (MatchCharset(*it, Charset23)) { state = 832; ++it; continue; }
                return -1;
            case 832:
                if (MatchCharset(*it, Charset15)) { state = 833; ++it; continue; }
                return -1;
            case 833:
                if (MatchCharset(*it, Charset9)) { state = 834; ++it; continue; }
                return -1;
            case 834:
                return 180;
            case 835:
                if (MatchCharset(*it, Charset9)) { state = 836; ++it; continue; }
                return -1;
            case 836:
                if (MatchCharset(*it, Charset29)) { state = 837; ++it; continue; }
                return 178;
            case 837:
                if (MatchCharset(*it, Charset22)) { state = 838; ++it; continue; }
                return -1;
            case 838:
                if (MatchCharset(*it, Charset14)) { state = 839; ++it; continue; }
                return -1;
            case 839:
                if (MatchCharset(*it, Charset28)) { state = 840; ++it; continue; }
                return -1;
            case 840:
                if (MatchCharset(*it, Charset9)) { state = 841; ++it; continue; }
                return -1;
            case 841:
                if (MatchCharset(*it, Charset30)) { state = 842; ++it; continue; }
                return -1;
            case 842:
                return 179;
            case 843:
                if (MatchCharset(*it, Charset24)) { state = 844; ++it; continue; }
                return -1;
            case 844:
                if (MatchCharset(*it, Charset7)) { state = 845; ++it; continue; }
                return -1;
            case 845:
                if (MatchCharset(*it, Charset21)) { state = 846; ++it; continue; }
                return -1;
            case 846:
                if (MatchCharset(*it, Charset21)) { state = 847; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 849; ++it; continue; }
                return -1;
            case 847:
                if (MatchCharset(*it, Charset5)) { state = 848; ++it; continue; }
                return -1;
            case 848:
                return 181;
            case 849:
                if (MatchCharset(*it, Charset11)) { state = 850; ++it; continue; }
                return -1;
            case 850:
                if (MatchCharset(*it, Charset21)) { state = 851; ++it; continue; }
                return -1;
            case 851:
                if (MatchCharset(*it, Charset17)) { state = 852; ++it; continue; }
                return -1;
            case 852:
                if (MatchCharset(*it, Charset7)) { state = 853; ++it; continue; }
                return -1;
            case 853:
                if (MatchCharset(*it, Charset22)) { state = 854; ++it; continue; }
                return -1;
            case 854:
                if (MatchCharset(*it, Charset23)) { state = 855; ++it; continue; }
                return -1;
            case 855:
                if (MatchCharset(*it, Charset11)) { state = 856; ++it; continue; }
                return -1;
            case 856:
                if (MatchCharset(*it, Charset21)) { state = 857; ++it; continue; }
                return -1;
            case 857:
                return 182;
            case 858:
                if (MatchCharset(*it, Charset15)) { state = 859; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 862; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 871; ++it; continue; }
                return -1;
            case 859:
                if (MatchCharset(*it, Charset18)) { state = 860; ++it; continue; }
                return -1;
            case 860:
                if (MatchCharset(*it, Charset13)) { state = 861; ++it; continue; }
                return -1;
            case 861:
                return 186;
            case 862:
                if (MatchCharset(*it, Charset7)) { state = 863; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 868; ++it; continue; }
                return -1;
            case 863:
                if (MatchCharset(*it, Charset13)) { state = 864; ++it; continue; }
                return -1;
            case 864:
                if (MatchCharset(*it, Charset11)) { state = 865; ++it; continue; }
                return -1;
            case 865:
                if (MatchCharset(*it, Charset18)) { state = 866; ++it; continue; }
                return -1;
            case 866:
                if (MatchCharset(*it, Charset23)) { state = 867; ++it; continue; }
                return -1;
            case 867:
                return 184;
            case 868:
                if (MatchCharset(*it, Charset15)) { state = 869; ++it; continue; }
                return -1;
            case 869:
                if (MatchCharset(*it, Charset9)) { state = 870; ++it; continue; }
                return -1;
            case 870:
                return 185;
            case 871:
                if (MatchCharset(*it, Charset9)) { state = 872; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 880; ++it; continue; }
                return -1;
            case 872:
                if (MatchCharset(*it, Charset30)) { state = 873; ++it; continue; }
                return -1;
            case 873:
                if (MatchCharset(*it, Charset29)) { state = 874; ++it; continue; }
                return -1;
            case 874:
                if (MatchCharset(*it, Charset8)) { state = 875; ++it; continue; }
                return -1;
            case 875:
                if (MatchCharset(*it, Charset16)) { state = 876; ++it; continue; }
                return -1;
            case 876:
                if (MatchCharset(*it, Charset7)) { state = 877; ++it; continue; }
                return -1;
            case 877:
                if (MatchCharset(*it, Charset22)) { state = 878; ++it; continue; }
                return -1;
            case 878:
                if (MatchCharset(*it, Charset23)) { state = 879; ++it; continue; }
                return -1;
            case 879:
                return 187;
            case 880:
                if (MatchCharset(*it, Charset17)) { state = 881; ++it; continue; }
                return -1;
            case 881:
                return 188;
            case 882:
                if (MatchCharset(*it, Charset11)) { state = 883; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 891; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 894; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 895; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 900; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 906; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 910; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 917; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 930; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 947; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 967; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 996; ++it; continue; }
                return -1;
            case 883:
                if (MatchCharset(*it, Charset25)) { state = 884; ++it; continue; }
                return -1;
            case 884:
                if (MatchCharset(*it, Charset11)) { state = 885; ++it; continue; }
                return -1;
            case 885:
                if (MatchCharset(*it, Charset21)) { state = 886; ++it; continue; }
                return -1;
            case 886:
                if (MatchCharset(*it, Charset19)) { state = 887; ++it; continue; }
                return -1;
            case 887:
                if (MatchCharset(*it, Charset15)) { state = 888; ++it; continue; }
                return -1;
            case 888:
                if (MatchCharset(*it, Charset19)) { state = 889; ++it; continue; }
                return -1;
            case 889:
                if (MatchCharset(*it, Charset11)) { state = 890; ++it; continue; }
                return -1;
            case 890:
                return 194;
            case 891:
                if (MatchCharset(*it, Charset15)) { state = 892; ++it; continue; }
                return -1;
            case 892:
                if (MatchCharset(*it, Charset23)) { state = 893; ++it; continue; }
                return -1;
            case 893:
                return 199;
            case 894:
                if (MatchCharset(*it, Charset6)) { state = 894; ++it; continue; }
                return 200;
            case 895:
                if (MatchCharset(*it, Charset24)) { state = 896; ++it; continue; }
                return -1;
            case 896:
                if (MatchCharset(*it, Charset15)) { state = 897; ++it; continue; }
                return -1;
            case 897:
                if (MatchCharset(*it, Charset21)) { state = 898; ++it; continue; }
                return -1;
            case 898:
                if (MatchCharset(*it, Charset11)) { state = 899; ++it; continue; }
                return -1;
            case 899:
                return 205;
            case 900:
                if (MatchCharset(*it, Charset9)) { state = 901; ++it; continue; }
                return -1;
            case 901:
                if (MatchCharset(*it, Charset21)) { state = 902; ++it; continue; }
                return -1;
            case 902:
                if (MatchCharset(*it, Charset28)) { state = 903; ++it; continue; }
                return -1;
            case 903:
                if (MatchCharset(*it, Charset16)) { state = 904; ++it; continue; }
                return -1;
            case 904:
                if (MatchCharset(*it, Charset16)) { state = 905; ++it; continue; }
                return -1;
            case 905:
                return 206;
            case 906:
                if (MatchCharset(*it, Charset28)) { state = 907; ++it; continue; }
                return -1;
            case 907:
                if (MatchCharset(*it, Charset21)) { state = 908; ++it; continue; }
                return -1;
            case 908:
                if (MatchCharset(*it, Charset10)) { state = 909; ++it; continue; }
                return -1;
            case 909:
                return 216;
            case 910:
                if (MatchCharset(*it, Charset13)) { state = 911; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 913; ++it; continue; }
                return -1;
            case 911:
                if (MatchCharset(*it, Charset11)) { state = 912; ++it; continue; }
                return -1;
            case 912:
                return 189;
            case 913:
                if (MatchCharset(*it, Charset16)) { state = 914; ++it; continue; }
                return -1;
            case 914:
                if (MatchCharset(*it, Charset28)) { state = 915; ++it; continue; }
                return -1;
            case 915:
                if (MatchCharset(*it, Charset21)) { state = 916; ++it; continue; }
                return -1;
            case 916:
                return 190;
            case 917:
                if (MatchCharset(*it, Charset14)) { state = 918; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 923; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 926; ++it; continue; }
                return -1;
            case 918:
                if (MatchCharset(*it, Charset28)) { state = 919; ++it; continue; }
                return -1;
            case 919:
                if (MatchCharset(*it, Charset16)) { state = 920; ++it; continue; }
                return -1;
            case 920:
                if (MatchCharset(*it, Charset7)) { state = 921; ++it; continue; }
                return -1;
            case 921:
                if (MatchCharset(*it, Charset21)) { state = 922; ++it; continue; }
                return -1;
            case 922:
                return 191;
            case 923:
                if (MatchCharset(*it, Charset24)) { state = 924; ++it; continue; }
                return -1;
            case 924:
                if (MatchCharset(*it, Charset23)) { state = 925; ++it; continue; }
                return -1;
            case 925:
                return 192;
            case 926:
                if (MatchCharset(*it, Charset28)) { state = 927; ++it; continue; }
                return -1;
            case 927:
                if (MatchCharset(*it, Charset16)) { state = 928; ++it; continue; }
                return -1;
            case 928:
                if (MatchCharset(*it, Charset16)) { state = 929; ++it; continue; }
                return -1;
            case 929:
                return 193;
            case 930:
                if (MatchCharset(*it, Charset15)) { state = 931; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 935; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 943; ++it; continue; }
                return -1;
            case 931:
                if (MatchCharset(*it, Charset11)) { state = 932; ++it; continue; }
                return -1;
            case 932:
                if (MatchCharset(*it, Charset16)) { state = 933; ++it; continue; }
                return -1;
            case 933:
                if (MatchCharset(*it, Charset10)) { state = 934; ++it; continue; }
                return -1;
            case 934:
                return 195;
            case 935:
                if (MatchCharset(*it, Charset7)) { state = 936; ++it; continue; }
                return -1;
            case 936:
                if (MatchCharset(*it, Charset19)) { state = 937; ++it; continue; }
                return -1;
            case 937:
                if (MatchCharset(*it, Charset17)) { state = 938; ++it; continue; }
                return -1;
            case 938:
                if (MatchCharset(*it, Charset11)) { state = 939; ++it; continue; }
                return -1;
            case 939:
                if (MatchCharset(*it, Charset23)) { state = 940; ++it; continue; }
                return -1;
            case 940:
                if (MatchCharset(*it, Charset7)) { state = 941; ++it; continue; }
                return -1;
            case 941:
                if (MatchCharset(*it, Charset16)) { state = 942; ++it; continue; }
                return -1;
            case 942:
                return 198;
            case 943:
                if (MatchCharset(*it, Charset21)) { state = 944; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 946; ++it; continue; }
                return -1;
            case 944:
                if (MatchCharset(*it, Charset23)) { state = 945; ++it; continue; }
                return -1;
            case 945:
                return 196;
            case 946:
                return 197;
            case 947:
                if (MatchCharset(*it, Charset7)) { state = 948; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 952; ++it; continue; }
                return -1;
            case 948:
                if (MatchCharset(*it, Charset21)) { state = 949; ++it; continue; }
                return -1;
            case 949:
                if (MatchCharset(*it, Charset30)) { state = 950; ++it; continue; }
                return -1;
            case 950:
                if (MatchCharset(*it, Charset22)) { state = 951; ++it; continue; }
                return -1;
            case 951:
                return 201;
            case 952:
                if (MatchCharset(*it, Charset7)) { state = 953; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 955; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 959; ++it; continue; }
                return -1;
            case 953:
                if (MatchCharset(*it, Charset21)) { state = 954; ++it; continue; }
                return -1;
            case 954:
                return 202;
            case 955:
                if (MatchCharset(*it, Charset15)) { state = 956; ++it; continue; }
                return -1;
            case 956:
                if (MatchCharset(*it, Charset7)) { state = 957; ++it; continue; }
                return -1;
            case 957:
                if (MatchCharset(*it, Charset16)) { state = 958; ++it; continue; }
                return -1;
            case 958:
                return 203;
            case 959:
                if (MatchCharset(*it, Charset16)) { state = 960; ++it; continue; }
                return -1;
            case 960:
                if (MatchCharset(*it, Charset17)) { state = 961; ++it; continue; }
                return -1;
            case 961:
                if (MatchCharset(*it, Charset7)) { state = 962; ++it; continue; }
                return -1;
            case 962:
                if (MatchCharset(*it, Charset22)) { state = 963; ++it; continue; }
                return -1;
            case 963:
                if (MatchCharset(*it, Charset23)) { state = 964; ++it; continue; }
                return -1;
            case 964:
                if (MatchCharset(*it, Charset11)) { state = 965; ++it; continue; }
                return -1;
            case 965:
                if (MatchCharset(*it, Charset21)) { state = 966; ++it; continue; }
                return -1;
            case 966:
                return 204;
            case 967:
                if (MatchCharset(*it, Charset11)) { state = 968; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 971; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 976; ++it; continue; }
                return -1;
            case 968:
                if (MatchCharset(*it, Charset7)) { state = 969; ++it; continue; }
                return -1;
            case 969:
                if (MatchCharset(*it, Charset16)) { state = 970; ++it; continue; }
                return -1;
            case 970:
                return 209;
            case 971:
                if (MatchCharset(*it, Charset12)) { state = 972; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 974; ++it; continue; }
                return -1;
            case 972:
                if (MatchCharset(*it, Charset12)) { state = 973; ++it; continue; }
                return -1;
            case 973:
                return 207;
            case 974:
                if (MatchCharset(*it, Charset10)) { state = 975; ++it; continue; }
                return -1;
            case 975:
                return 208;
            case 976:
                if (MatchCharset(*it, Charset18)) { state = 977; ++it; continue; }
                return -1;
            case 977:
                if (MatchCharset(*it, Charset11)) { state = 978; ++it; continue; }
                return -1;
            case 978:
                if (MatchCharset(*it, Charset29)) { state = 979; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 984; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 992; ++it; continue; }
                return 210;
            case 979:
                if (MatchCharset(*it, Charset22)) { state = 980; ++it; continue; }
                return -1;
            case 980:
                if (MatchCharset(*it, Charset30)) { state = 981; ++it; continue; }
                return -1;
            case 981:
                if (MatchCharset(*it, Charset15)) { state = 982; ++it; continue; }
                return -1;
            case 982:
                if (MatchCharset(*it, Charset18)) { state = 983; ++it; continue; }
                return -1;
            case 983:
                return 211;
            case 984:
                if (MatchCharset(*it, Charset28)) { state = 985; ++it; continue; }
                return -1;
            case 985:
                if (MatchCharset(*it, Charset21)) { state = 986; ++it; continue; }
                return -1;
            case 986:
                if (MatchCharset(*it, Charset21)) { state = 987; ++it; continue; }
                return -1;
            case 987:
                if (MatchCharset(*it, Charset15)) { state = 988; ++it; continue; }
                return -1;
            case 988:
                if (MatchCharset(*it, Charset10)) { state = 989; ++it; continue; }
                return -1;
            case 989:
                if (MatchCharset(*it, Charset28)) { state = 990; ++it; continue; }
                return -1;
            case 990:
                if (MatchCharset(*it, Charset21)) { state = 991; ++it; continue; }
                return -1;
            case 991:
                return 212;
            case 992:
                if (MatchCharset(*it, Charset28)) { state = 993; ++it; continue; }
                return -1;
            case 993:
                if (MatchCharset(*it, Charset28)) { state = 994; ++it; continue; }
                return -1;
            case 994:
                if (MatchCharset(*it, Charset17)) { state = 995; ++it; continue; }
                return -1;
            case 995:
                return 213;
            case 996:
                if (MatchCharset(*it, Charset15)) { state = 997; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 1003; ++it; continue; }
                return -1;
            case 997:
                if (MatchCharset(*it, Charset9)) { state = 998; ++it; continue; }
                return -1;
            case 998:
                if (MatchCharset(*it, Charset15)) { state = 999; ++it; continue; }
                return -1;
            case 999:
                if (MatchCharset(*it, Charset10)) { state = 1000; ++it; continue; }
                return -1;
            case 1000:
                if (MatchCharset(*it, Charset7)) { state = 1001; ++it; continue; }
                return -1;
            case 1001:
                if (MatchCharset(*it, Charset16)) { state = 1002; ++it; continue; }
                return -1;
            case 1002:
                return 214;
            case 1003:
                if (MatchCharset(*it, Charset17)) { state = 1004; ++it; continue; }
                return -1;
            case 1004:
                if (MatchCharset(*it, Charset28)) { state = 1005; ++it; continue; }
                return -1;
            case 1005:
                if (MatchCharset(*it, Charset18)) { state = 1006; ++it; continue; }
                return -1;
            case 1006:
                return 215;
            case 1007:
                if (MatchCharset(*it, Charset11)) { state = 1008; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 1014; ++it; continue; }
                if (MatchCharset(*it, Charset28)) { state = 1019; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 1029; ++it; continue; }
                return -1;
            case 1008:
                if (MatchCharset(*it, Charset7)) { state = 1009; ++it; continue; }
                return -1;
            case 1009:
                if (MatchCharset(*it, Charset9)) { state = 1010; ++it; continue; }
                return -1;
            case 1010:
                if (MatchCharset(*it, Charset14)) { state = 1011; ++it; continue; }
                return -1;
            case 1011:
                if (MatchCharset(*it, Charset11)) { state = 1012; ++it; continue; }
                return -1;
            case 1012:
                if (MatchCharset(*it, Charset21)) { state = 1013; ++it; continue; }
                return -1;
            case 1013:
                return 217;
            case 1014:
                if (MatchCharset(*it, Charset18)) { state = 1015; ++it; continue; }
                return -1;
            case 1015:
                if (MatchCharset(*it, Charset30)) { state = 1016; ++it; continue; }
                return -1;
            case 1016:
                if (MatchCharset(*it, Charset11)) { state = 1017; ++it; continue; }
                return -1;
            case 1017:
                if (MatchCharset(*it, Charset21)) { state = 1018; ++it; continue; }
                return -1;
            case 1018:
                return 218;
            case 1019:
                if (MatchCharset(*it, Charset4)) { state = 1020; ++it; continue; }
                return -1;
            case 1020:
                if (MatchCharset(*it, Charset15)) { state = 1021; ++it; continue; }
                return -1;
            case 1021:
                if (MatchCharset(*it, Charset9)) { state = 1022; ++it; continue; }
                return -1;
            case 1022:
                if (MatchCharset(*it, Charset29)) { state = 1023; ++it; continue; }
                return -1;
            case 1023:
                if (MatchCharset(*it, Charset9)) { state = 1024; ++it; continue; }
                return -1;
            case 1024:
                if (MatchCharset(*it, Charset16)) { state = 1025; ++it; continue; }
                return -1;
            case 1025:
                if (MatchCharset(*it, Charset28)) { state = 1026; ++it; continue; }
                return -1;
            case 1026:
                if (MatchCharset(*it, Charset24)) { state = 1027; ++it; continue; }
                return -1;
            case 1027:
                if (MatchCharset(*it, Charset10)) { state = 1028; ++it; continue; }
                return -1;
            case 1028:
                return 219;
            case 1029:
                if (MatchCharset(*it, Charset7)) { state = 1030; ++it; continue; }
                return -1;
            case 1030:
                if (MatchCharset(*it, Charset9)) { state = 1031; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 1035; ++it; continue; }
                return -1;
            case 1031:
                if (MatchCharset(*it, Charset30)) { state = 1032; ++it; continue; }
                return -1;
            case 1032:
                if (MatchCharset(*it, Charset11)) { state = 1033; ++it; continue; }
                return -1;
            case 1033:
                if (MatchCharset(*it, Charset21)) { state = 1034; ++it; continue; }
                return -1;
            case 1034:
                return 220;
            case 1035:
                if (MatchCharset(*it, Charset11)) { state = 1036; ++it; continue; }
                return -1;
            case 1036:
                if (MatchCharset(*it, Charset21)) { state = 1037; ++it; continue; }
                return -1;
            case 1037:
                return 221;
            case 1038:
                if (MatchCharset(*it, Charset18)) { state = 1039; ++it; continue; }
                return -1;
            case 1039:
                if (MatchCharset(*it, Charset9)) { state = 1040; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 1043; ++it; continue; }
                return -1;
            case 1040:
                if (MatchCharset(*it, Charset28)) { state = 1041; ++it; continue; }
                return -1;
            case 1041:
                if (MatchCharset(*it, Charset18)) { state = 1042; ++it; continue; }
                return -1;
            case 1042:
                return 223;
            case 1043:
                if (MatchCharset(*it, Charset11)) { state = 1044; ++it; continue; }
                return -1;
            case 1044:
                if (MatchCharset(*it, Charset21)) { state = 1045; ++it; continue; }
                return -1;
            case 1045:
                if (MatchCharset(*it, Charset25)) { state = 1046; ++it; continue; }
                return -1;
            case 1046:
                if (MatchCharset(*it, Charset7)) { state = 1047; ++it; continue; }
                return -1;
            case 1047:
                if (MatchCharset(*it, Charset23)) { state = 1048; ++it; continue; }
                return -1;
            case 1048:
                if (MatchCharset(*it, Charset11)) { state = 1049; ++it; continue; }
                return -1;
            case 1049:
                if (MatchCharset(*it, Charset21)) { state = 1050; ++it; continue; }
                return -1;
            case 1050:
                return 224;
            case 1051:
                if (MatchCharset(*it, Charset7)) { state = 1052; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 1064; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 1083; ++it; continue; }
                return -1;
            case 1052:
                if (MatchCharset(*it, Charset18)) { state = 1053; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1055; ++it; continue; }
                return -1;
            case 1053:
                if (MatchCharset(*it, Charset10)) { state = 1054; ++it; continue; }
                return -1;
            case 1054:
                return 225;
            case 1055:
                if (MatchCharset(*it, Charset11)) { state = 1056; ++it; continue; }
                return -1;
            case 1056:
                if (MatchCharset(*it, Charset21)) { state = 1057; ++it; continue; }
                return -1;
            case 1057:
                if (MatchCharset(*it, Charset17)) { state = 1058; ++it; continue; }
                return 226;
            case 1058:
                if (MatchCharset(*it, Charset7)) { state = 1059; ++it; continue; }
                return -1;
            case 1059:
                if (MatchCharset(*it, Charset22)) { state = 1060; ++it; continue; }
                return -1;
            case 1060:
                if (MatchCharset(*it, Charset23)) { state = 1061; ++it; continue; }
                return -1;
            case 1061:
                if (MatchCharset(*it, Charset11)) { state = 1062; ++it; continue; }
                return -1;
            case 1062:
                if (MatchCharset(*it, Charset21)) { state = 1063; ++it; continue; }
                return -1;
            case 1063:
                return 227;
            case 1064:
                if (MatchCharset(*it, Charset7)) { state = 1065; ++it; continue; }
                return -1;
            case 1065:
                if (MatchCharset(*it, Charset30)) { state = 1066; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 1067; ++it; continue; }
                return -1;
            case 1066:
                return 228;
            case 1067:
                if (MatchCharset(*it, Charset28)) { state = 1068; ++it; continue; }
                return -1;
            case 1068:
                if (MatchCharset(*it, Charset18)) { state = 1069; ++it; continue; }
                return -1;
            case 1069:
                if (MatchCharset(*it, Charset33)) { state = 1070; ++it; continue; }
                if (MatchCharset(*it, Charset34)) { state = 1074; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 1075; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1082; ++it; continue; }
                return 229;
            case 1070:
                if (MatchCharset(*it, Charset28)) { state = 1071; ++it; continue; }
                return -1;
            case 1071:
                if (MatchCharset(*it, Charset21)) { state = 1072; ++it; continue; }
                return -1;
            case 1072:
                if (MatchCharset(*it, Charset34)) { state = 1073; ++it; continue; }
                return -1;
            case 1073:
                return 230;
            case 1074:
                return 231;
            case 1075:
                if (MatchCharset(*it, Charset17)) { state = 1076; ++it; continue; }
                return -1;
            case 1076:
                if (MatchCharset(*it, Charset7)) { state = 1077; ++it; continue; }
                return -1;
            case 1077:
                if (MatchCharset(*it, Charset22)) { state = 1078; ++it; continue; }
                return -1;
            case 1078:
                if (MatchCharset(*it, Charset23)) { state = 1079; ++it; continue; }
                return -1;
            case 1079:
                if (MatchCharset(*it, Charset11)) { state = 1080; ++it; continue; }
                return -1;
            case 1080:
                if (MatchCharset(*it, Charset21)) { state = 1081; ++it; continue; }
                return -1;
            case 1081:
                return 232;
            case 1082:
                return 233;
            case 1083:
                if (MatchCharset(*it, Charset17)) { state = 1084; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 1086; ++it; continue; }
                return -1;
            case 1084:
                if (MatchCharset(*it, Charset19)) { state = 1085; ++it; continue; }
                return -1;
            case 1085:
                return 234;
            case 1086:
                if (MatchCharset(*it, Charset10)) { state = 1087; ++it; continue; }
                return -1;
            case 1087:
                if (MatchCharset(*it, Charset17)) { state = 1088; ++it; continue; }
                return -1;
            case 1088:
                if (MatchCharset(*it, Charset7)) { state = 1089; ++it; continue; }
                return -1;
            case 1089:
                if (MatchCharset(*it, Charset22)) { state = 1090; ++it; continue; }
                return -1;
            case 1090:
                if (MatchCharset(*it, Charset23)) { state = 1091; ++it; continue; }
                return -1;
            case 1091:
                if (MatchCharset(*it, Charset11)) { state = 1092; ++it; continue; }
                return -1;
            case 1092:
                if (MatchCharset(*it, Charset21)) { state = 1093; ++it; continue; }
                return -1;
            case 1093:
                return 235;
            default:
                return -1;
            }
        }

        // TODO: EOF?
        return -1;
    }
}
