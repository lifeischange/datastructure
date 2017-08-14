#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define offset 3

Type median(Type A[],int Left,int Right){
		int certer;
		certer=(Left+Right)/2;
		if(A[Left]>A[Right])
			Swap(&A[Left],&A[Right]);
		if(A[Left]>A[certer])
			Swap(&A[Left],&A[certer]);
		if(A[certer]>A[Right])
			Swap(&A[certer],&A[Right]);
		
		Swap(&A[certer],&A[Right-1]);
		return A[Right-1]; 
	}

void quicksort(Type A[],int Left,int Right){
	Type Tmp;
	int i,j;
	if(Left+offset<=Right){
	Tmp=median(A,Left,Right);
	i=Left;
	j=Right-1;
	for(;;){
	while(A[++i]<Tmp){}
	while(A[--j]>Tmp){}
	if(i<j)
		Swap(&A[i],&A[j]);
	else
		Swap(&A[i],&A[Right-1]);
		break;
		}
	quicksort(A,Left,i-1);
	quicksort(A,i+1,Right);
		}
	else
		insertsort(A+Left,Right-Left+1);
	}

void sort(Type A[],int N){
	quicksort(A,0,N-1);
}
