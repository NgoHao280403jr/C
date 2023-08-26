#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct Node{
	int info;
	Node* next;
};

struct Stack{
	Node* top;
};

void initStack(Stack &l){
	l.top = NULL;
}

Node* createNode(int value){
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
void createsStack(Stack &l)
{
	int n, x;
	Node*q;
	initStack(l);
	do
	{
		printf("moi nhap so phan tu trong danh sach(n>0): ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		printf("moi nhap phan tu thu %d= ",i);
		scanf("%d",&x);
		Node*q = createNode(x);
		push(l, q);

	}
}
void them1PhanTu(Stack &l)
{
	int x;
	printf("\nmoi nhap phan tu muon them:  ");
	scanf("%d", &x);
	Node*q = createNode(x);
	push(l, q);
}
void stackOutput(Stack l){
	for (Node *k = l.top; k != NULL; k = k->next){
		printf("%d ", k->info);
	}
	
}
void xemPhanTuDinhStack(Stack l)
{
	Node *k = l.top;
	printf("\nPhan tu o danh stank la: %d ", k->info);
}
void main(){
	Stack stack;
	createsStack(stack);
	stackOutput(stack);
	them1PhanTu(stack);
	stackOutput(stack);
	xemPhanTuDinhStack(stack);
	getch();
}
