#include "types.h"

extern "C" u32 func_ov138_020645e8(void *ctx);
extern "C" void func_ov138_02064634(u8 *table);

extern "C" s32 func_ov138_02064658(void *ctx, u8 *src, u8 *dst, u32 size) {
    u8 table[256];

    if (size & 3) {
        return -1;
    }
    func_ov138_02064634(table);
    for (u32 i = 0; i < size; i += 4) {
        dst[i] = src[i] ^ func_ov138_020645e8(ctx);
        dst[i + 1] = src[i + 1] ^ func_ov138_020645e8(ctx);
        dst[i + 2] = table[src[i + 2]];
        dst[i + 3] = src[i + 3];
    }
    return 0;
}
