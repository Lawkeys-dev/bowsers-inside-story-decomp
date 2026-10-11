#include "types.h"

struct Unk_ov129_0206dce4_Vtbl {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ void (*unk4)(void* self);
};

struct Unk_ov129_0206dce4_Sub {
    /* 0x0 */ Unk_ov129_0206dce4_Vtbl* vtbl;
};

struct Unk_ov129_0206dce4 {
    /* 0x000 */ void* vtbl;
    /* 0x004 */ u8 unk004[0x24];
    /* 0x028 */ Unk_ov129_0206dce4_Sub* unk28;
    /* 0x02c */ void* unk2c;
    /* 0x030 */ void* unk30;
    /* 0x034 */ u8 unk034[0x7f4];
    /* 0x828 */ void* unk828;
    /* 0x82c */ void* unk82c;
};

extern "C" u8 data_ov129_020760ac[];

extern "C" void func_0201a9a4(void* p);
extern "C" void func_0201a168(void* p);
extern "C" void func_0201a174(void* p);
extern "C" void func_0201a588(void* p);
extern "C" void func_ov127_0206c4a8(void* p);
extern "C" void func_02036330();
extern "C" void func_020363dc();
extern "C" void func_02036168();
extern "C" void func_02036200();
extern "C" void func_0203618c();
extern "C" void func_02036228();
extern "C" void func_02036344();
extern "C" void func_020363f0();
extern "C" void func_020363a0();
extern "C" void func_020363b4();
extern "C" void func_02038374(s32 arg);
extern "C" void func_02038344(s32 arg);

extern "C" Unk_ov129_0206dce4* func_ov129_0206dce4(Unk_ov129_0206dce4* self) {
    self->vtbl = data_ov129_020760ac;
    func_0201a9a4(self->unk82c);
    if (self->unk28 != NULL) {
        self->unk28->vtbl->unk4(self->unk28);
    }
    void* obj = self->unk2c;
    if (obj != NULL) {
        func_ov127_0206c4a8(obj);
        func_0201a168(obj);
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
