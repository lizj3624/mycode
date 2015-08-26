// $_FILEHEADER_BEGIN ****************************
// 北京八度互联科技有限公司版权所有
// Copyright (C) Badu Corporation.  All Rights Reserved
// 文件名称：my_strcmp.c
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：strcmp
// $_FILEHEADER_END ******************************
#include <stdio.h>
#include <assert.h>

int my_strcmp(char *dst, char *src)
{
    assert((dst != NULL)&&(src != NULL));

    while(*dst == *src)
    {
        if(*dst == '\0')
            return 0;

        dst++;
        src++;
    }

    return *dst - *src;
}

int main()
{
    char a[5] = "12345";
    char b[5] = "67890";

    printf("result = %d\n", my_strcmp(a,b));

    return 0;
}

