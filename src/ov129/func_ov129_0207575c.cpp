#include "types.h"

struct Unk_ov129_0207575c {
    /* 0x00 */ u8 unk00[0x28];
    /* 0x28 */ void *unk28;
    /* 0x2c */ u8 unk2c[0x870 - 0x2c];
    /* 0x870 */ u16 unk870;
    /* 0x872 */ u8 unk872[0x87c - 0x872];
    /* 0x87c */ u8 unk87c;
};

struct Unk_ov129_Vec {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
};

extern "C" void *func_ov127_0206a30c(void *obj, s32 which);
extern "C" void func_ov127_0206b1c0(void *obj, Unk_ov129_Vec *vec);
extern "C" void func_ov003_0206b2d4(void *obj, s32 a, s32 b, s32 c);

extern "C" u16 data_0205afa8;
extern "C" s16 data_0204b1dc[];
extern "C" Unk_ov129_Vec data_ov129_02075f2c;
extern "C" Unk_ov129_Vec data_ov129_02075f38;

extern "C" void func_ov129_0207575c(Unk_ov129_0207575c *self) {
    s32 special;
    if (self->unk87c == 0xa || self->unk87c == 0x11 || self->unk87c == 0x1a) {
        special = 1;
    } else {
        special = 0;
    }
    void *a = func_ov127_0206a30c(self->unk28, 6);
    void *b = func_ov127_0206a30c(self->unk28, 7);
    s32 x = (s32)(self->unk870 << 16);
    s32 idx = ((x / 64) & 0xffff) >> 4;
    s32 v = data_0204b1dc[idx * 2 + 1];

    if (!(data_0205afa8 & 0x200) || special) {
        if (v > 0) {
            v *= -1;
        }
        Unk_ov129_Vec vec = data_ov129_02075f2c;
        vec.x = (v << 2) + 0x18000;
        func_ov127_0206b1c0(a, &vec);
    } else {
        func_ov003_0206b2d4(a, 1, 0x14, 0xb0);
    }

    if (!(data_0205afa8 & 0x100) || special) {
        if (v < 0) {
            v *= -1;
        }
        Unk_ov129_Vec vec = data_ov129_02075f38;
        vec.x = (v << 2) + 0xe8000;
        func_ov127_0206b1c0(b, &vec);
    } else {
        func_ov003_0206b2d4(b, 1, 0xec, 0xb0);
    }

    self->unk870 += 1;
    self->unk870 &= 0x3f;
}
