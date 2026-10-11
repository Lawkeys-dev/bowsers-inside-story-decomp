#include "types.h"

extern "C" void func_ov138_02064574(void *dst, void *src, s32 size);
extern "C" s32 func_ov138_02064658(void *buf, s32 a, s32 b, s32 c);

extern "C" BOOL func_ov138_02064700(void *src, s32 a, s32 b, s32 c) {
    u8 buf[0x108];
    func_ov138_02064574(buf, src, 0x10);
    return -(func_ov138_02064658(buf, a, b, c) == -1);
}
