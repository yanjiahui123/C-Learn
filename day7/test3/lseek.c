#include <func.h>

typedef struct student{
    char num[10];
    char name[20];
    double score;
}stu,*pstu;

int main(int argc, char **argv)
{
    ARGS_CHECK(argc, 2);
    int fd = open(argv[1],O_RDWR);
    int i;
    ERROR_CHECK(fd, -1, "open");
    stu s[3] = {
        {"111","yjh",99.0},
        {"222","yjj",98.0},
        {"333","bjj",90.2}
    };
    for(i=0;i<3;i++)
    {
        write(fd,&s[i],sizeof(stu));
    }
    
    int ret;
    ret = lseek(fd,0,SEEK_SET);
    stu temp;
    for(i=0;i<3;i++)
    {
        read(fd,&temp,sizeof(stu));
        printf("%s %s %f\n",temp.num,temp.name,temp.score);
    }
    close(fd);
    return 0;
}

