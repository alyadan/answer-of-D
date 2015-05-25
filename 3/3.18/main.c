#include <stdio.h>
#include "stack.h"

int IsCSource(char* );
void Match(char* );
void GetStr(FILE*, char* s); 

int main(int argc, char* argv[])
{
	FILE *fp;
	char str[10000];
	if(argc != 2){
		printf("wrong param\n");
		return 1;
	}else if(!IsCSource(argv[1])){
		printf("Not a c source\n");
		return 2;
	}
	
	if((fp = fopen(argv[1], "r+")))
		printf("open success!\n");
	GetStr(fp, str);
	Match(str);
	//printf("%s\n", str);
	fclose(fp);
	return 0;
}

int IsCSource(char* s)
{
	char *p = s;
	while(*p++ != '.'&&*p != '\0');
	if(*p == '\0')
		return 0;
	else
		if(*p++ == 'c' && *p == '\0')
			return 1;
	return 0;
}

void GetStr(FILE *fp, char *s)
{
	char *p = s;
	int c;
	while(!feof(fp)){
		c = fgetc(fp);
		*p++ = c;
	}
	*p = '\0';
}
void Match(char *str)
{
	char *p = str;
	int lines = 1, temp;
	Stack S = CreateStack(100);
	while(*p){
		switch(*p++){
			case '\n':	lines++;
						break;
			case '\\':	Push(*(p-1), S);
						if( *p++ == '*')
							Push(*(p-1), S);
						else{
							Pop(S);
							p--;
						}
						break;
			case '*':	if(*p++  == '/')
							if(TopAndPop(S) == '*' && TopAndPop(S) == '\\')
								break;
							else{
								printf("wrong match in lines: %d\n", lines);
								return;
							}
						else
							p--;
						break;
			case '(': Push(*(p-1), S);
					  break;
			case ')': if(TopAndPop(S) == '(')
						  break;
					  else{
						printf("wrong match in lines: %d\n", lines);
						return;
					  }
					  break;
			case '[': Push(*(p-1), S);
					  break;
			case ']': if(TopAndPop(S) == '[')
						  break;
					  else{
						printf("wrong match in lines: %d\n", lines);
						return;
					  }
					  break;
			case '{': Push(*(p-1), S);
					  break;
			case '}': if(TopAndPop(S) == '{')
						  break;
					  else{
						printf("wrong match in lines: %d\n", lines);
						return;
					  }
					  break;
			case '\'': while(*p++ != '\'')
					if(*(p-1) == '\\')
						p++;
				    break;
			case '"': while(*p++ != '"')
					if(*(p-1) == '\\')
						p++;
				   break;
			default: break;
		}
	}
	printf("it's all right!\n");
}

