// $_FILEHEADER_BEGIN ****************************
// 文件名称：my_strcat.c
// 创建日期：2015年08月25日
// 创建人：  LiZunju
// 文件说明：my_strcat
// $_FILEHEADER_END ******************************
#include <stdio.h>

char * my_strcat(char * dst, char * src)
{
    if(dst == NULL || src == NULL)
        return NULL;

    char *p = dst;

    while(*dst != '\0')
        dst++;

    while((*dst++ = *src++) != '\0')
        ;

    return p;
}

int main()
{
    char a[5] = "12345";
    char b[10] = "abcde";

    my_strcat(b,a);

    printf("b = %s\n",b);

    return 0;
}
