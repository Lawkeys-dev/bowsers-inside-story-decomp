#include "types.h"

struct Unk_ov129_0206de4c_Sub {
    /* 0x00 */ void *vtbl;
};

struct Unk_ov129_0206de4c {
    /* 0x00 */ void *vtbl;
    /* 0x04 */ u8 unk04[0x28 - 0x04];
    /* 0x28 */ Unk_ov129_0206de4c_Sub *unk28;
    /* 0x2c */ void *unk2c;
    /* 0x30 */ void *unk30;
    /* 0x34 */ u8 unk34[0x828 - 0x34];
    /* 0x828 */ void *unk828;
    /* 0x82c */ void *unk82c;
};

extern "C" void func_0201a9a4(void *);
extern "C" void func_0201a168(void *);
extern "C" void func_0201a174(void *);
extern "C" void func_0201a588(void *);
extern "C" void func_ov127_0206c4a8(void *);
extern "C" void func_02036168();
extern "C" void func_0203618c();
extern "C" void func_02036200();
extern "C" void func_02036228();
extern "C" void func_02036330();
extern "C" void func_02036344();
extern "C" void func_020363a0();
extern "C" void func_020363b4();
extern "C" void func_020363dc();
extern "C" void func_020363f0();
extern "C" void func_02038344(s32);
extern "C" void func_02038374(s32);
extern "C" u8 data_ov129_020760ac[];

extern "C" Unk_ov129_0206de4c *func_ov129_0206de4c(Unk_ov129_0206de4c *self) {
    self->vtbl = data_ov129_020760ac;
    func_0201a9a4(self->unk82c);
    if (self->unk28 != NULL) {
        typedef void (*VFunc)(void *);
        VFunc f = (VFunc)((void **)self->unk28->vtbl)[1];
        f(self->unk28);
    }
    void *tmp = self->unk2c;
    if (tmp != NULL) {
        func_ov127_0206c4a8(tmp);
        func_0201a168(tmp);
    }
    if (self->unk30 != NULL) {
        func_0201a174(self->unk30);
    }
    func_0201a168(self->unk828);
    func_02036330();
    func_020363dc();
    func_02036168();
    func_02036200();
    func_0203618c();
    func_02036228();
    func_02036344();
    func_020363f0();
    func_020363a0();
    func_020363b4();
    func_02038374(1);
    func_02038344(4);
    func_0201a588(self);
    return self;
}
