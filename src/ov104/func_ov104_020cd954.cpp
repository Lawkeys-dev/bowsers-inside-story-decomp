#include "types.h"

#define HW_REG(addr) (*(volatile u32*)(addr))

extern "C" void func_ov104_020cd954(s32 arg0, u32 arg1) {
    if (arg0 > 0) {
        HW_REG(0x040004A4) = 0x3e000080 | (arg0 << 16);
        HW_REG(0x040004A8) = 0x5edc0000 | (arg1 >> 3);
        HW_REG(0x04000480) = 0x7fff;
        HW_REG(0x04000500) = 3;
        HW_REG(0x04000488) = 0;
        HW_REG(0x0400048C) = 0;
        HW_REG(0x0400048C) = 0;
        HW_REG(0x04000488) = 0xc000000;
        HW_REG(0x0400048C) = 0x18000000;
        HW_REG(0x0400048C) = 0;
        HW_REG(0x04000488) = 0x1000;
        HW_REG(0x0400048C) = 0x2000;
        HW_REG(0x0400048C) = 0;
        HW_REG(0x04000488) = 0x0c001000;
        HW_REG(0x0400048C) = 0x18002000;
        HW_REG(0x0400048C) = 0;
        HW_REG(0x04000504) = 0;
    }
}
