// $_FILEHEADER_BEGIN ****************************
// 文件名称：my_atof.cpp
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：atof
// $_FILEHEADER_END ******************************

#include <stdio.h>
#include <iostream>
#include <cmath>

float my_atof(char * str)
{
    if(str == NULL)
        return 0;

    float sum = 0.00;
    float decial = 0.00;
    
    int dotflag = 0;
    int negflag = 0;
    int j = 0;

    while(*str != '\0')
    {
        if(*str == '.')
        {
            dotflag = 1;
            str++;
            continue;
        }

        if(*str == '-')
        {
            negflag = 1;
            str++;
            continue;
        }

        if(*str != '.'&& dotflag == 0)
        {
            sum = sum * 10 + (*str - '0');
            str++;
        }

        if(dotflag == 1)
        {
            j++;
            decial = decial + (float)(*str - '0')/pow(10,j); 
            str++;
        }
    }

    if(negflag == 1)
        return -(sum + decial);
    else
        return (sum + decial);
}

int main()
{
    char a[9] = "12345.34";

    std::cout << "f = " << my_atof(a) << std::endl;
    return 0;
}
