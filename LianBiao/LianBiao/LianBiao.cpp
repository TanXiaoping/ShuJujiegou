//*****************线性表中元素的增添与删除**************
#include"pch.h"
//构造一个空的线性表L
status InitList(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZZE;
	return OK;
}

//向线性表中输入元素
void PutInList(SqList &L,int length) {
	printf("请入你要输入的元素并用空格隔开;  ");
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &L.elem[i]);
	}
	printf("你输入的元素如下；  ");
	for (int i = 0; i < length; i++)
	{
		printf("\t%d",L.elem[i]);
	}
	printf("\n");
}

//将元素e插入到位置i
status ListInsert(SqList &L, int i,ElemType e){
	int *q;
	int *p;
	if (i<0 || i>L.length + 1) {
		return error;
	}
	if(L.length>=L.listsize){
		ElemType *newbase;
		newbase = (ElemType*)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LIST_INIT_SIZZE;
	}
	if (i <= L.length + 1)
	{
		q = &(L.elem[i - 1]);
		for (p = &(L.elem[L.length - 1]); p >= q; --p)
			*(p + 1) = *p;
		*q = e;
		++L.length;
		printf("输出插入后的元素");
		for (int i = 0; i < L.length; i++)
		{
			printf("\t%d", L.elem[i]);
		}
		printf("\n");
	}
	return OK;
}

//将线性表中第i个元素删除
status ListDelete(SqList &L,int i) {
	int *a;
	if (i > L.length)
		return error;
	if (i < L.length) {
		for (a = &L.elem[i - 1]; a < &L.elem[L.length - 1]; a++)
			*a = *(a + 1);
		L.length--;
		printf("删除后的线性表;  ");
		for (int k = 0; k < L.length; k++)
		{
			printf("\t%d",L.elem[k]);
		}
		printf("\n");
	}
	return OK;
}

//从线性表中获取第几个元素
status GetElem(SqList &L,int i) {
	int ai;
	ai = L.elem[i-1];
	return ai;
}

//将两个线性表进行合并并排序
status ListCombine(SqList &La,SqList &Lb,SqList &Lc) {
	InitList(Lc);
	int ai, bj;
	int i = 1, j = 1;
	int k = 0;

	while ((i<=La.length)&&(j<=La.length))
	{
		ai = GetElem(La, i);
		bj = GetElem(Lb, j);
		printf("获取的元素是：   %d", ai);
		if (ai <= bj) {
			ListInsert(Lc, ++k, ai);
			++i;
		}
		else {
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}
	while (i<=La.length)
	{
		ai = GetElem(La, i++);
		ListInsert(Lc, ++k, ai);
	}
	while (j<=Lb.length)
	{
		bj = GetElem(Lb, j++);
		ListInsert(Lc, ++k , bj);
	}
	printf("线性表Lc的元素为；  ");
	for (int n = 0; n < Lc.length; n++)
	{
		printf("%d", Lc.elem[n]);
	}
	return OK;
}

int main()
{
	int ai,i, e, length, Delete;
	int La_len, Lb_len;
	SqList L, La, Lb, Lc;//新建一个线性表
	InitList(L);
	printf("请输入要输入元素的个数;  ");
	scanf("%d", &length);
	PutInList(L, length);
	L.length = length;
	printf("请输入要插入元素;  ");
	scanf("%d", &e);
	printf("请输入要插入元素的位置;  ");
	scanf("%d", &i);
	ListInsert(L, i, e);
	printf("请输入想要删除元素的位置;  ");
	scanf("%d", &Delete);
	ListDelete(L, Delete);
	printf("**********下面进行线性表的合并*********\n");
	InitList(La);
	printf("请输入你想要在La线性表中输入元素的个数：  ");
	scanf("%d", &La_len);
	PutInList(L, La_len);
	La.length = La_len;
	InitList(Lb);
	printf("请输入你想要在Lb线性表中输入元素的个数：  ");
	scanf("%d", &Lb_len);
	PutInList(L, Lb_len);
	Lb.length = Lb_len;
	ListCombine(La, Lb, Lc);
}