#ifndef CIRCULARLINKLIST_H_INCLUDED
#define CIRCULARLINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"

typedef struct CircularNode{
    ElementType data;
    struct CircularNode * next;
}CircularNode;

typedef struct CircularList{
    int length;
    CircularNode * next;
}CircularList;

//插入元素
void InsertCircularListEle(CircularList * cllist, ElementType element, int pos);
//打印
void PrintCircularLinkList(CircularList * cllist);
//初始化
void InitCircularLinkList(CircularList * cllist, ElementType * dataArray, int length);
//删除
ElementType DeleteCircularList(CircularList * cllist, int pos);
//获取节点指针
CircularNode * GetCircularListNode(CircularList * cllist, ElementType element);
//从node开始打印
void PrinCircularListNode(CircularList * cllist, CircularNode * node);
#endif // CIRCULARLINKLIST_H_INCLUDED
