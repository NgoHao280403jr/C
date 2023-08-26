#include <stdio.h>
#include <conio.h>
#include "BRTree.h"

void main()
{
	BRTree brtree;
	initBRTree(brtree);

	process(brtree);

	printf("\n-------------------------------------");
	getch();
}