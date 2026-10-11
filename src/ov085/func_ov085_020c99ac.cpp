#include "types.h"

extern "C" s32 func_ov014_02096360(u32 arg);
extern "C" void func_ov085_020cae08(void *arg);
extern "C" u8 data_ov085_020cb2b8;

/* 0xf0 */
union Unk_ov085_020c99ac_word {
    u32 raw;
    struct {
        s32 lo : 12;
        s32 mid : 12;
        u32 hi : 8;
    } f;
};

/* object pointed to by 0x8 of the caller */
struct Unk_ov085_020c99ac_obj {
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
    /* 0xec */ u32 unkEC;
    /* 0xf0 */ Unk_ov085_020c99ac_word word;
};

struct Unk_ov085_020c99ac {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ Unk_ov085_020c99ac_obj *obj;
};

extern "C" void func_ov085_020c99ac(Unk_ov085_020c99ac *self) {
    Unk_ov085_020c99ac_obj *obj = self->obj;
    s32 r;
    if (obj->unkEC == 0) {
        r = 1;
    } else {
        r = func_ov014_02096360(obj->unkEC);
    }
    if (r != 0) {
        u32 unit = 0x1000;
        u32 w = obj->word.raw;
        u32 mask = -unit;
        u32 hiPart = w & mask;
        s32 mid = (s32)(w << 8) >> 20;
        s32 lo = (s32)(w << 20) >> 20;
        u32 newLo = lo - (0x1e - mid);
        u32 loPart = newLo & (mask >> 20);
        u32 v = hiPart | loPart;
        obj->word.raw = v;
        obj->word.f.mid = 0x1e;
        obj->vf18(0, -1, 0x100, 0);
        func_ov085_020cae08(&data_ov085_020cb2b8);
        self->unk0 = 0;
    }
}
