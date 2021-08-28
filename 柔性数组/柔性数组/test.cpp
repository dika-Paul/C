#define _CRT_SECURE_NO_WARINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct S {
	int a;
	int b[0];
};

int main()
{
	printf("%d\n", sizeof(struct S));
	struct S* p = (struct S*)malloc(sizeof(struct S) + 5 * (sizeof(int)));
	p->a = 100;
	int i = 0;
	for (i = 0; i <= 5; i++)
	{
		p->b[i] = i;
	}
	struct S* ptr = (struct S*)realloc(p, sizeof(struct S) + 10 * (sizeof(int)));
	assert(ptr == NULL);
	p = NULL;
	return 0;
}

/*
* 
* there are two kinds of methods
* struct S {
	int a;
	int b[0];
};
struct S {
	int a;
	int* b;
};
* Comepare to the second method, the first one can reduce the satuation "memory fragmentation" 
* 
*/