#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define LeftChild(x) (2*(x)+1)

void PercDown(Type A[],int i,int N){
	Type Tmp;
	int child;
	Tmp=A[i]; 
	for(child=LeftChild(i);LeftChild(i)<N;i=child){
		if(child!=N-1 && A[child+1]>A[child])
			child++;
		if(A[child]>Tmp)
			A[i]=A[child];  
		else
			break;
		A[child]=T 
		}
	A[i]=Tmp; 
	}

void heapsort1(Type A[],int N){
	int i;
	for(i=N/2;i>=0;i--)
		PercDown(A,i,N);
	for(i=N-1;i>0;i--){
		Swap(&A[0],&A[i]);
		PercDown(A,0,i);
		}
	
	}
