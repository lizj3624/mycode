// $_FILEHEADER_BEGIN ****************************
// �����˶Ȼ����Ƽ����޹�˾��Ȩ����
// Copyright (C) Badu Corporation.  All Rights Reserved
// �ļ����ƣ�my_strcpy.c
// �������ڣ�2015��08��25��
// �����ˣ�  LiZunju
// �ļ�˵����my_strcpy
// $_FILEHEADER_END ******************************
// strcpy �´��'\0'
// ԭָ�벻���޸ģ�Ҫconst
// �������
// Ҫ��סdst���׵�ַ����������׵�ַ
// stcpy������Ϊ����������ʵ��

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
