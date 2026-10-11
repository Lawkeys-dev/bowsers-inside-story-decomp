#include "types.h"

union Unk_ov085_W10 {
    u32 raw;
    struct {
        /* bits 0-22 */ u32 lo : 23;
        /* bit 23 */ u32 b23 : 1;
        /* bit 24 */ u32 mid : 1;
        /* bits 25-31 */ u32 hi : 7;
    } f;
};

class Unk_ov085_Ctx {
public:
    /* 0x00 */ virtual void vf00();
    /* 0x04 */ virtual void vf04(void* p);
    /* 0x04 */ u8 pad04[0x20 - 0x04];
    /* 0x20 */ s32 unk20;
};

class Unk_ov085_Sub {
public:
    /* 0x00 */ virtual void vf00();
    /* 0x04 */ virtual void vf04(void* p);
};

struct Unk_ov085_Vec {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
};

struct Unk_ov085_Obj {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ Unk_ov085_Sub sub;
    /* 0x10 */ u8 pad10[0x2c - 0x10];
    /* 0x2c */ Unk_ov085_Vec vec;
    /* 0x38 */ u8 pad38[0x3c - 0x38];
    /* 0x3c */ s16 unk3c;
    /* 0x3e */ s16 unk3e;
};

// Virtual base of the effect objects, reached through the vtable offset.
class Unk_ov085_VBase {
public:
    /* 0x00 */ virtual void vb00();
    /* 0x04 */ u8 pad04[0x10 - 0x04];
    /* 0x10 */ Unk_ov085_W10 w10;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u32 unk18;
};

class Unk_ov085_Eff : public virtual Unk_ov085_VBase {
public:
    /* 0x00 */ virtual void vf00();
};

struct Unk_ov085_W10Obj {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ Unk_ov085_W10 w10;
};

struct Unk_ov085_Global {
    /* 0x00 */ u8 pad00[0x44];
    /* 0x44 */ Unk_ov085_Eff* unk44;
    /* 0x48 */ u8 pad48[0x4c - 0x48];
    /* 0x4c */ s32 unk4c;
    /* 0x50 */ u8 pad50[0x58 - 0x50];
    /* 0x58 */ Unk_ov085_W10Obj* unk58;
    /* 0x5c */ s32 unk5c;
};

struct Unk_ov085_Self {
    /* 0x00 */ void (*unk00)();
    /* 0x04 */ u8 pad04[0xc - 0x04];
    /* 0x0c */ Unk_ov085_Eff* unkC;
    /* 0x10 */ Unk_ov085_Obj* obj;
};

struct Unk_ov016_020b8900 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

extern "C" Unk_ov085_Ctx* func_ov011_02066dac(u8* p, s32 a);
extern "C" void func_ov085_020cad10();
extern "C" Unk_ov085_Eff* func_ov015_020a0f98(u8* base, s32 id, s32 flag);
extern "C" void func_ov016_020ad31c(u8* p);
extern "C" void func_ov016_020ad144(u8* p);
extern "C" void func_ov120_020d4a34(u8* dst, s32 src, u32 n);
extern "C" double func_02043df0(s32 x);
extern "C" double func_020441e8(double a, double b);
extern "C" double func_02043a34(double a, double b);
extern "C" s32 func_02043d4c(double a);
extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov085_Global data_ov085_020cb294;
extern "C" Unk_ov016_020b8900 data_ov016_020b8900;

// TODO: 99.95%, only the register of the unk5c load differs: the original loads the global address and the value into r1, this compiles the value into r0.
// Tried without effect: intermediate local for the func_ov015 result, pointer or reference alias for the global,
// `0 < x`, `(s32)` casts, extern returning Unk_ov085_Eff*. `>= 1` changes the branch (blt).
extern "C" void func_ov085_020ca9c4(Unk_ov085_Self* self) {
    Unk_ov085_Ctx* a = func_ov011_02066dac(data_ov008_02064f08, 0x4006);
    Unk_ov085_Obj* obj = self->obj;
    Unk_ov085_Ctx* b = func_ov011_02066dac(data_ov008_02064f08, 0x3001);

    if (*(s32*)(data_ov008_02064f08 + 0x1e9000 + 0x71c) > a->unk20 - 0x3000) {
        Unk_ov085_Vec temp = obj->vec;
        temp.x = func_02043d4c(func_020441e8(func_02043df0(temp.x), 4096.0));
        obj->sub.vf04(&temp);
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e96f0, obj->vec.x - ((obj->unk3c << 7) / 16) - 0xc000, 0xa);
    } else {
        if (obj->unk3c < 0x8000) {
            obj->unk3c = (s16)func_02043d4c(func_02043a34(func_02043df0(obj->unk3c), 512.0));
        } else {
            Unk_ov085_Vec temp = obj->vec;
            temp.x = func_02043d4c(func_020441e8(func_02043df0(temp.x), 4096.0));
            obj->sub.vf04(&temp);
        }
    }

    Unk_ov085_Vec vec0 = obj->vec;
    vec0.x += (-(obj->unk3c << 7)) / 16;
    b->vf04(&vec0);

    obj->unk3e -= 0x1fc00;
    if (obj->unk3e > 0x2000) {
        obj->unk3e = 0x2000;
    }

    if (b->unk20 + 0x6000 > *(s32*)(data_ov008_02064f08 + 0x1e9000 + 0x71c)) {
        return;
    }

    Unk_ov085_Global* g = &data_ov085_020cb294;
    Unk_ov085_VBase& y = *g->unk44;
    y.unk18 = 0;
    y.unk16 &= ~0x3fff;
    y.w10.f.b23 = 1;
    y.unk16 &= ~0x8000;
    y.w10.f.hi = 1;

    Unk_ov085_W10Obj* z = g->unk58;
    z->w10.f.hi = 1;

    Unk_ov085_VBase& y2 = *self->unkC;
    y2.unk18 = 0;
    y2.unk16 &= ~0x3fff;
    y2.w10.f.b23 = 1;
    y2.unk16 &= ~0x8000;
    y2.w10.f.hi = 1;

    self->unkC = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xe5, 0);

    if (data_ov085_020cb294.unk5c > 0) {
        func_ov016_020ad31c(data_ov008_02064f08 + 0x254 + 0x2cc00);
    }

    data_ov016_020b8900.unk00 = 0x40000174;
    data_ov016_020b8900.unk04 = 0;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0a = 0x7f;
    data_ov016_020b8900.unk0b = 0;
    data_ov016_020b8900.unk0c = 0;
    data_ov016_020b8900.unk0e = 0x7f;
    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);

    data_ov085_020cb294.unk4c = obj->unk3e / 32;
    self->unk00 = func_ov085_020cad10;
}
