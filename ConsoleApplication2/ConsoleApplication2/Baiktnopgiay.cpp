#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>
struct nhanVienIT
{
	char MSNV[11];
	char hoTen[31];
	int tuoi;
	int namCongTac;
	char chucVu[31];
	float heSoLuong;
}; 
void nhap1C(int a[], int &n);
void xuat1C(int a[], int n);
void swap(int& m, int& n);
void interchangeSort(int a[], int n);
void phanTuChanBoiCua3(int a[], int n);
void viTriPhanTuMin(int a[], int n);
void quickSort(int a[], int Left, int Right);
int ViTriMin(int a[], int n);
void Delete(int a[], int &n, int k);
void chen(int a[], int n, int k);
int  soHoanChinh(int n);
void demSoHoanChinh(int a[], int n);
int soNguyenTo( int n);
void timSoNguyenTo(int a[], int n);
void demViTriX(int a[], int n);
void docFile(nhanVienIT it[], int& n);
void xuatFile(nhanVienIT it[], int n);
void luongThucLanh(nhanVienIT it[], int n);
void xoanv(nhanVienIT it[], int &n);
void swap1(nhanVienIT &a, nhanVienIT &b);
void sapXepFile(nhanVienIT it[], int n);
void nhapM2C(int c[][50], int &n);
void xuatM2C(int c[][50], int n); 
int ktSoChinhPhuong(int n);
void soChinhPhuongDuongCheoChinh(int c[][50], int n);
void tongTamGiacTren(int c[][50], int n);
void TimGiaTriNguyenToMaxTren1Cot(int c[][50], int n);
float det(int a[][50], int n);
void sapXepDuongCheoChinh(int c[][50], int n);
void demSoHoanHaoDuongCheoPhu(int c[][50], int n);
void XoaCot(int c[][50], int &n);
void tongNguyenToDuongCheoChinh(int c[][50], int n);
void maTranChuyenVi(int c[][50], int n);
void main()
{
	nhanVienIT it[100];
	int a[50],b[50];
	int vitrimin;
	int luachon, n,m, i{},k;
	int c[50][50];
	for (;;)
	{
		system("cls");
		printf("0. thoat");
		printf("\n1. bai 2.1");
		printf("\n2. bai 2.2");
		printf("\n3. bai 2.3");
		printf("\n4. bai 2.4");
		printf("\n5. bai 2.5");
		printf("\n6. bai 2.6");
		printf("\n7. bai 2.7");
		printf("\n8. bai 2.8");
		printf("\n9. bai 2.9");
		printf("\n10. bai 2.10");
		printf("\n11. bai 4.2");
		printf("\n12. bai 4.3");
		printf("\n13. bai 4.4");
		printf("\n14. bai 4.5");
		printf("\n15. bai 3.1");
		printf("\n16. bai 3.2");
		printf("\n17. bai 3.3");
		printf("\n18. bai 3.4");
		printf("\n19. bai 3.5");
		printf("\n20. bai 3.6"); 
		printf("\n21. bai 3.7");
		printf("\n22. bai 3.8");
		printf("\n23. bai 3.9");
		printf("\n24. bai 3.10");
		printf("\nmoi nhap lua chon: ");
		scanf("%d", &luachon);
		if (luachon == 0)break;
		switch (luachon)
		{
		case 1: nhap1C(a, n);
			xuat1C(a, n);
			break;
		case 2: nhap1C(a, n);
			printf("mang truoc khi sap xep: ");
			xuat1C(a, n);
			interchangeSort(a, n);
			printf("\nmang sau khi sap xep la: ");
			xuat1C(a, n);
			break;
		case 3:  nhap1C(a, n);
			xuat1C(a, n);
			printf(" \ncac phan tu chan la boi cua 3 la: ");
			phanTuChanBoiCua3(a, n);
			break;
		case 4: nhap1C(a, n);
			xuat1C(a, n);
			viTriPhanTuMin(a, n);
			break;
		case 5: nhap1C(a, n);
			printf("mang truoc khi sap xep: ");
			xuat1C(a, n);
			quickSort(a, i, n);
			printf("\nmang sau khi sap xep la: ");
			xuat1C(a, n);
			break;
		case 6: nhap1C(a, n);
			xuat1C(a, n);
			vitrimin = ViTriMin(a, n);
			Delete(a, n, vitrimin);
			printf("\nmang sau khi xoa min la: ");
			xuat1C(a, n);
			break;
		case 7: nhap1C(a, n);
			xuat1C(a, n);
			printf("\nnhap vi tri can chen:");
			scanf("%d", &k);
			chen(a, n, k);
			break;
		case 8:nhap1C(a, n);
			xuat1C(a, n);
			demSoHoanChinh(a, n);
			break;
		case 9: nhap1C(a, n);
			timSoNguyenTo(a, n);
		break;
		case 10:nhap1C(a, n);
			xuat1C(a, n);
			demViTriX(a, n);
			break;
		case 11: docFile(it, n);
			xuatFile(it, n);
			break;
		case 12: docFile(it, n);
			luongThucLanh(it, n);
			break;
		case 13: docFile(it, n);
			xuatFile(it, n);
			xoanv(it, n);
			xuatFile(it, n);
			break;
		case 14: docFile(it, n);
			sapXepFile(it, n);
			xuatFile(it, n);
			break;
		case 15: nhapM2C(c, n);
			xuatM2C(c, n);
			break;
		case 16: nhapM2C(c, n);
			xuatM2C(c, n);
			printf("cac so chinh phuong tren duong cheo chinh la:");
			soChinhPhuongDuongCheoChinh(c, n);
			break;
		case 17:  nhapM2C(c, n);
			xuatM2C(c, n);
			tongTamGiacTren(c, n);
			break;
		case 18:  nhapM2C(c, n);
			xuatM2C(c, n);
			TimGiaTriNguyenToMaxTren1Cot(c, n);
			break;
		case 19: nhapM2C(c, n);
			xuatM2C(c, n);
			printf("\nDinh thuc cua ma tran La:%4.2f ", det(c, n));
			break;
		case 20: nhapM2C(c, n);
			xuatM2C(c, n);
			sapXepDuongCheoChinh(c, n);
			break;
		case 21:nhapM2C(c, n);
			xuatM2C(c, n);
			demSoHoanHaoDuongCheoPhu(c, n);
			break;
		case 22: nhapM2C(c, n);
			xuatM2C(c, n);
			XoaCot(c, n);
			break;
		case 23: nhapM2C(c, n);
			xuatM2C(c, n);
			tongNguyenToDuongCheoChinh(c, n);
			break;
		case 24: nhapM2C(c, n);
			xuatM2C(c, n);
			maTranChuyenVi(c, n);
			break;
		default:
			break;
		}
		getch();
	}
}
void nhap1C(int a[], int &n)
{
	printf("moi nhap kich thuoc mang");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
}
void xuat1C(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%5d", a[i]);
	}
}
void swap(int& m, int& n)
{
	int swap = m;
	m = n;
	n = swap;
}
void interchangeSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void phanTuChanBoiCua3(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && a[i] % 3 == 0)
		{
			printf("%5d", a[i]);
		}
	}
}
void viTriPhanTuMin(int a[], int n)
{
	int min = a[0];
	int d;
	for (int i = 1; i < n; i++)
	{
		if (min>a[i])
		{
			min = a[i];
			d = i;
		}
	}
	printf("vi tri phan tu min la: %d", d + 1);
}
void quickSort(int a[], int Left, int Right)
{
	int i = Left, j = Right, Mid = (Left + Right) / 2;
	int x = a[Mid];
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i < j);
	if (Left < j) quickSort(a, Left, j);
	if (Right > i) quickSort(a, i, Right);
}
int ViTriMin(int a[], int n)
{
	int min = a[0], vitri = 0;
	for (int i = 1; i<n; i++)
	{
		if (a[i]<min)
		{
			min = a[i];
			vitri = i;
		}
	}
	return vitri;
}
void Delete(int a[], int &n, int k)
{
	for (int i = k; i<n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void chen(int a[], int n, int k)
{
	int x;
	printf("\nnhap so can chen:");
	scanf("%d", &x);
	for (int i = n; i >= k; i--)
	{
		a[i] = a[i - 1];
	}
	a[k] = x;
	n++;
	printf("mang sau khi chen la: ");
	xuat1C(a, n);
}
int  soHoanChinh(int n)
{
	int s = 0;
	for (int i = 1; i < n; i++)
	{
		if (n%i == 0)
		{
			s = s + i;
		}
	}
	if (s == n)
		return 1;
	return 0;
}
void demSoHoanChinh(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if(soHoanChinh(a[i])==1)
			dem++;
	}
	printf("\nmang co %d so hoan thien", dem);
}
int soNguyenTo( int n)
{
	int dem=0;
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt((float)n); i++)
		{
		if (n % i == 0)
			dem++;
		}
	if (dem == 0)
		return 1;
	return 0;
}
void timSoNguyenTo(int a[], int n)
{
	int b[50],nb=0;
	for (int i = 0; i < n; i++)
	{
		if (soNguyenTo(a[i]) == 1)
		{
			b[nb] = a[i];
			nb++;
		}
	}
	printf("\ncac so nguyen to cua mang b la: ");
	xuat1C(b, nb);
	interchangeSort(b, nb);
	printf("\nsap xep so nguyen to tang dan trong mang b la: ");
	xuat1C(b, nb);
}
void demViTriX(int a[], int n)
{
	int x,dem=0;
	printf("\nnhap so can tim x: ");
	scanf("%d", &x);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			dem++;
	}
	printf("\nso lan %d xuat hien trong mang %d lan", x, dem);
}
void docFile(nhanVienIT it[], int& n)
{
	FILE* f;
	f = fopen("nhanvienIT.txt", "rt");
	fscanf(f, "%d ", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%[^#]#%[^#]#%d#%d#%[^#]#%f\n", &it[i].MSNV,&it[i].hoTen,&it[i].tuoi,&it[i].namCongTac,&it[i].chucVu,&it[i].heSoLuong);
	}
	fclose(f);
}
void xuatFile(nhanVienIT it[], int n)
{
	printf("\n%-15s%-20s%-10s%-15s%-20s%-15s", "MSNV", "HO VA TEN", "TUOI", "NAM CONG TAC","CHUC VU","HE SO LUONG");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-15s%-20s%-10d%-15d%-20s%-15.2f", it[i].MSNV, it[i].hoTen, it[i].tuoi, it[i].namCongTac, it[i].chucVu, it[i].heSoLuong);
	}
}
void luongThucLanh(nhanVienIT it[], int n)
{
	float luongthuclanh;
	int luongcoban = 1490;
	int phucapchucvu;
	char s1[] = "Truong Phong";
	char s2[] = "Giam Doc";
	printf("\n%-15s%-20s%-10s", "MSNV", "HO VA TEN", "LUONG THUC LANH");
	for (int i = 0; i < n; i++)
	{
		if (strcmpi(it[i].chucVu, s2) == 0)
		{
			phucapchucvu = 1000;
		}
		else if (strcmpi(it[i].chucVu, s1) == 0)
		{
			phucapchucvu = 500;
		}
		else 
		{ 
			phucapchucvu = 0; 
		}
		luongthuclanh = it[i].heSoLuong*luongcoban + phucapchucvu;
		printf("\n%-15s%-20s%-10.2f", it[i].MSNV, it[i].hoTen, luongthuclanh);
	}
}
void xoanv(nhanVienIT it[], int &n)
{
	int xoa;
	printf("\nvui long nhap stt nhan vien muon xoa: ");
	scanf("%d", &xoa);
	for (int i = xoa-1; i < n; i++){
		it[i] = it[i + 1];
	}
	n--;
}
void swap1(nhanVienIT &a, nhanVienIT &b)
{
	nhanVienIT v = a;
	a = b;
	b = v;
}
void sapXepFile(nhanVienIT it[], int n)
{
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (it[i].heSoLuong < it[j].heSoLuong)
				swap1(it[i], it[j]);
		}
	}
}
void nhapM2C(int c[][50], int &n)
{
	printf("moi nhap kich thuoc mang ma tran: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < n; j++)
		{
			printf("c[%d][%d]=", i, j);
			scanf("%d", &c[i][j]);
		}
	}

}
void xuatM2C(int c[][50], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", c[i][j]);
		}
		printf("\n");
	}
}
int ktSoChinhPhuong(int n)
{
	float i = 0;
	while (i <= n)
	{
		if (pow(i, 2) == n)
		{
			return 1;
		}
		i++;
	}
	return 0;
}
void soChinhPhuongDuongCheoChinh(int c[][50], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j&&ktSoChinhPhuong(c[i][j]) == 1)
			{
				printf("%d", c[i][j]);
				dem++;
			}
		}
	}
	if (dem == 0)
	{
		printf("khong co so chinh phuong!");
	}
}
void tongTamGiacTren(int c[][50], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j < n - 1&&c[i][j]%2==0)
			{
				s += c[i][j];
			}
		}
	}
	printf("tong phan tu chan cua tam giac tren duong cheo phu la: %d", s);
}
void TimGiaTriNguyenToMaxTren1Cot(int c[][50], int n)

{
	int dem = 0;
	for (int i = 0; i < n; i++)

	{
		int Max = 0;
		for (int j = 0; j < n; j++)
		{
			if (Max < c[j][i]&&soNguyenTo(c[j][i])==1)
			{
				Max = c[j][i];
				dem++;
			}
		}
		if (dem == 0)
		{
			printf("khong co so nguyen to nao!");
		}
		else
		{
			printf("\nCot %d: ", i);
			printf("Gia tri max %d", Max);
		}
	}
}
float det(int a[][50], int n)
{
	int i, j, k, dem = 0, kt;
	float b[100], h, det = 1, c[100];
	for (i = 0; i<n - 1; i++)
	{
		if (a[i][i] == 0)
		{
			kt = 0;
			for (j = 0; j<n; j++)
			if (a[i][j] != 0)
			{
				for (k = 0; k<n; k++)
				{// Doi cot j voi cot i
					c[k] = a[k][i];
					a[k][i] = a[k][j];
					a[k][j] = c[k];
				}
				dem++;// dem so lan doi cot
				kt++;// Kiem tra xem co so 0 o dong i cot j
				break;
			}
			if (kt == 0) return 0;
		}
		
		b[i] = a[i][i];
		for (j = 0; j<n; j++) a[i][j] = a[i][j] / b[i];//tao so 1 o dong i,cot i
		for (j = i + 1; j<n; j++)
		{
			h = a[j][i];
			for (k = 0; k<n; k++) a[j][k] = a[j][k] - h*a[i][k];//lay dong thu j-h*dong i
		}
	}
	b[n - 1] = a[n - 1][n - 1];
	for (i = 0; i<n; i++) det = det*b[i];// Nhan cac so da lay ra ngoai dinh thuc
	if (dem % 2 == 0) return det;
	else return -det;
}
void sapXepDuongCheoChinh(int c[][50], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j<n; j++)
		{
			if (c[i][i]>c[j][j])
			{
				swap(c[i][i], c[j][j]);
			}
				
		}
	}
	printf("ma tran sau khi duoc sap xep:\n");
	xuatM2C(c, n);
}
void demSoHoanHaoDuongCheoPhu(int c[][50], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == n - 1 && soHoanChinh(c[i][j]) == 1)
				dem++;
		}
	}
	if (dem == 0)
		printf("k co so hoan hao tren duong cheo phu!");
	else
	{
		printf("co %d so hoan hao tren duong cheo phu",dem);
	}
}
void XoaCot(int c[][50], int &n)
{	
	
	int cot; 
	
	printf("nhap cot can xoa:"); 
	scanf("%d", &cot);
	for (int i = 0; i < n; i++)
	{
		int m = n;
		for (int j = cot; j < m - 1; j++)
		{
			c[i][j] = c[i][j + 1];
			
		}
		m--;
	}
	printf("ma tran sau khi xoa la:\n");
	xuatM2C(c, n);
}
void tongNguyenToDuongCheoChinh(int c[][50], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j&&soNguyenTo(c[i][j]) == 1)
				s += c[i][j];
		}
	}
	printf("tong so nguyen to tren duong cheo chinh la: %d", s);
}
void maTranChuyenVi(int c[][50], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++) 
		{
			swap(c[i][j], c[j][i]);
		}
	}

	printf("\nMa tran chuyen vi cua ma tran da cho la:\n");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%5d", c[i][j]);
		}
	}
}