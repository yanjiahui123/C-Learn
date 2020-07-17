#include <func.h>

int main(int argc, char **argv)
{
    if(!fork())
    {
        printf("i am child.\n");
        while(1);
    }
    else
    {
        printf("i am parent.\n");
        return 0;
    }
}
