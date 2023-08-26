#ifndef _SINH_VIEN_H_
#define _SINH_VIEN_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct SinhVien{
	char ma[11];
	char hoTen[31];
	char diaChi[41];
	int namSinh;
	float diemTB;
};
//xuat tieu de SV
void xuatTieuDe();
//xuat 1 sinh vien
void xuatSV(SinhVien x);
//nhap 1 sinh vien
void nhapSV(SinhVien& x);
//doc 1 sinh vien
void docSV(FILE* &fp, SinhVien&x);
#endif