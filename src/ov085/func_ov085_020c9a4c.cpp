#include "types.h"

extern "C" u32 data_ov008_02064f08;
extern "C" void func_ov085_020c9f3c();
extern "C" void func_ov085_020c9acc();
extern "C" void func_ov120_020d4a34(u32 dst, u32 src, u32 size);

struct Unk_ov085_020c9a4c_self {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 *unk08;
};

extern "C" void func_ov085_020c9a4c(Unk_ov085_020c9a4c_self *self) {
    u32 base = data_ov008_02064f08;
    u32 *other = self->unk08;
    if (*(u32 *)(base + 0x2d4c0) & 2) {
        self->unk00 = (u32)func_ov085_020c9f3c;
        return;
    }
    u32 r5 = other[8];
    func_ov120_020d4a34(base + 0x1e96f0, r5 - 0x15800, 0x3c);
    base = data_ov008_02064f08;
    func_ov120_020d4a34(base + 0x1e9720, r5 + 0x5800, 0x3c);
    self->unk00 = (u32)func_ov085_020c9acc;
}
