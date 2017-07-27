#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "tree.h"

SearchTree MakeEmpty(SearchTree T){
	if(!T){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
		}
	return NULL;
	}

Position Find(ElementType X,SearchTree T){
	if(T==NULL)
		return NULL;
	if(X>T->Element)
		return Find(X,T->Right);
	else if(X<T->Element)
		return Find(X,T->Left);
	else
		return T;
	}

Position FindMin(SearchTree T){
	if(T==NULL)
		return NULL;
	if(T->Left==NULL)
		return T;
	return FindMin(T->Left);
}


Position FindMax(SearchTree T){
	if(T->Right){
		while(T->Right){
			T=T->Right;
			}
		}
	return T;
	}

SearchTree Insert(ElementType X,SearchTree T){
	if(T==NULL){
		Position P;
		P=malloc(sizeof(struct TreeNode));
		if(P==NULL)
			printf("No Space.\n");
		else{
			P->Element=X;
			P->Left=P->Right=NULL;
			}
		}
	else
		if(X>T->Element)
			T->Right=Insert(X,T->Right);
	else
		if(X<T->Element)
			T->Left=Insert(X,T->Left);
	else
		return T;
	}

SearchTree Delete(ElementType X,SearchTree T){
	Position Temp;
	if(T==NULL){
		printf("The Tree is Empty.");
		return T;
		}
	if(X>T->Element)
		T->Right=Delete(X,T->Right);
	else
		if(X<T->Element)
		T->Left=Delete(X,T->Left);
	else{
		if(T->Left && T->Right){
			Temp=FindMax(T->Left);
			T->Element=Temp->Element;
			T->Left=Delete(Temp->Element,T->Left);
			}
		else
			if(T->Left){
				Temp=T;
				T=T->Left;}
		else
			if(T->Right){
				Temp=T;
				T=T->Right;}
		free(Temp);
		}
	return T;
		
	}


















