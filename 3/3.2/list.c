#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List MakeEmpty(List L)
{
	L = (List) malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}
int IsEmpty(List L)
{
	return L->Next == NULL;
}
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Last(List L)
{
	Position P = L;

	while(P->Next != NULL)
	{
		P = P->Next;
	}

	return P;
}
Position Find(int x, List L)
{
	Position P;

	P = L->Next;
	while(P != NULL && P->Element != x)
		P = P->Next;
	return P;
}
void Delete(int x, List L)
{
	Position P, TemCell;

	P = FindPrevious(x, L);

	if( !IsLast(P,L)){
		TemCell = P->Next;
		P->Next = TemCell->Next;
		free(TemCell);
	}
}
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while(P->Next != NULL && P->Next->Element != X){
		P = P->Next;
	}

	return P;
}
void Insert(ElementType X, List L, Position P)
{
	Position TemCell;
	TemCell = malloc(sizeof(struct Node));
	if(TemCell == NULL){
		printf("Out of space");	
	}
	TemCell->Element = X;
	TemCell->Next = P->Next;
	P->Next = TemCell;
}
void DeleteList( List L)
{
	Position P, Tmp;

	P = L->Next;
	L->Next = NULL;
	while(P != NULL){
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
Position Header(List L)
{
	return L;
}
Position First(List L)
{
	return L->Next;
}

void PrintList(List L)
{
	Position P = L;
	while(P->Next != NULL )
	{
		P = P->Next;
		printf("%d\n",P->Element );
	}

}
