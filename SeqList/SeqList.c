#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

//ע����SeqList.h�ļ��ж������SeqList���ͺ�SeqListNode���͡����Զ������TSeqList���ͺ�TSeqListNode����
//�����Ƿ�װ�Եı���

typedef unsigned int TSeqListNode; //����unsigned int ������Ϊ�˴洢���ݵĵ�ַ��ָ�룩����Ϊ��32λ����ϵͳ���κ�ָ�붼��4���ֽڣ���unsigned int ������ռ4���ֽڡ�ͬ����64λ�п�����unsigned long

typedef struct _tag_SeqList  //ϰ�����»���_��ͷ
{
    int capacity;
    int length;
    TSeqListNode* node; //node�����д�ŵ�ַ
} TSeqList;

SeqList* SeqList_Create(int capacity) // O(1)
{
    TSeqList* ret = NULL;
    
    if( capacity >= 0 )
    {
        ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity); //����һ����������TSeqListָ���TSeqListNode��node������ռ���ֽ�
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode*)(ret + 1); // (ret + 1)����һ��(TSeqList)��С��������node����Ŀ�ʼ��ַ
    }
    
    return ret; //���ﷵ�ص���TSeqList*�������Ǻ�����Ҫ���SeqList*����Ϊ���൱��void*����void*����ָ���κ����͵�ָ��
}

void SeqList_Destroy(SeqList* list) // O(1)
{
    free(list); //��SeqList_Create������ֻ������һ���ڴ�ռ䣬��������ֻ���ͷ�һ��
}

void SeqList_Clear(SeqList* list) // O(1)
{
    TSeqList* sList = (TSeqList*)list; //��ʾת��ָ������
    
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
    
	//ret�洢���������жϵĽ������0��1
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
        
        sList->node[i] = (TSeqListNode)node; //�洢��ַ
        
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
