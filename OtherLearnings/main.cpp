#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstddef>
#include <iostream>
#include "main.h"

struct rectangle
{
	float len, brd;
	double area;
};

struct book
{
	char title[10];
	double price;
	int pages;
};

int main()
{
	printf("%i\n", offsetof(struct book, title));
	printf("%i\n", offsetof(struct book, price));
	printf("%i\n", offsetof(struct book, pages));
	// CheckPassStructureAsArgumentWithPoiner();
	//CheckPassStructureAsArgument();
}

void CheckPassStructureAsArgumentWithPoiner()
{
	struct rectangle *r;
	float x, y;
	x = 10.5, y = 20.5;
	r = areaP(x, y);

	printf("Length: %f \nBreadth: %f \nArea: %lf\n", r->len, r->brd, r->area);

	printf("%p\n", r);

	free(r);
}

struct rectangle *areaP(float x, float y)
{
	double area = (double)(x * y);
	struct rectangle *rec = (struct rectangle *)malloc(sizeof(struct rectangle));
	rec->len = x;
	rec->brd = y;
	rec->area = area;

	printf("%p\n", rec);

	return rec;
}

void CheckPassStructureAsArgument()
{
	struct rectangle r;
	float x, y;
	x = 10.5, y = 20.5;
	r = area(x, y);

	printf("Length: %f \nBreadth: %f \nArea: %lf\n", r.len, r.brd, r.area);

	printf("%p\n", r);
}

struct rectangle area(float x, float y)
{
	double area = (double)(x * y);
	struct rectangle rec = { x, y, area};

	printf("%p\n", rec);

	return rec;
}