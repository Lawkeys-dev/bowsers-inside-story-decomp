#include "types.h"

struct Vec32 {
    s32 x;
    s32 y;
    s32 z;
};

// Placeholder until the owning class is identified
struct Unk_ov118_Entry {
    /* 0x00 */ Vec32 pos;
    /* 0x0c */ Vec32 prevPos;
    /* 0x18 */ s32 unk18;
};

struct Unk_ov118_020ebda8 {
    /* 0x00 */ u8 unk0[0xf4];
    /* 0xf4 */ Unk_ov118_Entry* entries;
    /* 0xf8 */ s8 count;
    /* 0xf9 */ s8 unkf9;
    /* 0xfa */ s8 spacing;
};

// Stacks the entries vertically below the given position
extern "C" void func_ov118_020ebda8(Unk_ov118_020ebda8* self, Vec32* pos) {
    Unk_ov118_Entry* entry = self->entries;
    for (s32 i = 0; i < self->count; i++, entry++) {
        entry->pos.x = entry->prevPos.x = pos->x;
        entry->pos.y = entry->prevPos.y = pos->y;
        entry->pos.z = entry->prevPos.z = pos->z - ((i * self->spacing) << 8);
    }
}
