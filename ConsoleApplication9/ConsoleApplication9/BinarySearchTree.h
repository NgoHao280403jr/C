#ifndef BST
#define BST
struct tuDien
{
	char ta[30];
	char tv[30];
};
struct  TNode
{
	tuDien info;
	TNode* Left;
	TNode* Right;
};
struct BSTree
{
	TNode*Root;
};
void initBSTree(BSTree &bst);
TNode*createTNode(tuDien x);
void createBSTree_FromFile(BSTree&bst);
int insertTNode(TNode*&root, TNode*p);
void traverseLNR(TNode*Root);
void search_word(TNode*root, char ta1[]);
void search(TNode *root);
#endif