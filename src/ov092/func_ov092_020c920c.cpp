#include "types.h"

struct Unk_ov092_020c920c {
    /* 0x0 */ void (*unk0)();
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
};

extern "C" void func_ov092_020c9224();

extern "C" void func_ov092_020c920c(Unk_ov092_020c920c* self) {
    self->unk8 = 1;
    self->unk0 = func_ov092_020c9224;
}
