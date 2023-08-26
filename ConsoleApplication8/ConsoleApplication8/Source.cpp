/*
Họ và tên: Ngô Văn Nhật Hào
Lớp: 12DHTH17
Buổi/Tiết: ST6/12345

*/
//======================================================================
#include<stdio.h>
#include<conio.h>
//======================================================================
//Phần khai báo
//======================================================================
#define MAX 50
struct Graph
{
	int flag;
	int n;
	int m[MAX][MAX];
};

void initGraph(Graph &g);
void showGraph(Graph g);
void docMaTranKe(Graph &g);
void docDanhSachCanh(Graph &g);
bool docDanhSachKe(Graph &g,char fileName[]);
void saveGraph(Graph g, char fileName[]);
void ghiDanhSachCanh(Graph &g, char fileName[]);
//======================================================================
//Phần chương trình chính (main)
//======================================================================
void main()
{
	Graph g1, g2, g3;
	docMaTranKe(g1);
	showGraph(g1);
	docDanhSachCanh(g2);
	showGraph(g2);
	docDanhSachKe(g3,"data2.txt");
	showGraph(g3);
	saveGraph(g2,"HAM.OUT.txt");
	ghiDanhSachCanh(g2, "test.txt");
	getch();
}




//======================================================================
//Phần định nghĩa hàm
//======================================================================
void initGraph(Graph &g)
{
	g.flag = 0;
	g.n = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			g.m[i][j] = 0;
		}
	}

}
void showGraph(Graph g)
{
	if (g.flag == 0)
	{
		printf("\n DO THI VO HUONG\n");
	}
	else
	{
		printf("\n DO THI CO HUONG\n");
	}
	printf("     ");
	for (int i = 0; i < g.n; i++)
	{
		printf("%5d", i + 1);
	}
	printf("\n\n");
	for (int i = 0; i < g.n; i++)
	{
		printf("%5d", i + 1);
		for (int j = 0; j < g.n; j++)
		{
			printf("%5d", g.m[i][j]);
		}
		printf("\n");
	}
}
void docMaTranKe(Graph &g)
{
	initGraph(g);
	FILE *f;
	f = fopen("data.txt", "rt");
	if (!f) return;
	fscanf(f, "%d\n", &g.flag);
	fscanf(f, "%d\n", &g.n);
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			fscanf(f, "%d\n", &g.m[i][j]);
		}
	}
	fclose(f);
}
void docDanhSachCanh(Graph &g)
{
	initGraph(g);

	FILE *f;
	f = fopen("data1.txt", "rt");
	if (!f) return;
	fscanf(f, "%d", &g.flag);
	fscanf(f, "%d", &g.n);
	int canh, dinhdau, dinhcuoi;
	fscanf(f, "%d", &canh);
	for (int i = 0; i < canh; i++)
	{
		fscanf(f, "%d%d", &dinhdau, &dinhcuoi);
		g.m[dinhdau][dinhcuoi] = 1;
		if (g.flag == 0)
		{
			g.m[dinhcuoi][dinhdau] = 1;
		}
	}
	fclose(f);
}
bool docDanhSachKe(Graph &g,char fileName[])
{
	initGraph(g);
	FILE *f;
	f = fopen(fileName, "rt");
	if (!f)
	{
		printf("loi mo file de doc!");
		return false;
	}
	fscanf(f, "%d", &g.flag);
	fscanf(f, "%d", &g.n);	
	int soTPLT, dinhdau, dinhcuoi;
	fscanf(f, "%d", &soTPLT);
	for (int i = 0; i < soTPLT; i++)
	{
		fscanf(f, "%d", &dinhdau);
		while (true)
		{
			char chEnd;
			fscanf(f, "%c", &chEnd);
			if (chEnd == 10)break;
			fscanf(f, "%d", &dinhcuoi);
			g.m[dinhdau][dinhcuoi] = 1;
			if (g.flag == 0)
			{
				g.m[dinhcuoi][dinhdau] = 1;
			}
			if (i == soTPLT - 1)break;
		}
	}
	fclose(f);
	return true;
}
void saveGraph(Graph g,char fileName[])
{
	FILE *f;
	f = fopen(fileName, "wt");
	if (!f)
	{
		printf("loi mo file de ghi!");
		return;
	}
	if (g.flag == 0)
	{
		fprintf(f,"\n DO THI VO HUONG\n");
	}
	else
	{
		fprintf(f,"\n DO THI CO HUONG\n");
	}
	fprintf(f, "So dinh: %d\n", g.n);
	fprintf(f,"     ");
	for (int i = 0; i < g.n; i++)
	{
		fprintf(f,"%5d", i + 1);
	}
	fprintf(f,"\n\n");
	for (int i = 0; i < g.n; i++)
	{
		fprintf(f,"%5d", i + 1);
		for (int j = 0; j < g.n; j++)
		{
			fprintf(f,"%5d", g.m[i][j]);
		}
		fprintf(f,"\n");
	}
}
//void ghiDanhSachKe(Graph &g,char fileName[])
//{
//	
//	
//	FILE *f;
//	f = fopen(fileName, "wt");
//	if (!f) return;
//	fprintf(f, "%d\n", g.flag);
//	fprintf(f, "%d\n", g.n);
//	int canh=0, dinhdau, dinhcuoi;	
//	for (dinhdau = 0; dinhdau < g.n; dinhdau++)
//	{
//		fprintf(f, "%d\t", dinhdau);
//
//		for (dinhdau = 0; dinhdau < g.n; dinhdau++)
//		{
//			for (dinhcuoi = 0; dinhcuoi < g.n; dinhcuoi++)
//			{
//				if (g.m[dinhdau][dinhcuoi] == 1)
//				{
//					canh++;
//					fprintf(f, "%d", dinhcuoi);
//				}
//			}
//		}
//	}
//	fprintf(f, "%d\n", canh);
//	fclose(f);
//}
void ghiDanhSachCanh(Graph &g, char fileName[])
{


	FILE *f;
	f = fopen(fileName, "wt");
	if (!f) return;
	fprintf(f, "%d\n", g.flag);
	fprintf(f, "%d\n", g.n);
	int canh = 0, dinhdau, dinhcuoi;
	for (dinhdau = 0; dinhdau < g.n; dinhdau++)
	{
		for (dinhcuoi = 0; dinhcuoi < g.n; dinhcuoi++)
		{
			if (dinhdau < dinhcuoi&&g.m[dinhdau][dinhcuoi] == 1)
			{
				canh++;
				fprintf(f, "%d\t%d\n", dinhdau, dinhcuoi);
			}
		}
	}
	fprintf(f, "%d\n", canh);
	fclose(f);
}