#ifndef template_h
#define template_h
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <fstream>
#include <string>
#include"memory.h"
#pragma warning(disable: 4996 )
using namespace std;
/**
* Change variable in template
* Example: "xin chao $name"
* Change to: "xin chao NPV"
*/
unsigned int Find(wchar_t* str, wchar_t* substr,unsigned int startPos)
{
	unsigned int length = wcslen(str);
	unsigned int length1 = wcslen(substr);
	for (unsigned int i = startPos; i < length; i++)
	{
		int flag = 0;
		for( unsigned int j = 0; j < length1; j++)
		{
			if (str[j + i] != substr[j])
			{
				flag = 1;
			}
		}
		if (flag == 0)
			return i;
	}
	return -1;
}
void Delete(wchar_t* src,unsigned int startPos,unsigned int numChar)
{
	int length = wcslen(src);
	for (int i = startPos; i < length - numChar; i++)
	{
		src[i] = src[i + numChar];
	}
	src[length - numChar] = '\0';
}
void Insert(wchar_t* chuoicha, wchar_t* chuoicon, int vitri)
{
	int l = wcslen(chuoicha);
	int l1 = wcslen(chuoicon);
	wchar_t* temp = new wchar_t[l - vitri + 1];
	wcscpy(temp, chuoicha + vitri);
	wcscpy(chuoicha + vitri, chuoicon);
}
void TimKiemVaThayThe(wchar_t *s, wchar_t *s1, wchar_t *s2)
{
	int n = wcslen(s);
	int n1 = wcslen(s1);
	int n2 = wcslen(s2);
	if (wcscmp(s1, s2) != 0)
	{
		unsigned int pos = Find(s, s1, 0);
		while (pos != EOF)
		{
			Delete(s, pos, n1);
			Insert(s, s2, pos);
			unsigned int n = Find(s, s1, pos);
			pos = n;
		}
	}
	else
		return;
}
#endif