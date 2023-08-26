#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void menu();
void thucthi();
void InterchangeSort(int a[], int n);
int BinarySearchMax(int a[], int l, int r, int max);
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
	printf("\n2.BT4");

}
void thucthi()
	{
		int luachon;
		int a[50];
		int n, x, max;
		for (;;)
		{
			printf("\nmoi nhap lua chon ");
			scanf("%d", &luachon);
			if (luachon == 0) break;
			switch (luachon)
			{
			case 1:
			{printf("\nmoi nhap so luong phan tu:");
			scanf("%d", &n);
			nhapMang(a, n);
			printf("\nmang moi nhap la:");
			xuatMang(a, n); }
				break;

			case 2:{
					 
					   printf("\nmang sap xep theo chieu tang dan:");
					   InterchangeSort(a, n);
					   xuatMang(a, n);
					   max = a[n - 1];
					   printf("\nvi tri phan tu can tim la: %d", BinarySearchMax(a, 0, n - 1, max)); }
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

void InterchangeSort(int a[], int n){
		int i, j;
		for (i = 0; i < n - 1; i++)
		{
			//j sẽ được duyệt từ vị trí của phân tử chưa sắp xếp tới cuối mảng
			for (j = i + 1; j < n; j++)
			{

				if (a[i] > a[j])
				{
					//Ta đảo vị trí của 2 phần tử
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
int BinarySearchMax(int a[], int l, int r, int max)
	{

		if (l > r)
			return -1;
		int mid = (l + r) / 2;
		if (a[mid] == max)
			return mid;
		if (a[mid] > max)
			return BinarySearchMax(a, l, mid - 1, max);
		else
		{
			return BinarySearchMax(a, mid + 1, r, max);
		}

	}