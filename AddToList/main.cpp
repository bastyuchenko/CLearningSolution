#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int* data;
	int numItems;
} list;

void addToList(list*, int);

void printList(list*);

int main() {
	list myList = { NULL, 0 };
	int numberToAdd;

	while (true)
	{
		printList(&myList);

		printf("\nEnter number: ");
		scanf("%d", &numberToAdd);

		addToList(&myList, numberToAdd);
	}
}

void printList(list* mList) {
	for (int i = 0; i < mList->numItems; i++)
	{
		printf("%i ", *(mList->data + i));
	}
}

void addToList(list* mList, int item)
{
	mList->numItems++;
	int* new_data = (int*)realloc(mList->data, mList->numItems * sizeof(*mList->data));
	if (new_data != NULL)
	{
		mList->data = new_data;
	}
	*(mList->data + mList->numItems - 1) = item;
}