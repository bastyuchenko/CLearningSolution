#include <stdio.h>

static int matr[3][4] = {
	{2, 4, 6, 8},
	{10, 12, 14, 16},
	{18, 20, 22, 24}};

void mulitiArray()
{

	int *arr = matr[0];
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

void pointerArray1()
{

	int *p[] = {
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

void pointerArray2()
{

	int *arr = (int *)matr;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", *arr++);
		}
		printf("\n");
	}
}

void pointerArray3()
{

	int(*arr)[4] = matr;

	// alternative
	// int (*arr)[4] = (int(*)[4])matr;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", *(arr[i] + j));
		}
		printf("\n");
	}
}

void pointerArray4()
{

	int *arr = (int *)matr;
	// alternative
	// int *arr = &matr[0][0];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", *(arr + i * 4 + j));
		}
		printf("\n");
	}
}

void pointerCube()
{
	int cube[5][3][4] = {
		{{11, 12, 13, 113},
		 {14, 15, 16, 116},
		 {17, 18, 19, 119}},

		{{21, 22, 23, 223},
		 {24, 25, 26, 226},
		 {27, 28, 29, 229}},

		{{31, 32, 33, 333},
		 {34, 35, 36, 336},
		 {37, 38, 39, 339}},

		{{41, 42, 43, 443},
		 {44, 45, 46, 446},
		 {47, 48, 49, 449}},

		{{51, 52, 53, 553},
		 {54, 55, 56, 556},
		 {57, 58, 59, 559}}};

	int *arr = (int *)cube;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int h = 0; h < 4; h++)
			{
				// arr[i][j][k] = *(ptr + (i * JMAX*KMAX) + (j*KMAX + k))
				// printf("%d\t", *(arr + (i * jMAX*hMAX) + (j*hMAX + h)));
				printf("%d\t", *(arr + i * 12 + j * 4 + h));
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

int main()
{
	pointerCube();
}