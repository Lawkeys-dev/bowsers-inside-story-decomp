#include "types.h"

struct Unk_ov088_020cb258 {
    /* 0x00 */ u8 unk00[0x8];
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a[0x16];
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
};

struct Unk_ov088_020cb258_Ret {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
};

struct Unk_ov088_020cb258_Data {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
};

extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov088_020cb258_Data data_ov088_020cd2e4;
extern "C" Unk_ov088_020cb258_Data data_ov088_020cd2ec;

extern "C" Unk_ov088_020cb258_Ret* func_ov088_020caefc(Unk_ov088_020cb258* self);
extern "C" void func_ov088_020c94b4(Unk_ov088_020cb258* self, Unk_ov088_020cb258_Data pair, s32 c, s32 d);

extern "C" s32 func_ov088_020cb258(Unk_ov088_020cb258* self) {
    if (*(s16*)(data_ov008_02064f08 + 0x2f14e) <= 0) {
        return -1;
    }
    Unk_ov088_020cb258_Ret* ret = func_ov088_020caefc(self);
    if (ret == NULL) {
        return -1;
    }
    self->unk20++;
    if (self->unk08 < 0x10 && self->unk20 >= ret->unk00) {
        self->unk20 = 0;
        self->unk22++;
        if (ret->unk02 <= -1) {
            func_ov088_020c94b4(self, data_ov088_020cd2ec, ret->unk02, 0);
        } else {
            func_ov088_020c94b4(self, data_ov088_020cd2e4, ret->unk02, 0);
        }
    }
    return 0;
}
