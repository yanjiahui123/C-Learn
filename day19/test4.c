#include <func.h>
#define N 20000000
typedef struct
{
    int val;
    pthread_mutex_t mutex;
}Data_t;
void * threadFunc(void * p)
{
    Data_t *pArg = (Data_t *)p;
    for(int i=0;i<N;i++)
    {
        pthread_mutex_lock(&pArg->mutex);
        ++(pArg->val);
        pthread_mutex_unlock(&pArg->mutex);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    Data_t p;
    p.val=0;
    pthread_mutex_init(&p.mutex, NULL);
    pthread_t thid;
    
    struct timeval start, finish;
    gettimeofday(&start, NULL);
    int ret = pthread_create(&thid, NULL, threadFunc, &p);
    THREAD_ERROR_CHECK(ret, "pthread_create");

    for(int i=0;i<N;i++)
    {
        pthread_mutex_lock(&p.mutex);
        ++(p.val);
        pthread_mutex_unlock(&p.mutex);
    }
    
    long threadRet;
    ret = pthread_join(thid, (void **)&threadRet);
    gettimeofday(&finish, NULL);
    printf("use time %ld\n",finish.tv_sec-start.tv_sec+(finish.tv_usec-start.tv_usec)/1000000);
    printf("I am main thread get %d\n", p.val);
    return 0;
}

