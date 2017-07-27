#ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType X,HashTable H);
void Insert(ElementType X,HashTable H);

#endif

struct ListNode{
	ElementType Element;
	Position Next;
	};

typedef Position List;

struct HashTbl{
	int TableSize;
	List *TheLists;
	};
