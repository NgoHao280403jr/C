#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct SinhVien
{
	char mssv[11];
	char hoten[31];
	float diem;
	char gioitinh[6];
};
void nhapMangNgauNhien(int a[], int &n);
void xuatMang(int a[], int n);
void xuatMangNgauNhien(int *a, int n);
void timMaxle(int *a, int n);
int ktSoChinhPhuong(int n);
void tinhTongCP(int *a, int n);
void nhapFile(SinhVien sv[], int& n);
void xuat(SinhVien sv[], int n);
void timSV(SinhVien sv[], int n);
void xuat1SV(SinhVien sv[], int i);
void timdiemMin(SinhVien sv[], int n);

void main()
{ 
	SinhVien sv[100];
	int luachon, n;
	int a[50];
	for (;;)
	{
		system("cls");
		printf("0.thoat\n");
		printf("1.bai 2.1\n");
		printf("2.bai 2.2\n");
		printf("3.bai 2.3\n");
		printf("4.bai 2.4\n");
		printf("5.bai 4.3\n");
		printf("6.bai 4.4\n");
		printf("7.bai 4.5\n");
		printf("moi nhap lua chon: ");
		scanf("%d", &luachon);
		if (luachon == 0)break;
		switch (luachon)
		{
		case 1: nhapMangNgauNhien(a, n);
			xuatMangNgauNhien(a, n);
			break;
		case 2: nhapMangNgauNhien(a, n);
			xuatMang(a, n);
			break;
		case 3:nhapMangNgauNhien(a, n);
			xuatMangNgauNhien(a, n);
			timMaxle(a, n);
			break; 
		case 4: nhapMangNgauNhien(a, n);
			xuatMangNgauNhien(a, n);
			tinhTongCP(a, n);
			break;
		case 5: nhapFile(sv, n);
			xuat(sv, n);
			break;
		case 6: nhapFile(sv, n);
			xuat(sv, n);
			timSV(sv, n);
			break;
		case 7: nhapFile(sv, n);
			xuat(sv, n);
			timdiemMin(sv, n);
			break;

		default:
			break;
		}
		getch();
	}

}
void nhapMangNgauNhien(int *a, int &n)
{
	printf("moi nhap kich thuoc mang: ");
	scanf("%d", &n);
	for  (int i = 0;  i < n; i++)
	{
		*(a+i) = -50 + rand() % 100;
	}
}
void xuatMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d co dia chi la: %x\n", *(a+i),a+i);
}
void xuatMangNgauNhien(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%5d ", *(a + i));
}
void timMaxle(int *a, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) % 2 == 1)
		{
			max = *(a + i); break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max < *(a + i) && *(a + i) % 2 == 1)
		{
			max = *(a + i);
		}
	}
	printf("\nMax le trong mang la: %d", max);
}
int ktSoChinhPhuong(int n)
{
	float i = 0;
	while ( i<=n)
	{
		if (pow(i, 2) == n)
		{
			return 1;
		}
		i++;
	}
	return 0;
}
void tinhTongCP(int *a, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (ktSoChinhPhuong(*(a + i)) == 1)
		{
			s = s + *(a + i);
		}
	}
	printf("\ntong cac so chinh phuong la: %d", s);
}
void nhapFile(SinhVien sv[], int& n) 
{
	FILE* f;
	f = fopen("sinhvien.txt", "rt");
	fscanf(f, "%d ", &n);
	for (int i = 0; i < n; i++) 
	{
		fscanf(f, "%[^#]#%[^#]#%[^#]#%f\n", &sv[i].mssv, &sv[i].hoten, &sv[i].gioitinh,&sv[i].diem );
	}
	fclose(f);
}
void xuat(SinhVien sv[], int n)
{
	printf("\n%-15s%-20s%-15s%-15s", "MSSV", "HO VA TEN","GIOI TINH", "DIEM" );
	for (int i = 0; i < n; i++)
	{
		printf("\n%-15s%-20s%-15s%-15.2f", sv[i].mssv, sv[i].hoten, sv[i].gioitinh, sv[i].diem);
	}
}
void xuat1SV(SinhVien sv[], int i)
{
	printf("\n%-15s%-20s%-15s%-15s", "MSSV", "HO VA TEN", "GIOI TINH", "DIEM");
	printf("\n%-15s%-20s%-15s%-15.2f", sv[i].mssv, sv[i].hoten, sv[i].gioitinh, sv[i].diem);
}
void timSV(SinhVien sv[], int n)
{
	char add[31];
	printf("\nVui long nhap ma sinh vien can tim: ");
	rewind(stdin);
	gets(add);
	for (int i = 0; i < n; i++)
	{
		if (strcmpi(add, sv[i].hoten) == 0)
		{
			xuat1SV(sv, i);
		}
	}
}
void timdiemMin(SinhVien sv[], int n)
{
	float min = sv[0].diem;
	for (int i = 1; i < n; i++)
	{
		if (min > sv[i].diem)
		{
			min = sv[i].diem;
		}
	}
	printf("\nsinh vien co diem thap nhat la: ");
	for (int i = 0; i < n; i++)
	{
		if (min ==sv[i].diem)
			xuat1SV(sv, i);
	}
}