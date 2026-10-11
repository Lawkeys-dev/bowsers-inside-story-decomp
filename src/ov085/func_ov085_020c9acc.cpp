#include "types.h"

// Virtual slots 0x00-0x44 are unknown placeholders, only slot 0x00 and 0x48 are called here.
class Unk_ov085_Obj {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    /* 0x48 */ virtual void unk48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 pad04[0x20 - 0x04];
    /* 0x20 */ s32 x;
    /* 0x24 */ s32 y;
    /* 0x28 */ s32 z;
};

struct Unk_ov085_State {
    /* 0x00 */ void (*func)(Unk_ov085_State* self);
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_Obj* obj;
};

struct Unk_ov085_Hw00 {
    /* bit 0 */ u32 f0 : 1;
    /* bits 1-4 */ u32 f1 : 4;
    /* bits 5-9 */ u32 f5 : 5;
    /* bits 10-14 */ u32 f10 : 5;
    /* bits 15-31 */ u32 rest : 17;
};

struct Unk_ov085_Hw04 {
    /* bits 0-3 */ u32 a : 4;
    /* bit 4 */ u32 b : 1;
    /* bits 5-7 */ u32 c : 3;
    /* bit 8 */ u32 d : 1;
    /* bits 9-16 */ u32 e : 8;
    /* bits 17-27 */ u32 g : 11;
    /* bits 28-31 */ u32 rest : 4;
};

struct Unk_ov085_Hw08 {
    /* bit 0 */ u32 f0 : 1;
    /* bits 1-9 */ u32 a : 9;
    /* bits 10-18 */ u32 b : 9;
    /* bits 19-31 */ u32 rest : 13;
};

struct Unk_ov085_Hw {
    /* 0x00 */ Unk_ov085_Hw00 w00;
    /* 0x04 */ Unk_ov085_Hw04 w04;
    /* 0x08 */ Unk_ov085_Hw08 w08;
    /* 0x0c */ u32 unk0c[4];
    /* 0x1c */ u32 unk1c;
};

struct Unk_ov085_Bits7d0 {
    /* bits 0-11 */ u32 lo : 12;
    /* bits 12-23 */ u32 mid : 12;
    /* bits 24-31 */ u32 hi : 8;
};

struct Unk_ov085_Regs {
    /* 0x000 */ u8 pad000[0x7d0];
    /* 0x7d0 */ Unk_ov085_Bits7d0 w7d0;
};

extern "C" u8* data_ov008_02064f08;
extern "C" u8 data_ov085_020cb294[0x100];

extern "C" s32 func_ov120_020d4954(u8* p);
extern "C" s32 func_ov014_02096a48(Unk_ov085_Obj* obj);
extern "C" void func_ov014_02097538(s32* p, s32* vec, s32 arg);
extern "C" void* func_ov016_020af9dc(u8* p);
extern "C" void func_ov085_020c9cd0(Unk_ov085_State* self);

// TODO: 88.51% match. The hardware words are bitfield structs written through one pointer, and the prologue, the
// bitfield read-modify-write sequences and the call match. Remaining: mwcc keeps the hardware pointer in r0 (the
// original copies it to r1 after the call), so the temporaries shift to r1/r2/r12 instead of r0/r2/r6; the 0x380a3
// constant is loaded at the store instead of early (a local did not change the scheduling); the 0xf001ffff/0xfffe01ff
// literal pool order is swapped.
extern "C" void func_ov085_020c9acc(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->obj;
    s32 vec[3];
    if (func_ov120_020d4954(data_ov008_02064f08 + 0x1e96ec) != 0) {
        return;
    }
    s32 t = func_ov014_02096a48(obj);
    func_ov014_02097538(&obj->x, vec, t);
    s32 flag = 0;
    if (vec[0] >= 0xf000) {
        vec[0] -= 0xf000;
        flag = 1;
    }
    Unk_ov085_Hw* hw = (Unk_ov085_Hw*)func_ov016_020af9dc(data_ov008_02064f08 + 0xa98c);
    hw->w00.f1 = 1;
    hw->w08.a = vec[0] / 256 - 0x58;
    hw->w08.b = vec[1] / 256 - 0x4c;
    hw->w04.g = (data_ov085_020cb294[0x60] == 0) ? 0x14 : 0x15;
    hw->w00.f5 = 0;
    hw->w00.f10 = 0;
    hw->w08.f0 = 1;
    hw->w04.a = 1;
    hw->w04.b = 1;
    hw->w04.c = 1;
    hw->w04.d = 0;
    hw->w04.e = 0;
    hw->w00.f0 = 0;
    hw->unk1c = 0x380a3;
    Unk_ov085_Obj* vobj = (Unk_ov085_Obj*)(data_ov008_02064f08 + 0x5a0 + 0x30000);
    vobj->unk00();
    Unk_ov085_Regs* regs = (Unk_ov085_Regs*)(data_ov008_02064f08 + 0x30000);
    regs->w7d0.lo = flag ? 0xf0 : 0;
    regs = (Unk_ov085_Regs*)(data_ov008_02064f08 + 0x30000);
    regs->w7d0.mid = 0;
    self->func = func_ov085_020c9cd0;
}
