#include "types.h"

struct Unk_ov088_020ca0c4_Vec3 {
    /* 0x00 */ u32 unk[3];
};

struct Unk_ov088_020ca0c4_Sub {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ u16 unk0c;
};

struct Unk_ov088_020ca0c4_Obj {
    /* 0x00 vtable: slots 0x00-0x40 not identified yet */
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1c();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2c();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3c();
    virtual void vfunc40();
    /* 0x44 */ virtual void vfunc44(void *p);
    /* 0x48 */ virtual void vfunc48(u32 a, s32 b, u32 c, u32 d);
    u8 unk04[0x30];
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u8 unk38[0x4];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u8 unk40[0xac];
    /* 0xec */ void *unkEc;
    /* 0xf0 */ u8 unkF0[0x10];
    /* 0x100 */ Unk_ov088_020ca0c4_Sub unk100;
};

struct Unk_ov088_020ca0c4_Owner {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ Unk_ov088_020ca0c4_Obj *obj10;
};

struct Unk_ov088_020ca0c4_This;

typedef u32 (Unk_ov088_020ca0c4_This::*Unk_ov088_020ca0c4_pmf)();

struct Unk_ov088_020ca0c4_This {
    /* 0x00 */ Unk_ov088_020ca0c4_Owner *owner;
    /* 0x04 */ s32 state;
    /* 0x08 */ u8 unk08[0x24];
    /* 0x2c */ Unk_ov088_020ca0c4_Obj *obj2c;
    /* 0x30 */ u8 unk30[0x48];
    /* 0x78 */ Unk_ov088_020ca0c4_pmf fn78;
};

struct Unk_ov088_020ca0c4_Data {
    /* 0x00 */ u8 unk00[0x5c];
    /* 0x5c */ Unk_ov088_020ca0c4_pmf pmf5c;
};

extern "C" void *data_ov008_02064f08;
extern "C" Unk_ov088_020ca0c4_Vec3 data_ov088_020cd2a0;
extern "C" Unk_ov088_020ca0c4_Vec3 data_ov088_020cd2ac;
extern "C" Unk_ov088_020ca0c4_Data data_ov088_020cd2e0;

extern "C" Unk_ov088_020ca0c4_Obj *func_ov011_02066c28(void *a, u32 b);
extern "C" Unk_ov088_020ca0c4_Obj *func_ov011_0206661c(void *a, u32 b, u32 c);
extern "C" void func_ov013_0208eb04(void *a, u32 b, u32 c, u32 d, s32 e);
extern "C" void func_ov013_0208aa60(void *a, Unk_ov088_020ca0c4_Vec3 *b);
extern "C" u32 func_ov013_0208acb8(u32 a, Unk_ov088_020ca0c4_Vec3 *b);
extern "C" void func_ov013_0208a2a0(void *a, u32 b);
extern "C" void func_ov014_020961bc(void *a, u32 b);
extern "C" s32 func_ov014_02096360(void *a);
extern "C" void func_ov014_02097b18(Unk_ov088_020ca0c4_Obj *a, s32 b);
extern "C" void func_ov014_020978bc(Unk_ov088_020ca0c4_Obj *a, Unk_ov088_020ca0c4_Vec3 *b, s32 c);
extern "C" void func_ov088_020c95a4(Unk_ov088_020ca0c4_This *a, Unk_ov088_020ca0c4_Obj *b, u32 c, u32 d, u32 e, u32 f,
                                    u32 g);

extern "C" s32 func_ov088_020ca0c4(Unk_ov088_020ca0c4_This *self) {
    Unk_ov088_020ca0c4_Vec3 vec;
    Unk_ov088_020ca0c4_Vec3 vec2;
    Unk_ov088_020ca0c4_Obj *obj;
    Unk_ov088_020ca0c4_Obj *obj10;
    s32 neg = -1;
    u32 zero;
    u32 r5;

    switch (self->state) {
    case 0:
        obj = func_ov011_02066c28(data_ov008_02064f08, 0xa000);
        func_ov013_0208eb04(obj, 0xc2000064, 1, 0, neg);
        obj = func_ov011_02066c28(data_ov008_02064f08, 0xa001);
        func_ov013_0208eb04(obj, 0xc10000db, 0, 0, neg);
        obj = func_ov011_02066c28(data_ov008_02064f08, 0xa002);
        func_ov013_0208eb04(obj, 0xc000007d, 1, 0, neg);
        obj = func_ov011_02066c28(data_ov008_02064f08, 0xa003);
        func_ov013_0208eb04(obj, 0xc0000088, 1, 0, neg);
        self->obj2c = func_ov011_0206661c(data_ov008_02064f08, 0x3000, 0);
        /* fall through */
    case 10:
        if (((func_ov011_02066c28(data_ov008_02064f08, 0xa003)->unk34) << 3) >> 31) {
            return 0xa;
        }
        if (((func_ov011_02066c28(data_ov008_02064f08, 0xa002)->unk34) << 3) >> 31) {
            return 0xa;
        }
        if (((func_ov011_02066c28(data_ov008_02064f08, 0xa001)->unk34) << 3) >> 31) {
            return 0xa;
        }
        if (((func_ov011_02066c28(data_ov008_02064f08, 0xa000)->unk34) << 3) >> 31) {
            return 0xa;
        }
        obj = func_ov011_02066c28(data_ov008_02064f08, 0xa000);
        self->obj2c->vfunc44(obj);
        zero = 0;
        self->obj2c->unk3c |= 0x200;
        self->obj2c->vfunc48(zero, zero - 1, 0x100, 0);
        func_ov014_02097b18(self->obj2c, -1);
        vec = data_ov088_020cd2a0;
        func_ov014_020978bc(self->obj2c, &vec, -1);
        {
            self->owner->obj10->vfunc48(6, 6 - 7, 0x100, 0);
        }
        vec2 = data_ov088_020cd2ac;
        obj10 = self->owner->obj10;
        func_ov013_0208aa60(&obj10->unk100, &vec2);
        r5 = func_ov013_0208acb8(0x4000, &vec2);
        func_ov013_0208a2a0(&obj10->unk100, r5);
        func_ov088_020c95a4(self, self->owner->obj10, 0xf0, 0x1b0, 0, 0x3c, r5);
        /* fall through */
    case 30:
        if (self->owner->obj10->unk100.unk0c != 0) {
            return 0x1e;
        }
        if (self->owner->obj10->unkEc != NULL) {
            func_ov014_020961bc(self->owner->obj10->unkEc, 1);
        }
        /* fall through */
    case 35: {
        s32 r;
        s32 id = 0x19;
        if (self->owner->obj10->unkEc != NULL) {
            r = func_ov014_02096360(self->owner->obj10->unkEc);
        } else {
            r = 1;
        }
        if (r == 0) {
            return 0x23;
        }
        self->owner->obj10->vfunc48(id, id - 0x1a, 0x100, 0);
        if (self->owner->obj10->unkEc != NULL) {
            func_ov014_020961bc(self->owner->obj10->unkEc, 1);
        }
    }
        /* fall through */
    case 40: {
        s32 r;
        s32 id = 0x1a;
        if (self->owner->obj10->unkEc != NULL) {
            r = func_ov014_02096360(self->owner->obj10->unkEc);
        } else {
            r = 1;
        }
        if (r == 0) {
            return 0x28;
        }
        self->owner->obj10->vfunc48(id, id - 0x1b, 0x100, 0);
        self->fn78 = data_ov088_020cd2e0.pmf5c;
        return 0;
    }
    default:
        break;
    }
    return 0;
}
