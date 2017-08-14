#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void insertsort(Type A[],int N){
	int i,j;
	Type Tmp;
	for(i=1;i<N;i++){
		Tmp=A[i];
		for(j=i;j>0;j--){
			if(A[j-1]>Tmp)
				A[j]=A[j-1];
			else
				break;
			}
		A[j]=Tmp; 
		}
	}


