#include<stdlib.h>
#include<stdio.h>
#include<string.h>

PriorityQueue Initialize(int MaxElements){
	if(MaxElements<MinHeapElements){
		printf("The priority queue size is too small.\n");
		return NULL;
		}
	PriorityQueue Q;
	Q=malloc(sizeof(struct HeapStruct));
	if(Q==NULL){
		printf("There is no more space for queue.\n");
		return NULL;
		}
	Q->Capacity=MaxElements;
	Q->Size=0;
	Q->Element=malloc((MaxElements+1)*sizeof(ElementType));
	if(Q->Element==NULL){
		printf("There is no more space for queue elements.\n");
		return NULL;
		}
	Q->Element[0]=MinData; 
	return Q;
	}

void Insert(ElementType X,PriorityQueue H){
	int i;
	i=H->Size+1;
	if(i>H->Capacity)
		printf("PriorityQueue is full.\n");
	while(H->Element[i/2]>X){
		H->Element[i]=H->Element[i/2];
		i/=2;
		}
	H->Element[i]=X; 
	}

ElementType DeleteMin(PriorityQueue H){
	if(H->Size==0){
		printf("The queue is empty.\n");
		return H->Element[0];
		}
	ElementType temp,MinElement;
	int child,i;
	temp=H->Element[H->Size--];
	MinElement=H->Element[1]; 
	for(i=1;i*2<=H->Size;i=child){
		child=2*i;
		if(child!=H->Size && H->Element[child]>H->Element[child+1])
			child++;
		if(temp>H->Element[child])
			H->Element[i]=H->Element[child];
		else
			break;
		}
	
	H->Element[i]=temp;
	return MinElement;
	}
