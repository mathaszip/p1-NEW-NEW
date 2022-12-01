#include <stdlib.h>

void * allocate_memory_dynamically(int amount_of_memory, const void *allocation_pointer){
    return malloc(amount_of_memory * sizeof allocation_pointer);
}