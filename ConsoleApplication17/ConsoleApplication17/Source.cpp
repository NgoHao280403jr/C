#include <stdio.h>
#include <math.h>
#include <conio.h>

void main()
{
	int n,s=0;
	for (;;)
	{

		printf("\nmoi nhap n:");
		scanf("%d", &n);
		if (n < 5)
		{
			printf("moi ban nhap lai n > 5!");
		}
		else
			break;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % 5==0)
		{
			s = s + i;
		}
	}
	printf("tong la:%d", s);
	getch();
}