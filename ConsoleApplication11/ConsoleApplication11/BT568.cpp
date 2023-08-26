#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void menu();
void thucthi();
void tachMang(int x[100], int n, int x1[100], int &n_1, int x2[100], int &n_2);
int BinarySearch(int a[], int l, int r, int x);
int pow(int a, int n);
int tongMang(int a[], int n);
int tinhTongTBDeTri(int a[], int n);
int sosanh(int a[], int n);
int timKiemNhiPhanPhanTuGanGiaTriTB(int a[], int l, int r, int x);
void main()
{
	menu();
	thucthi();
	getch();
}
void menu()
{
	printf("0.Thoat");
	printf("\n1.De quy nhap xuat mang 1 chieu");

}

void thucthi()
{
	int luachon;
	int a[50];
	int n, x;
	for (;;)
	{
		printf("\nmoi nhap lua chon ");
		scanf("%d", &luachon);
		if (luachon == 0) break;
		switch (luachon)
		{
		case 1:
			printf("\nmoi nhap so luong phan tu:");
			scanf("%d", &n);
			nhapMang(a, n);
			printf("\nmang moi nhap la:");
			xuatMang(a, n);
			break;
		case 2:
			printf("\nmoi nhap phan tu can tim");
			scanf("%d", &x);
			printf("\nvi tri phan tu can tim la: %d", BinarySearch(a, 0, n - 1, x));
			break;
		case 3:
			printf("\nmoi nhap phan tu:");
			scanf("%d", &x);
			printf("\nmoi nhap so luong phan tu:");
			scanf("%d", &n);
			printf("\n ket qua: %d", pow(x, n));
			break;
		case 4: printf("\ntong tb mang: %d", tinhTongTBDeTri(a, n) / n);
			printf("\nvi tri phan tu gan voi gia tri trung binh nhat la:%d ", timKiemNhiPhanPhanTuGanGiaTriTB(a, 0, n - 1, x));
			break;
		default:
			break;
		}
	}

}
void nhapMang(int a[], int n)

{
	srand(time(NULL));
	if (n == 0)
		return;
	nhapMang(a, n - 1);
	a[n - 1] = rand() % 100 + 1;

}
void xuatMang(int a[], int n)
{
	if (n == 0)
		return;
	xuatMang(a, n - 1);
	printf("%5d", a[n - 1]);

}
void tachMang(int x[100], int n, int x1[100], int &n_1, int x2[100], int &n_2)
{
	int i1 = 0;  n_1 = 0;
	int i2 = 0;  n_2 = 0;
	for (int i = 0; i<n; i++){
		if (x[i] % 2 == 0){
			x1[i1] = x[i];
			i1++;
			n_1++;
		}
		else{
			x2[i2] = x[i];
			i2++;
			n_2++;
		}
	}
}
int BinarySearch(int a[], int l, int r, int x)
{
	if (l > r)
		return -1;
	int mid = (l + r) / 2;
	if (a[mid] == x)
		return mid;
	if (a[mid] > x)
		return BinarySearch(a, l, mid - 1, x);
	else
	{
		return BinarySearch(a, mid + 1, r, x);
	}

}
int pow(int a, int n)
{
	if (n == 1) {
		return a;
	}
	else {
		if (n % 2 == 0)
			return pow(a, n / 2) * pow(a, n / 2);
		else
			return pow(a, n / 2) * pow(a, n / 2) * a;
	}
}
int tongMang(int a[], int n)
{

	if (n == 0)
		return 0;
	return a[n - 1] + tongMang(a, n - 1);
}
int tinhTongTBDeTri(int a[], int n)
{
	int n1, n2;
	int b[50];
	int c[50];
	if (n == 1)
		return a[0];
	tachMang(a, n, b, n1, c, n2);
	return tongMang(b, n1) + tongMang(c, n2);
}
int sosanh(int a[], int n)
{
	int i;
	int min = abs(tinhTongTBDeTri(a, n) - a[0]);
	for (i = 0; i < n; i++)
	{
		if (abs(tinhTongTBDeTri(a, n)) - a[i] < min)
		{
			min = abs(tinhTongTBDeTri(a, n) - a[i]);
		}
	}
	return min;
}
int timKiemNhiPhanPhanTuGanGiaTriTB(int a[], int l, int r, int x)
{
	x = sosanh(a, l + r);
	if (l > r)
		return -1;
	int mid = (l + r) / 2;
	if (tinhTongTBDeTri(a, l + r) - a[mid] == x);
	return mid;
	if (a[mid] > x)
		return BinarySearch(a, l, mid - 1, x);
	else
	{
		return BinarySearch(a, mid + 1, r, x);
	}

}