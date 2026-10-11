#include "types.h"

// Virtual slots 0x00-0x40 are unknown placeholders, only slots 0x04, 0x44 and 0x48 are called here.
class Unk_ov085_Obj {
public:
    virtual void vf00();
    virtual void vf04(void* p);
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
    /* 0x44 */ virtual void vf44(s32 a);
    /* 0x48 */ virtual void vf48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 pad04[0x10 - 0x04];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 pad14[0x20 - 0x14];
    /* 0x20 */ s32 x;
    /* 0x24 */ s32 y;
    /* 0x28 */ s32 z;
    /* 0x2c */ u8 pad2c[0xec - 0x2c];
    /* 0xec */ struct Unk_ov085_Ext* unkEc;
    /* 0xf0 */ u32 unkF0;
};

struct Unk_ov085_Ext {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ s32 unk20;
};

struct Unk_ov085_Vec {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
};

struct Unk_ov085_Eff {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 pad14[0x2c - 0x14];
    /* 0x2c */ Unk_ov085_Vec vec;
    /* 0x38 */ u8 pad38[0x3c - 0x38];
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

struct Unk_ov085_Glob {
    /* 0x00 */ u8 pad00[0x08];
    /* 0x08 */ Unk_ov085_Obj* unk08;
    /* 0x0c */ u8 pad0c[0x38 - 0x0c];
    /* 0x38 */ s32 unk38;
    /* 0x3c */ s32 unk3c;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8 pad44[0x50 - 0x44];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ Unk_ov085_Eff* unk58;
    /* 0x5c */ void* unk5c;
};

struct Unk_ov085_Mid {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ Unk_ov085_Ext* unk10;
};

struct Unk_ov085_Sys {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ Unk_ov085_Mid* unk04;
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

extern "C" Unk_ov085_Glob data_ov085_020cb294;
extern "C" Unk_ov085_Sys data_ov085_020cb280;
extern "C" Unk_ov016_020b8900 data_ov016_020b8900;
extern "C" u8* data_ov008_02064f08;

extern "C" void* func_ov011_02066dac(u8* a, u32 b);
extern "C" Unk_ov085_Obj* func_ov011_0206661c(u8* a, u32 b, u32 c);
extern "C" void func_ov014_02099dac(Unk_ov085_Obj* p, u32 arg);
extern "C" s32 func_ov014_02099fac(Unk_ov085_Obj* p, s32 flag);
extern "C" void func_ov014_02099bd4(Unk_ov085_Obj* p);
extern "C" void* func_ov016_020ad144(u8* p);
extern "C" Unk_ov085_Eff* func_ov016_020af408(u8* p, u32 a, u32 b);
extern "C" s32 func_ov015_020a83f0(Unk_ov085_Mid* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void func_ov120_020d4a34(u8* p, s32 v, s32 n);
extern "C" void func_ov085_020ca68c();

// TODO: 100.00% match, but not completed: the full link fails with undefined soft-float helpers (_ddiv, _dfix, _dflt,
// _dsub) because the `double` arithmetic makes the compiler call them, and the build has no symbol with these names.
// Probably the same routines exist in the arm9 program under their func_0204xxxx names (see func_02043df0 and
// func_020441e8 used in func_ov085_020ca68c.cpp): check symbols.txt before deciding how to link them.
extern "C" void func_ov085_020ca2c8(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->obj;
    Unk_ov085_Eff* eff = self->unk10;
    if (data_ov085_020cb294.unk5c == NULL) {
        data_ov016_020b8900.unk00 = 0x42000e;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = 0;
        data_ov016_020b8900.unk0e = 0x7f;
        data_ov085_020cb294.unk5c = func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
    }
    if (eff->unk3c < 0x4000) {
        eff->unk3c = (s16)((double)eff->unk3c - 512.0);
    }
    Unk_ov085_Obj* hw = (Unk_ov085_Obj*)func_ov011_02066dac(data_ov008_02064f08, 0x3001);
    if (hw == NULL) {
        u32 id = 0x3001;
        hw = func_ov011_0206661c(data_ov008_02064f08, id, 0x3000 - id);
        hw->vf44(obj->unkEc->unk20);
        hw->vf48(0x2a, -1, 0x100, 1);
        hw->vf04(&eff->vec);
        func_ov014_02099dac(hw, 0x1002);
        hw->unkF0 = (hw->unkF0 & ~0x1f000000) | 0x1f000000;
    }

    Unk_ov085_Vec vec = eff->vec;
    vec.x += (-(eff->unk3c << 7)) / 16;
    hw->vf04(&vec);
    func_ov120_020d4a34(data_ov008_02064f08 + 0x1e96f0, eff->vec.x - ((eff->unk3c << 7) / 16) - 0xc000, 10);
    eff->unk3e = (s16)(eff->unk3e - 0x1fc00);
    if (eff->unk3e > 0x2000) {
        eff->unk3e = 0x2000;
    }
    if (func_ov014_02099fac(hw, 0) == 0) {
        return;
    }

    data_ov016_020b8900.unk00 = 0x40000212;
    data_ov016_020b8900.unk04 = 0;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0a = 0x7f;
    data_ov016_020b8900.unk0b = 0;
    data_ov016_020b8900.unk0c = 0x1002;
    data_ov016_020b8900.unk0e = 0x7f;
    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
    func_ov014_02099bd4(hw);
    Unk_ov085_Eff* res = func_ov016_020af408(data_ov008_02064f08 + 0x1ed00, 0x3b, 0x1002);
    data_ov085_020cb294.unk58 = res;
    res->unk10 &= 0x01ffffff;
    self->vtbl = func_ov085_020ca68c;

    Unk_ov085_Obj* other = data_ov085_020cb294.unk08;
    data_ov085_020cb294.unk38 = other->x - hw->x;
    data_ov085_020cb294.unk3c = other->y - hw->y;
    data_ov085_020cb294.unk40 = other->z - hw->z;
    func_ov011_02066dac(data_ov008_02064f08, 0x4006);

    s32 mode = *(s32*)(data_ov008_02064f08 + 0x2d000 + 0x464);
    s32 r7;
    switch (mode) {
    case 1:
        r7 = -0xf800;
        break;
    case 2:
        r7 = -0xf800;
        break;
    case 3:
        r7 = 0x50800;
        break;
    case 4:
        r7 = -0xf800;
        break;
    }

    Unk_ov085_Mid* mid = data_ov085_020cb280.unk04;
    s32 r5 = mid->unk10->unk20 - r7;
    s32 pos = func_ov015_020a83f0(mid, 0x180, data_ov085_020cb280.unk00, 1, 0);
    data_ov085_020cb294.unk54 = pos;
    double d1 = (double)pos;
    double d2 = (double)r5;
    s32 t = (s32)(d1 / (d2 / 4096.0));
    data_ov085_020cb294.unk50 = t;
    if (t <= 0) {
        data_ov085_020cb294.unk50 = 1;
    }
}
