#include "types.h"

struct Unk_ov088_elem;
struct Unk_ov088;

typedef s16 (Unk_ov088::*Unk_ov088_pmf)(Unk_ov088_elem* elem);

/* 0x20 bytes, stored at Unk_ov088 + 0x80 + index * 0x20 */
struct Unk_ov088_elem {
    /* 0x00 */ s16 result;
    /* 0x02 */ u8 unk02[0x2];
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0c */ u8 unk0c[0x8];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ Unk_ov088_pmf pmf;
};

struct Unk_ov088 {
    /* 0x00 */ u8 unk00[0x8];
    /* 0x08 */ u16 count;
    /* 0x0a */ u8 unk0a[0x76];
    /* 0x80 */ Unk_ov088_elem elems[20];
};

extern "C" Unk_ov088_pmf data_0204ffe0;

extern "C" s32 func_ov088_020c94b4(Unk_ov088* self, Unk_ov088_pmf pmf, u32 c, u32 d) {
    s32 i;
    for (i = 0; i < 20; i++) {
        if (self->elems[i].pmf == 0) {
            self->elems[i].pmf = pmf;
            self->elems[i].unk14 = 0;
            self->elems[i].result = 0;
            self->elems[i].unk04 = c;
            self->elems[i].unk08 = d;
            self->count++;
            self->elems[i].result = (self->*(self->elems[i].pmf))(&self->elems[i]);
            if (self->elems[i].result == -1) {
                self->elems[i].pmf = data_0204ffe0;
                self->count--;
            }
            return i;
        }
    }
    return i;
}
