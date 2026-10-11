#include "types.h"

struct Unk_ov088_Pair {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
};

class Unk_ov088_mgr {
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
    /* 0x04 */ u8 pad04[0xec - 0x04];
    /* 0xec */ void *unkEc;
};

struct Unk_ov088_obj {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ Unk_ov088_mgr *mgr;
};

struct Unk_ov088_020cd0d8 {
    /* 0x00 */ Unk_ov088_obj *obj;
    /* 0x04 */ s32 state;
    /* 0x08 */ u16 unk08;
};

extern "C" Unk_ov088_Pair data_ov088_020cd34c;
extern "C" u8 *data_ov008_02064f08;

extern "C" s32 func_ov014_020961bc(void *p, s32 a);
extern "C" s32 func_ov014_02096360(void *p);
extern "C" s32 func_ov015_020a7aac(void *p);
extern "C" s32 func_ov015_020ac67c(void *p);
extern "C" void func_ov088_020c94b4(void *self, Unk_ov088_Pair pair, u32 c, u32 d);
extern "C" void func_ov088_020c9988(void *self, s32 a);
extern "C" s32 func_ov120_020d4954(void *p);
extern "C" s32 func_ov120_020d53c0();
extern "C" void func_ov013_0208a300(void *p, s32 a);

extern "C" s32 func_ov088_020cd0d8(Unk_ov088_020cd0d8 *self) {
    u8 *g;
    s32 r;

    switch (self->state) {
    case 0:
        self->obj->mgr->v18(0x1b, 0x1b - 0x1c, 0x100, 0);
        if (self->obj->mgr->unkEc != NULL) {
            func_ov014_020961bc(self->obj->mgr->unkEc, 1);
        }
        // fall through
    case 10:
        if (self->obj->mgr->unkEc != NULL) {
            r = func_ov014_02096360(self->obj->mgr->unkEc);
        } else {
            r = 1;
        }
        if (r == 0) {
            return 0xa;
        }
        func_ov088_020c94b4(self, data_ov088_020cd34c, 0, 0);
        func_ov088_020c9988(self, 0);
        // fall through
    case 100:
        if (self->unk08 != 0) {
            return 100;
        }
        // fall through
    case 110:
        if (func_ov120_020d4954(data_ov008_02064f08 + 0x1e96ec) != 0) {
            return 110;
        }
        if (func_ov015_020ac67c(self->obj) != 0) {
            func_ov015_020a7aac(self->obj);
        }
        g = data_ov008_02064f08;
        func_ov015_020a7aac(g + 0x2f000 + 0x11c);
        g = data_ov008_02064f08;
        func_ov013_0208a300(*(u8 **)(g + 0x2f000 + 0x12c) + 0x100, 0xc);
        // fall through
    case 120:
        g = data_ov008_02064f08;
        if (*(u16 *)(*(u8 **)(g + 0x2f000 + 0x12c) + 0x100 + 0xc) != 0) {
            return 120;
        }
        // fall through
    case 150:
        if (func_ov120_020d53c0() != 0) {
            return 150;
        }
        return -1;
    default:
        return 0;
    }
}
