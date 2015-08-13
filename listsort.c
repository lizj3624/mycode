#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct DuLNode

{
    ElemType data;
    struct DuLNode* next;
    struct DuLNode* prior;
}DuLNode,*DuLinkList;


void initList(DuLinkList* L)
{
    *L=(DuLinkList)malloc(sizeof(DuLNode));
    (*L)->data=49;
    (*L)->prior=NULL;
    (*L)->next=NULL;
}


void insertList(DuLinkList L,ElemType elem)
{
    DuLinkList p=(DuLinkList)malloc(sizeof(DuLNode));
    p->data=elem;
    p->next=NULL;
    while(L->next!=NULL)
        L=L->next;
    L->next=p;

    p->prior=L;
}


void traverseList(DuLinkList L)
{
    //int cnt=1;

    while(L->next)
    { 
        printf("%d   ",L->data);
        L=L->next;
    }

    printf("%d\n",L->data);
}


void freeList(DuLinkList L)
{
    DuLinkList p;

    while(L->next)
    {
        p=L;

        L=L->next;
        free(p);
    }

    free(L);
}


DuLinkList  partition(DuLinkList L,DuLinkList low,DuLinkList high)
{
    DuLinkList pivotkey=(DuLinkList)malloc(sizeof(DuLNode));
    pivotkey->data=low->data;

    while(low!=high){
        while(low!=high&&high->data>=pivotkey->data) 
            high=high->prior;
        low->data=high->data;

        while(low!=high&&low->data<=pivotkey->data)  
            low=low->next;

        high->data=low->data;

        traverseList(L);
    }

    low->data=pivotkey->data;

    return low;
}


void sortList(DuLinkList L,DuLinkList low,DuLinkList high)
{
    DuLinkList pivotloc=partition(L,low,high);

    printf("111\n");
    if(pivotloc!=low)
        sortList(L,low,pivotloc->prior);

    printf("222\n");
    if(pivotloc!=high)
        sortList(L,pivotloc->next,high);
}

int  main()
{
    DuLinkList L;
    initList(&L);
    insertList(L,38);
    insertList(L,65);
    insertList(L,97);
    insertList(L,13);
    insertList(L,27);
    insertList(L,50);
    insertList(L,23);
    insertList(L,17);
    insertList(L,30);
    traverseList(L);

    DuLinkList low,high,L2;
    low=L;L2=L;
    while(L2->next!=NULL)
        L2=L2->next;
    high=L2;
    sortList(L,low,high);

    traverseList(L);

    freeList(L);
    return 0;
}

