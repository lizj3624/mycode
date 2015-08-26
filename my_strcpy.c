// $_FILEHEADER_BEGIN ****************************
// 北京八度互联科技有限公司版权所有
// Copyright (C) Badu Corporation.  All Rights Reserved
// 文件名称：my_strcpy.c
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：my_strcpy
// $_FILEHEADER_END ******************************
// strcpy 会拷贝'\0'
// 原指针不能修改，要const
// 参数检查
// 要记住dst的首地址，返回这个首地址
// stcpy可以作为其他函数的实参

#include <stdio.h>
#include <string.h>

char * my_strcpy(char * dst, const char * src)
{
    if(dst == NULL || src == NULL)
        return NULL;

    char * address = dst;

    while((*dst++ = *src++) != '\0')
        ;

    return address;
}

char * my_strncpy(char * dst, const char * src, int n)
{
    if(dst == NULL || src == NULL)
        return NULL;

    char * address = dst;
    int m = n;

    while(((*dst++ = *src++) != '\0')&& m > 0)
    {
        m--;
    }
       
    *(address+n) = '\0';

    return address;
}

int main()
{
    char a[10] = "2345609875";
    char b[10];
    char c[4];
    char d[4];

    my_strcpy(b,a);
    strcpy(d,a);
    my_strncpy(c,a,4);

    printf("b = %s\n", b);
    printf("c = %s\n", c);
    printf("d = %s\n", d);

    return 0;
}
