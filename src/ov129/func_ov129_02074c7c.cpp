#include "types.h"

extern "C" void *func_ov127_0206a30c(void *self, s32 id);
extern "C" s32 func_ov127_0206c8d4(void *self, s32 x);
extern "C" s32 func_ov127_0206c818(void *self, s32 x);
extern "C" void func_ov127_0206c7f0(void *self);
extern "C" void func_ov127_0206b1ac(void *obj, s32 x, s32 y);
extern "C" void func_ov011_0206c4cc(void *self, s32 x, s32 y, s32 z, s32 s0, s32 s1, s32 s2);
extern "C" void func_ov127_0206c5c0(void *self, void *obj, s32 a, s32 b, s32 c, s32 d);
extern "C" void func_ov127_0206ad18(void *self, void *obj, s32 a, s32 b, s32 c);

struct Unk_ov129_02074c7c_Data {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u32 unk8;
};

struct Unk_ov129_02074c7c_Obj {
    /* 0x0 */ u8 pad0[0x50];
    /* 0x50 */ u8 unk50;
    /* 0x51 */ u8 pad51[0x54 - 0x51];
    /* 0x54 */ Unk_ov129_02074c7c_Data *unk54;
    /* 0x58 */ u8 pad58[0x5c - 0x58];
    /* 0x5c */ void *unk5c;
};

struct Unk_ov129_02074c7c {
    /* 0x0 */ u8 pad0[0x28];
    /* 0x28 */ void *unk28;
    /* 0x2c */ void *unk2c;
    /* 0x30 */ u8 pad30[0x824 - 0x30];
    /* 0x824 */ u8 unk824;
    /* 0x825 */ u8 pad825[0x830 - 0x825];
    /* 0x830 */ void *unk830;
    /* 0x834 */ u8 pad834[0x83c - 0x834];
    /* 0x83c */ u16 unk83c;
    /* 0x83e */ u8 pad83e[0x872 - 0x83e];
    /* 0x872 */ s16 unk872;
    /* 0x874 */ u8 pad874[0x87c - 0x874];
    /* 0x87c */ u8 unk87c;
};

extern "C" Unk_ov129_02074c7c_Data data_02058f84;
extern "C" u16 data_0205afa8;

extern "C" void func_ov129_02074c7c(Unk_ov129_02074c7c *self) {
    s32 i;
    u32 bits;
    Unk_ov129_02074c7c_Obj *obj;
    s32 cam;
    s32 neg;
    Unk_ov129_02074c7c_Obj *o5;
    Unk_ov129_02074c7c_Obj *o6;
    Unk_ov129_02074c7c_Obj *o7;

    for (i = 0; i < 3; i++) {
        obj = (Unk_ov129_02074c7c_Obj *)func_ov127_0206a30c(self->unk28, i + 0x51);
        bits = ((u32)data_02058f84.unk8 << 24) >> 28;
        if (bits & (1 << (self->unk824 * 2))) {
            obj->unk50 |= 0x8;
        } else {
            obj->unk50 &= ~0x8;
        }
    }

    if ((data_0205afa8 & 0x300) == 0 || self->unk87c == 0xa || self->unk87c == 0x11 || self->unk87c == 0x1a) {
        self->unk872 -= 1;
    } else {
        if (data_0205afa8 & 0x200) {
            self->unk872 -= 2;
        }
        if (data_0205afa8 & 0x100) {
            self->unk872 += 2;
        }
    }

    cam = func_ov127_0206c8d4(self->unk830, self->unk83c);
    o5 = (Unk_ov129_02074c7c_Obj *)func_ov127_0206a30c(self->unk28, 0x51);
    o6 = (Unk_ov129_02074c7c_Obj *)func_ov127_0206a30c(self->unk28, 0x52);
    o7 = (Unk_ov129_02074c7c_Obj *)func_ov127_0206a30c(self->unk28, 0x53);
    neg = -func_ov127_0206c818(self->unk2c, cam + 2);
    if (self->unk872 < neg) {
        self->unk872 = 0xc0;
    }
    if (self->unk872 > 0xc0) {
        self->unk872 = neg;
    }

    func_ov127_0206b1ac(o5, 0x20, 0xa8);
    func_ov127_0206b1ac(o6, 0x60, 0xa8);
    func_ov127_0206b1ac(o7, 0xa0, 0xa8);
    func_ov127_0206c7f0(self->unk2c);
    func_ov011_0206c4cc(self->unk2c, cam + 2, self->unk872 + 0x10, 0, 2, 0, 0);

    func_ov127_0206c5c0(self->unk2c, o5->unk5c, 2, 0, 8, 8);
    func_ov127_0206ad18(self->unk28, o5->unk5c, o5->unk54->unk8 + 0x6600000, 0x800, 2);

    func_ov127_0206c5c0(self->unk2c, o6->unk5c, 0xa, 0, 8, 8);
    func_ov127_0206ad18(self->unk28, o6->unk5c, o6->unk54->unk8 + 0x6600000, 0x800, 2);

    func_ov127_0206c5c0(self->unk2c, o7->unk5c, 0x12, 0, 8, 8);
    func_ov127_0206ad18(self->unk28, o7->unk5c, o7->unk54->unk8 + 0x6600000, 0x800, 2);
}
