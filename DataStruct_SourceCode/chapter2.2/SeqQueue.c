#include "SeqQueue.h"

/** ��ʼ�� */
void InitSeqQueue(SeqQueue * seqQueue){
    if(NULL == seqQueue){
        seqQueue = (SeqQueue *)malloc(sizeof(SeqQueue));
    }
    seqQueue->front = 0;
    seqQueue->rear = 0;
    seqQueue->length = 0;
}
/** �ж�ѭ�������Ƿ�Ϊ�� */
State IsSeqQueueFull(SeqQueue * seqQueue){
    if( seqQueue->front == ((seqQueue->rear + 1) % MAX_SIZE) ){
        return TRUE;
    }
    return FALSE;
}
/** ��� */
State OfferSeqQueue(SeqQueue * seqQueue, ElementType element){
    if( seqQueue->front == ((seqQueue->rear + 1) % MAX_SIZE)){
        return FALSE;
    }
    seqQueue->data[seqQueue->rear] = element;
    seqQueue->rear = (seqQueue->rear + 1) % MAX_SIZE;
    seqQueue->length++;
    return TRUE;
}
/** ���� */
State PollSeqQueue(SeqQueue * seqQueue, ElementType * element){
    if(seqQueue->front == seqQueue->rear){
        return FALSE;
    }
    *element = seqQueue->data[seqQueue->front];
    seqQueue->front = (seqQueue->front + 1) % MAX_SIZE;
    seqQueue->length--;
    return TRUE;
}

















