#include "types.h"

struct Unk_ov129_02074970_54 {
    /* 0x00 */ u8 pad[0x8];
    /* 0x08 */ u32 unk8;
};

struct Unk_ov129_02074970_5c {
    /* 0x00 */ u8 pad[0x50];
    /* 0x50 */ u8 unk50;
    /* 0x51 */ u8 pad2[0x3];
    /* 0x54 */ Unk_ov129_02074970_54* unk54;
    /* 0x58 */ u8 pad3[0x4];
    /* 0x5c */ void* unk5c;
};

struct Unk_ov129_02074970 {
    /* 0x00 */ u8 pad[0x28];
    /* 0x28 */ void* unk28;
    /* 0x2c */ u8 pad2[0x834 - 0x2c];
    /* 0x834 */ void* unk834;
    /* 0x838 */ u8 pad3[0x86c - 0x838];
    /* 0x86c */ void* unk86c;
};

extern "C" Unk_ov129_02074970_5c* func_ov127_0206a30c(void* a);
extern "C" void* func_ov127_0206c8d4(void* a, void* b);
extern "C" void func_ov011_0206c6f4(void* a, u32 b, void* c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);
extern "C" void func_01ff8228(void* a, u32 b, u32 c);
extern "C" void func_02036464();
extern "C" u32 func_0201f0bc();
extern "C" void func_ov127_0206ad18(void* a, void* b, u32 c, u32 d, u32 e);
extern "C" void func_ov127_0206b1ac(Unk_ov129_02074970_5c* a, void* b, u32 c);

// TODO: 95.47%. Remaining diffs: the 0x54 pointer load and the func_0201f0bc result end up in r2/r12 instead of r1/r3
// (register choice for the temporaries before func_ov127_0206ad18), and the two args of func_ov127_0206b1ac are moved in
// the opposite order (r1 before r0). Tried without change: obj/r4 declaration order (fixed r4/r5), inline call
// expression (r12/r2 still), operand swap, a local for the 0x54 pointer, sum local, result declared at top, s32/u16
// return type of func_0201f0bc, u32/void* for a3, s32 unk8, void* or typed first param of func_ov127_0206b1ac.
extern "C" void func_ov129_02074970(Unk_ov129_02074970* self, u32 unused, void* a2, void* a3, u32 a4, u8 flag1, u8 flag2) {
    void* r4;
    Unk_ov129_02074970_5c* obj = func_ov127_0206a30c(self->unk28);
    r4 = obj->unk5c;
    void* p = func_ov127_0206c8d4(self->unk834, a2);
    if (flag1 != 0) {
        func_ov011_0206c6f4(self->unk86c, (u32)p + 2, r4, 0, 0, 1, 0x20, 2, 1, 1, 1);
    }
    if (flag2 != 0) {
        func_01ff8228(r4, 0, 0x80);
    }
    func_02036464();
    u32 r3 = func_0201f0bc();
    Unk_ov129_02074970_54* t = obj->unk54;
    func_ov127_0206ad18(self->unk28, r4, r3 + t->unk8, 0x800, 0);
    func_ov127_0206b1ac(obj, a3, a4);
    obj->unk50 |= 0x8;
}
