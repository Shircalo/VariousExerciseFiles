#include "CircularLinkList.h"

//插入元素
void InsertCircularListEle(CircularList * cllist, ElementType element, int pos)
{
    CircularNode * node = (CircularNode *)malloc(sizeof(CircularNode));
    node->data = element;
    node->next = NULL;

    if(pos == 1)
    {
        node->next = cllist->next;
        if(!node->next)
        {
            cllist->next = node;
            node->next = node;
            cllist->length++;
            return;
        }
        CircularNode * lastnode = cllist->next;
        for(int i = 1; i < cllist->length; i++)
        {
            lastnode = lastnode->next;
        }
        lastnode->next = node;
        cllist->next = node;
        cllist->length++;
        return;
    }

    CircularNode * currnode = cllist->next;
    for(int i = 1; currnode && i < pos - 1; i++)
    {
        currnode = currnode->next;
    }
    if(currnode)
    {
        node->next = currnode->next;
        currnode->next = node;
        cllist->length++;
        return;
    }
    cllist->next = node;
    node->next = node;
    cllist->length++;
}
//打印
void PrintCircularLinkList(CircularList * cllist)
{
    if((cllist->length == 0) || !cllist->next)
    {
        printf("链表为空\n");
        return;
    }
    CircularNode * node = cllist->next;
    for(int i = 1; i < cllist->length + 1; i++)
    {
        printf("%d\t%s\n",node->data.id, node->data.name);
        node = node->next;
    }
}
//初始化
void InitCircularLinkList(CircularList * cllist, ElementType * dataArray, int length)
{
    for(int i = 1; i < length + 1; i++)
    {
        InsertCircularListEle(cllist, dataArray[i - 1], i);
    }
}
//删除
ElementType DeleteCircularList(CircularList * cllist, int pos)
{
    ElementType element;
    element.id = -99;
    if(pos == 1)
    {
        CircularNode * node = cllist->next;
        if(node)
        {
            element = node->data;
            CircularNode * lastnode = cllist->next;
            for(int i = 1; i < cllist->length; i++)
            {
                lastnode = lastnode->next;
            }
            cllist->next = node->next;
            lastnode->next = cllist->next;
            free(node);
            cllist->length--;
        }
        return element;
    }

    CircularNode * prenode = NULL;
    CircularNode * node = cllist->next;
    for(int i = 1; node && i < pos; i++)
    {
        prenode = node;
        node = node->next;
    }
    if(node)
    {
        element = node->data;
        prenode->next = node->next;
        free(node);
        cllist->length--;
    }
    return element;
}
//获取节点指针
CircularNode * GetCircularListNode(CircularList * cllist, ElementType element)
{
    CircularNode * node = cllist->next;
    if(!node)return NULL;

    do{
        if((node->data.id == element.id) && (strcmp(node->data.name, element.name) == 0))
        {
            return node;
        }
        node = node->next;
    }while(node != cllist->next);
    return NULL;
}
//从node开始打印
void PrinCircularListNode(CircularList * cllist, CircularNode * node)
{
    if(cllist->next == NULL || node == NULL)return;

    CircularNode * orinode = node;
    do{
        printf("%d\t%s\n",node->data.id,node->data.name);
        node = node->next;
    }while(node != orinode);
}






