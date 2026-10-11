#include "types.h"

struct Unk_ov129_02070f78 {
    /* 0x000 */ u8 unk000[0x836];
    /* 0x836 */ u8 unk836;
};

extern "C" u32 data_02055fe0;
extern "C" u32 data_02056504;

extern "C" void func_02005da0(u32 *p, u32 flags);
extern "C" void func_020057ac(u32 p, u32 flags);

extern "C" void func_ov129_02070f78(Unk_ov129_02070f78 *p) {
    if (p->unk836 != 0) {
        func_02005da0(&data_02056504, 0);
        data_02056504 |= 2;
    } else {
        func_020057ac(data_02055fe0, 0);
    }
}
