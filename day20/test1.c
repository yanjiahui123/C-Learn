#include <func.h>
#define N 20000000
typedef struct
{
    int val;
    pthread_mutex_t mutex;
}Data_t;

void *threadFunc(void * p)
{
    Data_t *pArg = (Data_t *)p;
    int i;
    for(i=0;i<N;i++)
    {
        pthread_mutex_lock(&pArg->mutex);
        ++(pArg->val);
        pthread_mutex_unlock(&pArg->mutex);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thid;
    Data_t threadInfo; 
    threadInfo.val = 0;
    pthread_mutex_init(&threadInfo.mutex, NULL);
    pthread_create(&thid, NULL, threadFunc, &threadInfo);
    int i;
    for(i=0;i<N;i++)
    {
        pthread_mutex_lock(&threadInfo.mutex);
        ++(threadInfo.val);
        pthread_mutex_unlock(&threadInfo.mutex);
    }
    pthread_join(thid, NULL);
    printf("ret = %d\n",threadInfo.val);
    return 0;
}

