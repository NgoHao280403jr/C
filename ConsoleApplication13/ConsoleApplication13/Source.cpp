#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<time.h>
#define size 100
#define MAX 100
using namespace std;
void Menu();
void TaoMang(int a[], int n);
void XuatMang(int a[], int n);
void Nhap_Mang(int array[], int& n);
void Xuat_MaxMang(int array[], int n);
int TimVTMax77(int a[], int n);
void tinhtich(char a[], char b[], char c[]);
float trungBinhCong(int a[], int n);
int main()
{
	int a[MAX], n;
	cout << "Nhap vao so phan tu thuc su: ";
	cin >> n;
	TaoMang(a, n);
	XuatMang(a, n);
	int kq = TimVTMax77(a, n);
	cout << "\nVi tri cua gia tri Max la: " << kq << "\t";
	cout << endl;
	char A[size], B[size], C[size * 2];
	cin.getline(A, size);
	cin.getline(B, size);
	tinhtich(A, B, C);
	cout << C;
	getch();
	return 0;
}
void Menu()
{
	printf(" \n************MENU*******************");
	printf(" \n0.Thoat chuong trinh ");

}
void TaoMang(int a[], int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i<n; i++)
	{
		a[i] = rand() % 100 - rand() % 100;
	}
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i<n; i++)
		cout << a[i] << "\t";
}

int TimVTMax77(int a[], int n)
{
	int i, vtmax = 0;
	int max = a[0];
	for (i = 0; i<n; i++)
	if (a[i]> max)
	{
		max = a[i];
		vtmax = i;
	}
	return vtmax;
}
void tinhtich(char A[], char B[], char C[])
{
	strrev(A);
	strrev(B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	for (int i = 0; i < lenA + lenB; i++)
		C[i] = '0';
	for (int iB = 0; iB < lenB; iB++)

	{
		int nho = 0;
		int iA;
		for (int iA = 0; iA < lenA; iA++)
		{
			int x = (A[iB] - '0') * (A[iA] - '0') + nho + (C[iA + iB] - '0');
			C[iA + iB] = x % 10 + '0';
			nho = x / 10;
		}
		if (nho > 0)
			C[iA + iB] = nho + '0';
	}
	if (C[lenA + lenB - 1] != '0')
		C[lenA + lenB] = '\0';
	else
		C[lenA + lenB] = '\0';
	strrev(C);
}
float trungBinhCong(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i];
	}
	return (float)tong / n;
}
int tam1, tam2, vt;
int daysolonnhatbentrai(int a[], int i, int j)
{
	int maxsum = 0;
	int sum = 0;
	for (int k = j; k <= j; k++)
	{
		sum = sum + a[k];
		if (sum > maxsum)
		{
			maxsum = sum;
			tam1 = k;
		}
	}
	return maxsum;
}
int daysolonnhatbenphai(int a[], int i, int j)
{
	int maxsum = 0;
	int sum = 0;
	for (int k = i; k <= j; k++)
	{
		sum = sum + a[k];
		if (sum > maxsum)
		{
			maxsum = sum + a[k];
			tam2 = k;
		}
	}
	return maxsum;
}
int daysoconlonnnhat(int a[], int i, int j)
{
	if (i == j)
		return a[i];
	int m = (i + j) / 2;
	int trai = daysoconlonnnhat(a, i, m);
	int phai = daysoconlonnnhat(a, m + 1, j);
	int giua = (daysoconlonnnhat(a, i, m) + daysoconlonnnhat(a, m + 1, j));
	if
		(trai < phai) vt = tam1;
	else

		vt = tam2;
	return trai, phai, giua;
}
