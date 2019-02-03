#include <stdio.h>
#include <stdlib.h>

#include "DataElement.h"
#include "SequenceList.h"
#include "LinkList.h"
#include "CircularLinkList.h"
#include "StaticLinkList.h"
#include "DoublyLinkList.h"
#include "SeqStack.h"
#include "SeqQueue.h"

ElementType dataArray[] = {
    {1,"萌王"},
    {2,"夏尔"},
    {3,"库洛艾"}

};

void TestSequenceList(void);
void TestLinkList(void);
void TestCircularLinkList(void);
void TestStaticLinkList(void);
void TestDoublyLinkList(void);
void TestSeqStack(void);
void TestSeqQueue(void);

int main()
{
    TestSeqQueue();
    //TestSeqStack();
    //printf("Hello world!\n");
    //TestSequenceList();
    //TestLinkList();
    //TestCircularLinkList();
    //TestStaticLinkList();
    //TestDoublyLinkList();
    return 0;
}
//
void TestSequenceList(void)
{
    SeqList sequence;
    InitList(&sequence, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintList(&sequence);
    ElementType * element = DelElement(&sequence, 0);
    PrintList(&sequence);
    printf("%d,%s\n",element->id, element->name);
    free(element);
}
//
void TestLinkList(void)
{
    LinkList linklist;
    linklist.length = 0;
    InitLinkList(&linklist, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    DelLinkListElement(&linklist, 1);
    ClearLinkList(&linklist);
    PrintLinkList(&linklist);
}
//
void TestCircularLinkList(void)
{void TestStaticLinkList(void);
    ElementType element;
    CircularList * cllist = (CircularList *)malloc(sizeof(CircularList));
    cllist->length = 0;
    cllist->next = NULL;
    InitCircularLinkList(cllist, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintCircularLinkList(cllist);
    element = DeleteCircularList(cllist, 2);
    printf("\n");
    ElementType elem = dataArray[0];
    PrinCircularListNode(cllist, GetCircularListNode(cllist, elem));
    printf("\n%d\t%s\n",element.id,element.name);
}
//
void TestStaticLinkList(void)
{
    StaticLinkList sllist;
    InitStaticLinkList(sllist);
    PrintStaticLinkList(sllist);
    ElementType element1;
    ElementType element2;
    ElementType element3;
    element1.id = 1;
    element1.name = "萌王";
    element2.id = 2;
    element2.name = "夏尔";
    element3.id = 3;
    element3.name = "库洛艾";
    printf("\n");
    InserStaticLinkList(sllist, 1, element1);
    InserStaticLinkList(sllist, 2, element2);
    InserStaticLinkList(sllist, 3, element3);
    PrintStaticLinkList(sllist);
    printf("删除后为：\n");
    DelStaticLinkList(sllist, 1);
    PrintStaticLinkList(sllist);
}
//
void TestDoublyLinkList(void){
    DoublyLinkList * dlList = (DoublyLinkList *)malloc(sizeof(DoublyLinkList));
    dlList->length = 0;
    dlList->next = NULL;
    InserDoublyLinkList(dlList, 1, dataArray[0]);
    InserDoublyLinkList(dlList, 2, dataArray[1]);
    InserDoublyLinkList(dlList, 3, dataArray[2]);
    PrintDoublyLinkList(dlList);
    printf("\n");
    DelDoublyLinkList(dlList, 1);
    PrintDoublyLinkList(dlList);
}
//
void TestSeqStack(void){
    SeqStack * stack = (SeqStack *)malloc(sizeof(SeqStack));
    ElementType * element = (ElementType *)malloc(sizeof(ElementType));

    InitSeqStack(stack);        //不要忘记初始化
    for(int i = 0; i < 3; i++){
        printf("入栈元素为：%d\t%s\n", dataArray[i].id,dataArray[i].name);
        PushSeqStack(stack, dataArray[i]);
    }
    PopSeqStack(stack, element);
    printf("当前出栈元素为：%d\t%s\n", element->id,element->name);
    for(int i = 0; i < stack->length; i++){
        printf("元素为：%d\t%s\n", stack->elements[i].id,stack->elements[i].name);
    }

    free(stack);
}
//
void TestSeqQueue(void){
    SeqQueue queue;
    InitSeqQueue(&queue);
    OfferSeqQueue(&queue, dataArray[0]);
    OfferSeqQueue(&queue, dataArray[1]);
    OfferSeqQueue(&queue, dataArray[2]);
    for(int i = 0; i < queue.length; i++){
        printf("%d\t%s\n", queue.data[i].id,queue.data[i].name);
    }
    ElementType element;
    PollSeqQueue(&queue, &element);
    printf("当前出队元素：%d\t%s\n", element.id,element.name);
    printf("当前队列元素为：\n");
    for(int i = queue.front; i < queue.rear; i++){
        printf("%d\t%s\n", queue.data[i].id,queue.data[i].name);
    }
}











