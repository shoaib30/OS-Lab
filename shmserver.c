//#include <sys/types.h>
//#include <sys/ipc.h>
//#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

#define MAXSIZE 27

void die(char *s)
{
    perror(s);
    exit(0);
}
int main()
{
    char c;
    int shmid;
    key_t key = 5678;
    char *shm, *s;
    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        die("shmat");
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
    *s++ = c;
    while (*shm != '*')
        sleep(1);
    exit(0);
}
