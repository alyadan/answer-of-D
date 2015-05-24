#include <stdio.h>
#include "list.h"
#include <time.h>

Position Search(int n, Position P);
List Init(int n);
void PrintLots(List L, List P);
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
	printf("please input the element you want search:");
	scanf("%d",&n);

	t1 = clock();

	if(Find( n, L)){
		t2 = clock();
		printf("find success!through %ld mm\n", (t2-t1)/1000);
	}
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

Position Search(int n, Position P)
{
	if(P == NULL || P->Element == n )
		return P;
	return Search(n, P->Next);
}
	
