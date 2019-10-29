#include "pch.h"

//创建空的单链表
Status InItList(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (!L)
	{
		return error;
	}
	else
	{
		L->next = NULL;
		return OK;
	}
}

//向单链表输入元素
Status CreateList(LinkList &L,int Length){
	LinkList p;
	p = L;
	printf("请向单链表中输入元素并用空格隔开；  ");
	for (int i = 0; i < Length; i++)
	{
		L->next = (LNode*)malloc(sizeof(LNode));
		L = L->next;
		scanf("%d", &L->data);
	}
	L = p->next;
	printf("单链表中的元素为：  ");
	for (int i = 0; i < Length; i++)
	{
		printf("\t%d", L->data);
		L = L->next;
	}
	L = p;
	printf("\n");
	return OK;
}

//获取第i个元素
Status GetElem(LinkList L, int i, ElemType e) {
	LinkList p;
	int j;
	p = L->next;
	j = 1;//计数器
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return error;
	}
	else
	{
		e = p->data;
		printf("这是你想找的数：  %d", e);
		printf("\n");
		return OK;
	}
}

//向第i个位置添加元素e
Status ListInsert(LinkList &L, int i, ElemType e1) {
	LinkList p,s;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p||j>i-1)
	{
		return error;
	}
	s = (LNode*)malloc(sizeof(LNode));
	s->data = e1;
	s->next = p->next;
	p->next = s;
	return OK; 
}

int main() {
	LinkList L;
	int Length;
	int i, e = 0;//元素的获取
	InItList(L);
	printf("请输入你想向单链表中输入元素的个数；  ");
	scanf("%d", &Length);
	CreateList(L, Length);
	printf("**********************单链表中元素查找******************\n");
	printf("请输入你想找的位置：  ");
	scanf("%d", &i);
	GetElem(L, i, e);
}