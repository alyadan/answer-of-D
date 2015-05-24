#include <stdio.h>
#include "list.h"
#include <time.h>

void calc(int n, List L);
List Init(int n);
void PrintLots(List L, List P);
int main()
{
	clock_t t1,t2;
	List L = NULL;
	printf("please input m,n:\n");
	scanf("%d,%d", &n, &m);
	
	t1 = clock();

	L = Init(n);
	calc(m, L);
	printf("\n");

	t2 = clock();
	printf("\ntotal time:%lumm\n", (t2-t1)/1000);
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

void calc(int n, List L)
{
	int i;
	Position P, Temp;
	P = L->Next;
	for(i = n;!IsEmpty(L); i = n){
		while(i-- > 0){
			P = P->Next;
			if(P == L)
				i++;	
		}
		printf("%d ",P->Element);
		Temp = P->Next;
		Delete(P->Element,L);
		P = Temp;
	}
}
