#include "types.h"

struct Unk_ov092_020c9420 {
    /* 0x00 */ u8 unk0[0xC];
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
};

struct Unk_ov092_Obj {
    /* 0x00 */ u8 unk0[0x54];
    /* 0x54 */ u32 unk54;
};

extern "C" Unk_ov092_020c9420 data_ov092_020c9420;
extern "C" u8 data_ov092_020c942c[];

extern "C" void func_ov016_020af944(void* arg);

extern "C" void func_ov092_020c91c4(Unk_ov092_Obj* obj) {
    func_ov016_020af944(data_ov092_020c942c);
    if (data_ov092_020c9420.unk10 != 0) {
        data_ov092_020c9420.unkC = data_ov092_020c9420.unk10;
        data_ov092_020c9420.unk10 = 0;
    }
    if (data_ov092_020c9420.unkC == 0) {
        obj->unk54 = 0;
    }
}
