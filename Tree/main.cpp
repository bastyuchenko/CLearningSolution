#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *parent;
	struct node *childLeft;
	struct node *childRight;
};

struct node *createNode(int value, struct node *parent)
{
	struct node *item = (struct node *)malloc(sizeof(struct node));
	item->parent = parent;
	item->value = value;
	item->childLeft = NULL;
	item->childRight = NULL;

	if (value * 2 % 10 == 0)
	{
		item->childLeft = createNode(value * 0.2, item);
	}

	if (value * 8 % 10 == 0)
	{
		item->childRight = createNode(value * 0.8, item);
	}

	return item;
}

void printTree(node *item)
{
	printf("%d\t", item->value);
	fputs("\n", stdout);

	if (item->childLeft != NULL)
	{
		printTree(item->childLeft);
	}

	if (item->childRight != NULL)
	{
		printTree(item->childRight);
	}
}

int main()
{
	struct node *top = createNode(500, NULL);

	printTree(top);
}