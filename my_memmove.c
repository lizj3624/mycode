// $_FILEHEADER_BEGIN ****************************
// �����˶Ȼ����Ƽ����޹�˾��Ȩ����
// Copyright (C) Badu Corporation.  All Rights Reserved
// �ļ����ƣ�my_memmove.c
// �������ڣ�2015��08��25��
// �����ˣ�  LiZunju
// �ļ�˵����memove
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
