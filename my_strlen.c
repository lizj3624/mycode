// $_FILEHEADER_BEGIN ****************************
// �ļ����ƣ�my_strlen.c
// �������ڣ�2015��08��25��
// �����ˣ�  LiZunju
// �ļ�˵����my_strlen
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
