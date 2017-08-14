#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void shellsort(Type A[],int N){
	int Increment,i,j;
	Type Tmp;
	for(Increment=N/2;Increment>0;Increment/=2){
		for(i=Increment;i<N;i++){
			Tmp=A[i];
			for(j=i;j>=Increment;j-=Increment){
				if(A[j-Increment]>Tmp){
					A[j]=A[j-Increment];  
					}
				else
					break;
				}
			A[j]=Tmp; 	
			}
		}
	}
