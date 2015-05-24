#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List MakeEmpty(List L)
{
	if(!L){
		L = (List) malloc(sizeof(struct Node));
		L->Next = NULL;
	}else if(L->Next == NULL){
		return L;
	}else{	
		DeleteList(L);
	}
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
	while(P->Next != NULL ){
		P = P->Next;
		printf("%d\n",P->Element );
	}

}

List InitWithArray(int *a, int n)
{
	List L =NULL;
	L = MakeEmpty(L);
	for(int i = 0; i < n; i++){
		Insert(a[i], L, Last(L));
	}
	return L;
}

int Swap(int i, int j, List L)
{
	Position P1 = PositionOfIndex(i, L);
	Position P2 = PositionOfIndex(j, L);
	if(!P1 || !P2)
		return 0;
    SwapPosition( P1, P2, L);
	return 1;
}

void SwapPosition(Position P1, Position P2, List L)
{
	Position Temp1, Temp2, Temp3;
	if(FindPrevious(P1->Element, L) == P2){
		FindPrevious(P2->Element, L)->Next = P1;
		P2->Next = P1->Next;
		P1->Next = P2;
	}else if(FindPrevious(P2->Element, L) == P1){
		FindPrevious(P1->Element, L)->Next = P2;
		P1->Next = P2->Next;
		P2->Next = P1;
	}else{
		Temp1 = FindPrevious(P2->Element, L);
		FindPrevious(P1->Element, L)->Next = P2;
		Temp1->Next  = P1;
		Temp1 = P1->Next;
		P1->Next = P2->Next;
		P2->Next = Temp1;
	}
}

Position PositionOfIndex(int i, List L)
{
	Position P = L;
	for(int j = 0; j < i && P->Next != NULL; j++){
		P = P->Next;	
	}
	return P;
}
