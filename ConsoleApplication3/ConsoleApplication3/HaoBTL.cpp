#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
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
void nhapM2C(int a[][50], int &n)
{
	printf("moi nhap kich thuoc mang ma tran: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("c[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}

}
void xuatM2C(int a[][50], int n)
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

int kiemTra1CotMaTranCoGiamDan(int a[][50], int x, int hang)
{ 
	int flag = 0; 
	for (int i = 0; i < hang - 1; i++)
		{ for (int k = i + 1; k < hang; k++)
			{ if (a[x][i] < a[x][k])
				{ 
					flag = 1; 
					break;
				}
			} 
		}return flag; 
}
void cotGiamDan(int a[][50], int dong, int cot)
{ 
	for (int i = 0; i < cot; i++)
	{
		for (int j = 0; j < dong; j++)
		{
			if (kiemTra1CotMaTranCoGiamDan(a, i, cot) == 1)
				printf("%d", a[j][i]);
		}
	}
}
void lietKeCacCotGiamDan(int a[][50], int dong, int cot) 
{ 
	int i, j, flag; 
	for (j = 0; j < cot; j++) 
		{ for (flag = 1, i = 0; i < dong - 1; i++) 
			{ if (a[i][j] < a[i + 1][j])
				{ 
					flag = 0; 
					break; 
				} 
			}	
				if (flag == 1)
					{	
					printf("\nCot a[%d] giam", j); 
					} 
		} 
}


int CntMaxInMatrix(int a[][50], int nRow, int nCol)
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
void tongDuongCheoChinh(int a[][50], int n)
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
	printf("\n%-30s%-20s%-20s%-15s%-20s%-15s%-15s", "HO VA TEN", "SDT", "VE NGUOI LON","VE TRE EM","TEN PHIM","PHONG CHIEU","XUAT CHIEU");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-30s%-20s%-20d%-15d%-20s%-15s%-15s", kh[i].hoTen, kh[i].soDT, kh[i].veNL, kh[i].veTE, kh[i].tenPhim, kh[i].phongChieu, kh[i].xuatChieu);
	}
}
void xuat1KH(khachhang kh[], int i)
{
	printf("\n%-30s%-20s%-20s%-15s%-20s%-15s%-15s", "HO VA TEN", "SDT", "VE NGUOI LON", "VE TRE EM", "TEN PHIM", "PHONG CHIEU", "XUAT CHIEU");
	printf("\n%-30s%-20s%-20d%-15d%-20s%-15s%-15s", kh[i].hoTen, kh[i].soDT, kh[i].veNL, kh[i].veTE, kh[i].tenPhim, kh[i].phongChieu, kh[i].xuatChieu);
}
void timKH(khachhang kh[], int n)
{
	char add[11],adds[11];
	printf("\nVui long nhap phong chieu can tim: ");
	rewind(stdin);
	gets(add);
	printf("\nVui long nhap xuat chieu can tim: ");
	rewind(stdin);
	gets(adds);
	for (int i = 0; i < n; i++){
		if (strcmpi(add, kh[i].phongChieu) == 0 && strcmpi(adds, kh[i].xuatChieu) == 0)
			xuat1KH(kh, i);
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
return (pow(-1.0, n)*((2*n-1+2*n) / giaithua(2.0*n)))+bai9d(n-1);

}
int bai14(int n)
{
	if (n < 6)
		return n;
	return bai14(n - 5) + bai14(n - 4) + bai14(n - 3) + bai14(n - 2) + bai14(n - 1);
}
float bai19(int n)
{
	if (n == 1)
		return 1;
	else
	return bai19(2.0 * n) - n - 2;
	return (bai19(2.0 * n + 1) - 1.0*n*n - 1) / bai19(1.0*n + 1);
}
void main()
{
	int n;
	int a[50][50];
	khachhang  kh[100];
	/*nhapM2C(a, n);
	xuatM2C(a, n);*/
	/*printf("so phan tu cuc dai la %d", CntMaxInMatrix(a, n, n));*/
	/*lietKeCacCotGiamDan(a, n, n);*/
	/*tongDuongCheoChinh(a, n);*/
	/*docFile(kh, n);
	xuatFile(kh, n);
	timKH(kh, n);*/
	printf("moi nhap n:");
	scanf("%d", &n);
	printf("bai 9 :%.2f", bai19(n));
	getch();
}
void tongDoanhThu(khachhang kh[], int n)
{
	char dt[20];
	int s = 0;
	printf("\nVui long nhap phim can tim: ");
	rewind(stdin);
	gets(dt);
	for (int i = 0; i < n; i++)
	{
		if (strcmpi(dt, kh[i].tenPhim) == 0)
		{
			s = kh[i].veNL * 40000 + kh[i].veTE * 20000;
		}
	}
	printf("doanh thu cua phim %s la:%d", dt, s);
}