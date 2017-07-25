#ifndef _Cursor_H

typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P,const List L);
Position Find(ElementType X,const List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,const List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L);

#endif

struct Node{
	ElementType Element;
	Position Next;
	};

struct Node CursorSpace[SpaceSize]; 
