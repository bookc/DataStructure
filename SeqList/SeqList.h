#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList; //注意这里是void类型，之所以定义void类型，是为了增加封装性。针对此.h文件，可以用不同的.c文件实现。主要利用了void型指针的作用。
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

