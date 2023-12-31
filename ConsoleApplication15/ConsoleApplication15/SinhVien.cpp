#include "SinhVien.h"
#include <string.h>
void xuatTieuDe()
{
	printf("%-10s%-30s%-40s%10s%10s\n", "Ma", "HoTen", "DiaChi", "NS", "DTB");
}
void xuatSV(SinhVien x)
{
	printf("%-10s%-30s%-40s%10d%10.1f\n", x.ma, x.hoTen, x.diaChi, x.namSinh, x.diemTB);
}
void docSV(FILE* &fp, SinhVien&x)
{
	//100030;Nguyen Van Xuan;123, Q1, TP.HCM;1999;9.5
	fscanf(fp, "%[^;];", &x.ma);
	fscanf(fp, "%[^;];", &x.hoTen);
	fscanf(fp, "%[^;];", &x.diaChi);
	fscanf(fp, "%d;", &x.namSinh);
	fscanf(fp, "%f\n", &x.diemTB);
}
//nhap 1 sinh vien
void nhapSV(SinhVien& x)
{
	printf("\n----------\n");
	printf("Nhap ma: ");
	scanf("%s", &x.ma);
	printf("Nhap ho ten: ");
	fflush(stdin);
	gets(x.hoTen);
	printf("Nhap dia chi: ");
	fflush(stdin);
	gets(x.diaChi);
	printf("Nhap nam sinh: ");
	scanf("%d", &x.namSinh);
	printf("Nhap diem trung binh: ");
	scanf("%f", &x.diemTB);
}