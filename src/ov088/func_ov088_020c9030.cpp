#include "types.h"

struct Unk_ov088_020c9030 {
    /* 0x00 */ u8 pad00[0x54];
    /* 0x54 */ void (*unk54)();
};

extern "C" void func_ov088_020c9058();
extern "C" s32 func_ov088_020c920c(void* arg);
extern "C" u8 data_ov088_020cd4f8[];

extern "C" void func_ov088_020c9030(Unk_ov088_020c9030* self) {
    if (func_ov088_020c920c(data_ov088_020cd4f8) != 1) {
        self->unk54 = func_ov088_020c9058;
    }
}
