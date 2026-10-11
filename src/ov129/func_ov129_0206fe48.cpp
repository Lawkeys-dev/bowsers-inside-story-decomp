#include "types.h"

typedef void (*Unk_ov129_VFunc)(void *self, s32 arg);

struct Unk_ov129_Obj {
    /* 0x00 */ Unk_ov129_VFunc *vtable;
};

struct Unk_ov129_0206fe48 {
    /* 0x00 */ u8 pad00[0x30];
    /* 0x30 */ u8 *unk30;
    /* 0x34 */ u8 pad34[0x874 - 0x34];
    /* 0x874 */ Unk_ov129_Obj *unk874;
};

struct Unk_ov129_0206fe48_Buf {
    /* 0x00 */ u32 w0Bit0 : 1;
    /* 0x00 */ u32 w0Bits1to4 : 4;
    /* 0x00 */ u32 w0Bits5to9 : 5;
    /* 0x00 */ u32 w0Bits10to14 : 5;
    /* 0x00 */ u32 w0Rest : 17;
    /* 0x04 */ u32 w1Bits0to4 : 5;
    /* 0x04 */ u32 w1Bits5to7 : 3;
    /* 0x04 */ u32 w1Bit8 : 1;
    /* 0x04 */ u32 w1Bits9to16 : 8;
    /* 0x04 */ u32 w1Idx : 11;
    /* 0x04 */ u32 w1Bits28to31 : 4;
    /* 0x08 */ u32 w2Bit0 : 1;
    /* 0x08 */ u32 w2Field1 : 9;
    /* 0x08 */ u32 w2Field2 : 9;
    /* 0x08 */ u32 w2Bits19to26 : 8;
    /* 0x08 */ u32 w2Rest : 5;
    /* 0x0c */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u32 unk1c;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 w9Bits0to6 : 7;
    /* 0x24 */ u32 w9Rest : 25;
};

extern "C" void func_0200dcdc(void *obj, Unk_ov129_0206fe48_Buf *out, u32 a, u32 b);
extern "C" void func_0200e24c(void *obj, s32 a, s32 b, void *c);
extern "C" void func_ov000_02063ba8(void *obj, Unk_ov129_0206fe48_Buf *buf, s32 c);
extern "C" u8 data_02050164[];

// TODO: 77.20% match. buf is a bitfield struct (the constant masks now match the original literal pool). Still
// differs: mwcc sinks the two rsb values (0x82 - w, 0x38 - h) below the call to func_0200dcdc, while the original
// computes them before it, keeping w and h in the argument registers. That moves self/idx/temporaries to other
// registers (self in r5 instead of r7, idx in r4 instead of r6) and reorders the bitfield read-modify-write sequences.
extern "C" void func_ov129_0206fe48(Unk_ov129_0206fe48 *self, u32 idx) {
    Unk_ov129_0206fe48_Buf buf;
    self->unk874->vtable[1](self->unk874, 0);
    u8 *base = self->unk30;
    u32 off = ((u32 *)base)[idx];
    u8 *ent = base + off;
    u32 w = (ent[0] + 1) << 2;
    u32 r4 = 0x82 - w;
    u32 h = (ent[1] & ~3) << 1;
    u32 r5 = 0x38 - h;
    func_0200dcdc(self->unk874, &buf, h, w);
    buf.w0Bit0 = 1;
    buf.w0Bits1to4 = 3;
    buf.w0Bits5to9 = 0;
    buf.w0Bits10to14 = 0;
    buf.w1Bits0to4 = 0x10;
    buf.w1Bits5to7 = 0;
    buf.w1Bit8 = 0;
    buf.w1Bits9to16 = 0;
    buf.w1Idx = idx;
    buf.w1Bits28to31 = 6;
    buf.w2Bit0 = 1;
    buf.w2Field1 = r4;
    buf.w2Field2 = r5;
    buf.w2Bits19to26 = 0;
    buf.w9Bits0to6 = 8;
    buf.unkC = 0;
    buf.unk10 = (u32)self + 0x85c;
    buf.unk14 = (u32)self->unk30;
    buf.unk18 = 0;
    buf.unk1c = 0;
    func_0200e24c(self->unk874, 1, 0xf, data_02050164);
    func_ov000_02063ba8(self->unk874, &buf, 0);
}
