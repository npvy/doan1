#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <conio.h>
#include "readcsv.h"
#pragma warning(disable: 4996 )
struct sv
{
	wchar_t *mssv;
	wchar_t *hoten;
	wchar_t *khoa;
	wchar_t *nienkhoa;
	wchar_t *ngaysinh;
	wchar_t *image;
	wchar_t *mota;
	wchar_t *email;
	unsigned int demsothich;
	wchar_t **sothich;
};
int mssv = 11;
int hoten = 31;
int khoa = 31;
int nienkhoa = 5;
int ngaysinh = 11;
int email = 31;
int image = 100;
int mota = 1001;
int sothich = 1001;

void readfile(FILE *f)
{
	_setmode(_fileno(f), _O_U8TEXT);
	int dem = 0;
	wchar_t** p = (wchar_t**)malloc(20 * sizeof(wchar_t*));
	if (f != NULL)
	{
		while (!feof(f))
		{
			p[dem] = (wchar_t*)malloc(1000 * sizeof(wchar_t));
			fgetws(*(p + dem), 1000, f);
			p[dem][wcslen(p[dem]) - 1] = L'\0';
			dem++;
			XuLiChuoi(p[dem]);
		}
		dem--;
		for (int i = 0; i < dem; i++)
		{
			sv A;
			A.demsothich = 0;
			wchar_t* flag[10];
			wchar_t* tmp;
			// MSSV
			if (i == 0)
			{
				tmp = wcstok(p[i], L",");
				A.mssv = wcstok(NULL, L",");
				xoakep(A.mssv);
			}
			else
			{
				A.mssv = wcstok(p[i], L",");
				xoakep(A.mssv);
			}
			// Ho va ten
			tmp = wcstok(NULL, L",");
			A.hoten = wcstok(NULL, L",");
			xoakep(A.hoten);
			// Khoa
			tmp = wcstok(NULL, L",");
			A.khoa = wcstok(NULL, L",");
			xoakep(A.khoa);
			// Nien khoa
			tmp = wcstok(NULL, L",");
			A.nienkhoa = wcstok(NULL, L",");
			xoakep(A.nienkhoa);
			// Ngay sinh
			tmp = wcstok(NULL, L",");
			A.ngaysinh = wcstok(NULL, L",");
			xoakep(A.ngaysinh);
			// Hinh anh
			tmp = wcstok(NULL, L",");
			A.image = wcstok(NULL, L",");
			xoakep(A.image);
			// Email
			tmp = wcstok(NULL, L",");
			A.email = wcstok(NULL, L",");
			xoakep(A.email);
			// Mo ta ban than
			tmp = wcstok(NULL, L",");
			A.mota = wcstok(NULL, L",");
			TraLaiKiTu(A.mota);
			xoakep(A.mota);
			// So thich
			tmp = wcstok(NULL, L",");
			flag[A.demsothich] = wcstok(NULL, L",");
			while (flag[A.demsothich] != NULL)
			{
				A.demsothich++;
				tmp = wcstok(NULL, L",");
				flag[A.demsothich] = wcstok(NULL, L",");
				xoakep(flag[A.demsothich]);
				TraLaiKiTu(flag[A.demsothich]);
			}
			A.sothich = (wchar_t**)malloc(A.demsothich * sizeof(wchar_t*));
			for (int j = 0; j < A.demsothich; j++)
			{
				*(A.sothich + j) = flag[j];
			}
			free(A.sothich);
		}
		fclose(f);
	}
	for (int i = 0; i < dem; i++)
	{
		free(*(p + i));
	}
	free(p);
}
void xuatdssv(sv *SV, int sosv)
{
	for (int i = 0; i < sosv; i++)
	{
		wprintf(L"\n\n\t************* SINH VIÊN THỨ %d ", i + 1);
		wprintf(L"\n-MSSV: %ls ", SV[i].mssv);
		wprintf(L"\n-Họ tên: %ls  ", SV[i].hoten);
		wprintf(L"\n-Khoa: %ls ", SV[i].khoa);
		wprintf(L"\n-Khóa: %ls  ", SV[i].nienkhoa);
		wprintf(L"\n-Ngày sinh: %ls  ", SV[i].ngaysinh);
		wprintf(L"\n-Hình ảnh: %ls  ", SV[i].image);
		wprintf(L"\n-Mô tả bản thân:  %ls ", SV[i].mota);
		wprintf(L"\n-Sở thích: ", SV[i].sothich);
	}
}
void wmain()
{
	//Doc unicode
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	
	system("pause");
}

