// $_FILEHEADER_BEGIN ****************************
// �����˶Ȼ����Ƽ����޹�˾��Ȩ����
// Copyright (C) Badu Corporation.  All Rights Reserved
// �ļ����ƣ�my_bubblesort.cpp
// �������ڣ�2015��08��10��
// �����ˣ�  LiZunju
// �ļ�˵����bubble
// $_FILEHEADER_END ******************************
#include <iostream>
#include <algorithm>

int bobble_sort(int *p, int n)
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 1; j < n - i; j++)
        {
            if(p[j] > p[j-1])
            {
                std::swap(p[j],p[j-1]);
            } 
        }
    }

    return 0;
}

int main()
{
    int a[10] = {43,99,21,11,9,18,3,7,6,34};
    int k;
    std::cout << "a =";
    for(k = 0; k < 10; k++)
    {
        std::cout << " " << a[k];
    }
    std::cout<<std::endl;;

    bobble_sort(a,10);

    std::cout << "a =";
    for(k = 0; k < 10; k++)
    {
        std::cout << " "<< a[k];
    }
    std::cout<<std::endl;;

    return 0;
}

