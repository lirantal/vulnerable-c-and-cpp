#include <stdio.h>

void pointerArithmetic() {
    int arr[10];
    int *ptr = arr;
    // ❌ Pointer goes out of bounds
    ptr += 15;
    // Undefined behavior, potential memory corruption
    *ptr = 10;
}

int main() {
    pointerArithmetic();
    return 0;
}

/**
This code demonstrates: Pointer Arithmetic Vulnerability (MISRA Rule 18.1):
- The pointer ptr is incremented to go out of bounds of the array arr, leading to undefined behavior.
- MISRA guidelines enforce that pointers should always point within the bounds of the same array.

// ✅ Avoid pointer arithmetic that goes out of bounds to prevent undefined behavior and memory corruption

#include <stdio.h>

void safePointerArithmetic() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    // Properly handle pointer within bounds
}

int main() {
    safePointerArithmetic();
    return 0;
}
*/