// $_FILEHEADER_BEGIN ****************************
// 北京八度互联科技有限公司版权所有
// Copyright (C) Badu Corporation.  All Rights Reserved
// 文件名称：dul_node.c
// 创建日期：2015年08月11日
// 创建人：  LiZunju
// 文件说明：double_node
// $_FILEHEADER_END ******************************
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct dul_node_t{
    int  data;
    struct dul_node_t * prior;
    struct dul_node_t * next;
}dul_node;

void InitDulNode(dul_node ** plist)
{
    *plist = malloc(sizeof(dul_node));
    if((*plist) == NULL)
    {
        printf("malloc error %d\n",errno);
        return;
    }
    (*plist)->data = 0;
    (*plist)->prior = NULL;
    (*plist)->next = NULL;
}

void InsertDulNode(dul_node * plist, dul_node *elem)
{
    if((plist) == NULL || elem == NULL)
    {
        printf("param error\n");
        return;
    }

    dul_node * pNode = plist;
    while(pNode->next != NULL)
        pNode = pNode->next;

    elem->prior = pNode;
    pNode->next = elem;
    elem->next = NULL;
}

void PrintDulNode(dul_node * plist)
{
    if(plist == NULL)
    {
        printf("head null\n");
        return;
    }

    dul_node * pCurr = plist;
    while(pCurr != NULL)
    {
        printf("%d ", pCurr->data);
        pCurr = pCurr->next;
    }
    printf("\n");
}

void FreeDulNode(dul_node * plist)
{
    if(plist == NULL)
    {
        printf("list null\n");
        return;
    }

    dul_node * pCurr = plist;
    while(plist != NULL)
    {
       pCurr = plist;
       plist = plist->next;
       free(pCurr); 
    }
}

dul_node * Partition(dul_node * plist, dul_node * begin, dul_node * end)
{
    if(plist == NULL)
    {
        printf("list NULL\n");
        return NULL;
    }

    int data;
    if(begin < end)
    {
        data = begin->data;
        while(begin < end)
        {
            while(begin < end && (data <= end->data))
                end = end->prior;
            if(begin < end)
            {
               begin->data = end->data;
               begin = begin->next;
            }

            while(begin < end && (data > begin->data))
                begin = begin->next;
            if(begin < end)
            {
                end->data = begin->data;
                end = end->prior;
            } 
        }
        begin->data = data;
    }

    return begin;
}

void myqsort(dul_node * plist, dul_node * begin, dul_node * end)
{
    if(plist == NULL)
    {
        printf("list NULL\n");
        return;
    }

    dul_node * pCurr;

    pCurr = Partition(plist, begin, end);

    if(pCurr != begin)
        myqsort(plist, begin, pCurr->prior);

    if(pCurr != end)
        myqsort(plist, pCurr->next, end);
}

int main()
{
    dul_node * my_dul_node;
    InitDulNode(&my_dul_node);
    my_dul_node->data = 49;

    //printf("data %d\n", my_dul_node->data);
    dul_node * my_dul_node1;
    InitDulNode(&my_dul_node1);
    my_dul_node1->data = 38;
    //printf("data1 %d\n", my_dul_node1->data);
    InsertDulNode(my_dul_node, my_dul_node1);

    dul_node * my_dul_node2;
    InitDulNode(&my_dul_node2);
    my_dul_node2->data = 65;
    //printf("data2 %d\n", my_dul_node2->data);
    InsertDulNode(my_dul_node, my_dul_node2);

    dul_node * my_dul_node3;
    InitDulNode(&my_dul_node3);
    my_dul_node3->data = 97;
    InsertDulNode(my_dul_node, my_dul_node3);

    dul_node * my_dul_node4;
    InitDulNode(&my_dul_node4);
    my_dul_node4->data = 13;
    InsertDulNode(my_dul_node, my_dul_node4);

    dul_node * my_dul_node5;
    InitDulNode(&my_dul_node5);
    my_dul_node5->data = 27;
    InsertDulNode(my_dul_node, my_dul_node5);

    dul_node * my_dul_node6;
    InitDulNode(&my_dul_node6);
    my_dul_node6->data = 50;
    InsertDulNode(my_dul_node, my_dul_node6);
    
    dul_node * my_dul_node7;
    InitDulNode(&my_dul_node7);
    my_dul_node7->data = 23;
    InsertDulNode(my_dul_node, my_dul_node7);

    dul_node * my_dul_node8;
    InitDulNode(&my_dul_node8);
    my_dul_node8->data = 17;
    InsertDulNode(my_dul_node, my_dul_node8);

    dul_node * my_dul_node9;
    InitDulNode(&my_dul_node9);
    my_dul_node9->data = 30;
    InsertDulNode(my_dul_node, my_dul_node9);

    PrintDulNode(my_dul_node);

    dul_node * begin;
    dul_node * end;
    begin = end = my_dul_node;
    while(end->next != NULL)
        end = end->next;

    myqsort(my_dul_node, begin, end);

    PrintDulNode(my_dul_node);

    FreeDulNode(my_dul_node);

    return 0;
}
