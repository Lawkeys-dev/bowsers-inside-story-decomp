#include "types.h"

class Unk_ov088_Inner {
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
    /* 0x04 */ u8 unk04[0x1c];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 unk24[0xc8];
    /* 0xec */ void* unkEc;
    /* 0xf0 */ u8 unkF0[0x10];
    /* 0x100 */ u8 unk100[0xc];
    /* 0x10c */ u16 unk10c;
};

struct Unk_ov088_Ctx {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ Unk_ov088_Inner* inner;
};

struct Unk_ov088_Self {
    /* 0x00 */ Unk_ov088_Ctx* ctx;
    /* 0x04 */ u8 unk04[0x14];
    /* 0x18 */ s32 unk18;
};

struct Unk_ov088_Arg {
    /* 0x00 */ s16 state;
    /* 0x02 */ u8 unk02[2];
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk8;
};

struct Unk_ov014_Obj {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ s32 unk20;
};

struct Unk_ov088_Global {
    /* 0x00 */ u8 unk00[0x2f12c];
    /* 0x2f12c */ Unk_ov014_Obj* obj;
};

extern "C" Unk_ov088_Global* data_ov008_02064f08;

extern "C" void func_ov014_02097a48(Unk_ov014_Obj* obj, s32* out, s32 zero);
extern "C" void func_ov014_020977e8(Unk_ov088_Inner* inner, s32* pos);
extern "C" void func_ov014_020961bc(void* p, s32 a);
extern "C" s32 func_ov014_02096360(void* p);
extern "C" u64 func_02043df0(void* p);
extern "C" s32 func_02043d4c(u64 v);
extern "C" void func_ov013_0208aa40(void* p, s16 dir, s32 a, s32 b);
extern "C" s32 func_ov013_0208a844(s32 a, s32 b, s32 c);
extern "C" s32 func_ov013_0208a9b8(s32 a, s32 b, s32 c);
extern "C" void func_ov013_0208a2c0(void* p, s32 a, s32 b, s32 c, s32 d);

// TODO: 96.82%. Remaining diff: mwcc re-materialises the constant 0 for the stack argument of the case 0 v18 call
// (original stores one zero before the dir compare, we store it after the compare). A zero local does not help.
extern "C" s32 func_ov088_020c9a40(Unk_ov088_Self* self, Unk_ov088_Arg* arg) {
    s32 x;
    s32 dir;
    s32 dist;
    s32 d;
    s32 y;
    s32 pos[3];
    s32 r;

    switch (arg->state) {
    case 0:
        self->ctx->inner->v12();
        if (self->ctx->inner->unk20 - data_ov008_02064f08->obj->unk20 >= 0x21200) {
            func_ov014_02097a48(data_ov008_02064f08->obj, &pos[0], 0);
            pos[0] += 0x21c00;
            pos[2] = 0;
            func_ov014_020977e8(self->ctx->inner, &pos[0]);
        }
        d = data_ov008_02064f08->obj->unk20 + 0x17c00 - self->ctx->inner->unk20;
        if (d > 0) {
            dir = 1;
        } else {
            dir = -1;
        }
        self->unk18 = 0;
        dist = (d <= 0) ? -d : d;
        if (dir > 0) {
            self->ctx->inner->v18(6, 6 - 7, 0x100, 0);
        } else {
            self->ctx->inner->v18(5, 5 - 6, 0x100, 0);
        }
        x = func_02043d4c(arg->unk4 != NULL ? func_02043df0(arg->unk4) : 0x40C8000000000000ULL);
        y = func_02043d4c(arg->unk8 != NULL ? func_02043df0(arg->unk8) : 0x40C8000000000000ULL);
        {
            Unk_ov088_Inner* inner = self->ctx->inner;
            s32 res1;
            s32 res2;

            func_ov013_0208aa40(&inner->unk100, (s16)dir, 0, 0);
            res1 = func_ov013_0208a844(x, y, dist);
            res2 = func_ov013_0208a9b8(x, y, dist);
            func_ov013_0208a2c0(&inner->unk100, res1, dist, x, res2);
        }
        /* fall through */
    case 10:
        if (self->ctx->inner->unk10c != 0) {
            return 10;
        }
        if (self->ctx->inner->unkEc != NULL) {
            func_ov014_020961bc(self->ctx->inner->unkEc, 1);
        }
        /* fall through */
    case 20:
        if (self->ctx->inner->unkEc != NULL) {
            r = func_ov014_02096360(self->ctx->inner->unkEc);
        } else {
            r = 1;
        }
        if (r == 0) {
            return 0x14;
        }
        self->ctx->inner->v18(0, 0 - 1, 0x100, 0);
        return -1;
    default:
        return 0;
    }
}
