#include "types.h"

struct Unk_ov088_020cbe14 {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x4];
    /* 0x28 */ s32 unk28;
    /* 0x2c */ u8 pad2c[0x2];
    /* 0x2e */ u16 unk2e;
    /* 0x30 */ u8 pad30[0x24];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[0x4];
    /* 0x5c */ s32 unk5c;
};

extern "C" s32 func_020350a8(s32 x, s32 y);

extern "C" void func_ov088_020cbe14(void *unused, Unk_ov088_020cbe14 *obj) {
    s32 angle = func_020350a8(obj->unk5c - obj->unk28, obj->unk20 - obj->unk54);
    angle += 0x8000;
    if (angle >= 0x10000) {
        angle -= 0x10000;
    }
    obj->unk2e = angle;
}
