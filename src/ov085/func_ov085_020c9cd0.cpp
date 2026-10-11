#include "types.h"

// Virtual slots 0x00-0x40 are unknown placeholders, only slots 0x44 and 0x48 are called here.
class Unk_ov085_Obj {
public:
    virtual void vf00();
    virtual void vf04();
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
    /* 0x44 */ virtual void unk44(u32 arg);
    /* 0x48 */ virtual void unk48(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 unk04[0x20 - 0x04];
    /* 0x20 */ s32 x;
    /* 0x24 */ s32 y;
    /* 0x28 */ s32 z;
    /* 0x2c */ u8 unk2c[0xec - 0x2c];
    /* 0xec */ void* unkEc;
};

// Object at data_ov008_02064f08 + 0x305a0, slot 0x04 is called with one argument.
class Unk_ov085_Slot {
public:
    virtual void vf00();
    virtual void vf04(u32 arg);
};

struct Unk_ov085_State {
    /* 0x00 */ void (*func)(Unk_ov085_State* self);
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_Obj* obj;
};

/* word at 0x08 of the sub-object */
struct Unk_ov085_Sub08 {
    /* bits 0-4 */ u32 pad0 : 5;
    /* bits 5-9 */ u32 by : 5;
    /* bits 10-14 */ u32 bx : 5;
    /* bits 15-31 */ u32 rest : 17;
};

/* word at 0xa4 of the sub-object */
struct Unk_ov085_SubA4 {
    /* bits 0-25 */ u32 pad0 : 26;
    /* bit 26 */ u32 flag : 1;
    /* bits 27-31 */ u32 rest : 5;
};

struct Unk_ov085_Sub {
    /* 0x00 */ u8 unk00[0x08];
    /* 0x08 */ Unk_ov085_Sub08 w08;
    /* 0x0c */ u8 unk0c[0xa4 - 0x0c];
    /* 0xa4 */ Unk_ov085_SubA4 wA4;
};

struct Unk_ov085_Fnobj {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ void (*fn)(void* self, u32 arg);
};

/* data_0205afa8, byte 0x18 */
struct Unk_ov085_Afa8 {
    /* 0x00 */ u8 unk00[0x18];
    /* 0x18 */ u8 pad18 : 3;
    /* 0x18 */ u8 flag18 : 1;
    /* 0x18 */ u8 rest18 : 4;
};

extern "C" void* data_ov008_02064f08;
extern "C" Unk_ov085_Obj* func_ov011_02066dac(void* a, u32 b);
extern "C" Unk_ov085_Obj* func_ov011_0206661c(void* a, u32 b, s32 c);
extern "C" u32 func_ov011_02066c28(void* a, u32 b);
extern "C" s32 func_ov014_02096a48(Unk_ov085_Obj* obj);
extern "C" void func_ov014_02097538(s32* p, s32* out, s32 n);
extern "C" void func_ov014_020978bc(Unk_ov085_Obj* o, s32* out, u32 n);
extern "C" void func_ov014_02097b18(Unk_ov085_Obj* o, u32 n);
extern "C" void func_ov014_02098650(Unk_ov085_Obj* o);
extern "C" void func_ov120_020d4a34(void* dst, s32 src, u32 n);
extern "C" void func_ov085_020c9acc(Unk_ov085_State* self);
extern "C" void func_ov085_020c9f3c(Unk_ov085_State* self);

extern "C" Unk_ov085_Afa8 data_0205afa8;
extern "C" u8 data_ov085_020cb294[];

// TODO: 90.79% match. Remaining diff is register allocation in the pos[0] wrap block: the original keeps pos[0]
// in r2 and the sub-object pointer in r3, mine has them swapped (and by/bx in other registers). Tried without
// success: bit-field reads at point of use (82-84%), p0 declared before/after sub and by/bx (89-90%), wrap as
// `p0 >= 0xf000` value (88.9%), inline flag read (84%).
extern "C" void func_ov085_020c9cd0(Unk_ov085_State* self) {
    Unk_ov085_Obj* obj = self->obj;
    Unk_ov085_Obj* other = func_ov011_02066dac(data_ov008_02064f08, 0x3002);
    if (other == NULL) {
        other = func_ov011_0206661c(data_ov008_02064f08, 0x3002, -1);
    }
    u8 bitA = (*(Unk_ov085_Sub**)((u8*)data_ov008_02064f08 + 0x30000 + 0x5ec))->wA4.flag;
    if (bitA == 0) {
        return;
    }
    if (other->unkEc == NULL) {
        s32 pos[3];
        func_ov014_02097538(&obj->x, pos, func_ov014_02096a48(obj));
        Unk_ov085_Sub* sub = *(Unk_ov085_Sub**)((u8*)data_ov008_02064f08 + 0x30000 + 0x5ec);
        s32 wrap = 0;
        u32 by = sub->w08.by;
        u32 bx = sub->w08.bx;
        s32 p0 = pos[0];
        if (p0 >= 0xf000) {
            pos[0] = p0 - 0xf000;
            wrap = 1;
        }
        pos[0] += (((by + 1) << 3) - 0x6c) << 8;
        if (wrap) {
            pos[0] += 0xf000;
        }
        pos[1] += (((bx + 1) << 3) - 0x52) << 8;
        pos[2] = 0;
        other->unk44(func_ov011_02066c28(data_ov008_02064f08, 0xa001));
        other->unk48(0, -1, 0x100, 1);
        func_ov014_02097b18(other, 0);
        func_ov014_020978bc(other, pos, 0);
    }
    if (data_0205afa8.flag18 == 0) {
        u16 m = *(u16*)((u8*)data_ov008_02064f08 + 0x16) & 0x401;
        if (m == 0) {
            return;
        }
    }
    func_ov014_02098650(other);
    Unk_ov085_Slot* slot = (Unk_ov085_Slot*)((u8*)data_ov008_02064f08 + 0x30000 + 0x5a0);
    slot->vf04(0);
    u32 cnt = data_ov085_020cb294[0x60] + 1;
    data_ov085_020cb294[0x60] = cnt;
    if ((cnt & 0xff) < 2) {
        self->func = func_ov085_020c9acc;
        return;
    }
    s32 base = *(s32*)(*(u8**)(data_ov085_020cb294 + 0x14) + 0x20);
    s32 r4 = base + 0x6c00;
    func_ov120_020d4a34((u8*)data_ov008_02064f08 + 0x1e96f0, r4 - 0x1b000, 0x3c);
    func_ov120_020d4a34((u8*)data_ov008_02064f08 + 0x1e9720, r4, 0x3c);
    self->func = func_ov085_020c9f3c;
}
