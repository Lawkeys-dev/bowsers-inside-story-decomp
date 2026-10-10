#include "types.h"

// Placeholders until the owning classes are identified
struct Unk_ov004_A {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 unk2[6];
    /* 0x8 */ u16 unk8;
    /* 0xa */ u16 unkA;
    /* 0xc */ u8 unkC[4];
};

struct Unk_ov004_B {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u8 unk2[22];
};

struct Unk_ov004_0208ac58 {
    /* 0x0000 */ u8 unk0[0x13f4];
    /* 0x13f4 */ Unk_ov004_A* unk13F4;
    /* 0x13f8 */ Unk_ov004_B* unk13F8;
};

extern "C" BOOL func_ov004_0208ac58(Unk_ov004_0208ac58* self, s32 index) {
    BOOL result = TRUE;
    BOOL busy = FALSE;
    if (self->unk13F4[index].unk0 != 0 && self->unk13F4[index].unkA < self->unk13F4[index].unk8) {
        busy = TRUE;
    }
    if (!busy && self->unk13F8[index].unk0 == 0) {
        result = FALSE;
    }
    return result;
}
