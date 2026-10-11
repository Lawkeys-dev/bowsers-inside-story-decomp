#include "types.h"

/* Object whose first word is a vtable pointer (vtable entries are 4 bytes each) */
struct Unk_ov088_Obj {
    /* 0x00 */ void (**vtbl)(void *);
    /* 0x04 */ u8 pad04[0x8];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 pad0e[0x2e];
    /* 0x3c */ u32 unk3c;
    /* 0x40 */ u8 pad40[0xc0];
    /* 0x100 */ u8 unk100[0xc];
    /* 0x10c */ u16 unk10c;
};

/* Message passed to the state handler */
struct Unk_ov088_Msg {
    /* 0x00 */ s16 type;
    /* 0x02 */ u8 pad02[0x12];
    /* 0x14 */ Unk_ov088_Obj *obj;
};

/* State of the handler (argument r0) */
struct Unk_ov088_State {
    /* 0x00 */ u8 pad00[0x24];
    /* 0x24 */ s16 unk24;
};

/* 16-bit halfword whose low 14 bits are used */
struct Unk_ov088_Bits {
    /* 0x00 */ u16 val : 14;
    /* 0x00 */ u16 flags : 2;
};

/* Shared 0x2c-byte record filled in by the init case */
struct Unk_ov088_Rec {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

extern "C" u8 *data_ov008_02064f08;
extern "C" Unk_ov088_Rec data_ov016_020b8900;

extern "C" void *func_ov015_020a0f98(void *base, s32 a, s32 b);
extern "C" void func_ov014_02099bd4(Unk_ov088_Obj *obj);
extern "C" void func_ov014_0209799c(void *p, Unk_ov088_Obj *obj, s32 b);
extern "C" void func_ov016_020ad144(void *p, Unk_ov088_Rec *rec);
extern "C" void func_ov013_0208a300(void *p, u32 v);

extern "C" s32 func_ov088_020cbcb0(Unk_ov088_State *state, Unk_ov088_Msg *msg) {
    switch (msg->type) {
    case 0: {
        state->unk24++;
        msg->obj->vtbl[12](msg->obj);
        func_ov014_02099bd4(msg->obj);
        u32 *r4 = (u32 *)func_ov015_020a0f98(data_ov008_02064f08 + 0x3e8 + 0x25800, 0x147, 0);
        r4[0x40 / 4] = 0x2000;
        func_ov014_0209799c((u8 *)r4 + 0xc, msg->obj, 0);
        data_ov016_020b8900.unk00 = 0x42800a;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = msg->obj->unk0c;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x254 + 0x2cc00, &data_ov016_020b8900);
        u32 vt = *(u32 *)r4;
        s32 voff = *(s32 *)(vt - 0xc);
        Unk_ov088_Bits *bits = (Unk_ov088_Bits *)((u8 *)r4 + voff + 0x16);
        func_ov013_0208a300((u8 *)msg->obj + 0x100, bits->val);
        return 10;
    }
    case 10:
        msg->obj->unk3c |= 0x200;
    // fall through
    case 15:
        if (msg->obj->unk10c != 0) {
            return 15;
        }
        if (msg->obj != NULL) {
            msg->obj->vtbl[3](msg->obj);
        }
        msg->obj = NULL;
        return -1;
    default:
        return 0;
    }
}
