#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct nhanvien
{
	char MSNV[11];
	char hoTen[31];
	float luong;
};
void nhapM1C(int a[], int&n);
void xuatM1C(int a[], int n);
long tongmangchan(int a[], int n);
int demchan(int a[], int n);
void sapxeptang(int a[], int n);
void docFile(nhanvien nv[], int& n);
void xuatFile(nhanvien nv[], int n);
void timNV(nhanvien nv[], int n);
void xuat1NV(nhanvien nv[], int i);
void tongLuong(nhanvien nv[], int n);
void swap1(nhanvien &a, nhanvien &b);
void sapXep(nhanvien nv[], int n);
int tong(int n);
float tong1(int n);
void main()
{
	nhanvien nv[100];
	int luachon;
	int a[50], n;
	for (;;)
	{
		system("cls");
		printf("0.thoat");
		printf("\n1.cau2a");
		printf("\n2.cau2b");
		printf("\n3.cau2c");
		printf("\n4.cau3a");
		printf("\n5.cau3b");
		printf("\n6.cau3d");
		printf("\n7.cau4a");
		printf("\n8.cau4b");
		printf("\n9.cau4c");
		printf("\nmoi ban nhap lua chon: ");
		scanf("%d", &luachon);
		if (luachon == 0)break;
		switch (luachon)
		{
		case 1: nhapM1C(a, n);
			xuatM1C(a, n);
			printf("tong chan la: %d", tongmangchan(a, n));
			break;
		case 2: nhapM1C(a, n);
			xuatM1C(a, n);
			printf("mang dc sap xep la:");
			sapxeptang(a, n);
			xuatM1C(a, n);
			break;
		case 3: nhapM1C(a, n);
			xuatM1C(a, n);
			printf("\nso so chan trong mang la:%d", demchan(a, n));
			break;
		case 4:docFile(nv, n);
			xuatFile(nv, n);
			break;
		case 5: docFile(nv, n);
			xuatFile(nv, n);
			timNV(nv, n);
			break;
		case 6:docFile(nv, n);
			xuatFile(nv, n);
			tongLuong(nv, n);
			break;
		case 7:docFile(nv, n);
			xuatFile(nv, n);
			printf("sap xep theo luong giam dan:");
			sapXep(nv, n);
			xuatFile(nv, n);
			break;
		case 8: printf("nhap n:");
			scanf("%d", &n);
			printf("tong la: %d", tong(n));
			break;
		case 9:printf("nhap n:");
			scanf("%d", &n);
			printf("tong la: %.2f", tong1(n));
			break;
	default:
			break;
		}
		getch();
	}
}
void nhapM1C(int a[], int&n)
{
	printf("nhap kich thuoc mang:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i);
		scanf("%d",&a[i]);
	}
}
void xuatM1C(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d",a[i]);
	}
}
long tongmangchan(int a[], int n)
{
	if (n == 0)
		return 0;
	if (a[n - 1] % 2 == 0)
		return a[n - 1] + tongmangchan(a, n - 1);
	return tongmangchan(a, n - 1);
}
int demchan(int a[], int n)
{
	if (n == 0)
		return 0;
	if (n % 2 == 0)
		return 1 + demchan(a, n - 1);
	return demchan(a, n - 1);
}
void sapxeptang(int a[], int n)
{
	if (n == 1)
		return;
	for (int i = 0; i<n; i++){
		if (a[i] > a[n - 1]){
			int tam = a[i];
			a[i] = a[n - 1];
			a[n - 1] = tam;
		}
	}
	sapxeptang(a, n - 1);
}
void docFile(nhanvien nv[], int& n)
{
	FILE* f;
	f = fopen("nhanvien.txt", "rt");
	fscanf(f, "%d ", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%[^#]#%[^#]#%f\n", &nv[i].MSNV, &nv[i].hoTen, &nv[i].luong);
	}
	fclose(f);
}
void xuatFile(nhanvien nv[], int n)
{
	printf("\n%-15s%-20s%-15s", "MSNV", "HO VA TEN", "SO LUONG");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-15s%-20s%-15.2f", nv[i].MSNV, nv[i].hoTen, nv[i].luong);
	}
}
void xuat1NV(nhanvien nv[], int i)
{
	printf("\n%-15s%-20s%-15s", "MSNV", "HO VA TEN", "SO LUONG");
	printf("\n%-15s%-20s%-15.2f", nv[i].MSNV, nv[i].hoTen, nv[i].luong);
}
void timNV(nhanvien nv[], int n)
{
	char add[11];
	printf("\nVui long nhap ma nhan vien can tim: ");
	rewind(stdin);
	gets(add);
	for (int i = 0; i < n; i++){
		if (strcmpi(add, nv[i].MSNV) == 0)
			xuat1NV(nv, i);
	}
}
void tongLuong(nhanvien nv[], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s += nv[i].luong;
	}
	printf("\ntong luong phai tra la: %.2f", s);
}
void swap1(nhanvien &a, nhanvien &b)
{
	nhanvien v = a;
	a = b;
	b = v;
}
void sapXep(nhanvien nv[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nv[i].luong < nv[j].luong)
				swap1(nv[i], nv[j]);
		}
	}
}
int tong(int n)
{
	if (n == 0)
		return 1;
	return  (2 * n + 1) + tong(n - 1);
}
float tong1(int n)
{
	if (n == 0)
		return 0.5;
	return   (2.0 * n + 1) / (2.0 * n + 2) + tong1(n - 1);
}
