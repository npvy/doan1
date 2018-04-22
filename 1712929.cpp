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
		wprintf(L"\n");
	}
}
void wmain()
{
	//Doc unicode
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	bool kt = false;
	FILE *doc=NULL;
	wchar_t *lines=NULL;
	unsigned int sosv = 0;
	sv *SV;
	wchar_t *fomart = L"mssv,hoten,khoa,nienkhoa,ngaysinh,image,mota,sothich";
	sosv = demsosv(doc, kt);
	if (kt)
	{
		wprintf(L"File could not be opened.\n");
	}
	else if (sosv == 0)
	{
		wprintf(L"empty\n");
	}
	else
	{
		
		khoitao(lines, sosv);
		xuatdssv(SV, sosv);
		delete[]SV;
	}
	system("pause");
}
