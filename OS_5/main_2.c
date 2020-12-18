#include<stdlib.h>
#include <stdio.h>
#include<stdbool.h>
#include <dlfcn.h>
#include"stack.h"

struct Node;
typedef struct Node Node;


struct ForStack;
typedef struct ForStack ForStack;

int main()
{
    void *lib = dlopen("./libstack.so", RTLD_LAZY);//разрешение неопределенных символов в виде кода, содержащегося в исполняемой динамической библиотеке;
    if (!lib)
    {
        printf("Cannot open lib because: %s\n", dlerror());
        return 1;
    }
    Stack* (*create)()=dlsym(lib,"create");//использует указатель на динамическую библиотеку, возвращаемую dlopen, и оканчивающееся нулем 
    //символьное имя, а затем возвращает адрес, указывающий, откуда загружается этот символ.
    void (*push)(Stack*,double)=dlsym(lib,"push");
    double(*pop)(Stack*)=dlsym(lib,"pop");
    void (*clear)(Stack*)=dlsym(lib,"clear");
    void (*print)(const Stack*)=dlsym(lib,"print");
    int (*sizeStack)(const Stack*)=dlsym(lib,"sizeStack");
    bool (*isEmpty)(const Stack*)=dlsym(lib,"isEmpty");


   
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

    dlclose(lib); 
    return 0;
}

