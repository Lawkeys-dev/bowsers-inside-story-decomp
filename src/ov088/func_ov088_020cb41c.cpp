#include "types.h"

class Unk_ov088_020cb41c_Obj;

struct Unk_ov088_020cb41c_Ctx {
    /* 0x00 */ u8 unk00[2];
    /* 0x02 */ u16 id;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0c */ u32 state;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ Unk_ov088_020cb41c_Obj* obj;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u32 unk1c;
};

struct Unk_ov088_020cb41c_Owner {
    /* 0x00 */ u8* scene;
};

struct Unk_ov088_020cb41c_Scene {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ u32 unk10;
};

class Unk_ov088_020cb41c_Obj {
public:
    /* 0x00 vptr */ virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    /* 0x44 */ virtual void v17(u32 a);
    /* 0x48 */ virtual void v18(s32 a, s32 b, s32 c, s32 d);
    /* 0x04 */ u8 unk04[0x8];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x1e];
    /* 0x2c */ s16 unk2c;
    /* 0x2e */ u8 unk2e[0x6];
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u8 unk38[0xb8];
    /* 0xf0 */ u32 unkf0;
    /* 0xf4 */ u8 unkf4[0xc];
    /* 0x100 */ u8 unk100[0x38];
    /* 0x138 */ u8 unk138[0x38];
};

struct Unk_ov088_020cb41c_Ret {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
};

struct Unk_ov088_020cb41c_Data {
    /* 0x00 */ u8 unk00[0x7c];
    /* 0x7c */ u32 unk7c;
    /* 0x80 */ u32 unk80;
};

struct Unk_ov088_020cb41c_Sub {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov088_020cb41c_Sub data_ov016_020b8900;
extern "C" Unk_ov088_020cb41c_Data data_ov088_020cd2e0;

extern "C" Unk_ov088_020cb41c_Obj* func_ov015_020a7ad4(u8* scene, u16 id, s32 a2, s32 a3);
extern "C" u32 func_ov011_02066c28(u8* a0, u32 a1);
extern "C" void func_ov014_0209799c(void* a0, Unk_ov088_020cb41c_Obj* a1, s32 a2);
extern "C" void func_ov015_0209fab0(void* a0, u16 a1);
extern "C" void func_ov014_02097a20(Unk_ov088_020cb41c_Obj* a0, u32 a1, s32 a2, s32 a3, s32 a4);
extern "C" void* func_ov015_020a0f98(u8* a0, s32 a1, s32 a2);
extern "C" void func_ov016_020ad144(u8* a0);
extern "C" Unk_ov088_020cb41c_Ret* func_ov088_020cb0cc(Unk_ov088_020cb41c_Owner* a0, s32 a1);
extern "C" void func_ov013_0208aa40(void* a0, s32 a1, s32 a2, s32 a3);
extern "C" u32 func_ov013_0208a844(s32 a0, s32 a1, s32 a2);
extern "C" u32 func_ov013_0208a9b8(s32 a0, s32 a1, s32 a2);
extern "C" void func_ov013_0208a2c0(void* a0, u32 a1, s32 a2, s32 a3, u32 a4);
extern "C" void func_ov013_0208aa60(void* a0, s32* a1);
extern "C" void func_ov013_0208a2a0(void* a0, u32 a1);
extern "C" void func_ov014_02099d84(Unk_ov088_020cb41c_Obj* a0);

// TODO: the two final loads from data_ov088_020cd2e0 (0x7c, 0x80) are issued in reverse order: the compiler emits them in
// the reverse order of the stores, so the original order (both loads, then stores 0x18 and 0x1c) is not reached. ~99.92%.
// Confirmed on func_ov088_020ca0c4 (matched this way): in func_ov088_020c920c the same "ldr lo; ldr hi; str lo; str hi" pattern comes from assigning
// a pointer-to-member-function (ptr + adj), so the 0x18 field and the data at 0x7c are probably pmf fields: try typing them
// as a pmf typedef (see src/ov088/func_ov088_020c94b4.cpp) and writing `self->unk18 = data.pmf7c;`.
extern "C" s32 func_ov088_020cb41c(Unk_ov088_020cb41c_Owner* owner, Unk_ov088_020cb41c_Ctx* self) {
    u8* fx;
    u32 v;
    Unk_ov088_020cb41c_Ret* ret;
    Unk_ov088_020cb41c_Obj* obj;
    u32 val;

    self->obj = func_ov015_020a7ad4(owner->scene, self->id, 0, -1);
    v = func_ov011_02066c28(data_ov008_02064f08, 0xa001);
    self->obj->v17(v);

    self->obj->v18(7, 7 - 8, 0x100, 0);
    self->obj->unk34 = 0x2000;
    self->obj->unk2c = -8;
    self->obj->unkf0 = (self->obj->unkf0 & ~0x1f000000) | 0x3000000;
    func_ov014_02097a20(self->obj, ((Unk_ov088_020cb41c_Scene*)owner->scene)->unk10, -0x1a00, 0, 0x4c00);

    fx = (u8*)func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xda, 1);
    func_ov014_0209799c(fx + 0xc, self->obj, 0);
    func_ov015_0209fab0(fx + 0xc, self->obj->unk0c);

    data_ov016_020b8900.unk00 = 0x42000b;
    data_ov016_020b8900.unk04 = 0;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0a = 0x7f;
    data_ov016_020b8900.unk0b = 0;
    data_ov016_020b8900.unk0c = self->obj->unk0c;
    data_ov016_020b8900.unk0e = 0x7f;
    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);

    ret = func_ov088_020cb0cc(owner, (s16)self->unk04);
    obj = self->obj;
    val = -(ret->x << 8);
    func_ov013_0208aa40(obj->unk100, -1, 0, 0);
    u32 r4 = func_ov013_0208a844(0x1000, 0x4000, val);
    func_ov013_0208a2c0(obj->unk100, r4, val, 0x1000, func_ov013_0208a9b8(0x1000, 0x4000, val));

    s32 vec[3] = {0, ret->y << 8, ret->z << 8};
    Unk_ov088_020cb41c_Obj* o = self->obj;
    func_ov013_0208aa60(o->unk138, vec);
    func_ov013_0208a2a0(o->unk138, (u16)r4);
    func_ov014_02099d84(self->obj);

    self->state = 6;
    u32 a = data_ov088_020cd2e0.unk7c;
    u32 b = data_ov088_020cd2e0.unk80;
    self->unk18 = a;
    self->unk1c = b;
    return 0;
}
