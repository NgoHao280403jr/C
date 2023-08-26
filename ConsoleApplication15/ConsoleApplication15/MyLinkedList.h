#ifndef _MY_LINKED_LIST_H_
#define _MY_LINKED_LIST_H_
#include "SinhVien.h"
struct Node {
	SinhVien key;
	Node* next;
};
typedef Node* NodePtr;
//khoi tao danh sach
void List_init(Node*& head);
//kiem tra danh sach rong
bool List_isEmpty(Node* head);
//giai phong danh sach
void List_free(Node*& head);
//chen phan tu moi vao danh sach
void List_insert(Node*& head, SinhVien x);
//xoa mot phan tu
void List_remove(Node*& head, char key_ma[]);
Node* List_search(Node* head, char key_ma[]);
void List_traverse(Node* head);
#endif