#include "types.h"

struct Unk_ov129_0206df28_828 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
};

// Vtable at offset 0x00 (virtual methods, slots 0x00..0x10).
struct Unk_ov129_0206df28 {
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();

    /* 0x004 */ u8 pad004[0x28 - 0x4];
    /* 0x028 */ void *unk28;
    /* 0x02c */ u8 pad02c[0x34 - 0x2c];
    /* 0x034 */ u32 unk34;
    /* 0x038 */ u8 pad038[0x825 - 0x38];
    /* 0x825 */ u8 unk825;
    /* 0x826 */ u8 pad826[0x828 - 0x826];
    /* 0x828 */ Unk_ov129_0206df28_828 *unk828;
};

extern "C" u32 func_ov127_0206ae3c(void *obj, u32 arg);
extern "C" void func_ov127_0206af34(void *obj, u32 arg);
extern "C" void func_02019b2c(void);

extern "C" void func_ov129_0206df28(Unk_ov129_0206df28 *self) {
    if (self->unk825 != 0) {
        if (func_ov127_0206ae3c(self->unk28, 0) == 0) {
            if (func_ov127_0206ae3c(self->unk28, 1) == 0) {
                BOOL busy;
                if (self->unk828->unk00 != 0 || self->unk828->unk04 != 0) {
                    busy = TRUE;
                } else {
                    busy = FALSE;
                }
                if (busy == 0) {
                    self->vfunc10();
                    if (self != NULL) {
                        self->vfunc04();
                    }
                    return;
                }
            }
        }
    }

    func_ov127_0206af34(self->unk28, 1);
    self->unk34 = self->unk34 + 1;
    func_02019b2c();
}
