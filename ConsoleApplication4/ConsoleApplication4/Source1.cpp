#include <conio.h>
#include <stdio.h>
#include <string.h>
struct SinhVien
{
	char MaSV[11];
	float Toan, Ly, Hoa, DTB;
	int NamSinh;
	struct HoTen
	{
		char Ho[16], ten[10];
	}; HoTen HT;
};
void nhapFile(SinhVien a[], int &n)
{
	printf(" moi nhap so sinh vien: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Nhap ma sinh vien thu %d: ", i+1);
		fflush(stdin);
		gets(a[i].MaSV);
		printf("Nhap diem toan cua sinh vien thu %d: ", i+1);
		scanf("%f", &a[i].Toan);
		printf("Nhap diem Ly cua sinh vien thu %d: ", i+1);
		scanf("%f", &a[i].Ly);
		printf("Nhap diem Hoa cua sinh vien thu %d: ", i+1);
		scanf("%f", &a[i].Hoa);
		printf("Nhap nam sinh cua sinh vien thu %d: ", i+1);
		scanf("%d", &a[i].NamSinh);
		printf("Nhap Ho sinh vien thu %d: ", i+1);
		fflush(stdin);
		gets(a[i].HT.Ho);
		printf("Nhap Ten sinh vien thu %d: ", i+1);
		fflush(stdin);
		gets(a[i].HT.ten);
	}
}
void DTB(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].DTB = (a[i].Toan + a[i].Ly + a[i].Hoa)*1.0 / 3;
	}
}
void xuat(SinhVien a[], int n)
{
	printf("\n%-15s%-20s%-15s%-15s%-15s%-15s%-15s", "Ma Sinh Vien","Ho Ten Sinh Vien","Nam Sinh", "Diem Toan", "Diem Ly", "Diem Hoa" ,"Diem Trung Binh" );
	for (int i = 0; i < n; i++){
		printf("\n%-15s%-5s%-15s%-15d%-15.2f%-15.2f%-15.2f%-15.2f", a[i].MaSV, a[i].HT.Ho, a[i].HT.ten, a[i].NamSinh, a[i].Toan, a[i].Ly, a[i].Hoa, a[i].DTB);
	}
}

void xuat1SV(SinhVien a)
{
	printf("------------------------------------------------------------\n");
	printf("Ma sinh vien:");
	puts(a.MaSV);
	printf("Ho va ten: %s %s\n", a.HT.Ho, a.HT.ten);
	printf("Nam sinh: %d\n", a.NamSinh);
	printf("Toan: %.2f\t\tLy: %.2f\t\tHoa: %.2f\n", a.Toan, a.Ly, a.Hoa);
	printf("Diem trung binh: %.2f\n", a.DTB);
}
void xuatNSV(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat1SV(a[i]);
	}
}
void timSVDTBMax(SinhVien a[], int n)
{
	float max = a[0].DTB;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].DTB > max)
		{
			max = a[i].DTB;
			b = i;
		}
	}
	xuat1SV(a[b]);
}
void InterchangeSort(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].DTB > a[j].DTB)
			{
				SinhVien c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
}
void SelectionSort(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j<n; j++)
		if (a[j].Toan > a[min].Toan)
			min = j;
		SinhVien c = a[min];
		a[min] = a[i];
		a[i] = c;
	}
}
void timKiemSV(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].DTB > 5 && a[i].Toan > 3 && a[i].Ly > 3 && a[i].Hoa)
			xuat1SV(a[i]);
	}
}
void timSVLonTuoi(SinhVien a[], int n)
{
	int max = a[0].NamSinh;
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].NamSinh < max)
		{
			int max = a[i].NamSinh;
			m = i;
		}
	}
	xuat1SV(a[m]);
}
void SelcetionSort(SinhVien a[], int n)
{
	char x[10];
	int dem = 0;
	printf("Nhap ten sinh vien muon tim: ");
	scanf("%s", &x);
	printf("-------------------------Sinh vien muon tim-------------------------\n");
	for (int i = 0; i < n; i++)
	{
		if (strcmpi(a[i].HT.ten, x) == 0)
		{
			xuat1SV(a[i]);
			dem = 1;
		}
	}
	if (dem == 0)
		printf("Khong tim thay sinh vien!!");
}
void sapXepTen(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		if (strcmp(a[i].HT.ten, a[j].HT.ten) > 0)
		{
			SinhVien c = a[i];
			a[i] = a[j];
			a[j] = c;
		}
	}
}
void BinarySort(SinhVien a[], int n)
{
	char x[10];
	int dem = 0, trai = 0, phai = n - 1;
	printf("Nhap ten sinh vien muon tim: ");
	scanf("%s", &x);
	printf("-------------------------Sinh vien muon tim-------------------------\n");
	while (trai <= phai)
	{
		int mid = (trai + phai) / 2;
		if (strcmpi(a[mid].HT.ten, x) == 0)
		{
			xuat1SV(a[mid]);
			break;
		}
		else
		if (strcmpi(a[mid].HT.ten, x) < 0)
			trai = mid + 1;
		else
			phai = mid - 1;
	}
}

void menu()
{
	printf("-----------------------------------Danh sach bai lam-----------------------------------\n");
	printf("1.Nhap xuat danh sach sinh vien\n");
	printf("2.Tim sinh vien co diem trung binh cao nhat\n");
	printf("3.Sap xep tang dan theo diem trung binh\n");
	printf("4.Sap xep giam dan theo diem toan\n");
	printf("5.Sinh vien co diem trung binh tren 5 va khong mon nao duoi 3\n");
	printf("6.Tim sinh vien lon tuoi nhat\n");
	printf("7.Nhap ten sinh vien va xuat ra sinh vien do(Selection sort)\n");
	printf("8.Nhap ten sinh vien va xuat ra sinh vien do(Binart Sort sort)\n\n");
}
void main()
{
	menu();
	int so, n;
	SinhVien sv[10];
	printf("Nhap bai muon lam: ");
	scanf("%d", &so);
	switch (so)
	{
	case 1:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  break;
	}
	case 2:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  printf("\n--------------Sinh vien co diem trung binh cao nhat--------------\n");
			  timSVDTBMax(sv, n);
			  break;
	}
	case 3:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  InterchangeSort(sv, n);
			  printf("--------------------------Sau khi sap xep diem trung binh tang dan--------------------------\n");
			  xuat(sv, n);
			  break;
	}
	case 4:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  SelectionSort(sv, n);
			  printf("--------------------------Sau khi sap xep diem toan giam dan--------------------------\n");
			  xuat(sv, n);
			  break;
	}
	case 5:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  printf("----------------------Sinh vien DTB lon hon 5 va khong mon nao duoi 3----------------------\n");
			  timKiemSV(sv, n);
			  break;
	}
	case 6:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  printf("---------------------Sinh vien tuoi cao nhat---------------------\n");
			  timSVLonTuoi(sv, n);
			  break;
	}
	case 7:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  SelcetionSort(sv, n);
			  break;
	}
	case 8:
	{
			  nhapFile(sv, n);
			  DTB(sv, n);
			  xuat(sv, n);
			  sapXepTen(sv, n);
			  BinarySort(sv, n);
			  break;
	}
	}
	getch();
}