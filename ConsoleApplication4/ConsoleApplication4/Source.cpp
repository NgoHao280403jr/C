#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100
void taoM1C(int a[], int &n)
{
	printf("\nNhap so luong phan tu: ");
	scanf("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
void xuatM1C(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
}
//Cau a: tinh tong cac phan tu chan cua mang a
int tongChanA(int a[], int n)
{
	if (n == 0)
		return 0;
	if (a[n - 1] % 2 == 0)
		return a[n - 1] + tongChanA(a, n - 1);
	return tongChanA(a, n - 1);
}
//cau c: tim Max chan trong a
int MaxChan(int a[], int n, int i, int max)
{
	if (i == n)
		return max;
	if ((a[i] % 2 == 0) && (a[i] > max))
		max = a[i];
	return MaxChan(a, n, ++i, max);
}
//cau d: tinh tong le trong mang a
int tongLeA(int a[], int n)
{
	if (n == 0)
		return 0;
	if (a[n - 1] % 2 != 0)
		return a[n - 1] + tongLeA(a, n - 1);
	return tongLeA(a, n - 1);
}
void main()
{
	int a[MAX], n;
	int max = -1;
	taoM1C(a, n);
	printf("\nMang tao ngau nhien: ");
	xuatM1C(a, n);
	printf("\n\n>>Tong cac phan tu chan trong mang = %d", tongChanA(a, n));
	printf("\n\n>>Tong cac phan tu le trong mang = %d", tongLeA(a, n));
	int kq = MaxChan(a, sizeof(a) / sizeof(int), 0, max);
	if (kq == -1)
		printf("\n\nKhong ton tai so chan!");
	else
		printf("\n\nPhan tu chan lon nhat trong mang = %d", kq);
	getch();
}
