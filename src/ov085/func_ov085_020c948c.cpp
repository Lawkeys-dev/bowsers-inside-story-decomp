#include "types.h"

struct Unk_ov085_020cb294 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0c */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
};

extern "C" Unk_ov085_020cb294 data_ov085_020cb294;
extern "C" u32 data_ov085_020cb2a0[];
extern "C" u32 data_ov085_020cb2b8[];

extern "C" void func_ov016_020af944(void* p);
extern "C" void func_ov085_020c952c();

struct Unk_ov085_020c948c {
    /* 0x00 */ u8 unk00[0x54];
    /* 0x54 */ void* unk54;
};

extern "C" void func_ov085_020c948c(Unk_ov085_020c948c* self) {
    func_ov016_020af944(&data_ov085_020cb2a0);
    func_ov016_020af944(&data_ov085_020cb294);
    func_ov016_020af944(&data_ov085_020cb2b8);
    if (data_ov085_020cb294.unk10 != 0) {
        data_ov085_020cb294.unkC = data_ov085_020cb294.unk10;
        data_ov085_020cb294.unk10 = 0;
    }
    if (data_ov085_020cb294.unk4 != 0) {
        data_ov085_020cb294.unk0 = data_ov085_020cb294.unk4;
        data_ov085_020cb294.unk4 = 0;
    }
    if (data_ov085_020cb294.unk28 != 0) {
        data_ov085_020cb294.unk24 = data_ov085_020cb294.unk28;
        data_ov085_020cb294.unk28 = 0;
    }
    if (data_ov085_020cb294.unkC == 0 && data_ov085_020cb294.unk0 == 0 && data_ov085_020cb294.unk24 == 0) {
        self->unk54 = (void*)func_ov085_020c952c;
    }
}
