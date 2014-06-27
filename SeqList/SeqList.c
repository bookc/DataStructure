#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

//注意在SeqList.h文件中定义的是SeqList类型和SeqListNode类型。而自定义的是TSeqList类型和TSeqListNode类型
//这正是封装性的表现

typedef unsigned int TSeqListNode; //这里unsigned int 类型是为了存储数据的地址（指针）。因为在32位操作系统中任何指针都是4个字节，而unsigned int 正好是占4个字节。同理在64位中可以用unsigned long

typedef struct _tag_SeqList  //习惯性下划线_开头
{
    int capacity;
    int length;
    TSeqListNode* node; //node数组中存放地址
} TSeqList;

SeqList* SeqList_Create(int capacity) // O(1)
{
    TSeqList* ret = NULL;
    
    if( capacity >= 0 )
    {
        ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity); //这里一次性申请了TSeqList指针和TSeqListNode型node数组所占的字节
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode*)(ret + 1); // (ret + 1)跳过一个(TSeqList)大小，正好是node数组的开始地址
    }
    
    return ret; //这里返回的是TSeqList*，而不是函数中要求的SeqList*，因为其相当于void*，而void*可以指向任何类型的指针
}

void SeqList_Destroy(SeqList* list) // O(1)
{
    free(list); //在SeqList_Create函数中只申请了一次内存空间，所以这里只需释放一次
}

void SeqList_Clear(SeqList* list) // O(1)
{
    TSeqList* sList = (TSeqList*)list; //显示转化指针类型
    
    if( sList != NULL )
    {
        sList->length = 0;
    }
}

int SeqList_Length(SeqList* list) // O(1)
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->length;
    }
    
    return ret;
}

int SeqList_Capacity(SeqList* list) // O(1)
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->capacity;
    }
    
    return ret;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) // O(n) 
{
    TSeqList* sList = (TSeqList*)list;
    int ret = (sList != NULL);
    int i = 0;
    
    ret = ret && (sList->length + 1 <= sList->capacity);
    ret = ret && (0 <= pos);
    
	//ret存储上面条件判断的结果，非0即1
    if( ret )
    {
        if( pos >= sList->length )
        {
            pos = sList->length;
        }
        
        for(i=sList->length; i>pos; i--)
        {
            sList->node[i] = sList->node[i-1];
        }
        
        sList->node[i] = (TSeqListNode)node; //存储地址
        
        sList->length++;
    }
    
    return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) // O(1) 
{
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = NULL;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
        ret = (SeqListNode*)(sList->node[pos]);
    }
    
    return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) // O(n)
{
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = SeqList_Get(list, pos);
    int i = 0;
    
    if( ret != NULL )
    {
        for(i=pos+1; i<sList->length; i++)
        {
            sList->node[i-1] = sList->node[i];
        }
        
        sList->length--;
    }
    
    return ret;
}
