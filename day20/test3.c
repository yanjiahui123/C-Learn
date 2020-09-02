#include <func.h>
typedef struct
{
    pthread_cond_t cond;
    pthread_mutex_t mutex;
}Data_t;
void *threadFunc1(void *p)
{
    Data_t *pArg = (Data_t*)p;
    pthread_mutex_lock(&pArg->mutex);
    pthread_cond_wait(&pArg->cond, &pArg->mutex);
    printf("thread1 wake up\n");
    pthread_mutex_unlock(&pArg->mutex);
}
void *threadFunc2(void *p)
{
    Data_t *pArg = (Data_t*)p;
    pthread_mutex_lock(&pArg->mutex);
    pthread_cond_wait(&pArg->cond, &pArg->mutex);
    printf("thread2 wake up\n");
    pthread_mutex_unlock(&pArg->mutex);
}
int main(int argc, char **argv)
{
    pthread_t thid1, thid2;
    Data_t threadInfo;
    pthread_mutex_init(&threadInfo.mutex, NULL);
    pthread_cond_init(&threadInfo.cond, NULL);
    pthread_create(&thid1, NULL, threadFunc1, &threadInfo);
    pthread_create(&thid1, NULL, threadFunc2, &threadInfo);
    usleep(100);
    pthread_cancel(thid1);
    pthread_cancel(thid2);

    pthread_join(thid1,NULL);
    pthread_join(thid2,NULL);

    return 0;
}

