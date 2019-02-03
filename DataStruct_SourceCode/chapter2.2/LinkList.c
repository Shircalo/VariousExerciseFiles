#include "LinkList.h"
//����ڵ�
void InsertLinkList(LinkList * linklist, int pos, ElementType element)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;

    if(pos == 1)
    {
        node->next = linklist->next;
        linklist->next = node;
        linklist->length++;
        return;
    }
    Node * currnode = linklist->next;
    for(int i = 1; currnode && i < pos - 1; i++)
    {
        currnode = currnode->next;
    }

    if(currnode)
    {
        node->next = currnode->next;
        currnode->next = node;
        linklist->length++;
    }
}
//��ʼ������
void InitLinkList(LinkList * linklist, ElementType * dataArray, int length)
{
    for(int i = 0; i < length; i++)
    {
        InsertLinkList(linklist, i + 1, dataArray[i]);
    }
}
//��ӡ����
void PrintLinkList(LinkList * linklist)
{
    Node * node = linklist->next;
    if(!node)
    {
        printf("����Ϊ��\n");
        linklist->length = 0;
        return;
    }
    for(int i = 0; i < linklist->length; i++)
    {
        printf("%d\t%s\n",node->data.id, node->data.name);
        node = node->next;
    }
}
//�Ƿ�Ϊ��
int IsLinkListEmpty(LinkList * linklist)
{
    return linklist->length ? FALSE : TRUE;
}
//��ȡԪ��
ElementType GetLinkListElement(LinkList * linklist, int pos)
{
    Node * node = linklist->next;
    for(int i = 1; node && i < pos; i++)
    {
        node = node->next;
    }
    return node->data;
}
//ɾ���ڵ�
ElementType DelLinkListElement(LinkList * linklist, int pos)
{
    ElementType element;
    element.id = -99;
    Node * node = NULL;

    if(pos == 1)
    {
        node = linklist->next;
        if(node)
        {
            element = node->data;
            linklist->next = node->next;
            free(node);
            linklist->length--;
        }
        return element;
    }

    Node * prenode = NULL;
    node = linklist->next;
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
        linklist->length--;
    }
    return element;
}
//��սڵ�
void ClearLinkList(LinkList * linklist)
{
    Node * node = linklist->next;
    Node * nextnode = NULL;

    while(node)
    {
        nextnode = node->next;
        free(node);
        node = nextnode;
    }

    linklist->next = NULL;
    linklist->length = 0;
}










