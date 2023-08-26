#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct phanSo{
	int tuSo;
	int mauSo;
	phanSo* next;
};

struct NodeList{
	phanSo* head;
	phanSo* tail;
};

phanSo* createFraction(int valueA, int valueB){
	phanSo* p = new phanSo;
	if (p == NULL){
		printf("Khong du bo nho");
		return NULL;
	}
	p->tuSo = valueA;
	p->mauSo = valueB;
	p->next = NULL;
	return p;
}

void initNodeList(NodeList &l){
	l.head = NULL;
	l.tail = NULL;
}

void tailInsert(NodeList &l, phanSo* p){
	if (l.head == NULL){
		l.head = l.tail = p;
	}
	else{
		l.tail->next = p;
		l.tail = p;
	}
}

void insertFraction(NodeList &l){
	int quantity;
	int valueA, valueB;
	printf("quantity:");
	scanf("%d", &quantity);
	srand((unsigned)time(NULL));
	for (int i = 0; i<quantity; i++){
		valueA = rand() % 100;
		valueB = rand() % 100;
		phanSo*p = createFraction(valueA, valueB);
		tailInsert(l, p);
	}
}

void printFraction (phanSo*p){
	printf("%d/%d \t", p->tuSo, p->mauSo);
}

void output(NodeList &l){
	for (phanSo*k = l.head; k != NULL; k = k->next){
		printFraction(k);
	}
	printf("\n");
}

int GDC(int valueA, int valueB){
	while (valueA != valueB){
		while (valueA>valueB){
			valueA -= valueB;
		}
		while (valueB>valueA){
			valueB -= valueA;
		}
	}
	return valueA;
}

//c
void reducedFraction (phanSo*&p){
	int a = GDC(p->tuSo, p->mauSo);
	p->tuSo /= a;
	p->mauSo /= a;
}

void reducedFractionNodeList(NodeList &l){
	for (phanSo*k = l.head; k != NULL; k = k->next){
		reducedFraction(k);
	}
}

//d
phanSo* mutipleFraction(phanSo*a, phanSo*b){
	phanSo*result;
	result->tuSo = a->tuSo*b->mauSo;
	result->mauSo = a->mauSo*b->mauSo;
	reducedFraction(result);
	return result;
}

//e
void printMaxMinFractionNodeList(NodeList &l){
	float max, min;
	phanSo*maxF, *minF;
	maxF = minF = l.head;
	max = min = l.head->tuSo / l.head->mauSo;

	for (phanSo*k = l.head->next; k != NULL; k = k->next){
		float num = k->tuSo;
		float den = k->mauSo;
		if (min>num / den){
			min = num / den;
			minF = k;
		}
		if (max<num / den){
			max = num / den;
			maxF = k;
		}
	}

	printf("max:");
	printFraction(maxF);
	printf("min:");
	printFraction(minF);
	printf("\n");
}

//f
void fractionPlusOne (phanSo*&p){
	p->tuSo += p->mauSo;
}

void fractionPlusOneNodeList (NodeList &l){
	for (phanSo*k = l.head; k != NULL; k = k->next){
		fractionPlusOne(k);
	}
}

//g
void printFractionGreaterThanOne(NodeList &l){
	for (phanSo*k = l.head; k != NULL; k = k->next){
		if (k->tuSo>k->mauSo){
			printFraction(k);
		}
	}
	printf("\n");
}

//h
phanSo*findX(NodeList&l, phanSo*x){
	for (phanSo*k = l.head; k != NULL; k = k->next){
		phanSo*p = k;
		reducedFraction(p);
		if (p->tuSo == x->tuSo&&p->mauSo== x->mauSo){
			return k;
		}
	}
	return NULL;
}

void findXInNodeList(NodeList&l){
	int num, den;
	printf("num&den:");
	scanf("%d/%d", &num, &den);
	phanSo*x = createFraction(num, den);
	reducedFraction(x);
	phanSo* result = findX(l, x);
	if (result != NULL){
		printFraction(result);
	}
	else{
		printf("Khong ton tai x");
	}
}

void main(){
	NodeList List;
	initNodeList(List);
	insertFraction(List);
	output(List);
	reducedFractionNodeList(List);
	output(List);
	printMaxMinFractionNodeList(List);
	printFractionGreaterThanOne(List);
	findXInNodeList(List);
	getch();
}