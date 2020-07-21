#include <func.h>
#define N 100000
int main(int argc, char **argv)
{
    int shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    int semid = semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(semid,-1,"semget");
    int *p =(int *) shmat(shmid,NULL,1);
    ERROR_CHECK(p,(int *)-1,"shmat");
    struct sembuf sopp,sopv;
    sopp.sem_num=0;
    sopp.sem_op=-1;
    sopp.sem_flg=SEM_UNDO;
    sopv.sem_num=0;
    sopv.sem_op=1;
    sopv.sem_flg=SEM_UNDO;
    *p=0;
    if(!fork())
    {
        int i;
        for(i=0;i<N;i++)
        {
            semop(semid,&sopp,1);
            p[0]++;
            semop(semid,&sopv,1);
        }
    }
    else
    {
        int i;
        for(i=0;i<N;i++)
        {
            semop(semid,&sopp,1);
            p[0]++;
            semop(semid,&sopv,1);
        }
        wait(NULL);
        printf("%d\n",p[0]);
    }
    return 0;
}

