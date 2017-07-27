#ifndef _AvlTree_H

struct AvlTreeNode;
typedef int ElementType;
typedef struct AvlTreeNode *AvlTree;
typedef struct AvlTreeNode *Position;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X,AvlTree T);
ElementType Retrieve(Position P);
#endif

struct AvlTreeNode{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
	};
