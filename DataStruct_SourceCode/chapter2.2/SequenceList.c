#include "SequenceList.h"

//初始化顺序表
void InitList(SeqList * sequence, ElementType * elementarray, int length)
{
    if(length > MAX_SIZE)
    {
        printf("超出数组最大容量，初始化失败！");
        return;
    }
    sequence->length = 0;
    for(int i = 0; i < length; i++)
    {
        InsertElement(sequence, i, elementarray[i]);
    }
}
//向顺序表的indes下标处插入某个元素
void InsertElement(SeqList * sequence, int index, ElementType element)
{
    if(sequence->length + 1 >= MAX_SIZE)
    {
        printf("只能在允许的下标范围内插入元素[0, %d]\n", MAX_SIZE - 1);
        return;
    }
    if(index < 0 || index > sequence->length)
    {
        printf("插入的下标超过了数组的最大长度，插入失败！\n");
        return;
    }
    for(int i = sequence->length - 1; i >= index; i--)
    {
        sequence->datas[i + 1] =  sequence->datas[i];
    }
    sequence->datas[index] = element;
    sequence->length++;
}
//打印顺序表
void PrintList(SeqList * sequence)
{
    for(int i = 0; i < sequence->length; i++)
    {
        printf("%d\t%s\n",sequence->datas[i].id, sequence->datas[i].name);
    }
    return;
}
//删除元素
ElementType * DelElement(SeqList * sequence, int index)
{
    if(index < 0 || index > sequence->length)
    {
        printf("删除失败！\n");
        return NULL;
    }
    ElementType * element = (ElementType *)malloc(sizeof(ElementType));
    *element = *GetElement(sequence, index);
    for(int i = index; i < sequence->length - 1; i++)
    {
        sequence->datas[i] = sequence->datas[i + 1];
    }
    sequence->length--;
    return element;
}
//查找元素
ElementType * GetElement(SeqList * sequence, int index)
{
    if(index < 0 || index > sequence->length)
    {
        printf("删除失败！\n");
        return NULL;
    }
    ElementType * element;
    element = &sequence->datas[index];
    return element;
}
//获取长度
int GetLength(SeqList * sequence)
{
    if(sequence == NULL)
        return 0;
    return sequence->length;
}
//清空顺序表
void ClearList(SeqList * sequence)
{
    if(sequence == NULL)return;
    sequence->length = 0;
}
//是否为空
int IsEmpty(SeqList * sequence)
{
    return GetLength(sequence) ? TRUE : FALSE;
}












