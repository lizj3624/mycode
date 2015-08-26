// $_FILEHEADER_BEGIN ****************************
// �����˶Ȼ����Ƽ����޹�˾��Ȩ����
// Copyright (C) Badu Corporation.  All Rights Reserved
// �ļ����ƣ�my_strcmp.c
// �������ڣ�2015��08��25��
// �����ˣ�  LiZunju
// �ļ�˵����strcmp
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

