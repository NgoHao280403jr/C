#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
struct Node{
	char info;
	Node* next;
};

struct Stack{
	Node* top;
};

void initStack(Stack &l){
	l.top = NULL;
}

Node* createNode(char value){
	Node* p = new Node;
	if (p == NULL){
		printf("Khong du bo nho");
		return NULL;
	}
	p->info = value;
	p->next = NULL;
	return p;
}
Node* pop(Stack&l)
{
	Node* p = NULL;
	if (l.top != NULL)
	{
		p = l.top;
		l.top = l.top->next;
		p->next = NULL;
	}
	return p;
}
void push(Stack &l, Node *p){
	if (l.top == NULL){
		l.top = p;
	}
	else{
		p->next = l.top;
		l.top = p;
	}
}

int check(Stack &l, char *str)
{
	int i;
	
	for (i = 0; i < strlen(str); i++)
	{
		if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
		{
			Node*q = createNode(str[i]);
			push(l, q);
		}
		else
		{

			if (l.top != NULL)
			{
				if (str[i] == ')')
				{
					if (l.top->info != '(') //
						return 0;
				}
				if (str[i] == '}')
				{
					if (l.top->info != '{') //
						return 0;
				}
				if (str[i] == '[')
				{
					if (l.top->info != ']') //
						return 0;
				}
				pop(l);
			}
			else
			{
				return 0;
			}
		}
	}
	if (l.top == NULL)
		return 1;
}
void main()
{
	Stack l;
	char add[11];
	printf("\nVui long nhap ki tu: ");
	rewind(stdin);
	gets(add);
	if (check(l, add) == 0)
	{
		printf("chuoi ngoac sai");
	}
	else
	{
		printf("chuoi ngoac dung");
	}
	getch();
}