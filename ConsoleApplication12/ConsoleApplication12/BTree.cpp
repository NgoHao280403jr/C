#include"BTree.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
TNode*createTNode(ItemType x)
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
int insertTNode(TNode*&root, TNode*p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	if (root->info == p->info)
		return 0;
	if (p->info<root->info)
		insertTNode(root->Left, p);
	else
		insertTNode(root->Right, p);
	return 1;

}
void createBSTree_FromArray(BSTree&bst,ItemType a[],int n)
{
	
	initBSTree(bst);
	for (int i = 0; i < n; i++)
	{
		TNode*p = createTNode(a[i]);
		insertTNode(bst.Root, p);
	}
}
void traverseLNR(TNode*Root)
{
	if (Root == NULL) return;
	traverseLNR(Root->Left);
	printf("%4d", Root->info);
	traverseLNR(Root->Right);
}
int maxTNode(TNode*root)
{
	TNode*p = root;
	while (p->Right != NULL)
	{
		p = p->Right;
	}
	return p->info;
}
void showTNodeOfLevelK(TNode*root, int k)
{

	if (!root)return;
	if (k == 0)
		printf("%d\t", root->info);
	k--;
	showTNodeOfLevelK(root->Left, k);
	showTNodeOfLevelK(root->Right, k);
}
int sumTNode(TNode*Root)
{
	if (!Root)return 0;
	int suml = sumTNode(Root->Left);
	int sumr = sumTNode(Root->Right);
	return(Root->info + suml + sumr);
}
int isLeaf(TNode*T)
{

	if (T == NULL)return 0;
	if (T->Left == NULL&&T->Right == NULL)
		return 1;
	else
		return 0;
}
void ktNutLa(TNode*Root)
{

	int x;
	printf("\nmoi nhap nut: ");
	scanf("%d", &x);
	TNode *p = createTNode(x);
	if (isLeaf(p) == 1)
		printf("la 1 nut la");
	else
		printf("khong la 1 nut la ");
}
int deleteNodeLeft(TNode* T, ItemType&x)
{
	if (T == NULL) return 0;
	TNode*p = T->Left;
	if (p == NULL) return 0;
	if (p->Left != NULL&&p->Right != NULL)
		return 0;
	x = T->info;
	delete p;
	return 1;
}
void xoatrai(TNode*root)
{
	int x;
	printf("\nmoi nhap nut: ");
	scanf("%d", &x);
	deleteNodeLeft(root, x);
}
TNode * findTNode(TNode*&p)
{
	TNode* f = p;
	TNode* q = p->Right;
	while (q->Left != NULL)
	{
		f = q;
		q = q->Left;
	}
	p->info = q->info;
	if (f == p)
	{
		f->Right = q->Right;
	}
	else
	{
		f->Left = q->Right;
	}
	return q;
}
int deleteTNodeX(TNode*&root, ItemType x)
{
	if (root == NULL)
		return 0;
	if (root->info>x)
		return deleteTNodeX(root->Left, x);
	else if (root->info<x)
	{
		return deleteTNodeX(root->Right, x);
	}
	else
	{
		TNode*p = root;
		if (root->Left == NULL)
		{
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL)
		{
			root = root->Left;
			delete p;
		}
		else
		{
			TNode *q = findTNode(p);
			delete q;
		}
		return 1;
	}
}
void levelOrder(TNode *root) {
	if (root == NULL) return;

	queue <TNode *> q;
	q.push(root);

	while (!q.empty()) {
		TNode *p;
		p = q.front();
		q.pop();
		printf("%d\t", p->info);
		if (p->Left != NULL)
			q.push(p->Left);
		if (p->Right != NULL)
			q.push(p->Right);
	}
}
void khoang(TNode *root, ItemType x, ItemType y)
{
	TNode*p = root;
	while (p!=NULL)
	{
		if (p->info >= x&&p->info <= y)
		{
			printf("%d\t", p->info);
		}
		else if (p->info>y)
		{
			p = p->Left;
		}
		else
		{	
			p = p->Right;
		}
	}
}