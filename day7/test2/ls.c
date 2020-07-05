#include <func.h>


int main(int argc, char **argv)
{
    DIR * dir;
    dir = opendir(argv[1]);
    ERROR_CHECK(dir, NULL, "opendir");
    struct dirent * p;
    while((p = readdir(dir)))
    {
        if(!strcmp(p->d_name,".") || !strcmp(p->d_name,".."))
            continue;
        struct stat buf;
        int ret;
        ret = stat(p->d_name,&buf);
        printf("%x %ld %s %s %ld %s\n",buf.st_mode,buf.st_nlink,
               getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,
               buf.st_size,ctime(&buf.st_mtim));

    }
    return 0;
}

