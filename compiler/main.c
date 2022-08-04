#include "../lib/common.h"
#include "../lib/chunk.h"
#include "../lib/debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);

    writeChunk(&chunk, OP_RETURN);

    // disassembl chunk
    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}