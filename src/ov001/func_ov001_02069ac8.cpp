#include "types.h"

struct Unk_ov001_Vtbl {
    /* 0x0 */ void* unk0;
    /* 0x4 */ void (*unk4)(void* self);
};

struct Unk_ov001_Obj {
    /* 0x0 */ Unk_ov001_Vtbl* vtbl;
};

struct Unk_ov001_02055fe4 {
    /* 0x000 */ u8 unk000[0x4cd];
    /* 0x4cd */ u8 unk4cd;
    /* 0x4ce */ u8 unk4ce[0x4d4 - 0x4ce];
    /* 0x4d4 */ void* unk4d4;
    /* 0x4d8 */ u32 unk4d8[4];
    /* 0x4e8 */ u8 unk4e8[0x514 - 0x4e8];
};

struct Unk_ov001_01ff93c8 {
    /* 0x00 */ u8 unk0[0xc];
    /* 0x0c */ u8 unkC;
};

extern "C" Unk_ov001_02055fe4 data_02055fe4;
extern "C" Unk_ov001_01ff93c8 data_01ff93c8;
extern "C" u8 data_02047d3c[];

extern "C" void* func_01ff8228(void* dst, s32 val, u32 size);
extern "C" Unk_ov001_Obj* func_ov001_02069978(void);
extern "C" u32 func_0201af08(Unk_ov001_Obj* obj, s32 a, s32 b);
extern "C" u32 func_02019eac(s32 a, u32 b, s32 c, s32 d);
extern "C" void* func_0201c044(Unk_ov001_Obj* obj, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void func_0201b0e4(Unk_ov001_Obj* obj);

// TODO: the zero/one stack arguments are rematerialized after the call to func_02019eac instead of
// being kept in callee-saved registers (original: r4 = 0 copied from i, r11 = 1 hoisted before the loop).
// Local zero/one variables are constant-folded and do not reproduce it. Obj/i/unk registers are shifted
// as a consequence (77.49%).
extern "C" void func_ov001_02069ac8() {
    Unk_ov001_Obj* obj;
    s32 i;
    s32 j;
    u32 max;
    u32 r;
    u8 unk;

    func_01ff8228(&data_02055fe4, 0, 0x514);
    data_02055fe4.unk4d4 = data_02047d3c;
    obj = func_ov001_02069978();
    unk = data_01ff93c8.unkC;
    if (unk != 1 && unk != 2 && unk != 5) {
        unk = 1;
    }
    data_02055fe4.unk4cd = unk;
    for (i = 0; i < 4; i++) {
        s16 row = (s16)i;
        max = 0;
        for (j = 1; j <= 5; j++) {
            r = func_0201af08(obj, row, (u16)j);
            if (r > max) {
                max = r;
            }
        }
        if (max != 0) {
            r = func_02019eac(1, max, 0, 0);
            data_02055fe4.unk4d8[i] = (u32)func_0201c044(obj, (s16)i, unk, 0, r, 0, 0, 0, 0, 1, 0);
        }
    }
    func_0201b0e4(obj);
    if (obj != NULL) {
        obj->vtbl->unk4(obj);
    }
}
