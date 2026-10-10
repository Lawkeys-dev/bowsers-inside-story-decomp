#include "types.h"

struct Unk_ov092_A {
    /* 0x00 */ u8 unk00[0x48];
    /* 0x48 */ u16 low : 8;
    /* 0x48 */ u16 flag8 : 1;
};

struct Unk_ov092_B {
    /* 0x00 */ u8 unk00[0x54];
    /* 0x54 */ u32 unk54;
};

struct Unk_ov092_Global {
    /* 0x0 */ Unk_ov092_A* unk0;
    /* 0x4 */ Unk_ov092_B* unk4;
};

extern "C" Unk_ov092_Global data_ov092_020c9420;

extern "C" void func_ov092_020c9264();

extern "C" void func_ov092_020c9224(void** out) {
    if (data_ov092_020c9420.unk4->unk54 == 0) {
        *out = NULL;
        return;
    }
    if (data_ov092_020c9420.unk0->flag8) {
        *out = (void*)func_ov092_020c9264;
    }
}
