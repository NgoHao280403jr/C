#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"BinarySearchTree.h"
#include"hinhcay.h"
TNode*createTNode(tuDien x)
{
	TNode*p = new TNode;
	if (p == NULL)
	{
		printf("khong du bo nho! ");
		getch();
		return NULL;
	}
	p->info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;

}
void initBSTree(BSTree &bst)
{
	bst.Root = NULL;
}
int insertTNode(TNode *&root, TNode*p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		strcpy(root->info.ta, p->info.ta);
		strcpy(root->info.tv, p->info.tv);
		return 1;
	}
	
	if (strcmp(root->info.ta, p->info.ta)==0 )
		return 0;
	else if (strcmp(root->info.ta, p->info.ta)>0 )
		insertTNode(root->Left, p);
	else
		insertTNode(root->Right, p);
	return 1;

}
void createBSTree_FromFile(BSTree&bst)
{

	tuDien k;
	int n;
	initBSTree(bst);
	FILE*f;
	f = fopen("tuDien.txt", "r");
	if (f == NULL)
	{
		printf("Loi file");
		return;
	}
	fscanf(f, "%d\n", &n);
	for (int i = 0; i<n; i++)
	{
		fscanf(f, "%[^\#]#%[^\#]#\n",k.ta,k.tv);
		TNode*p = createTNode(k);
		insertTNode(bst.Root, p);
	}
	fclose(f);
}
void traverseLNR(TNode*Root)
{
	if (Root == NULL) return;
	traverseLNR(Root->Left);
	printf("%-10s:%-15s\n", Root->info.ta, Root->info.tv);
	traverseLNR(Root->Right);
}
void search_word(TNode*root, char ta1[])
{
	
	if (root != NULL)
	{
		if (strcmp(root->info.ta, ta1) == 0)
			printf("%s", root->info.tv);
		else if (strcmp(root->info.ta, ta1)>0)
			return search_word(root->Left, ta1);
		else return search_word(root->Right, ta1);
	}
	else
	{
		printf("Khong co trong tu dien!\n");
		return ;
	}
}
void search(TNode *root)
{
	char ta[30];
	fflush(stdin);
	printf("English:");
	gets(ta);
	printf("Vietnamese:"); 
	search_word(root, ta);
}