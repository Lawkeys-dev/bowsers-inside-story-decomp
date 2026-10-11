#include "types.h"

struct Unk_ov085_Flags {
    u32 low : 28;
    u32 flag : 1;
    u32 high : 3;
};

struct Unk_ov085_Obj {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ Unk_ov085_Flags unk34;
};

struct Unk_ov085_Self {
    /* 0x00 */ u8 pad0[0x54];
    /* 0x54 */ void* unk54;
};

extern "C" Unk_ov085_Obj* func_ov011_02066c28(void* a, u32 b);
extern "C" void func_ov013_0208eb04(void* a, u32 b, s32 c, s32 d, s32 e);
extern "C" void func_ov085_020c92f8();
extern "C" void* data_ov008_02064f08;

extern "C" void func_ov085_020c9280(Unk_ov085_Self* self) {
    if (func_ov011_02066c28(data_ov008_02064f08, 0xa000)->unk34.flag) {
        return;
    }
    Unk_ov085_Obj* obj = func_ov011_02066c28(data_ov008_02064f08, 0xa001);
    func_ov013_0208eb04(obj, 0xc2000088, 1, 0, -1);
    self->unk54 = (void*)func_ov085_020c92f8;
}
