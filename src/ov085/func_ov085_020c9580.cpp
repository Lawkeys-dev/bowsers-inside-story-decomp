#include "types.h"

// Virtual slots 0x00-0x40 are unknown placeholders, only slots 0x44 and 0x48 are called here.
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
    /* 0x44 */ virtual void unk44(u32 arg);
    /* 0x48 */ virtual void unk48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 unk04[0x20 - 0x04];
    /* 0x20 */ s32 x;
    /* 0x24 */ s32 y;
    /* 0x28 */ s32 z;
    /* 0x2c */ s16 unk2c;
};

struct Unk_ov085_State {
    /* 0x00 */ void (*func)(Unk_ov085_State* self);
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_Obj* obj;
};

extern "C" void* data_ov008_02064f08;
extern "C" void* func_ov011_02066dac(void* a, u32 b);
extern "C" u32 func_ov011_02066c28(void* a, u32 b);
extern "C" void func_02034c40(s32* vec);
extern "C" void func_ov013_0208aa60(void* obj, s32* vec);
extern "C" void func_ov013_0208a2a0(void* obj, u32 arg);
extern "C" void func_ov085_020c96b4(Unk_ov085_State* self);

extern "C" void func_ov085_020c9580(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->obj;
    Unk_ov085_Obj* other = (Unk_ov085_Obj*)func_ov011_02066dac(data_ov008_02064f08, 0x4006);
    obj->unk44(func_ov011_02066c28(data_ov008_02064f08, 0xb002));
    obj->unk48(0xb, -1, 0x100, 0);
    s32 pos[3];
    pos[0] = (other->x << 4) + 0x4e000 - (obj->x << 4);
    pos[1] = (other->y - obj->y) << 4;
    pos[2] = (other->z << 4) + 0x5a000 - (obj->z << 4);
    func_02034c40(pos);
    s32 vec[3];
    vec[0] = pos[0] / 16;
    vec[1] = pos[1] / 16;
    vec[2] = pos[2] / 16;
    func_ov013_0208aa60((u8*)obj + 0x100, vec);
    func_ov013_0208a2a0((u8*)obj + 0x100, 0x14);
    obj->unk2c = -5;
    self->func = func_ov085_020c96b4;
}
