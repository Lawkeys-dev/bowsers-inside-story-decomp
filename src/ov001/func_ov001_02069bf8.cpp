#include "types.h"

#define REG_KEYINPUT (*(volatile u16*)0x4000130)
#define REG_IE (*(volatile u32*)0x4000210)

struct Unk_ov001_02069bf8 {
    /* 0x00 */ u8 unk00[0x8];
    /* 0x08 */ u8 unk08[0x8];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
};

extern "C" void func_0203a9ac(void* dst, s32 value, u32 size);
extern "C" void func_02019a2c(void);
extern "C" void func_02019a74(void* arg, u16 keys);
extern "C" void func_02019b2c(void);
extern "C" void func_0201e9c8(void);

extern "C" void func_ov001_02069bf8(Unk_ov001_02069bf8* self) {
    func_0203a9ac(&self->unk08, 0, 0x14);
    self->unk10 = 10;
    self->unk11 = 2;
    func_02019a2c();
    func_02019a74(&self->unk08, (u16)(((REG_KEYINPUT | *(volatile u16*)0x27fffa8) ^ 0x2fff) & 0x2fff));
    if (REG_IE & 1) {
        func_02019b2c();
    } else {
        func_0201e9c8();
    }
    func_02019a2c();
    func_02019a74(&self->unk08, (u16)(((REG_KEYINPUT | *(volatile u16*)0x27fffa8) ^ 0x2fff) & 0x2fff));
}
