#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "AVLtree.h"

static int Height(AvlTree T);

static Position DoubleRotateWithRight(Position K3);
static Position SingleRotateWithLeft(Position K2);
AvlTree MakeEmpty(AvlTree T){
	if(T==NULL)
		return NULL;
	MakeEmpty(T->Left);
	MakeEmpty(T->Right);
	free(T);
	}

Position Find(ElementType X,AvlTree T){
	if(T){
		if(X>T->Element)
			return Find(X,T->Right);
		else
		if(X<T->Element)
			return Find(X,T->Left);
		}
	return T;
	}

Position FindMin(AvlTree T){
	if(T==NULL)
		return NULL;
	if(T->Left)
		return FindMin(T->Left);
	return T;
	}


Position FindMax(AvlTree T){
	if(T==NULL)
		return NULL;
	if(T->Right)
		return FindMax(T->Right);
	return T;
	}

AvlTree Insert(ElementType X,AvlTree T){
	if(T==NULL){
		printf("The is a empty tree.\n");
		Position T;
		T=malloc(sizeof(struct AvlTreeNode));
		if(T==NULL)
			return NULL;
		T->Height=0;
		T->Element=X;
		T->Left=T->Right=NULL;
		return T;
		}
	if(X>T->Element){
		T->Right=Insert(X,T->Right);
		if(Height(T->Right)-Height(T->Left)==2){
			if(X>T->Right->Element)
				T=SingleRotateWithRight(T);
			else
				T=DoubleRotateWithRight(T);
			}
		}
	else
		if(X<T->Element){
			T->Left=Insert(X,T->Left);
			if(Height(T->Left)-Height(T->Right)==2){
				if(X<T->Left->Element)
					T=SingleRotateWithLeft(T);
				else
					T=DoubleRotateWithLeft(T);
				}
		
		}
	T->Height=max(Height(T->Left),Height(T->Right))+1;
	return T;
	}

static int Height(AvlTree T){
	if(T)
		return T->Height;
	return -1;
	}

static Position SingleRotateWithLeft(Position K2){
	Position K;
	K=K2->Left;
	K2->Left=K->Right;
	K->Right=K2;
	K2->Height=max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=max(Height(K1->Left),Height(K1->Right))+1;
	return K2;
	}

static Position DoubleRotateWithRight(Position K3){
	
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
		}
