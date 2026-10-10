#include "types.h"

struct Unk_ov092_020c93dc {
    /* 0x00 */ void (*unk00)();
    /* 0x04 */ u32 unk04;
    /* 0x08 */ s32 unk08;
};

extern "C" void func_ov092_020c9280();

extern "C" void func_ov092_020c93dc(Unk_ov092_020c93dc* self) {
    self->unk08--;
    if (self->unk08 == 0) {
        self->unk00 = func_ov092_020c9280;
    }
}
