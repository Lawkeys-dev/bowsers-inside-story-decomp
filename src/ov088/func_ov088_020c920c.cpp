#include "types.h"

struct Unk_ov088_Obj;

// Member function pointers as stored in the object (ARM ABI: ptr + adj, adj bit 0 = virtual).
typedef u32 (Unk_ov088_Obj::*Unk_ov088_Fn0)();
typedef s16 (Unk_ov088_Obj::*Unk_ov088_Fn1)(struct Unk_ov088_Entry*);

struct Unk_ov088_Entry {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ u8 unk02[0x16];
    /* 0x18 */ Unk_ov088_Fn1 fn;
};

struct Unk_ov088_Obj {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u16 unk08;
    /* 0x0a */ u8 unk0a[0x78 - 0x0a];
    /* 0x78 */ Unk_ov088_Fn0 fn78;
    /* 0x80 */ Unk_ov088_Entry entries[0x14];
};

extern "C" Unk_ov088_Fn0 data_0204ffe0;

extern "C" void func_ov088_020c9724(Unk_ov088_Obj* self);

// TODO: register allocation still differs: ret lands in r7 (original r6), the entry pointer in r8 and the fn walker is not hoisted (original r7 = &entries[i].fn), default global not hoisted into r11.
extern "C" BOOL func_ov088_020c920c(Unk_ov088_Obj* self) {
    BOOL ret = TRUE;

    if (self->fn78 != 0) {
        Unk_ov088_Fn0 old = self->fn78;
        self->unk04 = (self->*self->fn78)();
        if (self->fn78 != 0 && self->fn78 != old) {
            self->unk04 = (self->*self->fn78)();
        }
        if (self->unk04 == 0xffffffff) {
            ret = FALSE;
            self->fn78 = data_0204ffe0;
        } else {
            func_ov088_020c9724(self);
        }
    } else {
        ret = FALSE;
    }

    for (s32 i = 0; i < 0x14; i++) {
        if (self->entries[i].fn != 0) {
            Unk_ov088_Fn1 old = self->entries[i].fn;
            Unk_ov088_Entry* e = &self->entries[i];
            self->entries[i].unk00 = (self->*e->fn)(e);
            if (e->fn != old) {
                self->entries[i].unk00 = (self->*e->fn)(e);
            }
            if (self->entries[i].unk00 != -1) {
                ret = TRUE;
            } else {
                self->entries[i].fn = (Unk_ov088_Fn1)data_0204ffe0;
                self->unk08--;
            }
        }
    }
    return ret;
}
