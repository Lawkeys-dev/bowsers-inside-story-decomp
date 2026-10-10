#include "types.h"

struct Unk_ov092_Out {
    /* 0x0 */ void* unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ s32 unk8;
};

struct Unk_ov092_020c9420 {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ s32 unk8;
};

union Unk_ov092_Flags {
    u32 raw;
    struct {
        u32 unk0 : 9;
        u32 flag9 : 1;
    } bits;
};

struct Unk_ov092_Entry {
    /* 0x00 */ u8 unk00[0x0c];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x20 - 0x0e];
    /* 0x20 */ u8 unk20[0x3c - 0x20];
    /* 0x3c */ Unk_ov092_Flags unk3c;
};

struct Unk_ov092_Obj {
    /* 0x00 */ u8 unk00[0x40];
    /* 0x40 */ u32 unk40;
};

struct Unk_ov016_020b8900 {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
    /* 0x8 */ u16 unk8;
    /* 0xa */ u8 unkA;
    /* 0xb */ u8 unkB;
    /* 0xc */ u16 unkC;
    /* 0xe */ u16 unkE;
};

extern "C" Unk_ov092_020c9420 data_ov092_020c9420;
extern "C" u32 data_ov008_02064f08;
extern "C" Unk_ov016_020b8900 data_ov016_020b8900;

extern "C" s32 func_0201cf78(s32 arg);
extern "C" Unk_ov092_Entry* func_ov011_02066dac(u32 base, u32 id);
extern "C" void func_ov014_020977e8(void* dst, void* src);
extern "C" Unk_ov092_Obj* func_ov015_020a0f98(u32 base, s32 size, s32 arg);
extern "C" void func_ov015_0209fa78(void* obj, s32 arg1, s32 arg2);
extern "C" void func_ov016_020ad144(u32 base);
extern "C" void func_ov092_020c93dc();

extern "C" void func_ov092_020c9280(Unk_ov092_Out* out) {
    s32 skip = func_0201cf78(data_ov092_020c9420.unk8);
    data_ov092_020c9420.unk8--;
    s32 i;
    for (i = 0x4000; i <= 0x4003; i++) {
        Unk_ov092_Entry* entry = func_ov011_02066dac(data_ov008_02064f08, (u16)i);
        if (entry == NULL) {
            continue;
        }
        if (entry->unk3c.bits.flag9) {
            continue;
        }
        if (skip != 0) {
            skip--;
            continue;
        }
        Unk_ov092_Obj* obj = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0x3c, 1);
        func_ov014_020977e8(&obj->unk00[0x0c], entry->unk20);
        func_ov015_0209fa78(&obj->unk00[0x0c], 0, 0x301f);
        obj->unk40 = 0x1000;
        entry->unk3c.raw |= 0x200;
        data_ov016_020b8900.unk0 = 0x38023;
        data_ov016_020b8900.unk4 = 0;
        data_ov016_020b8900.unk6 = 0;
        data_ov016_020b8900.unk8 = 1;
        data_ov016_020b8900.unkA = 0x7f;
        data_ov016_020b8900.unkB = 0;
        data_ov016_020b8900.unkC = entry->unk0c;
        data_ov016_020b8900.unkE = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
        break;
    }
    out->unk8 = func_0201cf78(2) + 1;
    out->unk0 = data_ov092_020c9420.unk8 != 0 ? (void*)func_ov092_020c93dc : NULL;
}
