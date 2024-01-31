#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>

struct proc{
    int id;
    int num;
    char a;
};
void waiting(int);
int main() {
    struct proc proc[4];
    const int num_children=4;
    for (int x = 0; x < num_children; x++){
        printf("Input a character to be assigned to process %d:",x+1);
        scanf(" %c",&proc[x].a);
    }
    for(int x=0;x<num_children;x++){
        pid_t child_pid = fork();
        proc[x].num=x+1;
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0){
            proc[x].id=getpid();
            printf("I am child process %d (with pid %d) and my character was %c\n",proc[x].num,proc[x].id,proc[x].a);
            exit(EXIT_SUCCESS);  // Child process exits
        }   
    }
    waiting(num_children);
    /*
    for (int x = 0; x < num_children; x++) {
        wait(NULL); // Wait for all child processes to finish
    }
    */
    return 0;
}
