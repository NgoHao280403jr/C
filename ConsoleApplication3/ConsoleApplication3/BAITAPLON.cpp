#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
struct khachhang
{
	char hoTen[30];
	char soDT[11];
	int veNL, veTE;
	char tenPhim[20];
	char phongChieu[20];
	char xuatChieu[20];
	int tienTra;
};
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
void nhapmangNN(float a[], int&n);//Mang 1C
void xuatmangNN(float a[], int n);
float tongMang(float a[], int n);
void daoNguocMang(float a[], int n);
void kiemTraMangDoiXung(float a[], int n);
void soLanXuatHien(int a[], int n);
float trungBinhCong(float a[], int n);
void tongSoDuong(float a[], int n);
int kiemTraTangDan(float a[], int n);
void tamGiacTren(int a[][MAX], int n);//Ma tran bai2
void nhapMaTran(int a[][MAX], int &n);
void xuatMaTran(int a[][MAX], int n);
int tinhTongDong(int a[][MAX], int i, int n);//Ma tran bai4
int tongDongChanMin(int a[][MAX], int n);
void tongDuongCheoChinh(int a[][MAX], int n);//bai 5
int tongChanTamGiacTren(int a[][MAX], int n);
int tongLeTamGiacDuoi(int a[][MAX], int n);//bai 7
void xuatCacPTTrenDuongCheoPhu(int a[][MAX], int n);
void xuatDong(int a[][MAX], int n, int i);//bai 9
void xuatPhanTuBien(int a[][MAX], int n);
int kiemTraDongTangDan(int a[][MAX], int i, int n);
void xuatCacDongTangDan(int a[][MAX], int n);
void xuatCot(int a[][MAX], int n, int j);//bai 10
int kiemTraCotGiamDan(int a[][MAX], int j, int n);
void xuatCacCotGiamDan(int a[][MAX], int n);
void ChuyenCotKvaL(int a[][MAX], int n);// bai 12
void BubbleSortA(int a[MAX][MAX], int n);// bai 13
void HoanDoi(int &a, int &b);
void sapXepTongDongTang(int a[][MAX], int n);//bai14
int CntMaxInMatrix(int a[][MAX], int nRow, int nCol);//bai15
void docFile(khachhang kh[], int& n);//docflie cau b
void xuatFile(khachhang kh[], int n);//cau c
void tinhTienMoiKH(khachhang kh[], int n);//d
int tinhTongDoangThu(khachhang a[], int n);//cau e
void xuat1KH(khachhang kh[], int i);//cau g 
void timKH(khachhang kh[], int n);
void swap1(khachhang &a, khachhang &b);//cau h
void sapXep(khachhang kh[], int n);
void sapXepTenKH(khachhang kh[], int n);// cau i
void sapXepTangDan(khachhang a[], int n);//cau j
void xuat1KHs(khachhang d);
void BinarySearch(khachhang a[], int n);
float bai9a(int n);//de quy bai 9
int bai9b(int n);
int tong(int n);
int bai9c(int n);
float giaithua(int n);
float bai9d(int n);
int Fibonacci(int x);// bai 10
int tinhXn(int n);// bai 12
int tinhYn(int n);
int CapSoNhan(int n, int a, int q);//bai 13
int bai14(int n);// bai 14
int Cau15(int n);
int Cau17(int n);
int rec_c18(int n);
float Bai19(int n);
int tongChanA(int a[], int n);//de quy bai 2a 
void taoM1C(int a[], int &n);
void xuatM1C(int a[], int n);
void sapXepDQ(int a[], int n);//de quy bai 2b
void swap(int &a, int &b);
int nhiPhan(int a[], int x, int start, int end);
int MaxChan(int a[], int n, int i, int max);//cau c
int tongLeA(int a[], int n);//cau d 
void xuatSoViTriLe(int a[], int n);//cau e 
int ChuSoDauTien(int a);//de quy bai 8 a
int deQui(int n, int sdn);
int ChuSoLonNhat(int n, int &max1);
int sonhonhat(int n);
int KTToanLe(int n); 
int KTToanChan(int n);
void nhapFile(SinhVien a[], int &n);
void DTB(SinhVien a[], int n);
void xuat(SinhVien a[], int n);
void xuat1SV(SinhVien a);
void xuatNSV(SinhVien a[], int n);
void timSVDTBMax(SinhVien a[], int n);
void InterchangeSort(SinhVien a[], int n);
void SelectionSort(SinhVien a[], int n);
void timKiemSV(SinhVien a[], int n);
void timSVLonTuoi(SinhVien a[], int n);
void SelcetionSort(SinhVien a[], int n);
void sapXepTen(SinhVien a[], int n);
void BinarySort(SinhVien a[], int n);
void main()
{
	int luachon, b[50];
	float a[50];
	int n,m,f,q,x,sdn,max1;
	int c[MAX][MAX];
	khachhang  kh[100];
	SinhVien sv[100];
	int kq = nhiPhan(b, x, 0, n - 1);
	int max = -1;
	int kq1 = MaxChan(b, sizeof(b) / sizeof(int), 0, max);
	for (;;)
	{
		system("cls");
		printf("*******************************************************************************************\n");
		printf("0.thoat");
		printf("\n1.Tao mang 1 chieu, Xuat mang mot chieu");
		printf("\n2.Tinh tong cac gia tri mang");
		printf("\n3.Tinh gia tri trung binh cac phan tu trong mang");
		printf("\n4.Tinh tong cac gia tri duong trong mang");
		printf("\n5.Dao nguoc cac gia tri mang");
		printf("\n6.Kiem tra tinh doi xung cua mang(***)");
		printf("\n7.Tim phan tu xuat hien nhieu nhat trong mang");
		printf("\n8.Kiem tra mang tang khong");
		printf("\n9.Xuat cac phan tu tren duong cheo phu");
		printf("\n10.Xuat cac phan tu thuoc tam giac tren");
		printf("\n11.Tim cot co tong lon nhat trong ma tran");//
		printf("\n12.Tim dong co tong nho nhat trong ma tran");
		printf("\n13.Tinh tong cac phan tu tren duong cheo chinh");
		printf("\n14.Tinh tong cac phan tu chan thuoc tam giac tren");
		printf("\n15.Tinh tong cac phan tu le thuoc tam giac duoi");
		printf("\n16.Xuat cac phan tu thuoc cac duong bien cua ma tran");
		printf("\n17.Xuat cac dong tang dan");
		printf("\n18.Xuat cac cot giam dan");
		printf("\n19.Chuyen doi vi tri hai dong k va l trong ma tran");//
		printf("\n20.Chuyen doi vi tri hai cot k va l trong ma tran");
		printf("\n21.Sap xep ma tran tang dan theo dong(***)");
		printf("\n22.Sap xep ma tran theo quy tac tong cac dong tang dan");
		printf("\n23.Dem so phan tu cuc dai trong ma tran");
		printf("\n24.Nhap danh sach cac sinh vien cho mot lop,Xuat danh sach sinh vien");
		printf("\n25.Tim sinh vien co diem trung binh cao nhat");
		printf("\n26.Sap xep danh sach lop theo thu tu tang dan cua diem trung binh");
		printf("\n27.Sap xep danh sach lop theo thu tu giam dan cua diem toan");
		printf("\n28.Tim va in ra cac sinh vien co diem trung binh lon hon 5 va khong co mon nao duoi 3");
		printf("\n29.Tim sinh vien co tuoi lon nhat");
		printf("\n30.Tim sinh vien bat ky Nhap ten sinh vien va xuat ra sinh vien do(Selection sort)(***)");
		printf("\n31.Tim sinh vien bat ky Nhap ten sinh vien va xuat ra sinh vien do(Binart Sort )");
		printf("\n32.Doc danh sach khach hang tu file, Xuat danh sach khach hang");
		printf("\n33.Tinh tien moi khach hang phai tra");
		printf("\n34.Tinh tong doanh thu cua rap phim(***)");
		printf("\n35.Xuat thong tinh khach hang dat ve cua phong chieu x va xuat chieu y");
		printf("\n36.Sap xep danh sach khach hang theo so tien phai tra tang dan");
		printf("\n37.Sap xep danh sach tang dan theo ho ten");
		printf("\n38.Tim khach hang co ten Nguyen Van An voi danh sach da sap xep theo giai thuat Binary search");
		printf("\n39.bai9 a,b,c,d(***)");
		printf("\n40.bai10");
		printf("\n41.bai11"); //
		printf("\n42.bai12");
		printf("\n43.bai13");
		printf("\n44.bai14");
		printf("\n45.bai15");
		printf("\n46.bai16");//
		printf("\n47.bai17");
		printf("\n48.bai18");
		printf("\n49.bai19");
		printf("\n50.bai2 a");
		printf("\n51.bai2 b");
		printf("\n52.bai2 c");
		printf("\n53.bai2 d");
		printf("\n54.bai2 e");
		printf("\n55.bai8 a");
		printf("\n56.bai8 b");
		printf("\n57.bai8 c");
		printf("\n58.bai8 d");
		printf("\n59.bai8 e");
		printf("\n60.bai8 f");
		printf("\n******************************************************************************************\n");
		printf("\nmoi nhap lua chon:");
		scanf("%d", &luachon);
		if (luachon == 0) break;
		switch (luachon)
		{
		case 1: nhapmangNN(a, n);
			xuatmangNN(a, n);
			break;
		case 2: nhapmangNN(a, n);
			xuatmangNN(a, n);
			printf("tong cua mang la:%.2f ", tongMang(a, n));
			break;
		case 3:nhapmangNN(a, n);
			xuatmangNN(a, n);
			printf(" trung binh cong cua mang la:%.2f", trungBinhCong(a, n));
			break;
		case 4:nhapmangNN(a, n);
			xuatmangNN(a, n);
			tongSoDuong(a, n);
			break;
		case 5:nhapmangNN(a, n);
			xuatmangNN(a, n);
			printf("\nmang dao nguoc la: ");
			daoNguocMang(a, n);

			break;
		case 6:nhapmangNN(a, n);
			xuatmangNN(a, n);
			kiemTraMangDoiXung(a, n);
			break;
		case 7: 
			soLanXuatHien(b, n);
			break;
		case 8:nhapmangNN(a, n);
			xuatmangNN(a, n);
			printf("mang tang dan ?:%d ",kiemTraTangDan(a, n));
			break;
		case 9: nhapMaTran(c, n);
			xuatMaTran(c, n);
			xuatCacPTTrenDuongCheoPhu(c, n);
			break;
		case 10: nhapMaTran(c, n);
			xuatMaTran(c, n);
			tamGiacTren(c, n);
			break;
		case 12: nhapMaTran(c, n);
			xuatMaTran(c, n);
			printf("Dong co tong chan nho nhat: %d", tongDongChanMin(c, n));
			break;
		case 13: nhapMaTran(c, n);
			xuatMaTran(c, n);
			tongDuongCheoChinh(c, n);
			break;
		case 14:nhapMaTran(c, n);
			xuatMaTran(c, n);
			printf("tong chan tam giac tren la:%d", tongChanTamGiacTren(c, n));
			break;
		case 15:nhapMaTran(c, n);
			xuatMaTran(c, n);
			printf("\nTong cac phan tu le tam giac duoi = %d", tongLeTamGiacDuoi(c, n));
			break;
		case 16: nhapMaTran(c, n);
			xuatMaTran(c, n);
			printf("\n-------------\n");
			xuatPhanTuBien(c, n);
			break;
		case 17:nhapMaTran(c, n);
			xuatMaTran(c, n);
			printf("dong tang dan la:\n ");
			xuatCacDongTangDan(c, n);
			break;
		case 18: nhapMaTran(c, n);
				xuatMaTran(c, n);
				printf("cot giam dan la:\n");
				xuatCacCotGiamDan(c, n);
				break;
		case 20: nhapMaTran(c, n);
			xuatMaTran(c, n);
			ChuyenCotKvaL(c, n);
			break;
		case 21:nhapMaTran(c, n);
			xuatMaTran(c, n);
			printf("ma tran sau khi sap xep:\n");
			BubbleSortA(c, n);
			xuatMaTran(c, n);
			break;
		case 22:nhapMaTran(c, n);
			xuatMaTran(c, n);
			sapXepTongDongTang(c, n);
			printf("Mang sau khi sap xep theo quy tac tong cac dong tang dan:\n");
			xuatMaTran(c, n);
			break;
		case 23:nhapMaTran(c, n);
			xuatMaTran(c, n);
			printf("so phan tu cuc dai la %d", CntMaxInMatrix(c, n, n));
			break;
		case 24:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   break;
		}
		case 25:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   printf("\n--------------Sinh vien co diem trung binh cao nhat--------------\n");
				   timSVDTBMax(sv, n);
				   break;
		}
		case 26:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   InterchangeSort(sv, n);
				   printf("--------------------------Sau khi sap xep diem trung binh tang dan--------------------------\n");
				   xuat(sv, n);
				   break;
		}
		case 27:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   SelectionSort(sv, n);
				   printf("--------------------------Sau khi sap xep diem toan giam dan--------------------------\n");
				   xuat(sv, n);
				   break;
		}
		case 28:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   printf("----------------------Sinh vien DTB lon hon 5 va khong mon nao duoi 3----------------------\n");
				   timKiemSV(sv, n);
				   break;
		}
		case 29:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   printf("---------------------Sinh vien tuoi cao nhat---------------------\n");
				   timSVLonTuoi(sv, n);
				   break;
		}
		case 30:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   SelcetionSort(sv, n);
				   break;
		}
		case 31:
		{
				   nhapFile(sv, n);
				   DTB(sv, n);
				   xuat(sv, n);
				   sapXepTen(sv, n);
				   BinarySort(sv, n);
				   break;
		}
		case 32: docFile(kh, n);
			xuatFile(kh, n);
			break;
		case 33:docFile(kh, n);
			xuatFile(kh, n);
			tinhTienMoiKH(kh, n);
			break;
		case 34: docFile(kh, n);
			xuatFile(kh, n);
			printf("\ntong doanh thu cua rap phim la:%d", tinhTongDoangThu(kh, n));
			break;
		case 35: docFile(kh, n);
			xuatFile(kh, n);
			timKH(kh, n);
			break;
		case 36: docFile(kh, n);
			xuatFile(kh, n);
			printf("\ndanh sach sau khi sap xep la:\n");
			sapXep(kh, n);
			xuatFile(kh, n);
			break;
		case 37: docFile(kh, n);
			xuatFile(kh, n);
			printf("\ndanh sach sau khi sap xep la:\n");
			sapXepTenKH(kh, n);
			xuatFile(kh, n);
			break;
		case 38:docFile(kh, n);
			xuatFile(kh, n);
			printf("\ndanh sach sau khi sap xep la:\n");
			sapXepTangDan(kh, n);
			xuatFile(kh, n);
			printf("\nTim kiem Nguyen Van An:\n");
			BinarySearch(kh, n);
			break;
		case 39: printf("nhap n:");
			scanf("%d", &n);
			printf("\nbai 9a ket qua: %.2f", bai9a(n));
			printf("\nbai 9b ket qua: %d", bai9b(n));
			printf("\nbai 9c ket qua: %d", bai9c(n));
			printf("\nbai 9d ket qua: %.2f", bai9d(n));
			break;
		case 40: printf("nhap m: ");
			scanf("%d", &m);
			printf("nhap n: ");
			scanf("%d", &n);
			for (int i = m; i <= n; i++)
			{
				if (Fibonacci(i) <= n)
					printf("%6d", Fibonacci(i));
			}
			break;
		case 42:printf("nhap n: ");
			scanf("%d", &n);
			printf("\nXn = %d \t\tYn = %d", tinhXn(n), tinhYn(n));
			break;
		case 43: printf("Nhap n: ");
			scanf("%d", &n);
			printf("Nhap so hang dau tien: ");
			scanf("%d", &f);
			printf("Nhap cong boi: ");
			scanf("%d", &q);
			printf("Phan tu thu n: %d", CapSoNhan(n, f, q));
			break;
		case 44:printf("Nhap n: ");
			scanf("%d", &n);
			printf("ket qua:%d", bai14(n));
			break;
		case 45: printf("Nhap n: ");
			scanf("%d", &n);
			printf("ket qua:%d", Cau15(n));
			break;
		case 47: printf("Nhap n: ");
			scanf("%d", &n);
			printf("ket qua:%d", Cau17(n));
			break;
		case 48: printf("Nhap n: ");
			scanf("%d", &n);
			printf("ket qua:%d", rec_c18(n));
			break;
		case 49: printf("Nhap n: ");
			scanf("%d", &n);
			printf("ket qua:%.2f", Bai19(n));
			break;
		case 50: taoM1C(b, n);
			xuatM1C(b, n);
			tongChanA(b, n);
			break;
		case 51: taoM1C(b, n);
			xuatM1C(b, n);
			printf("\nNhap x can tim: ");
			scanf("%d", &x);
			
			if (kq == -1)
				printf("\n>>Khong tim thay!\n");
			else
				printf("\n>>Tim thay tai vi tri a[%d]\n", kq);
			break;
		case 52: taoM1C(b, n);
			xuatM1C(b, n);	
			if (kq1 == -1)
				printf("\n\nKhong ton tai so chan!");
			else
				printf("\n\nPhan tu chan lon nhat trong mang = %d", kq1);
			break;
		case 53:taoM1C(b, n);
			xuatM1C(b, n);
			printf("\n\n>>Tong cac phan tu le trong mang = %d", tongLeA(b, n));
			break;
		case 54: taoM1C(b, n);
			xuatM1C(b, n);
			printf("\n>>Cac so o vi tri le: ");
			xuatSoViTriLe(b, n);
			break;
		case 55: printf("Nhap n:");
			scanf("%d", &n);
			printf("\nKet qua: %d", ChuSoDauTien(n));
			break;
		case 56: printf("Nhap n:");
			scanf("%d", &n);
			printf("\nKet qua: %d", deQui(n, sdn));
			break;
		case 57: printf("Nhap n:");
			scanf("%d", &n);
			printf("\nKet qua: %d", ChuSoLonNhat(n, max));
			break;
		case 58:	
			printf("Nhap n:");
			scanf("%d", &n);
			printf("\nKet qua: %d", sonhonhat(n));
			break;
		case 59:
			printf("Nhap n:");
			scanf("%d", &n);
			if (KTToanLe(n) == 1)
				printf("Chu so toan le");
			else
				printf("Chu so khong toan le");
			break;
		case 60: printf("Nhap n:");
			scanf("%d", &n);
			if (KTToanChan(n) == 1)
				printf("Chu so toan chan");
			else
				printf("Chu so khong toan chan");
			break;
		
		default:
		break;
		}
		getch();
	}
}
void nhapmangNN(float a[], int&n)
{
	printf("nhap so phan tu mang");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i] = -50 + rand() % 100;
	}
}
void xuatmangNN(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%.2f\t", a[i]);
	}
}
float tongMang(float a[], int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return  a[0];
	return a[n - 1] + tongMang(a, n - 1);
}
float trungBinhCong(float a[], int n)
{
	int s = n;
	if (n == 0)
		return 0;
	return a[n - 1]/s + tongMang(a, n - 1)/s;
}
void daoNguocMang(float a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		printf("%.2f\t", a[i]);
	}
}
void kiemTraMangDoiXung(float a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != a[n - i - 1])
			dem++;
	}
	if (dem = 0)
		printf(" mang doi xung ");
	else
		printf(" mang k doi xung");
}
void soLanXuatHien(int a[], int n)
{
	int i, j, max, gt, dem;
	printf("nhap so phan tu cua mang:");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("a[%d]=", i + 1);
		scanf_s("%d", &a[i]);
	}
	printf("mang da nhap:\n");
	for (i = 0; i < n; i++) printf(" %d ", a[i]);
	max = 1;
	for (i = 0; i < n; i++)
	{
		dem = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i] == a[j]) dem++;
		}
		if (max < dem)
		{
			max = dem;
			gt = a[i];
		}
	}
	printf("\nphan tu xuat hien nhieu nhat la: %d\n voi so lan xuat hien la: %d", gt, max);
}
void tongSoDuong(float a[], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]>0)
		{
			s += a[i];
		}
	}
	printf("tong cso duong la:%.2f", s);
}
int kiemTraTangDan(float a[], int n)
{
	int flag=1;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i]>a[i + 1])
		{
			flag = 0; break; 
		}
	}
	return flag;
}
void nhapMaTran(int a[][MAX], int &n)
{
	printf("\nNhap so luong phan tu mang: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		printf("\nNhap phan tu thu [%d][%d]: ", i, j);
		scanf("%d", &a[i][j]);
	}
}
void xuatMaTran(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
void xuatCacPTTrenDuongCheoPhu(int a[][MAX], int n)
{
	printf("\n ma tran \n");
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}
void tamGiacTren(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	if (i < j)
		printf("%5d", a[i][j]);
}
int tinhTongDong(int a[][MAX], int i, int n)
{
	int Tong = 0;
	for (int j = 0; j < n; j++)
	{
		Tong = Tong + a[i][j];
	}
	return Tong;
}
int tongDongChanMin(int a[][MAX], int n)
{
	int dong = 0;
	for (int i = 0; i < n; i++)
	{
		if (tinhTongDong(a, i, n) % 2 == 0)
		{
			int min = tinhTongDong(a, i, n);
			for (int i = 0; i < n; i++)
			{
				if (tinhTongDong(a, i, n) < min && tinhTongDong(a, i, n) % 2 == 0)
				{
					min = tinhTongDong(a, i, n);
					dong = i;
				}
			}
		}
	}
	return dong;
}
void tongDuongCheoChinh(int a[][MAX], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				s += a[i][j];
			}
		}
	}
	printf("tong duong cheo chinh la: %d", s);
}
int tongChanTamGiacTren(int a[][MAX], int n)
{
	int tong = 0;
	for (int i = 0; i<n - 1; i++)
	for (int j = 0; j<n - 1; j++)
	if (i<j)
	if (a[i][j] % 2 == 0)
		tong = tong + a[i][j];
	return tong;
}
int tongLeTamGiacDuoi(int a[][MAX], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (i > j && a[i][j] % 2 != 0)
			sum += a[i][j];
	}
	return sum;
}
void xuatPhanTuBien(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				printf("%6d", a[i][j]);
		}
	}
}
void xuatDong(int a[][MAX], int n, int i)
{
	for (int j = 0; j < n; j++)
	{
		printf("%6d", a[i][j]);
	}
}
int kiemTraDongTangDan(int a[][MAX], int i, int n)
{
	int flag = 1;
	for (int j = 0; j < n - 1; j++)
	{
		for (int k = j + 1; k < n; k++)
		{
			if (a[i][j] >  a[i][k])
				flag = 0;
		}
	}
	return flag;
}
void xuatCacDongTangDan(int a[][MAX], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (kiemTraDongTangDan(a, i, n) == 1)
		{
			xuatDong(a, n, i);
			printf("\n\n");
			dem++;
		}
	}
	if (dem == 0)
		printf("khong co dong tang!");
}
void xuatCot(int a[][MAX], int n, int j)
{
	for (int i = 0; i < n; i++)
	{
		printf("%6d", a[i][j]);
	}
}
int kiemTraCotGiamDan(int a[][MAX], int j, int n)
{
	int flag = 1;
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			if (a[i][j] >  a[k][j])
				flag = 0;
		}
	}
	return flag;
}
void xuatCacCotGiamDan(int a[][MAX], int n)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
	{
		if (kiemTraDongTangDan(a, j, n) == 1)
		{
			xuatCot(a, n, j);
			printf("\n\n");
			dem++;
		}
	}
	if (dem == 0)
		printf("khong co cot giam !");
}
void ChuyenCotKvaL(int a[][MAX], int n)
{
	int k, l;
	printf("\nNhap vi tri cot k: ");
	scanf("%d", &k);
	printf("\nNhap vi tri cot l: ");
	scanf("%d", &l);
	k--, l--;
	printf("\nMang sau khi chuyen doi cot k va l: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t = j;
			if (t == l)
				t = k;
			else if (t == k)
				t = l;
			printf("%d\t", a[i][t]);
		}
		printf("\n");
	}
}
void BubbleSortA(int a[MAX][MAX], int n)
{
	for (int k = 0; k<n; k++)
	for (int i = 0; i<n - 1; i++)
	for (int j = n - 1; j>i; j--)
	if (a[k][j]<a[k][j - 1])
	{
		int temp = a[k][j];
		a[k][j] = a[k][j - 1];
		a[k][j - 1] = temp;
	}
}
void HoanDoi(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void sapXepTongDongTang(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = i + 1; k < n; k++)
		if (tinhTongDong(a, i, n) > tinhTongDong(a, k, n))
		{
			for (int j = 0; j < n; j++)
			{
				HoanDoi(a[i][j], a[k][j]);
			}
		}
	}
}
int CntMaxInMatrix(int a[][MAX], int nRow, int nCol)
{
	int iRow, iCol;
	int cnt = 0;

	for (iRow = 0; iRow < nRow; iRow++)
	{
		for (iCol = 0; iCol < nCol; iCol++)
		{
			// So sánh với phần tử trước đó trong hàng
			if (iRow - 1 >= 0)
			{
				if (a[iRow][iCol] <= a[iRow - 1][iCol])
					continue;
			}
			// So sánh với phần tử tiếp theo trong hàng
			if (iRow + 1 < nRow)
			{
				if (a[iRow][iCol] <= a[iRow + 1][iCol])
					continue;
			}
			// So sánh với phần tử trước đó trong cột
			if (iCol - 1 >= 0)
			{
				if (a[iRow][iCol] <= a[iRow][iCol - 1])
					continue;
			}
			// So sánh với phần tử tiếp theo trong cột
			if (iCol + 1 < nCol)
			{
				if (a[iRow][iCol] <= a[iRow][iCol + 1])
					continue;
			}
			cnt++;
		}
	}

	return cnt;
}
void docFile(khachhang kh[], int& n)
{
	FILE* f;
	f = fopen("dskh.txt", "rt");
	fscanf(f, "%d ", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%d\n", &kh[i].hoTen, &kh[i].soDT, &kh[i].tenPhim, &kh[i].phongChieu, &kh[i].xuatChieu, &kh[i].veNL, &kh[i].veTE);
	}
	fclose(f);
}
void xuatFile(khachhang kh[], int n)
{
	printf("\n%-30s%-20s%-20s%-15s%-20s%-15s%-15s", "HO VA TEN", "SDT", "VE NGUOI LON", "VE TRE EM", "TEN PHIM", "PHONG CHIEU", "XUAT CHIEU");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-30s%-20s%-20d%-15d%-20s%-15s%-15s", kh[i].hoTen, kh[i].soDT, kh[i].veNL, kh[i].veTE, kh[i].tenPhim, kh[i].phongChieu, kh[i].xuatChieu);
	}
}
int tinhTongDoangThu(khachhang a[], int n)
{
	int TongDoanhThu = 0;
	for (int i = 0; i < n; i++)
	{
		TongDoanhThu = TongDoanhThu + (a[i].veNL * 40000 + a[i].veTE * 20000);
	}
	return TongDoanhThu;
}
void xuat1KH(khachhang kh[], int i)
{
	printf("\n%-30s%-20s%-20s%-15s%-20s%-15s%-15s", "HO VA TEN", "SDT", "VE NGUOI LON", "VE TRE EM", "TEN PHIM", "PHONG CHIEU", "XUAT CHIEU");
	printf("\n%-30s%-20s%-20d%-15d%-20s%-15s%-15s", kh[i].hoTen, kh[i].soDT, kh[i].veNL, kh[i].veTE, kh[i].tenPhim, kh[i].phongChieu, kh[i].xuatChieu);
}
void timKH(khachhang kh[], int n)
{
	char add[11], adds[11];
	printf("\nVui long nhap phong chieu can tim: ");
	rewind(stdin);
	gets(add);
	printf("\nVui long nhap xuat chieu can tim: ");
	rewind(stdin);
	gets(adds);
	for (int i = 0; i < n; i++)
	{
		if (strcmpi(add, kh[i].phongChieu) == 0 && strcmpi(adds, kh[i].xuatChieu) == 0)
			xuat1KH(kh, i);
	}
}
void swap1(khachhang &a, khachhang &b)
{
	khachhang v = a;
	a = b;
	b = v;
}
void sapXep(khachhang kh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (kh[i].veNL * 40000 + kh[i].veTE * 20000 < kh[j].veNL * 40000 + kh[j].veTE * 20000)
				swap1(kh[i], kh[j]);
		}
	}
}
void tinhTienMoiKH(khachhang kh[], int n)
{
	for (int i = 0; i < n; i++)
	{ 
		int s = 0;
		s = kh[i].veNL * 40000 + kh[i].veTE * 20000;
		printf("\nkhach hang %s phai tra la: %d VND\n", kh[i].hoTen, s);
	}
}
void sapXepTenKH(khachhang kh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(kh[i].hoTen, kh[j].hoTen) > 0) 
				swap1(kh[i], kh[j]);
		}
	}
}
void sapXepTangDan(khachhang a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(a[i].hoTen, a[j].hoTen) > 0)
			{
				khachhang kh = a[i];
				a[i] = a[j];
				a[j] = kh;
			}

		}
	}
}
void xuat1KHs(khachhang d)
{
	printf("------------------------------------------------------------\n");
	printf("Ho Ten:%s\n", d.hoTen);
	printf("So dien thoai:");
	puts(d.soDT);
	printf("Ten phim:");
	puts(d.tenPhim);
	printf("Phong chieu:%s \tXuat chieu:%s\n", d.phongChieu, d.xuatChieu);
	printf("Ve nguoi lon:%d \t\t Ve tre em:%d\n", d.veNL, d.veTE);
	printf("------------------------------------------------------------\n\n");
}
void BinarySearch(khachhang a[], int n)
{
	int trai = 0, phai = n - 1;
	char x[31] = "Nguyen Van An";
	while (trai <= phai)
	{
		int mid = (trai + phai) / 2;
		if (strcmp(a[mid].hoTen, x) == 0)
		{
			xuat1KHs(a[mid]);
			break;
		}
		else
		if (strcmp(a[mid].hoTen, x) < 0)
			trai = mid + 1;
		else
			phai = mid - 1;
	}
}
float bai9a(int n)
{
	if (n == 1)
		return 1.0 / 6;
	return  1 / (1.0*n * (n + 1)*(n + 2)) + bai9a(n - 1);
}
int bai9b(int n)
{
	if (n == 1)
		return 1;
	return n*n + bai9b(n - 1);
}
int tong(int n)
{
	if (n == 1)
		return 1;
	return n + tong(n - 1);
}
int bai9c(int n)
{
	if (n == 1)
		return 1;
	return tong(n) + bai9c(n - 1);
}
float giaithua(int n)
{
	if (n == 1)
		return 1;
	return n*giaithua(n - 1);
}
float bai9d(int n)
{
	if (n == 0)
		return 0;
	return (pow(-1.0, n)*((2 * n - 1 + 2 * n) / giaithua(2.0*n))) + bai9d(n - 1);
}
int Fibonacci(int x)
{
	if (x == 1 || x == 2)
		return 1;
	return Fibonacci(x - 1) + Fibonacci(x - 2);
}
int tinhXn(int n)
{
	if (n == 0)
		return 1;
	return tinhXn(n - 1) + tinhYn(n - 1);
}
int tinhYn(int n)
{
	if (n == 0)
		return 0;
	return 3 * tinhXn(n - 1) + 2 * tinhYn(n - 1);
}
int CapSoNhan(int n, int a, int q)
{
	if (n == 1)
		return a;
	return CapSoNhan(n - 1, a, q)*q;
}

int bai14(int n)
{
	if (n < 6)
		return n;
	return bai14(n - 5) + bai14(n - 4) + bai14(n - 3) + bai14(n - 2) + bai14(n - 1);
}
int Cau15(int n)
{
	if (n == 1)
		return 1;
	else
	{
		int sum = 0;
		for (int i = 1; i <= n - 1; i++)
			sum += Cau15(i);
		return n*sum;
	}
}
int Cau17(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return Cau17(n - 1) + (n - 1)*(Cau17(n - 2));
}
int rec_c18(int n)
{
	int i, kq = 0;
	if (n <= 1)
		return n + 1;
	for (i = 1; i <= n; i++)
		kq = kq + i * rec_c18(n - i);
	return kq;
}
float Bai19(int n)
{
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return n / 2 + Bai19(n / 2) + 2;
	if (n % 2 != 0)
		return (n*n - 2 * n + 1) / 4 + Bai19((n - 1) / 2)*Bai19((n + 1) / 2) + 1;
}
void taoM1C(int a[], int &n)
{
	printf("\nNhap so luong phan tu: ");
	scanf("%d", &n);
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

int tongChanA(int a[], int n)
{
	if (n == 0)
		return 0;
	if (a[n - 1] % 2 == 0)
		return a[n - 1] + tongChanA(a, n - 1);
	return tongChanA(a, n - 1);
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void sapXepDQ(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (a[i] > a[j])
		swap(a[i], a[j]);
}
int nhiPhan(int a[], int x, int start, int end)
{
	if (start > end)
		return -1;
	int k = (start + end) / 2;
	if (a[k] == x)
		return k;
	if (x < a[k])
		nhiPhan(a, x, start, k - 1);
	else if (x > a[k])
		nhiPhan(a, x, k + 1, end);
}
int MaxChan(int a[], int n, int i, int max)
{
	if (i == n)
		return max;
	if ((a[i] % 2 == 0) && (a[i] > max))
		max = a[i];
	return MaxChan(a, n, ++i, max);
}
int tongLeA(int a[], int n)
{
	if (n == 0)
		return 0;
	if (a[n - 1] % 2 != 0)
		return a[n - 1] + tongLeA(a, n - 1);
	return tongLeA(a, n - 1);
}
void xuatSoViTriLe(int a[], int n)
{
	if (n == 0)
		return;
	else
	{
		xuatSoViTriLe(a, n - 1);
		if ((n - 1) % 2 != 0)
			printf("%5d\t", a[n - 1]);
	}
}
int ChuSoDauTien(int a)
{
	if (a<10)
		return a;
	else
		return ChuSoDauTien(a / 10);
}
int deQui(int n, int sdn)
{
	if (n == 0)
		return sdn;
	else
	{
		sdn = sdn * 10 + n % 10;
		return deQui(n / 10, sdn);
	}
}
int ChuSoLonNhat(int n, int &max1)
{
	int m;
	if (n == 0)
		return max1;
	else
	{
		m = n % 10;
		if (m>max1)
			max1 = m;
	}
	return ChuSoLonNhat(n / 10, max1);
}
int sonhonhat(int n)
{
	if (n < 10)
		return n;
	if ((n % 10) < sonhonhat(n / 10))
		return n % 10;
	else
		return sonhonhat(n / 10);
}
int KTToanLe(int n)
{
	if (n % 2 == 0 && n != 0)
	{
		return 0;
	}
	if (n % 2 == 1)
	{
		return KTToanLe(n / 10);
	}
	return 1;
}
int KTToanChan(int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return 0;
	}
	if (n % 2 == 0)
	{
		return KTToanChan(n / 10);
	}
	return 1;
}
void nhapFile(SinhVien a[], int &n)
{
	printf(" moi nhap so sinh vien: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Nhap ma sinh vien thu %d: ", i + 1);
		fflush(stdin);
		gets(a[i].MaSV);
		printf("Nhap diem toan cua sinh vien thu %d: ", i + 1);
		scanf("%f", &a[i].Toan);
		printf("Nhap diem Ly cua sinh vien thu %d: ", i + 1);
		scanf("%f", &a[i].Ly);
		printf("Nhap diem Hoa cua sinh vien thu %d: ", i + 1);
		scanf("%f", &a[i].Hoa);
		printf("Nhap nam sinh cua sinh vien thu %d: ", i + 1);
		scanf("%d", &a[i].NamSinh);
		printf("Nhap Ho sinh vien thu %d: ", i + 1);
		fflush(stdin);
		gets(a[i].HT.Ho);
		printf("Nhap Ten sinh vien thu %d: ", i + 1);
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
	printf("\n%-15s%-20s%-15s%-15s%-15s%-15s%-15s", "Ma Sinh Vien", "Ho Ten Sinh Vien", "Nam Sinh", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem Trung Binh");
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