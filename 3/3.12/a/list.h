#ifndef _List_H
typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Last(List L);
Position Find(int x, List L);
void Delete(int x, List L);
Position FindPrevious(ElementType X, List L);
Position Insert(ElementType X, List L, Position P);
void DeleteList( List L);
Position Header(List L);
Position First(List L);
void PrintList(List L);
List InitWithArray(int *a, int n);
int Swap(int i, int j, List L);
void SwapPosition(Position P1, Position P2, List L);
Position PositionOfIndex(int i, List L);

#endif /* _List_H */

/* Place in the implementation file*/

struct Node
{
	int Element;
	Position Next;
};
