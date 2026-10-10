#include "types.h"

struct Unk_ov104_020cda80 {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u32 unk4;
};

struct Unk_ov019_020cd524 {
    /* 0x0 */ u8 unk0[0xc];
    /* 0xc */ u32 unkC;
};

extern "C" Unk_ov104_020cda80 data_ov104_020cda80;
extern "C" Unk_ov019_020cd524 data_ov019_020cd524;

extern "C" void func_ov104_020cd9f8(s32 value);
extern "C" void func_ov104_020cd954(s32 a, u32 b);

extern "C" void func_ov104_020cd834(s32 state) {
    switch (state) {
    case 0:
        data_ov104_020cda80.unk4 = 0x28000;
        data_ov104_020cda80.unk0 = 0x1f;
        data_ov104_020cda80.unk2 = 0x1f;
        break;
    case 1:
        if (data_ov104_020cda80.unk0 > 0) {
            data_ov104_020cda80.unk0--;
        }
        break;
    case 2:
        if (data_ov104_020cda80.unk0 > 0) {
            data_ov104_020cda80.unk0--;
        }
        break;
    case 3:
        data_ov104_020cda80.unk4 = 0x48000;
        if (data_ov104_020cda80.unk0 > 0) {
            data_ov104_020cda80.unk0--;
        }
        if (data_ov104_020cda80.unk2 > 0) {
            data_ov104_020cda80.unk2--;
        }
        *(volatile u16*)0x04000304 &= ~0x8000;
        break;
    case 4:
        if (data_ov104_020cda80.unk0 > 0) {
            data_ov104_020cda80.unk0--;
        }
        if (data_ov104_020cda80.unk2 > 0) {
            data_ov104_020cda80.unk2--;
        }
        if (data_ov104_020cda80.unk2 == 0) {
            data_ov019_020cd524.unkC = 0;
        }
        break;
    }

    func_ov104_020cd9f8(data_ov104_020cda80.unk2);
    func_ov104_020cd954(data_ov104_020cda80.unk0, data_ov104_020cda80.unk4);
}
