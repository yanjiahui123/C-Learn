#include <func.h>

int main(int argc, char **argv)
{
    if(!fork())
    {
        printf("i am child,pid=%d\n",getpid());
    }
    else
    {
        printf("i am parent,pid=%d\n",getpid());
        int status;
        pid_t pid = wait(&status);
        if(WIFEXITED(status))
        {
            printf("exit_code=%d\n",WEXITSTATUS(status));
        }
        else
        {
            printf("child crash.\n");
        }
    }
    return 0;
}

