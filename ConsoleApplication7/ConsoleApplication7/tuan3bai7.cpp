#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
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

int precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/' || x == '%')
		return 2;

	return 3;
}
void infixtoPostfix(char infix[], char postfix[])
{
	Stack S;
	char x, token;
	int i = 0, j = 0;    // i-index of infix,j-index of postfix
	initStack(S);
	for (i = 0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if (isalnum(token))
			postfix[j++] = token;
		else
		if (token == '(')
		{
			Node*q = createNode('(');
			push(S, q);
		}
		else
		if (token == ')')
		while (S.top->info != '(')
			postfix[j++] = x;
		else
		{
			while (precedence(token) <= precedence(S.top->info) && S.top!=NULL)
			{
				x = S.top->info;
				postfix[j++] = x;
			}
			Node*q = createNode(token);
			push(S,q);
		}
	}

	while (S.top != NULL)
	{
		pop(S);
		postfix[j++] = x;
	}

	postfix[j] = '\0';
}


void output(Stack l)
{
	for (Node *k = l.top; k != NULL; k = k->next){
		printf("%d ", k->info);
	}
}
void main()
{
	Stack l;
	char add[50];
	char b[50];
	printf("\nVui long nhap ki tu: ");
	rewind(stdin);
	gets(add);
	infixtoPostfix(add, b);
	output(l);
	getch();

}