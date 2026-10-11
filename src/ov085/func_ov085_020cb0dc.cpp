#include "types.h"

// Virtual slots other than the called ones are placeholders.
class Unk_ov085_020cb0dc_emb {
public:
    virtual void vf00();
    virtual void vf04(void *a);
};

class Unk_ov085_020cb0dc_sub {
public:
    virtual void vf00();
    virtual void vf04(void *buf);
};

struct Unk_ov085_020cb0dc_obj {
    /* 0x00 */ u8 pad00[0xc];
    /* 0x0c */ Unk_ov085_020cb0dc_emb unk0c;
    /* 0x10 */ u8 pad10[0x2c];
    /* 0x3c */ s16 unk3c;
    /* 0x3e */ s16 unk3e;
};

struct Unk_ov085_020cb0dc_buf {
    /* 0x00 */ u32 unk00[3];
};

struct Unk_ov085_020cb0dc {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8 pad04[4];
    /* 0x08 */ Unk_ov085_020cb0dc_sub *unk08;
    /* 0x0c */ Unk_ov085_020cb0dc_obj *unk0c;
};

extern "C" u8 *data_ov008_02064f08;
extern "C" Unk_ov085_020cb0dc_buf data_ov085_020cb224;
extern "C" Unk_ov085_020cb0dc_obj *func_ov015_020a0f98(u8 *base, u32 a, u32 b);
extern "C" void func_ov015_0209fa78(Unk_ov085_020cb0dc_emb *emb, u32 a, u32 b);
extern "C" void func_ov085_020cb190();

extern "C" void func_ov085_020cb0dc(Unk_ov085_020cb0dc *self) {
    Unk_ov085_020cb0dc_sub *r4;
    Unk_ov085_020cb0dc_buf buf;

    r4 = self->unk08;
    self->unk0c = func_ov015_020a0f98(data_ov008_02064f08 + 0x25be8, 0x14e, 0);
    self->unk0c->unk3e = 0x2000;
    self->unk0c->unk3c = self->unk0c->unk3e;
    self->unk0c->unk0c.vf04((u8 *)r4 + 0x20);
    func_ov015_0209fa78(&self->unk0c->unk0c, 0, 0x400f);
    buf = data_ov085_020cb224;
    r4->vf04(&buf);
    self->unk00 = (u32)func_ov085_020cb190;
}
