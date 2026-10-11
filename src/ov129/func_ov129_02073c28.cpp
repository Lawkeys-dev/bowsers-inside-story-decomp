#include "types.h"

struct Unk_ov129_02073c28 {
    /* 0x00 */ u8 unk00[0x28];
    /* 0x28 */ void *unk28;
};

struct Unk_ov129_02073c28_data {
    /* 0x00 */ u8 unk00[0x8];
    /* 0x08 */ u32 unk8;
};

struct Unk_ov127_0206a30c {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
};

extern "C" Unk_ov129_02073c28_data data_02058f84;
extern "C" Unk_ov127_0206a30c *func_ov127_0206a30c(void *obj, s32 id);
extern "C" void func_ov129_02073cd8(Unk_ov129_02073c28 *self, s32 x, s32 y, s32 z, u32 flag);

extern "C" void func_ov129_02073c28(Unk_ov129_02073c28 *self) {
    u32 flags = (data_02058f84.unk8 << 24) >> 28;
    Unk_ov127_0206a30c *a = func_ov127_0206a30c(self->unk28, 0x13);
    Unk_ov127_0206a30c *b = func_ov127_0206a30c(self->unk28, 0x32);
    func_ov129_02073cd8(self, a->unk14 / 4096, a->unk18 / 4096, 0, flags & 1);
    func_ov129_02073cd8(self, b->unk14 / 4096, b->unk18 / 4096, 0x1f, flags & 4);
}
