#pragma once
#include<stdio.h>
#include<string.h>

size_t strlen1(const char* str);
char* strcpy1(char* dest, const char* src);
char* strncpy1(char* dest, const char* scr, size_t n);
char* strcat1(char* dest, const char* scr);
char* strncat1(char* dest, const char* scr, size_t n);
char* strchr1(const char* s, const char c);
char* strrchr1(const char* s, const char c);
int strcmp1(const char* str1, const char* str2);
int strncmp1(const char* str1, const char* str2, const size_t n);
char* strstr1(const char* str, const char* substr);