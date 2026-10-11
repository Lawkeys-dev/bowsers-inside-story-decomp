#include "types.h"

struct Unk_ov088_Obj;

struct Unk_ov088_Ec {
    /* 0x00 */ u8 pad00[0x30];
    /* 0x30 */ s16 unk30;
};

class Unk_ov088_Obj {
public:
    /* 0x00 vptr */ virtual void v0();
    virtual void v1();
    virtual void v2();
    /* 0x0c */ virtual void v3();
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
    virtual void v17();
    /* 0x48 */ virtual void v18(s32 a, s32 b, s32 c, s32 d);
    /* 0x04 */ u8 pad04[0x8];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 pad0e[0x12];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x4];
    /* 0x28 */ s32 unk28;
    /* 0x2c */ u8 pad2c[0x2];
    /* 0x2e */ u16 unk2e;
    /* 0x30 */ u8 pad30[0xc];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u8 pad40[0xac];
    /* 0xec */ Unk_ov088_Ec* unkec;
};

struct Unk_ov088_Task {
    /* 0x00 */ s16 state;
    /* 0x02 */ u8 pad02[0x12];
    /* 0x14 */ Unk_ov088_Obj* obj;
};

struct Unk_ov088_Ctx {
    /* 0x00 */ void* unk00;
    /* 0x04 */ u8 pad04[0x20];
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 pad26[0x2];
    /* 0x28 */ s16 unk28;
};

struct Unk_ov088_Eff {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ u8 sub0c[0x34];
    /* 0x40 */ s32 unk40;
};

struct Unk_ov088_Sub {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 pad0e[0x36];
    /* 0x44 */ u16 unk44;
};

struct Unk_ov088_Cfg {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

class Unk_ov088_VObj {
public:
    /* 0x00 vptr */ virtual void v0();
    virtual void v1();
    /* 0x08 */ virtual s32 v2();
};

struct Unk_ov088_Vec {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
};

extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov088_Cfg data_ov016_020b8900;

extern "C" Unk_ov088_Eff* func_ov015_020a0f98(u8* mgr, s32 id, s32 flag);
extern "C" void func_ov014_0209799c(u8* a, Unk_ov088_Obj* b, s32 c);
extern "C" void func_ov015_0209fab0(u8* a, u16 b);
extern "C" void func_ov016_020ad144(u8* a);
extern "C" void func_ov015_020a8a5c(void* a, s32 b, u8* c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void func_ov014_02097a20(u8* a, Unk_ov088_Obj* b, s32 c, s32 d, s32 e);
extern "C" void func_ov013_0208aa40(u8* a, s32 b, s32 c, s32 d);
extern "C" s32 func_ov013_0208a5ac(s32 a, s32 b, s32 c, s32 d);
extern "C" s32 func_ov013_0208a610(s32 a, s32 b);
extern "C" void func_ov013_0208a2c0(u8* a, s32 b, s32 c, s32 d, s32 e);
extern "C" void func_ov013_0208aa60(u8* a, Unk_ov088_Vec* b);
extern "C" void func_ov013_0208a2a0(u8* a, s32 b);
extern "C" s64 func_02043e30(u16 a);
extern "C" void func_02043a34(s64 a, s32 b, float c);
extern "C" u16 func_02043d98();

extern "C" s32 func_ov088_020cccf8(void* ctx, Unk_ov088_Task* task) {
    Unk_ov088_Ctx* self = (Unk_ov088_Ctx*)ctx;
    switch (task->state) {
    case 0: {
        Unk_ov088_Obj* obj = task->obj;
        Unk_ov088_Ec* ec = obj->unkec;
        s32 st = (ec != NULL) ? ec->unk30 : 0;
        if (st == 5) {
            obj->unk3c |= 0x200;
            Unk_ov088_Eff* eff = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0x146, 0);
            eff->unk40 = 0x2000;
            func_ov014_0209799c(eff->sub0c, task->obj, 0);
            func_ov015_0209fab0(eff->sub0c, ((Unk_ov088_Sub*)(*(u8**)(data_ov008_02064f08 + 0x2f000 + 0x12c)))->unk0c);
            func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xde, 1);
            data_ov016_020b8900.unk00 = 0x38066;
            data_ov016_020b8900.unk04 = 0;
            data_ov016_020b8900.unk06 = 0;
            data_ov016_020b8900.unk08 = 1;
            data_ov016_020b8900.unk0a = 0x7f;
            data_ov016_020b8900.unk0b = 0;
            data_ov016_020b8900.unk0c = task->obj->unk0c;
            data_ov016_020b8900.unk0e = 0x7f;
            func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
            if (*(s16*)(data_ov008_02064f08 + 0x2f14e) > 0) {
                func_ov015_020a8a5c(self->unk00, 0, data_ov008_02064f08 + 0x11c + 0x2f000, 0x80, 0, 5, 0, 0);
            }
            return 100;
        }
        obj->v18(3, -1, 0x100, 0);
        if (*(s16*)(data_ov008_02064f08 + 0x2f14e) > 0) {
            func_ov015_020a8a5c(self->unk00, 0, data_ov008_02064f08 + 0x11c + 0x2f000, 0x80, 0, 5, 0, 0);
        }
        Unk_ov088_Eff* eff2 = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xdb, 0);
        eff2->unk40 = 0x2000;
        func_ov015_0209fab0(eff2->sub0c, ((Unk_ov088_Sub*)(*(u8**)(data_ov008_02064f08 + 0x2f000 + 0x12c)))->unk0c);
        s32 t = 0x1000;
        func_ov014_02097a20(eff2->sub0c, task->obj, t - 0x2400, 0, t);
        data_ov016_020b8900.unk00 = 0x3001d;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = task->obj->unk0c;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
        Unk_ov088_Obj* o = task->obj;
        s32 neg = -o->unk28;
        func_ov013_0208aa40((u8*)o + 0x100, 0, 0, 1);
        s32 r4 = func_ov013_0208a5ac(0x1000, 0x3000, neg, 1);
        s32 r0v = func_ov013_0208a610(0x1000, 0x3000);
        func_ov013_0208a2c0((u8*)o + 0x100, r4, neg, 0x3000, r0v);
        Unk_ov088_VObj* vo = (Unk_ov088_VObj*)(data_ov008_02064f08 + 0x1e96b0);
        s32 v = vo->v2();
        Unk_ov088_Vec vec;
        vec.x = v - task->obj->unk20 - 0xc800;
        vec.y = 0;
        vec.z = 0;
        Unk_ov088_Obj* p = task->obj;
        func_ov013_0208aa60((u8*)p + 0x138, &vec);
        func_ov013_0208a2a0((u8*)p + 0x138, (u16)r4);
    }
        // fall through
    case 10: {
        Unk_ov088_Obj* obj = task->obj;
        s64 v = func_02043e30(obj->unk2e);
        func_02043a34(v, 0, 4.625f);
        obj->unk2e = func_02043d98();
        if (((Unk_ov088_Sub*)((u8*)task->obj + 0x100))->unk0c != 0 || ((Unk_ov088_Sub*)((u8*)task->obj + 0x100))->unk44 != 0) {
            return 10;
        }
    }
        // fall through
    case 100: {
        self->unk24 += 1;
        self->unk28 += 1;
        Unk_ov088_Obj* obj = task->obj;
        if (obj != NULL) {
            obj->v3();
        }
        task->obj = NULL;
        return -1;
    }
    default:
        return 0;
    }
}
