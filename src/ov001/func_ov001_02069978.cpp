#include "types.h"

struct Unk_ov001_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    /* 0x04 */ u8 unk04[0xcc];
    /* 0xd0 */ s32 unkD0;
};

extern "C" void* func_0201a138(u32 a, s32 b, s32 c, s32 d);
extern "C" Unk_ov001_Obj* func_0201bb14(void* ptr, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void func_0201bdfc(Unk_ov001_Obj* obj, s32 idx, void* data, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" u8 data_ov001_02069d40[];
extern "C" u8 data_ov001_02069d58[];
extern "C" u8 data_ov001_02069d70[];
extern "C" u8 data_ov001_02069d88[];

extern "C" Unk_ov001_Obj* func_ov001_02069978() {
    Unk_ov001_Obj* obj = (Unk_ov001_Obj*)func_0201a138(0xc24, 0, 0, 1);
    if (obj != NULL) {
        obj = func_0201bb14(obj, 8, 0, 4, 4, -1, 0);
    }
    func_0201bdfc(obj, 0, data_ov001_02069d40, 0, 0, 0, 0, 0, 0);
    func_0201bdfc(obj, 1, data_ov001_02069d58, 0, 0, 0, 0, 0, 0);
    func_0201bdfc(obj, 2, data_ov001_02069d70, 0, 0, 0, 0, 0, 0);
    func_0201bdfc(obj, 3, data_ov001_02069d88, 0, 0, 0, 0, 0, 0);
    BOOL done = obj->unkD0 == 0;
    while (!done) {
        obj->vf4();
        done = obj->unkD0 == 0;
    }
    return obj;
}
