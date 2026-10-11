#include "types.h"

struct Unk_ov085_Flags {
    u32 low : 28;
    u32 flag : 1;
    u32 high : 3;
};

union Unk_ov085_Word {
    u32 raw;
    struct {
        s32 lo : 12;
        s32 mid : 12;
        u32 hi : 8;
    } f;
};

struct Unk_ov085_Ctx {
    /* 0x00 */ u8 pad00[0x34];
    /* 0x34 */ Unk_ov085_Flags unk34;
    /* 0x38 */ u8 pad38[0xec - 0x38];
    /* 0xec */ void* unkEc;
    /* 0xf0 */ Unk_ov085_Word word;
};

struct Unk_ov085_Global {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ void (*unkC)();
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk_ov085_Ctx* unk14;
};

struct Unk_ov085_Self {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ Unk_ov085_Ctx* obj;
    /* 0x14 */ u8 pad14[0x54 - 0x14];
    /* 0x54 */ void (*unk54)();
};

class Unk_ov085_Vt {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual s32 vf14(s32 a, s32 b);
};

extern "C" Unk_ov085_Ctx* func_ov011_02066dac(void* p, s32 a);
extern "C" Unk_ov085_Ctx* func_ov011_02066c28(void* p, s32 a);
extern "C" s32 func_ov120_020d4954(void* p);
extern "C" void func_ov085_020cb0dc(void* p);
extern "C" void func_ov085_020cae08(void* p);
extern "C" void func_ov085_020c9820(void* p);
extern "C" void func_ov085_020c948c();
extern "C" void func_ov085_020c9a4c();
extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov085_Global data_ov085_020cb294;
extern "C" u8 data_ov085_020cb2a0[];
extern "C" u8 data_ov085_020cb2b8[];

extern "C" void func_ov085_020c92f8(Unk_ov085_Self* self) {
    Unk_ov085_Ctx* p = func_ov011_02066dac(data_ov008_02064f08, 0x400f);
    if (func_ov120_020d4954(data_ov008_02064f08 + 0x1e96ec) != 0) {
        return;
    }
    if (func_ov011_02066c28(data_ov008_02064f08, 0xb00b)->unk34.flag) {
        return;
    }
    if (func_ov011_02066c28(data_ov008_02064f08, 0xa000)->unk34.flag) {
        return;
    }
    if (func_ov011_02066c28(data_ov008_02064f08, 0xa001)->unk34.flag) {
        return;
    }
    if (data_ov085_020cb294.unk14->word.f.mid != 0) {
        Unk_ov085_Vt* vt = (Unk_ov085_Vt*)(data_ov008_02064f08 + 0x3c + 0x2d400);
        if (vt->vf14(0, 0x402a) != 0) {
            if (p != NULL && p->unkEc != NULL) {
                func_ov085_020cb0dc(data_ov085_020cb2b8);
            } else {
                data_ov085_020cb294.unkC = func_ov085_020c9a4c;
            }
        } else {
            func_ov085_020cae08(data_ov085_020cb2b8);
        }
    } else {
        func_ov085_020c9820(data_ov085_020cb2a0);
    }
    Unk_ov085_Ctx* obj = self->obj;
    s32 sum = obj->word.f.lo + obj->word.f.mid;
    obj->word.f.lo = sum;
    obj->word.f.mid = 0;
    self->unk54 = func_ov085_020c948c;
}
