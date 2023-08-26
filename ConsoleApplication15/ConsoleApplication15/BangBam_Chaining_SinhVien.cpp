#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"
#define DEFAULT_LOAD_FACTOR 0.8
struct HashTable{
	NodePtr* bucket; //su dung mang dong
	int size; //kich thuoc bang bam (so bucket)
	int count; //so luong phan tu tren bang bam
};
//ham bam
int hash(char key[], int maxsize)
{
	int h = 0;
	for (int i = 0; key[i] != '\0'; i++){
		h = h * 31 + key[i];
	}
	return h % maxsize;
}
// khoi tao
void HT_init(HashTable& ht, int maxsize)
{
	ht.size = maxsize;
	ht.count = 0;
	ht.bucket = new NodePtr[ht.size];
	for (int i = 0; i < ht.size; i++) {
		List_init(ht.bucket[i]);
	}
}
//huy bang bam
void HT_free(HashTable& ht)
{
	for (int i = 0; i < ht.size; i++){
		List_free(ht.bucket[i]);
	}
	ht.size = 0;
	ht.count = 0;
	delete[] ht.bucket;
}
//tim kiem
Node* HT_get(HashTable ht, char key_ma[])
{
	int h = hash(key_ma, ht.size);
	return List_search(ht.bucket[h], key_ma);
}
//xoa phan tu
void HT_remove(HashTable &ht, char key_ma[])
{
	int h = hash(key_ma, ht.size);
	//kiem tra khoa da ton tai chua
	Node* result = List_search(ht.bucket[h], key_ma);
	if (result == NULL) {
		printf("Khoa %s khong ton tai!\n", key_ma);
	}
	else
	{
		List_remove(ht.bucket[h], key_ma);
		ht.count--;
	}
}
//bam lai
void rehashing_HT(HashTable& ht_old, int maxsize_new);
//chen phan tu moi vao bang bam
void HT_push(HashTable& ht, SinhVien x)
{
	int h = hash(x.ma, ht.size);
	//kiem tra khoa da ton tai chua
	Node* result = List_search(ht.bucket[h], x.ma);
	if (result != NULL) {
		printf("SV co ma %s da ton tai!\n", x.ma);
	}
	else{
		//them khoa moi vao (them dau)
		List_insert(ht.bucket[h], x);
		ht.count++;
		//tinh lai tai trong tren bang bam
		double loadFactor = ht.count *1.0 / ht.size;
		if (loadFactor > DEFAULT_LOAD_FACTOR) {
			//bam lai voi kich thuoc moi gap doi cu
			rehashing_HT(ht, ht.size * 2);
		}
	}
}
void rehashing_HT(HashTable& ht, int maxsize_new)
{
	//tao ra bang bam moi voi kich thuoc moi
	HashTable ht_new;
	HT_init(ht_new, maxsize_new);
	//chuyen du lieu cua bang bam cu sang bang moi
	for (int i = 0; i < ht.size; i++) {
		for (Node* p = ht.bucket[i]; p != NULL; p = p->next) {
			SinhVien key = p->key;
			HT_push(ht_new, key);
		}
	}
	//cap nhat lai bang bam hien tai
	HashTable ht_old = ht;
	ht = ht_new;
	HT_free(ht_old);
}
//duyet
void HT_traverse(HashTable ht)
{
	//duyet qua cac bucket
	for (int i = 0; i < ht.size; i++) {
		printf("[%d]: ", i);
		List_traverse(ht.bucket[i]);
	}
	double loadFactor = 0;
	if (ht.count != 0)
		loadFactor = ht.count*1.0 / ht.size;
	printf("He so tai hien tai: [%.2f]% \n", loadFactor);
}
//doc danh sach sinh vien tu file va luu vao bang bam
bool inputFromFile(HashTable& ht, char file[])
{
	FILE* fp = fopen(file, "rt");
	if (fp == NULL) return false;
	else
	{
		int n;
		fscanf(fp, "%d\n", &n);
		SinhVien x;
		for (int i = 0; i < n; i++)
		{
			docSV(fp, x);
			HT_push(ht, x);
		}
		fclose(fp);
		return true;
	}
}
void menu()
{
	printf("\n----Menu---");
	printf("\n0.Thoat");
	printf("\n1.Tai du lieu mac dinh (tu file)");
	printf("\n2.Them mot sinh vien");
	printf("\n3.Xoa mot sinh vien theo ma");
	printf("\n4.Tra cuu thong tin sinh vien theo ma:");
}
void main()
{
	//khai bao bang bam: loai dia chi moi, dung pp do tuyen tinh, kich thuoc ban dau = 5
	HashTable ht;
	int tableSize = 5;
	//khoi tao bang bam
	HT_init(ht, tableSize);
	int choose = 0;
	do {
		system("cls");
		HT_traverse(ht);
		menu();
		printf("\nChon: ");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 0:
		{
				  break;
		}
		case 1:
		{
				  char file[] = "inputSV.txt";
				  inputFromFile(ht, file);
				  break;
		}
		case 2:
		{
				  SinhVien x;
				  printf("\nNhap sinh vien moi: \n");
				  nhapSV(x);
				  HT_push(ht, x);
				  break;
		}
		case 3:
		{
				  char key_ma[10];
				  printf("\nNhap ma sv can xoa: ");
				  scanf("%s", &key_ma);
				  HT_remove(ht, key_ma);
				  break;
		}
		case 4:
		{
				  char key_ma[10];
				  printf("\nNhap ma sv can tra: ");
				  scanf("%s", &key_ma);
				  Node* p = HT_get(ht, key_ma);
				  if (p != NULL) {
					  printf("Thong tin chi tiet cua sv %s:\n", key_ma);
					  xuatTieuDe();
					  xuatSV(p->key);
				  }
				  else {
					  printf("Sv co ma %s khong ton tai\n", key_ma);
				  }
				  break;
		}
		default:
			break;
		}
		system("pause");
	} while (choose != 0);
	//huy bang bam
	HT_free(ht);
}