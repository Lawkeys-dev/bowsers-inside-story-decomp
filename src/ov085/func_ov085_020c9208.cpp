#include "types.h"

struct Unk_ov085_020c9208 {
    /* 0x00 */ u8 unk00[0x54];
    /* 0x54 */ void *unk54;
};

struct Unk_ov085_Flags {
    u32 low : 28;
    u32 flag : 1;
    u32 high : 3;
};

struct Unk_ov011_02066c28 {
    /* 0x00 */ u8 unk00[0x34];
    /* 0x34 */ Unk_ov085_Flags unk34;
};

extern "C" void *data_ov008_02064f08;
extern "C" Unk_ov011_02066c28 *func_ov011_02066c28(void *base, u32 id);
extern "C" void func_ov013_0208eb04(void *a, u32 b, u32 c, u32 d, s32 e);
extern "C" void func_ov085_020c9280();

extern "C" void func_ov085_020c9208(Unk_ov085_020c9208 *self) {
    if (func_ov011_02066c28(data_ov008_02064f08, 0xb00b)->unk34.flag) {
        return;
    }
    void *q = func_ov011_02066c28(data_ov008_02064f08, 0xa000);
    func_ov013_0208eb04(q, 0xc10000e1, 1, 0, -1);
    self->unk54 = (void *)func_ov085_020c9280;
}
