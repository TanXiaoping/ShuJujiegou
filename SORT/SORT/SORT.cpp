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
void PutInList(SqList &L, int length) {
	printf("请入你要输入的元素并用空格隔开;  ");
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &L.elem[i]);
	}
	printf("你输入的元素如下；  ");
	for (int i = 0; i < length; i++)
	{
		printf("\t%d", L.elem[i]);
	}
	printf("\n");
}

//冒泡排序
void bubbleSort(SqList &L) {
	int temp;
	for (int i = 0; i < L.length; i++)
	{
		for (int j = i; j < L.length-1; j++)
		{
			if (L.elem[j] > L.elem[j+1])
			{
				temp = L.elem[j + 1];
				L.elem[j + 1] = L.elem[j];
				L.elem[j] = temp;
			}
		}
	}
	printf("由冒泡排序后的线性表");
	for (int i = 0; i < L.length; i++)
	{
		printf("\t%d", L.elem[i]);
	}
	printf("\n");
}

//选择排序
void selectionSort(SqList &L) {
	int temp;
	for (int i = 0; i < L.length-1; i++)
	{
		int minElem = i;
		for (int j=i+1;  j< L.length ;j++)
		{
			minElem = L.elem[i] > L.elem[j] ? j : i;
		}
		temp = L.elem[i];
		L.elem[i] = L.elem[minElem];
		L.elem[minElem] = temp;
	}
	printf("由选择排序后的线性表");
	for (int i = 0; i < L.length; i++)
	{
		printf("\t%d", L.elem[i]);
	}
	printf("\n");
}

//快速排序


int main() {
	SqList L;
	int length;
	InitList(L);
	printf("请输入要输入元素的个数;  ");
	scanf("%d", &length);
	PutInList(L, length);
	L.length = length;
	bubbleSort(L);
	selectionSort(L);
	return 0;
}