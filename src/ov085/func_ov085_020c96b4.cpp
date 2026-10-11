#include "types.h"

// Virtual slots other than the called ones are placeholders.
class Unk_ov085_Obj {
public:
    virtual void vf00();
    virtual void unk04(void* arg);
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
    /* 0x04 */ u8 pad04[0x20 - 4];
    /* 0x20 */ void* unk20;
    /* 0x24 */ u8 pad24[0x2c - 0x24];
    /* 0x2c */ u16 unk2c;
    /* 0x2e */ u8 pad2e[0xec - 0x2e];
    /* 0xec */ void* unkEc;
    /* 0xf0 */ u8 padF0[0x10c - 0xf0];
    /* 0x10c */ u16 unk10c;
};

class Unk_ov085_Emb {
public:
    virtual void vf00();
    virtual void unk04(void* arg);
};

struct Unk_ov085_Sub {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ Unk_ov085_Emb emb;
    /* 0x10 */ u8 unk10[0x3c - 0x10];
    /* 0x3c */ s16 unk3c;
    /* 0x3e */ s16 unk3e;
};

struct Unk_ov085_State {
    /* 0x00 */ void (*unk0)(void);
    /* 0x04 */ u32 unk4;
    /* 0x08 */ Unk_ov085_Obj* unk8;
};

struct Unk_ov085_Ret {
    /* 0x00 */ u8 unk0[0x20];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
};

struct Unk_ov085_Args {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" Unk_ov085_Ret* func_ov011_02066dac(void* a, u32 b);
extern "C" void func_ov014_020961bc(void* a, s32 b);
extern "C" Unk_ov085_Sub* func_ov015_020a0f98(void* base, s32 id, s32 b);
extern "C" void func_ov085_020c97b0(void);
extern "C" u8* data_ov008_02064f08;

extern "C" void func_ov085_020c96b4(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->unk8;
    Unk_ov085_Args args;
    Unk_ov085_Ret* ret = func_ov011_02066dac(data_ov008_02064f08, 0x4006);
    if (obj->unk10c != 0) {
        return;
    }
    args.a = ret->unk20 + 0x4e00;
    args.b = ret->unk24;
    args.c = ret->unk28 + 0x5a00;
    obj->unk04(&args);
    obj->unk48(0xc, -1, 0x100, 0);
    if (obj->unkEc != NULL) {
        func_ov014_020961bc(obj->unkEc, 1);
    }
    obj->unk2c = 0;
    Unk_ov085_Sub* fx = func_ov015_020a0f98(data_ov008_02064f08 + 0x25800 + 0x3e8, 0x130, 0);
    fx->unk3e = 0x2000;
    fx->unk3c = fx->unk3e;
    fx->emb.unk04(&obj->unk20);
    self->unk0 = func_ov085_020c97b0;
}
