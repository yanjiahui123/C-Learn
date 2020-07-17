#include <func.h>

int main(int argc, char **argv)
{
    pid_t pid;
    pid = fork();
    if(!pid)
    {
        printf("i am child,pid is %d\n",getpid());
        while(1);
    }
    else
    {
        printf("i am parent,pid is %d\n",getpid());
        while(1);
    }
    return 0;
}

