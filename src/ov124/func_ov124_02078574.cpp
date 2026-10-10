#include "types.h"

// Counts the non-zero bytes of a w*h rectangle at (x, y) in a byte buffer
extern "C" s32 func_ov124_02078574(u8* buf, s32 stride, s32 unused, s32 x, s32 y, s32 w, s32 h) {
    s32 count = 0;
    for (s32 row = y; row < y + h; row++) {
        for (s32 col = x; col < x + w; col++) {
            if (buf[row * stride + col] != 0) {
                count++;
            }
        }
    }
    return count;
}
