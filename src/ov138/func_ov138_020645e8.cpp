#include "types.h"

// RC4-style keystream generator: i and j indices followed by the 256-byte permutation state.

struct Unk_ov138_Rc4 {
    /* 0x00 */ u32 i;
    /* 0x04 */ u32 j;
    /* 0x08 */ u8 s[256];
};

extern "C" u8 func_ov138_020645e8(Unk_ov138_Rc4* rc4) {
    u32 i = (rc4->i + 1) & 0xff;
    u8 si = rc4->s[i];
    u32 j = (si + rc4->j) & 0xff;
    u8 sj = rc4->s[j];
    rc4->i = i;
    rc4->j = j;
    u8 t = (si + sj) & 0xff;
    rc4->s[j] = si;
    rc4->s[i] = sj;
    return rc4->s[t];
}
