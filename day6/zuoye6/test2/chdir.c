#include <func.h>

int main()
{
    char current[512];
    strcpy(current,getcwd(NULL,0));
    printf("current path %s\n", current);
    int ret=chdir("../");
    ERROR_CHECK(ret, -1, "chdir");
    printf("After change current %s\n",getcwd(NULL,0));
    return 0;
}

