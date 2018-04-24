#ifndef read_csv_h
#define read_csv_h
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <fstream>
#pragma warning(disable: 4996 )
void ChuanHoaKiTu(wchar_t *a, int i, int j)
{
	for (i; i < j; i++)
	{
		if (a[i] == L',')
			a[i] = L'$';
	}
}
void xoakep(wchar_t *a)
{
	int n = wcslen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == L'"')
			a[i] = L' ';
	}
}
void XuLiChuoi(wchar_t *a)
{
	int length = wcslen(a);
	for (int i = 0; i < length; i++)
	{
		if (a[i] == L'\"')
		{
			for (int j = i + 1; j < length; j++)
			{
				if (a[j] == L'"')
				{
					ChuanHoaKiTu(a, i, j);
					i = j + 1;
					break;
				}
			}
		}
	}
}
void TraLaiKiTu(wchar_t *a)
{
	int n = wcslen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == L'$')
			a[i] = L',';
	}
}

#endif 
