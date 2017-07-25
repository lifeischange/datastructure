# ifndef _LIST_H

typedef int ElementType;
struct Node;
typedef struct Node Root;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P,List L);
Position Find(ElementType X,List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X,List L);
void DeleteList(List L);

# endif

struct Node{
	ElementType Element;
	Position Next;
	};
