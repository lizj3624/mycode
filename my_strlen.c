// $_FILEHEADER_BEGIN ****************************
// 文件名称：my_strlen.c
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：my_strlen
// $_FILEHEADER_END ******************************
#include <stdio.h>

int my_strlen(const char * str)
{
    if(str == NULL)
        return 0;

    int len = 0;

    while(*str++ != '\0')
        len++;

    return len;
}

int main()
{
    char a[10] = "wedf234";

    printf("len = %d\n", my_strlen(a));

    return 0;
}
