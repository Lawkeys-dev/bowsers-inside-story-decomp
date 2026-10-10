#include "types.h"

union Unk_ov092_Flags {
    struct {
        u32 unk0 : 28;
        u32 flag28 : 1;
        u32 unk29 : 3;
    } bits;
    u32 raw;
};

struct Unk_ov092_Ret;

class Unk_ov092_Obj {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11(Unk_ov092_Ret* ret);
    /* 0x04 */ u8 pad04[0x38];
    /* 0x3c */ Unk_ov092_Flags flags;
};

struct Unk_ov092_Inner {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ u32 unk20;
};

struct Unk_ov092_Mid {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ Unk_ov092_Inner* unk10;
};

struct Unk_ov092_Global {
    /* 0x00 */ void* unk0;
    /* 0x04 */ u32 unk4;
};

struct Unk_ov092_Ret {
    /* 0x00 */ u8 pad00[0x34];
    /* 0x34 */ Unk_ov092_Flags flags;
};

struct Unk_ov092_Self {
    /* 0x00 */ u8 pad00[0x54];
    /* 0x54 */ void* unk54;
};

extern "C" Unk_ov092_Global data_ov092_020c9420;
extern "C" u32 data_ov092_020c942c;
extern "C" u32 data_ov008_02064f08;
extern "C" u32 data_ov101_020cf274;
extern "C" void func_ov092_020c91c4();

extern "C" Unk_ov092_Ret* func_ov011_02066c28(u32 a, u32 b);
extern "C" Unk_ov092_Obj* func_ov011_0206661c(u32 a, u32 b, s32 c);
extern "C" void func_ov092_020c920c(u32 a, u32 b);
extern "C" void func_ov120_020d49e4(u32 a, u32 b, u32 c);

extern "C" void func_ov092_020c90ac(Unk_ov092_Self* self) {
    Unk_ov092_Ret* ret = func_ov011_02066c28(data_ov008_02064f08, 0xa013);
    if (ret->flags.bits.flag28 != 0) {
        return;
    }
    Unk_ov092_Obj* obj = func_ov011_0206661c(data_ov008_02064f08, 0x301f, -1);
    obj->v11(ret);
    obj->flags.raw |= 0x200;
    data_ov092_020c9420.unk0 = self;
    data_ov092_020c9420.unk4 = data_ov008_02064f08 + 0x2f11c;
    func_ov092_020c920c((u32)&data_ov092_020c942c, data_ov008_02064f08 + 0x2f11c);
    Unk_ov092_Mid* mid = (Unk_ov092_Mid*)data_ov092_020c9420.unk4;
    func_ov120_020d49e4(data_ov008_02064f08 + 0x1e96f0, mid->unk10->unk20 - 0x1e00, 0x18);
    mid = (Unk_ov092_Mid*)data_ov092_020c9420.unk4;
    func_ov120_020d49e4(data_ov008_02064f08 + 0x1e9720, mid->unk10->unk20 + 0x1f400, 0x18);
    data_ov101_020cf274 = 1;
    self->unk54 = (void*)func_ov092_020c91c4;
}
