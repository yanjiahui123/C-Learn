#include <func.h>

int main(int argc, char **argv)
{
    int shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    char *p;
    p =(char *)shmat(shmid,NULL,1);
    ERROR_CHECK(p,(char *)-1,"shmat");
    strcpy(p,"hello");
    struct shmid_ds buf;
    if(!fork())
    {
        printf("I am child,get %s\n",p);
        exit(0);
    }
    else
    {
        p[0]='H';
        wait(NULL);
        int ret=shmctl(shmid,IPC_RMID,&buf);
        ERROR_CHECK(ret,-1,"shmctl");
    }
    return 0;
}

