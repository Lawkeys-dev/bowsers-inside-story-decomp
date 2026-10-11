#include "types.h"

struct Unk_ov129_Obj {
    /* 0x000 */ u8 pad000[0x14];
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad018[0xec - 0x18];
    /* 0x0ec */ u8 unkEc;
};

struct Unk_ov129_02074ad0 {
    /* 0x000 */ u8 pad000[0x28];
    /* 0x028 */ Unk_ov129_Obj *unk28;
    /* 0x02c */ u8 pad02c[0x824 - 0x2c];
    /* 0x824 */ u8 unk824;
    /* 0x825 */ u8 pad825;
    /* 0x826 */ u8 unk826;
    /* 0x827 */ u8 pad827[0x83c - 0x827];
    /* 0x83c */ u16 unk83c;
};

extern "C" Unk_ov129_Obj *func_ov127_0206a30c(void *obj, s32 id);
extern "C" void func_ov127_0206b2a0(Unk_ov129_Obj *obj, s32 a, s32 b, s32 c);
extern "C" void func_ov003_0206b2d4(Unk_ov129_Obj *obj, s32 a, s32 b, s32 c);
extern "C" void func_ov129_02074a5c(Unk_ov129_02074ad0 *self, s32 a, s32 b);
extern "C" u16 *func_ov129_0206dfd4(Unk_ov129_02074ad0 *self, u16 val);
extern "C" u8 data_020590a0[];

extern "C" void func_ov129_02074ad0(Unk_ov129_02074ad0 *self) {
    Unk_ov129_Obj *obj;
    u16 x;
    u16 y;
    s32 idx;

    if (!(self->unk826 & 1)) {
        return;
    }
    obj = func_ov127_0206a30c(self->unk28, 0x54);
    if (self->unk824 == 0) {
        func_ov127_0206b2a0(obj, 0xc000, 0x8000, 0x18000);
    } else {
        func_ov127_0206b2a0(obj, 0xc000, 0x80000, 0x18000);
    }

    x = func_ov127_0206a30c(self->unk28, 0x13)->unkEc;
    y = func_ov127_0206a30c(self->unk28, 0x32)->unkEc;

    if (self->unk824 == 0) {
        if (x != 0x1f) {
            x = x + 2;
            y = y - 2;
        } else {
            self->unk826 &= ~1;
        }
    } else {
        if (y != 0x1f) {
            x = x - 2;
            y = y + 2;
        } else {
            self->unk826 &= ~1;
        }
    }

    func_ov129_02074a5c(self, 0, x);
    func_ov129_02074a5c(self, 0x1f, y);

    {
        Unk_ov129_Obj *r7 = func_ov127_0206a30c(self->unk28, 0x5d);
        Unk_ov129_Obj *r5 = func_ov127_0206a30c(self->unk28, 0);
        Unk_ov129_Obj *r4 = func_ov127_0206a30c(self->unk28, 1);

        if (r7->unk14 == -0x30000) {
            func_ov003_0206b2d4(r7, 0x18, 0x40, 0x94);
            func_ov003_0206b2d4(r5, 0x18, 0x0, 0x8c);
            func_ov003_0206b2d4(r4, 0x18, 0x40, 0x8c);
        }
    }

    idx = self->unk824 * 2;
    self->unk83c = func_ov129_0206dfd4(self, *(u16 *)&data_020590a0[idx * 0x7ec])[0];
}
