//题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
//句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。
//例如输入“I am a student.”，则输出“student. a am I”。
//分析：由于编写字符串相关代码能够反映程序员的编程能力和编程习惯，与字符串相关的问题一直是程序员笔试、面试题的热门题目。
//本题也曾多次受到包括微软在内的大量公司的青睐。
//由于本题需要翻转句子，我们先颠倒句子中的所有字符。这时，不但翻转了句子中单词的顺序，而且单词内字符也被翻转了。
//我们再颠倒每个单词内的字符。由于单词内的字符被翻转两次，因此顺序仍然和输入时的顺序保持一致。
//还是以上面的输入为例子。翻转“I am a student.”中所有字符得到“.tneduts a ma I”，
//再翻转每个单词中字符的顺序得到“students. a am I”，正是符合要求的输出。

/*2、
  给定一个字符串，一个这个字符串的子串，将第一个字符串反转，但保留子串的顺序不变
  例如输入： 第一个字符串: "http://www.sina.com "  
子串: "sina "  
输出： "moc.sina.www//:ptth "  
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Reverse(char *pBeg, char *pEnd);
char * ReverseSenc(char *pData);

int main()
{
    //char str[]="I am a student";
    char mystr[] = "http://www.sina.com";
    char substr[] = "sina";
    char *pEnd = NULL, *pBeg = NULL;
    /*int i;
   
    pEnd = str;
    pBeg = str;
    pCur = str;

    for(i = 0; i < strlen(str) - 1; i++)
        pEnd++;   
    printf("str:%s\n", str);
    //Reverse(pBeg, pEnd);
    ReverseSenc(str);
    printf("Reverse:%s\n", str);
   */
    //substr reverse
    printf("mystr:%s\n", mystr);
    printf("substr:%s\n", substr);
    pEnd = pBeg = strstr(mystr, substr);
    pEnd = pEnd + (strlen(substr) - 1);
    Reverse(pBeg, pEnd);
    pBeg = pEnd = mystr;
    pEnd = pEnd + (strlen(mystr) - 1);
    Reverse(pBeg, pEnd);
    printf("reverse mystr:%s\n", mystr);
    return 0;
}

int Reverse(char *pBeg, char *pEnd)
{
    char pTmp;

    if ((pBeg == NULL) || (pEnd == NULL))
    {
        printf("param is null!\n");
        return -1;
    }
    while(pBeg < pEnd)
    {
        pTmp = *pBeg;
        *pBeg = *pEnd;
        *pEnd = pTmp;
        pBeg++;
        pEnd--;
    }
    return 0;
}

char * ReverseSenc(char *pData)
{
    char *pEnd = NULL, *pBeg = NULL;
    int i;

    if (pData == NULL)
       return NULL;

    pEnd = pBeg = pData;

    for (i = 0; i < strlen(pData) - 1; i++)   
        pEnd++;
    Reverse(pBeg, pEnd);

    pBeg = pEnd = pData;
    while(*pBeg != '\0')
    {
        if (*pBeg == ' ')
        {
            pBeg++;
            pEnd++;
            continue;
        }
        else if((*pEnd == ' ') || (*pEnd == '\0'))  
        {
            Reverse(pBeg, --pEnd);
            pBeg = ++pEnd;
        }
        else
            pEnd++;
    }
    return pData;
}
