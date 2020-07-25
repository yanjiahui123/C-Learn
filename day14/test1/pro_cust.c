#include <func.h>

int main(int argc, char **argv)
{
    int semid = semget(1000,2,IPC_CREAT|0600);
    ERROR_CHECK(semid,-1,"semget");
    unsigned short arr[2] = {10, 0};
    semctl(semid,0,SETALL,arr);
    struct sembuf sopp,sopv;
    if(!fork())//子进程作为消费者
    {
        while(1)
        {
            sopp.sem_num = 1;
            sopp.sem_op = -1;
            sopp.sem_flg = SEM_UNDO;
            sopv.sem_num = 0;
            sopv.sem_op = 1;
            sopv.sem_flg = SEM_UNDO;
            printf("i am child, empty=%d,full=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            semop(semid, &sopp, 1);
            printf("consume success\n");
            semop(semid, &sopv, 1);
            printf("i am child, empty=%d,full=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            sleep(3);
        }
    }
    else
    {
        while(1)
        {
            sopp.sem_num = 0;
            sopp.sem_op = -1;
            sopp.sem_flg = SEM_UNDO;
            sopv.sem_num = 1;
            sopv.sem_op = 1;
            sopv.sem_flg = SEM_UNDO;    
            printf("i am parent, empty=%d,full=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            semop(semid, &sopp, 1);
            printf("produce success\n");
            semop(semid, &sopv, 1);
            printf("i am parent, empty=%d,full=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            sleep(2);
        }
    }
    return 0;
}

