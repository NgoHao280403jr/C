#ifndef BST
#define BST
#include <conio.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <Windows.h>
using namespace std;
typedef int ItemType;
struct  TNode
{
	ItemType info;
	TNode* Left;
	TNode* Right;
};
struct BSTree
{
	TNode*Root;
};
void initBSTree(BSTree &bst);
TNode*createTNode(ItemType x);
void createBSTree_FromArray(BSTree&bst, ItemType a[], int n);
int insertTNode(TNode*&root, TNode*p);
void traverseLNR(TNode*Root);
int maxTNode(TNode*root);
void showTNodeOfLevelK(TNode*root, int k);
int sumTNode(TNode*Root);
int isLeaf(TNode*T);
void ktNutLa(TNode*Root);
int deleteNodeLeft(TNode* T, ItemType&x);
void xoatrai(TNode*root);
TNode * findTNode(TNode*&p);
int deleteTNodeX(TNode*&root, ItemType x);
void levelOrder(TNode *root);
void khoang(TNode *root, ItemType x, ItemType y);
#endif