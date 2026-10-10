#include "types.h"

// Double-ended heap allocator: each of the 4 heaps allocates from its bottom (side 0) or its top (side 1).
// An allocator id is (heap << 1) | side. Names are placeholders until the owning class is identified.

#define BLOCK_HEADER_SIZE 12

union Unk_ov002_BlockInfo {
    struct {
        u32 size : 25;
        u32 free : 1;
        u32 side : 1;
        u32 heap : 5;
    } bits;
    struct {
        u32 sizeAndFree : 26;
        u32 id : 6;
    } fields;
};

struct Unk_ov002_Block {
    /* 0x0 */ Unk_ov002_Block* prev;
    /* 0x4 */ Unk_ov002_Block* next;
    /* 0x8 */ Unk_ov002_BlockInfo info;
};

struct Unk_ov002_Heap {
    /* 0x00 */ Unk_ov002_Block* unk0[2];
    /* 0x08 */ Unk_ov002_Block* bounds[2];
    /* 0x10 */ u32 unk10;
};

extern "C" Unk_ov002_Heap data_0205b7f0[4];

extern "C" void* func_ov002_02069a88(Unk_ov002_Block* block, s32 id, u32 size, s32 unused);

extern "C" void* func_ov002_02069820(s32 id, u32 size, u32 addr, s32 arg3) {
    if (size != 0) {
        s32 side = id & 1;
        size = (size + 3) & ~3;
        Unk_ov002_Block* bottom = data_0205b7f0[id >> 1].bounds[0];
        if ((u32)bottom + BLOCK_HEADER_SIZE < addr && (u32)data_0205b7f0[id >> 1].bounds[1] > addr + size) {
            Unk_ov002_Block* block = data_0205b7f0[id >> 1].bounds[side];
            if (side == 0) {
                func_ov002_02069a88(block, id, addr - (u32)block - BLOCK_HEADER_SIZE * 2, 0);
                block->info.bits.free = TRUE;
                return func_ov002_02069a88(block->next, id, size, arg3);
            } else {
                func_ov002_02069a88(block->prev, id, (u32)block - addr - size - BLOCK_HEADER_SIZE, 0);
                Unk_ov002_Block* prev = block->prev;
                prev->info.bits.free = TRUE;
                return func_ov002_02069a88(prev->prev, id, size, arg3);
            }
        } else if (addr == (u32)bottom + BLOCK_HEADER_SIZE) {
            if (bottom->info.bits.free && size <= bottom->info.bits.size) {
                return func_ov002_02069a88(bottom, id & ~1, size, arg3);
            }
        } else if ((u32)data_0205b7f0[id >> 1].bounds[1] == addr + size) {
            Unk_ov002_Block* block = data_0205b7f0[id >> 1].bounds[1]->prev;
            if (block->info.bits.free && size <= block->info.bits.size) {
                return func_ov002_02069a88(block, id | 1, size, arg3);
            }
        } else {
            Unk_ov002_Block* block = data_0205b7f0[id >> 1].unk0[side];
            u32 header = addr - BLOCK_HEADER_SIZE;
            if (side != 0) {
                block = block->prev;
            }
            BOOL forward = side == 0;
            do {
                s32 blockSize = block->info.bits.size;
                if (header > (u32)block && addr + size < (u32)block->next) {
                    if (block->info.bits.free && blockSize >= size) {
                        if (side == 0) {
                            func_ov002_02069a88(block, id, addr - (u32)block - BLOCK_HEADER_SIZE * 2, 0);
                            block->info.bits.free = TRUE;
                            return func_ov002_02069a88(block->next, id, size, arg3);
                        } else {
                            func_ov002_02069a88(block, id, (u32)block->next - addr - size - BLOCK_HEADER_SIZE, 0);
                            block->next->info.bits.free = TRUE;
                            return func_ov002_02069a88(block, id, size, arg3);
                        }
                    }
                    break;
                }
                block = forward ? block->next : block->prev;
            } while (block != NULL);
        }
    }
    return NULL;
}

extern "C" void* func_ov002_02069a88(Unk_ov002_Block* block, s32 id, u32 size, s32 unused) {
    s32 heap = id >> 1;
    s32 blockSize = block->info.bits.size;
    if (size + BLOCK_HEADER_SIZE < blockSize) {
        if (!(id & 1)) {
            Unk_ov002_Block* rest = (Unk_ov002_Block*)((u8*)block + BLOCK_HEADER_SIZE + size);
            rest->info.fields.sizeAndFree = (blockSize - (size + BLOCK_HEADER_SIZE)) | 0x2000000;
            rest->prev = block;
            rest->next = block->next;
            if (rest->next != NULL) {
                rest->next->prev = rest;
            }
            block->info.fields.sizeAndFree = size;
            block->next = rest;
            if (data_0205b7f0[heap].bounds[0] < rest) {
                data_0205b7f0[heap].bounds[0] = rest;
            }
        } else {
            Unk_ov002_Block* prev = block;
            block = (Unk_ov002_Block*)((u8*)block + (blockSize - size));
            block->info.fields.sizeAndFree = size;
            block->prev = prev;
            block->next = prev->next;
            if (block->next != NULL) {
                block->next->prev = block;
            }
            prev->info.fields.sizeAndFree = (blockSize - (size + BLOCK_HEADER_SIZE)) | 0x2000000;
            prev->next = block;
            if (data_0205b7f0[heap].bounds[1] > block) {
                data_0205b7f0[heap].bounds[1] = block;
            }
        }
    } else {
        block->info.fields.sizeAndFree = blockSize;
    }
    block->info.fields.id = id;
    return (u8*)block + BLOCK_HEADER_SIZE;
}

extern "C" void* func_ov002_02069bbc(u32 size, u32 addr, s32 id, s32 arg3) {
    return func_ov002_02069820(id, size, addr, arg3);
}

extern "C" void func_ov002_02069bdc(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    Unk_ov002_Block* block = (Unk_ov002_Block*)((u8*)ptr - BLOCK_HEADER_SIZE);
    Unk_ov002_Heap* heap = &data_0205b7f0[block->info.bits.heap];
    if (block->info.bits.side) {
        heap->bounds[1] = block;
        heap->bounds[0]->next = block;
        heap->bounds[0]->info.fields.sizeAndFree =
            ((u32)heap->bounds[1] - (u32)heap->bounds[0] - BLOCK_HEADER_SIZE) | 0x2000000;
        heap->bounds[1]->prev = heap->bounds[0];
    } else {
        Unk_ov002_Block* next = block->next;
        heap->bounds[0] = next;
        heap->bounds[1]->prev = next;
        heap->bounds[0]->info.fields.sizeAndFree =
            ((u32)heap->bounds[1] - (u32)heap->bounds[0] - BLOCK_HEADER_SIZE) | 0x2000000;
        heap->bounds[0]->next = heap->bounds[1];
    }
}

extern "C" void func_ov002_02069c98(s32 id) {
    Unk_ov002_Heap* heap = &data_0205b7f0[id >> 1];
    if (id & 1) {
        Unk_ov002_Block* block = heap->unk0[1];
        heap->bounds[1] = block;
        heap->bounds[0]->next = block;
        heap->bounds[0]->info.fields.sizeAndFree =
            ((u32)heap->bounds[1] - (u32)heap->bounds[0] - BLOCK_HEADER_SIZE) | 0x2000000;
        heap->bounds[1]->prev = heap->bounds[0];
    } else {
        Unk_ov002_Block* block = heap->unk0[0];
        heap->bounds[0] = block;
        heap->bounds[1]->prev = block;
        heap->bounds[0]->info.fields.sizeAndFree =
            ((u32)heap->bounds[1] - (u32)heap->bounds[0] - BLOCK_HEADER_SIZE) | 0x2000000;
        heap->bounds[0]->next = heap->bounds[1];
    }
}
