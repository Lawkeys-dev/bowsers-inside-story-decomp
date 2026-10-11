#include "types.h"

// Word at 0x3c: bit 9 is a flag, bits 14-22 a signed 9-bit value.
union Unk_ov088_Word3c {
    u32 raw;
    struct {
        u32 pad0 : 9;
        u32 flag9 : 1;
        u32 pad10 : 4;
        s32 field14 : 9;
        u32 rest23 : 9;
    } bits;
};

// Sub-object at 0x100 of Unk_ov088_Obj.
struct Unk_ov088_Sub {
    /* 0x00 */ u8 pad00[0x0c];
    /* 0x0c */ u16 unk0c;
};

// Virtual slots 0x00-0x2c are unknown placeholders, only slots 0x0c, 0x30, 0x44 and 0x48 are called here.
class Unk_ov088_Obj {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    /* 0x0c */ virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    /* 0x30 */ virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    /* 0x44 */ virtual void unk44(u32 arg);
    /* 0x48 */ virtual void unk48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 pad04[0x2c - 0x04];
    /* 0x2c */ s16 unk2c;
    /* 0x2e */ u16 unk2e;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x3c - 0x38];
    /* 0x3c */ Unk_ov088_Word3c w3c;
    /* 0x40 */ u8 pad40[0x100 - 0x40];
    /* 0x100 */ Unk_ov088_Sub unk100;
};

// Object reached through the virtual call at slot 0x08 (returns a value, has a field at 0x34).
class Unk_ov088_Cam {
public:
    virtual void v0();
    virtual void v1();
    virtual s32 v2();

    /* 0x04 */ u8 pad04[0x34 - 0x04];
    /* 0x34 */ s32 unk34;
};

// Virtual base of the effect object, reached through the vtable offset.
class Unk_ov088_Base {
public:
    /* 0x00 */ virtual void vb00();
    /* 0x04 */ u8 pad04[0x16 - 0x04];
    /* 0x16 */ u16 unk16 : 14;
};

// Effect object returned by func_ov015_020a0f98.
class Unk_ov088_Fx : public virtual Unk_ov088_Base {
public:
    /* 0x00 */ virtual void vf00();
    /* 0x04 */ u8 pad04[0x40 - 0x04];
    /* 0x40 */ u32 unk40;
};

struct Unk_ov088_Ec2 {
    /* 0x00 */ u8 pad00[0x40];
    /* 0x40 */ u32 unk40;
};

struct Unk_ov088_Ec {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ Unk_ov088_Ec2* unk20;
};

// Actor returned by func_ov011_02066dac.
struct Unk_ov088_Actor {
    /* 0x00 */ u8 pad00[0x3c];
    /* 0x3c */ Unk_ov088_Word3c w3c;
    /* 0x40 */ u8 pad40[0xec - 0x40];
    /* 0xec */ Unk_ov088_Ec* ec;
};

struct Unk_ov088_Vec {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
};

struct Unk_ov088_P {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
};

struct Unk_ov088_Self {
    /* 0x00 */ u8 pad00[0x38];
    /* 0x38 */ s32 unk38;
};

struct Unk_ov088_Msg {
    /* 0x00 */ s16 type;
    /* 0x02 */ u16 id;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0c */ u8 pad0c[0x14 - 0x0c];
    /* 0x14 */ Unk_ov088_Obj* obj;
};

extern "C" u8* data_ov008_02064f08;

extern "C" Unk_ov088_Obj* func_ov015_020a7ad4(u8* base, u16 id, s32 a, s32 b);
extern "C" u32 func_ov011_02066c28(u8* base, u32 id);
extern "C" Unk_ov088_Actor* func_ov011_02066dac(u8* base, u32 id);
extern "C" void func_ov014_020977e8(Unk_ov088_Obj* obj, Unk_ov088_Vec* vec);
extern "C" s32 func_ov013_0208a240(Unk_ov088_Vec* vec);
extern "C" s32 func_0204536c(s32 a, s32 b);
extern "C" void func_ov013_0208aa60(Unk_ov088_Sub* sub, Unk_ov088_Vec* vec);
extern "C" s32 func_ov013_0208acb8(s32 a, Unk_ov088_Vec* vec);
extern "C" void func_ov013_0208a2a0(Unk_ov088_Sub* sub, s32 a);
extern "C" s32 func_020350a8(s32 a, s32 b);
extern "C" void func_ov014_02099dd8(Unk_ov088_Obj* obj);
extern "C" s32 func_ov014_0209a0a4(Unk_ov088_Obj* obj, u32 idx);
extern "C" u32 func_ov014_0209a15c(Unk_ov088_Obj* obj, u16 idx);
extern "C" void func_ov014_02099bd4(Unk_ov088_Obj* obj);
extern "C" Unk_ov088_Fx* func_ov015_020a0f98(u8* base, s32 a, s32 b);
extern "C" void func_ov014_02097a20(void* p, Unk_ov088_Obj* obj, s32 a, s32 b, s32 c);
extern "C" void func_ov013_0208a300(Unk_ov088_Sub* sub, u32 a);

extern "C" s32 func_ov088_020c9cb4(Unk_ov088_Self* self, Unk_ov088_Msg* msg) {
    switch (msg->type) {
    case 0: {
        msg->obj = func_ov015_020a7ad4(data_ov008_02064f08 + 0x11c + 0x2f000, msg->id, 0, -1);
        msg->obj->unk44(func_ov011_02066c28(data_ov008_02064f08, 0xa003));
        if (self->unk38 < 0) {
            self->unk38 = 0;
        } else if (self->unk38 > 3) {
            self->unk38 = 3;
        }
        msg->obj->unk48(self->unk38, -1, 0x100, 0);
        msg->obj->unk34 = 0x2000;
        msg->obj->unk2c = -8;

        Unk_ov088_P* p = *(Unk_ov088_P**)(data_ov008_02064f08 + 0x2f000 + 0x12c);
        Unk_ov088_Vec tmp;
        tmp.x = p->unk20 + 0x4400;
        tmp.y = p->unk24;
        tmp.z = p->unk28 + 0x6800;
        Unk_ov088_Vec vec = tmp;
        vec.z += msg->obj->w3c.bits.field14 << 8;

        func_ov014_020977e8(msg->obj, &vec);
        vec.x = msg->unk04 - tmp.x;
        vec.y = 0;
        vec.z = -(msg->unk08 + (tmp.z - tmp.y));

        s32 scale;
        if (self->unk38 < 3) {
            Unk_ov088_Cam* cam = (Unk_ov088_Cam*)(data_ov008_02064f08 + 0x1e96b0);
            s32 ret = cam->v2();
            scale = func_0204536c((ret + cam->unk34 + 0x3000 - tmp.x) << 8, vec.x);
        } else {
            scale = func_0204536c(0xb80000, func_ov013_0208a240(&vec));
        }

        vec.x = vec.x * scale / 0x100;
        vec.z = vec.z * scale / 0x100;

        Unk_ov088_Obj* obj = msg->obj;
        func_ov013_0208aa60(&obj->unk100, &vec);
        s32 r = func_ov013_0208acb8(0x8000, &vec);
        func_ov013_0208a2a0(&obj->unk100, r);
        msg->obj->unk2e = func_020350a8(vec.y - vec.z, vec.x);
        func_ov014_02099dd8(msg->obj);
    }
    // fall through
    case 0xa:
        if (msg->obj->unk100.unk0c != 0) {
            s32 idx = 0;
            s32 n = func_ov014_0209a0a4(msg->obj, idx);
            while (n > 0) {
                Unk_ov088_Actor* actor = func_ov011_02066dac(data_ov008_02064f08, func_ov014_0209a15c(msg->obj, (u16)n));
                if (actor != NULL && actor->w3c.bits.flag9 == 0 && actor->ec->unk20->unk40 == 0xc10000db) {
                    msg->obj->w3c.raw |= 0x200;
                    func_ov014_02099bd4(msg->obj);
                    msg->obj->vf30();
                    Unk_ov088_Fx* fx = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xf, 0);
                    fx->unk40 = 0x2000;
                    func_ov014_02097a20((u8*)fx + 0xc, msg->obj, 0, 0, -(msg->obj->w3c.bits.field14 << 8));
                    func_ov013_0208a300(&msg->obj->unk100, fx->unk16);
                    return 0x64;
                }
                idx++;
                n = func_ov014_0209a0a4(msg->obj, idx);
            }
            return 0xa;
        }
    // fall through
    case 0x64:
        if (msg->obj->unk100.unk0c != 0) {
            return 0x64;
        }
        msg->obj->w3c.raw |= 0x200;
        func_ov014_02099bd4(msg->obj);
        if (msg->obj != NULL) {
            msg->obj->vf0c();
        }
        msg->obj = NULL;
        return -1;
    default:
        return 0;
    }
}
