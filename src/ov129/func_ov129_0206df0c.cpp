#include "types.h"

extern "C" void func_ov127_0206af4c(void *param);
extern "C" void func_ov129_0206db20(void *param);
extern "C" u8 data_ov129_02076008[];

extern "C" void func_ov129_0206df0c(u8 *self) {
    func_ov127_0206af4c(*(void **)(self + 0x28));
    func_ov129_0206db20(data_ov129_02076008);
}
