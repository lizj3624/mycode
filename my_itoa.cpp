// $_FILEHEADER_BEGIN ****************************
// 文件名称：my_itoa.c
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：itoa
// $_FILEHEADER_END ******************************

#include <iostream>
#include <algorithm>

void reserver(char * str)
{
    char * begin = str;
    char * end = str;

    while(*end != '\0')
        end++;
    end--;

    while(begin < end)
    {
        std::swap(*begin, *end);
        begin++;
        end--;
    } 
}

void my_itoa(int num, char * str)
{
    int isNeg = 0;
    int i = 0;

    if(num < 0) 
    {
        num = -num;
        isNeg = 1;
    } 

    while(num > 0)
    {
        str[i++] = (num % 10) + '0';
        num = num/10;
    }
    if(isNeg == 1)
        str[i++] = '-';
    str[i++] = '\0';

    reserver(str);
}

int main()
{
    int my_num = -2345902;
    char my_str[10];

    std::cout << "num: " << my_num << std::endl;

    my_itoa(my_num, my_str);

    std::cout << "str: " << my_str << std::endl;
}


