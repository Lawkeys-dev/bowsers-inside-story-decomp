#include "types.h"

struct Unk_ov129_0207032c {
    /* 0x000 */ u8 pad000[0x28];
    /* 0x028 */ void* unk28;
    /* 0x02c */ u8 pad02c[0x824 - 0x2c];
    /* 0x824 */ u8 unk824;
    /* 0x825 */ u8 pad825[0x830 - 0x825];
    /* 0x830 */ u8 unk830;
    /* 0x831 */ u8 pad831[0x846 - 0x831];
    /* 0x846 */ s16 unk846;
    /* 0x848 */ u16 unk848;
    /* 0x84a */ u8 pad84a[0x854 - 0x84a];
    /* 0x854 */ void* unk854;
    /* 0x858 */ void* unk858;
};

struct Unk_ov129_Inner {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u32 unk8;
};

struct Unk_ov129_Sub54 {
    /* 0x00 */ u8 pad0[0x54];
    /* 0x54 */ Unk_ov129_Inner* unk54;
    /* 0x58 */ u8 pad58[0x5c - 0x58];
    /* 0x5c */ void* unk5c;
};

struct Unk_ov129_Global {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u32 unk8;
};

extern "C" Unk_ov129_Global data_02058f84;
extern "C" u16 data_0205afa8;

extern "C" s32 func_ov127_0206c8d4(void* p, u16 a);
extern "C" void* func_ov127_0206a30c(void* p, s32 id);
extern "C" s32 func_ov127_0206c818(void* p, s32 a);
extern "C" void func_ov127_0206b1ac(void* p, s32 a, s32 b);
extern "C" void func_ov011_0206c6f4(void* a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern "C" void func_01ff8228(void* p, s32 a, s32 b);
extern "C" void func_02036464(void);
extern "C" u32 func_0201f0bc(void);
extern "C" void func_ov127_0206ad18(void* a, void* b, u32 c, s32 d, s32 e);

extern "C" void func_ov129_0207032c(Unk_ov129_0207032c* self) {
    s32 i;
    u16 keys;
    s32 ret;
    s32 r4;
    Unk_ov129_Sub54* r5;
    u16* r6;

    if (!((1 << (self->unk824 * 2)) & ((data_02058f84.unk8 << 24) >> 28))) {
        return;
    }
    keys = data_0205afa8;
    if (!(keys & 0x300) || self->unk830 == 0xc) {
        self->unk846 -= 1;
    } else {
        if (keys & 0x200) {
            self->unk846 -= 2;
        }
        if (data_0205afa8 & 0x100) {
            self->unk846 += 2;
        }
    }

    r4 = func_ov127_0206c8d4(self->unk858, self->unk848);
    r5 = (Unk_ov129_Sub54*)func_ov127_0206a30c(self->unk28, 0x29);
    ret = func_ov127_0206c818(self->unk854, r4 + 2);
    if (self->unk846 < -ret) {
        self->unk846 = 0xc0;
    }
    if (self->unk846 > 0xc0) {
        self->unk846 = -ret;
    }
    func_ov127_0206b1ac(r5, 0x20, 0xa8);
    r6 = (u16*)r5->unk5c;
    func_ov011_0206c6f4(self->unk854, r4 + 2, r6, self->unk846, 0, 2, 0x20, 2, 1, 1, 1);
    for (i = 0; i < 16; i++) {
        func_01ff8228(&r6[(i << 6) + 0x30], 0, 0x20);
    }
    func_02036464();
    ret = func_0201f0bc();
    func_ov127_0206ad18(self->unk28, r6, ret + r5->unk54->unk8, 0x800, 0);
}
