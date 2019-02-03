#include "LinkStack.h"

/** 初始化链栈 */
void InitLinkedList(LinkedStack * linkedStack){
    linkedStack->top = NULL;    //栈为空
    linkedStack->length = 0;    //长度为0
}
/** 压栈并返回结果（TRUE FALSE） */
int PushLinkedList(LinkedStack * linkedStack, ElementType element){
    //创建一个新结点
    StackNode * newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = element;
    //将新结点的next指向top
    newNode->next = linkedStack->top;
    linkedStack->top = newNode;
    linkedStack->length++;
    return TRUE;
}
/** 出栈 返回元素和结果 */
int PopLinkedStack(LinkedStack * linkedStack, ElementType * element){
    if( NULL == linkedStack->top ){
        printf("栈为空");
        return TRUE;
    }
    //返回元素
    *element = linkedStack->top->data;
    //栈顶指针指向下一个结点
    StackNode * tempNode = linkedStack->top;
    linkedStack->top = linkedStack->top->next;
    //释放原栈顶空间
    free(tempNode);
    linkedStack->length--;
    return TRUE;
}
/** 清空栈 */
void ClearLinkedStack(LinkedStack * linkedStack){
    StackNode * tempNode = linkedStack->top;    //临时结点指向栈顶
    while(linkedStack->top){
        linkedStack->top = linkedStack->top->next;
        free(tempNode);
        linkedStack->length--;
    }
}
/** 销毁栈 */
void DestroyLinkedStack(LinkedStack * linkedStack){
    //先清空栈
    ClearLinkedStack(linkedStack);
    free(linkedStack);
    linkedStack = NULL;
}







