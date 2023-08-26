#include <conio.h>
#include <stdio.h>
#include <fstream>

using namespace std;
#define maxsize 101
struct SV
{
	int masv;
	char ten[20];
	int namsinh;
	int diemTB;
};


struct Node
{
	int key;
	SV value;
	Node* next;
	Node* prev;
};

typedef Node* NodePtr;

struct HashTable
{
	NodePtr* bucket;
	int size; //kich thuoc bang bam (so luong bucket)
	int n;//so luong phan tu tren bang bam
};

void initList(Node*& head)
{
	head = NULL;
}
bool isEmptyList(Node* head)
{
	return head == NULL;
}
Node* createNode(int key, SV value)
{
	Node* p = new Node;
	p->key = key;
	p->value = value;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void addHead(Node*& head, int key, SV value)
{
	Node* p = createNode(key, value);
	if (isEmptyList(head))
	{
		head = p;
	}
	else
	{
		p->next = head;
		head->prev = p;
		head = p;
	}
}
void removeHead(Node*& head)
{
	if (!isEmptyList(head))
	{
		Node* tmp = head;
		head = tmp->next;
		delete tmp;
	}
}
void removeAfter(Node*& q)
{
	if (q != NULL)
	{
		Node* p = q->next;
		q->next = p->next;
		delete p;
	}
}
void removeNodeList(Node*& head, int key)
{

	if (isEmptyList(head)) return;
	else
	{
		//xac dinh node chua key va node truoc cua no
		Node* p = head;
		Node* q = NULL; //q la node truoc p
		while (p != NULL && p->key != key)
		{
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			printf("Khoa khong ton tai!\n");
		}
		else
		{
			if (q == NULL) //p==head
				removeHead(head);
			else
				removeAfter(q);
		}
	}

}

Node* searchList(Node* head, int key)
{
	for (Node* p = head; p != NULL; p = p->next)
	{
		if (p->key == key)
			return p;
	}
	return NULL;
}
void xuatSV(SV x)
{
	printf("%5d %15s %5d\n", x.masv, x.ten, x.diemTB);
}
void traverseList(Node* head)
{
	for (Node* p = head; p != NULL; p = p->next)
	{
		//printf("%d ", p->key);
		xuatSV(p->value);
	}
	printf("\n");
}

void removeAllList(Node*& head)
{
	while (!isEmptyList(head))
		removeHead(head);
}



//Bang Bam
int hashSV(int key, int M)
{
	return key % M;
}

//khoi tao
void initHT(HashTable& ht, int capacity)
{
	ht.size = capacity;
	ht.n = 0;
	ht.bucket = new NodePtr[ht.size];
	for (int i = 0; i < ht.size; i++)
	{
		initList(ht.bucket[i]);
	}
}
//thao tac huy
void removeAllNodeHT(HashTable& ht)
{
	//duyet qua cac bucket
	for (int i = 0; i < ht.size; i++)
	{
		//xoa tat ca cac phan tu ben trong bucket
		removeAllList(ht.bucket[i]);
	}
	delete[] ht.bucket;
	ht.n = 0;
	ht.size = 0;
}
Node* searchNodeHT(HashTable ht, int key)
{
	int pos = hashSV(key, ht.size);
	return searchList(ht.bucket[pos], key);
}
void traverseHT(HashTable ht)
{
	for (int i = 0; i < ht.size; i++)
	{
		printf("bucket[%d]: \n", i);
		traverseList(ht.bucket[i]);
	}
}
//thao tac xoa
void removeNodeHT(HashTable& ht, int key)
{
	int pos = hashSV(key, ht.size);
	removeNodeList(ht.bucket[pos], key);
}

//thao tac them
void insertNodeHT(HashTable& ht, int key, SV value)
{
	int pos = hashSV(key, ht.size);
	
	
		//them vao dau
		addHead(ht.bucket[pos], key, value);
		//tang so luong phan tu tren bang bam
		ht.n++;
	
}


void docfile(HashTable& ht)
{
	FILE* f = fopen("DSSV.txt", "rt");
	if (!f)
		return;
	int n;
	fscanf(f, "%d", &n);
	SV x;
	initHT(ht, maxsize);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d#%[^\#]#%d#%d\n", &x.masv, x.ten, &x.namsinh,&x.diemTB);
		insertNodeHT(ht, x.diemTB, x);
	}
}

void dssvXS(HashTable ht)
{
	for (int i = maxsize - 1; i > 90; i--)
	{
		
		for (Node* p = ht.bucket[i]; p != NULL; p = p->prev)
		{
			if (p->key != NULL)
				xuatSV(p->value);
		}
		
	}
}

void xoasvdiemx(HashTable& ht, int x)
{
	for (int i = 0; i < maxsize; i++)
	{
		removeNodeHT(ht, x);
	}
}

void main()
{
	HashTable ht;
	int x;
	docfile(ht);
	traverseHT(ht);
	printf("DANH SACH SINH VIEN XUAT SAC LA:\n");
	dssvXS(ht);
	printf("Nhap diem can xoa: ");
	scanf("%d", &x);
	xoasvdiemx(ht, x);
	traverseHT(ht);
	getch();
}