#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

struct rectangle {
	float len, brd;
	double area;
};



int main() {

	struct rectangle* r;
	float x, y;
	x = 10.5, y = 20.5;
	r = area(x, y);

	printf("Length: %f \nBreadth: %f \nArea: %lf\n", r->len, r->brd, r->area);

	printf("%p\n",r);

	free(r);

	return 0;
}

struct rectangle* area(float x, float y) {
	double area = (double)(x * y);
	struct rectangle *rec = (struct rectangle *)malloc(sizeof(struct rectangle));
	rec->len = x; rec->brd = y; rec->area = area;

	printf("%p\n", rec);

	return rec;
}