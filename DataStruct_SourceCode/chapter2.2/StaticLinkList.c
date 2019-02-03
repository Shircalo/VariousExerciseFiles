#include "StaticLinkList.h"
//��ʼ��
void InitStaticLinkList(StaticLinkList sllist)
{
    for(int i = 0; i < MAX_SIZE_SSL; i++)
    {
        sllist[i].data.id = -1;
        sllist[i].data.name = NULL;
        sllist[i].cursor = i + 1;
    }

    sllist[MAX_SIZE_SSL - 1].cursor = 0; //���һ���ڵ��ÿ�
    sllist[MAX_SIZE_SSL - 2].cursor = 0; //û����һ��Ԫ��
}
//��ӡcursor
void PrintStaticLinkList(StaticLinkList sllist)
{
    for(int i = 0; i < MAX_SIZE_SSL; i++)
    {
        printf("i:%d\tcursor:%d\tid:%d\t%s\n", i, sllist[i].cursor, sllist[i].data.id, sllist[i].data.name);
    }
}
/** ����Ԫ�� */
int InserStaticLinkList(StaticLinkList sllist, int pos, ElementType element){
    if(pos < 1 || pos > GetStaticLinkList(sllist) + 1){
        return ERROR;
    }
    //��ȡ��һ��Ԫ���±�
    int cursor = MAX_SIZE_SSL - 1;
    //�ж�pos
    //�����ڴ�
    int newIndex = mallocSSL(sllist);

    if(newIndex){
        sllist[newIndex].data = element;
        for(int i = 1; i <= pos - 1; i++){
            cursor = sllist[cursor].cursor;
        }
        sllist[newIndex].cursor = sllist[cursor].cursor;
        sllist[cursor].cursor = newIndex;
        return OK;
    }
    return ERROR;
}
/** �����ڴ� */
int mallocSSL(StaticLinkList sllist){
    int cursor = sllist[0].cursor;
    if(cursor){
        sllist[0].cursor = sllist[cursor].cursor;
    }
    return cursor;
}
/** ��ȡ��̬����ĳ��� */
int GetStaticLinkList(StaticLinkList sllist){
    int count = 0;
    int cursor = sllist[MAX_SIZE_SSL - 1].cursor;

    while(cursor){
        cursor = sllist[cursor].cursor;
        count++;
    }
    return count;
}
/** ����ԭʼ������ָ���±�Ŀռ� */
void FreeStaticLinkListS(StaticLinkList sllist, int index){
    //���±�Ϊindex�Ŀ��нڵ���յ���������
    sllist[index].cursor = sllist[0].cursor;
    //0��Ԫ�ص�cursorָ��������ĵ�һ���ڵ㣬��ʾindex����
    sllist[0].cursor = index;
}
/** ɾ������ָ��λ�õ�Ԫ�� */
void DelStaticLinkList(StaticLinkList sllist, int pos){
    if(pos < 1 || pos > GetStaticLinkList(sllist)){
        return;
    }

    int cursor = MAX_SIZE_SSL - 1;
    //�ҵ�ǰ׺����±�
    for(int i = 1; i <= pos - 1; i++){
        cursor = sllist[cursor].cursor;
    }
    //ȥ��Ԫ��
    int delIndex = sllist[cursor].cursor;
    sllist[cursor].cursor = sllist[delIndex].cursor;
    //���տռ�
    FreeStaticLinkListS(sllist, delIndex);
}
