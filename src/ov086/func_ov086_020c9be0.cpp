#include "types.h"

// Placeholder until the owning class is identified
struct Unk_ov086_020c9be0 {
    /* 0x00 */ u8 unk0[0x46];
    /* 0x46 */ u16 mode;
};

extern "C" s32 func_ov086_020c9be0(Unk_ov086_020c9be0* self) {
    switch (self->mode) {
        case 1: return 0x2800;
        case 2: return 0x2800;
        case 3: return 0x62800;
        case 4: return 0x62800;
    }
    return 0x2800;
}
