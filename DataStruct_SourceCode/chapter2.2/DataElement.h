#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0

//数据元素
typedef struct{
    int id;
    char * name;
}ElementType;
//顺序表结构
typedef struct{
    ElementType datas[MAX_SIZE];
    int length;
}SeqList;


#endif // DATAELEMENT_H_INCLUDED
