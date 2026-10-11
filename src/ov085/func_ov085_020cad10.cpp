#include "types.h"

struct Unk_ov085_020cad10_Sub {
    /* 0x00 */ void* vtbl;
    /* 0x04 */ u8 pad04[0x0c];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 pad14[0x02];
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u8 pad1c[0x22];
    /* 0x3e */ s16 unk3e;
};

struct Unk_ov085_020cad10 {
    /* 0x00 */ void* vtbl;
    /* 0x04 */ u8 pad04[0x0c];
    /* 0x10 */ Unk_ov085_020cad10_Sub* unk10;
};

struct Unk_ov085_020cb294 {
    /* 0x00 */ u8 pad00[0x4c];
    /* 0x4c */ s32 unk4c;
};

extern "C" Unk_ov085_020cb294 data_ov085_020cb294;
extern "C" void func_ov085_020cad94();

extern "C" void func_ov085_020cad10(Unk_ov085_020cad10* self) {
    Unk_ov085_020cad10_Sub* p = self->unk10;
    p->unk3e -= data_ov085_020cb294.unk4c;
    if (p->unk3e < 0) {
        s32 off = ((s32*)(*(u32*)p))[-3];
        Unk_ov085_020cad10_Sub* b = (Unk_ov085_020cad10_Sub*)((u8*)p + off);
        b->unk18 = 0;
        b->unk16 &= -0x4000;
        b->unk10 |= 0x800000;
        b->unk16 &= ~0x8000;
        b->unk10 &= ~0xfe000000;
        b->unk10 |= 0x2000000;
        self->vtbl = (void*)func_ov085_020cad94;
    }
}
