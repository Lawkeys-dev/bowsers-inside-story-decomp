#include "types.h"

extern "C" u8 data_02058f84[];

extern "C" void func_01ff8228(void *dst, s32 value, u32 size);
extern "C" void func_02017758(s32 arg);
extern "C" s32 func_0201793c(s32 arg, void *dst, u32 size);
extern "C" s32 func_02017b0c(void);

extern "C" s32 func_ov001_02069cf8() {
    func_01ff8228(data_02058f84, 0, 0x2000);
    func_02017758(1);
    if (func_0201793c(0, data_02058f84, 0x2000) == 0) {
        return 0;
    }
    return func_02017b0c();
}
