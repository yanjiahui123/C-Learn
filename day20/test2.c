#include <func.h>

typedef struct
{
    int tickets;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
}Data_t;

void * saleWindows1(void *p)
{
    Data_t *pArg = (Data_t *)p;
    while(1)
    {
        pthread_mutex_lock(&pArg->mutex);
        if(pArg->tickets>0)
        {
            printf("I am saller1 ,rest tickets = %d\n",pArg->tickets);
            --pArg->tickets;
            printf("I am saller1 after saling,rest tickets = %d\n",pArg->tickets);
            if(!pArg->tickets)
            {
                pthread_cond_signal(&pArg->cond);
            }
            pthread_mutex_unlock(&pArg->mutex);
            sleep(1);
        }
        else
        {
            pthread_mutex_unlock(&pArg->mutex);
            break; 
        }
    }
    return NULL;
}
void * saleWindows2(void *p)
{
    Data_t *pArg = (Data_t *)p;
    while(1)
    {
        pthread_mutex_lock(&pArg->mutex);
        if(pArg->tickets>0)
        {
            printf("I am saller2 ,rest tickets = %d\n",pArg->tickets);
            --pArg->tickets;
            printf("I am saller2 after saling,rest tickets = %d\n",pArg->tickets);
            if(!pArg->tickets)
            {
                pthread_cond_signal(&pArg->cond);
            }
            pthread_mutex_unlock(&pArg->mutex);
            sleep(1);
        }
        else
        {
            pthread_mutex_unlock(&pArg->mutex);
            break;
        }
    }
    return NULL;
}

void *setTickets(void *p)
{
    Data_t *pArg = (Data_t *)p;
    pthread_mutex_lock(&pArg->mutex);
    if(pArg->tickets > 0)
        pthread_cond_wait(&pArg->cond, &pArg->mutex);
    printf("reset tickets\n");
    pArg->tickets = 20;
    pthread_mutex_unlock(&pArg->mutex);
}
int main(int argc, char **argv)
{
    pthread_t thid1, thid2, thid3;
    Data_t threadInfo;
    threadInfo.tickets=20;
    pthread_cond_init(&threadInfo.cond, NULL);
    pthread_mutex_init(&threadInfo.mutex, NULL);
    pthread_create(&thid1, NULL, saleWindows1, &threadInfo);
    pthread_create(&thid2, NULL, saleWindows2, &threadInfo);
    pthread_create(&thid3, NULL, setTickets, &threadInfo);

    usleep(100);
    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);
    pthread_join(thid3, NULL);
    return 0;
}

