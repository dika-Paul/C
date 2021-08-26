#define _CRT_SECURE_NO_WARNINGS

#include"str_f.h"

#include<stdio.h>
#include<string.h>

int main()
{
	char a[100] = "bacbeg";
	char bb[] = "cde";
	char b = 'b';
	printf("%s", strrchr1(a, b));
	return 0;
}