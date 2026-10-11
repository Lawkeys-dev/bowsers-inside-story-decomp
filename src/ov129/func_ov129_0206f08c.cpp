#include "types.h"

struct Unk_ov129_0206f08c;

extern "C" void func_0200e964(void *p);
extern "C" void func_0201a168(void *p);
extern "C" void func_ov127_0206c4a8(void *p);
extern "C" void func_ov129_0206de4c(Unk_ov129_0206f08c *self);
extern "C" u8 data_ov129_020763a4[];
extern "C" u32 data_ov129_02076334[];

struct Unk_ov129_0206f08c {
    /* 0x000 */ void *vtable;
    /* 0x004 */ u8 pad004[0x84c - 0x004];
    /* 0x84c */ void *unk84c;
    /* 0x850 */ void *unk850;
    /* 0x854 */ void *unk854;
    /* 0x858 */ void *unk858;
    /* 0x85c */ u8 pad85c[0x860 - 0x85c];
    /* 0x860 */ void *unk860;
    /* 0x864 */ u8 pad864[0x868 - 0x864];
    /* 0x868 */ void *unk868;
    /* 0x86c */ u8 pad86c[0x870 - 0x86c];
    /* 0x870 */ void *unk870;
    /* 0x874 */ void *unk874;
};

extern "C" Unk_ov129_0206f08c *func_ov129_0206f08c(Unk_ov129_0206f08c *self) {
    void *p;
    self->vtable = data_ov129_02076334;
    data_ov129_020763a4[0] = 0;
    p = self->unk874;
    if (p != NULL) {
        func_0200e964(p);
        func_0201a168(p);
    }
    func_0201a168(self->unk850);
    func_0201a168(self->unk858);
    func_0201a168(self->unk860);
    func_0201a168(self->unk868);
    func_0201a168(self->unk870);
    p = self->unk84c;
    if (p != NULL) {
        func_ov127_0206c4a8(p);
        func_0201a168(p);
    }
    p = self->unk854;
    if (p != NULL) {
        func_ov127_0206c4a8(p);
        func_0201a168(p);
    }
    func_ov129_0206de4c(self);
    return self;
}
