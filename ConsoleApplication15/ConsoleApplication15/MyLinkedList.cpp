#include "MyLinkedList.h"
#include <stdio.h>
#include <string.h>
void List_init(Node*& head)
{
	head = NULL;
}
bool List_isEmpty(Node* head)
{
	return head == NULL;
}
Node* createNode(SinhVien x)
{
	Node* p = new Node;
	p->key = x;
	p->next = NULL;
	return p;
}
//chon pp them dau (add head)
void List_insert(Node*& head, SinhVien x)
{
	Node* p = createNode(x);
	if (List_isEmpty(head)) {
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}
}
void removeHead(Node*& head)
{
	if (List_isEmpty(head)) return;
	else {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}
void removeAfter(Node*& head, Node* q)
{
	if (List_isEmpty(head) || q == NULL || q->next == NULL)
		return;
	else {
		Node* p = q->next;
		q->next = p->next;
		delete p;
	}
}
void List_remove(Node*& head, char key_ma[])
{
	if (List_isEmpty(head)) return;
	else {
		Node* p = head, *q = NULL; // q la node truoc p
		while (p != NULL && strcmp(p->key.ma, key_ma) != 0) {
			q = p;
			p = p->next;
		}
		if (q == NULL)
			removeHead(head); //p la head
		else
			removeAfter(head, q);//xoa p
	}
}
void List_free(Node*& head)
{
	Node* tmp;
	while (head != NULL){
		tmp = head;
		head = tmp->next;
		delete tmp;
	}
	head = NULL;
}
Node* List_search(Node* head, char key_ma[])
{
	Node* p = head;
	while (p != NULL){
		if (strcmp(p->key.ma, key_ma) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}
void List_traverse(Node* head)
{
	Node* p = head;
	while (p != NULL) {
		printf("<%-10s>%-20s%-25s%-10d%-10.2f\n ", p->key.ma,p->key.hoTen,p->key.diaChi,p->key.namSinh,p->key.diemTB); //chi hien thi ma sinh vien
		p = p->next;
	}
	printf("\n");
}