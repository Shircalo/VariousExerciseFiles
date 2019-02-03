#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

typedef struct Node{
    ElementType data;
    struct Node * next;
}Node;

typedef struct LinkList{
    int length;
    Node * next;
}LinkList;
//插入节点
void InsertLinkList(LinkList * linklist, int pos, ElementType element);
//初始化链表
void InitLinkList(LinkList * linklist, ElementType * dataArray, int length);
//打印链表
void PrintLinkList(LinkList * linklist);
//是否为空
int IsLinkListEmpty(LinkList * linklist);
//获取元素
ElementType GetLinkListElement(LinkList * linklist, int pos);
//删除节点
ElementType DelLinkListElement(LinkList * linklist, int pos);
//清空链表
void ClearLinkList(LinkList * linklist);
#endif // LINKLIST_H_INCLUDED
