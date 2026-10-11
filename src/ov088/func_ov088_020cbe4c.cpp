#include "types.h"

class Unk_ov088_020cbe4c_Obj {
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
    /* 0x44 */ virtual void v17(u32 arg);
    /* 0x48 */ virtual void v18(s32 a, s32 b, s32 c, s32 d);
    /* 0x04 */ u8 unk04[0x8];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x1e];
    /* 0x2c */ s16 unk2c;
    /* 0x2e */ u8 unk2e[0x6];
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u8 unk38[0x4];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u8 unk40[0xb0];
    /* 0xf0 */ u32 unkF0;
};

struct Unk_ov088_020cbe4c_Mgr {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ u32 unk10;
};

struct Unk_ov088_020cbe4c_Self {
    /* 0x00 */ Unk_ov088_020cbe4c_Mgr* mgr;
    /* 0x04 */ u8 unk04[0x22];
    /* 0x26 */ s16 counter;
};

struct Unk_ov088_020cbe4c_Res {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
};

struct Unk_ov088_020cbe4c_State {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 id;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0c */ u32 unk0c;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ Unk_ov088_020cbe4c_Obj* obj;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u32 unk1c;
};

struct Unk_ov088_020cbe4c_Global {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

struct Unk_ov088_020cbe4c_Table {
    /* 0x00 */ u8 unk00[0x34];
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u32 unk38;
};

extern "C" u32 data_ov008_02064f08;
extern "C" Unk_ov088_020cbe4c_Global data_ov016_020b8900;
extern "C" Unk_ov088_020cbe4c_Table data_ov088_020cd2e0;

extern "C" void* func_ov015_020a7ad4(void* mgr, u16 id, u32 zero, s32 minusOne);
extern "C" u32 func_ov011_02066c28(u32 a, u32 b);
extern "C" void* func_ov015_020a0f98(u32 base, u32 b, u32 c);
extern "C" void func_ov014_0209799c(void* p, Unk_ov088_020cbe4c_Obj* obj, u32 zero);
extern "C" void func_ov015_0209fab0(void* p, u32 v);
extern "C" void func_ov014_02097a20(Unk_ov088_020cbe4c_Obj* obj, u32 a, u32 b, u32 c, u32 d);
extern "C" void func_ov014_02099d84(Unk_ov088_020cbe4c_Obj* obj);
extern "C" Unk_ov088_020cbe4c_Res* func_ov088_020cb0cc(Unk_ov088_020cbe4c_Self* self, s32 v);
extern "C" s32 func_0201cf78(s32 v);
extern "C" u32 func_ov013_0208a844(u32 a, u32 b, u32 c);
extern "C" u32 func_ov013_0208a9b8(u32 a, u32 b, u32 c);
extern "C" void func_ov013_0208aa40(void* p, s32 a, u32 b, u32 c);
extern "C" void func_ov013_0208aa60(void* p, s32* v);
extern "C" void func_ov013_0208a2a0(void* p, u32 v);
extern "C" void func_ov013_0208a2c0(void* p, u32 a, u32 b, u32 c, u32 d);
extern "C" void func_ov016_020ad144(u32 p);

// TODO: 98.47%. Left: the object pointer register (r7 in the original, r12 for the unk3c update and r8 in
// the 0x100/0x138 blocks), which swaps the negated value with it (r8 vs r7), and the r0/r1 swap for the
// 0x2 store and the data pointer before the unk18/unk1c copy.
extern "C" s32 func_ov088_020cbe4c(Unk_ov088_020cbe4c_Self* self, Unk_ov088_020cbe4c_State* state) {
    Unk_ov088_020cbe4c_Obj* obj;
    Unk_ov088_020cbe4c_Res* res;
    s32 vec[3];
    s32 diff;
    s32 sign;
    u32 h;
    u32 ret;

    self->counter++;
    state->obj = (Unk_ov088_020cbe4c_Obj*)func_ov015_020a7ad4(self->mgr, state->id, 0, -1);
    u32 v = func_ov011_02066c28(data_ov008_02064f08, 0xa001);
    state->obj->v17(v);
    state->obj->v18(2, 2 - 3, 0x100, 0);
    state->obj->unk34 = 0x2000;
    state->obj->unk2c = -8;
    state->obj->unkF0 = (state->obj->unkF0 & ~0x1f000000) | 0x2000000;
    obj = state->obj;
    obj->unk3c = (obj->unk3c & 0xff803fff) | 0x7b0000;
    u32 c = 0x4c00;
    func_ov014_02097a20(state->obj, self->mgr->unk10, c - 0x6600, 0, c);

    {
        void* p = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xda, 1);
        func_ov014_0209799c((u8*)p + 0xc, state->obj, 0);
        func_ov015_0209fab0((u8*)p + 0xc, state->obj->unk0c);
    }

    res = func_ov088_020cb0cc(self, (s16)state->unk04);

    s32 r8 = -((s32)res->unk00 << 8);
    {
        obj = state->obj;
        func_ov013_0208aa40((u8*)obj + 0x100, -1, 0, 0);
        h = func_ov013_0208a844(0x2000, 0x4000, r8);
        func_ov013_0208a2c0((u8*)obj + 0x100, h, r8, 0x2000, func_ov013_0208a9b8(0x2000, 0x4000, r8));
    }

    data_ov016_020b8900.unk00 = 0x42000b;
    data_ov016_020b8900.unk04 = 0;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0a = 0x7f;
    data_ov016_020b8900.unk0b = 0;
    data_ov016_020b8900.unk0c = state->obj->unk0c;
    data_ov016_020b8900.unk0e = 0x7f;
    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);

    if (res->unk04 > res->unk06) {
        diff = res->unk04 - res->unk06;
        sign = -1;
    } else {
        diff = res->unk06 - res->unk04;
        sign = 1;
    }
    ret = func_0201cf78(diff);
    s32 r3 = res->unk04 + ret * sign;

    vec[0] = 0;
    vec[1] = res->unk02 << 8;
    vec[2] = r3 << 8;
    {
        obj = state->obj;
        func_ov013_0208aa60((u8*)obj + 0x138, vec);
        func_ov013_0208a2a0((u8*)obj + 0x138, (u16)h);
    }

    state->unk10 = 0;
    if (res->unk08 == 0) {
        state->unk04 = 0x8000;
    } else {
        if (res->unk08 == 1) {
            state->unk04 = 0;
        } else {
            state->unk10 = 0x190;
        }
    }
    func_ov014_02099d84(state->obj);
    state->unk0c = 2;
    state->unk18 = data_ov088_020cd2e0.unk34;
    state->unk1c = data_ov088_020cd2e0.unk38;
    return 0;
}
