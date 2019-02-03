#ifndef STATICLINKLIST_H_INCLUDED
#define STATICLINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

#define MAX_SIZE_SSL 10
#define OK 1
#define ERROR 0
#define OK 1

/********************************************************
*��̬������ʵ�ʿ������õ��٣�ֻ��Ϊ����û��ָ��������
*ģ��
*********************************************************/

typedef struct {
    ElementType data;
    int cursor;
}StaticLinkList[MAX_SIZE_SSL];
//��ʼ��
void InitStaticLinkList(StaticLinkList sllist);
//��ӡcursor
void PrintStaticLinkList(StaticLinkList sllist);
/** ����Ԫ�� */
int InserStaticLinkList(StaticLinkList sllist, int pos, ElementType element);
/** �����ڴ� */
int mallocSSL(StaticLinkList sllist);
/** ��ȡ��̬����ĳ��� */
int GetStaticLinkList(StaticLinkList sllist);
/** ����ԭʼ������ָ���±�Ŀռ� */
void FreeStaticLinkListS(StaticLinkList sllist, int index);
/** ɾ������ָ��λ�õ�Ԫ�� */
void DelStaticLinkList(StaticLinkList sllist, int pos);

#endif // STATICLINKLIST_H_INCLUDED
