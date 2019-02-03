#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

//��ʼ��˳���
void InitList(SeqList * sequence, ElementType * elementarray, int length);
////��˳����indes�±괦����ĳ��Ԫ��
void InsertElement(SeqList * sequence, int index, ElementType element);
//��ӡ˳���
void PrintList(SeqList * sequence);
//ɾ��Ԫ��
ElementType * DelElement(SeqList * sequence, int index);
//����Ԫ��
ElementType * GetElement(SeqList * sequence, int index);
//��ȡ����
int GetLength(SeqList * sequence);
//���˳���
void ClearList(SeqList * sequence);
//�Ƿ�Ϊ��
int IsEmpty(SeqList * sequence);
#endif // SEQUENCELIST_H_INCLUDED
