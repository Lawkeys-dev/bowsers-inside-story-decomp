#include "types.h"

/* Placeholder structs until the owning class is identified. */

struct Unk_ov088_Node {
    /* 0x00 */ s32* vtbl;
    /* 0x04 */ u8 unk04[0x40 - 0x04];
    /* 0x40 */ u32 unk40;
};

struct Unk_ov088_Inner {
    /* 0x00 */ u8 unk00[0x40];
    /* 0x40 */ u32 unk40;
};

struct Unk_ov088_Obj {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ Unk_ov088_Inner* unk20;
    /* 0x24 */ u8 unk24[0x30 - 0x24];
    /* 0x30 */ s16 unk30;
};

struct Unk_ov088_B {
    /* 0x00 */ u8 unk00[0xc];
    /* 0x0c */ u16 unkC;
    /* 0x0e */ u8 unk0E[0xec - 0xe];
    /* 0xec */ Unk_ov088_Obj* unkEC;
};

struct Unk_ov088_A {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ Unk_ov088_B* unk10;
};

struct Unk_ov088_This {
    /* 0x00 */ Unk_ov088_A* unk0;
    /* 0x04 */ u8 unk04[0x0c - 0x04];
    /* 0x0c */ Unk_ov088_Node* unkC;
    /* 0x10 */ Unk_ov088_Node* unk10;
    /* 0x14 */ u8 unk14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
};

struct Unk_ov088_Ov016 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0A;
    /* 0x0b */ u8 unk0B;
    /* 0x0c */ u16 unk0C;
    /* 0x0e */ u16 unk0E;
};

extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov088_Ov016 data_ov016_020b8900;

extern "C" s32 func_ov014_02096290(Unk_ov088_Obj* obj);
extern "C" void func_ov014_0209799c(void* dst, Unk_ov088_B* b, s32 arg);
extern "C" Unk_ov088_Node* func_ov015_020a0f98(void* mgr, s32 msg, s32 arg);
extern "C" void func_ov016_020ad144(void* arg);

extern "C" void func_ov088_020c9724(Unk_ov088_This* self) {
    Unk_ov088_Obj* obj = self->unk0->unk10->unkEC;
    if (obj != NULL && obj->unk20 != NULL) {
        u32 t = obj->unk20->unk40;
        if (t != 0xc10000d9 && t != 0xc10000d9 + 0x2a && t != 0xc10000d9 + 0x2b) {
            return;
        }
    }

    Unk_ov088_Node* node = NULL;
    s16 state = obj != NULL ? obj->unk30 : (s16)0;
    s32 r0 = obj != NULL ? func_ov014_02096290(obj) : 0;

    u32 msg = 0;
    switch (state) {
        case 5:
            if (r0 == 5 || r0 == 0xc) {
                if (self->unk18 >= 1) {
                    return;
                }
                self->unk18 = 1;
                if (r0 == 5) {
                    node = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xbc, 0);
                    self->unkC = node;
                    *(void**)((u8*)node + node->vtbl[-3] + 0x1c) = &self->unkC;
                } else if (r0 == 0xc) {
                    node = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xbd, 0);
                    self->unk10 = node;
                    *(void**)((u8*)node + node->vtbl[-3] + 0x1c) = &self->unk10;
                }
                msg = 0xc0;
            } else {
                self->unk18 = 0;
            }
            break;
        case 6:
            if (r0 == 4 || r0 == 0xb) {
                if (self->unk18 >= 1) {
                    return;
                }
                self->unk18 = 1;
                if (r0 == 4) {
                    node = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xbe, 0);
                } else if (r0 == 0xb) {
                    node = func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0xbf, 0);
                }
                msg = 0xc0;
            } else {
                self->unk18 = 0;
            }
            break;
        default:
            self->unk18 = 0;
            break;
    }

    if (node == NULL) {
        return;
    }
    node->unk40 = 0x2000;
    func_ov014_0209799c((u8*)node + 0xc, self->unk0->unk10, 0);
    if (msg != 0) {
        func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, msg, 1);
    }
    data_ov016_020b8900.unk00 = 0x20428006;
    data_ov016_020b8900.unk04 = 0;
    data_ov016_020b8900.unk06 = 0;
    data_ov016_020b8900.unk08 = 1;
    data_ov016_020b8900.unk0A = 0x7f;
    data_ov016_020b8900.unk0B = 0;
    data_ov016_020b8900.unk0C = self->unk0->unk10->unkC;
    data_ov016_020b8900.unk0E = 0x7f;
    func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00);
}
