#include "types.h"

struct Unk_ov129_02074a5c {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ void *unk28;
};

// Virtual interface: slot N sits at vtable offset N * 4, so v28 is at 0x70.
struct Unk_ov129_02074a5c_Obj {
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28(u8 value) = 0;
};

struct Unk_ov129_02074a5c_Entry {
    /* 0x00 */ u8 pad00[0x54];
    /* 0x54 */ u8 obj54[4]; // Unk_ov129_02074a5c_Obj sub-object (vtable pointer first)
};

struct Unk_ov129_02074a5c_Last {
    /* 0x00 */ u8 pad00[0x86];
    /* 0x86 */ u8 unk86;
};

extern "C" void *func_ov127_0206a30c(void *obj, s32 index);

extern "C" void func_ov129_02074a5c(Unk_ov129_02074a5c *self, u16 first, u8 value) {
    u16 end = first + 0x2e;
    s32 i = (u16)(first + 0x12) + 1;
    if (i < end) {
        do {
            Unk_ov129_02074a5c_Entry *entry = (Unk_ov129_02074a5c_Entry *)func_ov127_0206a30c(self->unk28, i);
            if (entry != NULL) {
                Unk_ov129_02074a5c_Obj *obj = (Unk_ov129_02074a5c_Obj *)entry->obj54;
                obj->v28(value);
            }
            i++;
        } while (i < end);
    }
    Unk_ov129_02074a5c_Last *last = (Unk_ov129_02074a5c_Last *)func_ov127_0206a30c(self->unk28, end);
    last->unk86 = value;
}
