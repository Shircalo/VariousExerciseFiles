#include "SeqQueue.h"

/** 初始化 */
void InitSeqQueue(SeqQueue * seqQueue){
    if(NULL == seqQueue){
        seqQueue = (SeqQueue *)malloc(sizeof(SeqQueue));
    }
    seqQueue->front = 0;
    seqQueue->rear = 0;
    seqQueue->length = 0;
}
/** 判断循环队列是否为空 */
State IsSeqQueueFull(SeqQueue * seqQueue){
    if( seqQueue->front == ((seqQueue->rear + 1) % MAX_SIZE) ){
        return TRUE;
    }
    return FALSE;
}
/** 入队 */
State OfferSeqQueue(SeqQueue * seqQueue, ElementType element){
    if( seqQueue->front == ((seqQueue->rear + 1) % MAX_SIZE)){
        return FALSE;
    }
    seqQueue->data[seqQueue->rear] = element;
    seqQueue->rear = (seqQueue->rear + 1) % MAX_SIZE;
    seqQueue->length++;
    return TRUE;
}
/** 出队 */
State PollSeqQueue(SeqQueue * seqQueue, ElementType * element){
    if(seqQueue->front == seqQueue->rear){
        return FALSE;
    }
    *element = seqQueue->data[seqQueue->front];
    seqQueue->front = (seqQueue->front + 1) % MAX_SIZE;
    seqQueue->length--;
    return TRUE;
}

















