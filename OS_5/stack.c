#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

struct Node {
	double data;
	Node* next;

};

struct Stack
{
	Node* head;
};


Stack* create()
{
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->head = NULL;
	return newStack;
}

void push(Stack* begin, double x) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = begin->head;
	begin->head = newNode;
}

double pop(Stack* begin)
{
	if (isEmpty(begin))
	{
		printf("stack is Empty");
		exit(EXIT_FAILURE);
	}
	Node* tmp = begin->head;
	double value = begin->head->data;
	begin->head = begin->head->next;
	free(tmp);
	return value;
}

void clear(Stack* begin) {
	if (isEmpty(begin))
	{
		printf("stack is EMPTY\n");
		return;
	}
	Node* iterator = begin->head;
	while (iterator != NULL)
	{
		Node* tmp = iterator;
		iterator = iterator->next;
		free(tmp);
	}
	begin->head = NULL;
}


void print(const Stack* begin)
{
	if (isEmpty(begin))
	{
		printf("stack is Empty\n");
		return;
	}
	Node* iterator = begin->head;
	while (iterator != NULL)
	{
		printf("%f ", iterator->data);
		iterator = iterator->next;
	}
}

int sizeStack(const Stack* begin)
{
	int size = 0;
	Node* iterator = begin->head;
	while (iterator != NULL)
	{
		++size;
		iterator = iterator->next;
	}
	return size;
}


bool isEmpty(const Stack* begin)
{
	if (begin->head == NULL)
	{
		return true;
	}
	return false;
}