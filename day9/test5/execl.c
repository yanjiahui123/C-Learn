#include <func.h>

int main(int argc, char **argv)
{
    printf("i am main process.\n");
    execl("./add","add","3","4",NULL);
    return 0;
}

