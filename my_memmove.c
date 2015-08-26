// $_FILEHEADER_BEGIN ****************************
// 北京八度互联科技有限公司版权所有
// Copyright (C) Badu Corporation.  All Rights Reserved
// 文件名称：my_memmove.c
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：memove
// $_FILEHEADER_END ******************************

#include <stdio.h>
char * my_memmove(void *dest, const void *src, size_t count)
{
    char *tmp;
    const char *s;

    if (dest <= src) {
        tmp = dest;
        s = src;
        while (count--)
            *tmp++ = *s++;
    } else {
        tmp = dest;
        tmp += count;
        s = src;
        s += count;
        while (count--)
            *--tmp = *--s;
    }
    return dest;
}
