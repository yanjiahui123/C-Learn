#include <func.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1],O_RDWR);
    dup2(fd, STDOUT_FILENO);
    printf("nihao\n");
    close(fd);
    return 0;
}

