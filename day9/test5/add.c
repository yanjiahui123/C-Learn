#include <func.h>

int main(int argc,char ** argv)
{
    printf("%s+%s=%d\n",argv[1],argv[2],argv[1][0]-'0'+argv[2][0]-'0');
    return 0;
}
