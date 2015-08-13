// $_FILEHEADER_BEGIN ****************************
// 文件名称：my_qort_sort.cpp
// 创建日期：2015年08月10日
// 创建人：  LiZunju
// 文件说明：qort
// $_FILEHEADER_END ******************************
#include <iostream>
#include <algorithm>
#include <stdio.h>

void qsort(int *p, int begin, int end)
{
    if(begin < end)
    {
        int _begin = begin;
        int _end = end;
        int x = p[begin];
        while(_begin < _end)
        {
            while(_begin < _end && p[_end] >= x)
                _end--;
            if(_begin < _end)
                p[_begin++] = p[_end];

            while(_begin < _end && p[_begin] < x)
                _begin++;
            if(_begin < _end)
                p[_end--] = p[_begin];

            for(int y = 0; y < 10; y++)
                std::cout << p[y] << " ";
            std::cout << std::endl;
        }
        p[_begin] = x;
        printf("1111\n");
        for(int y = 0; y < 10; y++)
            std::cout << p[y] << " ";
        std::cout << std::endl;
        qsort(p,begin,_begin -1);
        printf("2222\n");
        for(int y = 0; y < 10; y++)
            std::cout << p[y] << " ";
        std::cout << std::endl;
        qsort(p,_begin + 1,end);
    }   
}

int main()
{
    int a[10] = {21,4,6,1,8,45,28,30,22,49}; 
    for(int i = 0; i < 10; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    qsort(a,0,9);

    for(int y = 0; y < 10; y++)
        std::cout << a[y] << " ";
    std::cout << std::endl;

    return 0;
}

