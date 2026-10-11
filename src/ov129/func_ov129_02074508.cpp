#include "types.h"

struct Unk_ov129_Vtable {
    /* 0x0 */ void* unk0;
    /* 0x4 */ void (*unk4)(void* self, s32 arg);
};

struct Unk_ov129_Obj {
    /* 0x0 */ Unk_ov129_Vtable* vt;
};

struct Unk_ov129_Entry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
};

union Unk_ov129_Word0 {
    struct {
        u32 unk0 : 1;
        u32 unk1 : 4;
        u32 unk5 : 5;
        u32 unk10 : 5;
        u32 unk15 : 17;
    } bits;
    u32 raw;
};

union Unk_ov129_Word1 {
    struct {
        u32 unk0 : 4;
        u32 unk4 : 1;
        u32 unk5 : 3;
        u32 unk8 : 1;
        u32 unk9 : 8;
        u32 unk17 : 11;
        u32 unk28 : 4;
    } bits;
    u32 raw;
};

union Unk_ov129_Word2 {
    struct {
        u32 unk0 : 1;
        u32 unk1 : 9;
        u32 unk10 : 9;
        u32 unk19 : 8;
        u32 unk27 : 5;
    } bits;
    u32 raw;
};

union Unk_ov129_Word24 {
    struct {
        u32 unk0 : 7;
        u32 unk7 : 25;
    } bits;
    u32 raw;
};

struct Unk_ov129_Out {
    /* 0x00 */ Unk_ov129_Word0 unk0;
    /* 0x04 */ Unk_ov129_Word1 unk4;
    /* 0x08 */ Unk_ov129_Word2 unk8;
    /* 0x0c */ u32 unkc;
    /* 0x10 */ void* unk10;
    /* 0x14 */ void* unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u32 unk1c;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ Unk_ov129_Word24 unk24;
};

struct Unk_ov129_Self {
    /* 0x000 */ u8 unk000[0x834];
    /* 0x834 */ u32* unk834;
    /* 0x838 */ u8 unk838[0x1c];
    /* 0x854 */ u8 unk854[0x30];
    /* 0x884 */ Unk_ov129_Obj* unk884;
};

extern "C" u8 data_02050164[];

extern "C" void func_0200dcdc(Unk_ov129_Obj* obj, Unk_ov129_Out* out, u32 a, u32 b);
extern "C" void func_0200e24c(Unk_ov129_Obj* obj, void* a, s32 b, void* c);
extern "C" void func_ov000_02063ba8(Unk_ov129_Obj* obj, Unk_ov129_Out* out, s32 arg);

// TODO: about 71% match. Still differs: the original keeps a and b in r2/r3 and computes x = 0x82 - b and
// y = 0x38 - a with rsb before the call. mwcc keeps the shifted values in r4/r5 and sinks the rsb after the call.
// The word1 unk0 field stays a 4-bit clear plus a separate bit 4 set (merging it into a 5-bit field is wrong here).
// Tried: merged 5-bit field, a/b locals, x/y before the call, several write orders (58-67%), unsigned x/y (same).
extern "C" void func_ov129_02074508(Unk_ov129_Self* self, s32 idx) {
    Unk_ov129_Out out;
    u8* base;
    u32 off;
    u32 x;
    u32 y;
    Unk_ov129_Entry* entry;

    self->unk884->vt->unk4(self->unk884, 0);
    base = (u8*)self->unk834;
    off = ((u32*)base)[idx];
    entry = (Unk_ov129_Entry*)(base + off);
    x = 0x82 - ((entry->unk0 + 1) << 2);
    y = 0x38 - ((entry->unk1 & ~3) << 1);
    func_0200dcdc(self->unk884, &out, (entry->unk1 & ~3) << 1, (entry->unk0 + 1) << 2);

    out.unk4.bits.unk0 = 0;
    out.unk4.bits.unk4 = 1;
    out.unk4.bits.unk5 = 0;
    out.unk0.bits.unk0 = 0;
    out.unk0.bits.unk1 = 3;
    out.unk24.bits.unk0 = 8;
    out.unk0.bits.unk5 = 0;
    out.unk0.bits.unk10 = 0;
    out.unk4.bits.unk8 = 0;
    out.unk4.bits.unk17 = idx;
    out.unk4.bits.unk28 = 6;
    out.unk4.bits.unk9 = 0;
    out.unk8.bits.unk0 = 1;
    out.unk8.bits.unk1 = x;
    out.unk8.bits.unk10 = y;
    out.unk8.bits.unk19 = 0;

    out.unkc = 0;
    out.unk10 = self->unk854;
    out.unk18 = 0;
    out.unk1c = 0;
    out.unk14 = self->unk834;

    func_0200e24c(self->unk884, NULL, 0xf, data_02050164);
    func_ov000_02063ba8(self->unk884, &out, 0);
}
