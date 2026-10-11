#include "types.h"

struct Unk_ov088_Sub {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ u16 unk0c;
};

struct Unk_ov088_C {
    /* 0x00 */ u8 unk00[0x40];
    /* 0x40 */ u32 unk40;
};

struct Unk_ov088_B {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ Unk_ov088_C* unk20;
};

struct Unk_ov088_Obj {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x3c - 0x0e];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u8 unk40[0xec - 0x40];
    /* 0xec */ Unk_ov088_B* unkEc;
    /* 0xf0 */ u8 unkF0[0x100 - 0xf0];
    /* 0x100 */ Unk_ov088_Sub unk100;
};

struct Unk_ov088_Global {
    /* 0x00000 */ u8 unk00[0x2f12c];
    /* 0x2f12c */ Unk_ov088_Obj* unk2f12c;
};

extern "C" Unk_ov088_Global* data_ov008_02064f08;

extern "C" s32 func_ov014_0209a0a4(s32 a, s32 b);
extern "C" Unk_ov088_Obj* func_ov014_0209a15c(s32 a, s32 b);
extern "C" Unk_ov088_Obj* func_ov011_02066dac(Unk_ov088_Global* global, Unk_ov088_Obj* obj);

extern "C" s32 func_ov088_020cb32c(s32 p0, s32 p1, s32 p2) {
    if (func_ov014_0209a0a4(p1, p2) != 0) {
        Unk_ov088_Obj* obj = func_ov014_0209a15c(p1, func_ov014_0209a0a4(p1, p2));
        Unk_ov088_Obj* found = func_ov011_02066dac(data_ov008_02064f08, obj);
        if (found == NULL) {
            return func_ov088_020cb32c(p0, p1, p2 + 1);
        }
        if (found->unk0c == data_ov008_02064f08->unk2f12c->unk0c) {
            return func_ov088_020cb32c(p0, p1, p2 + 1);
        }
        if (found->unkEc->unk20->unk40 == 0xc10000db) {
            if (((found->unk3c << 0x16) >> 0x1f) == 0) {
                return 3;
            }
        } else if (found->unk100.unk0c != 0) {
            return 1;
        }
    }
    return 0;
}
