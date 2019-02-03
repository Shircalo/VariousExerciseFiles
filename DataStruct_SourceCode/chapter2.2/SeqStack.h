#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED
#include "DataElement.h"
#include <stdio.h>
#include <stdlib.h>

/** 定义栈的数据类型 */
typedef struct SeqStack{
    ElementType elements[MAX_SIZE];     //顺序栈中用来存放数据元素的数组
    int top;                            //栈顶
    int length;                         //栈的长度
}SeqStack;
/** 初始化栈 */
void InitSeqStack(SeqStack * seqStack);
/** 压栈并返回结果（TRUE FALSE） */
int PushSeqStack(SeqStack *seqStack, ElementType element);
/** 以指针的方式返回出栈的元素，并返回结果（TRUE FALSE） */
int PopSeqStack(SeqStack * seqStack, ElementType * element);
/** 清空栈 */
void ClearSeqStack(SeqStack * seqStack);
/** 判断栈是否为空 */
int IsSeqStackEmpty(SeqStack * seqStack);
/** 返回栈顶元素 */
void GetSeqStackTopElement(SeqStack * seqStack, ElementType * element);
#endif // SEQSTACK_H_INCLUDED
