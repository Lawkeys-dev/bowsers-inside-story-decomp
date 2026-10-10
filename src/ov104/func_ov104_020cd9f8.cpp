#include "types.h"

typedef volatile u32 vu32_ov104;

extern "C" void func_ov104_020cd9f8(s32 arg) {
    if (arg > 0) {
        *(vu32_ov104*)0x040004a4 = 0x3f000080 | (arg << 16);
        *(vu32_ov104*)0x040004a8 = 0;
        *(vu32_ov104*)0x04000480 = 0;
        *(vu32_ov104*)0x04000500 = 3;
        vu32_ov104* fifo = (vu32_ov104*)0x0400048c;
        *fifo = 0;
        *fifo = 2;
        *fifo = 0x18000000;
        *fifo = 2;
        *fifo = 0x2000;
        *fifo = 2;
        *fifo = 0x2000 - 0xe8000000;
        *fifo = 2;
        *(vu32_ov104*)0x04000504 = 0;
    }
}
