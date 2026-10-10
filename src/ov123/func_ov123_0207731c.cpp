#include "types.h"

// Placeholder until the owning class is identified
struct Unk_ov123_0207731c {
    /* 0x00 */ u8 unk0[0x10];
    /* 0x10 */ s16 values[6];
};

extern "C" s16 func_ov123_0207731c(Unk_ov123_0207731c* self, s32 index) {
    switch (index) {
        case 0: return self->values[0];
        case 1: return self->values[1];
        case 2: return self->values[2];
        case 3: return self->values[3];
        case 4: return self->values[4];
        case 5: return self->values[5];
    }
    return 0;
}
