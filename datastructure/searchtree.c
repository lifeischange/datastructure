#include<stdio.h>
#include<stdlib.h>
#include<string.h>

SearchTree MakeEmpty(SearchTree T){//这是销毁树，不是清空。
	if(T!=NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
		}
	return NULL;
	}

Position Find(ElementType X,SearchTree T){
	
	if(T!=NULL){
		if(X==T->Element)
			return T;
		else if(X<T->Element)
			return Find(X,T->Left);
		else
			return Find(X,T->Right);
		}
	return NULL;
	}

Position FindMin(SearchTree T){
	if(T==NULL)
		return NULL;
	else if(T->Left==NULL)
		return T;
	else
		return FindMin(T->Left);
	}

Position FindMax(SearchTree T){
	Position P;
	P=T;
	if(T==NULL)
		return NULL;
	while(P->Right!=NULL)
		P=P->Right;
	return P;
	}

SearchTree Insert(ElementType X,SearchTree T){
		if(T==NULL){
			T=malloc(sizeof(struct TreeToNode));
			if(T==NULL){
				FatalError("Out of space.");
				}
			T->Right=NULL;
			T->Left=NULL;
			T->Element=X;
			}
		else
		if(T->Element>X){
		T->Left=Insert(X,T->Left);
			}
		else
		if(T->Element<X){
			T->Right=Insert(X,T->Right);
			}
		return T;
	}

SearchTree Delete(ElementType X,SearchTree T){
	Position P;
	P=Find(X,T);
	if(P!=NULL){
		if(P->Left==NULL && P->Right==NULL)
			MakeEmpty(P);
		else
		if()
		}
	return T;
	}
