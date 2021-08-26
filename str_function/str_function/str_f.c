#include"str_f.h"

#include<stdio.h>

size_t strlen1(const char* str)
{
    int lenth = 0;
    while (*str != 0)
    {
        lenth++;
        str++;
    }
    return lenth;
}
char* strcpy1(char* dest, const char* src)
{
    int ii = 0;
    while (src[ii] != 0)
    {
        dest[ii] = src[ii];
        ii++;
    }
    return dest;
}
char* strncpy1(char* dest, const char* src, size_t n)
{
    int ii = 0;
    while (src[ii] != 0 && ii < n)
    {
        dest[ii] = src[ii];
        ii++;
    }
    if (ii < n)
    {
        for (ii = ii + 1; ii < n; ii++)
        {
            dest[ii] = 0;
        }
    }
    return dest;
}
char* strcat1(char* dest, const char* scr)
{
    int lenth = strlen1(dest);
    int ii = 0;
    while (scr[ii] != 0)
    {
        dest[lenth + ii] = scr[ii];
        ii++;
    }
    dest[lenth + ii] = 0;
    return dest;
}
char* strncat1(char* dest, const char* scr, size_t n)
{
    int lenth = strlen1(dest);
    int ii = 0;
    while (scr[ii] != 0 && ii < n)
    {
        dest[lenth + ii] = scr[ii];
        ii++;
    }
    if (ii < n)
    {
        for (ii = ii + 1; ii < n; ii++)
        {
            dest[lenth + ii] = 0;
        }
    }
    dest[lenth + ii] = 0;
    return dest;
}
char* strchr1(const char* s, const char c)
{
    int ii = 0;
    int lenth = strlen(s);
    while (ii <= lenth)
    {
        if (s[ii] == c)  return s + ii;
        ii++;
    }
    return NULL;
}
char* strrchr1(const char* s, const char c)
{
    char* p = NULL;
    int ii = 0;
    int lenth = strlen(s);
    while (ii <= lenth)
    {
        if (s[ii] == c)  p = s + ii;
        ii++;
    }
    return p;
}
int strcmp1(const char* str1, const char* str2)
{
    int ii = 0;
    while (1)
    {
        if (str1[ii] == 0 && str2[ii] == 0)  return 0;
        else if (str1[ii] > str2[ii]) return 1;
        else if (str1[ii] < str2[ii]) return -1;
        ii++;
    }
}
int strncmp1(const char* str1, const char* str2, const size_t n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (str1[i] > str2[i]) return 1;
        else if (str1[i] < str2[i]) return -1;
    }
    return 0;
}
char* strstr1(const char* str, const char* substr)
{
    int lenth_str = strlen(str);
    int lenth_sstr = strlen(substr);
    int i, ii;
    int tem;
    for (i = 0; i < lenth_str; i++)
    {
        if (str[i] == substr[0])
        {
            tem = i + 1;
            ii = 1;
            while (ii < lenth_sstr)
            {
                if (str[tem] == substr[ii]) { ii++; tem++; }
                else break;
            }
            if (ii == lenth_sstr)    return str + i;
        }
    }
    return NULL;
}