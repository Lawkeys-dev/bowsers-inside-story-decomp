#include "types.h"

struct Unk_ov001_02069cb8 {
    /* 0x00 */ void* vtable;
    /* 0x04 */ u8 unk04[0x28 - 0x04];
    /* 0x28 */ u16 unk28;
    /* 0x2a */ u16 unk2a;
};

extern "C" void func_0201a39c(void* obj, s32 arg1, s32 arg2, s32 arg3);
extern "C" void* data_02050034;

extern "C" Unk_ov001_02069cb8* func_ov001_02069cb8(Unk_ov001_02069cb8* self) {
    func_0201a39c(self, 8, 0, 0);
    self->vtable = &data_02050034;
    self->unk28 = 13;
    self->unk2a = 0xffff;
    return self;
}
