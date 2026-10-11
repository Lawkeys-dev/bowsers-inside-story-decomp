#include "types.h"

struct Unk_ov129_02070fc0 {
    /* 0x000 */ u8 pad000[0x874];
    /* 0x874 */ void *unk874;
};

extern "C" u8 data_ov129_020763a4[];
extern "C" void func_0200dc38(void *);
extern "C" void func_ov129_0206defc(Unk_ov129_02070fc0 *);

extern "C" void func_ov129_02070fc0(Unk_ov129_02070fc0 *self) {
    if (data_ov129_020763a4[0] == 1) {
        func_0200dc38(self->unk874);
    }
    func_ov129_0206defc(self);
}
