#include "types.h"

struct Unk_ov138_02064574 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u8 sbox[0x100];
};

// RC4 key scheduling: identity-fills the 256-byte state table, then mixes in the key.
extern "C" void func_ov138_02064574(Unk_ov138_02064574 *ctx, u8 *key, u32 keyLen) {
    u32 k = 0;
    u32 j = k;
    s32 n = k;
    s32 i;
    u8 tmp;
    u8 kb;

    ctx->unk00 = k;
    ctx->unk04 = k;
    for (; n < 0x100; n++) {
        ctx->sbox[n] = n;
    }

    for (i = 0xff; i >= 0; i--) {
        kb = key[k];
        j = (ctx->sbox[i] + (j + kb)) & 0xff;
        tmp = ctx->sbox[j];
        ctx->sbox[j] = ctx->sbox[i];
        ctx->sbox[i] = tmp;
        k++;
        if (k >= keyLen) {
            k = 0;
        }
    }
}
