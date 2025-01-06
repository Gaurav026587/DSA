#include<iostream>
#include<stdlib.h>

#define N 100
using namespace std;
int a[N],top=-1;
void push(int key)
{
	if(top==N-1)
	{
		cout<<"Stack is full"<<endl;
	}
	
	else{
		top++;
		a[top]=key;
		cout<<"Item "<<key<<" pushed succefully"<<endl;
	}
}

void pop()
{
	if(top==-1)
	{
		cout<<"Stack is empty"<<endl;
	}
	else{
		cout<<"Object "<<a[top]<<" popped"<<endl;
		top--;
	}
}

void display()
{
	if(top==-1)
	{
		cout<<"Stack is empty"<<endl;
	}
	
	else
	{
		cout<<"Elements of stack are:"<<endl;
		for(int i=0;i<=top;i++)
		{
			cout<<a[i]<<endl;
		}
	}
}

int main()
{
	int ch,value;
	char n;
	do
	{
		system("cls");
		cout<<"Menu:\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter value to push:";
				cin>>value;
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"BYE BYEE!";
				exit(0);
			default:
				cout<<"Wrong choice!!!";
				break;
		}
		cout<<"Do you want to choose again?\nY for yes\nN for no\n-";
		cin>>n;
	}while(n=='y'||n=='Y');
}
