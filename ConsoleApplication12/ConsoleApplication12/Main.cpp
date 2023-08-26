#include"BTree.h"
#include<stdio.h>
#include<conio.h>
#include"asciinode.h"

void main()
{
	int k;
	ItemType x, y;
	BSTree bst;
	ItemType a[11] = { 4, 5, 8, 2, 3, 9, 7, 6, 15, 26 };
	createBSTree_FromArray(bst,a,10);
	print_ascii_tree(bst.Root);
	traverseLNR(bst.Root);
	
	printf("\n");
	levelOrder(bst.Root);
	printf("\nmoi nhap khoang x,y:");
	scanf("%d%d", &x, &y);
	khoang(bst.Root, x, y);
	/*printf("\nmax la: %d",maxTNode(bst.Root));
	printf("\nmoi nhap muc k: ");
	scanf("%d",&k);
	showTNodeOfLevelK(bst.Root,k);
	printf("\nTong cua cay la: %d",sumTNode(bst.Root));
	ktNutLa(bst.Root);
	xoatrai(bst.Root);
	print_ascii_tree(bst.Root);*/
	/*printf("\nmoi nhap phan tu can xoa ");
	scanf("%d",&k);
	deleteTNodeX(bst.Root,k);
	print_ascii_tree(bst.Root);*/
	/*duyetChieuRong(bst.Root);*/
	getch();
}