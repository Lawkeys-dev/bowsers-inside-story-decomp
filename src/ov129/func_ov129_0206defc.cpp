#include "types.h"

struct Unk_ov129_0206defc {
    /* 0x00 */ u8 unk00[0x28];
    /* 0x28 */ void *unk28;
};

extern "C" void func_ov127_0206aba4(void *);

extern "C" void func_ov129_0206defc(Unk_ov129_0206defc *self) {
    func_ov127_0206aba4(self->unk28);
}
