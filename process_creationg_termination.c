#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>

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
    if(childPid == 0)
    {
        printf("Child process\n");
        sleep(2);
        printf("Child exiting\n");
    }
    else if(childPid > 0)
    {
        wait(0);
        printf("Parent End\n");
    }
    else
        err_sys("fork error\n");
    return 0;
}
