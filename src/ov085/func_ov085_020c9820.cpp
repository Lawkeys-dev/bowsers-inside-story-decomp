#include "types.h"

extern "C" void func_ov085_020c9830();

struct Unk_ov085_020c9820 {
    /* 0x00 */ void (*unk00)();
};

extern "C" void func_ov085_020c9820(Unk_ov085_020c9820 *self) {
    self->unk00 = func_ov085_020c9830;
}
