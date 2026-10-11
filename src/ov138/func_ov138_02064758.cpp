#include "types.h"

extern "C" void func_ov138_02064574(u8 *dst, void *src, u32 size);
extern "C" s32 func_ov138_020646f4(u8 *buf, void *a, void *b, s32 c);

extern "C" s32 func_ov138_02064758(void *src, void *a, void *b, s32 c) {
    u8 buf[0x108];
    func_ov138_02064574(buf, src, 0x10);
    s32 ret = func_ov138_020646f4(buf, a, b, c);
    return -(ret == -1);
}
