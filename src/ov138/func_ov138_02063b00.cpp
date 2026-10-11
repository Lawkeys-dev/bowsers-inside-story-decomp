#include "types.h"

extern "C" void func_ov138_02064758(u8* buf, u32* p, u32* p2, s32 offset);
extern "C" void func_020394a4(u32* p, s32 offset);
extern "C" void func_020394e0(u32* p, s32 offset);

extern "C" void func_ov138_02063b00(u32* p) {
    u8 buf[16];
    s32 i;
    u32 key = p[-1];

    for (i = 0; i < 16; i++) {
        buf[i] = key >> ((i % 4) * 8);
        if (i % 15 == 0) {
            buf[i] ^= 0xff;
        }
    }

    s32 idx = 0;
    if (key != p[0]) {
        do {
            idx++;
        } while (key != p[idx]);
    }

    idx = idx * 4;
    if (idx != 0) {
        func_ov138_02064758(buf, p, p, idx);
    }
    func_020394a4(p, idx);
    func_020394e0(p, idx);
}
