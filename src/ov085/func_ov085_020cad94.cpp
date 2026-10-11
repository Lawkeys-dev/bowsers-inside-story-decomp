#include "types.h"

// Vtable slots 0x00-0x44 are unknown placeholders, only slot 0x48 is called here.
class Unk_ov085_020cad94_obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    /* 0x48 */ virtual void vf18(s32 a, s32 b, s32 c, s32 d);

    /* 0x04 */ u8 pad04[0xf0 - 0x04];
    /* 0xf0 */ s32 unkF0;
};

struct Unk_ov085_020cad94 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk_ov085_020cad94_obj* unk08;
};

// TODO: register allocation differs: the original computes the masked field (val & ~0xfff) into r3
// and the masked sum into r1, leaving r12 free. mwcc computes the field into r12 (reusing val's
// register) and the sum into r3, then orr r3, r12, r3. The vtable call now matches (virtual
// vf18 slot 0x48). Ordering, signedness and temporaries variants tried so far do not change this.
extern "C" void func_ov085_020cad94(Unk_ov085_020cad94* self) {
    Unk_ov085_020cad94_obj* obj = self->unk08;
    u32 val = obj->unkF0;
    u32 keep = val & 0xfffff000;
    s32 lo = (s32)(val << 20) >> 20;
    s32 hi = (s32)(val << 8) >> 20;
    s32 sum = lo + hi;
    u32 low = sum & 0xfff;
    obj->unkF0 = (keep | low) & 0xff000fff;
    obj->vf18(0, -1, 0x100, 0);
    self->unk00 = 0;
}
