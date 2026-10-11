#include "types.h"

// Placeholder layouts, named by role until the owning classes are identified.

struct Unk_ov088_Inner {
    /* 0x00 */ u8 unk00[0x0c];
    /* 0x0c */ u16 unk0c;
};

struct Unk_ov088_Ec2 {
    /* 0x00 */ u8 unk00[0x40];
    /* 0x40 */ s32 unk40;
};

struct Unk_ov088_Ec {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ Unk_ov088_Ec2* unk20;
};

// Virtual slots 0x00-0x40 are unknown placeholders, only slots 0x08, 0x0c, 0x44 and 0x48 are called here.
class Unk_ov088_Obj {
public:
    virtual void vf00();
    virtual void vf04();
    virtual s32 vf08();
    virtual s32 vf0c();
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

    /* 0x04 */ u8 unk04[0x0c - 0x04];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x20 - 0x0e];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2c */ u8 unk2c[0x34 - 0x2c];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 unk38[0xec - 0x38];
    /* 0xec */ Unk_ov088_Ec* ec;
    /* 0xf0 */ u8 unkf0[0x100 - 0xf0];
    /* 0x100 */ Unk_ov088_Inner inner;
};

// Object reached through the global at 0x2f000 (the 0x12c field is an Unk_ov088_Obj).
struct Unk_ov088_Ctx {
    /* 0x000 */ u8 unk000[0x12c];
    /* 0x12c */ Unk_ov088_Obj* obj;
    /* 0x130 */ u8 unk130[0x13c - 0x130];
    /* 0x13c */ s32 unk13c;
    /* 0x140 */ u8 unk140[0x14e - 0x140];
    /* 0x14e */ s16 unk14e;
    /* 0x150 */ u8 unk150[0x174 - 0x150];
    /* 0x174 */ s32 unk174;
};

struct Unk_ov088_Ent {
    /* 0x00 */ u8 unk00[0x0c];
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u8 unk0e[0x3c - 0x0e];
    /* 0x3c */ u32 flags;
};

// Object with a virtual base: the base sits at this + vtbl[-3].
struct Unk_ov088_Fx {
    /* 0x00 */ void** vtbl;
    /* 0x04 */ u8 unk04[0x0c - 0x04];
    /* 0x0c */ u8 unk0c[0x38 - 0x0c];
    /* 0x38 */ u16 unk38;
};

struct Unk_ov088_VBase {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 unk14[0x16 - 0x14];
    /* 0x16 */ u16 unk16;
    /* 0x18 */ s32 unk18;
};

struct Unk_ov088_Self {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s32 state;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a[0x22 - 0x0a];
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 unk26[0x2c - 0x26];
    /* 0x2c */ Unk_ov088_Ent* ent;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3c */ s32 pts[3][3];
    /* 0x60 */ Unk_ov088_Fx* fx;
    /* 0x64 */ u8 unk64[0x78 - 0x64];
    /* 0x78 */ s32 unk78;
    /* 0x7c */ s32 unk7c;
};

struct Unk_ov088_Pair {
    /* 0x00 */ s32 a;
    /* 0x04 */ s32 b;
};

struct Unk_ov088_CdData {
    /* 0x00 */ u8 unk00[0x74];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 unk78;
};

struct Unk_ov088_Input {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16[0x18 - 0x16];
    /* 0x18 */ u8 unk18Low : 3;
    /* 0x18 */ u8 bit3 : 1;
};

struct Unk_ov016_Msg {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u16 unk0c;
    /* 0x0e */ u16 unk0e;
};

extern "C" u8* data_ov008_02064f08;
extern "C" Unk_ov088_Pair data_ov088_020cd344;
extern "C" Unk_ov088_Pair data_ov088_020cd32c;
extern "C" Unk_ov088_CdData data_ov088_020cd2e0;
extern "C" Unk_ov088_Input data_0205afa8;
extern "C" Unk_ov016_Msg data_ov016_020b8900;

extern "C" void func_ov088_020c94b4(Unk_ov088_Self* self, Unk_ov088_Pair pair, s32 c, s32 d);
extern "C" void func_ov088_020c95a4(Unk_ov088_Self* self, Unk_ov088_Obj* obj, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 func_ov088_020caefc(Unk_ov088_Self* self);
extern "C" void func_ov013_0208a300(void* p, u32 v);
extern "C" s32 func_ov120_020d4954(void* p);
extern "C" void func_ov120_020d71a4(void* p);
extern "C" u32 func_ov011_02066c28(void* p, u32 v);
extern "C" void func_ov014_020961bc(void* ec, u32 v);
extern "C" s32 func_ov014_02096360(void* ec);
extern "C" void func_ov120_020d4f08(void* a, u32 b, s32 c, s32 d, s32 e);
extern "C" Unk_ov088_Fx* func_ov015_020a0f98(void* p, s32 a, s32 b);
extern "C" void func_ov014_02097b18(void* p);
extern "C" void func_ov014_020977e8(void* p, s32* v);
extern "C" void func_ov120_020d722c(void* p);
extern "C" void func_ov016_020ad144(void* p, void* q);
extern "C" void func_ov014_02098650(Unk_ov088_Obj* obj, s32 v);
extern "C" s32 func_ov120_020d53c0(Unk_ov088_Self* self);
extern "C" void func_ov120_020d9954(void* p, s32* in, s32* out);

#define OV008_CTX() ((Unk_ov088_Ctx*)(data_ov008_02064f08 + 0x2f000))
#define OV088_X() ((Unk_ov088_Obj*)(data_ov008_02064f08 + 0x1e96b0))

// TODO: about 93.7% matched. Still differing: the loop flag (the original materializes 1 after the loop and tests it
// with cmp r0,#0, the loop here tests the counter against 3), the scheduling of the global pointer load before the
// stack argument of the unk48 call in case 0x1e, the register picks for the position block (the original keeps the
// global base in r0), the X object constant loads, and the reload of self->ent in the 0x1e block.
extern "C" s32 func_ov088_020ca4d0(Unk_ov088_Self* self) {
    switch (self->state) {
    case 0x00:
        func_ov088_020c94b4(self, data_ov088_020cd344, 0, 0);
        func_ov013_0208a300(&OV008_CTX()->obj->inner, 0x2d);
        // fallthrough
    case 0x14:
        if (OV008_CTX()->obj->inner.unk0c != 0) {
            return 0x14;
        }
        func_ov088_020c95a4(self, OV008_CTX()->obj, 0, 0x1d8, 1, 0, 0x28);
        // fallthrough
    case 0x19:
        if (func_ov120_020d4954(data_ov008_02064f08 + 0x1e96ec) != 0) {
            return 0x19;
        }
        func_ov120_020d71a4(data_ov008_02064f08);
        OV008_CTX()->obj->unk44(func_ov011_02066c28(data_ov008_02064f08, 0xa002));
        OV008_CTX()->obj->unk48(0, -1, 0x100, 0);
        if (OV008_CTX()->obj->ec != NULL) {
            func_ov014_020961bc(OV008_CTX()->obj->ec, 1);
        }
        // fallthrough
    case 0x1e: {
        {
            Unk_ov088_Ec* ec = OV008_CTX()->obj->ec;
            s32 ret = (ec == NULL) ? 1 : func_ov014_02096360(ec);
            if (ret == 0) {
                return 0x1e;
            }
        }
        OV008_CTX()->obj->unk48(1, -1, 0x100, 0);

        s32 pos[3];
        pos[0] = OV008_CTX()->obj->unk20 + 0x3c00;
        pos[1] = OV008_CTX()->obj->unk24;
        pos[2] = OV008_CTX()->obj->unk28 + 0x6200;
        self->pts[0][0] = pos[0];
        self->pts[0][1] = pos[1] - pos[2];
        self->pts[0][2] = 0;
        {
            Unk_ov088_Obj* x = OV088_X();
            s32 half = x->unk34;
            self->pts[1][0] = x->vf08() + half / 2;
        }
        {
            Unk_ov088_Obj* x = OV088_X();
            self->pts[1][1] = x->vf0c() + (x->unk34 << 8) / 432;
        }
        self->pts[1][2] = 0;
        {
            Unk_ov088_Obj* x = OV088_X();
            s32 half = x->unk34;
            self->pts[2][0] = x->vf08() + half / 2;
        }
        self->pts[2][1] = OV088_X()->vf0c();
        self->pts[2][2] = 0;
        self->ent->flags &= ~0x200;
        func_ov120_020d4f08(NULL, 0xa004, 0x8e, 0x30, self->ent->unk0c);
        self->fx = func_ov015_020a0f98(data_ov008_02064f08 + 0x25be8, 0x172, 0);
        {
            Unk_ov088_VBase* vb = (Unk_ov088_VBase*)((u8*)self->fx + ((s32*)self->fx->vtbl)[-3]);
            vb->unk10 &= 0x01ffffff;
        }
        func_ov014_02097b18(&self->fx->unk0c);
        pos[2] += 0x1c00;
        func_ov014_020977e8(&self->fx->unk0c, pos);
        self->fx->unk38 = 0x30;
    }
        // fallthrough
    case 0x64:
        if (func_ov088_020caefc(self) == 0 && self->unk24 == self->unk22) {
            return 0xc8;
        }
        {
            u8* g = data_ov008_02064f08;
            if (*(s16*)(g + 0x2f14e) <= 0) {
                return 0xc8;
            }
            if (((Unk_ov088_Ctx*)(g + 0x2f000))->unk13c == 0) {
                break;
            }
        }
        // fallthrough
    case 0x6e: {
        u8* g = data_ov008_02064f08;
        if (*(s16*)(g + 0x2f14e) <= 0) {
            return 0xc8;
        }
        if (((Unk_ov088_Ctx*)(g + 0x2f000))->unk13c != 0) {
            return 0x6e;
        }
        OV008_CTX()->obj->unk44(func_ov011_02066c28(g, 0xa002));
        OV008_CTX()->obj->unk48(1, -1, 0x100, 0);
    }
        break;
    case 0x82:
        goto entry82;
    case 0xc8:
        goto entryC8;
    case 0xd2:
        goto entryD2;
    case 0xdc:
        goto entryDC;
    case 0xe6:
        goto entryE6;
    case 0xfa:
        goto entryFA;
    default:
        goto entryDefault;
    }

    // Shared tail, reached by the 0x64 and 0x6e cases.
    self->unk30 = self->unk30 + 1;
    if (data_0205afa8.bit3 == 0) {
        return 0x64;
    }
    {
        s32 in[3];
        s32 out[3];
        in[0] = data_0205afa8.unk14 << 8;
        in[1] = data_0205afa8.unk15 << 8;
        in[2] = 0;
        func_ov120_020d9954(data_ov008_02064f08 + 0x1e97b0, in, out);
        out[1] = out[1] - out[2];
        out[2] = 0;

        {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 j = (i == 2) ? 0 : i + 1;
                s32 dxi = out[0] - self->pts[i][0];
                s32 dyj = self->pts[j][1] - self->pts[i][1];
                s32 dyi = out[1] - self->pts[i][1];
                s32 dxj = self->pts[j][0] - self->pts[i][0];
                s16 a = dxi / 16;
                s16 b = dyj / 16;
                s16 c = dyi / 16;
                s16 d = dxj / 16;
                if (a * b <= c * d) {
                    break;
                }
            }
            if (i != 3) {
                goto done;
            }
        }

        data_ov016_020b8900.unk00 = 0x38039;
        data_ov016_020b8900.unk04 = 0;
        data_ov016_020b8900.unk06 = 0;
        data_ov016_020b8900.unk08 = 1;
        data_ov016_020b8900.unk0a = 0x7f;
        data_ov016_020b8900.unk0b = 0;
        data_ov016_020b8900.unk0c = OV008_CTX()->obj->unk0c;
        data_ov016_020b8900.unk0e = 0x7f;
        func_ov016_020ad144(data_ov008_02064f08 + 0x2ce54, &data_ov016_020b8900);
        func_ov088_020c94b4(self, data_ov088_020cd32c, out[0], out[1]);

        if (self->unk30 < 0x10) {
            self->unk34 = self->unk34 + 1;
            if (self->unk34 >= 4) {
                self->unk34 = 0;
                self->unk38 = self->unk38 + 1;
                if (self->unk38 > 3) {
                    self->unk38 = 3;
                }
            }
        } else if (self->unk30 > 0xa) {
            self->unk38 = self->unk38 - 1;
            if (self->unk38 < 0) {
                self->unk38 = 0;
            }
        }
        self->unk30 = 0;
        OV008_CTX()->obj->unk48(2, -1, 0x100, 0);
        if (OV008_CTX()->obj->ec != NULL) {
            func_ov014_020961bc(OV008_CTX()->obj->ec, 1);
        }
    }

entry82:
    if (*(s16*)(data_ov008_02064f08 + 0x2f14e) <= 0) {
        return 0xc8;
    }
    if (OV008_CTX()->unk13c != 0) {
        return 0x6e;
    }
    {
        Unk_ov088_Ec* ec = OV008_CTX()->obj->ec;
        s32 ret = (ec == NULL) ? 1 : func_ov014_02096360(ec);
        if (ret == 0) {
            return 0x82;
        }
    }
    OV008_CTX()->obj->unk48(1, -1, 0x100, 0);

done:
    return 0x64;

entryC8: {
    func_ov120_020d722c(data_ov008_02064f08);
    self->ent->flags |= 0x200;
    Unk_ov088_VBase* vb = (Unk_ov088_VBase*)((u8*)self->fx + ((s32*)self->fx->vtbl)[-3]);
    vb->unk18 = 0;
    vb->unk16 &= ~0x3fff;
    vb->unk10 |= 0x800000;
    vb->unk16 &= ~0x8000;
    vb->unk10 = (vb->unk10 & 0x01ffffff) | 0x02000000;
}
entryD2: {
    {
        u8* g = data_ov008_02064f08;
        Unk_ov088_Ctx* ctx = (Unk_ov088_Ctx*)(g + 0x2f000);
        if (ctx->unk13c != 0) {
            return 0xd2;
        }
        if (*(s16*)(g + 0x2f14e) <= 0) {
            return 0xe6;
        }
        if (ctx->obj->ec->unk20->unk40 != 0xc000007d) {
            OV008_CTX()->obj->unk44(func_ov011_02066c28(g, 0xa002));
        }
    }
    OV008_CTX()->obj->unk48(3, -1, 0x100, 0);
    if (OV008_CTX()->obj->ec != NULL) {
        func_ov014_020961bc(OV008_CTX()->obj->ec, 1);
    }
}

entryDC: {
    {
        Unk_ov088_Ec* ec = OV008_CTX()->obj->ec;
        s32 ret = (ec == NULL) ? 1 : func_ov014_02096360(ec);
        if (ret == 0) {
            return 0xdc;
        }
    }
    if ((s32)OV008_CTX()->obj->ec->unk20 != OV008_CTX()->unk174) {
        func_ov014_02098650(OV008_CTX()->obj, OV008_CTX()->unk174);
        OV008_CTX()->obj->unk44(OV008_CTX()->unk174);
    }
    OV008_CTX()->obj->unk48(0, -1, 0x100, 0);
}

entryE6:
    if (self->unk08 != 0) {
        return 0xe6;
    }

entryFA:
    if (func_ov120_020d53c0(self) != 0) {
        return 0xfa;
    }
    self->unk78 = data_ov088_020cd2e0.unk74;
    self->unk7c = data_ov088_020cd2e0.unk78;
    return 0;

entryDefault:
    return 0;
}
