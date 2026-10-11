#include "types.h"

struct Unk_ov088_020caefc {
    /* 0x00 */ u8 pad00[0x1c];
    /* 0x1c */ u16 unk1c;
    /* 0x1e */ s16 unk1e;
    /* 0x20 */ u8 pad20[2];
    /* 0x22 */ s16 unk22;
};

extern "C" u32 data_ov088_020cd2e0[];
extern "C" u32 data_ov088_020cd304[];
extern "C" u32 data_ov088_020cd31c[];
extern "C" u32 data_ov088_020cd36c[];
extern "C" u32 data_ov088_020cd378[];
extern "C" u32 data_ov088_020cd388[];
extern "C" u32 data_ov088_020cd398[];
extern "C" u32 data_ov088_020cd3a8[];
extern "C" u32 data_ov088_020cd3bc[];
extern "C" u32 data_ov088_020cd3d0[];
extern "C" u32 data_ov088_020cd3e4[];
extern "C" u32 data_ov088_020cd3fc[];

extern "C" void* func_ov088_020caefc(Unk_ov088_020caefc* obj) {
    switch (obj->unk1c) {
    case 1:
        switch (obj->unk1e) {
        case 0:
            return (u32)obj->unk22 >= 4 ? NULL : &data_ov088_020cd378[obj->unk22];
        case 1:
            return (u32)obj->unk22 >= 4 ? NULL : &data_ov088_020cd388[obj->unk22];
        case 2:
            return (u32)obj->unk22 >= 2 ? NULL : &data_ov088_020cd31c[obj->unk22];
        case 3:
            return (u32)obj->unk22 >= 2 ? NULL : &data_ov088_020cd304[obj->unk22];
        }
        break;
    case 2:
        switch (obj->unk1e) {
        case 0:
            return (u32)obj->unk22 >= 3 ? NULL : &data_ov088_020cd36c[obj->unk22];
        case 1:
            return (u32)obj->unk22 >= 4 ? NULL : &data_ov088_020cd398[obj->unk22];
        case 2:
            return (u32)obj->unk22 >= 6 ? NULL : &data_ov088_020cd3e4[obj->unk22];
        case 3:
            return (u32)obj->unk22 >= 1 ? NULL : &data_ov088_020cd2e0[obj->unk22];
        }
        break;
    default:
        switch (obj->unk1e) {
        case 0:
            return (u32)obj->unk22 >= 6 ? NULL : &data_ov088_020cd3fc[obj->unk22];
        case 1:
            return (u32)obj->unk22 >= 5 ? NULL : &data_ov088_020cd3a8[obj->unk22];
        case 2:
            return (u32)obj->unk22 >= 5 ? NULL : &data_ov088_020cd3bc[obj->unk22];
        case 3:
            return (u32)obj->unk22 >= 5 ? NULL : &data_ov088_020cd3d0[obj->unk22];
        }
        break;
    }
    return NULL;
}
