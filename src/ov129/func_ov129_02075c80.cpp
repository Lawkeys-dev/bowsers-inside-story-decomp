#include "types.h"

struct Unk_ov129_02075c80 {
    /* 0x000 */ u8 unk000[0x826];
    /* 0x826 */ u8 unk826;
    /* 0x827 */ u8 unk827[0x884 - 0x827];
    /* 0x884 */ u32 unk884;
};

extern "C" void func_0200dc38(u32 arg);
extern "C" void func_ov129_0206defc(Unk_ov129_02075c80 *self);

extern "C" void func_ov129_02075c80(Unk_ov129_02075c80 *self) {
    if (self->unk826 & 2) {
        func_0200dc38(self->unk884);
    }
    func_ov129_0206defc(self);
}
