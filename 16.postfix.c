//psotfix conversion
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100	
	struct stack
	{	int a[100];
		int top;
	}st;
char push(char h)
{	st.top++;
	st.a[st.top]=h;
}
char pop()
{
	printf("%c",st.a[st.top]);
	st.top--;
}
int top()
{	return st.a[st.top];
}
int prior(char l)
{	
	switch(l)
	{		
		case '^':
			return 3;
		break;
		case '*':
			return 2;
		break;
		case '/':
			return 2;
		break;
		case '+':
			return 1;
		break;
		case '-':
			return 1;
		break;
		default:
			return 0;
	}
}
int main()
{ char s[MAX];
  int cho,i;
  st.top=-1;

		printf("Enter a string\n");
		scanf("%s",s);
		for(i=0;i<strlen(s);i++)
		{    
			if(isalnum(s[i]))
			{
				printf("%c",s[i]);
			}
			else if(s[i]=='(')
			{
				push(s[i]);
			}
			else if(s[i]==')')
			{	while(st.a[st.top]!='(')
					pop();
				st.top--;
			}
			else if((st.top==-1)||(prior(s[i])>prior( top() )))
			{
				push(s[i]);
			}
			else 
			{	while((st.top!=-1)&&(prior(s[i])<=prior(top())))
					pop();
					push(s[i]);
			}
		}
		while(st.top!=-1)
			pop();
}
