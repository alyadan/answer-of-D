#ifndef _STACK_H
#define _STACK_H

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);	
void Push(ElementType X,Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif // _STACK_H

