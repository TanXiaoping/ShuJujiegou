#ifndef PCH_H
#define PCH_H

#include<stdio.h>
#include"malloc.h"
#include<stdlib.h>

#define LIST_INIT_SIZZE 100
#define LISTINCREMENT 10
#define error 0
#define ture 1
#define OK 1
#define OVERFLOW 0 

typedef int ElemType;
typedef int status;

typedef struct LNode {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

#endif 
