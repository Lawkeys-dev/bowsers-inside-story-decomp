#include "types.h"

struct Unk_ov088_020c95a4_Src {
    /* 0x00 */ u8 pad[0x20];
    /* 0x20 */ s32 unk20;
};

struct Unk_ov088_020c95a4 {
    /* 0x00 */ u8 pad[0x64];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6c */ s32 unk6c;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
};

class Unk_ov088_Obj {
public:
    /* 0x00 vptr */ virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    /* 0x18 */ virtual void v6();
};

extern "C" u8* data_ov008_02064f08;

extern "C" void func_ov120_020d4a34(void* dst, u32 value, s32 count);

extern "C" void func_ov088_020c95a4(Unk_ov088_020c95a4* self, Unk_ov088_020c95a4_Src* src, s32 x, s32 y, s32 mode,
                                    s32 a6, s32 a7) {
    s32 base;
    self->unk64 = mode;
    if (src != NULL) {
        base = src->unk20;
    } else {
        base = 0;
    }
    self->unk68 = base + (x << 8);
    self->unk6c = y << 8;
    self->unk70 = (0x100 - a6) << 8;
    self->unk74 = a7;

    switch (mode) {
    case 0:
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e96f0, self->unk68 - self->unk6c, self->unk74);
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e9720, self->unk68, self->unk74);
        break;
    case 1:
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e96f0, self->unk68, self->unk74);
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e9720, self->unk68 + self->unk6c, self->unk74);
        break;
    default:
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e96f0, self->unk68 - (self->unk6c / 2), self->unk74);
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e9720, self->unk68 + (self->unk6c / 2), self->unk74);
        break;
    }
    func_ov120_020d4a34(data_ov008_02064f08 + 0x1e9780, self->unk70, self->unk74);
    Unk_ov088_Obj* obj = (Unk_ov088_Obj*)(data_ov008_02064f08 + 0x1e9750);
    obj->v6();
}
