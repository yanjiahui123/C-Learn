#include <func.h>

int main(int argc, char **argv)
{
    if(fork())
    {//父进程退出
        exit(0);
    }
    setsid();
    chdir("/");
    umask(0);
    int i;
    for(i=0;i<3;i++)
        close(i);
    int fd = open("/tmp/log",O_RDWR);
    while(1)
    {
        write(fd,"wo hen shuai",12);
        sleep(60);
    }
    return 0;
}

