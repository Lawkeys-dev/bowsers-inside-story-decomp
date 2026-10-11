#include "types.h"

struct Unk_ov129_0206e3d4_Vtbl {
    /* 0x00 */ void* unk00;
    /* 0x04 */ void* unk04;
    /* 0x08 */ void* unk08;
    /* 0x0c */ void (*unk0c)(void* self);
};

struct Unk_ov129_0206e3d4_Inner {
    /* 0x00 */ Unk_ov129_0206e3d4_Vtbl* vtbl;
};

struct Unk_ov129_0206e3d4 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ Unk_ov129_0206e3d4_Inner* inner;
};

extern "C" void func_ov129_0206e3d4(Unk_ov129_0206e3d4* self) {
    Unk_ov129_0206e3d4_Inner* inner = self->inner;
    inner->vtbl->unk0c(inner);
}
