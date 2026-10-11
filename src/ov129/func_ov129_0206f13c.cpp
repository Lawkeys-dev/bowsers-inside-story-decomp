#include "types.h"

struct Unk_ov129_0206f13c {
    /* 0x000 */ void* vtable;
    /* 0x004 */ u8 unk004[0x848];
    /* 0x84c */ void* unk84c;
    /* 0x850 */ void* unk850;
    /* 0x854 */ void* unk854;
    /* 0x858 */ void* unk858;
    /* 0x85c */ u32 unk85c;
    /* 0x860 */ void* unk860;
    /* 0x864 */ u32 unk864;
    /* 0x868 */ void* unk868;
    /* 0x86c */ u32 unk86c;
    /* 0x870 */ void* unk870;
    /* 0x874 */ void* unk874;
};

extern "C" u8 data_ov129_02076334[];
extern "C" u8 data_ov129_020763a4;

extern "C" void func_0200e964(void* p);
extern "C" void func_0201a168(void* p);
extern "C" void func_ov127_0206c4a8(void* p);
extern "C" void func_ov129_0206de4c(Unk_ov129_0206f13c* self);

extern "C" Unk_ov129_0206f13c* func_ov129_0206f13c(Unk_ov129_0206f13c* self) {
    void* ptr;

    self->vtable = data_ov129_02076334;
    data_ov129_020763a4 = 0;
    ptr = self->unk874;
    if (ptr != NULL) {
        func_0200e964(ptr);
        func_0201a168(ptr);
    }
    func_0201a168(self->unk850);
    func_0201a168(self->unk858);
    func_0201a168(self->unk860);
    func_0201a168(self->unk868);
    func_0201a168(self->unk870);
    ptr = self->unk84c;
    if (ptr != NULL) {
        func_ov127_0206c4a8(ptr);
        func_0201a168(ptr);
    }
    ptr = self->unk854;
    if (ptr != NULL) {
        func_ov127_0206c4a8(ptr);
        func_0201a168(ptr);
    }
    func_ov129_0206de4c(self);
    func_0201a168(self);
    return self;
}
