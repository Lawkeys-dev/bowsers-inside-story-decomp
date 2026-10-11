#include "types.h"

struct Unk_ov129_02075c44 {
    /* 0x000 */ u8 pad000[0x880];
    /* 0x880 */ u8 unk880;
};

extern "C" s32 data_02055fe0;
extern "C" void func_020057ac(s32 a, s32 b);

extern "C" void func_ov129_02075c44(Unk_ov129_02075c44 *p) {
    if (p->unk880 != 0) {
        func_020057ac(data_02055fe0, 0);
    } else {
        func_020057ac(data_02055fe0, 4);
    }
}
