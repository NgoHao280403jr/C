#include <stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>

struct Node {
	int info;
	Node* next;
};

struct Queue {
	Node* head;
	Node* tail;
};

void initQueue(Queue& q) {
	q.head = NULL;
	q.tail = NULL;
}

int isEmpty(Queue q) {
	if (q.head == NULL)
		return 1;
	else
		return 0;
}

void insertQueue(Queue& q, Node* p) {
	if (p == NULL)
		return ;
	if (isEmpty(q) == 1){
		q.head = p;
		q.tail = p;
	}
	else
	{
		q.tail->next = p;
		q.tail = p;
	}
}
void DaoNguocQueue(Queue &ds){
	//khoi tao NODE hien tai
	Node *current = ds.head;
	//khoi tao NODE truoc NODE hien tai
	Node *prev = NULL;
	//khoi tao NODE sau NODE hien tai
	Node *next = NULL;
	//duyet tu dau den cuoi danh sach
	while (current != NULL) {
		//gan next bang node phia sau node hien tai
		next = current->next;
		//gan con tro next cua node hien tai ve node phia sau no
		current->next = prev;
		//gan node phai sau bang node hien tai
		prev = current;
		//gan hien tai bang node phia sau
		current = next;
	}
	//gan lai node dau danh sach lien ket
	ds.head = prev;
}
void showQueue(Queue q) {
	if (isEmpty(q) == 1) {
		printf("\nHang doi rong!");
		return;
	}
	printf("\nNoi dung hang doi la:\n");
	for (Node* p = q.head; p != NULL; p = p->next)
		printf("%d\n", p->info);
}

Node* createQNode(int x) {
	Node* p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
int check(Queue s, int a) {
	for (Node* p = s.head; p != NULL; p = p->next)
	{
		if (a == p->info)
		{
			return 1;
		}
	}
	return 0;
}


void deleleHead(Queue& q) {
	if (q.head == NULL)
		return;
	else
	{
		Node* p = q.head;
		q.head = p->next;
		p->next = NULL;
		delete p;
	}
}
void input(Queue& q) {
	int n, m;
	int dem = 0;
	int gioihan;
	printf("Moi nhap gioi han tin nhan:");
	scanf("%d", &gioihan);
	initQueue(q);
	Node* p = new Node;

	printf("Moi nhap so luong tin nhan:");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Moi ban nhap sdt cua nguoi nhan:");
		scanf_s("%d", &m);
		if (dem < gioihan)
		{
			if (check(q, m) == 0)
			{
				p = createQNode(m);
				insertQueue(q, p);
				dem++;
			}
		}
		else
		{
			if (check(q, m) == 0)
			{
				p = createQNode(m);
				insertQueue(q, p);
				deleleHead(q);
			}
		}
	}

}

void main() {
	Queue q;
	input(q);
	DaoNguocQueue(q);
	showQueue(q);
	getch();
}