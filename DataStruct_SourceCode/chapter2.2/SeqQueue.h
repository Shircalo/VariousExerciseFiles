#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

/***********************************************************************************
 * Project:
 * Function:
 * Description:
 ***********************************************************************************
 *
 *
 ***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

typedef int State;

/** 循环队列的结构 */
typedef struct{
    ElementType data[MAX_SIZE];     //顺序存储，有些地方用的是 ElementType * base
    int front;                      //队头
    int rear;                       //队尾
    int length;                     //长度
    //可以增加一个标志位，显示是否已满
}SeqQueue;
/** 初始化 */
void InitSeqQueue(SeqQueue * seqQueue);
/** 入队 */
State OfferSeqQueue(SeqQueue * seqQueue, ElementType element);
/** 出队 */
State PollSeqQueue(SeqQueue * seqQueue, ElementType * element);
/** 判断循环队列是否为空 */
State IsSeqQueueFull(SeqQueue * seqQueue);

#endif // SEQQUEUE_H_INCLUDED
