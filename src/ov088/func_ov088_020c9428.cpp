#include "types.h"

struct Unk_ov088_020c9428 {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
};

struct Unk_ov008_02064f08 {
    /* 0x0000 */ u8 unk0000[0x2f000];
    /* 0x2f000 */ u8 unk2f000[0x13c];
    /* 0x2f13c */ s32 unk2f13c;
};

extern "C" Unk_ov008_02064f08 *data_ov008_02064f08;

extern "C" s32 func_ov088_020c9428(Unk_ov088_020c9428 *p) {
    Unk_ov008_02064f08 *base = data_ov008_02064f08;
    if (base->unk2f13c != 0) {
        return 1;
    }
    if ((s16)*(s16 *)((u8 *)base + 0x2f14e) <= 0) {
        if (p->unkC != 0 || p->unk10 != 0) {
            p->unk14 = 1;
            return 1;
        }
        p->unk14--;
        if (p->unk14 <= -1) {
            p->unk14 = 10;
        }
        if (p->unk14 > 0) {
            return 1;
        }
    }
    return 0;
}
