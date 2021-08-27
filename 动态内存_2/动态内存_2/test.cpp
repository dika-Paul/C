#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

int main()
{
	/*
	Can't release only a part of memory space
	* 
	int* p = (int*)calloc(10, sizeof(int));
	p += 5;
	free(p);*/

	/*
	Can't release a memory space twice
	* 
	int* p = (int*)calloc(10, sizeof(int));
	free(p);
	free(p);*/

	/*
	Don't forget to release memory spaces, it will cause your computer run lower and lower
	* 
	while (1)
	{
		malloc(1);
	}*/
	return 0;
}

/*
some typical mistake
* 
void Get_space(char* p)
{
	p = malloc(sizeof(char));
}
void test()
{
	char* p = NULL;
	Get_space(p); the value of p haven't been change
	strcpy(p, "Hellow");
	printf(p);
}
int main()
{
	test();
	return 0;
}
*

*
char* Get_space()
{
	char p[] = "hellow";
	return p;
}
void test()
{
	char* p = NULL;   函数内部在栈区申请的空间，会在函数结束后被释放
	p = Get_space();  the memory of Get_space will be released after the function end, remember --- the memory of the function in stack will be released after function ending
	printf(p);
}
int main()
{
	test();
	return 0;
}
int main()
{
	char* p = (char*)malloc(100);
	strcpy(p, "hellow");
	free(p);	after free p have no space to store the string "world"
	if(p != NULL)
	{
		strcpy(p, "world");
		printf(p);	this will print "world" but it's access violation
	}
	return 0;
}
*/