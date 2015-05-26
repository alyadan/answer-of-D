#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int Getline(char *s);
void Calc(char* s);

int main()
{
	char s[1000];
	printf("please input the formula:\n");
	Getline(s);
	Calc(s);	
	return 0;
}

int Getline(char *s)
{
	int c, n = 0;
	char *p = s;
	while((c = getchar()) != '\n'){
		n++;
		*p++ = c;
	}
	*p = '\0';
	return n;
}

char* GetElement(char *p,char *s);

void Calc(char *str)
{
	char* p = str;
	char Temp[100];
	Stack S = CreateStack(30);
	double num1,num2;
	while(*p != '\0'){
		p = GetElement(Temp, p);
		switch(Temp[0]){
			case '+': if(IsEmpty(S)){
						printf("Error\n");
						return;
					  }
					  num2 = TopAndPop(S);
					  if(IsEmpty(S)){
						printf("Error\n");
						return;
					  }
					  num1 = TopAndPop(S);
					  Push(num1 + num2, S);
					  break;
			case '-': if(Temp[1] == '\0'){
						if(IsEmpty(S)){
							printf("Error\n");
							return;
						}
						num2 = TopAndPop(S);
						if(IsEmpty(S)){
							printf("Error\n");
							return;
						}
						num1 = TopAndPop(S);
						Push(num1 - num2, S);
					   }else{
						Push(atof(Temp), S);
					   }
					  break;
			case '*': if(IsEmpty(S)){
						printf("Error\n");
						return;
					  }
					  num2 = TopAndPop(S);
					  if(IsEmpty(S)){
						printf("Error\n");
						return;
					  }
					  num1 = TopAndPop(S);
					  Push(num1 * num2, S);
					  break;
			case '/': if(IsEmpty(S)){
						printf("Error\n");
						return;
					  }
					  num2 = TopAndPop(S);
					  if(IsEmpty(S)){
						printf("Error\n");
						return;
					  }
					  num1 = TopAndPop(S);
					  if(num2 == 0){
						printf("div wrong!\n");
						return;
					  }
					  Push(num1 / num2, S);
					  break;
		   case '\0':; break;
			 default: Push(atof(Temp), S);
					  break;
		}
	}
	printf("%lf\n", TopAndPop(S));
}

char* GetElement(char *p,char *str)
{
	while(*str++ == ' ');
	str--;
	while(*str != ' '&& *str != '\0')
		*p++ = *str++;
	*p = '\0';
	return str;
}
