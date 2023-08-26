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
			if (i + j < n - 1 && c[i][j] % 2 == 0)
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
			if (Max < c[j][i] && soNguyenTo(c[j][i]) == 1)
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
		printf("co %d so hoan hao tren duong cheo phu", dem);
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