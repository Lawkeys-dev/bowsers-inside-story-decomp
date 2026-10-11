#include "types.h"

// Vtable at offset 0x00 (virtual methods, slots 0x00..0x10).
struct Unk_ov129_0206db28_28 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();

    /* 0x04 */ u8 pad04[0xcc];
    /* 0xd0 */ u32 unkD0;
};

struct Unk_ov129_0206db28 {
    /* 0x00 */ void *vtbl;
    /* 0x04 */ u8 pad04[0x24];
    /* 0x28 */ Unk_ov129_0206db28_28 *unk28;
    /* 0x2c */ u32 unk2c;
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u8 pad38[0x7ec];
    /* 0x824 */ u8 unk824;
    /* 0x825 */ u8 unk825;
    /* 0x826 */ u8 unk826;
    /* 0x828 */ void *unk828;
    /* 0x82c */ void *unk82c;
};

extern "C" void func_0201a39c();
extern "C" void func_02038374(s32);
extern "C" void func_02038344(s32);
extern "C" void *func_0201a138(s32, s32, s32, s32);
extern "C" void *func_ov001_02069820(void *, s32, s32, s32, s32);
extern "C" void func_0200a424(void *);
extern "C" void func_0201a8ec();
extern "C" void func_0201bf34(void *, s32, s32, s32, s32);
extern "C" void func_0201bdfc(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_ov129_0206e054(void *);
extern "C" void *func_ov129_0206e378(void *, s32, s32, void *);

extern "C" u8 data_ov129_020760ac[];
extern "C" u32 data_ov129_02076008[];
extern "C" u8 data_ov129_02075ca8[];
extern "C" u32 data_ov129_02076018[];

// TODO: 99.05%. Remaining: the compiler emits a dead `mov r3, #0` before `mov r10, r0` (the original
// materialises a zero ahead of the copy of self). Tried without success: a u32 zero local, a chained
// store `a = b = c = d = 0`, a zero local used by the stores, and literal zeros.
extern "C" Unk_ov129_0206db28 *func_ov129_0206db28(Unk_ov129_0206db28 *self) {
    s32 i;
    void *p;
    Unk_ov129_0206db28_28 *obj;
    BOOL done;

    func_0201a39c();
    self->vtbl = data_ov129_020760ac;
    func_02038374(4);
    func_02038344(1);
    self->unk826 = 0;
    self->unk34 = 0;
    self->unk824 = 0;
    self->unk825 = 0;
    func_ov129_0206e054(self);
    p = func_0201a138(0x210c, 0, 0, 0);
    if (p != NULL) {
        p = func_ov001_02069820(p, 8, 0, 1, 0);
    }
    self->unk28 = (Unk_ov129_0206db28_28 *)p;
    p = func_0201a138(0x48, 0, 0, 0);
    if (p != NULL) {
        func_0200a424(p);
    }
    self->unk828 = p;
    p = func_0201a138(0x28, 0, 0, 0);
    if (p != NULL) {
        p = func_ov129_0206e378(p, 8, 0, self);
    }
    self->unk82c = p;
    func_0201a8ec();
    func_0201bf34(self->unk28, 1, data_ov129_02076008[5], (s32)data_ov129_02075ca8, 0);
    for (i = 0; i < 6; i++) {
        if (i != 1) {
            func_0201bdfc(self->unk28, (s16)i, data_ov129_02076018[i], 0, 0, 0, 0, 0, 0);
            obj = self->unk28;
            done = (obj->unkD0 == 0) ? TRUE : FALSE;
            if (done == FALSE) {
                do {
                    obj->v10();
                    done = (obj->unkD0 == 0) ? TRUE : FALSE;
                } while (done == FALSE);
            }
        }
    }
    self->unk2c = 0;
    self->unk30 = 0;
    return self;
}
