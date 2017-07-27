#ifndef _HashOpad_H

typedef unsigned int index;
typedef index Position;

struct HashEntry;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType X,HashTable H);
void Insert(ElementType X,HashTable H);
HashTable Rehash(HashTable H);
#endif

enum KindOfEntry{
	Legitimate,Empty,Deleted
	};

struct HashEntry{
	ElementType Element;
	enum KindOfEntry Info;
	};

typedef struct HashEntry Cell;

struct HashTbl{
	int TableSize;
	Cell *TheCells;
	};
