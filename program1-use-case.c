#include <stdio.h>
#include <stdlib.h>

char* readFileIntoMemory(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file contents
    char* buffer = (char*)malloc(fsize + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // Read the file into the buffer
    fread(buffer, 1, fsize, file);
    // Null-terminate the string
    buffer[fsize] = '\0';

    fclose(file);
    return buffer;
}

int main(int argc, char* argv[]) {
    // get the filename for the file to read from the command line as the first argument:
    char* filename = argv[1];
    char* contents = readFileIntoMemory(filename);
    if (contents != NULL) {
        printf("File contents: %s\n", contents);
        // ❌ Forget to free the memory
        // free(contents)
        return;
    }
    return 0;
}