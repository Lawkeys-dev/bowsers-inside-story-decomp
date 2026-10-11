#include "types.h"

struct Unk_ov129_0207616c {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u16 unk4[3];
};

extern "C" Unk_ov129_0207616c data_ov129_0207616c[0x23];

extern "C" Unk_ov129_0207616c* func_ov129_0206dfe4(s32 unused, u16 id) {
    s32 i;
    s32 j;

    for (i = 0; i < 0x23; i++) {
        for (j = 0; j < 3; j++) {
            if (data_ov129_0207616c[i].unk4[j] == id) {
                return &data_ov129_0207616c[i];
            }
        }
    }
    return NULL;
}
