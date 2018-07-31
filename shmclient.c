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
    int shmid;
    key_t key = 5678;
    char *shm, *s;
    if ((shmid = shmget(key, MAXSIZE, 0666)) < 0)
    die("shmget");
      if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    die("shmat");
    for (s = shm; *s != '\0'; s++)
        putchar(*s);
    putchar('\n');
    *shm = '*';
    exit(0);
}
