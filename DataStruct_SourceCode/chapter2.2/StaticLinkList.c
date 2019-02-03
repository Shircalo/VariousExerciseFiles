#include "StaticLinkList.h"
//初始化
void InitStaticLinkList(StaticLinkList sllist)
{
    for(int i = 0; i < MAX_SIZE_SSL; i++)
    {
        sllist[i].data.id = -1;
        sllist[i].data.name = NULL;
        sllist[i].cursor = i + 1;
    }

    sllist[MAX_SIZE_SSL - 1].cursor = 0; //最后一个节点置空
    sllist[MAX_SIZE_SSL - 2].cursor = 0; //没有下一个元素
}
//打印cursor
void PrintStaticLinkList(StaticLinkList sllist)
{
    for(int i = 0; i < MAX_SIZE_SSL; i++)
    {
        printf("i:%d\tcursor:%d\tid:%d\t%s\n", i, sllist[i].cursor, sllist[i].data.id, sllist[i].data.name);
    }
}
/** 插入元素 */
int InserStaticLinkList(StaticLinkList sllist, int pos, ElementType element){
    if(pos < 1 || pos > GetStaticLinkList(sllist) + 1){
        return ERROR;
    }
    //获取第一个元素下标
    int cursor = MAX_SIZE_SSL - 1;
    //判断pos
    //分配内存
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
/** 分配内存 */
int mallocSSL(StaticLinkList sllist){
    int cursor = sllist[0].cursor;
    if(cursor){
        sllist[0].cursor = sllist[cursor].cursor;
    }
    return cursor;
}
/** 获取静态链表的长度 */
int GetStaticLinkList(StaticLinkList sllist){
    int count = 0;
    int cursor = sllist[MAX_SIZE_SSL - 1].cursor;

    while(cursor){
        cursor = sllist[cursor].cursor;
        count++;
    }
    return count;
}
/** 回收原始数组中指定下标的空间 */
void FreeStaticLinkListS(StaticLinkList sllist, int index){
    //将下标为index的空闲节点回收到备用链表
    sllist[index].cursor = sllist[0].cursor;
    //0号元素的cursor指向备用链表的第一个节点，表示index空闲
    sllist[0].cursor = index;
}
/** 删除表中指定位置的元素 */
void DelStaticLinkList(StaticLinkList sllist, int pos){
    if(pos < 1 || pos > GetStaticLinkList(sllist)){
        return;
    }

    int cursor = MAX_SIZE_SSL - 1;
    //找到前缀结点下标
    for(int i = 1; i <= pos - 1; i++){
        cursor = sllist[cursor].cursor;
    }
    //去除元素
    int delIndex = sllist[cursor].cursor;
    sllist[cursor].cursor = sllist[delIndex].cursor;
    //回收空间
    FreeStaticLinkListS(sllist, delIndex);
}
