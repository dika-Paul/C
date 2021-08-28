#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<cassert>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE* in = fopen("in.txt", "r");
	FILE* out = fopen("out.txt", "w");
	assert(in != NULL);
	/*
	* fputc and fgetc will get every char including "\n" and " "
	int ch;
	while ((ch = fgetc(in)) != EOF)
	{
		fputc(ch, out);
		printf("%c", ch);
		system("pause");
	}*/
	/*
	*  fgets will get char through your number, if there are not enough number it will get the whole line
	char ch[100];
	while (fgets(ch, 5, in))
	{
		fputs(ch, out);
		printf("%s", ch);
		system("pause");
	}*/
	
	fclose(in);
	fclose(out);
	in = NULL;
	out = NULL;
	return 0;
}