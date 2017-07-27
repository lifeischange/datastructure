HashTable InitializeTable(int TableSize){
	if(TableSize<MinTableSize){
		printf("The size is too small.\n");
		return NULL;
		}
	HashTable H;
	int i;
	H=malloc(sizeof(struct HashTbl));
	if(H==NULL){
		printf("There is no space.\n");
		return NULL;		
		}
	H->TableSize=TableSize;
	H->TheCells=malloc(H->TableSize*sizeof(Cell));
	if(H->TheCells==NULL){
		printf("There is no space.\n");
		return NULL;		
		}
	for(i=0;i<H->TableSize;i++){
		H->TheCells[i]->Info=Empty; 
		}
	return H;
	}

Position Find(ElementType X,HashTable H){
	int CollisionNum;
	Position CurrentPos;
	CurrentPos=hash(X,H->TableSize);
	CollisionNum=0;
	while(H->TheCells[CurrentPos].Info!=Empty &&
		H->TheCells[CurrentPos].Element!=X){
			CurrentPos+=2*++CollisionNum-1;
			if(CurrentPos>=H->TableSize)
				CurrentPos-=H->TableSize;
			}
	return CurrentPos;
	}

void Insert(ElementType X,HashTable H){
	Position P;
	P=Find(X,H);
	if(H->TheCells[P]->Info!=Legitiamte){
		H->TheCells[P].Element=X;
		H->TheCells[P].Info=Legitimate; 
	}
	}

HashTable Rehash(HashTable H){
	int i,OldSize;
	Cell *OldCells;
	
	OldSize=H->TableSize;
	OldCells=H->ThrCells;

	H=InitializeTable(2*H->TableSize);
	
	for(i=0;i<OldSize;i++){
		if(OldCells[i].Info==Legitimate)
			Insert(OldCells[i].Element,H);
		}
	free(OldCells);
	return H;
	}
