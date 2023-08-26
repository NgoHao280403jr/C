#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
struct sinhVien
{
	char maSV[11];
	char hoDem[26];
	char tenSV[9];
	int namSinh;
	float diemKQ;
	float diemTLcrr;
	float diemCKcrr;
	float diemTLctdldt;
	float diemCKctdldt;
	float diemTLthctdldt;
	float diemCKthctdldt;
};
struct Node
{
	sinhVien info;
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
Node*createNode(sinhVien x)
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

	sinhVien sv;
	int n;
	InitSlist(l);
	FILE*f;
	f = fopen("sinhvien.txt", "r");
	if (f == NULL)
	{
		printf("Loi file");
		return;
	}
	fscanf(f, "%d\n", &n);
	for (int i = 0; i<n; i++)
	{
		fscanf(f, "%[^\#]#%[^\#]#%[^\#]#%d#%f#%f#%f#%f#%f#%f\n", sv.maSV, sv.hoDem, sv.tenSV,&sv.namSinh,&sv.diemTLcrr,&sv.diemCKcrr,&sv.diemTLctdldt,&sv.diemCKctdldt,&sv.diemTLthctdldt,&sv.diemCKthctdldt);
		sv.diemKQ =((sv.diemTLcrr*0.3+0.7*sv.diemCKcrr)+(sv.diemTLctdldt*0.3+0.7*sv.diemCKctdldt)+(sv.diemTLthctdldt*0.3+0.7*sv.diemTLthctdldt))/3;
		Node*q = createNode(sv);
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
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH","KET QUA HOC TAP");
	
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		printf("\n%-25s%-20s%-20s%-15d%-15.2f",q->info.maSV,q->info.hoDem,q->info.tenSV,q->info.namSinh,q->info.diemKQ );

	}
}

void timSV(slist l)
{
	char add[11];
	printf("\nVui long nhap ma sinh vien can tim: ");
	rewind(stdin);
	gets(add);
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH", "KET QUA HOC TAP");
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (strcmpi(add, q->info.maSV) == 0)
			printf("\n%-25s%-20s%-20s%-15d%-15.2f", q->info.maSV, q->info.hoDem, q->info.tenSV, q->info.namSinh, q->info.diemKQ);
	}
}
void timTenSV(slist l)
{
	char add[11];
	printf("\nVui long nhap ten sinh vien can tim: ");
	rewind(stdin);
	gets(add);
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH", "KET QUA HOC TAP");
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (strcmpi(add, q->info.tenSV) == 0)
			printf("\n%-25s%-20s%-20s%-15d%-15.2f", q->info.maSV, q->info.hoDem, q->info.tenSV, q->info.namSinh, q->info.diemKQ);
	}
}
void xeploaiKha(slist l)
{
	printf("\n----DANH SACH HOC SINH LOAI KHA----");
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH", "KET QUA HOC TAP");
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (q->info.diemKQ> 7&&q->info.diemKQ<=8.5)
			printf("\n%-25s%-20s%-20s%-15d%-15.2f", q->info.maSV, q->info.hoDem, q->info.tenSV, q->info.namSinh, q->info.diemKQ);
	}
}
void minKha(slist l)
{
	float min;
	printf("\n-----HOC SINH KHA CO DIEM NHO NHAT------");
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH", "KET QUA HOC TAP");
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (q->info.diemKQ > 7 && q->info.diemKQ <= 8.5)
		{
			 min = q->info.diemKQ;	 
		}
		
	}
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (q->info.diemKQ > 7 && q->info.diemKQ <= 8.5&&min > q->info.diemKQ)
		{
			min = q->info.diemKQ;
		}
	}
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (q->info.diemKQ == min)
			printf("\n%-25s%-20s%-20s%-15d%-15.2f", q->info.maSV, q->info.hoDem, q->info.tenSV, q->info.namSinh, q->info.diemKQ);
	}
}
void timGanX(slist l)
{
	float x;
	float t;
	Node*q=l.head;
	printf("\nnhap x= ");
	scanf("%f", &x);
	float hieu = fabs(q->info.diemKQ - x);
	printf("\n-----HOC SINH KHA CO DIEM GAN VOI %d NHAT LA:------",x);
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH", "KET QUA HOC TAP");
	for (q = l.head->next; q != NULL; q = q->next)
	{
		if (hieu > fabs(q->info.diemKQ - x))
		{
			hieu = hieu = fabs(q->info.diemKQ - x);
			t = q->info.diemKQ;
		}
	}
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (q->info.diemKQ == t)
			printf("\n%-25s%-20s%-20s%-15d%-15.2f", q->info.maSV, q->info.hoDem, q->info.tenSV, q->info.namSinh, q->info.diemKQ);
	}
}
void swap( sinhVien &a, sinhVien &b)
{
	sinhVien t = a;
	a = b;
	b = t;
}
void maxKQ(slist l)
{
	printf("\n----SINH VIEN CO KET QUA HOC TAP CAO NHAT----");
	float max = l.head->info.diemKQ;
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH", "KET QUA HOC TAP");
	for (Node*q = l.head->next; q != NULL; q = q->next)
	{
		if (max < q->info.diemKQ)
		{
			max = q->info.diemKQ;
		}
	}
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (q->info.diemKQ== max)
			printf("\n%-25s%-20s%-20s%-15d%-15.2f", q->info.maSV, q->info.hoDem, q->info.tenSV, q->info.namSinh, q->info.diemKQ);
	}
}
void minKQ(slist l)
{
	printf("\n----SINH VIEN CO KET QUA HOC TAP THAP NHAT----");
	float min = l.head->info.diemKQ;
	printf("\n%-25s%-20s%-20s%-15s%-15s", "MA SO SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH", "KET QUA HOC TAP");
	for (Node*q = l.head->next; q != NULL; q = q->next)
	{
		if (min > q->info.diemKQ)
		{
			min = q->info.diemKQ;
		}
	}
	for (Node*q = l.head; q != NULL; q = q->next)
	{
		if (q->info.diemKQ == min)
			printf("\n%-25s%-20s%-20s%-15d%-15.2f", q->info.maSV, q->info.hoDem, q->info.tenSV, q->info.namSinh, q->info.diemKQ);
	}
}
void interChangeSortAscending(slist l)

{

	for (Node*i = l.head; i != NULL; i = i->next)
	{
		for (Node*j = i->next; j != NULL; j = j->next)

		{
			if (strcmp(i->info.maSV, j->info.maSV)>0)
			{
				swap(i->info, j->info);
			}

		}
	}
}
void sapxepTen(slist l)

{

	for (Node*i = l.head; i != l.tail; i = i->next)
	{
		for (Node*j = i->next; j != NULL; j = j->next)

		{
			if (strcmp(i->info.tenSV, j->info.tenSV)>0)
			{
				swap(i->info, j->info);
			}

		}
	}
}
void sapxepKQ(slist l)

{

	for (Node*i = l.head; i != l.tail; i = i->next)
	{
		for (Node*j = i->next; j != NULL; j = j->next)

		{
			if (i->info.diemKQ > j->info.diemKQ)
			{
				swap(i->info, j->info);
			}

		}
	}
}
void insertTail(slist &l)
{
	sinhVien sv;
	printf("\nNhap ma sinh vien:");
	fflush(stdin);
	gets(sv.maSV);
	printf("\nnhap ho dem sinh vien:");
	fflush(stdin);
	gets(sv.hoDem);
	printf("\nNhap ten sinh vien:");
	fflush(stdin);
	gets(sv.tenSV);
	printf("\nNhap nam sinh sinh vien:");
	scanf("%d", &sv.namSinh);
	printf("\nNhap diem tieu luan mon cau truc roi rac: ");
	scanf("%f", &sv.diemTLcrr);
	printf("\nNhap diem cuoi ky mon cau truc roi rac: ");
	scanf("%f", &sv.diemCKcrr);
	printf("\nNhap diem tieu luan mon cau truc du lieu va giai thuat: ");
	scanf("%f", &sv.diemTLctdldt);
	printf("\nNhap diem cuoi ky mon cau truc du lieu va giai thuat: ");
	scanf("%f", &sv.diemCKctdldt);
	printf("\nNhap diem tieu luan mon thuc hanh cau truc du lieu va giai thuat: ");
	scanf("%f", &sv.diemTLthctdldt);
	printf("\nNhap diem cuoi ky mon thuc hanh cau truc du lieu va giai thuat:");
	scanf("%f", &sv.diemCKthctdldt);
	sv.diemKQ = ((sv.diemTLcrr*0.3 + 0.7*sv.diemCKcrr) + (sv.diemTLctdldt*0.3 + 0.7*sv.diemCKctdldt) + (sv.diemTLthctdldt*0.3 + 0.7*sv.diemTLthctdldt)) / 3;
	Node*q = createNode(sv);
	
	if (q == NULL) return;
	if (l.head == NULL)
		l.head = l.tail = q;
	else
	{
		l.tail->next = q;
		l.tail = q;
	}
}

void xoaSV(slist &l)
{
	char add[11];
	printf("\nVui long nhap ma sinh vien can xoa: ");
	rewind(stdin);
	gets(add);
	Node *pDel = l.head;
	if (pDel == NULL)
	{
		printf("\ndanh sach rong");
	}
	else
	{
		Node *pPre = NULL;
		while (pDel != NULL)
		{
			Node*p = pDel->next;
			if (strcmpi(add, p->info.tenSV) == 0)
				break;
			pPre = pDel;
			pDel = pDel->next;
		}
		if (pDel == NULL)
		{
			printf("\nkhong thay ma sinh vien");
		}
		else
		{
			if (pDel == l.head)
			{
				l.head= l.head->next;
				pDel->next = NULL;
				delete pDel;
				pDel = NULL;
			}
			else
			{
				pPre->next = pDel->next;
				pDel->next = NULL;
				delete pDel;
				pDel = NULL;
			}
		}
	}
}
void main()
{
	slist l;
	int x, y, a;
	int luachon;
	for (;;)
	{
		system("cls");
		printf("\n.0 thoat");
		printf("\n1.bai3a");
		printf("\n2.bai3b");
		printf("\n3.bai3c");
		printf("\n4.bai3d");
		printf("\n5.bai3e");
		/*printf("\n6.bai3f");*/
		printf("\n7.bai3h");
		printf("\n8.bai3i");
		printf("\n9.bai3j");
		printf("\n10.bai3k");
		printf("\n11.bai3l");
		printf("\n12.bai3m");
		printf("\nmoi ban nhap lua chon\n");
		scanf("%d", &luachon);
		if (luachon == 0)break;
		switch (luachon)
		{
		case 1:createslist(l);
			processSlist(l);
			timSV(l);
			break;
		case 2:createslist(l);
			processSlist(l);
			timTenSV(l);
			break;
		case 3:createslist(l);
			processSlist(l);
			interChangeSortAscending(l);
			processSlist(l);
			break;
		case 4:createslist(l);
			processSlist(l);
			sapxepTen(l);
			processSlist(l);
			break;
		case 5:createslist(l);
			processSlist(l);
			interChangeSortAscending(l);
			insertTail(l);
			processSlist(l);
			break;
		/*case 6: createslist(l);
			processSlist(l);
			xoaSV(l);
			processSlist(l);
			break;
			*/		
		case 7:createslist(l);
			processSlist(l);
			sapxepKQ(l);
			processSlist(l);
			break;
		case 8:createslist(l);
			processSlist(l);
			xeploaiKha(l);
			break;
		case 9: createslist(l);
			processSlist(l);
			maxKQ(l);
			break;
		case 10: 
			createslist(l);
			processSlist(l);
			minKQ(l);
			break;
		case 11:createslist(l);
			processSlist(l);
			minKha(l);
			break;
		case 12: createslist(l);
			processSlist(l);
			timGanX(l);
			break;
		}
		getch();
	}
}