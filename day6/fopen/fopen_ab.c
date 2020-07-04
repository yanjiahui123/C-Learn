#include <func.h>

int main(int argc, char ** argv)
{
    ARGS_CHECK(argc, 2);
    FILE * fp;
    fp = fopen(argv[1], "rb+");
    ERROR_CHECK(fp, NULL, "fopen");
    char buf[50]={0};
    fread(buf,sizeof(char),sizeof(buf),fp);
    const char *str = "how are you";
    fwrite(str, sizeof(char), strlen(str), fp);
    fclose(fp);
    return 0;
}

