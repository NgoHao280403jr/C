#include"BinarySearchTree.h"
#include<stdio.h>
#include<conio.h>
#include"hinhcay.h"
void main()
{
	int k;
	BSTree bst;
	createBSTree_FromFile(bst);
	print_ascii_tree(bst.Root);
	traverseLNR(bst.Root);
	search(bst.Root);
	getch();
}