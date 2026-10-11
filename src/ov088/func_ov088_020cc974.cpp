#include "types.h"

struct Unk_ov088_Sub {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ u16 unk0c;
};

struct Unk_ov088_Sub2 {
    /* 0x00 */ u8 pad00[0x16];
    /* 0x16 */ u16 unk16 : 14;
};

struct Unk_ov088_Obj {
    /* 0x00 */ virtual void vf00();
    virtual void vf01();
    virtual u32 vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(void* a);
    virtual void vf18(s32 a, s32 b, s32 c, s32 d);
    /* 0x04 */ u8 pad04[0x8];
    /* 0x0c */ u16 unkC;
    /* 0x0e */ u8 pad0e[0x2];
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[0x8];
    /* 0x2c */ s16 unk2c;
    /* 0x2e */ u16 unk2e;
    /* 0x30 */ u8 pad30[0x4];
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u8 pad38[0x4];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u8 pad44[0xac];
    /* 0xf0 */ u32 unkF0;
    /* 0xf4 */ u8 padF4[0xc];
    /* 0x100 */ Unk_ov088_Sub unk100;
};

struct Unk_ov088_Ret {
    /* 0x00 */ s32* vtbl;
    /* 0x04 */ u8 pad04[0x3c];
    /* 0x40 */ u32 unk40;
};

struct Unk_ov088_Msg {
    /* 0x00 */ s16 type;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u8 pad04[0x10];
    /* 0x14 */ Unk_ov088_Obj* obj;
};

struct Unk_ov088_Self {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ s16 unk28;
};

struct Unk_ov088_Global {
    /* 0x00000 */ u8 unk00[0x1e96b0];
    /* 0x1e96b0 */ Unk_ov088_Obj unk1e96b0;
};

struct Unk_ov088_Dat {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

extern "C" Unk_ov088_Global* data_ov008_02064f08;
extern "C" Unk_ov088_Dat data_ov016_020b8900;

extern "C" void func_ov014_02099bd4(Unk_ov088_Obj* obj);
extern "C" void func_ov014_02097a48(Unk_ov088_Obj* obj, void* out, s32 arg);
extern "C" void func_ov014_020977e8(Unk_ov088_Obj* obj, void* out);
extern "C" void func_ov014_02099dd8(Unk_ov088_Obj* obj);
extern "C" void func_ov014_0209799c(void* p, Unk_ov088_Obj* obj, s32 arg);
extern "C" void* func_ov015_020a7ad4(void* heap, u16 id, s32 a, s32 b);
extern "C" Unk_ov088_Ret* func_ov015_020a0f98(void* heap, s32 id, s32 arg);
extern "C" void* func_ov011_02066c28(void* p, s32 id);
extern "C" void func_ov016_020ad144(void* p, Unk_ov088_Dat* dat, u16 v);
extern "C" void func_ov013_0208aa40(void* p, s32 a, s32 b, s32 c);
extern "C" u32 func_ov013_0208a844(s32 a, s32 b, u32 c);
extern "C" u32 func_ov013_0208a9b8(s32 a, s32 b, u32 c);
extern "C" void func_ov013_0208a2c0(void* p, u32 a, u32 b, s32 c, u32 d);
extern "C" void func_ov013_0208a300(void* p, u32 v);
extern "C" s32 func_ov088_020cb32c(Unk_ov088_Self* self, Unk_ov088_Obj* obj, s32 arg);
extern "C" u64 func_02043e30(u16 v);
extern "C" void func_02043a34(u64 v, s32 a, u32 c);
extern "C" u16 func_02043d98(void);

extern "C" s32 func_ov088_020cc974(Unk_ov088_Self* self, Unk_ov088_Msg* msg) {
    switch (msg->type) {
    case 0: {
        u32 local[3];
        func_ov014_02099bd4(msg->obj);
        func_ov014_02097a48(msg->obj, local, 0);
        if (msg->obj != NULL) {
            msg->obj->vf03();
        }
        msg->obj = NULL;
        msg->obj = (Unk_ov088_Obj*)func_ov015_020a7ad4((u8*)data_ov008_02064f08 + 0x2f11c, msg->unk02, 0, -1);
        void* p = func_ov011_02066c28(data_ov008_02064f08, 0xa001);
        msg->obj->vf17(p);
        msg->obj->vf18(5, -1, 0x100, 0);
        msg->obj->unk34 = 0x2000;
        msg->obj->unk2c = -8;
        msg->obj->unkF0 = (msg->obj->unkF0 & ~0x1f000000) | 0x2000000;
        msg->obj->unk3c = (msg->obj->unk3c & 0xff803fff) | 0x7b0000;
        func_ov014_020977e8(msg->obj, local);
        func_ov014_02099dd8(msg->obj);
        {
            Unk_ov088_Obj* obj = &data_ov008_02064f08->unk1e96b0;
            u32 t = obj->vf02();
            u32 base = obj->unk34;
            obj = msg->obj;
            u32 r8 = t + base - obj->unk20;
            func_ov013_0208aa40(&obj->unk100, 1, 0, 0);
            u32 r7 = func_ov013_0208a844(0x6000, 0x6000, r8 + 0x3000);
            u32 r = func_ov013_0208a9b8(0x6000, 0x6000, r8 + 0x3000);
            func_ov013_0208a2c0(&obj->unk100, r7, r8 + 0x3000, 0x6000, r);
        }
    }
        // fall through
    case 10: {
        if (func_ov088_020cb32c(self, msg->obj, 0) == 3) {
            return 0x32;
        }
        Unk_ov088_Obj* obj = msg->obj;
        func_02043a34(func_02043e30(obj->unk2e), 0, 0x40b40000);
        obj->unk2e = func_02043d98();
        if (msg->obj->unk100.unk0c != 0) {
            return 0xa;
        }
        return 0x64;
    }
    case 50: {
        msg->obj->vf12();
        msg->obj->unk3c |= 0x200;
        Unk_ov088_Ret* r4 = func_ov015_020a0f98((u8*)data_ov008_02064f08 + 0x25be8, 0xdd, 0);
        r4->unk40 = 0x2000;
        func_ov014_0209799c((u8*)r4 + 0xc, msg->obj, 0);
        data_ov016_020b8900.unk00 = 0x38066;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        u16 unkC = msg->obj->unkC;
        data_ov016_020b8900.unk0c = unkC;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144((u8*)data_ov008_02064f08 + 0x254 + 0x2cc00, &data_ov016_020b8900, unkC);
        s32 off = ((s32*)r4->vtbl)[-3];
        Unk_ov088_Sub2* sub = (Unk_ov088_Sub2*)((u8*)r4 + off);
        func_ov013_0208a300(&msg->obj->unk100, sub->unk16);
    }
        // fall through
    case 100:
        func_ov014_02099bd4(msg->obj);
        // fall through
    case 110:
        if (msg->obj->unk100.unk0c != 0) {
            return 0x6e;
        }
        self->unk28++;
        if (msg->obj != NULL) {
            msg->obj->vf03();
        }
        msg->obj = NULL;
        return -1;
    default:
        return 0;
    }
}
