#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void err_sys(const char* x)
{
    perror(x);
    exit(0);
}

int main()
{
    pid_t childPid;
    printf("Parent greeting\n");
    childPid = fork();
    if(childPid  >= 0)
    {
        if(childPid == 0) {
            printf("Child greeting\n");
            sleep(2);
            printf("Child exiting\n");
        }
        else{
           sleep(2);
            printf("Parent exiting\n");
        }
    }
    else
        err_sys("fork error\n");
    return 0;
}