#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList; //ע��������void���ͣ�֮���Զ���void���ͣ���Ϊ�����ӷ�װ�ԡ���Դ�.h�ļ��������ò�ͬ��.c�ļ�ʵ�֡���Ҫ������void��ָ������á�
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);

void SeqList_Destroy(SeqList* list);

void SeqList_Clear(SeqList* list);

int SeqList_Length(SeqList* list);

int SeqList_Capacity(SeqList* list);

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

SeqListNode* SeqList_Get(SeqList* list, int pos);

SeqListNode* SeqList_Delete(SeqList* list, int pos);

#endif

