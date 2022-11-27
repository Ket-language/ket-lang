#include "../lib/common.h"
#include "../lib/chunk.h"
#include "../lib/debug.h"
#include "../lib/vm.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_ADD, 123);

    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_DIVIDE, 123);
    writeChunk(&chunk, OP_NEGATE, 123);
    
    writeChunk(&chunk, OP_RETURN, 123);

    // disassembl chunk
    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}