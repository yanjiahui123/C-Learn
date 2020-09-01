#include <func.h>
void * threadFunc(void * p)
{
    printf("I am child thread get %ld\n", (long) p);
    long val = 2;
    pthread_exit((void *)val);
}

int main(int argc, char **argv)
{
    pthread_t thid;
    long val = 1;
    int ret = pthread_create(&thid, NULL, threadFunc, (void *)val);
    THREAD_ERROR_CHECK(ret, "pthread_create");
    long threadRet;
    ret = pthread_join(thid, (void **)&threadRet);
    printf("I am main thread get %ld\n", threadRet);
    return 0;
}

