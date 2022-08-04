#include <stdlib.h>
#include "../lib/chunk.h"

// Initialize Array Chunk
// Array Starts off empty
void initChunk(Chunk* chunk) {
    chunk->count    = 0;
    chunk->capacity = 0;
    chunk->code     = NULL;
}

void writeChunk(Chunk* chunk, uint8_t byte) {
    if (chunk->capacity < chunk->count +1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code     = GROW_ARRAY(uint8_t, chunk->code,oldCapacity, chunk->capacity)
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}