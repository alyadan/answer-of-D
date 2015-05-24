#include <stdio.h>
#include "list.h"

void PrintLots(List L, List P);
int main()
{
	List L,P;
	L = MakeEmpty(L);
	P = MakeEmpty(P);
	int a[5] = {5,6,7,8,9};
	for(int i = 0; i < 5; i++){
		Insert(a[i], L, Last(L));
	}
	int b[3] = {1,2,5};
	for(int i = 0; i < 3; i++){
		Insert(b[i], P, Last(P));
	}
	//PrintList(L);
	PrintLots(L, P);
	return 0;

}
	
void PrintLots(List L, List P)
{
	for(int i = 0;L->Next != NULL ;++i)
	{
		if(Find(i, P))
			printf("%d", L->Element);
		L = L->Next;	
	}

}
