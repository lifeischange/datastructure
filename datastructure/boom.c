#include <stdio.h>
#include<string.h>
#include<stdlib.h> 

struct List;
typedef struct List *node;

struct List{
	node index;
	int element;
	};
void printlist(node L){
	if(L!=NULL)
		{printf("%d\n",L->element);
		printlist(L->index);
		}
	};
	

void main(void){
	printf("begin!\n");
	node l=malloc(20*sizeof(struct List));
	if(l==NULL)
		printf("no space!");
	while(l->index!=NULL){
		printf("%d\n",l->element);
		l=l->index;
		}
	
	printlist(l);
	};
