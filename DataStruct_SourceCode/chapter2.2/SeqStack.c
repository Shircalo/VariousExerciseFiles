#include "SeqStack.h"

/** 初始化栈 */
void InitSeqStack(SeqStack * seqStack){
    seqStack->top = -1;            //栈为空
    seqStack->length = 0;
}
/** 压栈并返回结果（TRUE FALSE） */
int PushSeqStack(SeqStack *seqStack, ElementType element){
    if( (MAX_SIZE - 1) == seqStack->top ){
        printf("压栈失败！\n");
        return FALSE;
    }
    seqStack->top++;        //栈顶+1，以便插入新的元素
    seqStack->elements[seqStack->top] = element;
    seqStack->length++;     //不要忘记把长度+1
    return TRUE;
}
/** 以指针的方式返回出栈的元素，并返回结果（TRUE FALSE） */
int PopSeqStack(SeqStack * seqStack, ElementType * element){
    if( -1 == seqStack->top ){
        printf("失败！\n");
        return FALSE;
    }
    *element = seqStack->elements[seqStack->top];
    seqStack->length--;
    seqStack->top--;
    return TRUE;
}
/** 清空栈 */
void ClearSeqStack(SeqStack * seqStack){
    seqStack->length = 0;
    seqStack->top = -1;
}
/** 判断栈是否为空 */
int IsSeqStackEmpty(SeqStack * seqStack){
    if( -1 == seqStack->top ){
        return TRUE;
    }
    return FALSE;
}
/** 返回栈顶元素 */
void GetSeqStackTopElement(SeqStack * seqStack, ElementType * element){
    if( -1 == seqStack->top ){
        printf("栈为空！\n");
        return;
    }
    *element = seqStack->elements[seqStack->top];
}









