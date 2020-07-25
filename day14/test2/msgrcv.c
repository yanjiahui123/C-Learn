#include <func.h>
struct msgbuf{
    long mtype;
    char mtext[64];
};

int main(int argc, char **argv)
{
    int msgid = msgget(1000,IPC_CREAT|0600);
    ERROR_CHECK(msgid, -1, "msgget");
    struct msgbuf msg;
    bzero(&msg,sizeof(msg));
    int ret = msgrcv(msgid, &msg, sizeof(msg.mtext), atoi(argv[1]), 1);
    ERROR_CHECK(ret, -1, "msgrcv");
    printf("%s\n",msg.mtext);
    return 0;
}

