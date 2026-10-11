#include "types.h"

struct Unk_ov085_020ca68c_Vec3 {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
};

// Subobject: its vtable pointer is the first word.
class Unk_ov085_020ca68c_Sub {
public:
    virtual void vf00();
    virtual void vf04(void* p);
};

/* object pointed to by self->obj */
struct Unk_ov085_020ca68c_Obj {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ Unk_ov085_020ca68c_Sub unkC;
    /* 0x10 */ u8 pad10[0x2c - 0x10];
    /* 0x2c */ Unk_ov085_020ca68c_Vec3 pos;
    /* 0x38 */ u8 pad38[0x3c - 0x38];
    /* 0x3c */ s16 unk3c;
    /* 0x3e */ s16 unk3e;
};

struct Unk_ov085_020ca68c_Mid {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ s32 unk20;
};

/* object with virtual vf18, its 0x10 points to Unk_ov085_020ca68c_Mid */
class Unk_ov085_020ca68c_Mgr {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18(s32 a, s32 b, s32 c, s32 d, s32 e);
    /* 0x04 */ u8 pad04[0x10 - 0x04];
    /* 0x10 */ Unk_ov085_020ca68c_Mid* unk10;
};

/* global data_ov085_020cb280 */
struct Unk_ov085_020ca68c_Cb280 {
    /* 0x00 */ u8 pad00[0x4];
    /* 0x04 */ Unk_ov085_020ca68c_Mgr* mgr;
};

// Object pointed to by data_ov085_020cb294 + 0x8.
class Unk_ov085_020ca68c_Anim {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48(s32 a, s32 b, s32 c, s32 d);
    /* 0x04 */ u8 pad04[0x20 - 0x04];
    /* 0x20 */ s32 unk20;
};

// Object returned by func_ov011_02066dac.
class Unk_ov085_020ca68c_Vec {
public:
    virtual void vf00();
    virtual void vf04(Unk_ov085_020ca68c_Vec3* vec);
};

// Virtual base of the object returned by func_ov015_020a0f98.
class Unk_ov085_020ca68c_Base {
public:
    virtual void vf00();
    /* 0x04 */ u8 pad04[0x10 - 0x04];
    /* 0x10 */ u32 unk10;
};

class Unk_ov085_020ca68c_Ov015 : public virtual Unk_ov085_020ca68c_Base {
public:
    virtual void vf00();
    /* 0x04 */ u8 pad04[0xc - 0x04];
    /* 0x0c */ Unk_ov085_020ca68c_Sub sub0c;
};

/* global data_ov085_020cb294 */
struct Unk_ov085_020ca68c_Global {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ Unk_ov085_020ca68c_Anim* anim;
    /* 0x0c */ u8 pad0c[0x44 - 0x0c];
    /* 0x44 */ void* unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4c */ u8 pad4c[0x50 - 0x4c];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
};

struct Unk_ov085_020ca68c_State {
    /* 0x00 */ void (*func)(Unk_ov085_020ca68c_State* self);
    /* 0x04 */ u8 pad04[0x10 - 0x04];
    /* 0x10 */ Unk_ov085_020ca68c_Obj* obj;
};

extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov085_020ca68c_Global data_ov085_020cb294;
extern "C" Unk_ov085_020ca68c_Cb280 data_ov085_020cb280;
extern "C" u8 data_ov085_020cb2cc[];

extern "C" s64 func_02043df0(s32 v);
extern "C" void func_02043a34(s64 a, s32 b, float c);
extern "C" s32 func_02043d4c();
extern "C" void func_020441e8(s64 a, s32 b, float c);
extern "C" Unk_ov085_020ca68c_Vec* func_ov011_02066dac(u8* base, s32 a);
extern "C" void func_ov014_0209799c(void* a, void* b, void* c);
extern "C" Unk_ov085_020ca68c_Ov015* func_ov015_020a0f98(u8* base, s32 a, s32 b);
extern "C" void func_ov120_020d4a34(u8* base, s32 a, s32 b, s32 c);
extern "C" void func_ov085_020c9580(void* p);
extern "C" void func_ov085_020ca9c4(Unk_ov085_020ca68c_State* self);

// TODO: 96.76%. In the else branch (obj->unk3c >= 0x4000), the original loads pos.x (ldr r4,[obj,#0x2c]) and
// unk3c (ldrsh) after the literal-pool loads and sets the constant 10 before the shift; mwcc hoists the ldrsh
// above the pool loads and moves the pos.x load and the mov r2,#0xa. Tried: local x/k/px/t variables (declared
// before and after the vf04 call), inline expressions, `* 0x80` instead of `<< 7`, both orders: same result
// or worse (94.23% with pos.x loaded before the vf04 call).
extern "C" void func_ov085_020ca68c(Unk_ov085_020ca68c_State* self) {
    Unk_ov085_020ca68c_Obj* obj = self->obj;
    if (data_ov085_020cb294.unk54 > 0) {
        if (data_ov085_020cb294.unk50 >= data_ov085_020cb294.unk54) {
            data_ov085_020cb280.mgr->vf18(data_ov085_020cb294.unk54, 0x7f, 0, 0, 0);
            data_ov085_020cb294.unk54 = 0;
        } else {
            data_ov085_020cb280.mgr->vf18(data_ov085_020cb294.unk50, 0x7f, 0, 0, 0);
            data_ov085_020cb294.unk54 -= data_ov085_020cb294.unk50;
        }
    }

    if (obj->unk3c < 0x4000) {
        s64 r = func_02043df0(obj->unk3c);
        func_02043a34(r, 0, 4.0f);
        obj->unk3c = func_02043d4c();
    } else {
        Unk_ov085_020ca68c_Vec3 v = obj->pos;
        s64 r = func_02043df0(v.x);
        func_020441e8(r, 0, 5.5f);
        v.x = func_02043d4c();
        obj->unkC.vf04(&v);
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e96f0, obj->pos.x - ((obj->unk3c << 7) / 16) - 0xc000, 10,
                            obj->unk3c << 7);
    }

    Unk_ov085_020ca68c_Vec* other = func_ov011_02066dac(data_ov008_02064f08, 0x3001);
    Unk_ov085_020ca68c_Vec3 tmp = obj->pos;
    tmp.x += (-(obj->unk3c << 7)) / 16;
    other->vf04(&tmp);

    Unk_ov085_020ca68c_Anim* anim = data_ov085_020cb294.anim;
    s32 dt = anim->unk20;
    func_ov014_0209799c(anim, other, data_ov085_020cb2cc);
    dt -= anim->unk20;
    anim->vf48(4, -1, 0x100, 1);

    if (data_ov085_020cb294.unk44 == NULL) {
        Unk_ov085_020ca68c_Ov015* p = func_ov015_020a0f98(data_ov008_02064f08 + 0x25be8, 8, 1);
        data_ov085_020cb294.unk44 = p;
        p->unk10 &= ~0xfe000000;
    }

    data_ov085_020cb294.unk48 += dt;
    if (data_ov085_020cb294.unk48 >= 0x5000) {
        s32 n = data_ov085_020cb294.unk48 - 0x5000;
        data_ov085_020cb294.unk48 = n;
        Unk_ov085_020ca68c_Ov015* p = func_ov015_020a0f98(data_ov008_02064f08 + 0x25be8, 7, 0);
        p->sub0c.vf04(&anim->unk20);
    }

    obj->unk3e -= 0x1fc00;
    if (obj->unk3e > 0x2000) {
        obj->unk3e = 0x2000;
    }

    s32 lim;
    switch (*(s32*)(data_ov008_02064f08 + 0x2d464)) {
        case 1:
            lim = -0xf800;
            break;
        case 2:
            lim = -0xf800;
            break;
        case 3:
            lim = 0x50800;
            break;
        case 4:
            lim = -0xf800;
            break;
    }

    if (data_ov085_020cb280.mgr->unk10->unk20 > lim) {
        return;
    }
    func_ov085_020c9580(&data_ov085_020cb294);
    self->func = func_ov085_020ca9c4;
}
