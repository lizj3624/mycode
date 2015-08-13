#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int  number;
    struct LinkNode *next;
} ST_LinkNode;

ST_LinkNode * CreateLink ( int iNum );
ST_LinkNode * RevserseLink( ST_LinkNode * pstHead );
int PrintLink( ST_LinkNode * pstHead );
int LinkFree( ST_LinkNode * pstHead );

ST_LinkNode * CreateLink ( int iNum )
{
    ST_LinkNode * pstCur;

    pstCur = (ST_LinkNode *)malloc(sizeof(ST_LinkNode));
    if ( pstCur == NULL )
    {
        printf("malloc error!\n");
        exit(0);
    }
    pstCur->number = iNum;
    pstCur->next = NULL;

    return pstCur;
}

int PrintLink( ST_LinkNode * pstHead )
{
    ST_LinkNode * pstCurr;

    if ( pstHead->next == NULL )
    {
        printf("Head is null\n");
        return 0;
    }

    pstCurr = pstHead->next;
    while ( pstCurr != NULL )
    {
        printf("%d ", pstCurr->number);
        pstCurr = pstCurr->next;
    }
    printf("\n");

    return 0;
}

int LinkFree( ST_LinkNode * pstHead )
{
    ST_LinkNode * pstCurr;

    if (pstHead == NULL)
        return 0;

    pstCurr = pstHead->next;   
    while(pstCurr != NULL)
    {
        pstHead->next = pstCurr->next;
        free(pstCurr);
        pstCurr = pstHead->next;
    }
    free(pstHead);
    //printf("free ok !\n");
    return 0;
}

ST_LinkNode * RevserseLink( ST_LinkNode * pstHead )
{
    ST_LinkNode *pPri, *pCurr, *pNext;

    if (pstHead == NULL)
    {
        printf("head null\n");
        return pstHead;
    }

    pPri = pstHead->next;
    pCurr = pPri->next;
    pNext = pCurr->next;
    pPri->next = NULL;
    while( pNext != NULL )
    {
        pCurr->next = pPri;
        pPri = pCurr;
        pCurr = pNext;
        pNext = pNext->next;
    }
    pCurr->next = pPri;
    pstHead->next = pCurr;

    return pstHead;
}

int main()
{
    int i = 0;
    int myarr[10] = {4, 16, 3, 11, 17, 21,5,19,32,22};
    ST_LinkNode *pstHead = NULL;
    ST_LinkNode *pstCurr = NULL;
    ST_LinkNode *pstMyCurr = NULL;

    pstHead = (ST_LinkNode *)malloc(sizeof(ST_LinkNode));
    if (pstHead == NULL)
    {
        printf("head err!\n");
        return -1;
    }
   
    pstMyCurr = pstHead;
    for ( i = 0; i < 10; i++ )
    {
        pstCurr = CreateLink( myarr[i] );
        pstMyCurr->next = pstCurr;
        pstMyCurr = pstMyCurr->next;
    }
    printf("List: ");
    PrintLink( pstHead );
    printf("Reverse: ");
    RevserseLink( pstHead );
    PrintLink( pstHead );

    LinkFree( pstHead );
    return 0;
}
