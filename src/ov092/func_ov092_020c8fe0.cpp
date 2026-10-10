#include "types.h"

struct Unk_ov092_Entry {
    /* 0x00 */ u8 unk00[0x3c];
    /* 0x3c */ u32 flags;
};

extern "C" void* func_01ff8228(void* dst, s32 value, u32 size);

struct Unk_ov092_Entry;
struct Unk_ov092_Counter {
    /* 0x00 */ u32 unk0[2];
    /* 0x08 */ u32 count;

    void Add(Unk_ov092_Entry* e);
    BOOL IsEmpty() const {
        return count == 0;
    }
    void Clear() {
        func_01ff8228(this, 0, 0xc);
    }
};

struct Unk_ov092_Self {
    /* 0x00 */ u8 unk00[0x54];
    /* 0x54 */ void* unk54;
};

inline void Unk_ov092_Counter::Add(Unk_ov092_Entry* e) {
    if (e != NULL) {
        if (((e->flags << 22) >> 31) == 0) {
            count++;
        }
    }
}

extern "C" Unk_ov092_Counter data_ov092_020c9420;
extern "C" u32 data_ov008_02064f08;

extern "C" u32 func_ov011_02066c28(u32 heap, u32 arg);
extern "C" Unk_ov092_Entry* func_ov011_02066dac(u32 heap, u16 id);
extern "C" void func_ov013_0208eb04(u32 a0, u32 a1, u32 a2, u32 a3, s32 a4);
extern "C" void func_ov092_020c90ac(void);

// TODO: 97.84%. All instructions match; the literal pool differs: the original has data_ov092_020c9420 twice (memset
// target, then the loop/final check) while the compiler merges them into one entry.
// Writing `extern "C" Unk_ov092_Counter data_ov092_020c9420 = {};` (a definition in this TU) gives 100.00% MATCH. The
// whole module is one TU (delinks: .text/.init/.ctor/.bss in a single entry, with a static initializer in .init/.ctor), so
// the original source most likely DEFINES this global: it needs the module .bss to be delinked into this TU to link.
extern "C" void func_ov092_020c8fe0(Unk_ov092_Self* self) {
    data_ov092_020c9420.Clear();
    u32 heap = func_ov011_02066c28(data_ov008_02064f08, 0xa013);
    func_ov013_0208eb04(heap, 0xc10000d5, 1, 0, -1);
    for (s32 i = 0x4000; i <= 0x4003; i++) {
        data_ov092_020c9420.Add(func_ov011_02066dac(data_ov008_02064f08, (u16)i));
    }
    if (data_ov092_020c9420.count == 0) {
        self->unk54 = NULL;
    } else {
        self->unk54 = (void*)func_ov092_020c90ac;
    }
}
