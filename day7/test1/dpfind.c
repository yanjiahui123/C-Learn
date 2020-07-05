#include <func.h>
int printDir(char * path, int width)
{
    DIR * dir;
    dir = opendir(path);
    ERROR_CHECK(dir, NULL, "opendir");
    struct dirent * p;
    while((p=readdir(dir)))
    {
        if(!strcmp(p->d_name,".") || !strcmp(p->d_name,".."))
            continue;
        char buf[1024]={0};
        char * fullpath = getcwd(NULL,0);
        sprintf(buf,"%s%s%s",fullpath,"/",p->d_name);
        printf("%*s%s\n",width,"|__ ",buf);
        if(p->d_type == 4)
            printDir(p->d_name,width+4);
    }
    closedir(dir);
    return 0;
}

int main(int argc, char **argv)
{
    ARGS_CHECK(argc, 2);
    printDir(argv[1], 4);
    return 0;
}

