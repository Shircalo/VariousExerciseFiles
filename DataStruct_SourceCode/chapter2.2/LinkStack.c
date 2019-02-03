#include "LinkStack.h"

/** ��ʼ����ջ */
void InitLinkedList(LinkedStack * linkedStack){
    linkedStack->top = NULL;    //ջΪ��
    linkedStack->length = 0;    //����Ϊ0
}
/** ѹջ�����ؽ����TRUE FALSE�� */
int PushLinkedList(LinkedStack * linkedStack, ElementType element){
    //����һ���½��
    StackNode * newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = element;
    //���½���nextָ��top
    newNode->next = linkedStack->top;
    linkedStack->top = newNode;
    linkedStack->length++;
    return TRUE;
}
/** ��ջ ����Ԫ�غͽ�� */
int PopLinkedStack(LinkedStack * linkedStack, ElementType * element){
    if( NULL == linkedStack->top ){
        printf("ջΪ��");
        return TRUE;
    }
    //����Ԫ��
    *element = linkedStack->top->data;
    //ջ��ָ��ָ����һ�����
    StackNode * tempNode = linkedStack->top;
    linkedStack->top = linkedStack->top->next;
    //�ͷ�ԭջ���ռ�
    free(tempNode);
    linkedStack->length--;
    return TRUE;
}
/** ���ջ */
void ClearLinkedStack(LinkedStack * linkedStack){
    StackNode * tempNode = linkedStack->top;    //��ʱ���ָ��ջ��
    while(linkedStack->top){
        linkedStack->top = linkedStack->top->next;
        free(tempNode);
        linkedStack->length--;
    }
}
/** ����ջ */
void DestroyLinkedStack(LinkedStack * linkedStack){
    //�����ջ
    ClearLinkedStack(linkedStack);
    free(linkedStack);
    linkedStack = NULL;
}







