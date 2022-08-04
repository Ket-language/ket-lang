#ifndef ket_chunk_h
#define ket_chunk_h

#include "common.h"
#include "value.h"

/* Function Return Operation */
typedef enum {  
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

/* Array structure */
typedef struct {  
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);
int  addConstant(Chunk* chunk, Value value);

#endif