typedef int ElementType

List MakeEmpty(List L)
{
	Position p;
	p->ElementType=0;
	p->Next=NULL;
	L=p;
	return L;
}

int IsEmpty(List L)
{
return L->Next==NULL;
}

int IsLast(Position p ,List L){
	Position temp;
	temp=L;
	while (temp->Next)
		temp=temp->Next;
	return temp->ElementType==p->ElementType
}

Position Find(ElementType X,List L){
	Position temp;
	temp=L;
	while (temp->Next)
	{
		if(X==temp->ElementType)
			return temp;
		temp=temp->Next;
	}
	return NULL;
	}

void







