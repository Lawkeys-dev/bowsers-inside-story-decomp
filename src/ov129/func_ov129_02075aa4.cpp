#include "types.h"

struct Unk_ov129_02075aa4_Obj {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
};

struct Unk_ov129_02075aa4 {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ void *unk28;
};

extern "C" Unk_ov129_02075aa4_Obj *func_ov127_0206a30c(void *obj, s32 index);
extern "C" void func_ov127_0206b398(void *obj, s32 a1, s32 a2, s32 a3);

extern "C" void func_ov129_02075aa4(Unk_ov129_02075aa4 *self, s32 a1, s32 a2, s32 a3, s32 a4) {
    Unk_ov129_02075aa4_Obj *obj = func_ov127_0206a30c(self->unk28, a1 + 0x13);
    s32 dx = a3 - obj->unk14;
    s32 dy = a4 - obj->unk18;
    s32 i = (u16)(a1 + 0x12);
    s32 end = (u16)(a1 + 0x2e);
    for (; i <= end; i++) {
        void *p = func_ov127_0206a30c(self->unk28, i);
        if (p != NULL) {
            func_ov127_0206b398(p, a2, dx, dy);
        }
    }
}
