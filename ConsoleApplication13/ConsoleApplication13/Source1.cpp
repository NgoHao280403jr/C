#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

struct hoatDong
{
	char tenHD[20];
	int Si;
	int Ei;
};
struct Node
{
	hoatDong info;
	Node*next;
};

struct slist
{
	Node*head;
	Node*tail;
};
void InitSlist(slist &l)
{
	l.head = l.tail = NULL;
}
void InsertTail(slist &l, Node*q)
{
	if (q == NULL) return;
	if (l.head == NULL)
		l.head = l.tail = q;
	else
	{
		l.tail->next = q;
		l.tail = q;
	}

}
Node*createNode(hoatDong x)
{
	Node*q = new Node;
	if (q == NULL)
	{
		printf("Khong du bo nho!");
		getch();
		return NULL;
	}
	q->info = x;
	q->next = NULL;
	return q;
}
void createslist(slist &l)
{

	hoatDong hd;
	int n;
	InitSlist(l);
	FILE*f;
	f = fopen("data.txt", "r");
	if (f == NULL)
	{
		printf("Loi file");
		return;
	}
	fscanf(f, "%d\n", &n);
	for (int i = 0; i<n; i++)
	{
		fscanf(f, "%[^\ ] %d %f\n", hd.tenHD, &hd.Si, &hd.Ei);
		Node*q = createNode(hd);
		InsertTail(l, q);

	}
	fclose(f);
}

void processSlist(slist l)
{
	if (l.head == NULL)
	{
		printf("khong co gia tri nao");
		return;
	}
	printf("\n------DANH SACH HOC SINH-------");
	printf("\n%-25s%-20s%-20s", "TEN HOAT DONG", "THOI GIAN BAT DAU", "THOI GIAN KET THUC");

	for (Node*q = l.head; q != NULL; q = q->next)
	{
		printf("\n%-25s%-20d%-20d", q->info.tenHD, q->info.Si, q->info.Ei);

	}
}
void main()
{
	hoatDong hd;
	slist l;
	createslist(l);
	processSlist(l);
	printf("heloo word");
	getch();
}