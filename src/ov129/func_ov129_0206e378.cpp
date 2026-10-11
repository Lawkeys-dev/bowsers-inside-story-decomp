#include "types.h"

extern "C" void func_0201a69c(void *self);
extern "C" void *data_ov129_02076038[];

extern "C" void *func_ov129_0206e378(void *self) {
    func_0201a69c(self);
    *(void **)self = data_ov129_02076038;
    return self;
}
