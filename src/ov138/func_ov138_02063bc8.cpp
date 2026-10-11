#include "types.h"

extern "C" void func_020394a4(void *dst, s32 size);
extern "C" void func_020394e0(void *dst, s32 size);
extern "C" void func_ov138_02064700(void *dst, u32 *src1, u32 *src2, s32 size);

extern "C" void func_ov138_02063bc8(u32 *arr) {
    u32 *p = arr;
    u8 buf[16];
    s32 i;
    u32 val = p[1];
    for (i = 0; i < 16; i++) {
        buf[i] = (u8)(val >> ((i % 4) * 8));
        if (i % 15 == 0) {
            buf[i] ^= 0xff;
        }
    }
    if (p[0] != val) {
        do {
            p--;
        } while (p[0] != val);
    }
    s32 size;
    size = 0;
    while (p[size + 1] != val) {
        size++;
    }
    size *= 4;
    if (size != 0) {
        func_ov138_02064700(buf, p + 1, p + 1, size);
    }
    func_020394a4(p + 1, size);
    func_020394e0(p + 1, size);
}
