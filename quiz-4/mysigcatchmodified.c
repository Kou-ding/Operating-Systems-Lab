#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile int i=0;
void handler(int signo);

int main(void){
    printf("Press Ctrl+C 3 times to terminate the program...\n");
    signal(SIGINT,handler);
    while(1) {
        // Do nothing
    }
    return 0;
}

void handler(int signo){
    i++;
    if(i<3){
        printf("\nSIGINT (Ctrl+C) seen %d time(s).\n",i);
    }
    else{
        printf("\nSIGINT (Ctrl+C) seen %d time(s).\nExiting...\n",i);
        exit(EXIT_SUCCESS);
    } 
}
