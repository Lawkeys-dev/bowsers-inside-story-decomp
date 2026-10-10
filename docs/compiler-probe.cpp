// Functions decompiled to identify the compiler (see docs/compiler.md).
// Run: ./dev.sh python tools/probe_compilers.py docs/compiler-probe.cpp
//
// They are declared extern "C" and use placeholder structs so that they can be compared with the original
// code without being part of the build. Match percentages are for CodeWarrior 2.0/sp1p5.

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

// 100%
struct S1 {
    char pad0[4];
    s8 f4;
    s8 f5;
    char pad6[2];
    u8 f8;
    u8 f9;
};

extern "C" int func_ov122_0206d978(S1* s) {
    if (s->f4 != 0) {
        u8 m = s->f9;
        if (s->f8 <= m) {
            m = s->f8;
        }
        if (s->f5 >= m) {
            return 1;
        }
    }
    return 0;
}

// 100% with 2.0 only (1.2: 72-75%, DSi: 78%)
extern "C" int func_ov124_02078574(u8* buf, int stride, int unused, int x, int y, int w, int h) {
    int count = 0;
    for (int yy = y; yy < y + h; yy++) {
        for (int xx = x; xx < x + w; xx++) {
            if (buf[yy * stride + xx] != 0) {
                count++;
            }
        }
    }
    return count;
}

// 100% with 2.0 and DSi (1.2: 44-53%)
struct Vec {
    s32 x, y, z;
};

struct E {
    Vec cur;
    Vec prev;
    s32 pad18;
};

struct S5 {
    char pad0[0xf4];
    E* e;
    s8 count;
    s8 pad9;
    s8 spacing;
};

extern "C" void func_ov118_020ebda8(S5* s, Vec* pos) {
    E* e = s->e;
    for (int i = 0; i < s->count; i++, e++) {
        e->cur.x = e->prev.x = pos->x;
        e->cur.y = e->prev.y = pos->y;
        e->cur.z = e->prev.z = pos->z - ((i * s->spacing) << 8);
    }
}

// 100%
struct A16 {
    s16 f0;
    char pad2[6];
    u16 f8;
    u16 fa;
    char padc[4];
};

struct B24 {
    s16 f0;
    char pad2[22];
};

struct S4 {
    char pad0[0x13f4];
    A16* a;
    B24* b;
};

extern "C" int func_ov004_0208ac58(S4* s, int i) {
    int result = 1;
    int busy = 0;
    if (s->a[i].f0 != 0 && s->a[i].fa < s->a[i].f8) {
        busy = 1;
    }
    if (!busy && s->b[i].f0 == 0) {
        result = 0;
    }
    return result;
}

// 94.8%: the original loads the division constant before f38
struct S3 {
    char pad0[0x38];
    u32 f38;
    char pad3c[0xec - 0x3c];
    s32 fec;
    char padf0[0x12c - 0xf0];
    s16 f12c;
};

extern "C" void func_ov015_020a2b60(S3* s) {
    if (s->f12c >= 10) {
        s->fec = 0;
        return;
    }
    s->f12c++;
    int v = (10 - s->f12c) * 31 / 10;
    s->f38 = (s->f38 & ~0xff) | (v & 0xff);
}

// 98.1%: two registers swapped (r5/r6)
struct S2 {
    char pad0[0x6b44];
    s16 ids[2];
    s16 flags[2];
};

extern "C" int func_ov016_020af02c(S2* s, u32* bits, int mask) {
    int result = 0;
    for (int i = 0; i < 2; i++) {
        if ((mask & (1 << i)) && s->flags[i] != 0) {
            s16 id = s->ids[i];
            if (!(bits[id / 32] & (1 << (id & 0x1f)))) {
                bits[id / 32] |= 1 << (id & 0x1f);
                result |= 1 << i;
            }
        }
    }
    return result;
}

// 100% (jump tables, identical with every compiler)
struct S6 {
    char pad0[0x10];
    s16 v[6];
};

extern "C" s16 func_ov123_0207731c(S6* s, int i) {
    switch (i) {
        case 0: return s->v[0];
        case 1: return s->v[1];
        case 2: return s->v[2];
        case 3: return s->v[3];
        case 4: return s->v[4];
        case 5: return s->v[5];
    }
    return 0;
}

struct S7 {
    char pad0[0x46];
    u16 mode;
};

extern "C" int func_ov086_020c9be0(S7* s) {
    switch (s->mode) {
        case 1: return 0x2800;
        case 2: return 0x2800;
        case 3: return 0x62800;
        case 4: return 0x62800;
    }
    return 0x2800;
}
