#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED
#include "DataElement.h"
#include <stdio.h>
#include <stdlib.h>

/** ����ջ���������� */
typedef struct SeqStack{
    ElementType elements[MAX_SIZE];     //˳��ջ�������������Ԫ�ص�����
    int top;                            //ջ��
    int length;                         //ջ�ĳ���
}SeqStack;
/** ��ʼ��ջ */
void InitSeqStack(SeqStack * seqStack);
/** ѹջ�����ؽ����TRUE FALSE�� */
int PushSeqStack(SeqStack *seqStack, ElementType element);
/** ��ָ��ķ�ʽ���س�ջ��Ԫ�أ������ؽ����TRUE FALSE�� */
int PopSeqStack(SeqStack * seqStack, ElementType * element);
/** ���ջ */
void ClearSeqStack(SeqStack * seqStack);
/** �ж�ջ�Ƿ�Ϊ�� */
int IsSeqStackEmpty(SeqStack * seqStack);
/** ����ջ��Ԫ�� */
void GetSeqStackTopElement(SeqStack * seqStack, ElementType * element);
#endif // SEQSTACK_H_INCLUDED
