#include "types.h"

extern "C" u8 data_ov088_020cd414[];
extern "C" u8 data_ov088_020cd41a[];
extern "C" u8 data_ov088_020cd420[];
extern "C" u8 data_ov088_020cd426[];
extern "C" u8 data_ov088_020cd42c[];
extern "C" u8 data_ov088_020cd432[];
extern "C" u8 data_ov088_020cd438[];
extern "C" u8 data_ov088_020cd43e[];
extern "C" u8 data_ov088_020cd444[];
extern "C" u8 data_ov088_020cd44a[];
extern "C" u8 data_ov088_020cd450[];
extern "C" u8 data_ov088_020cd456[];
extern "C" u8 data_ov088_020cd45c[];
extern "C" u8 data_ov088_020cd466[];
extern "C" u8 data_ov088_020cd470[];
extern "C" u8 data_ov088_020cd47a[];
extern "C" u8 data_ov088_020cd484[];
extern "C" u8 data_ov088_020cd48e[];
extern "C" u8 data_ov088_020cd498[];
extern "C" u8 data_ov088_020cd4a2[];
extern "C" u8 data_ov088_020cd4ac[];
extern "C" u8 data_ov088_020cd4b6[];
extern "C" u8 data_ov088_020cd4c0[];
extern "C" u8 data_ov088_020cd4ca[];

// Returns the data address for a lookup index (second argument, biased by +12); out-of-range values map to the default entry.
extern "C" void *func_ov088_020cb0cc(s32 unused, s32 param) {
    switch (param + 12) {
    case 0:
        return data_ov088_020cd456;
    case 1:
        return data_ov088_020cd450;
    case 2:
        return data_ov088_020cd44a;
    case 3:
        return data_ov088_020cd444;
    case 4:
        return data_ov088_020cd43e;
    case 5:
        return data_ov088_020cd438;
    case 6:
        return data_ov088_020cd432;
    case 7:
        return data_ov088_020cd42c;
    case 8:
        return data_ov088_020cd426;
    case 9:
        return data_ov088_020cd420;
    case 10:
        return data_ov088_020cd41a;
    case 11:
        return data_ov088_020cd414;
    case 12:
        return data_ov088_020cd45c;
    case 13:
        return data_ov088_020cd466;
    case 14:
        return data_ov088_020cd470;
    case 15:
        return data_ov088_020cd47a;
    case 16:
        return data_ov088_020cd484;
    case 17:
        return data_ov088_020cd48e;
    case 18:
        return data_ov088_020cd498;
    case 19:
        return data_ov088_020cd4a2;
    case 20:
        return data_ov088_020cd4ac;
    case 21:
        return data_ov088_020cd4b6;
    case 22:
        return data_ov088_020cd4c0;
    default:
        return data_ov088_020cd4ca;
    }
}
