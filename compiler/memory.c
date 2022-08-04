#include "../lib/memory.h"

// reallocate() function is used to manage memory
// -allocating memory, freeing it, and 
// -changing the size of an existing allocation
void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1);
    return result;
}