#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main(void){
	int *temp,*n;
	printf("begin:");
	temp=calloc(2,3*sizeof(int));
	n=temp;
	if(!temp)
		printf("No space.");
	for(int i=0;i<6;i++){
		*temp=i;
		printf("point:%p pointaddress:%p  value:%d\n",temp,&temp,*temp);
		temp++;
		}
	printf("Start to free:\n\n");
	temp=n;
//	free(n);
//	free(temp);
	for(int i=0;i<9;i++){
//		printf("npoint:%p n_ pointaddress:%p n_ value:%d\n",n,&n,*n);
		printf("point:%p pointaddress:%p  value:%d\n\n",temp,&temp,*temp);
		temp++;
//		n++;
		}
	printf("Recall some space.\n");

	temp=realloc(n,300*sizeof(int));

	if(!temp)
		printf("No space.");
	for(int i=0;i<4;i++){
		*temp=i+8;
		printf("point:%p pointaddress:%p  value:%d\n",temp,&temp,*temp);
		temp++;
		}
	temp=temp-4;
	for(int i=4;i<16;i++){
		printf("point:%p pointaddress:%p  value:%d\n",temp,&temp,*temp);
		temp++;
		}
		}
	
