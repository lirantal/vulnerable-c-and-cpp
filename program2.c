#include <stdio.h>

void undefinedBehavior() {
    // ❌ Division by zero - undefined behavior
    int x = 5 / 0;
    printf("Value of x: %d\n", x);
}

int main() {
    undefinedBehavior();
    return 0;
}

/**
// ✅ Avoid undefined behavior by ensuring that the program does not perform operations that are not defined by the C standard.

#include <stdio.h>

void safeDivision(int a, int b) {
    if (b != 0) {
        int result = a / b;
        printf("Result: %d\n", result);
    } else {
        printf("Division by zero is not allowed\n");
    }
}

int main() {
    safeDivision(10, 0);
    return 0;
}
*/