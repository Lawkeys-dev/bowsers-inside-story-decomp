#include "types.h"

// Vtable slots 0x00-0x44 are unknown placeholders, only slot 0x48 is called here.
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

    /* 0x04 */ u8 pad04[0x8];
    /* 0x0c */ u16 unkC;
    /* 0x0e */ u8 pad0e[0xec - 0xe];
    /* 0xec */ void* unkEc;
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

struct Unk_ov085_State {
    /* 0x00 */ void (*vtbl)();
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_Obj* obj;
};

extern "C" Unk_ov016_020b8900 data_ov016_020b8900;
extern "C" u8* data_ov008_02064f08;

extern "C" void func_ov014_020961bc(void* p, s32 arg);
extern "C" void func_ov016_020ad144(void* p);
extern "C" void func_ov085_020c98e0();

extern "C" void func_ov085_020c9830(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->obj;
    obj->unk48(0x1c, -1, 0x100, 0);
    if (obj->unkEc != NULL) {
        func_ov014_020961bc(obj->unkEc, 1);
    }
    u16 unkC = obj->unkC;
    data_ov016_020b8900.unk00 = 0x40000180;
    data_ov016_020b8900.unk04 = 5;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0a = 0x7f;
    data_ov016_020b8900.unk0b = 0;
    data_ov016_020b8900.unk0c = unkC;
    data_ov016_020b8900.unk0e = 0x7f;
    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
    self->vtbl = func_ov085_020c98e0;
}
