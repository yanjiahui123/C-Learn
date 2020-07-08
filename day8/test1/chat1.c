#include <func.h>

int main(int argc, char **argv)
{
    ARGS_CHECK(argc, 3);
    int fdr = open(argv[1], O_RDONLY);
    int fdw = open(argv[2], O_WRONLY);
    printf("i am chat1, fdr = %d, fdw = %d\n",fdr, fdw);
    int ret;
    fd_set rdset;
    char buf[128] = {0};
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset);
        ret= select(fdr+1,&rdset,NULL,NULL,NULL);
        ERROR_CHECK(ret, -1,"select");
        if(FD_ISSET(STDIN_FILENO,&rdset))
        {
            memset(buf, 0, sizeof(buf));
            read(STDIN_FILENO, buf, sizeof(buf));
            write(fdw, buf, strlen(buf)-1);
        }
        if(FD_ISSET(fdr, &rdset))
        {
            memset(buf, 0, sizeof(buf));
            read(fdr, buf, sizeof(buf));
            printf("%s\n",buf);
        }
    }
    return 0;
}

