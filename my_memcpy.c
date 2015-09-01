// $_FILEHEADER_BEGIN ****************************
// 文件名称：my_memcpy.c
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：memcpy
// $_FILEHEADER_END ******************************

#include <stdio.h>

void *memcpy(void *dest, const void *src, size_t count)
{
    char *tmp = dest;
    const char *s = src;

    while (count--)
        *tmp++ = *s++;
    return dest;
}

