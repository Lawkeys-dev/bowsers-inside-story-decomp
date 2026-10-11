#include "types.h"

extern "C" BOOL func_ov138_02064634(u8 *buf) {
    for (s32 i = 0; i < 0x100; i++) {
        u8 v = (u8)i;
        buf[i] = v ^ 1;
    }
    return FALSE;
}
