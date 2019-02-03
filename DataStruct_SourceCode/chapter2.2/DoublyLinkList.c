#ifndef DOUBLYLINKLIST_C_INCLUDED
#define DOUBLYLINKLIST_C_INCLUDED
#include "DoublyLinkList.h"

/** 向双向链表的指定位置插入元素 */
void InserDoublyLinkList(DoublyLinkList * dlList, int pos, ElementType element){
    DoublyNode * node = (DoublyNode *)malloc(sizeof(DoublyNode));
    node->data = element;
    node->next = NULL;
    node->prev = NULL;
    if(1 == pos){
        //需要判断插入的位置和链表长度
        if(0 == dlList->length){
            dlList->next = node;
            dlList->length++;
            return;
        }
        node->next = dlList->next;
        dlList->next = node;
        node->next->prev = node;
        dlList->length++;
        return;
    }
    DoublyNode * currNode = dlList->next;
    for(int i = 1; currNode && i < pos - 1; i++){
        currNode = currNode->next;
    }
    if(currNode){
        node->prev = currNode;
        if(currNode->next){
            currNode->next->prev = node;
        }
        node->next = currNode->next;
        currNode->next = node;
        dlList->length++; //记住每次插入后长度加一
    }
}
/** 打印链表 */
void PrintDoublyLinkList(DoublyLinkList * dlList){
    DoublyNode * node = dlList->next;
    if(!node || 0 == dlList->length){
        dlList->length = 0;
        return;
    }
    for(int i = 0; i < dlList->length; i++){
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}
/** 删除指定位置元素 */
ElementType DelDoublyLinkList(DoublyLinkList * dlList, int pos){
    ElementType element;
    element.id = -99;
    if(1 == pos){
        DoublyNode * node = dlList->next;
        element = dlList->next->data;
        dlList->next = node->next;
        if(dlList->next){
            dlList->next->prev = NULL;
        }
        free(node);
        dlList->length--;
        return element;
    }
    DoublyNode * node = dlList->next;
    for(int i = 1; node && i < pos - 1; i++){
        node = node->next;
    }
    if(node){
        element = node->data;
        if(node->next){
            node->next->prev = node->prev;
        }
        node->prev->next = node->next;
        free(node);
        dlList->length--;
    }
    return element;
}
/** 根据指定位置查找元素 */
ElementType GetDoublyLinkListElement(DoublyLinkList * dlList, int pos){
    DoublyNode * node = dlList->next;
    for(int i = 1; node && i < pos - 1; i++){
        node = node->next;
    }
    return node->data;
}

#endif // DOUBLYLINKLIST_C_INCLUDED
