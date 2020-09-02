#include <func.h>

void *threadFunc(void *p)
{
    time_t now;
    time(&now);
    char buf[100]={0};
    char *s=ctime_r(&now, buf);
    printf("I am child now %s\n",s);
    sleep(3);
    printf("I am child now %s\n",s);
}
int main(int argc, char **argv)
{
    pthread_t thid;
    pthread_create(&thid, NULL, threadFunc, NULL);
    sleep(1);
    time_t now;
    time(&now);
    char buf[100]={0};
    char *s=ctime_r(&now, buf);
    printf("I am main now %s\n",s);
    pthread_join(thid, NULL);
    return 0;
}

