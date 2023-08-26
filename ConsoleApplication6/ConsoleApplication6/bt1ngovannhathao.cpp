#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct Node
{
	int info;
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
Node* createNode(int x)
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
	int n, x;
	Node*q;
	srand((unsigned)time(NULL));
	InitSlist(l);
	do
	{
		printf("moi nhap so phan tu trong danh sach(n>0): ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		/*printf("moi nhap phan tu thu %d= ",i);
		scanf("%d",&x);*/
		x = rand() % 100;
		Node*q = createNode(x);
		InsertTail(l, q);

	}
}
void processSlist(slist l)
{
	if (l.head == NULL)
	{
		printf("khong co gia tri nao");
		return;
	}
	Node*q = l.head;
	while (q != NULL)
	{
		printf("%5d", q->info);
		q = q->next;
	}
}

int kt(slist l)
{
	if (l.head == NULL)
		return 1;
	else
		return 0;
}
Node*findNode(slist l, int x)
{
	if (kt(l) == 1)
		return NULL;
	Node*p = l.head;
	while ((p != NULL) && (p->info != x))
	{
		p = p->next;
	}
	return p;
}
void beforeNode(slist &l, int x, int y)
{

	Node*p = createNode(x);
	Node*q = findNode(l, y);
	if (q == NULL)
	{
		printf("\nkhong ton tai %d trong ds\n", y);
		return;
	}
	Node*t = l.head;
	while (t->next->info != y)
	{
		t = t->next;
	}
	p->next = t->next;
	t->next = p;
}

void deleteGreaterNodes(slist &l, int x)
{
	Node *temp = l.head, *prev;

	
	if (temp != NULL && temp->info > x) {
		l.head = temp->next; 
		free(temp); 
		temp = l.head; 
	}

	while (temp != NULL) {
		while (temp != NULL && temp->info <= x) {
			prev = temp;
			temp = temp->next;
		}			
		if (temp == NULL)
			return;
		prev->next = temp->next;
		delete temp; 
		temp = prev->next;
	}
}
void deleteEvenElement(slist &l)
{
	Node *temp = l.head, *prev;


	if (temp != NULL && temp->info %2==0) 
	{
		l.head = temp->next;
		free(temp);
		temp = l.head;
	}

	while (temp != NULL) {
		while (temp != NULL && temp->info %2!= 0) 
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
			return;
		prev->next = temp->next;
		delete temp;
		temp = prev->next;
	}
}
void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void interChangeSortAscending(slist l)

{

	Node *i, *j;

	for (i = l.head; i != l.tail; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)

		{
			if (i->info > j->info)
			{
				swap(j->info, i->info);
			}
				
		}
	}
}
void interChangeSortDecrease(slist l)
{
	Node *i, *j;

	for (i = l.head; i != l.tail; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{

			if (i->info < j->info)
			{				
				swap(j->info, i->info);
			}
		}
	}

}
int ktSoNguyenTo(int soA)
{
	if (soA < 2)
		return 0;

	for (int i = 2; i <= sqrt((float)soA); i++)
	{
		if (soA%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void soNguyenTo(slist l)
{
	int dem = 0;
	Node* p = l.head;
	while (p != NULL)
	{
		if (ktSoNguyenTo(p->info) == 1)
		{
			dem++;
		}
		p = p->next;
	}
	printf("\nso phan tu nguyen to trong danh sach la:%d", dem);
}
bool ktSoChinhPhuong(int n)
{
	if (n<1)
		return false;
	int i = sqrt((float)n);
	if (i*i == n)
		return true;
	return false; // nếu không là scp return false
}
void tongSoChinhPhuong(slist l)
{
	int s = 0;
	Node* p = l.head;
	while (p != NULL)
	{
		if (ktSoChinhPhuong(p->info) == true)
		{
			s=s+p->info;
		}
		p = p->next;
	}
	printf("\nso tong so phan tu la so chinh phuong trong danh sach la:%d", s);
}
void timMax(slist l)
{
	Node* Max=l.head;
	Node*p = Max->next;
	while (p!=NULL)
	{
		if (Max->info < p->info)
		{
			Max->info = p->info;
		}
		p = p->next;
	}
	printf("\nphan tu max trong dslk la:%d", Max->info);
}
void timMin(slist l)
{
	Node* Min = l.head;
	Node*p = Min->next;
	while (p != NULL)
	{
		if (Min->info > p->info)
		{
			Min->info = p->info;
		}
		p = p->next;
	}
	printf("\nphan tu min trong dslk la:%d", Min->info);
}
void ktPhanTuLonx2(slist l)
{
	int dem = 0;
	Node*p = l.head;
	
	while (p != l.tail)
	{
		Node*q = p->next;
		if (p->info > 2 * q->info)
		{
			dem++;
		}
		p = q;
	}
	printf("\nso phan tu lon gap doi phan tu phia sau no la: %d", dem);
}
//void bai1j(slist l,slist l1,slist l2 )
//{
//	InitSlist(l1);
//	InitSlist(l2);
//	Node*p = l.head;
//	while (p!=NULL)
//	{
//		if (p->info % 2 == 0)
//		{
//			Node*a = p;
//			InsertTail(l1, a);
//		}
//		else
//		{
//			Node*b = p;
//			InsertTail(l2, b);
//		}
//	}
//	printf("\ndanh sach 1:");
//	processSlist(l1);
//	printf("\ndanh sach 2:");
//	processSlist(l2);
//}
void main()
{
	slist l; slist l1; slist l2;
	int x, y, a;
	int luachon;
	for (;;)
	{ 
		printf("\n.0 thoat");
		printf("\n1.bai1a");
		printf("\n2.bai1b");
		printf("\n3.bai1c");
		printf("\n4.bai1d");
		printf("\n5.bai1e");
		printf("\n6.bai1f");
		printf("\n7.bai1g");
		printf("\n8.bai1h");
		printf("\n9.bai1i");
		printf("\n10.bai1j");
		printf("\nmoi ban nhap lua chon\n");
		scanf("%d", &luachon);
		if (luachon == 0)break;
		switch (luachon)
		{
		case 1:
		{createslist(l);
		printf("\ndanh sach vua tao la:");
		processSlist(l);
		printf("\nmoi nhap phan tu muon them vao cuoi: ");
		scanf("%d", &x);
		Node*q = createNode(x);
		InsertTail(l, q);
		printf("\ndanh sach vua them  la:\n");
		processSlist(l);
		break; }
		case 2:{createslist(l);
			printf("\ndanh sach vua tao la:");
			processSlist(l);
			printf("\nmoi nhap x: ");
			scanf("%d", &x);
			printf("\nmoi nhap y: ");
			scanf("%d", &y);
			beforeNode(l, x, y);
			printf("\ndanh sach sau khi them la:\n");
			processSlist(l);
			break; }
		case 3:{createslist(l);
			printf("\ndanh sach vua tao la:");
			processSlist(l);
			printf("\nmoi nhap a xoa phan tu lon hon a: ");
			scanf("%d", &a);
			deleteGreaterNodes(l, a);
			break; }
		case 4: {createslist(l);
			printf("\ndanh sach vua tao la:");
			processSlist(l);
			deleteEvenElement(l);
			printf("\ndanh sach sau khi xoa phan tu chan :");
			processSlist(l);
			break; }
		case 5: {
					createslist(l);
					printf("\ndanh sach vua tao la:");
					processSlist(l);
					interChangeSortAscending(l);
					printf("\ndanh sach sau sap xep tang dan:");
					processSlist(l);
					interChangeSortDecrease(l);
					printf("\ndanh sach sau sap xep giam dan:");
					processSlist(l);
					break;
		}
		case 6: {
					createslist(l);
					printf("\ndanh sach vua tao la:");
					processSlist(l);
					soNguyenTo(l);
					break;
		}
		case 7: {
					createslist(l);
					printf("\ndanh sach vua tao la:");
					processSlist(l);
					tongSoChinhPhuong(l);
					break;
		}
		case 8: {
					createslist(l);
					printf("\ndanh sach vua tao la:");
					processSlist(l);
					timMax(l);
					timMin(l);
					break;
		}
		case 9:{
				   createslist(l);
				   printf("\ndanh sach vua tao la:");
				   processSlist(l);
				   ktPhanTuLonx2(l);
				   break;
		}
		}
		getch();
	}
	

}