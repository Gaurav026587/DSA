#include<iostream>
#include<string.h>
using namespace std;
char a[100],result[100];
int top=-1;

void push(char n)
{
	a[++top]=n;
}

int pop()
{
	return a[top--];
}

int assoc(char op)
{
	if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
}

void reverse(char infic[])
{
	int len=strlen(infic);
	for(int i=0;i<len/2;i++)
	{
		swap(infic[i],infic[len-i-1]);
	}
	
	for(int i=0;i<len;i++)
	{
		if(infic[i]=='(')
		infic[i]=')';
		else if(infic[i]==')')
		infic[i]='(';
	}
}

void convert(char infic[],char result[])
{
	int i,j=0,len=strlen(infic);
	reverse(infic);
	char ch;
	
	for(i=0;i<len;i++)
	{
		ch=infic[i];
		
		if(isalnum(ch))
		{
			result[j++]=ch;
		}
		else if (ch == '(') {
            push(ch);
        } 
		else if (ch == ')') {
            while (top >= 0 && a[top] != '(') {
                result[j++] = pop();
            }
            pop();
        }
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		{
			if(top>=0&&assoc(a[top])>=assoc(ch))
			{
				result[j++]=pop();
			}
			push(ch);
		}
	}
	
	int leng=strlen(result);
	for(int i=0;i<leng/2;i++)
	{
		swap(result[i],result[len-i-1]);
	}
	while (top >= 0) {
        result[j++] = pop();
}
}
int main()
{
	char infic[100];
	
	cout<<"Enter infix expression:";
	cin>>infic;
	
	convert(infic,result);
	cout<<"Result:"<<result;
	
	
}
