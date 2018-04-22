#ifndef read_csv_h
#define read_csv_h
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include"memory.h"
#include <fstream>
#pragma warning(disable: 4996 )
unsigned int demsosv(FILE *&doc,bool &kt)
{
	unsigned int dem = 0;
	wchar_t *a = (wchar_t*)malloc(sizeof(wchar_t));
	_wfopen_s(&doc, L"npvy.csv", L"rt,ccs=UTF-8");
	if (!feof(doc))
	{
		while (!feof(doc))
		{
			fgetws(a, sizeof(wchar_t), doc);
			dem++;
			khoitao(a, dem);
		}
		fclose(doc);
	}
	else kt = true;
	return dem;
}
void ChuanHoaKiTu(wchar_t a[], int i, int j)
{
	for (i; i < j; i++)
	{
		if (a[i] == L',')
			a[i] = L'$';
	}
}
void chuanhoakitu(wchar_t a[], int n)
{
	n = wcslen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == L'"')
			a[i] = L'\0';
	}
}
void XuLiChuoi(wchar_t a[])
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