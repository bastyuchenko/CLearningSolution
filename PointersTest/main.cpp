#include <stdio.h>

static int matr[3][4] = {
		{ 2,4,6,8 },
		{ 10,12,14,16 },
		{ 18,20,22,24 }
};

void mulitiArray(){

	int* arr = matr[0];
	printf("%d\n", matr[0][0]);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", *arr++);
		}
		printf("\n");
	}
}

void pointerArray1(){

	int* p[] = {
		matr[0],
		matr[1],
		matr[2],
	};

	for (int i = 0; i < 3; i++)
	{
		printf("%p\t", p[i]);
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", p[i]);
		}
		printf("\n");
	}
}

void pointerArray2(){

	int* arr = (int*)matr;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", *arr++);
		}
		printf("\n");
	}
}

void pointerArray3() {

	int (*arr)[4] = matr;

	// alternative
	// int (*arr)[4] = (int(*)[4])matr;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", *(arr[i]+j));
		}
		printf("\n");
	}
}


void pointerArray4() {

	int *arr = (int*)matr;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", *(arr + i*4 + j));
		}
		printf("\n");
	}
}

int main() {
	pointerArray3();
}