#include "types.h"

struct Unk_ov129_02075b28_Obj {
    /* 0x00 */ u8 unk0[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1c */ u8 unk1c[0x50 - 0x1c];
    /* 0x50 */ u8 unk50;
};

struct Unk_ov129_02075b28_Owner {
    /* 0x00 */ u8 unk0[0x28];
    /* 0x28 */ void* unk28;
    /* 0x2c */ u8 unk2c[0x824 - 0x2c];
    /* 0x824 */ u8 unk824;
};

extern "C" Unk_ov129_02075b28_Obj* func_ov127_0206a30c(void* p, s32 id);
extern "C" void func_ov127_0206b2a0(Unk_ov129_02075b28_Obj* obj, s32 x, s32 y, s32 z);
extern "C" void func_ov127_0206b398(void* obj, s32 x, s32 y, s32 z);
extern "C" u8 data_020590c0[];

// TODO: every instruction matches except the register assignment of the parameters and locals.
// mwcc puts self in r7, x/y/z in r6/r5/r4 and b in r9, flags in r8. The original has self=r8, x=r7, y=r6,
// z=r5, b=r4, flags=r9. Fixing the Owner layout (unk28 at 0x28) took it from 97.54% to 97.61%.
// Tried without moving the registers: declaration order of a/b/flags/idx, a temp for the 0x59 result,
// Obj*/void* types for a and b, unsigned params or loop counters, u32* flags, function-scope counter (worse).
extern "C" void func_ov129_02075b28(Unk_ov129_02075b28_Owner* self, s32 x, s32 y, s32 z) {
    Unk_ov129_02075b28_Obj* a = func_ov127_0206a30c(self->unk28, 0x58);
    Unk_ov129_02075b28_Obj* b = func_ov127_0206a30c(self->unk28, 0x59);
    u32 idx = self->unk824 * 2;
    u8* flags = data_020590c0 + idx * 0x7ec;
    for (s32 i = 0; i < 9; i++) {
        s32 bitId = i + 0xd000;
        s32 word = (bitId & ~0xd000) >> 5;
        if ((((u32*)flags)[word] >> (bitId & 0x1f)) & 1) {
            Unk_ov129_02075b28_Obj* obj = func_ov127_0206a30c(self->unk28, i + 9);
            obj->unk50 |= 0x8;
        } else {
            Unk_ov129_02075b28_Obj* obj = func_ov127_0206a30c(self->unk28, i + 9);
            obj->unk50 &= ~0x8;
        }
    }
    for (s32 i = 0; i < 10; i++) {
        Unk_ov129_02075b28_Obj* obj = func_ov127_0206a30c(self->unk28, i + 8);
        func_ov127_0206b2a0(obj, x, y, z);
        if (i == 0) {
            func_ov127_0206b398(a, x, y - obj->unk14, z - obj->unk18);
            func_ov127_0206b398(b, x, y - obj->unk14, z - obj->unk18);
        }
    }
}
