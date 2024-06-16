#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
    // get the filename from the first command line argument 
    char *filename = argv[1];
    // append the filename to the current directory
    char path[50] = "./";
    // ❌ concatenate the path and filename to create the full path into path variable with a fixed size of 50
    // a long filename can cause a buffer overflow
    strcat(path, filename);

    // ❌ concatenate the path and filename
    // the attacker can control the filename and provide a path traversal attack
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // read the contents of the file into memory and print the size of the file:
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, file);
    free(string);

    printf("Size of the file: %ld\n", fsize);
    printf("Contents of the file: %s\n", string);

    // ❌ free the string memory
    // the string is already freed above and this extra check introduces
    // a double free vulnerability which would crash the program:
    // 
    //   a.out(82730,0x1fff80c00) malloc: double free for ptr 0x158009800
    //   a.out(82730,0x1fff80c00) malloc: *** set a breakpoint in malloc_error_break to debug
    //   zsh: abort      ./a.out "../examples/CONTRIBUTING.md"
    if (string != NULL) {
        free(string);
    }

    // ❌ introduce a use after free vulnerability in the code as an example:
    if (fsize == 0) {
        string[0] = 'A';
    }
    
    fclose(file);
    return 0;
}