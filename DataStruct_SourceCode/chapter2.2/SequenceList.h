#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

//初始化顺序表
void InitList(SeqList * sequence, ElementType * elementarray, int length);
////向顺序表的indes下标处插入某个元素
void InsertElement(SeqList * sequence, int index, ElementType element);
//打印顺序表
void PrintList(SeqList * sequence);
//删除元素
ElementType * DelElement(SeqList * sequence, int index);
//查找元素
ElementType * GetElement(SeqList * sequence, int index);
//获取长度
int GetLength(SeqList * sequence);
//清空顺序表
void ClearList(SeqList * sequence);
//是否为空
int IsEmpty(SeqList * sequence);
#endif // SEQUENCELIST_H_INCLUDED
