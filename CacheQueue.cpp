// $_FILEHEADER_BEGIN ****************************
// 文件名称：CacheQueue.cpp
// 创建日期：2015年08月21日
// 创建人：  LiZunju
// 文件说明：consume_product
// $_FILEHEADER_END ******************************

#include "CacheQueue.h"

CacheQueue::CacheQueue()
{

}

CacheQueue::~CacheQueue()
{
    pthread_mutex_destroy(&_que_lock);
    pthread_cond_destroy(&_que_empty_cond);
    pthread_cond_destroy(&_que_full_cond);
}

void CacheQueue::Init()
{
    _que_len = 50; 
    pthread_cond_init(&_que_full_cond, NULL);
    pthread_cond_init(&_que_empty_cond, NULL);
    pthread_mutex_init(&_que_lock, NULL);

    //std::cout << "Init ok" << std::endl;
}

void CacheQueue::Push(int elem)
{
    pthread_mutex_lock(&_que_lock); 
    while(_que.size() >= (size_t)_que_len)
    {
        //std::cout << "push wait" << std::endl;
        pthread_cond_wait(&_que_full_cond,&_que_lock);
    }

    _que.push_back(elem);
    std::cout << "push elem : " << elem << std::endl;
    pthread_cond_signal(&_que_empty_cond); 

    pthread_mutex_unlock(&_que_lock);
}

void CacheQueue::Pop()
{
    pthread_mutex_lock(&_que_lock); 
    while(_que.size() <= 0)
    {
        //std::cout << "pop wait" << std::endl;
        pthread_cond_wait(&_que_empty_cond,&_que_lock);
    }

    int req = _que.front();
    std::cout << "pop elem : " << req << std::endl;
    _que.pop_front();

    pthread_cond_signal(&_que_full_cond);
    
    pthread_mutex_unlock(&_que_lock);
}
