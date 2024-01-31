#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signum);
int main(void){
    // handler is the function that deals with the input SIGINT (Ctr+C)
    signal(SIGINT, handler);

    printf("Press Ctrl+C to terminate the program...\n");

    // Loops infinitely to keep the program running
    while(1){
        // Do nothing
    }

    return 0;
}
void handler(int signum){
    if (signum==SIGINT){
        printf("\nSIGINT (Ctrl+C) caught. Exiting...\n");
        exit(EXIT_SUCCESS);
    }
}