// $_FILEHEADER_BEGIN ****************************
// �ļ����ƣ�my_insert_sort.cpp
// �������ڣ�2015��08��10��
// �����ˣ�  LiZunju
// �ļ�˵����insert
// $_FILEHEADER_END ******************************
#include <iostream>
#include <string>
#include <algorithm>

int insert_sort(int *p, int n)
{
    int i,j;
    for(i = 1; i < n; i++)
    {
        for(j = i - 1; j >= 0 && p[j] > p[j+1]; j--)
        {
            std::swap(p[j],p[j+1]);
        }
    }

    return 0;
}
int main()
{
    int a[10]={33,2,9,11,8,63,31,91,100,21};

    for(int i = 0; i < 10; i++)
        std::cout << a[i] <<" ";
    std::cout << std::endl;

    insert_sort(a,10);


    for(int y = 0; y < 10; y++)
        std::cout << a[y] <<" ";
    std::cout << std::endl;

    return 0;
}
