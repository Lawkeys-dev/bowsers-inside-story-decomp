#include "types.h"

struct Unk_ov088_Param {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8 unk04[0x24 - 0x04];
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
};

struct Unk_ov088_Sub {
    /* 0x00 */ u8 unk00[0x0c];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x44 - 0x0e];
    /* 0x44 */ u16 unk44;
};

class Unk_ov088_Obj {
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
    virtual void v17();
    /* 0x48 */ virtual void v18(s32 a, s32 b, s32 c, s32 d);
    /* 0x04 */ u8 unk04[0x0c - 0x04];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x20 - 0x0e];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2c */ u8 unk2c[0x3c - 0x2c];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u8 unk40[0x100 - 0x40];
    /* 0x100 */ Unk_ov088_Sub unk100;
    /* 0x146 */ u8 unk146[0x1c0 - 0x146];
    /* 0x1c0 */ u32 unk1c0;
};

class Unk_ov088_Other {
public:
    /* 0x00 vptr */ virtual void v0();
    virtual void v1();
    virtual s32 v2();
};

struct Unk_ov088_Ctx;

typedef u32 (Unk_ov088_Ctx::*Unk_ov088_pmf)();

struct Unk_ov088_Ctx {
    /* 0x00 */ s16 state;
    /* 0x02 */ u8 unk02[0x04 - 0x02];
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0c */ s32 counter;
    /* 0x10 */ u8 unk10[0x14 - 0x10];
    /* 0x14 */ Unk_ov088_Obj* obj;
    /* 0x18 */ Unk_ov088_pmf fn18;
};

struct Unk_ov088_Msg {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

struct Unk_ov088_Data {
    /* 0x00 */ u8 unk00[0x1c];
    /* 0x1c */ Unk_ov088_pmf pmf1c;
    /* 0x24 */ u8 unk24[0x84 - 0x24];
    /* 0x84 */ Unk_ov088_pmf pmf84;
};

struct Unk_ov088_Ent {
    /* 0x00 */ u8 unk00[0x0c];
    /* 0x0c */ u16 unk0c;
};

struct Unk_ov088_Eff {
    /* 0x00 */ u8 unk00[0x40];
    /* 0x40 */ u32 unk40;
};

extern "C" Unk_ov088_Msg data_ov016_020b8900;
extern "C" Unk_ov088_Data data_ov088_020cd2e0;
extern "C" u8* data_ov008_02064f08;
extern "C" s16 data_0204b1dc[];

extern "C" {
s32 func_ov088_020cb32c(Unk_ov088_Param* p, Unk_ov088_Obj* obj, s32 arg);
s32 func_ov088_020caefc(Unk_ov088_Param* p);
void func_ov016_020ad144(u8* heap);
Unk_ov088_Eff* func_ov015_020a0f98(u8* heap, s32 id, s32 flag);
void func_ov015_0209fab0(u8* p, u16 v);
void func_ov014_020977e8(Unk_ov088_Obj* obj, s32* pos);
void func_ov013_0208a300(Unk_ov088_Sub* sub, s32 v);
double func_02043df0(u32 x);
double func_02043a34(double a, double b);
s32 func_02043d4c(double a);
void func_ov013_0208aa40(Unk_ov088_Sub* sub, s32 a, s32 b, s32 c);
s32 func_ov013_0208a844(s32 a, s32 b, s32 c);
s32 func_ov013_0208a9b8(s32 a, s32 b, s32 c);
void func_ov013_0208a2c0(Unk_ov088_Sub* sub, s32 a, s32 b, s32 c, s32 d);
void func_ov014_0209aea4(Unk_ov088_Obj* obj, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
s32 func_ov014_0209a0a4(Unk_ov088_Obj* obj, s32 a);
s32 func_ov014_0209a15c(Unk_ov088_Obj* obj, u16 a);
Unk_ov088_Ent* func_ov011_02066dac(u8* heap, s32 id);
void func_ov014_02099bd4(Unk_ov088_Obj* obj);
void func_ov015_020a8a5c(u32 a, s32 b, u8* c, s32 d, s32 e, s32 f, s32 g, s32 h);
void func_ov014_0209799c(u8* p, Unk_ov088_Obj* obj, s32 x);
}

// TODO: 98.44% match. Remaining differences: the original has an extra
// `cmpgt r0, #1` after `cmp r0, #2` in the counter dispatch (if-chain, counter <= 2 / <= 4);
// none of the if/else/switch variants tried reproduced it (a switch gives a jump table).
// Also the register/order of the (ctx->unk04 >> 4) index and the data_0204b1dc load
// around pos[0] differs (a separate `idx` local gives the wrong register).
extern "C" s32 func_ov088_020cb66c(Unk_ov088_Param* p, Unk_ov088_Ctx* ctx) {
    s32 ret = func_ov088_020cb32c(p, ctx->obj, 0);
    if (ret == 1) {
        ctx->counter -= 1;
        if (ctx->counter == 0) {
            ctx->fn18 = data_ov088_020cd2e0.pmf84;
            return 0;
        }

        data_ov016_020b8900.unk00 = 0x42000c;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = ctx->obj->unk0c;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);

        if (ctx->counter <= 2) {
            ctx->obj->v18(10, -1, 0x100, 0);
        } else if (ctx->counter <= 4) {
            ctx->obj->v18(9, -1, 0x100, 0);
        } else {
            ctx->obj->v18(8, -1, 0x100, 0);
        }
        Unk_ov088_Eff* eff = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0x161, 0);
        eff->unk40 = 0x2000;
        func_ov015_0209fab0(eff->unk00 + 0x0c, ctx->obj->unk0c);
    } else if (ret == 3) {
        ctx->fn18 = data_ov088_020cd2e0.pmf1c;
        return 0;
    }

    switch (ctx->state) {
    case 0:
        if (ctx->obj->unk100.unk0c != 0 || ctx->obj->unk100.unk44 != 0) {
            return 0;
        }
        ctx->unk04 = 0x8000;
        ctx->unk08 = ctx->obj->unk28 / 256;
        func_ov013_0208a300(&ctx->obj->unk100, 0x226);
        // fall through
    case 0x1e: {
        s32 v = func_02043d4c(func_02043a34(func_02043df0(ctx->unk04), 384.0));
        ctx->unk04 = v;
        if (v >= 0x10000) {
            ctx->unk04 = v - 0x10000;
        }

        s32 pos[3];
        pos[0] = ctx->obj->unk20;
        s16 sx = data_0204b1dc[(ctx->unk04 >> 4) * 2];
        pos[1] = ctx->obj->unk24;
        pos[2] = ((sx / 16) << 3) + (ctx->unk08 << 8);
        func_ov014_020977e8(ctx->obj, pos);

        if (func_ov088_020caefc(p) == 0 && p->unk26 == p->unk28) {
            ctx->obj->v12();
        }

        if (ctx->obj->unk100.unk0c != 0) {
            if (*(s16*)(data_ov008_02064f08 + 0x2f14e) > 0) {
                return 0x1e;
            }
        }

        ctx->obj->v12();
        Unk_ov088_Other* other = (Unk_ov088_Other*)(data_ov008_02064f08 + 0x1e96b0);
        s32 v8 = other->v2();
        Unk_ov088_Obj* obj = ctx->obj;
        s32 r7 = obj->unk20 - v8 - 0x2000;
        func_ov013_0208aa40(&obj->unk100, -1, 0, 0);
        s32 r5 = func_ov013_0208a844(0, 0x8000, r7);
        s32 r0v = func_ov013_0208a9b8(0, 0x8000, r7);
        func_ov013_0208a2c0(&obj->unk100, r5, r7, 0, r0v);

        data_ov016_020b8900.unk00 = 0x42000b;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = ctx->obj->unk0c;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
        func_ov014_0209aea4(ctx->obj, 0, 1, 6, 0x1d, 0, 0);
    }
        // fall through
    case 0x64: {
        s32 idx = func_ov014_0209a0a4(ctx->obj, 0);
        if (idx > 0) {
            Unk_ov088_Ent* e = func_ov011_02066dac(data_ov008_02064f08, func_ov014_0209a15c(ctx->obj, (u16)idx));
            if (e != NULL) {
                Unk_ov088_Ent* ref = *(Unk_ov088_Ent**)(data_ov008_02064f08 + 0x2f12c);
                if (e->unk0c == ref->unk0c && *(s16*)(data_ov008_02064f08 + 0x2f14e) > 0) {
                    return 0x6e;
                }
            }
        }
        if (ctx->obj->unk100.unk0c != 0) {
            return 0x64;
        }
        return 0x78;
    }
    case 0x6e:
        ctx->obj->unk3c |= 0x200;
        func_ov014_02099bd4(ctx->obj);
        ctx->obj->v12();
        ctx->obj->unk1c0 = 0;
        if (*(s16*)(data_ov008_02064f08 + 0x2f14e) > 0) {
            func_ov015_020a8a5c(p->unk00, 0, data_ov008_02064f08 + 0x2f11c, 0x100, 0, 5, 0, 0);
        }
        {
            Unk_ov088_Eff* eff = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0x148, 0);
            eff->unk40 = 0x2000;
            func_ov014_0209799c(eff->unk00 + 0x0c, ctx->obj, 0);
            Unk_ov088_Ent* ref = *(Unk_ov088_Ent**)(data_ov008_02064f08 + 0x2f12c);
            func_ov015_0209fab0(eff->unk00 + 0x0c, ref->unk0c);
        }
        func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0x149, 1);

        data_ov016_020b8900.unk00 = 0x42800a;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = ctx->obj->unk0c;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
        // fall through
    case 0x78:
        func_ov014_02099bd4(ctx->obj);
        ctx->obj->unk1c0 = 0;
        p->unk24 += 1;
        if (ctx->obj != NULL) {
            ctx->obj->v3();
        }
        ctx->obj = NULL;
        return -1;
    default:
        return 0;
    }
}
