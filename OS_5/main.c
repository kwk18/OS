
#include<stdlib.h>
#include <stdio.h>
#include<stdbool.h>
#include"stack.h"

int main() {

	Stack *list =create();
	push((list), 1);
	push(list, 3);
	push(list, 2);
	print(list);
	printf("\n");
	printf("%f\n", pop(list));
	printf("%f\n", pop(list));
	push(list, 2);
	print(list);
	printf("\n");
	printf("%d\n", sizeStack(list));
	clear(list);

	print(list);
	free(list);
	
	return 0;
}

