#include <func.h>

void  cleanup(void *p)
{
   free(p);
   printf("clean func\n");
}
void * threadFunc(void * p)
{
    p = malloc(20);
    pthread_cleanup_push(cleanup, p);
    char buf[10];
    read(0, buf, 10);
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

