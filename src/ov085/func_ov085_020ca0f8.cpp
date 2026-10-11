#include "types.h"

// Virtual slots 0x00-0x40 are unknown placeholders, only slot 0x48 is called here.
class Unk_ov085_Obj {
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
    /* 0x48 */ virtual void unk48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 pad04[0x8];
    /* 0x0c */ u16 unkC;
    /* 0x0e */ u8 pad0e[0x20 - 0x0e];
    /* 0x20 */ s32 x;
    /* 0x24 */ s32 y;
    /* 0x28 */ s32 z;
};

// Sub-object embedded at offset 0x0c of the effect object.
class Unk_ov085_Sub {
public:
    /* 0x00 */ virtual void vf00();
    /* 0x04 */ virtual void vf04(void* p);
};

// Virtual base of the effect object, reached through the vtable offset.
class Unk_ov085_Base {
public:
    /* 0x00 */ virtual void vb00();
    /* 0x04 */ u8 pad04[0x10 - 0x04];
    /* 0x10 */ u32 unk10;
};

class Unk_ov085_Eff : public virtual Unk_ov085_Base {
public:
    /* 0x00 */ virtual void vf00();
    /* 0x04 */ u8 pad04[0x8];
    /* 0x0c */ Unk_ov085_Sub sub;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x3c - 0x18];
    /* 0x3c */ s16 unk3c;
    /* 0x3e */ s16 unk3e;
};

struct Unk_ov085_State {
    /* 0x00 */ void (*vtbl)();
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_Obj* obj;
    /* 0x0c */ u8 pad0c[0x10 - 0x0c];
    /* 0x10 */ Unk_ov085_Eff* unk10;
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

struct Unk_ov085_Vec {
    s32 v[3];
};

extern "C" Unk_ov016_020b8900 data_ov016_020b8900;
extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov085_Vec data_ov085_020cb200;

extern "C" void* func_ov015_020a0f98(u8* mgr, s32 id, s32 flag);
extern "C" void func_ov015_0209fa78(void* p, s32 a, s32 b);
extern "C" void func_ov014_0209799c(void* p, Unk_ov085_Obj* obj, Unk_ov085_Vec* vec);
extern "C" void func_ov016_020ad144(void* p);
extern "C" void func_ov085_020ca2c8();

extern "C" void func_ov085_020ca0f8(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->obj;
    if (self->unk10->unk14 != 0) {
        return;
    }
    obj->unk48(0x28, -1, 0x100, 0);
    Unk_ov085_Eff* first = (Unk_ov085_Eff*)func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xe7, 0);
    first->sub.vf04(&obj->x);
    first->unk3e = 0x2000;
    first->unk3c = first->unk3e;
    func_ov015_0209fa78(&first->sub, 0, 0x3000);

    func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xe8, 1);

    Unk_ov085_Vec vec = data_ov085_020cb200;

    self->unk10 = (Unk_ov085_Eff*)func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xea, 0);
    func_ov015_0209fa78(&self->unk10->sub, 0, 0x3000);
    self->unk10->unk3c = 0;
    self->unk10->unk3e = 0;
    self->unk10->unk10 &= 0x01ffffff;
    vec.v[0] += ((self->unk10->unk3c << 7) / 16) / 2;
    func_ov014_0209799c(&self->unk10->sub, obj, &vec);

    u16 unkC = obj->unkC;
    data_ov016_020b8900.unk00 = 0x30000;
    data_ov016_020b8900.unk04 = 0;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0a = 0x7f;
    data_ov016_020b8900.unk0b = 0;
    data_ov016_020b8900.unk0c = unkC;
    data_ov016_020b8900.unk0e = 0x7f;
    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
    self->vtbl = func_ov085_020ca2c8;
}
