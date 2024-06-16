#include <stdio.h>

void openFile() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }
    // Do something with the file
    // ❌ Forget to close the file
}

int main() {
    openFile();
    // Resource leak as file is not closed
    return 0;
}

/**
Resource Management Issues (MISRA Rule 22.1 to Rule 22.20):
- The function openFile opens a file but does not close it, leading to a resource leak.
- MISRA guidelines recommend proper resource management to prevent such issues.

// ✅ Avoid resource leaks by ensuring that resources such as files are properly closed after use

#include <stdio.h>

void openFile() {
    FILE *file = fopen("test.txt", "r");
    if (file != NULL) {
        // Do something with the file
        fclose(file); // Properly close the file
    } else {
        printf("Failed to open file\n");
    }
}

int main() {
    openFile();
    return 0;
}
*/