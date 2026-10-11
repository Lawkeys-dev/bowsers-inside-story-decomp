#include "types.h"

struct Unk_ov129_0207616c {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
};

extern "C" Unk_ov129_0207616c data_ov129_0207616c[];

extern "C" Unk_ov129_0207616c *func_ov129_0206e040(s32 unused, s32 index) {
    return &data_ov129_0207616c[index];
}
