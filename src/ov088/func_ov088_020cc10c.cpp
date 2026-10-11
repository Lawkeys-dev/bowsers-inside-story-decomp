#include "types.h"

struct Unk_ov088_020cc10c_Sub {
    /* 0x00 */ u8 unk00[0x0c];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x44 - 0x0e];
    /* 0x44 */ u16 unk44;
};

class Unk_ov088_020cc10c_Obj {
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
    /* 0x30 */ virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    /* 0x48 */ virtual void v18(s32 a, s32 b, s32 c, s32 d);
    /* 0x04 */ u8 unk04[0x08];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x20 - 0x0e];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2c */ u8 unk2c[0x5c - 0x2c];
    /* 0x5c */ s32 unk5c;
    /* 0x60 */ u8 unk60[0x100 - 0x60];
    /* 0x100 */ Unk_ov088_020cc10c_Sub sub100;
};

struct Unk_ov088_020cc10c_Owner {
    /* 0x00 */ u8 unk00[0x24];
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 unk26[2];
    /* 0x28 */ s16 unk28;
};

struct Unk_ov088_020cc10c_This;

typedef u32 (Unk_ov088_020cc10c_This::*Unk_ov088_020cc10c_pmf)();

struct Unk_ov088_020cc10c_Ctx {
    /* 0x00 */ s16 state;
    /* 0x02 */ u8 unk02[2];
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0c */ s32 unk0c;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ Unk_ov088_020cc10c_Obj *obj;
    /* 0x18 */ Unk_ov088_020cc10c_pmf fn18;
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

struct Unk_ov088_020cd2e0 {
    /* 0x00 */ u8 unk00[0x2c];
    /* 0x2c */ Unk_ov088_020cc10c_pmf pmf2c;
    /* 0x34 */ u8 unk34[0x44 - 0x34];
    /* 0x44 */ Unk_ov088_020cc10c_pmf pmf44;
    /* 0x4c */ u8 unk4c[0x54 - 0x4c];
    /* 0x54 */ Unk_ov088_020cc10c_pmf pmf54;
};

struct Unk_ov088_020cd4e0 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0c */ s32 unk0c;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
};

struct Unk_0204b1dc {
    /* 0x00 */ s16 val;
    /* 0x02 */ u16 unk02;
};

class Unk_ov088_VObj {
public:
    /* 0x00 vptr */ virtual void v0();
    virtual void v1();
    /* 0x08 */ virtual s32 v2();
};

extern "C" u8 *data_ov008_02064f08;
extern "C" Unk_ov016_020b8900 data_ov016_020b8900;
extern "C" Unk_ov088_020cd2e0 data_ov088_020cd2e0;
extern "C" Unk_ov088_020cd4e0 data_ov088_020cd4e0;
extern "C" Unk_0204b1dc data_0204b1dc[];

extern "C" s32 func_ov088_020cb32c(void *owner, Unk_ov088_020cc10c_Obj *obj, s32 zero);
extern "C" void func_ov088_020cbe14(void *owner, Unk_ov088_020cc10c_Obj *obj);
extern "C" void func_ov016_020ad144(u8 *p);
extern "C" double func_02043df0(s32 a);
extern "C" double func_02043a34(double a, double b);
extern "C" s32 func_02043d4c(double a);
extern "C" double func_020441e8(double a, double b);
extern "C" void func_ov014_020977e8(Unk_ov088_020cc10c_Obj *obj);
extern "C" void func_ov014_02099bd4(Unk_ov088_020cc10c_Obj *obj);
extern "C" void func_ov013_0208aa40(void *p, s32 a, s32 b, s32 c);
extern "C" s32 func_ov013_0208a844(s32 a, s32 b, s32 c);
extern "C" s32 func_ov013_0208a9b8(s32 a, s32 b, s32 c);
extern "C" void func_ov013_0208a2c0(void *p, s32 a, s32 b, s32 c, s32 d);
extern "C" void func_ov013_0208aa60(void *p);
extern "C" void func_ov013_0208a2a0(void *p, s32 a);

// TODO: 75.5% match. Remaining diffs are mostly callee-saved register allocation: the original has angle r4, ctx r5,
// owner r6, obj r7, d0 r8, here the body obj local outranks ctx/owner (ctx r6, owner r7, obj r5). Without a body obj
// local, ctx/owner get r5/r6 but d0 falls to r7. Declaration scope, order and early/late obj definition did not change it.
// Also the case 0x1e `if (unk10 > 0 && data > 0)` block layout differs (original places the then-block out of line).
extern "C" s32 func_ov088_020cc10c(Unk_ov088_020cc10c_Owner *owner, Unk_ov088_020cc10c_Ctx *ctx) {
    s32 ret = func_ov088_020cb32c(owner, ctx->obj, 0);
    Unk_ov088_020cc10c_Obj *obj = ctx->obj;

    if (ret == 1) {
        data_ov016_020b8900.unk00 = 0x42000c;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = ctx->obj->unk0c;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
        s32 zero = 0;
        ctx->unk0c--;
        if (ctx->unk0c == 0) {
            owner->unk24++;
            ctx->fn18 = data_ov088_020cd2e0.pmf54;
            return zero;
        }
        ctx->obj->v18(5, 5 - 6, 0x100, zero);
    } else if (ret == 3) {
        ctx->fn18 = data_ov088_020cd2e0.pmf44;
        return 0;
    }

    switch (ctx->state) {
    case 0: {
        if (ctx->obj->sub100.unk0c != 0 || ctx->obj->sub100.unk44 != 0) {
            return 0;
        }
        ctx->unk08 = ctx->obj->unk28 / 256;
    }
        // fall through
    case 0x1e: {
        s32 r4;
        if (ctx->unk10 > 0 && *(s16 *)(data_ov008_02064f08 + 0x2f14e) > 0) {
            ctx->unk04 = func_02043d4c(func_02043a34(func_02043df0(ctx->unk04), 716.8));
            if (ctx->unk04 >= 0x10000) {
                ctx->unk04 -= 0x10000;
            }
            r4 = (data_0204b1dc[ctx->unk04 >> 4].val / 16) * 40;
            data_ov088_020cd4e0.unk0c = ctx->obj->unk20;
            ctx->unk10--;
            if (ctx->unk10 <= 0) {
                ctx->unk10 = -1;
                data_ov016_020b8900.unk00 = 0x42000b;
                data_ov016_020b8900.unk04 = 0;
                data_ov016_020b8900.unk06 = 0;
                data_ov016_020b8900.unk08 = 1;
                data_ov016_020b8900.unk0a = 0x7f;
                data_ov016_020b8900.unk0b = 0;
                data_ov016_020b8900.unk0c = ctx->obj->unk0c;
                data_ov016_020b8900.unk0e = 0x7f;
                func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
            }
        } else {
            if (ctx->unk10 == 0) {
                ctx->unk04 = func_02043d4c(func_02043a34(func_02043df0(ctx->unk04), 384.0));
                if (ctx->unk04 >= 0x10000) {
                    ctx->unk04 -= 0x10000;
                }
                r4 = (data_0204b1dc[ctx->unk04 >> 4].val / 16) * 50;
            } else {
                ctx->unk04 = func_02043d4c(func_02043a34(func_02043df0(ctx->unk04), 716.8));
                if (ctx->unk04 >= 0x10000) {
                    ctx->unk04 -= 0x10000;
                }
                r4 = (data_0204b1dc[ctx->unk04 >> 4].val / 16) * 40;
            }
            data_ov088_020cd4e0.unk0c = func_02043d4c(func_020441e8(func_02043df0(ctx->obj->unk20), 332.8));
        }
        // L_438
        data_ov088_020cd4e0.unk10 = ctx->obj->unk24;
        data_ov088_020cd4e0.unk14 = r4 + (ctx->unk08 << 8);
        func_ov014_020977e8(ctx->obj);
        if (*(s16 *)(data_ov008_02064f08 + 0x2f14e) > 0) {
            if (ctx->obj->unk20 - (*(Unk_ov088_020cc10c_Obj **)(data_ov008_02064f08 + 0x2f000 + 0x12c))->unk20 > 0xa000) {
                return 0x1e;
            }
        } else {
            Unk_ov088_VObj *vo = (Unk_ov088_VObj *)(data_ov008_02064f08 + 0x1e96b0);
            s32 t = vo->v2();
            if (ctx->obj->unk20 + 0x3000 >= t) {
                return 0x1e;
            }
            owner->unk24++;
            owner->unk28++;
            ctx->obj->v12();
            func_ov014_02099bd4(ctx->obj);
            if (ctx->obj != NULL) {
                ctx->obj->v3();
            }
            ctx->obj = NULL;
            return -1;
        }
        // L_534
        obj = ctx->obj;
        data_ov088_020cd4e0.unk00 = 0xf000 - obj->unk28;
        data_ov088_020cd4e0.unk08 = 1;
        if (data_ov088_020cd4e0.unk00 < 0) {
            data_ov088_020cd4e0.unk00 = -data_ov088_020cd4e0.unk00;
            data_ov088_020cd4e0.unk08 = -1;
        }
        s32 d0 = data_ov088_020cd4e0.unk00;
        func_ov013_0208aa40(&obj->sub100, 0, 0, (s16)data_ov088_020cd4e0.unk08);
        r4 = func_ov013_0208a844(0x999, 0x8000, d0);
        s32 tmp = func_ov013_0208a9b8(0x999, 0x8000, d0);
        func_ov013_0208a2c0(&obj->sub100, r4, d0, 0x999, tmp);
        data_ov088_020cd4e0.unk04 = r4;
        u16 r4u = (u16)r4;
        data_ov088_020cd4e0.unk0c = 0x7800 - (obj->unk20 - (*(Unk_ov088_020cc10c_Obj **)(data_ov008_02064f08 + 0x2f000 + 0x12c))->unk20);
        data_ov088_020cd4e0.unk10 = 0;
        data_ov088_020cd4e0.unk14 = 0;
        func_ov013_0208aa60((u8 *)obj + 0x138);
        func_ov013_0208a2a0((u8 *)obj + 0x138, r4u);
    }
        // fall through
    case 0x23: {
        if (ctx->obj->unk28 - ctx->obj->unk5c <= 0) {
            return 0x23;
        }
    }
        // fall through
    case 0x28: {
        s32 r4;
        func_ov088_020cbe14(owner, ctx->obj);
        if (ctx->obj->sub100.unk0c != 0 || ctx->obj->sub100.unk44 != 0) {
            return 0x28;
        }
        obj = ctx->obj;
        data_ov088_020cd4e0.unk00 = 0x9800 - obj->unk28;
        data_ov088_020cd4e0.unk08 = 1;
        if (data_ov088_020cd4e0.unk00 < 0) {
            data_ov088_020cd4e0.unk00 = -data_ov088_020cd4e0.unk00;
            data_ov088_020cd4e0.unk08 = -1;
        }
        s32 d1 = data_ov088_020cd4e0.unk00;
        func_ov013_0208aa40(&obj->sub100, 0, 0, (s16)data_ov088_020cd4e0.unk08);
        r4 = func_ov013_0208a844(0x199, 0x6000, d1);
        s32 tmp2 = func_ov013_0208a9b8(0x199, 0x6000, d1);
        func_ov013_0208a2c0(&obj->sub100, r4, d1, 0x199, tmp2);
        data_ov088_020cd4e0.unk04 = r4;
        u16 r4u = (u16)r4;
        data_ov088_020cd4e0.unk0c = 0x5200 - (obj->unk20 - (*(Unk_ov088_020cc10c_Obj **)(data_ov008_02064f08 + 0x2f000 + 0x12c))->unk20);
        data_ov088_020cd4e0.unk10 = 0;
        data_ov088_020cd4e0.unk14 = 0;
        func_ov013_0208aa60((u8 *)obj + 0x138);
        func_ov013_0208a2a0((u8 *)obj + 0x138, r4u);
    }
        // fall through
    case 0x32: {
        func_ov088_020cbe14(owner, ctx->obj);
        if (ctx->obj->sub100.unk0c != 0 || ctx->obj->sub100.unk44 != 0) {
            return 0x32;
        }
        func_ov014_02099bd4(ctx->obj);
        ctx->fn18 = data_ov088_020cd2e0.pmf2c;
        return 0;
    }
    default:
        return 0;
    }
    return 0;
}
