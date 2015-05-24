#include <stdio.h>
#include "list.h"

void PrintLots(List L, List P);
int main()
{
	List L = NULL;
	L = MakeEmpty(L);
	int a[5] = {5,6,7,8,9};
	L = InitWithArray(a,5);
	if(!Swap(1, 3, L))
		printf("Swap failed");
	PrintList(L);
	return 0;
}
	
