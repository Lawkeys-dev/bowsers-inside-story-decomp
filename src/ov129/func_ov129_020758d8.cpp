#include "types.h"

struct Unk_ov129_020758d8_Obj {
    /* 0x00 */ u8 unk00[0x50];
    /* 0x50 */ u8 unk50Pad : 1;
    /* 0x50 */ u8 unk50Bit1 : 1;
};

struct Unk_ov129_020758d8 {
    /* 0x00 */ u8 unk00[0x28];
    /* 0x28 */ Unk_ov129_020758d8_Obj *unk28;
    /* 0x2c */ u8 unk2c[0x824 - 0x2c];
    /* 0x824 */ u8 unk824;
    /* 0x825 */ u8 unk825[0x874 - 0x825];
    /* 0x874 */ u16 unk874;
    /* 0x876 */ u8 unk876[0x87c - 0x876];
    /* 0x87c */ u8 unk87c;
    /* 0x87d */ u8 unk87d;
    /* 0x87e */ u8 unk87e;
    /* 0x87f */ u8 unk87f;
};

struct Unk_ov129_020758d8_Args {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
};

extern "C" void *func_ov127_0206a30c(void *p, s32 size);
extern "C" void func_ov127_0206b1c0(void *p, Unk_ov129_020758d8_Args *args);
extern "C" s16 data_0204b1dc[];

// TODO: one instruction differs: mwcc does not emit the "add r3, sp, #0" pointer for the argument-block stores (original keeps it in r3 for the zero stores); also the table literal pool is offset by one instruction because of it.
extern "C" void func_ov129_020758d8(Unk_ov129_020758d8 *self) {
    Unk_ov129_020758d8_Obj *obj = (Unk_ov129_020758d8_Obj *)func_ov127_0206a30c(self->unk28, 0x54);
    if (obj->unk50Bit1) {
        self->unk874 = 0;
        return;
    }

    s32 v = data_0204b1dc[((u16)(((s32)self->unk874 << 16) / 64) >> 4) * 2] * 4;
    s32 neg = -1;
    if (v < 0) {
        v = v * neg;
    }
    Unk_ov129_020758d8_Args args;
    args.unk00 = 0;
    args.unk04 = 0;
    args.unk08 = 0;

    switch (self->unk87c) {
        case 0:
        case 1:
        case 7:
        case 27:
            if (self->unk824 == 0) {
                args.unk00 = v + 0x8000;
            } else {
                args.unk00 = v + 0x80000;
            }
            args.unk04 = 0x18000;
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            if (self->unk87f == 0) {
                args.unk00 = v + 0x34000;
            } else {
                args.unk00 = v + 0x86000;
            }
            args.unk04 = 0xb4000;
            break;
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            if (self->unk87f == 0) {
                args.unk00 = v + 0x34000;
            } else {
                args.unk00 = v + 0x86000;
            }
            args.unk04 = 0xb4000;
            break;
        default:
            if (self->unk87e == 0) {
                args.unk04 = 0xa0000;
            } else {
                args.unk04 = 0xb4000;
            }
            if (self->unk87f == 0) {
                args.unk00 = v + 0x22000;
            } else {
                args.unk00 = v + 0x80000;
            }
            break;
    }

    func_ov127_0206b1c0(obj, &args);
    self->unk874++;
}
