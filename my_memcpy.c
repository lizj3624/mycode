// $_FILEHEADER_BEGIN ****************************
// �����˶Ȼ����Ƽ����޹�˾��Ȩ����
// Copyright (C) Badu Corporation.  All Rights Reserved
// �ļ����ƣ�my_memcpy.c
// �������ڣ�2015��08��25��
// �����ˣ�  LiZunju
// �ļ�˵����memcpy
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

