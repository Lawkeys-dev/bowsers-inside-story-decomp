#include "types.h"

/* 0xf0 */
union Unk_ov085_020caf8c_word {
    u32 raw;
    struct {
        s32 lo : 12;
        s32 mid : 12;
        u32 hi : 8;
    } f;
};

// Object reached from the global owner: vtable slot 1 takes a vector, slot 0x12 takes 4 arguments.
class Unk_ov085_Obj {
public:
    virtual void vf00();
    virtual void vf04(void* vec);
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
    /* 0x48 */ virtual void vf48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 pad04[0x28];
    /* 0x2c */ s16 unk2c;
    /* 0x2e */ u8 pad2e[0x2];
    /* 0x30 */ s16 unk30;
    /* 0x32 */ s16 unk32;
};

// Hardware object: same slot 0x48 as Unk_ov085_Obj, packed word at 0xf0.
class Unk_ov085_Hw {
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
    /* 0x48 */ virtual void vf48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 pad04[0xec];
    /* 0xf0 */ Unk_ov085_020caf8c_word word;
};

class Unk_ov085_Sub {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    /* 0x18 */ virtual void vf18(s32 a, s32 b, s32 c);
};

struct Unk_ov085_020caf8c {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 unk04[0x4];
    /* 0x08 */ Unk_ov085_Obj* obj;
    /* 0x0c */ struct Unk_ov085_Ctx* ctx;
};

struct Unk_ov085_Ctx {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 unk14;
};

struct Unk_ov085_Owner {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ Unk_ov085_Hw* unk10;
};

struct Unk_ov085_Vec {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
};

struct Unk_ov085_VecSrc {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
};

struct Unk_ov085_Cfg {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ Unk_ov085_VecSrc* unk14;
};

struct Unk_ov008_Mid {
    /* 0x0 */ u8 unk00[0x2d400];
    /* 0x2d400 */ Unk_ov085_Sub sub;
};

struct Unk_ov008_02064f08 {
    /* 0x00 */ u8 unk00[0x3c];
    /* 0x3c */ Unk_ov008_Mid unk3c;
};

extern "C" Unk_ov085_Cfg data_ov085_020cb294;
extern "C" Unk_ov085_Owner* data_ov085_020cb280;
extern "C" Unk_ov008_02064f08* data_ov008_02064f08;

extern "C" s32 func_ov085_020caf8c(Unk_ov085_020caf8c* self) {
    Unk_ov085_Obj* obj = self->obj;
    if (self->ctx->unk14 != 0) {
        return self->ctx->unk14;
    }
    Unk_ov085_VecSrc* src = data_ov085_020cb294.unk14;
    Unk_ov085_Vec vec;
    vec.x = src->unk20 + 0x3800;
    vec.y = src->unk24;
    vec.z = src->unk28 - 0x2000;
    obj->vf04(&vec);
    obj->vf48(2, -1, 0x100, 0);
    obj->unk32 = 0x2000;
    obj->unk30 = obj->unk32;
    obj->unk2c = ~1;

    Unk_ov085_Hw* hw = data_ov085_020cb280->unk10;
    u32 unit = 0x1000;
    u32 w = hw->word.raw;
    u32 mask = -unit;
    u32 hiPart = w & mask;
    s32 mid = (s32)(w << 8) >> 20;
    s32 lo = (s32)(w << 20) >> 20;
    u32 newLo = lo - (0x1e - mid);
    u32 loPart = newLo & (mask >> 20);
    u32 v = hiPart | loPart;
    hw->word.raw = v;
    hw->word.f.mid = 0x1e;

    data_ov085_020cb280->unk10->vf48(0, -1, 0x100, 1);
    data_ov008_02064f08->unk3c.sub.vf18(0, 0x4039, 1);
    self->unk00 = 0;
    return 0;
}
