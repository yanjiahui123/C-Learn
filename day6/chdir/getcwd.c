#include <func.h>

int main()
{
    int ret;
    ret = chdir("/tmp");
    ERROR_CHECK(ret, -1, "chdir");
    char path[512];
    strcpy(path,getcwd(NULL,0));
    printf("current path = %s\n",path);
    return 0;
}

