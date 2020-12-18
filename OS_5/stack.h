#pragma once


struct Node;
typedef struct Node Node;

struct Stack;
typedef struct Stack Stack;

Stack* create();
void push(Stack* begin, double x);
double pop(Stack* begin);
void clear(Stack* begin);
void print(const Stack* begin);
int sizeStack(const Stack* begin);
bool isEmpty(const Stack* begin);