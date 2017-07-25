#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "linked_list.h" 

#define FatalError printf
void main(void){
	printf("begin:\n");
	Position time,k;
	time=malloc(sizeof(struct Node));
	if(time==NULL)
		printf("Out of space.");
	for(int i=0;i<5;i++){
		Insert(i,time);
		}
	DeleteList(time);
	k=time->Next;
	while(k){
		printf("%d  %p  %p  %p\n",k->Element,k,&k,k->Next);
		k=k->Next;
		}
	
	}
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
	Position P,temp,Head;
	P=malloc(sizeof(struct Node));
	if(P==NULL)
		FatalError("No space.");
	P->Element=X;
	temp=L;
	while(temp->Next)
		temp=temp->Next;
	temp->Next=P;
	printf("%d\n",P->Element);
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
