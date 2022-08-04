#ifndef ket_chunk_h
#define ket_chunk_h

#include "common.h"

/* Function Return Operation */
typedef enum {  
    OP_RETURN,
} OpCode;

/* Array structure */
typedef struct {  
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif