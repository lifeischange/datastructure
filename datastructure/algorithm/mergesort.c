#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void merger(Type A[],Type Tmp[],int Left,int certer,int Right){
	int Rpos,Lpos;
	int nums;
	nums=Right-Left+1;
	Rpos=certer+1;
	Lpos=Left;
	while(Lpos<=certer && Rpos<=Right){
		if(A[Lpos]>A[Rpos])
			Tmp[Left++]=A[Rpos++];
		else
			Tmp[Left++]=A[Lpos++];
			}
	while(Lpos<=certer)
		Tmp[Left++]=A[Lpos++];
	while(Rpos<=Right)
		Tmp[Left++]=A[Rpos++];
	for(int i=0;i<nums;i++,Right--){
		A[Right]=Tmp[Right];  
		}
	}


void merge(Type A[],Type Tmp[],int Left,int Right){
	int certer;
	if(Left<Right){
	certer=(Left+Right)/2;
	merge(A,Tmp,Left,certer);
	merge(A,Tmp,certer+1,Right);
	merger(A,Tmp,Left,certer,Right);
		}
	}


void mergesort(Type A[],int N){
	Type *Tmp;
	Tmp=malloc(N*sizeof(Type));
	if(Tmp==NULL)
		error("there is no space,");
	merge(A,Tmp,0,N-1);
	free(Tmp);
	}
