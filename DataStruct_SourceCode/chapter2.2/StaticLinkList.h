#ifndef STATICLINKLIST_H_INCLUDED
#define STATICLINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

#define MAX_SIZE_SSL 10
#define OK 1
#define ERROR 0
#define OK 1

/********************************************************
*静态链表在实际开发中用的少，只是为了在没有指针的情况下
*模拟
*********************************************************/

typedef struct {
    ElementType data;
    int cursor;
}StaticLinkList[MAX_SIZE_SSL];
//初始化
void InitStaticLinkList(StaticLinkList sllist);
//打印cursor
void PrintStaticLinkList(StaticLinkList sllist);
/** 插入元素 */
int InserStaticLinkList(StaticLinkList sllist, int pos, ElementType element);
/** 分配内存 */
int mallocSSL(StaticLinkList sllist);
/** 获取静态链表的长度 */
int GetStaticLinkList(StaticLinkList sllist);
/** 回收原始数组中指定下标的空间 */
void FreeStaticLinkListS(StaticLinkList sllist, int index);
/** 删除表中指定位置的元素 */
void DelStaticLinkList(StaticLinkList sllist, int pos);

#endif // STATICLINKLIST_H_INCLUDED
