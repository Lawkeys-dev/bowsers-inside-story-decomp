#include "types.h"

extern "C" BOOL func_ov014_02096360(void *param);
extern "C" u8 *data_ov008_02064f08;

struct Unk_ov085_020c97b0_8;

struct Unk_ov085_020c97b0 {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ Unk_ov085_020c97b0_8 *unk8;
};

struct Unk_ov085_020c97b0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18(s32 a, s32 b, s32 c, s32 d);
    /* 0x4 */ u8 unk4[0xEC - 4];
    /* 0xEC */ void *unkEC;
};

extern "C" void func_ov085_020c97b0(Unk_ov085_020c97b0 *param) {
    Unk_ov085_020c97b0_8 *inner = param->unk8;
    BOOL ok;
    if (inner->unkEC == NULL) {
        ok = TRUE;
    } else {
        ok = func_ov014_02096360(inner->unkEC);
    }
    if (ok) {
        inner->vf18(0xd, -1, 0x100, 0);
        u8 *p = data_ov008_02064f08 + 0x2d000;
        *(s32 *)(p + 0x4ac) = 1;
        param->unk0 = 0;
    }
}
