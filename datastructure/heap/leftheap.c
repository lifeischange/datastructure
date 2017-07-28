
//合并驱动
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2){
	if(H1==NULL)
		return H2;
	if(H2==NULL)
		return H1;
	if(H1->Element<H2->Element)
		return Merge1(H1,H2);
	else
		return Merge1(H2,H1);
	}

static PriorityQueue Merge1(PriorityQueue H1,PriorityQueue H2){
	if(H1->Left==NULL)//H1是单节点的情况，省了下一步交换孩子。
		H1->Left=H2;
	else{
		H1->Right=Merge(H2,H1->Right);
		if(H1->Left->Npl<H1->Right->Npl)
			SwapChildren(H1);
		}
	H1->Npl=H1->Right->Npl+1;
	return H1;
	}

PriorityQueue Insert(ElementType X,PriorityQueue H){
	PriorityQueue P;
	P=malloc(sizeof(struct TreeNode));
	if(P==NULL)
		Error("No more space.\n");
	else{
		P->Element=X;
		P->Left=P->Right=NULL;
		P->Npl=0;
		H=Merge(P,H);
		}
	return H;
	}

PriorityQueue DeleteMin(PriorityQueue H){
	if(IsEmpty(H)){
		Error("Priority queue is empty.\n");
		return H;
		}
	PriorityQueue LeftHeap,RightHeap;
	LeftHeap=H->Left;
	RightHeap=H->Right;
	free(H);
	return Merge(LeftHeap,RightHeap);
	}
