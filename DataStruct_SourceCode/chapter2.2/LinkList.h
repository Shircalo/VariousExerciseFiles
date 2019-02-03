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
//����ڵ�
void InsertLinkList(LinkList * linklist, int pos, ElementType element);
//��ʼ������
void InitLinkList(LinkList * linklist, ElementType * dataArray, int length);
//��ӡ����
void PrintLinkList(LinkList * linklist);
//�Ƿ�Ϊ��
int IsLinkListEmpty(LinkList * linklist);
//��ȡԪ��
ElementType GetLinkListElement(LinkList * linklist, int pos);
//ɾ���ڵ�
ElementType DelLinkListElement(LinkList * linklist, int pos);
//�������
void ClearLinkList(LinkList * linklist);
#endif // LINKLIST_H_INCLUDED
