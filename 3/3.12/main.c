#include <stdio.h>
#include "list.h"
#include <time.h>

List Init(int n);
void reverse(List L, List P);
int main()
{
	time_t t1,t2;
	List L = NULL, P = NULL;
	L = MakeEmpty(L);
	P = MakeEmpty(P);
	int n;
	printf("pleat input the size of the list:");
	scanf("%d",&n);
	L = Init(n);
	//PrintList(L);

	t1 = clock();
		
	reverse(L, P);

	t2 = clock();
	PrintList(P);
	printf("find success!through %ld mm\n", (t2-t1)/1000);
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

void reverse(List L, List P)
{
	Position Pos;
	Pos = L;
	while((Pos = Pos->Next) != NULL){
		Insert(Pos->Element, P, P); //从表头插入数据就可以反转链表	
	}
}
