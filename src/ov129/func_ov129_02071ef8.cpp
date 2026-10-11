#include "types.h"

struct Unk_ov129_02071ef8 {
    /* 0x000 */ void* vtable;
    /* 0x004 */ u8 pad004[0x830 - 0x004];
    /* 0x830 */ void* unk830;
    /* 0x834 */ void* unk834;
    /* 0x838 */ void* unk838;
    /* 0x83c */ u8 pad83c[0x840 - 0x83c];
    /* 0x840 */ void* unk840;
    /* 0x844 */ void* unk844;
    /* 0x848 */ void* unk848;
    /* 0x84c */ u8 pad84c[0x868 - 0x84c];
    /* 0x868 */ void* unk868;
    /* 0x86c */ void* unk86c;
    /* 0x870 */ u8 pad870[0x884 - 0x870];
    /* 0x884 */ void* unk884;
};

struct Unk_ov129_Io {
    /* 0x000 */ u32 unk000[4];
    /* 0x010 */ u8 pad010[0x1000 - 0x010];
    /* 0x1000 */ u32 unk1000;
};

extern "C" void func_020068c4();
extern "C" void func_0200e964(void* p);
extern "C" void func_0201a168(void* p);
extern "C" void func_0201a174(void* p);
extern "C" void func_ov127_0206c4a8(void* p);
extern "C" void func_ov129_0206de4c(Unk_ov129_02071ef8* p);
extern "C" u8 data_ov129_02076370[];

// TODO: 98.33%. The IO base (0x4000010) and the zero constant get swapped between r0 and r1/r2 (original keeps the vtable pointer in r2, IO base in r1, zero in r0). Volatile pointers and a zero local made it worse.
extern "C" Unk_ov129_02071ef8* func_ov129_02071ef8(Unk_ov129_02071ef8* self) {
    Unk_ov129_Io* io;
    u32* reg2;
    void* tmp;

    io = (Unk_ov129_Io*)0x04000010;
    self->vtable = data_ov129_02076370;
    io->unk000[0] = 0;
    io->unk000[1] = 0;
    io->unk000[2] = 0;
    io->unk000[3] = 0;
    io->unk1000 = 0;
    reg2 = (u32*)0x04001014;
    reg2[0] = 0;
    reg2[1] = 0;
    reg2[2] = 0;
    func_020068c4();
    tmp = self->unk884;
    if (tmp != NULL) {
        func_0200e964(tmp);
        func_0201a168(tmp);
    }
    func_0201a174(self->unk830);
    func_0201a174(self->unk834);
    func_0201a174(self->unk838);
    func_0201a174(self->unk840);
    func_0201a174(self->unk844);
    func_0201a174(self->unk848);
    tmp = self->unk868;
    if (tmp != NULL) {
        func_ov127_0206c4a8(tmp);
        func_0201a168(tmp);
    }
    tmp = self->unk86c;
    if (tmp != NULL) {
        func_ov127_0206c4a8(tmp);
        func_0201a168(tmp);
    }
    func_ov129_0206de4c(self);
    return self;
}
