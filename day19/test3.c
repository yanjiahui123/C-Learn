#include <func.h>

void  cleanup1(void *p)
{
   printf("clean func1\n");
}
void  cleanup2(void *p)
{
   printf("clean func2\n");
}
void * threadFunc(void * p)
{
    pthread_cleanup_push(cleanup1, p);
    pthread_cleanup_push(cleanup2, p);
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thid;
    int ret = pthread_create(&thid, NULL, threadFunc, NULL);
    THREAD_ERROR_CHECK(ret, "pthread_create");
    ret = pthread_cancel(thid);
    THREAD_ERROR_CHECK(ret, "pthread_cancel");
    long threadRet;
    ret = pthread_join(thid, (void **)&threadRet);
    printf("I am main thread get %ld\n", threadRet);
    return 0;
}

