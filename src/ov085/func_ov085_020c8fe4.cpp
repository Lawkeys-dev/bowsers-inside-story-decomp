#include "types.h"

// Virtual slots 0x00-0x10 are unknown placeholders, only slot 0x14 is called here.
class Unk_ov085_Mgr {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    /* 0x14 */ virtual s32 vf14(s32 a, s32 b);
};

struct Unk_ov085_Obj {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[0xec - 0x24];
    /* 0xec */ void* unkEc;
    /* 0xf0 */ u32 unkF0;
};

struct Unk_ov085_Self {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ Unk_ov085_Obj* obj;
    /* 0x14 */ u8 pad14[0x54 - 0x14];
    /* 0x54 */ void (*unk54)();
};

struct Unk_ov085_Src {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u32 unk10;
};

struct Unk_ov085_Data280 {
    /* 0x00 */ Unk_ov085_Self* self;
    /* 0x04 */ Unk_ov085_Src* src;
};

struct Unk_ov085_Data294 {
    /* 0x00 */ u8 pad00[0x08];
    /* 0x08 */ u32 unk08;
    /* 0x0c */ u8 pad0c[0x14 - 0x0c];
    /* 0x14 */ Unk_ov085_Obj* obj14;
    /* 0x18 */ u8 pad18[0x2c - 0x18];
    /* 0x2c */ void* unk2c;
    /* 0x30 */ u8 pad30[0x44 - 0x30];
    /* 0x44 */ u32 unk44;
    /* 0x48 */ u8 pad48[0x5c - 0x48];
    /* 0x5c */ u32 unk5c;
    /* 0x60 */ u8 unk60;
};

extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov085_Data280 data_ov085_020cb280;
extern "C" Unk_ov085_Data294 data_ov085_020cb294;

extern "C" void* func_ov011_02066dac(u8* a, u32 b);
extern "C" void* func_ov011_02066c28(u8* a, u32 b);
extern "C" void* func_ov011_0206661c(u8* a, u32 b, s32 c);
extern "C" void func_ov013_0208eb04(void* a, u32 b, s32 c, s32 d, s32 e);
extern "C" void func_01ff8228(void* p, s32 v, u32 n);
extern "C" void func_ov120_020d4a34(void* dst, u32 src, u32 n);
extern "C" void func_ov085_020c9208();

// TODO: 99.09%, the only diff is one literal-pool entry: the original keeps two separate
// pool words for data_ov085_020cb280 (memset argument and later stores), mwcc dedups them here.
extern "C" void func_ov085_020c8fe4(Unk_ov085_Self* self) {
    Unk_ov085_Obj* ent = (Unk_ov085_Obj*)func_ov011_02066dac(data_ov008_02064f08, 0x400f);
    Unk_ov085_Obj* obj = self->obj;
    if (((s32)(obj->unkF0 << 8) >> 20) != 0) {
        Unk_ov085_Mgr* mgr = (Unk_ov085_Mgr*)(data_ov008_02064f08 + 0x2d43c);
        if (mgr->vf14(0, 0x402a) == 0) {
            if (ent != NULL && ent->unkEc != NULL) {
                self->unk54 = NULL;
                return;
            }
        }
    }

    func_01ff8228(&data_ov085_020cb280, 0, 8);
    data_ov085_020cb280.self = self;
    data_ov085_020cb280.src = (Unk_ov085_Src*)(data_ov008_02064f08 + 0x2f11c);
    void* tmp = func_ov011_02066c28(data_ov008_02064f08, 0xb00b);
    func_ov013_0208eb04(tmp, 0xc10000e0, 1, 0, -1);

    data_ov085_020cb294.unk08 = data_ov085_020cb280.src->unk10;
    data_ov085_020cb294.obj14 = data_ov085_020cb280.self->obj;
    data_ov085_020cb294.unk44 = 0;
    data_ov085_020cb294.unk5c = 0;
    data_ov085_020cb294.unk60 = 0;

    if (ent == NULL) {
        ent = (Unk_ov085_Obj*)func_ov011_0206661c(data_ov008_02064f08, 0x400f, -1);
    }
    data_ov085_020cb294.unk2c = ent;
    if (func_ov011_02066dac(data_ov008_02064f08, 0x3000) == NULL) {
        func_ov011_0206661c(data_ov008_02064f08, 0x3000, -1);
    }

    if (((s32)(data_ov085_020cb294.obj14->unkF0 << 8) >> 20) == 0 ||
        ((Unk_ov085_Mgr*)(data_ov008_02064f08 + 0x2d43c))->vf14(0, 0x402a) == 0) {
        u32 v = data_ov085_020cb294.obj14->unk20 + 0x6c00;
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e96f0, v - 0x1b000, 0x3c);
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e9720, v, 0x3c);
        func_ov120_020d4a34(data_ov008_02064f08 + 0x1e9780, 0x10000, 0x3c);
    }
    self->unk54 = func_ov085_020c9208;
}
