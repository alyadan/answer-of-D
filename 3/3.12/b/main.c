#include <stdio.h>
#include "list.h"
#include <time.h>

List Init(int n);
void reverse(List L);
int main()
{
	time_t t1,t2;
	List L = NULL;
	L = MakeEmpty(L);
	int n;
	printf("pleat input the size of the list:");
	scanf("%d",&n);
	L = Init(n);
	//PrintList(L);

	t1 = clock();
		
	reverse(L);

	t2 = clock();
	PrintList(L);
	printf("success!through %ld mm\n", (t2-t1)/1000);
	return 0;
}

List Init(int n)
{
	List L = NULL, temp;
	L = MakeEmpty(L);
	int i;
	temp = L;
	for(i = 1; i <= n; i++){
		temp = Insert(i, L, temp);
	}
	return L;
}

void reverse(List L)
{
	Position Pos, Temp;
	Pos = L->Next;
	L->Next = NULL;
	while(Pos != NULL){
		Temp = Pos;
		Pos = Pos->Next;
		Temp->Next = L->Next;
		L->Next = Temp;
	}
}
