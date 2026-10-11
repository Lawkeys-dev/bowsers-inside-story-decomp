#include "types.h"

// Vtable slots 0x00-0x40 are unknown placeholders, slots 0x04, 0x44 and 0x48 are called here.
class Unk_ov085_Obj {
public:
    virtual void vf00();
    /* 0x04 */ virtual void unk04(void* p);
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    /* 0x44 */ virtual void unk44(void* p);
    /* 0x48 */ virtual void unk48(s32 a, s32 b, s32 c, s32 d);
};

class Unk_ov085_Emb {
public:
    virtual void vf00();
    virtual void unk04(void* arg);
};

struct Unk_ov085_Sub {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ Unk_ov085_Emb emb;
    /* 0x10 */ u8 unk10[0x3c - 0x10];
    /* 0x3c */ s16 unk3c;
    /* 0x3e */ s16 unk3e;
};

struct Unk_ov085_State {
    /* 0x00 */ void* vtbl;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_Obj* obj;
    /* 0x0c */ Unk_ov085_Sub* sub;
};

struct Unk_ov085_Pos {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
};

struct Unk_ov085_Cfg {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x20 - 0xe];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
};

struct Unk_ov085_Global {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ Unk_ov085_Cfg* cfg;
};

struct Unk_ov085_Raw {
    /* 0x00 */ s32 w[3];
};

struct Unk_ov016_020b8900 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

extern "C" Unk_ov085_Global data_ov085_020cb294;
extern "C" Unk_ov085_Raw data_ov085_020cb218;
extern "C" Unk_ov016_020b8900 data_ov016_020b8900;
extern "C" u8* data_ov008_02064f08;

extern "C" void* func_ov011_02066c28(u8* base, s32 id);
extern "C" Unk_ov085_Sub* func_ov015_020a0f98(u8* base, s32 id, s32 b);
extern "C" void func_ov015_0209fa78(void* p, s32 a, s32 b);
extern "C" void func_ov016_020ad144(void* p);
extern "C" void func_ov085_020caf8c();

extern "C" void func_ov085_020cae08(Unk_ov085_State* self) {
    Unk_ov085_Cfg* cfg = data_ov085_020cb294.cfg;
    Unk_ov085_Obj* obj = self->obj;
    Unk_ov085_Pos pos;
    Unk_ov085_Raw copy;

    pos.x = cfg->unk20 + 0x3800;
    pos.y = cfg->unk24;
    pos.z = cfg->unk28 - 0x2000;

    obj->unk44(func_ov011_02066c28(data_ov008_02064f08, 0xb00b));
    obj->unk48(0, -1, 0x100, 0);
    copy = data_ov085_020cb218;
    obj->unk04(&copy);

    self->sub = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0x14a, 0);
    func_ov015_0209fa78(&self->sub->emb, 0, 0x400f);
    self->sub->unk3c = 0x2000;
    self->sub->unk3e = self->sub->unk3c;
    self->sub->emb.unk04(&pos);

    cfg = data_ov085_020cb294.cfg;
    u16 unkC = cfg->unk0c;
    data_ov016_020b8900.unk00 = 0x42000b;
    data_ov016_020b8900.unk04 = 0;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0a = 0x7f;
    data_ov016_020b8900.unk0b = 0;
    data_ov016_020b8900.unk0c = unkC;
    data_ov016_020b8900.unk0e = 0x7f;

    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
    self->vtbl = (void*)func_ov085_020caf8c;
}
