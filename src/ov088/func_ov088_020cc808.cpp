#include "types.h"

typedef void (*Unk_ov088_Fn)(void* self);

struct Unk_ov088_Sub {
    /* 0x00 */ u8 pad00[0x16];
    /* 0x16 */ u16 unk16 : 14;
};

struct Unk_ov088_Obj {
    /* 0x00 */ Unk_ov088_Fn* vtbl;
    /* 0x04 */ u8 pad04[0x8];
    /* 0x0c */ u16 unkC;
    /* 0x0e */ u8 pad0e[0x2];
    /* 0x10 */ u8 pad10[0x2c];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u8 pad40[0xc0];
    /* 0x100 */ u8 pad100[0xc];
    /* 0x10c */ u16 unk10c;
};

struct Unk_ov088_Msg {
    /* 0x00 */ s16 type;
    /* 0x02 */ u8 pad02[0x12];
    /* 0x14 */ Unk_ov088_Obj* obj;
};

struct Unk_ov088_Self {
    /* 0x00 */ u8 pad00[0x24];
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 pad26[0x2];
    /* 0x28 */ s16 unk28;
};

struct Unk_ov088_Global {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0a */ u8 unkA;
    /* 0x0b */ u8 unkB;
    /* 0x0c */ u16 unkC;
    /* 0x0e */ u16 unkE;
};

extern "C" u32 data_ov008_02064f08;
extern "C" Unk_ov088_Global data_ov016_020b8900;

extern "C" void* func_ov015_020a0f98(void* heap, s32 id, s32 arg);
extern "C" void func_ov014_02099bd4(Unk_ov088_Obj* obj);
extern "C" void func_ov014_0209799c(void* p, Unk_ov088_Obj* obj, s32 arg);
extern "C" void func_ov016_020ad144(void* p);
extern "C" void func_ov013_0208a300(void* p, u32 v);

extern "C" s32 func_ov088_020cc808(Unk_ov088_Self* self, Unk_ov088_Msg* msg) {
    switch (msg->type) {
    case 0:
        self->unk24++;
        self->unk28++;
        ((Unk_ov088_Fn*)msg->obj->vtbl)[12](msg->obj);
        func_ov014_02099bd4(msg->obj);
        {
            u8* heap = (u8*)data_ov008_02064f08;
            u32* r4 = (u32*)func_ov015_020a0f98(heap + 0x3e8 + 0x25800, 0xdd, 0);
            r4[0x40 / 4] = 0x2000;
            func_ov014_0209799c((u8*)r4 + 0xc, msg->obj, 0);
            data_ov016_020b8900.unk0 = 0x38066;
            data_ov016_020b8900.unk4 = 0;
            data_ov016_020b8900.unk6 = 0;
            data_ov016_020b8900.unk8 = 1;
            data_ov016_020b8900.unkA = 0x7f;
            data_ov016_020b8900.unkB = 0;
            data_ov016_020b8900.unkC = msg->obj->unkC;
            data_ov016_020b8900.unkE = 0x7f;
            func_ov016_020ad144((u8*)data_ov008_02064f08 + 0x254 + 0x2cc00);
            s32 off = *(s32*)(*(u8**)r4 - 0xc);
            Unk_ov088_Sub* sub = (Unk_ov088_Sub*)((u8*)r4 + off);
            func_ov013_0208a300((u8*)msg->obj + 0x100, sub->unk16);
        }
        return 10;
    case 10:
        msg->obj->unk3c |= 0x200;
    case 15:
        if (msg->obj->unk10c != 0) {
            return 15;
        }
        if (msg->obj != NULL) {
            ((Unk_ov088_Fn*)msg->obj->vtbl)[3](msg->obj);
        }
        msg->obj = NULL;
        return -1;
    default:
        return 0;
    }
}
