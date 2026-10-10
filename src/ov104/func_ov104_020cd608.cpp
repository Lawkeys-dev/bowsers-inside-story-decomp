#include "types.h"

struct Unk_ov104_Render {
    /* 0x00 */ virtual void unk00();
    /* 0x04 */ virtual void unk04(void* arg);
    /* 0x08 */ virtual void unk08();
    /* 0x0c */ virtual void unk0c();
    /* 0x10 */ virtual void unk10();
    /* 0x14 */ virtual void unk14();
    /* 0x18 */ virtual void unk18();
    /* 0x1c */ virtual void unk1c();
    /* 0x20 */ virtual void unk20();
    /* 0x24 */ virtual void unk24();
    /* 0x28 */ virtual void unk28();
    /* 0x2c */ virtual void unk2c();
    /* 0x30 */ virtual void unk30();
    /* 0x34 */ virtual void unk34();
    /* 0x38 */ virtual void unk38();
    /* 0x3c */ virtual void unk3c();
    /* 0x40 */ virtual void unk40();
    /* 0x44 */ virtual void unk44(void* arg);
    /* 0x48 */ virtual void unk48(u32 a, s32 b, s32 c, u32 d);
};

struct Unk_ov104_Obj {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ Unk_ov104_Render* unk10;
    /* 0x14 */ u8 unk14[0x38];
    /* 0x4c */ Unk_ov104_Obj* next;
    /* 0x50 */ u8 unk50[0x4];
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 unk58[0xc];
    /* 0x64 */ Unk_ov104_Obj* unk64;
    /* 0x68 */ u8 unk68[0x4];
    /* 0x6c */ u8 unk6c[0x200 - 0x6c];
    /* 0x200 */ u8 unk200[0x1e];
    /* 0x21e */ s16 unk21e;
};

struct Unk_ov104_Mgr {
    /* 0x0000 */ u8 unk0000[0x2800];
    /* 0x2800 */ Unk_ov104_Obj* unk2800;
};

struct Unk_ov104_Main {
    /* 0x000 */ u8 unk000[0x504];
    /* 0x504 */ u32 unk504;
};

extern "C" Unk_ov104_Main data_02055fe4;
extern "C" Unk_ov104_Mgr* data_ov008_02064f08;

extern "C" void* func_ov011_02066678(Unk_ov104_Mgr* mgr, u32 size, s32 align);
extern "C" void* func_ov011_02066c28(Unk_ov104_Mgr* mgr, u32 flags);
extern "C" void* func_ov011_02066f5c(u32 idx);
extern "C" void func_ov014_02097a20(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" void func_ov015_020a7aac(Unk_ov104_Obj* obj);
extern "C" void func_ov015_020a33d0(void* a, Unk_ov104_Obj* obj);

extern "C" void func_ov104_020cd608() {
    Unk_ov104_Obj* obj0 = NULL;
    Unk_ov104_Obj* obj1 = NULL;
    Unk_ov104_Obj* obj2 = NULL;

    if (((data_02055fe4.unk504 << 0x1c) >> 0x1e) == 2) {
        obj2 = (Unk_ov104_Obj*)func_ov011_02066678(data_ov008_02064f08, 0x1002, -1);
        obj2->unk64 = obj0;
    } else {
        obj0 = (Unk_ov104_Obj*)func_ov011_02066678(data_ov008_02064f08, 0x1000, -1);
        obj1 = (Unk_ov104_Obj*)func_ov011_02066678(data_ov008_02064f08, 0x1001, -1);
        obj0->unk64 = obj1;
        obj1->unk64 = obj0;
    }

    if (obj0 != NULL) {
        void* ret = func_ov011_02066f5c(0);
        obj0->unk10->unk04(ret);
        func_ov015_020a7aac(obj0);
        func_ov014_02097a20(obj0->unk10, obj0->unk10, -0x10000, 0, 0);
    }

    if (obj1 != NULL) {
        void* ret = func_ov011_02066f5c(1);
        obj1->unk10->unk04(ret);
        func_ov015_020a7aac(obj1);
        func_ov014_02097a20(obj1->unk10, obj1->unk10, -0x10000, 0, 0);
    }

    if (obj2 != NULL) {
        void* ret = func_ov011_02066f5c(2);
        obj2->unk10->unk04(ret);
        func_ov015_020a7aac(obj2);
        func_ov014_02097a20(obj2->unk10, obj2->unk10, -0x10000, 0, 0);
    }

    Unk_ov104_Obj* node = data_ov008_02064f08->unk2800;
    while (node != NULL) {
        Unk_ov104_Render* render = node->unk10;
        render->unk44(func_ov011_02066c28(data_ov008_02064f08, (u16)(node->unk21e + 0xc000)));
        render->unk48(0, -1, 0x100, 0);
        node->unk54 = 0;
        node = node->next;
    }

    node = data_ov008_02064f08->unk2800;
    while (node != NULL) {
        func_ov015_020a33d0(node->unk6c, node);
        node = node->next;
    }
}
