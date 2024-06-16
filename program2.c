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
