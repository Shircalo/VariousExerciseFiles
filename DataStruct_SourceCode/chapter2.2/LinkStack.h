#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"
#include "DataElement.h"

/** 定义链栈结点 */
typedef struct StackNode{
    ElementType data;               //结点中保存的元素
    struct StackNode * next;        //指向下个结点的指针
}StackNode;
/** 链栈的结构 */
typedef struct LinkedStack{
    StackNode * top;                //栈顶指针
    int length;                     //栈的长度
}LinkedStack;
/** 初始化链栈 */
void InitLinkedList(LinkedStack * linkedStack);
/** 压栈并返回结果（TRUE FALSE） */
int PushLinkedList(LinkedStack * linkedStack, ElementType element);
/** 出栈 返回元素和结果 */
int PopLinkedStack(LinkedStack * linkedStack, ElementType * element);
/** 清空栈 */
void ClearLinkedStack(LinkedStack * linkedStack);
/** 销毁栈 */
void DestroyLinkedStack(LinkedStack * linkedStack);

#endif // LINKSTACK_H_INCLUDED
