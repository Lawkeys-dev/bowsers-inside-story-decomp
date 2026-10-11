#include "types.h"

// TODO: the original writes PC directly (`eor pc, r1, r2, ror r1` after `ldm r0, {r1, r2}`), i.e. it jumps to a
// value computed from two words at r0 and never returns through lr. ARM C cannot express a write to PC with a
// rotated XOR, so this stub compiles to a normal return and does not match (0%).
extern "C" u32 func_ov129_0206db20(u32 *p) {
    u32 a = p[0];
    u32 b = p[1];
    return a ^ ((b >> a) | (b << (32 - a)));
}
