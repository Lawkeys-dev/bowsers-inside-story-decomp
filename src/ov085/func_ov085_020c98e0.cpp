#include "types.h"

// The calls below go through vtables (virtual methods), so the object pointer is copied to r0 before the vtable load.
// Only the virtual slots that are called are named; the others are placeholders.

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
    /* 0x20 */ u8 unk4[0x20 - 4];
    /* 0x20 */ void* unk20;
    /* 0x24 */ u8 unk24[0xec - 0x24];
    /* 0xec */ void* unkEC;
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
    /* 0x00 */ void* vtbl;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_Obj* obj;
};

extern "C" s32 func_ov014_02096360(void* p);
extern "C" void func_ov014_020961bc(void* p, s32 a);
extern "C" Unk_ov085_Sub* func_ov015_020a0f98(void* base, s32 id, s32 b);
extern "C" void func_ov085_020c99ac();
extern "C" u8* data_ov008_02064f08;

extern "C" void func_ov085_020c98e0(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->obj;
    s32 ret;
    if (obj->unkEC == NULL) {
        ret = 1;
    } else {
        ret = func_ov014_02096360(obj->unkEC);
    }
    if (ret != 0) {
        obj->unk48(0x1d, -1, 0x100, 0);
        if (obj->unkEC != NULL) {
            func_ov014_020961bc(obj->unkEC, 1);
        }
        Unk_ov085_Sub* sub = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xe0, 0);
        sub->unk3c = 0x2000;
        sub->unk3e = sub->unk3c;
        sub->emb.unk04(&obj->unk20);
        func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xe1, 1);
        self->vtbl = (void*)func_ov085_020c99ac;
    }
}
