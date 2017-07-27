
HashTable InitializeTable(int TableSize){
	HashTable H;
	if(TableSize<MinTableSize){
		printf("TableSize is too small.\n");
		return NULL;
		}
	H=malloc(sizeof(HashTbl));
	if(H==NULL){
		printf("Out of space.\n");
		return NULL;
		}
	H->TableSize=TableSize;
	H->TheLists=malloc(H->TableSize*sizeof(struct ListNode));
	if (H->TheLists==NULL){
		printf("No more space for lists.\n");
		return NULL;
		}
	for(int i=0;i<TableSize;i++){
		H->TheLists[i]->Next=NULL; 
		}
	return H;
	}

void DestroyTable(HashTable H){
	int i;
	i=H->TableSize;
	for(;i>0;i--){
		Position P;
		P=H->TheLists[i];
		Delete(P);
		}
	free(H);
	}

static void Delete(Position P){
	if(!P)
		return NULL;
	Position M;
	M=P->Next;
	if(M){
		free(P);
		P=M;
		M=P->Next;
		}
	}

Position Find(ElementType X,HashTable H){
	Position P;
	List L;
	L=H->TheLists[hash(X,H->TableSize)];
	P=L;
	while(P && P->Element!=X){
		P=P->Next;
		}
	return P;
	}

void Insert(ElementType X,HashTable H){
	Position P,Temp;
	List L;
	L=H->TheLists[hash(X,H->TableSize)];
	while(L){
		if(L->Element!=X)
			{
			Temp=L;
			L=L->Next;}

		else{
			printf("The element is already in the table.\n");
			return;
			}
		}
	P=malloc(sizeof(struct ListNode));
	P->Element=X;
	P->Next=NULL;
	Temp->Next=P;
	}
