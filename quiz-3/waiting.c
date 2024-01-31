#include <stdio.h>
#include <sys/wait.h>

void waiting(int time) {
    for (int x = 0; x < time; x++) {
        wait(NULL); // Wait for all child processes to finish
    }
}
