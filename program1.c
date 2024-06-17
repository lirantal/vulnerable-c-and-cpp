#include <stdio.h>
#include <stdlib.h>

void allocateMemory() {
    // Use-case:
    // For example, let's say you're writing a function to read a file into memory.
    // You don't know the size of the file until runtime, so you can't use a fixed-size array.
    // Instead, you can use malloc to allocate exactly the right amount of memory once you know the file size.
    int *ptr = (int *)malloc(10 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // Do something with ptr
    // ❌ Forget to free the memory
}

int main() {
    allocateMemory();
    // Memory leak as memory is not freed
    return 0;
}

/**
// ✅ Avoid memory leaks by ensuring that dynamically allocated memory is freed after use

#include <stdio.h>

void allocateMemory() {
    int arr[10]; // Use static allocation
    // Do something with arr

    // OR, if you manually allocate the memory with malloc(), free it after use:
    // free(ptr);
}

int main() {
    allocateMemory();
    return 0;
}
*/
