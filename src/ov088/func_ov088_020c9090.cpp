#include "types.h"

struct Unk_ov088_Entry {
    /* 0x00 */ u8 unk00[2];
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u8 unk04[0x14];
    /* 0x18 */ u32 unk18[2];
};

struct Unk_ov088_020c9090 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u16 unk8;
    /* 0x0c */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u16 unk1C;
    /* 0x1e */ s16 unk1E;
    /* 0x20 */ u16 unk20;
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u16 unk28;
    /* 0x2c */ u32 unk2C;
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u32 unk38;
    /* 0x3c */ u8 unk3C[0x24];
    /* 0x60 */ u32 unk60;
    /* 0x64 */ u32 unk64;
    /* 0x68 */ u32 unk68;
    /* 0x6c */ u32 unk6C;
    /* 0x70 */ u32 unk70;
    /* 0x74 */ u32 unk74;
    /* 0x78 */ u32 unk78[2];
    /* 0x80 */ Unk_ov088_Entry entries[20];
};

struct Unk_ov088_Cd2e0 {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ u32 pair14[2];
};

class Unk_ov088_Obj {
public:
    /* 0x00 vptr */ virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    /* 0x14 */ virtual s16 v5(s32 a, s32 b);
};

extern "C" void func_01ff8228(void* dst, s32 value, u32 size);
extern "C" s32 func_020058bc(s32 a, void* b, s32 c);

extern "C" u32 data_0204ffe0[2];
extern "C" Unk_ov088_Cd2e0 data_ov088_020cd2e0;
extern "C" u8* data_ov008_02064f08;

// TODO: 95.15%. The two 8-byte pair copies still differ: mwcc either loads the words in the reverse order of the
// original (lo stored first in source) or merges the loop copy into ldmia with the low word in r0 instead of r2
// (the original loads it into r2). Tried without success: u64 (77.85%, ldmia), struct temporary Unk_ov088_Pair
// (90.65%, spills to the stack), u32 arrays with the store order swapped (95.15%), s32 temporaries (95.15%),
// function-scope temporaries (95.14%), moving the unk02 store after the copy in the loop (83.74%).
// Confirmed on func_ov088_020ca0c4 (matched this way): in func_ov088_020c920c the same "ldr lo; ldr hi; str lo; str hi" pattern comes from assigning
// a pointer-to-member-function (ptr + adj). The field at 0x78 and entries[i].unk18 are pmf fields there (see
// src/ov088/func_ov088_020c94b4.cpp for the typedef): type unk78, entries[].unk18 and the sources as pmf and assign directly.
extern "C" void func_ov088_020c9090(Unk_ov088_020c9090* self, u32 arg1) {
    self->unk0 = arg1;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unk2C = 0;
    self->unk60 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = -1;
    self->unk74 = 0;
    self->unk70 = 0;
    self->unk68 = 0;
    self->unk6C = 0;
    self->unk18 = 0;
    self->unk30 = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk20 = 0;
    self->unk22 = 0;
    self->unk24 = 0;
    self->unk26 = 0;
    self->unk28 = 0;
    func_01ff8228(self->unk3C, 0, 0x24);
    {
        u32 lo = data_ov088_020cd2e0.pair14[0];
        u32 hi = data_ov088_020cd2e0.pair14[1];
        self->unk78[1] = hi;
        self->unk78[0] = lo;
    }
    for (s32 i = 0; i < 20; i++) {
        self->entries[i].unk02 = 0x3000 + i + 1;
        u32 lo = data_0204ffe0[0];
        u32 hi = data_0204ffe0[1];
        self->entries[i].unk18[0] = lo;
        self->entries[i].unk18[1] = hi;
    }
    self->unk1C = func_020058bc(0x9008, data_ov008_02064f08 + 0x3c + 0x2d400, 0);
    self->unk1E = ((Unk_ov088_Obj*)(data_ov008_02064f08 + 0x3c + 0x2d400))->v5(0, 0x402a);
    if (self->unk1E < 0) {
        self->unk1E = 0;
    } else if (self->unk1E > 3) {
        self->unk1E = 3;
    }
}
