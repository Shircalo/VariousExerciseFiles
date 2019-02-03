#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"
#include "DataElement.h"

/** ������ջ��� */
typedef struct StackNode{
    ElementType data;               //����б����Ԫ��
    struct StackNode * next;        //ָ���¸�����ָ��
}StackNode;
/** ��ջ�Ľṹ */
typedef struct LinkedStack{
    StackNode * top;                //ջ��ָ��
    int length;                     //ջ�ĳ���
}LinkedStack;
/** ��ʼ����ջ */
void InitLinkedList(LinkedStack * linkedStack);
/** ѹջ�����ؽ����TRUE FALSE�� */
int PushLinkedList(LinkedStack * linkedStack, ElementType element);
/** ��ջ ����Ԫ�غͽ�� */
int PopLinkedStack(LinkedStack * linkedStack, ElementType * element);
/** ���ջ */
void ClearLinkedStack(LinkedStack * linkedStack);
/** ����ջ */
void DestroyLinkedStack(LinkedStack * linkedStack);

#endif // LINKSTACK_H_INCLUDED
