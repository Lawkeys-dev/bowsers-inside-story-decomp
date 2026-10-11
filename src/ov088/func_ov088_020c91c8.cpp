#include "types.h"

// Object with a virtual base holding a u32 at 0x1c (cleared by this function).
class Unk_ov088_VBase {
public:
    /* 0x00 */ virtual void unk00();
    /* 0x04 */ u8 pad04[0x18];
    /* 0x1c */ u32 unk1c;
};

class Unk_ov088_Derived : public virtual Unk_ov088_VBase {
};

struct Unk_ov088_020c91c8 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8 pad04[0x08];
    /* 0x0c */ Unk_ov088_Derived *unk0c;
    /* 0x10 */ Unk_ov088_Derived *unk10;
};

extern "C" void func_ov088_020c91c8(Unk_ov088_020c91c8 *self) {
    if (self->unk0c != NULL) {
        self->unk0c->unk1c = 0;
    }
    if (self->unk10 != NULL) {
        self->unk10->unk1c = 0;
    }
}
