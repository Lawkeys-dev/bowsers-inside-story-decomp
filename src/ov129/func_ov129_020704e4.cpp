#include "types.h"

struct Unk_ov129_Vec {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
};

struct Unk_ov129_020704e4 {
    /* 0x00 */ u8 unk0[0x28];
    /* 0x28 */ void* unk28;
    /* 0x2c */ u8 unk2c[0x830 - 0x2c];
    /* 0x830 */ u8 unk830;
    /* 0x831 */ u8 unk831;
    /* 0x832 */ u16 unk832;
};

extern "C" u16 data_0205afa8;
extern "C" s16 data_0204b1dc[];
extern "C" Unk_ov129_Vec data_ov129_02075ee0;
extern "C" Unk_ov129_Vec data_ov129_02075ed4;

extern "C" void* func_ov127_0206a30c(void* obj, s32 id);
extern "C" void func_ov127_0206b1c0(void* obj, Unk_ov129_Vec* vec);
extern "C" void func_ov003_0206b2d4(void* obj, s32 a, s32 b, s32 c);

// TODO: 96.57%. Remaining diffs: the counter (self->unk832) is loaded into r3 instead of r1, which shifts
// the register allocation of the table pointer and flags address (r1/r2 instead of r2/r3). The flags word
// is also read earlier than in the original (it is hoisted above the index computation).
// Tried without gain: explicit idx local (same 96.57%), a `u32 flags` local read after val (93.22%, pushes
// r8 into use), a `s16* tbl` local (96.57%), declaring `s32 val` before the calls (87.63%).
extern "C" void func_ov129_020704e4(Unk_ov129_020704e4* self) {
    void* obj1 = func_ov127_0206a30c(self->unk28, 0x2a);
    void* obj2 = func_ov127_0206a30c(self->unk28, 0x2b);
    s32 t = (u32)self->unk832 << 16;
    t = t + ((u32)(t >> 5) >> 26);
    s32 tmp = (u32)(t << 10) >> 16;
    s32 idx = (tmp >> 4) << 1;
    s32 val = data_0204b1dc[idx + 1];

    if (!(data_0205afa8 & 0x200) || self->unk830 == 0xc) {
        if (val > 0) {
            val *= -1;
        }
        Unk_ov129_Vec pos = data_ov129_02075ee0;
        pos.x = val * 4 + 0x18000;
        func_ov127_0206b1c0(obj1, &pos);
    } else {
        func_ov003_0206b2d4(obj1, 1, 0x14, 0xb0);
    }

    if (!(data_0205afa8 & 0x100) || self->unk830 == 0xc) {
        if (val < 0) {
            val *= -1;
        }
        Unk_ov129_Vec pos = data_ov129_02075ed4;
        pos.x = val * 4 + 0xe8000;
        func_ov127_0206b1c0(obj2, &pos);
    } else {
        func_ov003_0206b2d4(obj2, 1, 0xec, 0xb0);
    }

    self->unk832++;
    self->unk832 &= 0x3f;
}
