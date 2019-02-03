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

/** ѭ�����еĽṹ */
typedef struct{
    ElementType data[MAX_SIZE];     //˳��洢����Щ�ط��õ��� ElementType * base
    int front;                      //��ͷ
    int rear;                       //��β
    int length;                     //����
    //��������һ����־λ����ʾ�Ƿ�����
}SeqQueue;
/** ��ʼ�� */
void InitSeqQueue(SeqQueue * seqQueue);
/** ��� */
State OfferSeqQueue(SeqQueue * seqQueue, ElementType element);
/** ���� */
State PollSeqQueue(SeqQueue * seqQueue, ElementType * element);
/** �ж�ѭ�������Ƿ�Ϊ�� */
State IsSeqQueueFull(SeqQueue * seqQueue);

#endif // SEQQUEUE_H_INCLUDED
