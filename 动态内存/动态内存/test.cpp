#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main()
{
	int* ptr = (int*)malloc(10 * sizeof(int));
	if (ptr == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		int* ptr2 = (int*)realloc(ptr, 20 * sizeof(int));
		free(ptr);
		ptr = NULL;
		for (i = 0; i < 10; i++)
		{
			*(ptr2 + i) = i;
			/*printf("%d ", *(ptr + i));*/
		}
		for (i = 0; i < 20; i++)
		{
			printf("%d ", *(ptr2 + i));
		}
		free(ptr2);
		ptr2 = NULL;
	}
	/*
	ptr = (int*)calloc(10, sizeof(int));
	free(ptr);
	ptr = NULL;*/
	return 0;
}
/*学习总结
	在动态内存的分配中，申请的空间一定要free，并且把指针置空，防止出现野指针
	其次，对realloc来说，不要用p = realloc(p,size_n)的写法，这在返回值为空的时候会造成内存泄露！！！*/