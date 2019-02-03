#ifndef DOUBLYLINKLIST_H_INCLUDED
#define DOUBLYLINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
/** ˫������Ľ�㣬����һ������������ָ���� */
typedef struct DoublyNode{
    ElementType data;
    struct DoublyNode * prev;
    struct DoublyNode * next;
}DoublyNode;
/** ˫������ */
typedef struct DoublyLinkList{
    int length;
    DoublyNode * next;
}DoublyLinkList;

/** ��˫�������ָ��λ�ò���Ԫ�� */
void InserDoublyLinkList(DoublyLinkList * dlList, int pos, ElementType element);
/** ɾ��ָ��λ��Ԫ�� */
ElementType DelDoublyLinkList(DoublyLinkList * dlList, int pos);
/** ��ӡ���� */
void PrintDoublyLinkList(DoublyLinkList * dlList);
/** ����ָ��λ�ò���Ԫ�� */
ElementType GetDoublyLinkListElement(DoublyLinkList * dlList, int pos);
/** ����˫��������ĳ���ڵ��ǰ�ý�� */
#endif // DOUBLYLINKLIST_H_INCLUDED
