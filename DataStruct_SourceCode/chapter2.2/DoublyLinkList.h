#ifndef DOUBLYLINKLIST_H_INCLUDED
#define DOUBLYLINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
/** 双向链表的结点，包含一个数据域，两个指针域 */
typedef struct DoublyNode{
    ElementType data;
    struct DoublyNode * prev;
    struct DoublyNode * next;
}DoublyNode;
/** 双向链表 */
typedef struct DoublyLinkList{
    int length;
    DoublyNode * next;
}DoublyLinkList;

/** 向双向链表的指定位置插入元素 */
void InserDoublyLinkList(DoublyLinkList * dlList, int pos, ElementType element);
/** 删除指定位置元素 */
ElementType DelDoublyLinkList(DoublyLinkList * dlList, int pos);
/** 打印链表 */
void PrintDoublyLinkList(DoublyLinkList * dlList);
/** 根据指定位置查找元素 */
ElementType GetDoublyLinkListElement(DoublyLinkList * dlList, int pos);
/** 返回双向链表中某个节点的前置结点 */
#endif // DOUBLYLINKLIST_H_INCLUDED
