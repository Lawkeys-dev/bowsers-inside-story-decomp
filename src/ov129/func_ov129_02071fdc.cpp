#include "types.h"

struct Unk_ov129_02071fdc {
    /* 0x000 */ void *vtable;
    /* 0x004 */ u8 unk004[0x830 - 0x004];
    /* 0x830 */ void *unk830;
    /* 0x834 */ void *unk834;
    /* 0x838 */ void *unk838;
    /* 0x83c */ u32 unk83c;
    /* 0x840 */ void *unk840;
    /* 0x844 */ void *unk844;
    /* 0x848 */ void *unk848;
    /* 0x84c */ u8 unk84c[0x868 - 0x84c];
    /* 0x868 */ void *unk868;
    /* 0x86c */ void *unk86c;
    /* 0x870 */ u8 unk870[0x884 - 0x870];
    /* 0x884 */ void *unk884;
};

extern "C" void func_020068c4();
extern "C" void func_0200e964(void *p);
extern "C" void func_0201a168(void *p);
extern "C" void func_0201a174(void *p);
extern "C" void func_ov127_0206c4a8(void *p);
extern "C" void func_ov129_0206de4c(Unk_ov129_02071fdc *p);

extern "C" u8 data_ov129_02076370[];

// TODO: register allocation differs slightly: the original keeps the vtable address in r2 and the
// hardware register base 0x04000010 in r1 (zero in r0); the compiled code uses r1/r0/r2 in the
// other order. Tried (all stay at 98.39%): zero local (first or last), literal zeros, volatile
// pointers, vtable through a local or a u32 cast, pointer declarations before/after the vtable store,
// struct for the IO block, chained zero assignment, vtable store moved between IO stores.
extern "C" Unk_ov129_02071fdc *func_ov129_02071fdc(Unk_ov129_02071fdc *self) {
    u32 *reg = (u32 *)0x04000010;
    u32 *reg2 = (u32 *)0x04001014;

    self->vtable = data_ov129_02076370;
    reg[0] = 0;
    reg[1] = 0;
    reg[2] = 0;
    reg[3] = 0;
    reg[0x400] = 0;
    reg2[0] = 0;
    reg2[1] = 0;
    reg2[2] = 0;
    func_020068c4();
    void *p = self->unk884;
    if (p != NULL) {
        func_0200e964(p);
        func_0201a168(p);
    }
    func_0201a174(self->unk830);
    func_0201a174(self->unk834);
    func_0201a174(self->unk838);
    func_0201a174(self->unk840);
    func_0201a174(self->unk844);
    func_0201a174(self->unk848);
    p = self->unk868;
    if (p != NULL) {
        func_ov127_0206c4a8(p);
        func_0201a168(p);
    }
    p = self->unk86c;
    if (p != NULL) {
        func_ov127_0206c4a8(p);
        func_0201a168(p);
    }
    func_ov129_0206de4c(self);
    func_0201a168(self);
    return self;
}
