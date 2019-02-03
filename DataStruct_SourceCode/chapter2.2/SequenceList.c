#include "SequenceList.h"

//��ʼ��˳���
void InitList(SeqList * sequence, ElementType * elementarray, int length)
{
    if(length > MAX_SIZE)
    {
        printf("�������������������ʼ��ʧ�ܣ�");
        return;
    }
    sequence->length = 0;
    for(int i = 0; i < length; i++)
    {
        InsertElement(sequence, i, elementarray[i]);
    }
}
//��˳����indes�±괦����ĳ��Ԫ��
void InsertElement(SeqList * sequence, int index, ElementType element)
{
    if(sequence->length + 1 >= MAX_SIZE)
    {
        printf("ֻ����������±귶Χ�ڲ���Ԫ��[0, %d]\n", MAX_SIZE - 1);
        return;
    }
    if(index < 0 || index > sequence->length)
    {
        printf("������±곬�����������󳤶ȣ�����ʧ�ܣ�\n");
        return;
    }
    for(int i = sequence->length - 1; i >= index; i--)
    {
        sequence->datas[i + 1] =  sequence->datas[i];
    }
    sequence->datas[index] = element;
    sequence->length++;
}
//��ӡ˳���
void PrintList(SeqList * sequence)
{
    for(int i = 0; i < sequence->length; i++)
    {
        printf("%d\t%s\n",sequence->datas[i].id, sequence->datas[i].name);
    }
    return;
}
//ɾ��Ԫ��
ElementType * DelElement(SeqList * sequence, int index)
{
    if(index < 0 || index > sequence->length)
    {
        printf("ɾ��ʧ�ܣ�\n");
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
//����Ԫ��
ElementType * GetElement(SeqList * sequence, int index)
{
    if(index < 0 || index > sequence->length)
    {
        printf("ɾ��ʧ�ܣ�\n");
        return NULL;
    }
    ElementType * element;
    element = &sequence->datas[index];
    return element;
}
//��ȡ����
int GetLength(SeqList * sequence)
{
    if(sequence == NULL)
        return 0;
    return sequence->length;
}
//���˳���
void ClearList(SeqList * sequence)
{
    if(sequence == NULL)return;
    sequence->length = 0;
}
//�Ƿ�Ϊ��
int IsEmpty(SeqList * sequence)
{
    return GetLength(sequence) ? TRUE : FALSE;
}












