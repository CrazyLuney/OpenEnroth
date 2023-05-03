//
// THIS FILE IS GENERATED
//
#include "SymbolMatcher.hpp"

namespace SymbolMatcher::DFA
{
    static constexpr inline char Charset0[6] = { 9,10,11,12,13,32 };
    static constexpr inline char Charset1[1] = { 44 };
    static constexpr inline char Charset2[2] = { 74,106 };
    static constexpr inline char Charset3[1] = { 43 };
    static constexpr inline char Charset4[1] = { 34 };
    static constexpr inline char Charset5[2] = { 88,120 };
    static constexpr inline char Charset6[2] = { 89,121 };
    static constexpr inline char Charset7[10] = { 48,49,50,51,52,53,54,55,56,57 };
    static constexpr inline char Charset8[2] = { 65,97 };
    static constexpr inline char Charset9[2] = { 66,98 };
    static constexpr inline char Charset10[2] = { 67,99 };
    static constexpr inline char Charset11[2] = { 68,100 };
    static constexpr inline char Charset12[2] = { 69,101 };
    static constexpr inline char Charset13[2] = { 70,102 };
    static constexpr inline char Charset14[2] = { 71,103 };
    static constexpr inline char Charset15[2] = { 72,104 };
    static constexpr inline char Charset16[2] = { 73,105 };
    static constexpr inline char Charset17[2] = { 76,108 };
    static constexpr inline char Charset18[2] = { 77,109 };
    static constexpr inline char Charset19[2] = { 78,110 };
    static constexpr inline char Charset20[2] = { 79,111 };
    static constexpr inline char Charset21[2] = { 80,112 };
    static constexpr inline char Charset22[2] = { 81,113 };
    static constexpr inline char Charset23[2] = { 82,114 };
    static constexpr inline char Charset24[2] = { 83,115 };
    static constexpr inline char Charset25[2] = { 84,116 };
    static constexpr inline char Charset26[2] = { 85,117 };
    static constexpr inline char Charset27[2] = { 87,119 };
    static constexpr inline char Charset28[1] = { 45 };
    static constexpr inline char Charset29[1] = { 37 };
    static constexpr inline char Charset30[1] = { 32 };
    static constexpr inline char Charset31[2] = { 86,118 };
    static constexpr inline char Charset32[2] = { 75,107 };
    static constexpr inline char Charset33[1] = { 95 };
    static constexpr inline char Charset34[2] = { 90,122 };
    static constexpr inline char Charset35[1] = { 49 };
    static constexpr inline char Charset36[1] = { 50 };
    static constexpr inline char Charset37[1] = { 51 };
    static constexpr inline char Charset38[1] = { 48 };

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
                if (MatchCharset(*it, Charset3)) { state = 7; ++it; continue; }
                if (MatchCharset(*it, Charset4)) { state = 8; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 9; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 12; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 13; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 25; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 153; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 226; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 322; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 443; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 495; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 542; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 587; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 681; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 721; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 788; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 876; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 896; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 912; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 1051; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1066; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 1090; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1249; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 1321; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 1334; ++it; continue; }
                return -1;
            case 1:
                if (MatchCharset(*it, Charset0)) { state = 1; ++it; continue; }
                return 2;
            case 2:
                return 62;
            case 3:
                if (MatchCharset(*it, Charset8)) { state = 4; ++it; continue; }
                return -1;
            case 4:
                if (MatchCharset(*it, Charset16)) { state = 5; ++it; continue; }
                return -1;
            case 5:
                if (MatchCharset(*it, Charset17)) { state = 6; ++it; continue; }
                return -1;
            case 6:
                return 153;
            case 7:
                return 201;
            case 8:
                return 218;
            case 9:
                if (MatchCharset(*it, Charset0)) { state = 10; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 11; ++it; continue; }
                return -1;
            case 10:
                if (MatchCharset(*it, Charset0)) { state = 10; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 11; ++it; continue; }
                return -1;
            case 11:
                if (MatchCharset(*it, Charset7)) { state = 11; ++it; continue; }
                return 290;
            case 12:
                return 291;
            case 13:
                if (MatchCharset(*it, Charset28)) { state = 14; ++it; continue; }
                if (MatchCharset(*it, Charset1)) { state = 16; ++it; continue; }
                if (MatchCharset(*it, Charset29)) { state = 18; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 13; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 19; ++it; continue; }
                return 152;
            case 14:
                if (MatchCharset(*it, Charset7)) { state = 15; ++it; continue; }
                return -1;
            case 15:
                if (MatchCharset(*it, Charset7)) { state = 15; ++it; continue; }
                return 97;
            case 16:
                if (MatchCharset(*it, Charset7)) { state = 17; ++it; continue; }
                return -1;
            case 17:
                if (MatchCharset(*it, Charset7)) { state = 17; ++it; continue; }
                return 113;
            case 18:
                return 272;
            case 19:
                if (MatchCharset(*it, Charset7)) { state = 20; ++it; continue; }
                return -1;
            case 20:
                if (MatchCharset(*it, Charset17)) { state = 21; ++it; continue; }
                if (MatchCharset(*it, Charset3)) { state = 23; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 20; ++it; continue; }
                return 72;
            case 21:
                if (MatchCharset(*it, Charset7)) { state = 22; ++it; continue; }
                return -1;
            case 22:
                if (MatchCharset(*it, Charset7)) { state = 22; ++it; continue; }
                return 74;
            case 23:
                if (MatchCharset(*it, Charset7)) { state = 24; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 21; ++it; continue; }
                return -1;
            case 24:
                if (MatchCharset(*it, Charset7)) { state = 24; ++it; continue; }
                return 73;
            case 25:
                if (MatchCharset(*it, Charset13)) { state = 26; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 31; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 36; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 41; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 50; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 52; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 66; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 73; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 81; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 106; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 123; ++it; continue; }
                return 3;
            case 26:
                if (MatchCharset(*it, Charset23)) { state = 27; ++it; continue; }
                return -1;
            case 27:
                if (MatchCharset(*it, Charset8)) { state = 28; ++it; continue; }
                return -1;
            case 28:
                if (MatchCharset(*it, Charset16)) { state = 29; ++it; continue; }
                return -1;
            case 29:
                if (MatchCharset(*it, Charset11)) { state = 30; ++it; continue; }
                return -1;
            case 30:
                return 6;
            case 31:
                if (MatchCharset(*it, Charset26)) { state = 32; ++it; continue; }
                return -1;
            case 32:
                if (MatchCharset(*it, Charset17)) { state = 33; ++it; continue; }
                return -1;
            case 33:
                if (MatchCharset(*it, Charset12)) { state = 34; ++it; continue; }
                return -1;
            case 34:
                if (MatchCharset(*it, Charset25)) { state = 35; ++it; continue; }
                return -1;
            case 35:
                return 14;
            case 36:
                if (MatchCharset(*it, Charset17)) { state = 37; ++it; continue; }
                return -1;
            case 37:
                if (MatchCharset(*it, Charset12)) { state = 38; ++it; continue; }
                return -1;
            case 38:
                if (MatchCharset(*it, Charset12)) { state = 39; ++it; continue; }
                return -1;
            case 39:
                if (MatchCharset(*it, Charset21)) { state = 40; ++it; continue; }
                return -1;
            case 40:
                return 24;
            case 41:
                if (MatchCharset(*it, Charset11)) { state = 42; ++it; continue; }
                return -1;
            case 42:
                if (MatchCharset(*it, Charset16)) { state = 43; ++it; continue; }
                return -1;
            case 43:
                if (MatchCharset(*it, Charset25)) { state = 44; ++it; continue; }
                return -1;
            case 44:
                if (MatchCharset(*it, Charset20)) { state = 45; ++it; continue; }
                return -1;
            case 45:
                if (MatchCharset(*it, Charset23)) { state = 46; ++it; continue; }
                return -1;
            case 46:
                if (MatchCharset(*it, Charset16)) { state = 47; ++it; continue; }
                return -1;
            case 47:
                if (MatchCharset(*it, Charset26)) { state = 48; ++it; continue; }
                return -1;
            case 48:
                if (MatchCharset(*it, Charset18)) { state = 49; ++it; continue; }
                return -1;
            case 49:
                return 25;
            case 50:
                if (MatchCharset(*it, Charset12)) { state = 51; ++it; continue; }
                return -1;
            case 51:
                return 26;
            case 52:
                if (MatchCharset(*it, Charset16)) { state = 53; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 61; ++it; continue; }
                return -1;
            case 53:
                if (MatchCharset(*it, Charset11)) { state = 54; ++it; continue; }
                return -1;
            case 54:
                if (MatchCharset(*it, Charset30)) { state = 55; ++it; continue; }
                return -1;
            case 55:
                if (MatchCharset(*it, Charset9)) { state = 56; ++it; continue; }
                return -1;
            case 56:
                if (MatchCharset(*it, Charset26)) { state = 57; ++it; continue; }
                return -1;
            case 57:
                if (MatchCharset(*it, Charset23)) { state = 58; ++it; continue; }
                return -1;
            case 58:
                if (MatchCharset(*it, Charset24)) { state = 59; ++it; continue; }
                return -1;
            case 59:
                if (MatchCharset(*it, Charset25)) { state = 60; ++it; continue; }
                return -1;
            case 60:
                return 4;
            case 61:
                if (MatchCharset(*it, Charset17)) { state = 62; ++it; continue; }
                return -1;
            case 62:
                if (MatchCharset(*it, Charset6)) { state = 63; ++it; continue; }
                return -1;
            case 63:
                if (MatchCharset(*it, Charset25)) { state = 64; ++it; continue; }
                return -1;
            case 64:
                if (MatchCharset(*it, Charset12)) { state = 65; ++it; continue; }
                return -1;
            case 65:
                return 5;
            case 66:
                if (MatchCharset(*it, Charset12)) { state = 67; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 68; ++it; continue; }
                return -1;
            case 67:
                return 7;
            case 68:
                if (MatchCharset(*it, Charset23)) { state = 69; ++it; continue; }
                return -1;
            case 69:
                if (MatchCharset(*it, Charset12)) { state = 70; ++it; continue; }
                return -1;
            case 70:
                if (MatchCharset(*it, Charset24)) { state = 71; ++it; continue; }
                return -1;
            case 71:
                if (MatchCharset(*it, Charset24)) { state = 72; ++it; continue; }
                return -1;
            case 72:
                return 8;
            case 73:
                if (MatchCharset(*it, Charset23)) { state = 74; ++it; continue; }
                return -1;
            case 74:
                if (MatchCharset(*it, Charset30)) { state = 75; ++it; continue; }
                return 9;
            case 75:
                if (MatchCharset(*it, Charset14)) { state = 76; ++it; continue; }
                return -1;
            case 76:
                if (MatchCharset(*it, Charset26)) { state = 77; ++it; continue; }
                return -1;
            case 77:
                if (MatchCharset(*it, Charset16)) { state = 78; ++it; continue; }
                return -1;
            case 78:
                if (MatchCharset(*it, Charset17)) { state = 79; ++it; continue; }
                return -1;
            case 79:
                if (MatchCharset(*it, Charset11)) { state = 80; ++it; continue; }
                return -1;
            case 80:
                return 10;
            case 81:
                if (MatchCharset(*it, Charset10)) { state = 82; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 89; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 103; ++it; continue; }
                return -1;
            case 82:
                if (MatchCharset(*it, Charset15)) { state = 83; ++it; continue; }
                return -1;
            case 83:
                if (MatchCharset(*it, Charset12)) { state = 84; ++it; continue; }
                return -1;
            case 84:
                if (MatchCharset(*it, Charset18)) { state = 85; ++it; continue; }
                return -1;
            case 85:
                if (MatchCharset(*it, Charset16)) { state = 86; ++it; continue; }
                return -1;
            case 86:
                if (MatchCharset(*it, Charset24)) { state = 87; ++it; continue; }
                return -1;
            case 87:
                if (MatchCharset(*it, Charset25)) { state = 88; ++it; continue; }
                return -1;
            case 88:
                return 11;
            case 89:
                if (MatchCharset(*it, Charset10)) { state = 90; ++it; continue; }
                return -1;
            case 90:
                if (MatchCharset(*it, Charset12)) { state = 91; ++it; continue; }
                return -1;
            case 91:
                if (MatchCharset(*it, Charset30)) { state = 92; ++it; continue; }
                return -1;
            case 92:
                if (MatchCharset(*it, Charset15)) { state = 93; ++it; continue; }
                return -1;
            case 93:
                if (MatchCharset(*it, Charset8)) { state = 94; ++it; continue; }
                return -1;
            case 94:
                if (MatchCharset(*it, Charset23)) { state = 95; ++it; continue; }
                return -1;
            case 95:
                if (MatchCharset(*it, Charset14)) { state = 96; ++it; continue; }
                return -1;
            case 96:
                if (MatchCharset(*it, Charset23)) { state = 97; ++it; continue; }
                return -1;
            case 97:
                if (MatchCharset(*it, Charset12)) { state = 98; ++it; continue; }
                return -1;
            case 98:
                if (MatchCharset(*it, Charset8)) { state = 99; ++it; continue; }
                return -1;
            case 99:
                if (MatchCharset(*it, Charset31)) { state = 100; ++it; continue; }
                return -1;
            case 100:
                if (MatchCharset(*it, Charset12)) { state = 101; ++it; continue; }
                return -1;
            case 101:
                if (MatchCharset(*it, Charset24)) { state = 102; ++it; continue; }
                return -1;
            case 102:
                return 12;
            case 103:
                if (MatchCharset(*it, Charset12)) { state = 104; ++it; continue; }
                return -1;
            case 104:
                if (MatchCharset(*it, Charset6)) { state = 105; ++it; continue; }
                return -1;
            case 105:
                return 13;
            case 106:
                if (MatchCharset(*it, Charset20)) { state = 107; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 115; ++it; continue; }
                return -1;
            case 107:
                if (MatchCharset(*it, Charset25)) { state = 108; ++it; continue; }
                return -1;
            case 108:
                if (MatchCharset(*it, Charset15)) { state = 109; ++it; continue; }
                return -1;
            case 109:
                if (MatchCharset(*it, Charset12)) { state = 110; ++it; continue; }
                return -1;
            case 110:
                if (MatchCharset(*it, Charset10)) { state = 111; ++it; continue; }
                return -1;
            case 111:
                if (MatchCharset(*it, Charset8)) { state = 112; ++it; continue; }
                return -1;
            case 112:
                if (MatchCharset(*it, Charset23)) { state = 113; ++it; continue; }
                return -1;
            case 113:
                if (MatchCharset(*it, Charset6)) { state = 114; ++it; continue; }
                return -1;
            case 114:
                return 15;
            case 115:
                if (MatchCharset(*it, Charset23)) { state = 116; ++it; continue; }
                return -1;
            case 116:
                if (MatchCharset(*it, Charset12)) { state = 117; ++it; continue; }
                return -1;
            case 117:
                if (MatchCharset(*it, Charset19)) { state = 118; ++it; continue; }
                return -1;
            case 118:
                if (MatchCharset(*it, Charset25)) { state = 119; ++it; continue; }
                return -1;
            case 119:
                if (MatchCharset(*it, Charset16)) { state = 120; ++it; continue; }
                return -1;
            case 120:
                if (MatchCharset(*it, Charset10)) { state = 121; ++it; continue; }
                return -1;
            case 121:
                if (MatchCharset(*it, Charset12)) { state = 122; ++it; continue; }
                return -1;
            case 122:
                return 16;
            case 123:
                if (MatchCharset(*it, Charset12)) { state = 124; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 127; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 130; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 136; ++it; continue; }
                return -1;
            case 124:
                if (MatchCharset(*it, Charset19)) { state = 125; ++it; continue; }
                return -1;
            case 125:
                if (MatchCharset(*it, Charset8)) { state = 126; ++it; continue; }
                return -1;
            case 126:
                return 17;
            case 127:
                if (MatchCharset(*it, Charset20)) { state = 128; ++it; continue; }
                return -1;
            case 128:
                if (MatchCharset(*it, Charset27)) { state = 129; ++it; continue; }
                return -1;
            case 129:
                return 22;
            case 130:
                if (MatchCharset(*it, Charset16)) { state = 131; ++it; continue; }
                return -1;
            case 131:
                if (MatchCharset(*it, Charset13)) { state = 132; ++it; continue; }
                return -1;
            case 132:
                if (MatchCharset(*it, Charset8)) { state = 133; ++it; continue; }
                return -1;
            case 133:
                if (MatchCharset(*it, Charset10)) { state = 134; ++it; continue; }
                return -1;
            case 134:
                if (MatchCharset(*it, Charset25)) { state = 135; ++it; continue; }
                return -1;
            case 135:
                return 23;
            case 136:
                if (MatchCharset(*it, Charset24)) { state = 137; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 144; ++it; continue; }
                return -1;
            case 137:
                if (MatchCharset(*it, Charset18)) { state = 138; ++it; continue; }
                return -1;
            case 138:
                if (MatchCharset(*it, Charset8)) { state = 139; ++it; continue; }
                return -1;
            case 139:
                if (MatchCharset(*it, Charset24)) { state = 140; ++it; continue; }
                return -1;
            case 140:
                if (MatchCharset(*it, Charset25)) { state = 141; ++it; continue; }
                return -1;
            case 141:
                if (MatchCharset(*it, Charset12)) { state = 142; ++it; continue; }
                return -1;
            case 142:
                if (MatchCharset(*it, Charset23)) { state = 143; ++it; continue; }
                return -1;
            case 143:
                return 21;
            case 144:
                if (MatchCharset(*it, Charset23)) { state = 145; ++it; continue; }
                return -1;
            case 145:
                if (MatchCharset(*it, Charset30)) { state = 146; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 151; ++it; continue; }
                return 18;
            case 146:
                if (MatchCharset(*it, Charset24)) { state = 147; ++it; continue; }
                return -1;
            case 147:
                if (MatchCharset(*it, Charset15)) { state = 148; ++it; continue; }
                return -1;
            case 148:
                if (MatchCharset(*it, Charset20)) { state = 149; ++it; continue; }
                return -1;
            case 149:
                if (MatchCharset(*it, Charset21)) { state = 150; ++it; continue; }
                return -1;
            case 150:
                return 19;
            case 151:
                if (MatchCharset(*it, Charset23)) { state = 152; ++it; continue; }
                return -1;
            case 152:
                return 20;
            case 153:
                if (MatchCharset(*it, Charset12)) { state = 154; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 157; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 163; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 176; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 188; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 209; ++it; continue; }
                return 27;
            case 154:
                if (MatchCharset(*it, Charset17)) { state = 155; ++it; continue; }
                return -1;
            case 155:
                if (MatchCharset(*it, Charset25)) { state = 156; ++it; continue; }
                return -1;
            case 156:
                return 32;
            case 157:
                if (MatchCharset(*it, Charset23)) { state = 158; ++it; continue; }
                return -1;
            case 158:
                if (MatchCharset(*it, Charset14)) { state = 159; ++it; continue; }
                return -1;
            case 159:
                if (MatchCharset(*it, Charset17)) { state = 160; ++it; continue; }
                return -1;
            case 160:
                if (MatchCharset(*it, Charset8)) { state = 161; ++it; continue; }
                return -1;
            case 161:
                if (MatchCharset(*it, Charset23)) { state = 162; ++it; continue; }
                return -1;
            case 162:
                return 46;
            case 163:
                if (MatchCharset(*it, Charset23)) { state = 164; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 166; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 172; ++it; continue; }
                return -1;
            case 164:
                if (MatchCharset(*it, Charset11)) { state = 165; ++it; continue; }
                return -1;
            case 165:
                return 30;
            case 166:
                if (MatchCharset(*it, Charset15)) { state = 167; ++it; continue; }
                return -1;
            case 167:
                if (MatchCharset(*it, Charset23)) { state = 168; ++it; continue; }
                return -1;
            case 168:
                if (MatchCharset(*it, Charset20)) { state = 169; ++it; continue; }
                return -1;
            case 169:
                if (MatchCharset(*it, Charset20)) { state = 170; ++it; continue; }
                return -1;
            case 170:
                if (MatchCharset(*it, Charset18)) { state = 171; ++it; continue; }
                return -1;
            case 171:
                return 31;
            case 172:
                if (MatchCharset(*it, Charset32)) { state = 173; ++it; continue; }
                return -1;
            case 173:
                if (MatchCharset(*it, Charset12)) { state = 174; ++it; continue; }
                return 28;
            case 174:
                if (MatchCharset(*it, Charset23)) { state = 175; ++it; continue; }
                return -1;
            case 175:
                return 29;
            case 176:
                if (MatchCharset(*it, Charset12)) { state = 177; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 180; ++it; continue; }
                return -1;
            case 177:
                if (MatchCharset(*it, Charset24)) { state = 178; ++it; continue; }
                return -1;
            case 178:
                if (MatchCharset(*it, Charset24)) { state = 179; ++it; continue; }
                return -1;
            case 179:
                return 35;
            case 180:
                if (MatchCharset(*it, Charset11)) { state = 181; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 184; ++it; continue; }
                return -1;
            case 181:
                if (MatchCharset(*it, Charset12)) { state = 182; ++it; continue; }
                return -1;
            case 182:
                if (MatchCharset(*it, Charset24)) { state = 183; ++it; continue; }
                return -1;
            case 183:
                return 33;
            case 184:
                if (MatchCharset(*it, Charset25)) { state = 185; ++it; continue; }
                return -1;
            case 185:
                if (MatchCharset(*it, Charset12)) { state = 186; ++it; continue; }
                return -1;
            case 186:
                if (MatchCharset(*it, Charset23)) { state = 187; ++it; continue; }
                return -1;
            case 187:
                return 34;
            case 188:
                if (MatchCharset(*it, Charset8)) { state = 189; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 192; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 196; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 197; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 205; ++it; continue; }
                return -1;
            case 189:
                if (MatchCharset(*it, Charset25)) { state = 190; ++it; continue; }
                return -1;
            case 190:
                if (MatchCharset(*it, Charset24)) { state = 191; ++it; continue; }
                return -1;
            case 191:
                return 36;
            case 192:
                if (MatchCharset(*it, Charset25)) { state = 193; ++it; continue; }
                return -1;
            case 193:
                if (MatchCharset(*it, Charset17)) { state = 194; ++it; continue; }
                return -1;
            case 194:
                if (MatchCharset(*it, Charset12)) { state = 195; ++it; continue; }
                return -1;
            case 195:
                return 41;
            case 196:
                return 42;
            case 197:
                if (MatchCharset(*it, Charset6)) { state = 198; ++it; continue; }
                return -1;
            case 198:
                if (MatchCharset(*it, Charset30)) { state = 199; ++it; continue; }
                return 37;
            case 199:
                if (MatchCharset(*it, Charset14)) { state = 200; ++it; continue; }
                return -1;
            case 200:
                if (MatchCharset(*it, Charset26)) { state = 201; ++it; continue; }
                return -1;
            case 201:
                if (MatchCharset(*it, Charset16)) { state = 202; ++it; continue; }
                return -1;
            case 202:
                if (MatchCharset(*it, Charset17)) { state = 203; ++it; continue; }
                return -1;
            case 203:
                if (MatchCharset(*it, Charset11)) { state = 204; ++it; continue; }
                return -1;
            case 204:
                return 38;
            case 205:
                if (MatchCharset(*it, Charset32)) { state = 206; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 207; ++it; continue; }
                return -1;
            case 206:
                return 39;
            case 207:
                if (MatchCharset(*it, Charset24)) { state = 208; ++it; continue; }
                return -1;
            case 208:
                return 40;
            case 209:
                if (MatchCharset(*it, Charset32)) { state = 210; ++it; continue; }
                return -1;
            case 210:
                if (MatchCharset(*it, Charset8)) { state = 211; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 216; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 220; ++it; continue; }
                return -1;
            case 211:
                if (MatchCharset(*it, Charset23)) { state = 212; ++it; continue; }
                return -1;
            case 212:
                if (MatchCharset(*it, Charset18)) { state = 213; ++it; continue; }
                return -1;
            case 213:
                if (MatchCharset(*it, Charset20)) { state = 214; ++it; continue; }
                return -1;
            case 214:
                if (MatchCharset(*it, Charset23)) { state = 215; ++it; continue; }
                return -1;
            case 215:
                return 43;
            case 216:
                if (MatchCharset(*it, Charset25)) { state = 217; ++it; continue; }
                return -1;
            case 217:
                if (MatchCharset(*it, Charset12)) { state = 218; ++it; continue; }
                return -1;
            case 218:
                if (MatchCharset(*it, Charset18)) { state = 219; ++it; continue; }
                return -1;
            case 219:
                return 44;
            case 220:
                if (MatchCharset(*it, Charset12)) { state = 221; ++it; continue; }
                return -1;
            case 221:
                if (MatchCharset(*it, Charset8)) { state = 222; ++it; continue; }
                return -1;
            case 222:
                if (MatchCharset(*it, Charset21)) { state = 223; ++it; continue; }
                return -1;
            case 223:
                if (MatchCharset(*it, Charset20)) { state = 224; ++it; continue; }
                return -1;
            case 224:
                if (MatchCharset(*it, Charset19)) { state = 225; ++it; continue; }
                return -1;
            case 225:
                return 45;
            case 226:
                if (MatchCharset(*it, Charset16)) { state = 227; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 230; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 234; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 281; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 302; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 308; ++it; continue; }
                return 47;
            case 227:
                if (MatchCharset(*it, Charset25)) { state = 228; ++it; continue; }
                return -1;
            case 228:
                if (MatchCharset(*it, Charset6)) { state = 229; ++it; continue; }
                return -1;
            case 229:
                return 58;
            case 230:
                if (MatchCharset(*it, Charset23)) { state = 231; ++it; continue; }
                return -1;
            case 231:
                if (MatchCharset(*it, Charset24)) { state = 232; ++it; continue; }
                return -1;
            case 232:
                if (MatchCharset(*it, Charset12)) { state = 233; ++it; continue; }
                return -1;
            case 233:
                return 65;
            case 234:
                if (MatchCharset(*it, Charset21)) { state = 235; ++it; continue; }
                if (MatchCharset(*it, Charset31)) { state = 237; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 239; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 261; ++it; continue; }
                return -1;
            case 235:
                if (MatchCharset(*it, Charset12)) { state = 236; ++it; continue; }
                return -1;
            case 236:
                return 48;
            case 237:
                if (MatchCharset(*it, Charset12)) { state = 238; ++it; continue; }
                return -1;
            case 238:
                return 53;
            case 239:
                if (MatchCharset(*it, Charset21)) { state = 240; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 252; ++it; continue; }
                return -1;
            case 240:
                if (MatchCharset(*it, Charset12)) { state = 241; ++it; continue; }
                return -1;
            case 241:
                if (MatchCharset(*it, Charset25)) { state = 242; ++it; continue; }
                return -1;
            case 242:
                if (MatchCharset(*it, Charset12)) { state = 243; ++it; continue; }
                return -1;
            case 243:
                if (MatchCharset(*it, Charset11)) { state = 244; ++it; continue; }
                return -1;
            case 244:
                if (MatchCharset(*it, Charset15)) { state = 245; ++it; continue; }
                return -1;
            case 245:
                if (MatchCharset(*it, Charset8)) { state = 246; ++it; continue; }
                return -1;
            case 246:
                if (MatchCharset(*it, Charset17)) { state = 247; ++it; continue; }
                return -1;
            case 247:
                if (MatchCharset(*it, Charset17)) { state = 248; ++it; continue; }
                return -1;
            case 248:
                if (MatchCharset(*it, Charset27)) { state = 249; ++it; continue; }
                return -1;
            case 249:
                if (MatchCharset(*it, Charset8)) { state = 250; ++it; continue; }
                return -1;
            case 250:
                if (MatchCharset(*it, Charset6)) { state = 251; ++it; continue; }
                return -1;
            case 251:
                return 49;
            case 252:
                if (MatchCharset(*it, Charset20)) { state = 253; ++it; continue; }
                return -1;
            case 253:
                if (MatchCharset(*it, Charset14)) { state = 254; ++it; continue; }
                return -1;
            case 254:
                if (MatchCharset(*it, Charset23)) { state = 255; ++it; continue; }
                return -1;
            case 255:
                if (MatchCharset(*it, Charset8)) { state = 256; ++it; continue; }
                return -1;
            case 256:
                if (MatchCharset(*it, Charset21)) { state = 257; ++it; continue; }
                return -1;
            case 257:
                if (MatchCharset(*it, Charset15)) { state = 258; ++it; continue; }
                return -1;
            case 258:
                if (MatchCharset(*it, Charset12)) { state = 259; ++it; continue; }
                return -1;
            case 259:
                if (MatchCharset(*it, Charset23)) { state = 260; ++it; continue; }
                return -1;
            case 260:
                return 50;
            case 261:
                if (MatchCharset(*it, Charset25)) { state = 262; ++it; continue; }
                return -1;
            case 262:
                if (MatchCharset(*it, Charset17)) { state = 263; ++it; continue; }
                return -1;
            case 263:
                if (MatchCharset(*it, Charset12)) { state = 264; ++it; continue; }
                return -1;
            case 264:
                if (MatchCharset(*it, Charset30)) { state = 265; ++it; continue; }
                return -1;
            case 265:
                if (MatchCharset(*it, Charset11)) { state = 266; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 273; ++it; continue; }
                return -1;
            case 266:
                if (MatchCharset(*it, Charset26)) { state = 267; ++it; continue; }
                return -1;
            case 267:
                if (MatchCharset(*it, Charset19)) { state = 268; ++it; continue; }
                return -1;
            case 268:
                if (MatchCharset(*it, Charset30)) { state = 269; ++it; continue; }
                return -1;
            case 269:
                if (MatchCharset(*it, Charset12)) { state = 270; ++it; continue; }
                return -1;
            case 270:
                if (MatchCharset(*it, Charset19)) { state = 271; ++it; continue; }
                return -1;
            case 271:
                if (MatchCharset(*it, Charset25)) { state = 272; ++it; continue; }
                return -1;
            case 272:
                return 51;
            case 273:
                if (MatchCharset(*it, Charset19)) { state = 274; ++it; continue; }
                return -1;
            case 274:
                if (MatchCharset(*it, Charset25)) { state = 275; ++it; continue; }
                return -1;
            case 275:
                if (MatchCharset(*it, Charset23)) { state = 276; ++it; continue; }
                return -1;
            case 276:
                if (MatchCharset(*it, Charset8)) { state = 277; ++it; continue; }
                return -1;
            case 277:
                if (MatchCharset(*it, Charset19)) { state = 278; ++it; continue; }
                return -1;
            case 278:
                if (MatchCharset(*it, Charset10)) { state = 279; ++it; continue; }
                return -1;
            case 279:
                if (MatchCharset(*it, Charset12)) { state = 280; ++it; continue; }
                return -1;
            case 280:
                return 52;
            case 281:
                if (MatchCharset(*it, Charset12)) { state = 282; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 284; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 294; ++it; continue; }
                return -1;
            case 282:
                if (MatchCharset(*it, Charset13)) { state = 283; ++it; continue; }
                return -1;
            case 283:
                return 56;
            case 284:
                if (MatchCharset(*it, Charset18)) { state = 285; ++it; continue; }
                return -1;
            case 285:
                if (MatchCharset(*it, Charset19)) { state = 286; ++it; continue; }
                return -1;
            case 286:
                if (MatchCharset(*it, Charset12)) { state = 287; ++it; continue; }
                return -1;
            case 287:
                if (MatchCharset(*it, Charset6)) { state = 288; ++it; continue; }
                return -1;
            case 288:
                if (MatchCharset(*it, Charset24)) { state = 289; ++it; continue; }
                return -1;
            case 289:
                if (MatchCharset(*it, Charset27)) { state = 290; ++it; continue; }
                return -1;
            case 290:
                if (MatchCharset(*it, Charset12)) { state = 291; ++it; continue; }
                return -1;
            case 291:
                if (MatchCharset(*it, Charset12)) { state = 292; ++it; continue; }
                return -1;
            case 292:
                if (MatchCharset(*it, Charset21)) { state = 293; ++it; continue; }
                return -1;
            case 293:
                return 57;
            case 294:
                if (MatchCharset(*it, Charset16)) { state = 295; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 297; ++it; continue; }
                return -1;
            case 295:
                if (MatchCharset(*it, Charset19)) { state = 296; ++it; continue; }
                return -1;
            case 296:
                return 54;
            case 297:
                if (MatchCharset(*it, Charset17)) { state = 298; ++it; continue; }
                return -1;
            case 298:
                if (MatchCharset(*it, Charset8)) { state = 299; ++it; continue; }
                return -1;
            case 299:
                if (MatchCharset(*it, Charset16)) { state = 300; ++it; continue; }
                return -1;
            case 300:
                if (MatchCharset(*it, Charset19)) { state = 301; ++it; continue; }
                return -1;
            case 301:
                return 55;
            case 302:
                if (MatchCharset(*it, Charset20)) { state = 303; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 306; ++it; continue; }
                return -1;
            case 303:
                if (MatchCharset(*it, Charset8)) { state = 304; ++it; continue; }
                return -1;
            case 304:
                if (MatchCharset(*it, Charset32)) { state = 305; ++it; continue; }
                return -1;
            case 305:
                return 59;
            case 306:
                if (MatchCharset(*it, Charset9)) { state = 307; ++it; continue; }
                return -1;
            case 307:
                return 60;
            case 308:
                if (MatchCharset(*it, Charset17)) { state = 309; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 311; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 320; ++it; continue; }
                return -1;
            case 309:
                if (MatchCharset(*it, Charset11)) { state = 310; ++it; continue; }
                return -1;
            case 310:
                return 61;
            case 311:
                if (MatchCharset(*it, Charset10)) { state = 312; ++it; continue; }
                return -1;
            case 312:
                if (MatchCharset(*it, Charset12)) { state = 313; ++it; continue; }
                return -1;
            case 313:
                if (MatchCharset(*it, Charset23)) { state = 314; ++it; continue; }
                return -1;
            case 314:
                if (MatchCharset(*it, Charset25)) { state = 315; ++it; continue; }
                return -1;
            case 315:
                if (MatchCharset(*it, Charset15)) { state = 316; ++it; continue; }
                return -1;
            case 316:
                if (MatchCharset(*it, Charset8)) { state = 317; ++it; continue; }
                return -1;
            case 317:
                if (MatchCharset(*it, Charset17)) { state = 318; ++it; continue; }
                return -1;
            case 318:
                if (MatchCharset(*it, Charset17)) { state = 319; ++it; continue; }
                return -1;
            case 319:
                return 63;
            case 320:
                if (MatchCharset(*it, Charset32)) { state = 321; ++it; continue; }
                return -1;
            case 321:
                return 64;
            case 322:
                if (MatchCharset(*it, Charset12)) { state = 323; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 326; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 354; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 398; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 421; ++it; continue; }
                if (MatchCharset(*it, Charset33)) { state = 434; ++it; continue; }
                return 66;
            case 323:
                if (MatchCharset(*it, Charset8)) { state = 324; ++it; continue; }
                return -1;
            case 324:
                if (MatchCharset(*it, Charset11)) { state = 325; ++it; continue; }
                return -1;
            case 325:
                return 71;
            case 326:
                if (MatchCharset(*it, Charset14)) { state = 327; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 331; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 346; ++it; continue; }
                return -1;
            case 327:
                if (MatchCharset(*it, Charset14)) { state = 328; ++it; continue; }
                return -1;
            case 328:
                if (MatchCharset(*it, Charset12)) { state = 329; ++it; continue; }
                return -1;
            case 329:
                if (MatchCharset(*it, Charset23)) { state = 330; ++it; continue; }
                return -1;
            case 330:
                return 67;
            case 331:
                if (MatchCharset(*it, Charset30)) { state = 332; ++it; continue; }
                return -1;
            case 332:
                if (MatchCharset(*it, Charset20)) { state = 333; ++it; continue; }
                return -1;
            case 333:
                if (MatchCharset(*it, Charset13)) { state = 334; ++it; continue; }
                return -1;
            case 334:
                if (MatchCharset(*it, Charset30)) { state = 335; ++it; continue; }
                return -1;
            case 335:
                if (MatchCharset(*it, Charset21)) { state = 336; ++it; continue; }
                return -1;
            case 336:
                if (MatchCharset(*it, Charset23)) { state = 337; ++it; continue; }
                return -1;
            case 337:
                if (MatchCharset(*it, Charset20)) { state = 338; ++it; continue; }
                return -1;
            case 338:
                if (MatchCharset(*it, Charset25)) { state = 339; ++it; continue; }
                return -1;
            case 339:
                if (MatchCharset(*it, Charset12)) { state = 340; ++it; continue; }
                return -1;
            case 340:
                if (MatchCharset(*it, Charset10)) { state = 341; ++it; continue; }
                return -1;
            case 341:
                if (MatchCharset(*it, Charset25)) { state = 342; ++it; continue; }
                return -1;
            case 342:
                if (MatchCharset(*it, Charset16)) { state = 343; ++it; continue; }
                return -1;
            case 343:
                if (MatchCharset(*it, Charset20)) { state = 344; ++it; continue; }
                return -1;
            case 344:
                if (MatchCharset(*it, Charset19)) { state = 345; ++it; continue; }
                return -1;
            case 345:
                return 70;
            case 346:
                if (MatchCharset(*it, Charset32)) { state = 347; ++it; continue; }
                return -1;
            case 347:
                if (MatchCharset(*it, Charset30)) { state = 348; ++it; continue; }
                return 68;
            case 348:
                if (MatchCharset(*it, Charset14)) { state = 349; ++it; continue; }
                return -1;
            case 349:
                if (MatchCharset(*it, Charset26)) { state = 350; ++it; continue; }
                return -1;
            case 350:
                if (MatchCharset(*it, Charset16)) { state = 351; ++it; continue; }
                return -1;
            case 351:
                if (MatchCharset(*it, Charset17)) { state = 352; ++it; continue; }
                return -1;
            case 352:
                if (MatchCharset(*it, Charset11)) { state = 353; ++it; continue; }
                return -1;
            case 353:
                return 69;
            case 354:
                if (MatchCharset(*it, Charset21)) { state = 355; ++it; continue; }
                if (MatchCharset(*it, Charset34)) { state = 361; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 364; ++it; continue; }
                return -1;
            case 355:
                if (MatchCharset(*it, Charset17)) { state = 356; ++it; continue; }
                return -1;
            case 356:
                if (MatchCharset(*it, Charset20)) { state = 357; ++it; continue; }
                return -1;
            case 357:
                if (MatchCharset(*it, Charset18)) { state = 358; ++it; continue; }
                return -1;
            case 358:
                if (MatchCharset(*it, Charset8)) { state = 359; ++it; continue; }
                return -1;
            case 359:
                if (MatchCharset(*it, Charset25)) { state = 360; ++it; continue; }
                return -1;
            case 360:
                return 75;
            case 361:
                if (MatchCharset(*it, Charset34)) { state = 362; ++it; continue; }
                return -1;
            case 362:
                if (MatchCharset(*it, Charset6)) { state = 363; ++it; continue; }
                return -1;
            case 363:
                return 83;
            case 364:
                if (MatchCharset(*it, Charset21)) { state = 365; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 374; ++it; continue; }
                return -1;
            case 365:
                if (MatchCharset(*it, Charset12)) { state = 366; ++it; continue; }
                return -1;
            case 366:
                if (MatchCharset(*it, Charset17)) { state = 367; ++it; continue; }
                return -1;
            case 367:
                if (MatchCharset(*it, Charset30)) { state = 368; ++it; continue; }
                return -1;
            case 368:
                if (MatchCharset(*it, Charset18)) { state = 369; ++it; continue; }
                return -1;
            case 369:
                if (MatchCharset(*it, Charset8)) { state = 370; ++it; continue; }
                return -1;
            case 370:
                if (MatchCharset(*it, Charset14)) { state = 371; ++it; continue; }
                return -1;
            case 371:
                if (MatchCharset(*it, Charset16)) { state = 372; ++it; continue; }
                return -1;
            case 372:
                if (MatchCharset(*it, Charset10)) { state = 373; ++it; continue; }
                return -1;
            case 373:
                return 82;
            case 374:
                if (MatchCharset(*it, Charset8)) { state = 375; ++it; continue; }
                return -1;
            case 375:
                if (MatchCharset(*it, Charset24)) { state = 376; ++it; continue; }
                return -1;
            case 376:
                if (MatchCharset(*it, Charset12)) { state = 377; ++it; continue; }
                return -1;
            case 377:
                if (MatchCharset(*it, Charset35)) { state = 378; ++it; continue; }
                if (MatchCharset(*it, Charset36)) { state = 379; ++it; continue; }
                if (MatchCharset(*it, Charset37)) { state = 380; ++it; continue; }
                if (MatchCharset(*it, Charset30)) { state = 381; ++it; continue; }
                return -1;
            case 378:
                return 79;
            case 379:
                return 80;
            case 380:
                return 81;
            case 381:
                if (MatchCharset(*it, Charset18)) { state = 382; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 388; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 394; ++it; continue; }
                return -1;
            case 382:
                if (MatchCharset(*it, Charset12)) { state = 383; ++it; continue; }
                return -1;
            case 383:
                if (MatchCharset(*it, Charset11)) { state = 384; ++it; continue; }
                return -1;
            case 384:
                if (MatchCharset(*it, Charset16)) { state = 385; ++it; continue; }
                return -1;
            case 385:
                if (MatchCharset(*it, Charset26)) { state = 386; ++it; continue; }
                return -1;
            case 386:
                if (MatchCharset(*it, Charset18)) { state = 387; ++it; continue; }
                return -1;
            case 387:
                return 76;
            case 388:
                if (MatchCharset(*it, Charset12)) { state = 389; ++it; continue; }
                return -1;
            case 389:
                if (MatchCharset(*it, Charset31)) { state = 390; ++it; continue; }
                return -1;
            case 390:
                if (MatchCharset(*it, Charset12)) { state = 391; ++it; continue; }
                return -1;
            case 391:
                if (MatchCharset(*it, Charset23)) { state = 392; ++it; continue; }
                return -1;
            case 392:
                if (MatchCharset(*it, Charset12)) { state = 393; ++it; continue; }
                return -1;
            case 393:
                return 77;
            case 394:
                if (MatchCharset(*it, Charset12)) { state = 395; ++it; continue; }
                return -1;
            case 395:
                if (MatchCharset(*it, Charset8)) { state = 396; ++it; continue; }
                return -1;
            case 396:
                if (MatchCharset(*it, Charset32)) { state = 397; ++it; continue; }
                return -1;
            case 397:
                return 78;
            case 398:
                if (MatchCharset(*it, Charset8)) { state = 399; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 414; ++it; continue; }
                return -1;
            case 399:
                if (MatchCharset(*it, Charset14)) { state = 400; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 410; ++it; continue; }
                return -1;
            case 400:
                if (MatchCharset(*it, Charset20)) { state = 401; ++it; continue; }
                return -1;
            case 401:
                if (MatchCharset(*it, Charset19)) { state = 402; ++it; continue; }
                return -1;
            case 402:
                if (MatchCharset(*it, Charset30)) { state = 403; ++it; continue; }
                return -1;
            case 403:
                if (MatchCharset(*it, Charset9)) { state = 404; ++it; continue; }
                return -1;
            case 404:
                if (MatchCharset(*it, Charset23)) { state = 405; ++it; continue; }
                return -1;
            case 405:
                if (MatchCharset(*it, Charset12)) { state = 406; ++it; continue; }
                return -1;
            case 406:
                if (MatchCharset(*it, Charset8)) { state = 407; ++it; continue; }
                return -1;
            case 407:
                if (MatchCharset(*it, Charset25)) { state = 408; ++it; continue; }
                return -1;
            case 408:
                if (MatchCharset(*it, Charset15)) { state = 409; ++it; continue; }
                return -1;
            case 409:
                return 84;
            case 410:
                if (MatchCharset(*it, Charset19)) { state = 411; ++it; continue; }
                return -1;
            case 411:
                if (MatchCharset(*it, Charset24)) { state = 412; ++it; continue; }
                return -1;
            case 412:
                if (MatchCharset(*it, Charset21)) { state = 413; ++it; continue; }
                return -1;
            case 413:
                return 85;
            case 414:
                if (MatchCharset(*it, Charset14)) { state = 415; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 419; ++it; continue; }
                return -1;
            case 415:
                if (MatchCharset(*it, Charset14)) { state = 416; ++it; continue; }
                return -1;
            case 416:
                if (MatchCharset(*it, Charset12)) { state = 417; ++it; continue; }
                return -1;
            case 417:
                if (MatchCharset(*it, Charset11)) { state = 418; ++it; continue; }
                return -1;
            case 418:
                return 86;
            case 419:
                if (MatchCharset(*it, Charset32)) { state = 420; ++it; continue; }
                return -1;
            case 420:
                return 87;
            case 421:
                if (MatchCharset(*it, Charset19)) { state = 422; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 431; ++it; continue; }
                return -1;
            case 422:
                if (MatchCharset(*it, Charset14)) { state = 423; ++it; continue; }
                return -1;
            case 423:
                if (MatchCharset(*it, Charset12)) { state = 424; ++it; continue; }
                return -1;
            case 424:
                if (MatchCharset(*it, Charset20)) { state = 425; ++it; continue; }
                return -1;
            case 425:
                if (MatchCharset(*it, Charset19)) { state = 426; ++it; continue; }
                return -1;
            case 426:
                if (MatchCharset(*it, Charset30)) { state = 427; ++it; continue; }
                return -1;
            case 427:
                if (MatchCharset(*it, Charset12)) { state = 428; ++it; continue; }
                return -1;
            case 428:
                if (MatchCharset(*it, Charset19)) { state = 429; ++it; continue; }
                return -1;
            case 429:
                if (MatchCharset(*it, Charset25)) { state = 430; ++it; continue; }
                return -1;
            case 430:
                return 88;
            case 431:
                if (MatchCharset(*it, Charset12)) { state = 432; ++it; continue; }
                return -1;
            case 432:
                if (MatchCharset(*it, Charset23)) { state = 433; ++it; continue; }
                return -1;
            case 433:
                return 89;
            case 434:
                if (MatchCharset(*it, Charset15)) { state = 435; ++it; continue; }
                return -1;
            case 435:
                if (MatchCharset(*it, Charset20)) { state = 436; ++it; continue; }
                return -1;
            case 436:
                if (MatchCharset(*it, Charset24)) { state = 437; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 440; ++it; continue; }
                return -1;
            case 437:
                if (MatchCharset(*it, Charset26)) { state = 438; ++it; continue; }
                return -1;
            case 438:
                if (MatchCharset(*it, Charset12)) { state = 439; ++it; continue; }
                return -1;
            case 439:
                return 90;
            case 440:
                if (MatchCharset(*it, Charset24)) { state = 441; ++it; continue; }
                return -1;
            case 441:
                if (MatchCharset(*it, Charset12)) { state = 442; ++it; continue; }
                return -1;
            case 442:
                return 91;
            case 443:
                if (MatchCharset(*it, Charset7)) { state = 444; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 445; ++it; continue; }
                if (MatchCharset(*it, Charset33)) { state = 449; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 455; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 465; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 477; ++it; continue; }
                return 92;
            case 444:
                if (MatchCharset(*it, Charset7)) { state = 444; ++it; continue; }
                return 95;
            case 445:
                if (MatchCharset(*it, Charset23)) { state = 446; ++it; continue; }
                return -1;
            case 446:
                if (MatchCharset(*it, Charset8)) { state = 447; ++it; continue; }
                return -1;
            case 447:
                if (MatchCharset(*it, Charset11)) { state = 448; ++it; continue; }
                return -1;
            case 448:
                return 100;
            case 449:
                if (MatchCharset(*it, Charset15)) { state = 450; ++it; continue; }
                return -1;
            case 450:
                if (MatchCharset(*it, Charset20)) { state = 451; ++it; continue; }
                return -1;
            case 451:
                if (MatchCharset(*it, Charset26)) { state = 452; ++it; continue; }
                return -1;
            case 452:
                if (MatchCharset(*it, Charset24)) { state = 453; ++it; continue; }
                return -1;
            case 453:
                if (MatchCharset(*it, Charset12)) { state = 454; ++it; continue; }
                return -1;
            case 454:
                return 104;
            case 455:
                if (MatchCharset(*it, Charset23)) { state = 456; ++it; continue; }
                return -1;
            case 456:
                if (MatchCharset(*it, Charset25)) { state = 457; ++it; continue; }
                return -1;
            case 457:
                if (MatchCharset(*it, Charset15)) { state = 458; ++it; continue; }
                return -1;
            case 458:
                if (MatchCharset(*it, Charset30)) { state = 459; ++it; continue; }
                return 93;
            case 459:
                if (MatchCharset(*it, Charset14)) { state = 460; ++it; continue; }
                return -1;
            case 460:
                if (MatchCharset(*it, Charset26)) { state = 461; ++it; continue; }
                return -1;
            case 461:
                if (MatchCharset(*it, Charset16)) { state = 462; ++it; continue; }
                return -1;
            case 462:
                if (MatchCharset(*it, Charset17)) { state = 463; ++it; continue; }
                return -1;
            case 463:
                if (MatchCharset(*it, Charset11)) { state = 464; ++it; continue; }
                return -1;
            case 464:
                return 94;
            case 465:
                if (MatchCharset(*it, Charset10)) { state = 466; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 473; ++it; continue; }
                return -1;
            case 466:
                if (MatchCharset(*it, Charset15)) { state = 467; ++it; continue; }
                return -1;
            case 467:
                if (MatchCharset(*it, Charset8)) { state = 468; ++it; continue; }
                return -1;
            case 468:
                if (MatchCharset(*it, Charset19)) { state = 469; ++it; continue; }
                return -1;
            case 469:
                if (MatchCharset(*it, Charset25)) { state = 470; ++it; continue; }
                return -1;
            case 470:
                if (MatchCharset(*it, Charset12)) { state = 471; ++it; continue; }
                return -1;
            case 471:
                if (MatchCharset(*it, Charset23)) { state = 472; ++it; continue; }
                return -1;
            case 472:
                return 96;
            case 473:
                if (MatchCharset(*it, Charset23)) { state = 474; ++it; continue; }
                return -1;
            case 474:
                if (MatchCharset(*it, Charset14)) { state = 475; ++it; continue; }
                return 98;
            case 475:
                if (MatchCharset(*it, Charset6)) { state = 476; ++it; continue; }
                return -1;
            case 476:
                return 99;
            case 477:
                if (MatchCharset(*it, Charset21)) { state = 478; ++it; continue; }
                return -1;
            case 478:
                if (MatchCharset(*it, Charset12)) { state = 479; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 488; ++it; continue; }
                return -1;
            case 479:
                if (MatchCharset(*it, Charset23)) { state = 480; ++it; continue; }
                return -1;
            case 480:
                if (MatchCharset(*it, Charset25)) { state = 481; ++it; continue; }
                return -1;
            case 481:
                if (MatchCharset(*it, Charset15)) { state = 482; ++it; continue; }
                return -1;
            case 482:
                if (MatchCharset(*it, Charset12)) { state = 483; ++it; continue; }
                return -1;
            case 483:
                if (MatchCharset(*it, Charset8)) { state = 484; ++it; continue; }
                return -1;
            case 484:
                if (MatchCharset(*it, Charset17)) { state = 485; ++it; continue; }
                return -1;
            case 485:
                if (MatchCharset(*it, Charset12)) { state = 486; ++it; continue; }
                return -1;
            case 486:
                if (MatchCharset(*it, Charset23)) { state = 487; ++it; continue; }
                return -1;
            case 487:
                return 101;
            case 488:
                if (MatchCharset(*it, Charset20)) { state = 489; ++it; continue; }
                return -1;
            case 489:
                if (MatchCharset(*it, Charset11)) { state = 490; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 492; ++it; continue; }
                return -1;
            case 490:
                if (MatchCharset(*it, Charset12)) { state = 491; ++it; continue; }
                return -1;
            case 491:
                return 102;
            case 492:
                if (MatchCharset(*it, Charset12)) { state = 493; ++it; continue; }
                return -1;
            case 493:
                if (MatchCharset(*it, Charset23)) { state = 494; ++it; continue; }
                return -1;
            case 494:
                return 103;
            case 495:
                if (MatchCharset(*it, Charset23)) { state = 496; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 499; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 516; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 535; ++it; continue; }
                return -1;
            case 496:
                if (MatchCharset(*it, Charset12)) { state = 497; ++it; continue; }
                return -1;
            case 497:
                if (MatchCharset(*it, Charset12)) { state = 498; ++it; continue; }
                return -1;
            case 498:
                return 116;
            case 499:
                if (MatchCharset(*it, Charset10)) { state = 500; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 504; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 514; ++it; continue; }
                return -1;
            case 500:
                if (MatchCharset(*it, Charset25)) { state = 501; ++it; continue; }
                return -1;
            case 501:
                if (MatchCharset(*it, Charset20)) { state = 502; ++it; continue; }
                return -1;
            case 502:
                if (MatchCharset(*it, Charset23)) { state = 503; ++it; continue; }
                return -1;
            case 503:
                return 105;
            case 504:
                if (MatchCharset(*it, Charset17)) { state = 505; ++it; continue; }
                return -1;
            case 505:
                if (MatchCharset(*it, Charset12)) { state = 506; ++it; continue; }
                return -1;
            case 506:
                if (MatchCharset(*it, Charset19)) { state = 507; ++it; continue; }
                return -1;
            case 507:
                if (MatchCharset(*it, Charset27)) { state = 508; ++it; continue; }
                return -1;
            case 508:
                if (MatchCharset(*it, Charset16)) { state = 509; ++it; continue; }
                return -1;
            case 509:
                if (MatchCharset(*it, Charset34)) { state = 510; ++it; continue; }
                return -1;
            case 510:
                if (MatchCharset(*it, Charset8)) { state = 511; ++it; continue; }
                return -1;
            case 511:
                if (MatchCharset(*it, Charset23)) { state = 512; ++it; continue; }
                return -1;
            case 512:
                if (MatchCharset(*it, Charset11)) { state = 513; ++it; continue; }
                return -1;
            case 513:
                return 106;
            case 514:
                if (MatchCharset(*it, Charset12)) { state = 515; ++it; continue; }
                return -1;
            case 515:
                return 107;
            case 516:
                if (MatchCharset(*it, Charset23)) { state = 517; ++it; continue; }
                return -1;
            case 517:
                if (MatchCharset(*it, Charset12)) { state = 518; ++it; continue; }
                return -1;
            case 518:
                if (MatchCharset(*it, Charset8)) { state = 519; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 521; ++it; continue; }
                if (MatchCharset(*it, Charset30)) { state = 525; ++it; continue; }
                return 108;
            case 519:
                if (MatchCharset(*it, Charset23)) { state = 520; ++it; continue; }
                return -1;
            case 520:
                return 111;
            case 521:
                if (MatchCharset(*it, Charset8)) { state = 522; ++it; continue; }
                return -1;
            case 522:
                if (MatchCharset(*it, Charset17)) { state = 523; ++it; continue; }
                return -1;
            case 523:
                if (MatchCharset(*it, Charset17)) { state = 524; ++it; continue; }
                return -1;
            case 524:
                return 112;
            case 525:
                if (MatchCharset(*it, Charset9)) { state = 526; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 530; ++it; continue; }
                return -1;
            case 526:
                if (MatchCharset(*it, Charset20)) { state = 527; ++it; continue; }
                return -1;
            case 527:
                if (MatchCharset(*it, Charset17)) { state = 528; ++it; continue; }
                return -1;
            case 528:
                if (MatchCharset(*it, Charset25)) { state = 529; ++it; continue; }
                return -1;
            case 529:
                return 109;
            case 530:
                if (MatchCharset(*it, Charset26)) { state = 531; ++it; continue; }
                return -1;
            case 531:
                if (MatchCharset(*it, Charset16)) { state = 532; ++it; continue; }
                return -1;
            case 532:
                if (MatchCharset(*it, Charset17)) { state = 533; ++it; continue; }
                return -1;
            case 533:
                if (MatchCharset(*it, Charset11)) { state = 534; ++it; continue; }
                return -1;
            case 534:
                return 110;
            case 535:
                if (MatchCharset(*it, Charset20)) { state = 536; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 538; ++it; continue; }
                return -1;
            case 536:
                if (MatchCharset(*it, Charset17)) { state = 537; ++it; continue; }
                return -1;
            case 537:
                return 114;
            case 538:
                if (MatchCharset(*it, Charset12)) { state = 539; ++it; continue; }
                return -1;
            case 539:
                if (MatchCharset(*it, Charset24)) { state = 540; ++it; continue; }
                return -1;
            case 540:
                if (MatchCharset(*it, Charset25)) { state = 541; ++it; continue; }
                return -1;
            case 541:
                return 115;
            case 542:
                if (MatchCharset(*it, Charset17)) { state = 543; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 548; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 551; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 556; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 560; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 564; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 580; ++it; continue; }
                return 117;
            case 543:
                if (MatchCharset(*it, Charset20)) { state = 544; ++it; continue; }
                return -1;
            case 544:
                if (MatchCharset(*it, Charset9)) { state = 545; ++it; continue; }
                return -1;
            case 545:
                if (MatchCharset(*it, Charset8)) { state = 546; ++it; continue; }
                return -1;
            case 546:
                if (MatchCharset(*it, Charset17)) { state = 547; ++it; continue; }
                return -1;
            case 547:
                return 122;
            case 548:
                if (MatchCharset(*it, Charset17)) { state = 549; ++it; continue; }
                return -1;
            case 549:
                if (MatchCharset(*it, Charset11)) { state = 550; ++it; continue; }
                return -1;
            case 550:
                return 123;
            case 551:
                if (MatchCharset(*it, Charset20)) { state = 552; ++it; continue; }
                return -1;
            case 552:
                if (MatchCharset(*it, Charset26)) { state = 553; ++it; continue; }
                return -1;
            case 553:
                if (MatchCharset(*it, Charset19)) { state = 554; ++it; continue; }
                return -1;
            case 554:
                if (MatchCharset(*it, Charset11)) { state = 555; ++it; continue; }
                return -1;
            case 555:
                return 124;
            case 556:
                if (MatchCharset(*it, Charset16)) { state = 557; ++it; continue; }
                return -1;
            case 557:
                if (MatchCharset(*it, Charset11)) { state = 558; ++it; continue; }
                return -1;
            case 558:
                if (MatchCharset(*it, Charset12)) { state = 559; ++it; continue; }
                return -1;
            case 559:
                return 125;
            case 560:
                if (MatchCharset(*it, Charset21)) { state = 561; ++it; continue; }
                return -1;
            case 561:
                if (MatchCharset(*it, Charset24)) { state = 562; ++it; continue; }
                return -1;
            case 562:
                if (MatchCharset(*it, Charset6)) { state = 563; ++it; continue; }
                return -1;
            case 563:
                return 126;
            case 564:
                if (MatchCharset(*it, Charset25)) { state = 565; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 573; ++it; continue; }
                return -1;
            case 565:
                if (MatchCharset(*it, Charset12)) { state = 566; ++it; continue; }
                return -1;
            case 566:
                if (MatchCharset(*it, Charset18)) { state = 567; ++it; continue; }
                return -1;
            case 567:
                if (MatchCharset(*it, Charset8)) { state = 568; ++it; continue; }
                return -1;
            case 568:
                if (MatchCharset(*it, Charset24)) { state = 569; ++it; continue; }
                return -1;
            case 569:
                if (MatchCharset(*it, Charset25)) { state = 570; ++it; continue; }
                return -1;
            case 570:
                if (MatchCharset(*it, Charset12)) { state = 571; ++it; continue; }
                return -1;
            case 571:
                if (MatchCharset(*it, Charset23)) { state = 572; ++it; continue; }
                return -1;
            case 572:
                return 118;
            case 573:
                if (MatchCharset(*it, Charset19)) { state = 574; ++it; continue; }
                return -1;
            case 574:
                if (MatchCharset(*it, Charset25)) { state = 575; ++it; continue; }
                return -1;
            case 575:
                if (MatchCharset(*it, Charset17)) { state = 576; ++it; continue; }
                return -1;
            case 576:
                if (MatchCharset(*it, Charset12)) { state = 577; ++it; continue; }
                return -1;
            case 577:
                if (MatchCharset(*it, Charset25)) { state = 578; ++it; continue; }
                return -1;
            case 578:
                if (MatchCharset(*it, Charset24)) { state = 579; ++it; continue; }
                return -1;
            case 579:
                return 119;
            case 580:
                if (MatchCharset(*it, Charset18)) { state = 581; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 582; ++it; continue; }
                return -1;
            case 581:
                return 120;
            case 582:
                if (MatchCharset(*it, Charset12)) { state = 583; ++it; continue; }
                return -1;
            case 583:
                if (MatchCharset(*it, Charset23)) { state = 584; ++it; continue; }
                return -1;
            case 584:
                if (MatchCharset(*it, Charset16)) { state = 585; ++it; continue; }
                return -1;
            case 585:
                if (MatchCharset(*it, Charset10)) { state = 586; ++it; continue; }
                return -1;
            case 586:
                return 121;
            case 587:
                if (MatchCharset(*it, Charset16)) { state = 588; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 595; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 600; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 633; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 651; ++it; continue; }
                if (MatchCharset(*it, Charset33)) { state = 671; ++it; continue; }
                return -1;
            case 588:
                if (MatchCharset(*it, Charset31)) { state = 589; ++it; continue; }
                return -1;
            case 589:
                if (MatchCharset(*it, Charset12)) { state = 590; ++it; continue; }
                return -1;
            case 590:
                if (MatchCharset(*it, Charset30)) { state = 591; ++it; continue; }
                return -1;
            case 591:
                if (MatchCharset(*it, Charset12)) { state = 592; ++it; continue; }
                return -1;
            case 592:
                if (MatchCharset(*it, Charset19)) { state = 593; ++it; continue; }
                return -1;
            case 593:
                if (MatchCharset(*it, Charset25)) { state = 594; ++it; continue; }
                return -1;
            case 594:
                return 138;
            case 595:
                if (MatchCharset(*it, Charset19)) { state = 596; ++it; continue; }
                return -1;
            case 596:
                if (MatchCharset(*it, Charset25)) { state = 597; ++it; continue; }
                return -1;
            case 597:
                if (MatchCharset(*it, Charset12)) { state = 598; ++it; continue; }
                return -1;
            case 598:
                if (MatchCharset(*it, Charset23)) { state = 599; ++it; continue; }
                return -1;
            case 599:
                return 142;
            case 600:
                if (MatchCharset(*it, Charset17)) { state = 601; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 606; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 615; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 619; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 622; ++it; continue; }
                return -1;
            case 601:
                if (MatchCharset(*it, Charset17)) { state = 602; ++it; continue; }
                return -1;
            case 602:
                if (MatchCharset(*it, Charset27)) { state = 603; ++it; continue; }
                return -1;
            case 603:
                if (MatchCharset(*it, Charset8)) { state = 604; ++it; continue; }
                return -1;
            case 604:
                if (MatchCharset(*it, Charset6)) { state = 605; ++it; continue; }
                return -1;
            case 605:
                return 127;
            case 606:
                if (MatchCharset(*it, Charset18)) { state = 607; ++it; continue; }
                return -1;
            case 607:
                if (MatchCharset(*it, Charset12)) { state = 608; ++it; continue; }
                return -1;
            case 608:
                if (MatchCharset(*it, Charset23)) { state = 609; ++it; continue; }
                return -1;
            case 609:
                if (MatchCharset(*it, Charset15)) { state = 610; ++it; continue; }
                return -1;
            case 610:
                if (MatchCharset(*it, Charset8)) { state = 611; ++it; continue; }
                return -1;
            case 611:
                if (MatchCharset(*it, Charset19)) { state = 612; ++it; continue; }
                return -1;
            case 612:
                if (MatchCharset(*it, Charset11)) { state = 613; ++it; continue; }
                return -1;
            case 613:
                if (MatchCharset(*it, Charset24)) { state = 614; ++it; continue; }
                return -1;
            case 614:
                return 128;
            case 615:
                if (MatchCharset(*it, Charset14)) { state = 616; ++it; continue; }
                return -1;
            case 616:
                if (MatchCharset(*it, Charset8)) { state = 617; ++it; continue; }
                return -1;
            case 617:
                if (MatchCharset(*it, Charset23)) { state = 618; ++it; continue; }
                return -1;
            case 618:
                return 129;
            case 619:
                if (MatchCharset(*it, Charset25)) { state = 620; ++it; continue; }
                return -1;
            case 620:
                if (MatchCharset(*it, Charset12)) { state = 621; ++it; continue; }
                return -1;
            case 621:
                return 132;
            case 622:
                if (MatchCharset(*it, Charset18)) { state = 623; ++it; continue; }
                return -1;
            case 623:
                if (MatchCharset(*it, Charset20)) { state = 624; ++it; continue; }
                return 130;
            case 624:
                if (MatchCharset(*it, Charset19)) { state = 625; ++it; continue; }
                return -1;
            case 625:
                if (MatchCharset(*it, Charset11)) { state = 626; ++it; continue; }
                return -1;
            case 626:
                if (MatchCharset(*it, Charset6)) { state = 627; ++it; continue; }
                return -1;
            case 627:
                if (MatchCharset(*it, Charset30)) { state = 628; ++it; continue; }
                return -1;
            case 628:
                if (MatchCharset(*it, Charset23)) { state = 629; ++it; continue; }
                return -1;
            case 629:
                if (MatchCharset(*it, Charset20)) { state = 630; ++it; continue; }
                return -1;
            case 630:
                if (MatchCharset(*it, Charset20)) { state = 631; ++it; continue; }
                return -1;
            case 631:
                if (MatchCharset(*it, Charset18)) { state = 632; ++it; continue; }
                return -1;
            case 632:
                return 131;
            case 633:
                if (MatchCharset(*it, Charset8)) { state = 634; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 638; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 640; ++it; continue; }
                return -1;
            case 634:
                if (MatchCharset(*it, Charset17)) { state = 635; ++it; continue; }
                return -1;
            case 635:
                if (MatchCharset(*it, Charset12)) { state = 636; ++it; continue; }
                return -1;
            case 636:
                if (MatchCharset(*it, Charset23)) { state = 637; ++it; continue; }
                return -1;
            case 637:
                return 133;
            case 638:
                if (MatchCharset(*it, Charset18)) { state = 639; ++it; continue; }
                return -1;
            case 639:
                return 134;
            case 640:
                if (MatchCharset(*it, Charset20)) { state = 641; ++it; continue; }
                if (MatchCharset(*it, Charset9)) { state = 645; ++it; continue; }
                return -1;
            case 641:
                if (MatchCharset(*it, Charset16)) { state = 642; ++it; continue; }
                return -1;
            case 642:
                if (MatchCharset(*it, Charset24)) { state = 643; ++it; continue; }
                return -1;
            case 643:
                if (MatchCharset(*it, Charset18)) { state = 644; ++it; continue; }
                return -1;
            case 644:
                return 137;
            case 645:
                if (MatchCharset(*it, Charset8)) { state = 646; ++it; continue; }
                return 135;
            case 646:
                if (MatchCharset(*it, Charset17)) { state = 647; ++it; continue; }
                return -1;
            case 647:
                if (MatchCharset(*it, Charset16)) { state = 648; ++it; continue; }
                return -1;
            case 648:
                if (MatchCharset(*it, Charset24)) { state = 649; ++it; continue; }
                return -1;
            case 649:
                if (MatchCharset(*it, Charset25)) { state = 650; ++it; continue; }
                return -1;
            case 650:
                return 136;
            case 651:
                if (MatchCharset(*it, Charset23)) { state = 652; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 658; ++it; continue; }
                return -1;
            case 652:
                if (MatchCharset(*it, Charset24)) { state = 653; ++it; continue; }
                return -1;
            case 653:
                if (MatchCharset(*it, Charset12)) { state = 654; ++it; continue; }
                return -1;
            case 654:
                if (MatchCharset(*it, Charset18)) { state = 655; ++it; continue; }
                return -1;
            case 655:
                if (MatchCharset(*it, Charset8)) { state = 656; ++it; continue; }
                return -1;
            case 656:
                if (MatchCharset(*it, Charset19)) { state = 657; ++it; continue; }
                return -1;
            case 657:
                return 139;
            case 658:
                if (MatchCharset(*it, Charset23)) { state = 659; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 669; ++it; continue; }
                return -1;
            case 659:
                if (MatchCharset(*it, Charset30)) { state = 660; ++it; continue; }
                return -1;
            case 660:
                if (MatchCharset(*it, Charset20)) { state = 661; ++it; continue; }
                return -1;
            case 661:
                if (MatchCharset(*it, Charset13)) { state = 662; ++it; continue; }
                return -1;
            case 662:
                if (MatchCharset(*it, Charset30)) { state = 663; ++it; continue; }
                return -1;
            case 663:
                if (MatchCharset(*it, Charset21)) { state = 664; ++it; continue; }
                return -1;
            case 664:
                if (MatchCharset(*it, Charset20)) { state = 665; ++it; continue; }
                return -1;
            case 665:
                if (MatchCharset(*it, Charset27)) { state = 666; ++it; continue; }
                return -1;
            case 666:
                if (MatchCharset(*it, Charset12)) { state = 667; ++it; continue; }
                return -1;
            case 667:
                if (MatchCharset(*it, Charset23)) { state = 668; ++it; continue; }
                return -1;
            case 668:
                return 140;
            case 669:
                if (MatchCharset(*it, Charset12)) { state = 670; ++it; continue; }
                return -1;
            case 670:
                return 141;
            case 671:
                if (MatchCharset(*it, Charset15)) { state = 672; ++it; continue; }
                return -1;
            case 672:
                if (MatchCharset(*it, Charset20)) { state = 673; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 677; ++it; continue; }
                return -1;
            case 673:
                if (MatchCharset(*it, Charset26)) { state = 674; ++it; continue; }
                return -1;
            case 674:
                if (MatchCharset(*it, Charset24)) { state = 675; ++it; continue; }
                return -1;
            case 675:
                if (MatchCharset(*it, Charset12)) { state = 676; ++it; continue; }
                return -1;
            case 676:
                return 143;
            case 677:
                if (MatchCharset(*it, Charset18)) { state = 678; ++it; continue; }
                return -1;
            case 678:
                if (MatchCharset(*it, Charset8)) { state = 679; ++it; continue; }
                return -1;
            case 679:
                if (MatchCharset(*it, Charset19)) { state = 680; ++it; continue; }
                return -1;
            case 680:
                return 144;
            case 681:
                if (MatchCharset(*it, Charset18)) { state = 682; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 684; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 695; ++it; continue; }
                return -1;
            case 682:
                if (MatchCharset(*it, Charset18)) { state = 683; ++it; continue; }
                return -1;
            case 683:
                return 147;
            case 684:
                if (MatchCharset(*it, Charset12)) { state = 685; ++it; continue; }
                return -1;
            case 685:
                if (MatchCharset(*it, Charset30)) { state = 686; ++it; continue; }
                return -1;
            case 686:
                if (MatchCharset(*it, Charset9)) { state = 687; ++it; continue; }
                return -1;
            case 687:
                if (MatchCharset(*it, Charset17)) { state = 688; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 692; ++it; continue; }
                return -1;
            case 688:
                if (MatchCharset(*it, Charset8)) { state = 689; ++it; continue; }
                return -1;
            case 689:
                if (MatchCharset(*it, Charset24)) { state = 690; ++it; continue; }
                return -1;
            case 690:
                if (MatchCharset(*it, Charset25)) { state = 691; ++it; continue; }
                return -1;
            case 691:
                return 145;
            case 692:
                if (MatchCharset(*it, Charset17)) { state = 693; ++it; continue; }
                return -1;
            case 693:
                if (MatchCharset(*it, Charset25)) { state = 694; ++it; continue; }
                return -1;
            case 694:
                return 146;
            case 695:
                if (MatchCharset(*it, Charset10)) { state = 696; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 704; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 710; ++it; continue; }
                return -1;
            case 696:
                if (MatchCharset(*it, Charset16)) { state = 697; ++it; continue; }
                return -1;
            case 697:
                if (MatchCharset(*it, Charset19)) { state = 698; ++it; continue; }
                return -1;
            case 698:
                if (MatchCharset(*it, Charset12)) { state = 699; ++it; continue; }
                return -1;
            case 699:
                if (MatchCharset(*it, Charset23)) { state = 700; ++it; continue; }
                return -1;
            case 700:
                if (MatchCharset(*it, Charset8)) { state = 701; ++it; continue; }
                return -1;
            case 701:
                if (MatchCharset(*it, Charset25)) { state = 702; ++it; continue; }
                return -1;
            case 702:
                if (MatchCharset(*it, Charset12)) { state = 703; ++it; continue; }
                return -1;
            case 703:
                return 148;
            case 704:
                if (MatchCharset(*it, Charset25)) { state = 705; ++it; continue; }
                return -1;
            case 705:
                if (MatchCharset(*it, Charset16)) { state = 706; ++it; continue; }
                return -1;
            case 706:
                if (MatchCharset(*it, Charset8)) { state = 707; ++it; continue; }
                return -1;
            case 707:
                if (MatchCharset(*it, Charset25)) { state = 708; ++it; continue; }
                return -1;
            case 708:
                if (MatchCharset(*it, Charset12)) { state = 709; ++it; continue; }
                return -1;
            case 709:
                return 149;
            case 710:
                if (MatchCharset(*it, Charset8)) { state = 711; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 714; ++it; continue; }
                return -1;
            case 711:
                if (MatchCharset(*it, Charset19)) { state = 712; ++it; continue; }
                return -1;
            case 712:
                if (MatchCharset(*it, Charset12)) { state = 713; ++it; continue; }
                return -1;
            case 713:
                return 150;
            case 714:
                if (MatchCharset(*it, Charset23)) { state = 715; ++it; continue; }
                return -1;
            case 715:
                if (MatchCharset(*it, Charset26)) { state = 716; ++it; continue; }
                return -1;
            case 716:
                if (MatchCharset(*it, Charset10)) { state = 717; ++it; continue; }
                return -1;
            case 717:
                if (MatchCharset(*it, Charset25)) { state = 718; ++it; continue; }
                return -1;
            case 718:
                if (MatchCharset(*it, Charset20)) { state = 719; ++it; continue; }
                return -1;
            case 719:
                if (MatchCharset(*it, Charset23)) { state = 720; ++it; continue; }
                return -1;
            case 720:
                return 151;
            case 721:
                if (MatchCharset(*it, Charset12)) { state = 722; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 728; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 759; ++it; continue; }
                return -1;
            case 722:
                if (MatchCharset(*it, Charset8)) { state = 723; ++it; continue; }
                return -1;
            case 723:
                if (MatchCharset(*it, Charset25)) { state = 724; ++it; continue; }
                return -1;
            case 724:
                if (MatchCharset(*it, Charset15)) { state = 725; ++it; continue; }
                return -1;
            case 725:
                if (MatchCharset(*it, Charset12)) { state = 726; ++it; continue; }
                return -1;
            case 726:
                if (MatchCharset(*it, Charset23)) { state = 727; ++it; continue; }
                return -1;
            case 727:
                return 154;
            case 728:
                if (MatchCharset(*it, Charset31)) { state = 729; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 737; ++it; continue; }
                return -1;
            case 729:
                if (MatchCharset(*it, Charset16)) { state = 730; ++it; continue; }
                return -1;
            case 730:
                if (MatchCharset(*it, Charset19)) { state = 731; ++it; continue; }
                return -1;
            case 731:
                if (MatchCharset(*it, Charset14)) { state = 732; ++it; continue; }
                return -1;
            case 732:
                if (MatchCharset(*it, Charset23)) { state = 733; ++it; continue; }
                return -1;
            case 733:
                if (MatchCharset(*it, Charset20)) { state = 734; ++it; continue; }
                return -1;
            case 734:
                if (MatchCharset(*it, Charset20)) { state = 735; ++it; continue; }
                return -1;
            case 735:
                if (MatchCharset(*it, Charset18)) { state = 736; ++it; continue; }
                return -1;
            case 736:
                return 159;
            case 737:
                if (MatchCharset(*it, Charset15)) { state = 738; ++it; continue; }
                return -1;
            case 738:
                if (MatchCharset(*it, Charset25)) { state = 739; ++it; continue; }
                return -1;
            case 739:
                if (MatchCharset(*it, Charset19)) { state = 740; ++it; continue; }
                if (MatchCharset(*it, Charset30)) { state = 749; ++it; continue; }
                return 155;
            case 740:
                if (MatchCharset(*it, Charset16)) { state = 741; ++it; continue; }
                return -1;
            case 741:
                if (MatchCharset(*it, Charset19)) { state = 742; ++it; continue; }
                return -1;
            case 742:
                if (MatchCharset(*it, Charset14)) { state = 743; ++it; continue; }
                return -1;
            case 743:
                if (MatchCharset(*it, Charset30)) { state = 744; ++it; continue; }
                return -1;
            case 744:
                if (MatchCharset(*it, Charset9)) { state = 745; ++it; continue; }
                return -1;
            case 745:
                if (MatchCharset(*it, Charset20)) { state = 746; ++it; continue; }
                return -1;
            case 746:
                if (MatchCharset(*it, Charset17)) { state = 747; ++it; continue; }
                return -1;
            case 747:
                if (MatchCharset(*it, Charset25)) { state = 748; ++it; continue; }
                return -1;
            case 748:
                return 158;
            case 749:
                if (MatchCharset(*it, Charset9)) { state = 750; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 754; ++it; continue; }
                return -1;
            case 750:
                if (MatchCharset(*it, Charset20)) { state = 751; ++it; continue; }
                return -1;
            case 751:
                if (MatchCharset(*it, Charset17)) { state = 752; ++it; continue; }
                return -1;
            case 752:
                if (MatchCharset(*it, Charset25)) { state = 753; ++it; continue; }
                return -1;
            case 753:
                return 156;
            case 754:
                if (MatchCharset(*it, Charset26)) { state = 755; ++it; continue; }
                return -1;
            case 755:
                if (MatchCharset(*it, Charset16)) { state = 756; ++it; continue; }
                return -1;
            case 756:
                if (MatchCharset(*it, Charset17)) { state = 757; ++it; continue; }
                return -1;
            case 757:
                if (MatchCharset(*it, Charset11)) { state = 758; ++it; continue; }
                return -1;
            case 758:
                return 157;
            case 759:
                if (MatchCharset(*it, Charset10)) { state = 760; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 767; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 769; ++it; continue; }
                return -1;
            case 760:
                if (MatchCharset(*it, Charset32)) { state = 761; ++it; continue; }
                return -1;
            case 761:
                if (MatchCharset(*it, Charset24)) { state = 762; ++it; continue; }
                return -1;
            case 762:
                if (MatchCharset(*it, Charset18)) { state = 763; ++it; continue; }
                return -1;
            case 763:
                if (MatchCharset(*it, Charset16)) { state = 764; ++it; continue; }
                return -1;
            case 764:
                if (MatchCharset(*it, Charset25)) { state = 765; ++it; continue; }
                return -1;
            case 765:
                if (MatchCharset(*it, Charset15)) { state = 766; ++it; continue; }
                return -1;
            case 766:
                return 160;
            case 767:
                if (MatchCharset(*it, Charset14)) { state = 768; ++it; continue; }
                return -1;
            case 768:
                return 161;
            case 769:
                if (MatchCharset(*it, Charset11)) { state = 770; ++it; continue; }
                return -1;
            case 770:
                if (MatchCharset(*it, Charset30)) { state = 771; ++it; continue; }
                return -1;
            case 771:
                if (MatchCharset(*it, Charset8)) { state = 772; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 781; ++it; continue; }
                return -1;
            case 772:
                if (MatchCharset(*it, Charset19)) { state = 773; ++it; continue; }
                return -1;
            case 773:
                if (MatchCharset(*it, Charset11)) { state = 774; ++it; continue; }
                return -1;
            case 774:
                if (MatchCharset(*it, Charset30)) { state = 775; ++it; continue; }
                return -1;
            case 775:
                if (MatchCharset(*it, Charset2)) { state = 776; ++it; continue; }
                return -1;
            case 776:
                if (MatchCharset(*it, Charset26)) { state = 777; ++it; continue; }
                return -1;
            case 777:
                if (MatchCharset(*it, Charset11)) { state = 778; ++it; continue; }
                return -1;
            case 778:
                if (MatchCharset(*it, Charset14)) { state = 779; ++it; continue; }
                return -1;
            case 779:
                if (MatchCharset(*it, Charset12)) { state = 780; ++it; continue; }
                return -1;
            case 780:
                return 162;
            case 781:
                if (MatchCharset(*it, Charset8)) { state = 782; ++it; continue; }
                return -1;
            case 782:
                if (MatchCharset(*it, Charset23)) { state = 783; ++it; continue; }
                return -1;
            case 783:
                if (MatchCharset(*it, Charset32)) { state = 784; ++it; continue; }
                return -1;
            case 784:
                if (MatchCharset(*it, Charset15)) { state = 785; ++it; continue; }
                return -1;
            case 785:
                if (MatchCharset(*it, Charset8)) { state = 786; ++it; continue; }
                return -1;
            case 786:
                if (MatchCharset(*it, Charset18)) { state = 787; ++it; continue; }
                return -1;
            case 787:
                return 163;
            case 788:
                if (MatchCharset(*it, Charset7)) { state = 789; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 790; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 796; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 801; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 828; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 847; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 867; ++it; continue; }
                return 164;
            case 789:
                if (MatchCharset(*it, Charset7)) { state = 789; ++it; continue; }
                return 178;
            case 790:
                if (MatchCharset(*it, Charset10)) { state = 791; ++it; continue; }
                return -1;
            case 791:
                if (MatchCharset(*it, Charset23)) { state = 792; ++it; continue; }
                return -1;
            case 792:
                if (MatchCharset(*it, Charset20)) { state = 793; ++it; continue; }
                return -1;
            case 793:
                if (MatchCharset(*it, Charset17)) { state = 794; ++it; continue; }
                return -1;
            case 794:
                if (MatchCharset(*it, Charset17)) { state = 795; ++it; continue; }
                return -1;
            case 795:
                return 181;
            case 796:
                if (MatchCharset(*it, Charset24)) { state = 797; ++it; continue; }
                return -1;
            case 797:
                if (MatchCharset(*it, Charset25)) { state = 798; ++it; continue; }
                return -1;
            case 798:
                if (MatchCharset(*it, Charset16)) { state = 799; ++it; continue; }
                return -1;
            case 799:
                if (MatchCharset(*it, Charset10)) { state = 800; ++it; continue; }
                return -1;
            case 800:
                return 182;
            case 801:
                if (MatchCharset(*it, Charset10)) { state = 802; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 804; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 812; ++it; continue; }
                return -1;
            case 802:
                if (MatchCharset(*it, Charset12)) { state = 803; ++it; continue; }
                return -1;
            case 803:
                return 165;
            case 804:
                if (MatchCharset(*it, Charset16)) { state = 805; ++it; continue; }
                return -1;
            case 805:
                if (MatchCharset(*it, Charset10)) { state = 806; ++it; continue; }
                return -1;
            case 806:
                if (MatchCharset(*it, Charset30)) { state = 807; ++it; continue; }
                return 166;
            case 807:
                if (MatchCharset(*it, Charset24)) { state = 808; ++it; continue; }
                return -1;
            case 808:
                if (MatchCharset(*it, Charset15)) { state = 809; ++it; continue; }
                return -1;
            case 809:
                if (MatchCharset(*it, Charset20)) { state = 810; ++it; continue; }
                return -1;
            case 810:
                if (MatchCharset(*it, Charset21)) { state = 811; ++it; continue; }
                return -1;
            case 811:
                return 167;
            case 812:
                if (MatchCharset(*it, Charset25)) { state = 813; ++it; continue; }
                return -1;
            case 813:
                if (MatchCharset(*it, Charset12)) { state = 814; ++it; continue; }
                return -1;
            case 814:
                if (MatchCharset(*it, Charset23)) { state = 815; ++it; continue; }
                return -1;
            case 815:
                if (MatchCharset(*it, Charset30)) { state = 816; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 822; ++it; continue; }
                return -1;
            case 816:
                if (MatchCharset(*it, Charset25)) { state = 817; ++it; continue; }
                return -1;
            case 817:
                if (MatchCharset(*it, Charset15)) { state = 818; ++it; continue; }
                return -1;
            case 818:
                if (MatchCharset(*it, Charset16)) { state = 819; ++it; continue; }
                return -1;
            case 819:
                if (MatchCharset(*it, Charset12)) { state = 820; ++it; continue; }
                return -1;
            case 820:
                if (MatchCharset(*it, Charset13)) { state = 821; ++it; continue; }
                return -1;
            case 821:
                return 168;
            case 822:
                if (MatchCharset(*it, Charset12)) { state = 823; ++it; continue; }
                return -1;
            case 823:
                if (MatchCharset(*it, Charset8)) { state = 824; ++it; continue; }
                return -1;
            case 824:
                if (MatchCharset(*it, Charset17)) { state = 825; ++it; continue; }
                return -1;
            case 825:
                if (MatchCharset(*it, Charset12)) { state = 826; ++it; continue; }
                return -1;
            case 826:
                if (MatchCharset(*it, Charset23)) { state = 827; ++it; continue; }
                return -1;
            case 827:
                return 169;
            case 828:
                if (MatchCharset(*it, Charset11)) { state = 829; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 830; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 836; ++it; continue; }
                return -1;
            case 829:
                return 170;
            case 830:
                if (MatchCharset(*it, Charset10)) { state = 831; ++it; continue; }
                return -1;
            case 831:
                if (MatchCharset(*it, Charset15)) { state = 832; ++it; continue; }
                return -1;
            case 832:
                if (MatchCharset(*it, Charset8)) { state = 833; ++it; continue; }
                return -1;
            case 833:
                if (MatchCharset(*it, Charset19)) { state = 834; ++it; continue; }
                return -1;
            case 834:
                if (MatchCharset(*it, Charset25)) { state = 835; ++it; continue; }
                return -1;
            case 835:
                return 171;
            case 836:
                if (MatchCharset(*it, Charset12)) { state = 837; ++it; continue; }
                return -1;
            case 837:
                if (MatchCharset(*it, Charset20)) { state = 838; ++it; continue; }
                return -1;
            case 838:
                if (MatchCharset(*it, Charset23)) { state = 839; ++it; continue; }
                return -1;
            case 839:
                if (MatchCharset(*it, Charset30)) { state = 840; ++it; continue; }
                return -1;
            case 840:
                if (MatchCharset(*it, Charset24)) { state = 841; ++it; continue; }
                return -1;
            case 841:
                if (MatchCharset(*it, Charset15)) { state = 842; ++it; continue; }
                return -1;
            case 842:
                if (MatchCharset(*it, Charset20)) { state = 843; ++it; continue; }
                return -1;
            case 843:
                if (MatchCharset(*it, Charset27)) { state = 844; ++it; continue; }
                return -1;
            case 844:
                if (MatchCharset(*it, Charset12)) { state = 845; ++it; continue; }
                return -1;
            case 845:
                if (MatchCharset(*it, Charset23)) { state = 846; ++it; continue; }
                return -1;
            case 846:
                return 172;
            case 847:
                if (MatchCharset(*it, Charset19)) { state = 848; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 861; ++it; continue; }
                return -1;
            case 848:
                if (MatchCharset(*it, Charset11)) { state = 849; ++it; continue; }
                return -1;
            case 849:
                if (MatchCharset(*it, Charset30)) { state = 850; ++it; continue; }
                return 173;
            case 850:
                if (MatchCharset(*it, Charset9)) { state = 851; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 856; ++it; continue; }
                return -1;
            case 851:
                if (MatchCharset(*it, Charset17)) { state = 852; ++it; continue; }
                return -1;
            case 852:
                if (MatchCharset(*it, Charset8)) { state = 853; ++it; continue; }
                return -1;
            case 853:
                if (MatchCharset(*it, Charset24)) { state = 854; ++it; continue; }
                return -1;
            case 854:
                if (MatchCharset(*it, Charset25)) { state = 855; ++it; continue; }
                return -1;
            case 855:
                return 174;
            case 856:
                if (MatchCharset(*it, Charset26)) { state = 857; ++it; continue; }
                return -1;
            case 857:
                if (MatchCharset(*it, Charset16)) { state = 858; ++it; continue; }
                return -1;
            case 858:
                if (MatchCharset(*it, Charset17)) { state = 859; ++it; continue; }
                return -1;
            case 859:
                if (MatchCharset(*it, Charset11)) { state = 860; ++it; continue; }
                return -1;
            case 860:
                return 175;
            case 861:
                if (MatchCharset(*it, Charset10)) { state = 862; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 863; ++it; continue; }
                return -1;
            case 862:
                return 176;
            case 863:
                if (MatchCharset(*it, Charset16)) { state = 864; ++it; continue; }
                return -1;
            case 864:
                if (MatchCharset(*it, Charset17)) { state = 865; ++it; continue; }
                return -1;
            case 865:
                if (MatchCharset(*it, Charset12)) { state = 866; ++it; continue; }
                return -1;
            case 866:
                return 177;
            case 867:
                if (MatchCharset(*it, Charset19)) { state = 868; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 870; ++it; continue; }
                return -1;
            case 868:
                if (MatchCharset(*it, Charset32)) { state = 869; ++it; continue; }
                return -1;
            case 869:
                return 179;
            case 870:
                if (MatchCharset(*it, Charset19)) { state = 871; ++it; continue; }
                return -1;
            case 871:
                if (MatchCharset(*it, Charset25)) { state = 872; ++it; continue; }
                return -1;
            case 872:
                if (MatchCharset(*it, Charset8)) { state = 873; ++it; continue; }
                return -1;
            case 873:
                if (MatchCharset(*it, Charset16)) { state = 874; ++it; continue; }
                return -1;
            case 874:
                if (MatchCharset(*it, Charset19)) { state = 875; ++it; continue; }
                return -1;
            case 875:
                return 180;
            case 876:
                if (MatchCharset(*it, Charset8)) { state = 877; ++it; continue; }
                if (MatchCharset(*it, Charset33)) { state = 885; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 891; ++it; continue; }
                return 183;
            case 877:
                if (MatchCharset(*it, Charset31)) { state = 878; ++it; continue; }
                return -1;
            case 878:
                if (MatchCharset(*it, Charset16)) { state = 879; ++it; continue; }
                return -1;
            case 879:
                if (MatchCharset(*it, Charset14)) { state = 880; ++it; continue; }
                return -1;
            case 880:
                if (MatchCharset(*it, Charset8)) { state = 881; ++it; continue; }
                return -1;
            case 881:
                if (MatchCharset(*it, Charset25)) { state = 882; ++it; continue; }
                return -1;
            case 882:
                if (MatchCharset(*it, Charset20)) { state = 883; ++it; continue; }
                return -1;
            case 883:
                if (MatchCharset(*it, Charset23)) { state = 884; ++it; continue; }
                return -1;
            case 884:
                return 184;
            case 885:
                if (MatchCharset(*it, Charset15)) { state = 886; ++it; continue; }
                return -1;
            case 886:
                if (MatchCharset(*it, Charset20)) { state = 887; ++it; continue; }
                return -1;
            case 887:
                if (MatchCharset(*it, Charset26)) { state = 888; ++it; continue; }
                return -1;
            case 888:
                if (MatchCharset(*it, Charset24)) { state = 889; ++it; continue; }
                return -1;
            case 889:
                if (MatchCharset(*it, Charset12)) { state = 890; ++it; continue; }
                return -1;
            case 890:
                return 187;
            case 891:
                if (MatchCharset(*it, Charset23)) { state = 892; ++it; continue; }
                return 185;
            case 892:
                if (MatchCharset(*it, Charset18)) { state = 893; ++it; continue; }
                return -1;
            case 893:
                if (MatchCharset(*it, Charset8)) { state = 894; ++it; continue; }
                return -1;
            case 894:
                if (MatchCharset(*it, Charset17)) { state = 895; ++it; continue; }
                return -1;
            case 895:
                return 186;
            case 896:
                if (MatchCharset(*it, Charset9)) { state = 897; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 903; ++it; continue; }
                return -1;
            case 897:
                if (MatchCharset(*it, Charset12)) { state = 898; ++it; continue; }
                return -1;
            case 898:
                if (MatchCharset(*it, Charset17)) { state = 899; ++it; continue; }
                return -1;
            case 899:
                if (MatchCharset(*it, Charset16)) { state = 900; ++it; continue; }
                return -1;
            case 900:
                if (MatchCharset(*it, Charset24)) { state = 901; ++it; continue; }
                return -1;
            case 901:
                if (MatchCharset(*it, Charset32)) { state = 902; ++it; continue; }
                return -1;
            case 902:
                return 188;
            case 903:
                if (MatchCharset(*it, Charset25)) { state = 904; ++it; continue; }
                return -1;
            case 904:
                if (MatchCharset(*it, Charset38)) { state = 905; ++it; continue; }
                return -1;
            case 905:
                if (MatchCharset(*it, Charset35)) { state = 906; ++it; continue; }
                return -1;
            case 906:
                if (MatchCharset(*it, Charset30)) { state = 907; ++it; continue; }
                return -1;
            case 907:
                if (MatchCharset(*it, Charset9)) { state = 908; ++it; continue; }
                return -1;
            case 908:
                if (MatchCharset(*it, Charset20)) { state = 909; ++it; continue; }
                return -1;
            case 909:
                if (MatchCharset(*it, Charset8)) { state = 910; ++it; continue; }
                return -1;
            case 910:
                if (MatchCharset(*it, Charset25)) { state = 911; ++it; continue; }
                return -1;
            case 911:
                return 189;
            case 912:
                if (MatchCharset(*it, Charset23)) { state = 913; ++it; continue; }
                if (MatchCharset(*it, Charset6)) { state = 919; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 929; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 972; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 979; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 987; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 994; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 1035; ++it; continue; }
                return -1;
            case 913:
                if (MatchCharset(*it, Charset12)) { state = 914; ++it; continue; }
                return -1;
            case 914:
                if (MatchCharset(*it, Charset17)) { state = 915; ++it; continue; }
                return -1;
            case 915:
                if (MatchCharset(*it, Charset8)) { state = 916; ++it; continue; }
                return -1;
            case 916:
                if (MatchCharset(*it, Charset25)) { state = 917; ++it; continue; }
                return -1;
            case 917:
                if (MatchCharset(*it, Charset12)) { state = 918; ++it; continue; }
                return -1;
            case 918:
                return 211;
            case 919:
                if (MatchCharset(*it, Charset23)) { state = 920; ++it; continue; }
                return -1;
            case 920:
                if (MatchCharset(*it, Charset8)) { state = 921; ++it; continue; }
                return -1;
            case 921:
                if (MatchCharset(*it, Charset18)) { state = 922; ++it; continue; }
                return -1;
            case 922:
                if (MatchCharset(*it, Charset16)) { state = 923; ++it; continue; }
                return -1;
            case 923:
                if (MatchCharset(*it, Charset11)) { state = 924; ++it; continue; }
                return -1;
            case 924:
                if (MatchCharset(*it, Charset30)) { state = 925; ++it; continue; }
                return -1;
            case 925:
                if (MatchCharset(*it, Charset12)) { state = 926; ++it; continue; }
                return -1;
            case 926:
                if (MatchCharset(*it, Charset19)) { state = 927; ++it; continue; }
                return -1;
            case 927:
                if (MatchCharset(*it, Charset25)) { state = 928; ++it; continue; }
                return -1;
            case 928:
                return 215;
            case 929:
                if (MatchCharset(*it, Charset11)) { state = 930; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 938; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 951; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 959; ++it; continue; }
                return -1;
            case 930:
                if (MatchCharset(*it, Charset11)) { state = 931; ++it; continue; }
                return -1;
            case 931:
                if (MatchCharset(*it, Charset12)) { state = 932; ++it; continue; }
                return -1;
            case 932:
                if (MatchCharset(*it, Charset11)) { state = 933; ++it; continue; }
                return -1;
            case 933:
                if (MatchCharset(*it, Charset10)) { state = 934; ++it; continue; }
                return -1;
            case 934:
                if (MatchCharset(*it, Charset12)) { state = 935; ++it; continue; }
                return -1;
            case 935:
                if (MatchCharset(*it, Charset17)) { state = 936; ++it; continue; }
                return -1;
            case 936:
                if (MatchCharset(*it, Charset17)) { state = 937; ++it; continue; }
                return -1;
            case 937:
                return 190;
            case 938:
                if (MatchCharset(*it, Charset19)) { state = 939; ++it; continue; }
                return -1;
            case 939:
                if (MatchCharset(*it, Charset30)) { state = 940; ++it; continue; }
                return -1;
            case 940:
                if (MatchCharset(*it, Charset23)) { state = 941; ++it; continue; }
                return -1;
            case 941:
                if (MatchCharset(*it, Charset12)) { state = 942; ++it; continue; }
                return -1;
            case 942:
                if (MatchCharset(*it, Charset13)) { state = 943; ++it; continue; }
                return -1;
            case 943:
                if (MatchCharset(*it, Charset17)) { state = 944; ++it; continue; }
                return -1;
            case 944:
                if (MatchCharset(*it, Charset12)) { state = 945; ++it; continue; }
                return -1;
            case 945:
                if (MatchCharset(*it, Charset10)) { state = 946; ++it; continue; }
                return -1;
            case 946:
                if (MatchCharset(*it, Charset25)) { state = 947; ++it; continue; }
                return -1;
            case 947:
                if (MatchCharset(*it, Charset16)) { state = 948; ++it; continue; }
                return -1;
            case 948:
                if (MatchCharset(*it, Charset20)) { state = 949; ++it; continue; }
                return -1;
            case 949:
                if (MatchCharset(*it, Charset19)) { state = 950; ++it; continue; }
                return -1;
            case 950:
                return 191;
            case 951:
                if (MatchCharset(*it, Charset15)) { state = 952; ++it; continue; }
                return -1;
            case 952:
                if (MatchCharset(*it, Charset13)) { state = 953; ++it; continue; }
                return -1;
            case 953:
                if (MatchCharset(*it, Charset16)) { state = 954; ++it; continue; }
                return -1;
            case 954:
                if (MatchCharset(*it, Charset19)) { state = 955; ++it; continue; }
                return -1;
            case 955:
                if (MatchCharset(*it, Charset11)) { state = 956; ++it; continue; }
                return -1;
            case 956:
                if (MatchCharset(*it, Charset12)) { state = 957; ++it; continue; }
                return -1;
            case 957:
                if (MatchCharset(*it, Charset23)) { state = 958; ++it; continue; }
                return -1;
            case 958:
                return 194;
            case 959:
                if (MatchCharset(*it, Charset8)) { state = 960; ++it; continue; }
                if (MatchCharset(*it, Charset32)) { state = 965; ++it; continue; }
                return -1;
            case 960:
                if (MatchCharset(*it, Charset17)) { state = 961; ++it; continue; }
                return -1;
            case 961:
                if (MatchCharset(*it, Charset6)) { state = 962; ++it; continue; }
                return -1;
            case 962:
                if (MatchCharset(*it, Charset34)) { state = 963; ++it; continue; }
                return -1;
            case 963:
                if (MatchCharset(*it, Charset12)) { state = 964; ++it; continue; }
                return -1;
            case 964:
                return 192;
            case 965:
                if (MatchCharset(*it, Charset16)) { state = 966; ++it; continue; }
                return -1;
            case 966:
                if (MatchCharset(*it, Charset19)) { state = 967; ++it; continue; }
                return -1;
            case 967:
                if (MatchCharset(*it, Charset14)) { state = 968; ++it; continue; }
                return -1;
            case 968:
                if (MatchCharset(*it, Charset17)) { state = 969; ++it; continue; }
                return -1;
            case 969:
                if (MatchCharset(*it, Charset20)) { state = 970; ++it; continue; }
                return -1;
            case 970:
                if (MatchCharset(*it, Charset25)) { state = 971; ++it; continue; }
                return -1;
            case 971:
                return 193;
            case 972:
                if (MatchCharset(*it, Charset6)) { state = 973; ++it; continue; }
                return -1;
            case 973:
                if (MatchCharset(*it, Charset24)) { state = 974; ++it; continue; }
                return -1;
            case 974:
                if (MatchCharset(*it, Charset16)) { state = 975; ++it; continue; }
                return 195;
            case 975:
                if (MatchCharset(*it, Charset10)) { state = 976; ++it; continue; }
                return -1;
            case 976:
                if (MatchCharset(*it, Charset8)) { state = 977; ++it; continue; }
                return -1;
            case 977:
                if (MatchCharset(*it, Charset17)) { state = 978; ++it; continue; }
                return -1;
            case 978:
                return 196;
            case 979:
                if (MatchCharset(*it, Charset21)) { state = 980; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 983; ++it; continue; }
                return -1;
            case 980:
                if (MatchCharset(*it, Charset12)) { state = 981; ++it; continue; }
                return -1;
            case 981:
                if (MatchCharset(*it, Charset23)) { state = 982; ++it; continue; }
                return -1;
            case 982:
                return 197;
            case 983:
                if (MatchCharset(*it, Charset8)) { state = 984; ++it; continue; }
                return -1;
            case 984:
                if (MatchCharset(*it, Charset25)) { state = 985; ++it; continue; }
                return -1;
            case 985:
                if (MatchCharset(*it, Charset12)) { state = 986; ++it; continue; }
                return -1;
            case 986:
                return 198;
            case 987:
                if (MatchCharset(*it, Charset8)) { state = 988; ++it; continue; }
                return -1;
            case 988:
                if (MatchCharset(*it, Charset16)) { state = 989; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 992; ++it; continue; }
                return -1;
            case 989:
                if (MatchCharset(*it, Charset19)) { state = 990; ++it; continue; }
                return -1;
            case 990:
                if (MatchCharset(*it, Charset24)) { state = 991; ++it; continue; }
                return -1;
            case 991:
                return 199;
            case 992:
                if (MatchCharset(*it, Charset12)) { state = 993; ++it; continue; }
                return -1;
            case 993:
                return 200;
            case 994:
                if (MatchCharset(*it, Charset23)) { state = 995; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 999; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 1003; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 1011; ++it; continue; }
                return -1;
            case 995:
                if (MatchCharset(*it, Charset25)) { state = 996; ++it; continue; }
                return -1;
            case 996:
                if (MatchCharset(*it, Charset12)) { state = 997; ++it; continue; }
                return -1;
            case 997:
                if (MatchCharset(*it, Charset23)) { state = 998; ++it; continue; }
                return -1;
            case 998:
                return 208;
            case 999:
                if (MatchCharset(*it, Charset16)) { state = 1000; ++it; continue; }
                return -1;
            case 1000:
                if (MatchCharset(*it, Charset20)) { state = 1001; ++it; continue; }
                return -1;
            case 1001:
                if (MatchCharset(*it, Charset19)) { state = 1002; ++it; continue; }
                return -1;
            case 1002:
                return 209;
            case 1003:
                if (MatchCharset(*it, Charset12)) { state = 1004; ++it; continue; }
                return -1;
            case 1004:
                if (MatchCharset(*it, Charset23)) { state = 1005; ++it; continue; }
                return -1;
            case 1005:
                if (MatchCharset(*it, Charset30)) { state = 1006; ++it; continue; }
                return -1;
            case 1006:
                if (MatchCharset(*it, Charset10)) { state = 1007; ++it; continue; }
                return -1;
            case 1007:
                if (MatchCharset(*it, Charset26)) { state = 1008; ++it; continue; }
                return -1;
            case 1008:
                if (MatchCharset(*it, Charset23)) { state = 1009; ++it; continue; }
                return -1;
            case 1009:
                if (MatchCharset(*it, Charset12)) { state = 1010; ++it; continue; }
                return -1;
            case 1010:
                return 210;
            case 1011:
                if (MatchCharset(*it, Charset24)) { state = 1012; ++it; continue; }
                return -1;
            case 1012:
                if (MatchCharset(*it, Charset20)) { state = 1013; ++it; continue; }
                return -1;
            case 1013:
                if (MatchCharset(*it, Charset19)) { state = 1014; ++it; continue; }
                return -1;
            case 1014:
                if (MatchCharset(*it, Charset35)) { state = 1015; ++it; continue; }
                if (MatchCharset(*it, Charset36)) { state = 1016; ++it; continue; }
                if (MatchCharset(*it, Charset37)) { state = 1017; ++it; continue; }
                if (MatchCharset(*it, Charset30)) { state = 1018; ++it; continue; }
                return -1;
            case 1015:
                return 205;
            case 1016:
                return 206;
            case 1017:
                return 207;
            case 1018:
                if (MatchCharset(*it, Charset18)) { state = 1019; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 1025; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 1031; ++it; continue; }
                return -1;
            case 1019:
                if (MatchCharset(*it, Charset12)) { state = 1020; ++it; continue; }
                return -1;
            case 1020:
                if (MatchCharset(*it, Charset11)) { state = 1021; ++it; continue; }
                return -1;
            case 1021:
                if (MatchCharset(*it, Charset16)) { state = 1022; ++it; continue; }
                return -1;
            case 1022:
                if (MatchCharset(*it, Charset26)) { state = 1023; ++it; continue; }
                return -1;
            case 1023:
                if (MatchCharset(*it, Charset18)) { state = 1024; ++it; continue; }
                return -1;
            case 1024:
                return 202;
            case 1025:
                if (MatchCharset(*it, Charset12)) { state = 1026; ++it; continue; }
                return -1;
            case 1026:
                if (MatchCharset(*it, Charset31)) { state = 1027; ++it; continue; }
                return -1;
            case 1027:
                if (MatchCharset(*it, Charset12)) { state = 1028; ++it; continue; }
                return -1;
            case 1028:
                if (MatchCharset(*it, Charset23)) { state = 1029; ++it; continue; }
                return -1;
            case 1029:
                if (MatchCharset(*it, Charset12)) { state = 1030; ++it; continue; }
                return -1;
            case 1030:
                return 203;
            case 1031:
                if (MatchCharset(*it, Charset12)) { state = 1032; ++it; continue; }
                return -1;
            case 1032:
                if (MatchCharset(*it, Charset8)) { state = 1033; ++it; continue; }
                return -1;
            case 1033:
                if (MatchCharset(*it, Charset32)) { state = 1034; ++it; continue; }
                return -1;
            case 1034:
                return 204;
            case 1035:
                if (MatchCharset(*it, Charset6)) { state = 1036; ++it; continue; }
                return -1;
            case 1036:
                if (MatchCharset(*it, Charset10)) { state = 1037; ++it; continue; }
                return -1;
            case 1037:
                if (MatchCharset(*it, Charset15)) { state = 1038; ++it; continue; }
                return -1;
            case 1038:
                if (MatchCharset(*it, Charset20)) { state = 1039; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 1043; ++it; continue; }
                return -1;
            case 1039:
                if (MatchCharset(*it, Charset25)) { state = 1040; ++it; continue; }
                return -1;
            case 1040:
                if (MatchCharset(*it, Charset16)) { state = 1041; ++it; continue; }
                return -1;
            case 1041:
                if (MatchCharset(*it, Charset10)) { state = 1042; ++it; continue; }
                return -1;
            case 1042:
                return 214;
            case 1043:
                if (MatchCharset(*it, Charset10)) { state = 1044; ++it; continue; }
                return -1;
            case 1044:
                if (MatchCharset(*it, Charset30)) { state = 1045; ++it; continue; }
                return 212;
            case 1045:
                if (MatchCharset(*it, Charset24)) { state = 1046; ++it; continue; }
                return -1;
            case 1046:
                if (MatchCharset(*it, Charset15)) { state = 1047; ++it; continue; }
                return -1;
            case 1047:
                if (MatchCharset(*it, Charset20)) { state = 1048; ++it; continue; }
                return -1;
            case 1048:
                if (MatchCharset(*it, Charset10)) { state = 1049; ++it; continue; }
                return -1;
            case 1049:
                if (MatchCharset(*it, Charset32)) { state = 1050; ++it; continue; }
                return -1;
            case 1050:
                return 213;
            case 1051:
                if (MatchCharset(*it, Charset26)) { state = 1052; ++it; continue; }
                return -1;
            case 1052:
                if (MatchCharset(*it, Charset8)) { state = 1053; ++it; continue; }
                return -1;
            case 1053:
                if (MatchCharset(*it, Charset23)) { state = 1054; ++it; continue; }
                return -1;
            case 1054:
                if (MatchCharset(*it, Charset23)) { state = 1055; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1057; ++it; continue; }
                return -1;
            case 1055:
                if (MatchCharset(*it, Charset6)) { state = 1056; ++it; continue; }
                return -1;
            case 1056:
                return 216;
            case 1057:
                if (MatchCharset(*it, Charset12)) { state = 1058; ++it; continue; }
                return -1;
            case 1058:
                if (MatchCharset(*it, Charset23)) { state = 1059; ++it; continue; }
                return -1;
            case 1059:
                if (MatchCharset(*it, Charset18)) { state = 1060; ++it; continue; }
                return -1;
            case 1060:
                if (MatchCharset(*it, Charset8)) { state = 1061; ++it; continue; }
                return -1;
            case 1061:
                if (MatchCharset(*it, Charset24)) { state = 1062; ++it; continue; }
                return -1;
            case 1062:
                if (MatchCharset(*it, Charset25)) { state = 1063; ++it; continue; }
                return -1;
            case 1063:
                if (MatchCharset(*it, Charset12)) { state = 1064; ++it; continue; }
                return -1;
            case 1064:
                if (MatchCharset(*it, Charset23)) { state = 1065; ++it; continue; }
                return -1;
            case 1065:
                return 217;
            case 1066:
                if (MatchCharset(*it, Charset16)) { state = 1067; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 1070; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 1079; ++it; continue; }
                return -1;
            case 1067:
                if (MatchCharset(*it, Charset19)) { state = 1068; ++it; continue; }
                return -1;
            case 1068:
                if (MatchCharset(*it, Charset14)) { state = 1069; ++it; continue; }
                return -1;
            case 1069:
                return 221;
            case 1070:
                if (MatchCharset(*it, Charset8)) { state = 1071; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 1076; ++it; continue; }
                return -1;
            case 1071:
                if (MatchCharset(*it, Charset14)) { state = 1072; ++it; continue; }
                return -1;
            case 1072:
                if (MatchCharset(*it, Charset12)) { state = 1073; ++it; continue; }
                return -1;
            case 1073:
                if (MatchCharset(*it, Charset19)) { state = 1074; ++it; continue; }
                return -1;
            case 1074:
                if (MatchCharset(*it, Charset25)) { state = 1075; ++it; continue; }
                return -1;
            case 1075:
                return 219;
            case 1076:
                if (MatchCharset(*it, Charset16)) { state = 1077; ++it; continue; }
                return -1;
            case 1077:
                if (MatchCharset(*it, Charset10)) { state = 1078; ++it; continue; }
                return -1;
            case 1078:
                return 220;
            case 1079:
                if (MatchCharset(*it, Charset10)) { state = 1080; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 1088; ++it; continue; }
                return -1;
            case 1080:
                if (MatchCharset(*it, Charset32)) { state = 1081; ++it; continue; }
                return -1;
            case 1081:
                if (MatchCharset(*it, Charset30)) { state = 1082; ++it; continue; }
                return -1;
            case 1082:
                if (MatchCharset(*it, Charset9)) { state = 1083; ++it; continue; }
                return -1;
            case 1083:
                if (MatchCharset(*it, Charset17)) { state = 1084; ++it; continue; }
                return -1;
            case 1084:
                if (MatchCharset(*it, Charset8)) { state = 1085; ++it; continue; }
                return -1;
            case 1085:
                if (MatchCharset(*it, Charset24)) { state = 1086; ++it; continue; }
                return -1;
            case 1086:
                if (MatchCharset(*it, Charset25)) { state = 1087; ++it; continue; }
                return -1;
            case 1087:
                return 222;
            case 1088:
                if (MatchCharset(*it, Charset18)) { state = 1089; ++it; continue; }
                return -1;
            case 1089:
                return 223;
            case 1090:
                if (MatchCharset(*it, Charset18)) { state = 1091; ++it; continue; }
                if (MatchCharset(*it, Charset7)) { state = 1094; ++it; continue; }
                if (MatchCharset(*it, Charset22)) { state = 1095; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 1100; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 1106; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 1110; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 1117; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 1130; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 1157; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 1174; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1204; ++it; continue; }
                if (MatchCharset(*it, Charset26)) { state = 1238; ++it; continue; }
                return -1;
            case 1091:
                if (MatchCharset(*it, Charset16)) { state = 1092; ++it; continue; }
                return -1;
            case 1092:
                if (MatchCharset(*it, Charset25)) { state = 1093; ++it; continue; }
                return -1;
            case 1093:
                return 238;
            case 1094:
                if (MatchCharset(*it, Charset7)) { state = 1094; ++it; continue; }
                return 239;
            case 1095:
                if (MatchCharset(*it, Charset26)) { state = 1096; ++it; continue; }
                return -1;
            case 1096:
                if (MatchCharset(*it, Charset16)) { state = 1097; ++it; continue; }
                return -1;
            case 1097:
                if (MatchCharset(*it, Charset23)) { state = 1098; ++it; continue; }
                return -1;
            case 1098:
                if (MatchCharset(*it, Charset12)) { state = 1099; ++it; continue; }
                return -1;
            case 1099:
                return 246;
            case 1100:
                if (MatchCharset(*it, Charset10)) { state = 1101; ++it; continue; }
                return -1;
            case 1101:
                if (MatchCharset(*it, Charset23)) { state = 1102; ++it; continue; }
                return -1;
            case 1102:
                if (MatchCharset(*it, Charset20)) { state = 1103; ++it; continue; }
                return -1;
            case 1103:
                if (MatchCharset(*it, Charset17)) { state = 1104; ++it; continue; }
                return -1;
            case 1104:
                if (MatchCharset(*it, Charset17)) { state = 1105; ++it; continue; }
                return -1;
            case 1105:
                return 247;
            case 1106:
                if (MatchCharset(*it, Charset20)) { state = 1107; ++it; continue; }
                return -1;
            case 1107:
                if (MatchCharset(*it, Charset23)) { state = 1108; ++it; continue; }
                return -1;
            case 1108:
                if (MatchCharset(*it, Charset11)) { state = 1109; ++it; continue; }
                return -1;
            case 1109:
                return 259;
            case 1110:
                if (MatchCharset(*it, Charset14)) { state = 1111; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 1113; ++it; continue; }
                return -1;
            case 1111:
                if (MatchCharset(*it, Charset12)) { state = 1112; ++it; continue; }
                return -1;
            case 1112:
                return 224;
            case 1113:
                if (MatchCharset(*it, Charset17)) { state = 1114; ++it; continue; }
                return -1;
            case 1114:
                if (MatchCharset(*it, Charset20)) { state = 1115; ++it; continue; }
                return -1;
            case 1115:
                if (MatchCharset(*it, Charset23)) { state = 1116; ++it; continue; }
                return -1;
            case 1116:
                return 225;
            case 1117:
                if (MatchCharset(*it, Charset15)) { state = 1118; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 1123; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1126; ++it; continue; }
                return -1;
            case 1118:
                if (MatchCharset(*it, Charset20)) { state = 1119; ++it; continue; }
                return -1;
            case 1119:
                if (MatchCharset(*it, Charset17)) { state = 1120; ++it; continue; }
                return -1;
            case 1120:
                if (MatchCharset(*it, Charset8)) { state = 1121; ++it; continue; }
                return -1;
            case 1121:
                if (MatchCharset(*it, Charset23)) { state = 1122; ++it; continue; }
                return -1;
            case 1122:
                return 226;
            case 1123:
                if (MatchCharset(*it, Charset26)) { state = 1124; ++it; continue; }
                return -1;
            case 1124:
                if (MatchCharset(*it, Charset25)) { state = 1125; ++it; continue; }
                return -1;
            case 1125:
                return 227;
            case 1126:
                if (MatchCharset(*it, Charset20)) { state = 1127; ++it; continue; }
                return -1;
            case 1127:
                if (MatchCharset(*it, Charset17)) { state = 1128; ++it; continue; }
                return -1;
            case 1128:
                if (MatchCharset(*it, Charset17)) { state = 1129; ++it; continue; }
                return -1;
            case 1129:
                return 228;
            case 1130:
                if (MatchCharset(*it, Charset17)) { state = 1131; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 1139; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 1146; ++it; continue; }
                return -1;
            case 1131:
                if (MatchCharset(*it, Charset13)) { state = 1132; ++it; continue; }
                return -1;
            case 1132:
                if (MatchCharset(*it, Charset30)) { state = 1133; ++it; continue; }
                return -1;
            case 1133:
                if (MatchCharset(*it, Charset14)) { state = 1134; ++it; continue; }
                return -1;
            case 1134:
                if (MatchCharset(*it, Charset26)) { state = 1135; ++it; continue; }
                return -1;
            case 1135:
                if (MatchCharset(*it, Charset16)) { state = 1136; ++it; continue; }
                return -1;
            case 1136:
                if (MatchCharset(*it, Charset17)) { state = 1137; ++it; continue; }
                return -1;
            case 1137:
                if (MatchCharset(*it, Charset11)) { state = 1138; ++it; continue; }
                return -1;
            case 1138:
                return 232;
            case 1139:
                if (MatchCharset(*it, Charset12)) { state = 1140; ++it; continue; }
                return -1;
            case 1140:
                if (MatchCharset(*it, Charset23)) { state = 1141; ++it; continue; }
                return -1;
            case 1141:
                if (MatchCharset(*it, Charset21)) { state = 1142; ++it; continue; }
                return -1;
            case 1142:
                if (MatchCharset(*it, Charset16)) { state = 1143; ++it; continue; }
                return -1;
            case 1143:
                if (MatchCharset(*it, Charset21)) { state = 1144; ++it; continue; }
                return -1;
            case 1144:
                if (MatchCharset(*it, Charset12)) { state = 1145; ++it; continue; }
                return -1;
            case 1145:
                return 233;
            case 1146:
                if (MatchCharset(*it, Charset23)) { state = 1147; ++it; continue; }
                return -1;
            case 1147:
                if (MatchCharset(*it, Charset30)) { state = 1148; ++it; continue; }
                return 229;
            case 1148:
                if (MatchCharset(*it, Charset12)) { state = 1149; ++it; continue; }
                if (MatchCharset(*it, Charset14)) { state = 1153; ++it; continue; }
                return -1;
            case 1149:
                if (MatchCharset(*it, Charset31)) { state = 1150; ++it; continue; }
                return -1;
            case 1150:
                if (MatchCharset(*it, Charset16)) { state = 1151; ++it; continue; }
                return -1;
            case 1151:
                if (MatchCharset(*it, Charset17)) { state = 1152; ++it; continue; }
                return -1;
            case 1152:
                return 230;
            case 1153:
                if (MatchCharset(*it, Charset20)) { state = 1154; ++it; continue; }
                return -1;
            case 1154:
                if (MatchCharset(*it, Charset20)) { state = 1155; ++it; continue; }
                return -1;
            case 1155:
                if (MatchCharset(*it, Charset11)) { state = 1156; ++it; continue; }
                return -1;
            case 1156:
                return 231;
            case 1157:
                if (MatchCharset(*it, Charset16)) { state = 1158; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1162; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 1170; ++it; continue; }
                return -1;
            case 1158:
                if (MatchCharset(*it, Charset12)) { state = 1159; ++it; continue; }
                return -1;
            case 1159:
                if (MatchCharset(*it, Charset17)) { state = 1160; ++it; continue; }
                return -1;
            case 1160:
                if (MatchCharset(*it, Charset11)) { state = 1161; ++it; continue; }
                return -1;
            case 1161:
                return 234;
            case 1162:
                if (MatchCharset(*it, Charset8)) { state = 1163; ++it; continue; }
                return -1;
            case 1163:
                if (MatchCharset(*it, Charset21)) { state = 1164; ++it; continue; }
                return -1;
            case 1164:
                if (MatchCharset(*it, Charset18)) { state = 1165; ++it; continue; }
                return -1;
            case 1165:
                if (MatchCharset(*it, Charset12)) { state = 1166; ++it; continue; }
                return -1;
            case 1166:
                if (MatchCharset(*it, Charset25)) { state = 1167; ++it; continue; }
                return -1;
            case 1167:
                if (MatchCharset(*it, Charset8)) { state = 1168; ++it; continue; }
                return -1;
            case 1168:
                if (MatchCharset(*it, Charset17)) { state = 1169; ++it; continue; }
                return -1;
            case 1169:
                return 237;
            case 1170:
                if (MatchCharset(*it, Charset23)) { state = 1171; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1173; ++it; continue; }
                return -1;
            case 1171:
                if (MatchCharset(*it, Charset25)) { state = 1172; ++it; continue; }
                return -1;
            case 1172:
                return 235;
            case 1173:
                return 236;
            case 1174:
                if (MatchCharset(*it, Charset8)) { state = 1175; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 1179; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 1194; ++it; continue; }
                return -1;
            case 1175:
                if (MatchCharset(*it, Charset23)) { state = 1176; ++it; continue; }
                return -1;
            case 1176:
                if (MatchCharset(*it, Charset32)) { state = 1177; ++it; continue; }
                return -1;
            case 1177:
                if (MatchCharset(*it, Charset24)) { state = 1178; ++it; continue; }
                return -1;
            case 1178:
                return 240;
            case 1179:
                if (MatchCharset(*it, Charset8)) { state = 1180; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 1182; ++it; continue; }
                if (MatchCharset(*it, Charset17)) { state = 1186; ++it; continue; }
                return -1;
            case 1180:
                if (MatchCharset(*it, Charset23)) { state = 1181; ++it; continue; }
                return -1;
            case 1181:
                return 241;
            case 1182:
                if (MatchCharset(*it, Charset16)) { state = 1183; ++it; continue; }
                return -1;
            case 1183:
                if (MatchCharset(*it, Charset8)) { state = 1184; ++it; continue; }
                return -1;
            case 1184:
                if (MatchCharset(*it, Charset17)) { state = 1185; ++it; continue; }
                return -1;
            case 1185:
                return 242;
            case 1186:
                if (MatchCharset(*it, Charset17)) { state = 1187; ++it; continue; }
                return -1;
            case 1187:
                if (MatchCharset(*it, Charset18)) { state = 1188; ++it; continue; }
                return -1;
            case 1188:
                if (MatchCharset(*it, Charset8)) { state = 1189; ++it; continue; }
                return -1;
            case 1189:
                if (MatchCharset(*it, Charset24)) { state = 1190; ++it; continue; }
                return -1;
            case 1190:
                if (MatchCharset(*it, Charset25)) { state = 1191; ++it; continue; }
                return -1;
            case 1191:
                if (MatchCharset(*it, Charset12)) { state = 1192; ++it; continue; }
                return -1;
            case 1192:
                if (MatchCharset(*it, Charset23)) { state = 1193; ++it; continue; }
                return -1;
            case 1193:
                return 243;
            case 1194:
                if (MatchCharset(*it, Charset23)) { state = 1195; ++it; continue; }
                return -1;
            case 1195:
                if (MatchCharset(*it, Charset16)) { state = 1196; ++it; continue; }
                return -1;
            case 1196:
                if (MatchCharset(*it, Charset25)) { state = 1197; ++it; continue; }
                return -1;
            case 1197:
                if (MatchCharset(*it, Charset30)) { state = 1198; ++it; continue; }
                return 244;
            case 1198:
                if (MatchCharset(*it, Charset14)) { state = 1199; ++it; continue; }
                return -1;
            case 1199:
                if (MatchCharset(*it, Charset26)) { state = 1200; ++it; continue; }
                return -1;
            case 1200:
                if (MatchCharset(*it, Charset16)) { state = 1201; ++it; continue; }
                return -1;
            case 1201:
                if (MatchCharset(*it, Charset17)) { state = 1202; ++it; continue; }
                return -1;
            case 1202:
                if (MatchCharset(*it, Charset11)) { state = 1203; ++it; continue; }
                return -1;
            case 1203:
                return 245;
            case 1204:
                if (MatchCharset(*it, Charset12)) { state = 1205; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 1208; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 1218; ++it; continue; }
                return -1;
            case 1205:
                if (MatchCharset(*it, Charset8)) { state = 1206; ++it; continue; }
                return -1;
            case 1206:
                if (MatchCharset(*it, Charset17)) { state = 1207; ++it; continue; }
                return -1;
            case 1207:
                return 252;
            case 1208:
                if (MatchCharset(*it, Charset9)) { state = 1209; ++it; continue; }
                if (MatchCharset(*it, Charset13)) { state = 1213; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 1215; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1217; ++it; continue; }
                return -1;
            case 1209:
                if (MatchCharset(*it, Charset17)) { state = 1210; ++it; continue; }
                return -1;
            case 1210:
                if (MatchCharset(*it, Charset12)) { state = 1211; ++it; continue; }
                return -1;
            case 1211:
                if (MatchCharset(*it, Charset24)) { state = 1212; ++it; continue; }
                return -1;
            case 1212:
                return 248;
            case 1213:
                if (MatchCharset(*it, Charset13)) { state = 1214; ++it; continue; }
                return -1;
            case 1214:
                return 249;
            case 1215:
                if (MatchCharset(*it, Charset11)) { state = 1216; ++it; continue; }
                return -1;
            case 1216:
                return 250;
            case 1217:
                return 251;
            case 1218:
                if (MatchCharset(*it, Charset19)) { state = 1219; ++it; continue; }
                return -1;
            case 1219:
                if (MatchCharset(*it, Charset12)) { state = 1220; ++it; continue; }
                return -1;
            case 1220:
                if (MatchCharset(*it, Charset30)) { state = 1221; ++it; continue; }
                if (MatchCharset(*it, Charset10)) { state = 1226; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1234; ++it; continue; }
                return 253;
            case 1221:
                if (MatchCharset(*it, Charset24)) { state = 1222; ++it; continue; }
                return -1;
            case 1222:
                if (MatchCharset(*it, Charset32)) { state = 1223; ++it; continue; }
                return -1;
            case 1223:
                if (MatchCharset(*it, Charset16)) { state = 1224; ++it; continue; }
                return -1;
            case 1224:
                if (MatchCharset(*it, Charset19)) { state = 1225; ++it; continue; }
                return -1;
            case 1225:
                return 254;
            case 1226:
                if (MatchCharset(*it, Charset20)) { state = 1227; ++it; continue; }
                return -1;
            case 1227:
                if (MatchCharset(*it, Charset23)) { state = 1228; ++it; continue; }
                return -1;
            case 1228:
                if (MatchCharset(*it, Charset23)) { state = 1229; ++it; continue; }
                return -1;
            case 1229:
                if (MatchCharset(*it, Charset16)) { state = 1230; ++it; continue; }
                return -1;
            case 1230:
                if (MatchCharset(*it, Charset11)) { state = 1231; ++it; continue; }
                return -1;
            case 1231:
                if (MatchCharset(*it, Charset20)) { state = 1232; ++it; continue; }
                return -1;
            case 1232:
                if (MatchCharset(*it, Charset23)) { state = 1233; ++it; continue; }
                return -1;
            case 1233:
                return 255;
            case 1234:
                if (MatchCharset(*it, Charset20)) { state = 1235; ++it; continue; }
                return -1;
            case 1235:
                if (MatchCharset(*it, Charset20)) { state = 1236; ++it; continue; }
                return -1;
            case 1236:
                if (MatchCharset(*it, Charset18)) { state = 1237; ++it; continue; }
                return -1;
            case 1237:
                return 256;
            case 1238:
                if (MatchCharset(*it, Charset16)) { state = 1239; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 1245; ++it; continue; }
                return -1;
            case 1239:
                if (MatchCharset(*it, Charset10)) { state = 1240; ++it; continue; }
                return -1;
            case 1240:
                if (MatchCharset(*it, Charset16)) { state = 1241; ++it; continue; }
                return -1;
            case 1241:
                if (MatchCharset(*it, Charset11)) { state = 1242; ++it; continue; }
                return -1;
            case 1242:
                if (MatchCharset(*it, Charset8)) { state = 1243; ++it; continue; }
                return -1;
            case 1243:
                if (MatchCharset(*it, Charset17)) { state = 1244; ++it; continue; }
                return -1;
            case 1244:
                return 257;
            case 1245:
                if (MatchCharset(*it, Charset18)) { state = 1246; ++it; continue; }
                return -1;
            case 1246:
                if (MatchCharset(*it, Charset20)) { state = 1247; ++it; continue; }
                return -1;
            case 1247:
                if (MatchCharset(*it, Charset19)) { state = 1248; ++it; continue; }
                return -1;
            case 1248:
                return 258;
            case 1249:
                if (MatchCharset(*it, Charset8)) { state = 1250; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 1255; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 1260; ++it; continue; }
                if (MatchCharset(*it, Charset15)) { state = 1270; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 1290; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1307; ++it; continue; }
                return -1;
            case 1250:
                if (MatchCharset(*it, Charset31)) { state = 1251; ++it; continue; }
                return -1;
            case 1251:
                if (MatchCharset(*it, Charset12)) { state = 1252; ++it; continue; }
                return -1;
            case 1252:
                if (MatchCharset(*it, Charset23)) { state = 1253; ++it; continue; }
                return -1;
            case 1253:
                if (MatchCharset(*it, Charset19)) { state = 1254; ++it; continue; }
                return -1;
            case 1254:
                return 260;
            case 1255:
                if (MatchCharset(*it, Charset19)) { state = 1256; ++it; continue; }
                return -1;
            case 1256:
                if (MatchCharset(*it, Charset32)) { state = 1257; ++it; continue; }
                return -1;
            case 1257:
                if (MatchCharset(*it, Charset12)) { state = 1258; ++it; continue; }
                return -1;
            case 1258:
                if (MatchCharset(*it, Charset23)) { state = 1259; ++it; continue; }
                return -1;
            case 1259:
                return 266;
            case 1260:
                if (MatchCharset(*it, Charset8)) { state = 1261; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 1266; ++it; continue; }
                return -1;
            case 1261:
                if (MatchCharset(*it, Charset10)) { state = 1262; ++it; continue; }
                return -1;
            case 1262:
                if (MatchCharset(*it, Charset15)) { state = 1263; ++it; continue; }
                return -1;
            case 1263:
                if (MatchCharset(*it, Charset12)) { state = 1264; ++it; continue; }
                return -1;
            case 1264:
                if (MatchCharset(*it, Charset23)) { state = 1265; ++it; continue; }
                return -1;
            case 1265:
                return 261;
            case 1266:
                if (MatchCharset(*it, Charset21)) { state = 1267; ++it; continue; }
                return -1;
            case 1267:
                if (MatchCharset(*it, Charset17)) { state = 1268; ++it; continue; }
                return -1;
            case 1268:
                if (MatchCharset(*it, Charset12)) { state = 1269; ++it; continue; }
                return -1;
            case 1269:
                return 262;
            case 1270:
                if (MatchCharset(*it, Charset12)) { state = 1271; ++it; continue; }
                if (MatchCharset(*it, Charset20)) { state = 1277; ++it; continue; }
                if (MatchCharset(*it, Charset23)) { state = 1286; ++it; continue; }
                return -1;
            case 1271:
                if (MatchCharset(*it, Charset30)) { state = 1272; ++it; continue; }
                return -1;
            case 1272:
                if (MatchCharset(*it, Charset24)) { state = 1273; ++it; continue; }
                return -1;
            case 1273:
                if (MatchCharset(*it, Charset12)) { state = 1274; ++it; continue; }
                return -1;
            case 1274:
                if (MatchCharset(*it, Charset12)) { state = 1275; ++it; continue; }
                return -1;
            case 1275:
                if (MatchCharset(*it, Charset23)) { state = 1276; ++it; continue; }
                return -1;
            case 1276:
                return 263;
            case 1277:
                if (MatchCharset(*it, Charset18)) { state = 1278; ++it; continue; }
                return -1;
            case 1278:
                if (MatchCharset(*it, Charset8)) { state = 1279; ++it; continue; }
                return -1;
            case 1279:
                if (MatchCharset(*it, Charset24)) { state = 1280; ++it; continue; }
                return -1;
            case 1280:
                if (MatchCharset(*it, Charset30)) { state = 1281; ++it; continue; }
                return -1;
            case 1281:
                if (MatchCharset(*it, Charset14)) { state = 1282; ++it; continue; }
                return -1;
            case 1282:
                if (MatchCharset(*it, Charset23)) { state = 1283; ++it; continue; }
                return -1;
            case 1283:
                if (MatchCharset(*it, Charset12)) { state = 1284; ++it; continue; }
                return -1;
            case 1284:
                if (MatchCharset(*it, Charset6)) { state = 1285; ++it; continue; }
                return -1;
            case 1285:
                return 264;
            case 1286:
                if (MatchCharset(*it, Charset20)) { state = 1287; ++it; continue; }
                return -1;
            case 1287:
                if (MatchCharset(*it, Charset19)) { state = 1288; ++it; continue; }
                return -1;
            case 1288:
                if (MatchCharset(*it, Charset12)) { state = 1289; ++it; continue; }
                return -1;
            case 1289:
                return 265;
            case 1290:
                if (MatchCharset(*it, Charset27)) { state = 1291; ++it; continue; }
                if (MatchCharset(*it, Charset5)) { state = 1298; ++it; continue; }
                return -1;
            case 1291:
                if (MatchCharset(*it, Charset19)) { state = 1292; ++it; continue; }
                return -1;
            case 1292:
                if (MatchCharset(*it, Charset30)) { state = 1293; ++it; continue; }
                return -1;
            case 1293:
                if (MatchCharset(*it, Charset15)) { state = 1294; ++it; continue; }
                return -1;
            case 1294:
                if (MatchCharset(*it, Charset8)) { state = 1295; ++it; continue; }
                return -1;
            case 1295:
                if (MatchCharset(*it, Charset17)) { state = 1296; ++it; continue; }
                return -1;
            case 1296:
                if (MatchCharset(*it, Charset17)) { state = 1297; ++it; continue; }
                return -1;
            case 1297:
                return 267;
            case 1298:
                if (MatchCharset(*it, Charset16)) { state = 1299; ++it; continue; }
                return -1;
            case 1299:
                if (MatchCharset(*it, Charset10)) { state = 1300; ++it; continue; }
                return -1;
            case 1300:
                if (MatchCharset(*it, Charset30)) { state = 1301; ++it; continue; }
                return -1;
            case 1301:
                if (MatchCharset(*it, Charset10)) { state = 1302; ++it; continue; }
                return -1;
            case 1302:
                if (MatchCharset(*it, Charset17)) { state = 1303; ++it; continue; }
                return -1;
            case 1303:
                if (MatchCharset(*it, Charset20)) { state = 1304; ++it; continue; }
                return -1;
            case 1304:
                if (MatchCharset(*it, Charset26)) { state = 1305; ++it; continue; }
                return -1;
            case 1305:
                if (MatchCharset(*it, Charset11)) { state = 1306; ++it; continue; }
                return -1;
            case 1306:
                return 268;
            case 1307:
                if (MatchCharset(*it, Charset8)) { state = 1308; ++it; continue; }
                return -1;
            case 1308:
                if (MatchCharset(*it, Charset10)) { state = 1309; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 1313; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 1316; ++it; continue; }
                return -1;
            case 1309:
                if (MatchCharset(*it, Charset32)) { state = 1310; ++it; continue; }
                return -1;
            case 1310:
                if (MatchCharset(*it, Charset12)) { state = 1311; ++it; continue; }
                return -1;
            case 1311:
                if (MatchCharset(*it, Charset23)) { state = 1312; ++it; continue; }
                return -1;
            case 1312:
                return 269;
            case 1313:
                if (MatchCharset(*it, Charset12)) { state = 1314; ++it; continue; }
                return -1;
            case 1314:
                if (MatchCharset(*it, Charset23)) { state = 1315; ++it; continue; }
                return -1;
            case 1315:
                return 270;
            case 1316:
                if (MatchCharset(*it, Charset19)) { state = 1317; ++it; continue; }
                return -1;
            case 1317:
                if (MatchCharset(*it, Charset16)) { state = 1318; ++it; continue; }
                return -1;
            case 1318:
                if (MatchCharset(*it, Charset19)) { state = 1319; ++it; continue; }
                return -1;
            case 1319:
                if (MatchCharset(*it, Charset14)) { state = 1320; ++it; continue; }
                return -1;
            case 1320:
                return 271;
            case 1321:
                if (MatchCharset(*it, Charset19)) { state = 1322; ++it; continue; }
                return -1;
            case 1322:
                if (MatchCharset(*it, Charset10)) { state = 1323; ++it; continue; }
                if (MatchCharset(*it, Charset11)) { state = 1326; ++it; continue; }
                return -1;
            case 1323:
                if (MatchCharset(*it, Charset20)) { state = 1324; ++it; continue; }
                return -1;
            case 1324:
                if (MatchCharset(*it, Charset19)) { state = 1325; ++it; continue; }
                return -1;
            case 1325:
                return 273;
            case 1326:
                if (MatchCharset(*it, Charset12)) { state = 1327; ++it; continue; }
                return -1;
            case 1327:
                if (MatchCharset(*it, Charset23)) { state = 1328; ++it; continue; }
                return -1;
            case 1328:
                if (MatchCharset(*it, Charset27)) { state = 1329; ++it; continue; }
                return -1;
            case 1329:
                if (MatchCharset(*it, Charset8)) { state = 1330; ++it; continue; }
                return -1;
            case 1330:
                if (MatchCharset(*it, Charset25)) { state = 1331; ++it; continue; }
                return -1;
            case 1331:
                if (MatchCharset(*it, Charset12)) { state = 1332; ++it; continue; }
                return -1;
            case 1332:
                if (MatchCharset(*it, Charset23)) { state = 1333; ++it; continue; }
                return -1;
            case 1333:
                return 274;
            case 1334:
                if (MatchCharset(*it, Charset34)) { state = 1335; ++it; continue; }
                if (MatchCharset(*it, Charset8)) { state = 1342; ++it; continue; }
                if (MatchCharset(*it, Charset12)) { state = 1366; ++it; continue; }
                if (MatchCharset(*it, Charset16)) { state = 1390; ++it; continue; }
                return -1;
            case 1335:
                if (MatchCharset(*it, Charset33)) { state = 1336; ++it; continue; }
                return -1;
            case 1336:
                if (MatchCharset(*it, Charset15)) { state = 1337; ++it; continue; }
                return -1;
            case 1337:
                if (MatchCharset(*it, Charset20)) { state = 1338; ++it; continue; }
                return -1;
            case 1338:
                if (MatchCharset(*it, Charset26)) { state = 1339; ++it; continue; }
                return -1;
            case 1339:
                if (MatchCharset(*it, Charset24)) { state = 1340; ++it; continue; }
                return -1;
            case 1340:
                if (MatchCharset(*it, Charset12)) { state = 1341; ++it; continue; }
                return -1;
            case 1341:
                return 289;
            case 1342:
                if (MatchCharset(*it, Charset19)) { state = 1343; ++it; continue; }
                if (MatchCharset(*it, Charset33)) { state = 1345; ++it; continue; }
                if (MatchCharset(*it, Charset25)) { state = 1351; ++it; continue; }
                return -1;
            case 1343:
                if (MatchCharset(*it, Charset11)) { state = 1344; ++it; continue; }
                return -1;
            case 1344:
                return 275;
            case 1345:
                if (MatchCharset(*it, Charset15)) { state = 1346; ++it; continue; }
                return -1;
            case 1346:
                if (MatchCharset(*it, Charset20)) { state = 1347; ++it; continue; }
                return -1;
            case 1347:
                if (MatchCharset(*it, Charset26)) { state = 1348; ++it; continue; }
                return -1;
            case 1348:
                if (MatchCharset(*it, Charset24)) { state = 1349; ++it; continue; }
                return -1;
            case 1349:
                if (MatchCharset(*it, Charset12)) { state = 1350; ++it; continue; }
                return -1;
            case 1350:
                return 279;
            case 1351:
                if (MatchCharset(*it, Charset12)) { state = 1352; ++it; continue; }
                return -1;
            case 1352:
                if (MatchCharset(*it, Charset23)) { state = 1353; ++it; continue; }
                return -1;
            case 1353:
                if (MatchCharset(*it, Charset30)) { state = 1354; ++it; continue; }
                if (MatchCharset(*it, Charset18)) { state = 1360; ++it; continue; }
                return 276;
            case 1354:
                if (MatchCharset(*it, Charset14)) { state = 1355; ++it; continue; }
                return -1;
            case 1355:
                if (MatchCharset(*it, Charset26)) { state = 1356; ++it; continue; }
                return -1;
            case 1356:
                if (MatchCharset(*it, Charset16)) { state = 1357; ++it; continue; }
                return -1;
            case 1357:
                if (MatchCharset(*it, Charset17)) { state = 1358; ++it; continue; }
                return -1;
            case 1358:
                if (MatchCharset(*it, Charset11)) { state = 1359; ++it; continue; }
                return -1;
            case 1359:
                return 277;
            case 1360:
                if (MatchCharset(*it, Charset8)) { state = 1361; ++it; continue; }
                return -1;
            case 1361:
                if (MatchCharset(*it, Charset24)) { state = 1362; ++it; continue; }
                return -1;
            case 1362:
                if (MatchCharset(*it, Charset25)) { state = 1363; ++it; continue; }
                return -1;
            case 1363:
                if (MatchCharset(*it, Charset12)) { state = 1364; ++it; continue; }
                return -1;
            case 1364:
                if (MatchCharset(*it, Charset23)) { state = 1365; ++it; continue; }
                return -1;
            case 1365:
                return 278;
            case 1366:
                if (MatchCharset(*it, Charset8)) { state = 1367; ++it; continue; }
                return -1;
            case 1367:
                if (MatchCharset(*it, Charset32)) { state = 1368; ++it; continue; }
                if (MatchCharset(*it, Charset21)) { state = 1369; ++it; continue; }
                return -1;
            case 1368:
                return 280;
            case 1369:
                if (MatchCharset(*it, Charset20)) { state = 1370; ++it; continue; }
                return -1;
            case 1370:
                if (MatchCharset(*it, Charset19)) { state = 1371; ++it; continue; }
                return -1;
            case 1371:
                if (MatchCharset(*it, Charset30)) { state = 1372; ++it; continue; }
                if (MatchCharset(*it, Charset35)) { state = 1377; ++it; continue; }
                if (MatchCharset(*it, Charset36)) { state = 1381; ++it; continue; }
                if (MatchCharset(*it, Charset24)) { state = 1382; ++it; continue; }
                if (MatchCharset(*it, Charset27)) { state = 1389; ++it; continue; }
                return 281;
            case 1372:
                if (MatchCharset(*it, Charset24)) { state = 1373; ++it; continue; }
                return -1;
            case 1373:
                if (MatchCharset(*it, Charset15)) { state = 1374; ++it; continue; }
                return -1;
            case 1374:
                if (MatchCharset(*it, Charset20)) { state = 1375; ++it; continue; }
                return -1;
            case 1375:
                if (MatchCharset(*it, Charset21)) { state = 1376; ++it; continue; }
                return -1;
            case 1376:
                return 282;
            case 1377:
                if (MatchCharset(*it, Charset20)) { state = 1378; ++it; continue; }
                return -1;
            case 1378:
                if (MatchCharset(*it, Charset23)) { state = 1379; ++it; continue; }
                return -1;
            case 1379:
                if (MatchCharset(*it, Charset36)) { state = 1380; ++it; continue; }
                return -1;
            case 1380:
                return 283;
            case 1381:
                return 284;
            case 1382:
                if (MatchCharset(*it, Charset18)) { state = 1383; ++it; continue; }
                return -1;
            case 1383:
                if (MatchCharset(*it, Charset8)) { state = 1384; ++it; continue; }
                return -1;
            case 1384:
                if (MatchCharset(*it, Charset24)) { state = 1385; ++it; continue; }
                return -1;
            case 1385:
                if (MatchCharset(*it, Charset25)) { state = 1386; ++it; continue; }
                return -1;
            case 1386:
                if (MatchCharset(*it, Charset12)) { state = 1387; ++it; continue; }
                return -1;
            case 1387:
                if (MatchCharset(*it, Charset23)) { state = 1388; ++it; continue; }
                return -1;
            case 1388:
                return 285;
            case 1389:
                return 286;
            case 1390:
                if (MatchCharset(*it, Charset18)) { state = 1391; ++it; continue; }
                if (MatchCharset(*it, Charset19)) { state = 1393; ++it; continue; }
                return -1;
            case 1391:
                if (MatchCharset(*it, Charset21)) { state = 1392; ++it; continue; }
                return -1;
            case 1392:
                return 287;
            case 1393:
                if (MatchCharset(*it, Charset11)) { state = 1394; ++it; continue; }
                return -1;
            case 1394:
                if (MatchCharset(*it, Charset18)) { state = 1395; ++it; continue; }
                return -1;
            case 1395:
                if (MatchCharset(*it, Charset8)) { state = 1396; ++it; continue; }
                return -1;
            case 1396:
                if (MatchCharset(*it, Charset24)) { state = 1397; ++it; continue; }
                return -1;
            case 1397:
                if (MatchCharset(*it, Charset25)) { state = 1398; ++it; continue; }
                return -1;
            case 1398:
                if (MatchCharset(*it, Charset12)) { state = 1399; ++it; continue; }
                return -1;
            case 1399:
                if (MatchCharset(*it, Charset23)) { state = 1400; ++it; continue; }
                return -1;
            case 1400:
                return 288;
            default:
                return -1;
            }
        }

        // TODO: EOF?
        return -1;
    }
}
