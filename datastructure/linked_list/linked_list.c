#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "linked_list.h" 

List MakeEmpty(List L){
	L->Next=NULL;
	return L;
	}

int IsEmpty(List L){
	return L->Next==NULL;
	}

int IsLast(Position P,List L){
	while(L){
		if (L->Element==P->Element)
			return L->Next==NULL;
		L=L->Next;
		}
	printf("The Position is not in List.");
	exit(0);
	}

Position Find(ElementType X,List L){
	Position P=L->Next;
	while(P&&P->Element!=X)
		P=P->Next;
	return P;
	}

void Delete(ElementType X,List L){
	Position P,Q;
	Q=Find(X,L);
	P=FindPrevious(X,L);
	if(Q!=NULL)
		P->Next=Q->Next;
	free(Q);
	}

Position FindPrevious(ElementType X,List L){
	Position P=L;
	while(P->Next && P->Next->Element !=X)
		P=P->Next;
	return P;
	}

void Insert(ElementType X,List L){
	Position P,temp;
	temp=L;
	P=malloc(sizeof(struct Node));
	if(P==NULL)
		FatalError("No space.");
	P->Element=X;
	while(temp->Next)
		temp=temp->Next;
	temp->Next=P;
	}

void DeleteList(List L){
	Position P,temp;
	P=L->Next;
	L->Next=NULL;
	while(P!=NULL){
		temp=P;
		free(P);
		P=temp->Next;
		}
	}
