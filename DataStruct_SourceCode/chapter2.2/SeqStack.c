#include "SeqStack.h"

/** ��ʼ��ջ */
void InitSeqStack(SeqStack * seqStack){
    seqStack->top = -1;            //ջΪ��
    seqStack->length = 0;
}
/** ѹջ�����ؽ����TRUE FALSE�� */
int PushSeqStack(SeqStack *seqStack, ElementType element){
    if( (MAX_SIZE - 1) == seqStack->top ){
        printf("ѹջʧ�ܣ�\n");
        return FALSE;
    }
    seqStack->top++;        //ջ��+1���Ա�����µ�Ԫ��
    seqStack->elements[seqStack->top] = element;
    seqStack->length++;     //��Ҫ���ǰѳ���+1
    return TRUE;
}
/** ��ָ��ķ�ʽ���س�ջ��Ԫ�أ������ؽ����TRUE FALSE�� */
int PopSeqStack(SeqStack * seqStack, ElementType * element){
    if( -1 == seqStack->top ){
        printf("ʧ�ܣ�\n");
        return FALSE;
    }
    *element = seqStack->elements[seqStack->top];
    seqStack->length--;
    seqStack->top--;
    return TRUE;
}
/** ���ջ */
void ClearSeqStack(SeqStack * seqStack){
    seqStack->length = 0;
    seqStack->top = -1;
}
/** �ж�ջ�Ƿ�Ϊ�� */
int IsSeqStackEmpty(SeqStack * seqStack){
    if( -1 == seqStack->top ){
        return TRUE;
    }
    return FALSE;
}
/** ����ջ��Ԫ�� */
void GetSeqStackTopElement(SeqStack * seqStack, ElementType * element){
    if( -1 == seqStack->top ){
        printf("ջΪ�գ�\n");
        return;
    }
    *element = seqStack->elements[seqStack->top];
}









