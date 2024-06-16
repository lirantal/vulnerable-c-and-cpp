#include <stdio.h>
#include <stdlib.h>

void allocateMemory() {
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
