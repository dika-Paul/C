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
/*ѧϰ�ܽ�
	�ڶ�̬�ڴ�ķ����У�����Ŀռ�һ��Ҫfree�����Ұ�ָ���ÿգ���ֹ����Ұָ��
	��Σ���realloc��˵����Ҫ��p = realloc(p,size_n)��д�������ڷ���ֵΪ�յ�ʱ�������ڴ�й¶������*/