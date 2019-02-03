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
    {1,"����"},
    {2,"�Ķ�"},
    {3,"���尬"}

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
    element1.name = "����";
    element2.id = 2;
    element2.name = "�Ķ�";
    element3.id = 3;
    element3.name = "���尬";
    printf("\n");
    InserStaticLinkList(sllist, 1, element1);
    InserStaticLinkList(sllist, 2, element2);
    InserStaticLinkList(sllist, 3, element3);
    PrintStaticLinkList(sllist);
    printf("ɾ����Ϊ��\n");
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

    InitSeqStack(stack);        //��Ҫ���ǳ�ʼ��
    for(int i = 0; i < 3; i++){
        printf("��ջԪ��Ϊ��%d\t%s\n", dataArray[i].id,dataArray[i].name);
        PushSeqStack(stack, dataArray[i]);
    }
    PopSeqStack(stack, element);
    printf("��ǰ��ջԪ��Ϊ��%d\t%s\n", element->id,element->name);
    for(int i = 0; i < stack->length; i++){
        printf("Ԫ��Ϊ��%d\t%s\n", stack->elements[i].id,stack->elements[i].name);
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
    printf("��ǰ����Ԫ�أ�%d\t%s\n", element.id,element.name);
    printf("��ǰ����Ԫ��Ϊ��\n");
    for(int i = queue.front; i < queue.rear; i++){
        printf("%d\t%s\n", queue.data[i].id,queue.data[i].name);
    }
}











