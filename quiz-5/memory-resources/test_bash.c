#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Dynamically allocate 10 kB of memory
    void* ptr = malloc(10*1024);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Free the allocated memory
    free(ptr);

    sleep(4);
    printf("I have awakened!\n");
    return 0;
}
