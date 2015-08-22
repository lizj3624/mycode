// $_FILEHEADER_BEGIN ****************************
// 文件名称：CacheQueue.cpp
// 创建日期：2015年08月21日
// 创建人：  LiZunju
// 文件说明：consume_product
// $_FILEHEADER_END ******************************

#include <iostream>
#include <deque>
#include <pthread.h>

class CacheQueue
{
public:
    CacheQueue();
    ~CacheQueue();

    void Init();

    void Push(int elem);
    void Pop();

private:
    std::deque<int> _que;
    pthread_mutex_t _que_lock;
    pthread_cond_t _que_full_cond;
    pthread_cond_t _que_empty_cond;

    int _que_len;
};

