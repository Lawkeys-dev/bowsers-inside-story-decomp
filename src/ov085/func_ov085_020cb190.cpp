#include "types.h"

struct Unk_ov085_020cb190_c {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ u32 unk14;
};

struct Unk_ov085_020cb190 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0c */ Unk_ov085_020cb190_c *unk0c;
};

struct Unk_ov085_020cb294 {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ void (*unk0c)();
};

// Object reached through data_ov008_02064f08 + 0x3c + 0x2d400. Slot 6 (0x18) is called.
class Unk_ov008_Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    /* 0x18 */ virtual void vf6(u32 a, u32 b, u32 c);
};

extern "C" void func_ov014_02098650();
extern "C" void func_ov085_020c9a4c();
extern "C" Unk_ov085_020cb294 data_ov085_020cb294;
extern "C" u8 *data_ov008_02064f08;

// TODO (99.29%): only the register choice of the global store differs. The original
// loads the function address into r2 and the global address into r1, mwcc uses r1 and r0.
// Tried: u32 cast, local function pointer, pointer local for the global, dropping the
// hoisted val local. None changed the register allocation.
extern "C" u32 func_ov085_020cb190(Unk_ov085_020cb190 *self) {
    u32 val = self->unk08;
    if (self->unk0c->unk14 != 0) {
        return val;
    }
    data_ov085_020cb294.unk0c = func_ov085_020c9a4c;
    func_ov014_02098650();
    Unk_ov008_Obj *obj = (Unk_ov008_Obj *)(data_ov008_02064f08 + 0x3c + 0x2d400);
    obj->vf6(0, 0x4039, 0);
    self->unk00 = 0;
    return 0;
}
