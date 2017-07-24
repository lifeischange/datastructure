#ifndef _LIST_H

struct 	Node; /*节点结构*/
typedef struct Node *PtrToNode;/*节点指针*/
typedef PtrToNode List;/*链表指针*/
typedef PtrToNode Position;/*链表项*/

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position p,List L);
Position Find(ElementType X,List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X,List L,Position P);
void Delete(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);


#endif

struct Node
	{
	ElementType Element;
	Position Next;
	};
