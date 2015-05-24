#include <stdio.h>
#include "list.h"

int main()
{
	List L;
	L = MakeEmpty(L);
	int a[5] = {5,6,7,8,9};
	for(int i = 0; i < 5; i++){
		Insert(a[i], L, Last(L));
//		printf("success!");
	}
	PrintList(L);
	return 0;

}
	
