#include "types.h"

struct Unk_ov129_02074664 {
    /* 0x000 */ u8 pad000[0x28];
    /* 0x028 */ void* unk28;
    /* 0x02c */ u8 pad02c[0x824 - 0x2c];
    /* 0x824 */ u8 unk824;
    /* 0x825 */ u8 pad825[0x87c - 0x825];
    /* 0x87c */ u8 unk87c;
    /* 0x87d */ u8 pad87d[0x888 - 0x87d];
    /* 0x888 */ u8 unk888;
};

struct Unk_ov129_02074664_Data {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u32 unk8;
};

struct Unk_ov127_0206a30c {
    /* 0x00 */ u8 pad0[0x50];
    /* 0x50 */ u8 unk50;
};

extern "C" Unk_ov129_02074664_Data data_02058f84;
extern "C" u32 data_ov129_02076348;

extern "C" Unk_ov127_0206a30c* func_ov127_0206a30c(void* p, s32 id);
extern "C" void func_ov129_02074970(Unk_ov129_02074664* self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

// TODO: 98.41%. The original loads self->unk87c twice (one copy compared and stored to data_ov129_02076348, a second
// copy kept in r1 for the switch, loaded before the cmp). mwcc CSEs the two loads here, and it stores the global after
// the switch compare. The literal pool for data_ov129_02076348 is also at a different offset.
extern "C" void func_ov129_02074664(Unk_ov129_02074664* self) {
    s32 i;
    s32 changed;
    s32 state;

    for (i = 0; i < 4; i++) {
        Unk_ov127_0206a30c* p = func_ov127_0206a30c(self->unk28, i + 2);
        p->unk50 &= ~0x8;
    }

    u8 value = self->unk87c;
    u32 old = data_ov129_02076348;
    state = self->unk87c;
    changed = (old != value) ? 1 : 0;
    data_ov129_02076348 = value;

    switch (state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 7:
        case 27:
            func_ov129_02074970(self, 2, 0, 0x30, 0xa2, changed, 0);
            break;
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
        case 28:
            func_ov129_02074970(self, 2, 1, 0x38, 0x98, changed, 1);
            if (!((1 << (self->unk824 * 2)) & ((data_02058f84.unk8 << 24) >> 28))) {
                break;
            }
            func_ov129_02074970(self, 3, 0x14, 0x38, 0xac, changed, 0);
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            func_ov129_02074970(self, 2, 3, 1, 0x98, changed, 0);
            func_ov129_02074970(self, 3, 5, 0x4c, 0xac, changed, 0);
            break;
        case 18:
            func_ov129_02074970(self, 2, 4, 1, 0x98, changed, 0);
            func_ov129_02074970(self, 3, 5, 0x4c, 0xac, changed, 0);
            break;
        case 25:
        case 26:
            func_ov129_02074970(self, 2, 0x13, 8, 0x98, changed, 0);
            func_ov129_02074970(self, 3, 5, 0x4c, 0xac, changed, 0);
            break;
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
            if (self->unk888 != 0) {
                func_ov129_02074970(self, 2, 0x13, 8, 0x98, changed, 0);
            } else {
                func_ov129_02074970(self, 2, 4, 1, 0x98, changed, 0);
            }
            func_ov129_02074970(self, 3, 5, 0x4c, 0xac, changed, 0);
            break;
        default:
            break;
    }
}
