#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0

//����Ԫ��
typedef struct{
    int id;
    char * name;
}ElementType;
//˳���ṹ
typedef struct{
    ElementType datas[MAX_SIZE];
    int length;
}SeqList;


#endif // DATAELEMENT_H_INCLUDED
