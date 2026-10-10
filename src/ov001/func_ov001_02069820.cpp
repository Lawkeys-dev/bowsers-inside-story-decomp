#include "types.h"

struct Unk_ov001_01ff93c8 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[0x68 - 0x04];
    /* 0x68 */ u32 unk68;
    /* 0x6c */ u32 unk6c;
};

struct Unk_ov001_Time {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
};

extern "C" Unk_ov001_01ff93c8 data_01ff93c8;
extern "C" u8 data_01ff93cc[];
extern "C" u8 data_01ff93d4[];
extern "C" u8 data_01ff9428[];
extern "C" u8 data_01ff93c0;
extern "C" s32 data_02055fe0;
extern "C" u8 data_02056504[];

extern "C" void func_0201e90c(void);
extern "C" void func_02038374(s32 arg);
extern "C" void func_02038344(s32 arg);
extern "C" void func_ov001_02069bf8(void* arg);
extern "C" void func_ov001_02069cf8(void);
extern "C" void func_02041a2c(u32 a, u32 b);
extern "C" s32 func_0201a150(s32 a, s32 b, s32 c, s32 d);
extern "C" void func_0201b2e4(s32 a, s32 b);
extern "C" void func_0203f25c(void);
extern "C" s32 func_0203f2d4(void* arg);
extern "C" void func_0203f368(void* arg);
extern "C" void func_02039f14(void* arg);
extern "C" void func_02039ef8(void* arg);
extern "C" u64 func_02039f98(void);
extern "C" void func_02040f6c(Unk_ov001_Time* time);
extern "C" void func_0201cf1c(s32 arg);
extern "C" void func_02039b24(void);
extern "C" void func_02039c24(s32 arg, s32 zero);
extern "C" void func_ov001_02069ac8(void);
extern "C" void func_02005fe4(s32 a, u32 b, u32 c, u32 d);
extern "C" void func_0200b57c(void);
extern "C" s32 func_0201a138(s32 a, u32 b, s32 c, s32 d);
extern "C" s32 func_ov001_02069cb8(void);

extern "C" void func_ov001_02069820(s32 arg) {
    Unk_ov001_Time time;
    func_0201e90c();
    func_02038374(1);
    func_02038344(4);
    func_ov001_02069bf8(data_02056504);
    func_ov001_02069cf8();
    func_02041a2c(0x500, 0x2400);
    s32 x = func_0201a150(arg, 5, 0, 0);
    func_0201b2e4(x, arg);
    func_0203f25c();
    data_01ff93c8.unk0 = func_0203f2d4(data_01ff93cc);
    if (data_01ff93c8.unk0 != 0) {
        func_0203f368(data_01ff93cc);
    }
    func_02039f14(data_01ff93d4);
    func_02039ef8(data_01ff9428);
    u64 val = func_02039f98();
    data_01ff93c8.unk68 = (u32)val;
    data_01ff93c8.unk6c = (u32)(val >> 32);
    func_02040f6c(&time);
    func_0201cf1c(time.unk8 + ((time.unk0 << 16) + (time.unk4 << 8)));
    func_02039b24();
    func_02039c24(time.unk8 + (time.unk4 * 60 + time.unk0 * 3600), 0);
    func_ov001_02069ac8();
    func_02005fe4(0, 0xa0000, 0x2bc00, 0x2bc00);
    func_0200b57c();
    data_01ff93c0 = 1;
    s32 ret = func_0201a138(0x2c, 1, 0, 0);
    if (ret != 0) {
        ret = func_ov001_02069cb8();
    }
    data_02055fe0 = ret;
}
