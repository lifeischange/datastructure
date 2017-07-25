#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linked_list_array.h"

void InitializeCursorSpace(void){
	for(int i=0;i<SpaceSize;i++){
		CursorSpace[i].Next=(i+1)%SpaceSize; 
		}
	}

List MakeEmpty(List L){
	CursorSpace[L].Next=0;
	return L;
	}

int IsEmpty(const List L){
	return CursorSpace[L].Next==0; 
	}

int IsLast(const Position P,const List L){
	return CursorSpace[L].Element==CursorSpace[P].Element; 
	}

static Position CursorAlloc(void){
	Position P;
	P=CursorSpace[0].Next;
	CursorSpace[0].Next=CursorSpace[P].Next;
	return P;
	}

static void CursorFree(Position P){
	CursorSpace[P].Next=CursorSpace[0].Next;
	CursorSpace[0].Next=P; 
	}

Position Find(ElementType X,const List L){
	Position P;
	P=CursorSpace[L].Next;
	while(P && CursorSpace[P].Element!=X)
		P=CursorSpace[P].Next;
	return P;
		}

void Delete(ElementType X,List L){
	Position P,Temp;
	P=FindPrevious(X,L);
	if(!IsLast(P,L)){
		Temp=CursorSpace[P].Next; 
		CursorSpace[P].Next=CursorSpace[Temp].Next;
		CursorFree(Temp);
		
		}
	}
