#ifndef ket_chunk_h
#define ket_chunk_h

#include "common.h"

typedef enum {
    OP_RETURN,
} OpCode;

typedef struct {
    uint8_t* code;
} Chunk;

#endif