int IsEmpty(Stack S){
	return S->TopOfStack==EmptyTOS;
	};

Stack CreateStack(int MaxElements){
	Stack S;
	if(MaxElements<MinStackSize)
		Error("Stack size is too small");
	S=malloc(sizeof(StackRecord))
	if(!S)
		FatalError("Out of space!");
	ElementType *Array;
	Array=malloc(MaxElements*sizeof(ElementType));
	if(Array==NULL)
		Error("Out of space1")；
	S->Array=Array;
	S->Capacity=MaxElements;
	MakeEmpty(S);
	return S;
	};

void DisposeStack(Stack S){
	if(!S){
		free(S->Array);
		free(S);
		};
	};

void MakeEmpty(Stack S){
	S->TopOfStack=EmptyTOS;
};

void Push(ElementType X,Stack S){
	if(TopOfStack==Capacity)
		Error("No space1")；
	else{
		S->Array[++S->TopOfStack]=X; 
		};
	};

ElementType Top(Stack S){
	if(TopOfStack==-1)
		Error("Empty Stack!");
		return 0;
	return S->Array[TopOfStack]; 
	};

void pop(Stack S){
	if(!IsEmpty(S)){
		return S->Array[S->TopOfStack--]; 
		};
	else
		Error("Empty stack!");
	return 0;
	}
