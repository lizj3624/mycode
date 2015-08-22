// $_FILEHEADER_BEGIN ****************************
// �ļ����ƣ�CacheQueueMain.cpp
// �������ڣ�2015��08��21��
// �����ˣ�  LiZunju
// �ļ�˵����main
// $_FILEHEADER_END ******************************

#include "CacheQueue.h" 
#include <pthread.h>

void * PutData(void * data);
void * PopData(void * data);

CacheQueue my_queue;

int main()
{
    pthread_t my_consume;
    pthread_t my_product;

    my_queue.Init();

    pthread_create(&my_consume,NULL,&PopData,0); 
    pthread_create(&my_product,NULL,&PutData,0); 

    pthread_join(my_product,NULL);
    pthread_join(my_consume,NULL);

    return 0;
}

void * PutData(void * data)
{
    static int num = 0;
    while(1)
    {
        if(num > 50) 
            break;
        my_queue.Push(num);
        //std::cout <<"PutData" << std::endl;
        num++;
    } 

    return NULL;
}

void * PopData(void * data)
{
    static int num1 = 0;
    while(1)
    {
        if(num1 > 50)
            break;
        my_queue.Pop();
        //std::cout <<"PopData" << std::endl;
        num1++;
    }

    return NULL;
}
