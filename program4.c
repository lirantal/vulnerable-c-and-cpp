#include <iostream>
#include <cstring>

void vulnerableFunction(char* input) {
    char buffer[10];
    // ❌ Potential buffer overflow
    // Fix with Snyk Code:
    strcpy(buffer, input);
}

int main() {
    char input[20] = "This is a long string";
    vulnerableFunction(input);
    return 0;
}
