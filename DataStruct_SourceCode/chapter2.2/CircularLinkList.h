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

//����Ԫ��
void InsertCircularListEle(CircularList * cllist, ElementType element, int pos);
//��ӡ
void PrintCircularLinkList(CircularList * cllist);
//��ʼ��
void InitCircularLinkList(CircularList * cllist, ElementType * dataArray, int length);
//ɾ��
ElementType DeleteCircularList(CircularList * cllist, int pos);
//��ȡ�ڵ�ָ��
CircularNode * GetCircularListNode(CircularList * cllist, ElementType element);
//��node��ʼ��ӡ
void PrinCircularListNode(CircularList * cllist, CircularNode * node);
#endif // CIRCULARLINKLIST_H_INCLUDED
