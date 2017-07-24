#ifndef _stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);//处理编排 安置
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void pop(Stack S);
ElementType TopAndPop(Stack S);

#endif

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord{
	int Capacity;/*容量.能力。身份*/
	int TopOfStack;
	ElementType *Array;
	};
