#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <conio.h>
#include <string>
#include "template.h"
#pragma warning(disable: 4996 )
using namespace std;
struct sv
{
	wchar_t mssv[11];
	wchar_t hoten[31];
	wchar_t khoa[31];
	wchar_t nienkhoa[5];
	wchar_t ngaysinh[11];
	wchar_t image[100];
	wchar_t mota[1001];
	wchar_t email[31];
	wchar_t sothich[1001];
};
int sosv(FILE *&f)
{
	rewind(f);
	int dem = 0;
	wchar_t ch;
	while (!feof(f))
	{
		ch = fgetwc(f);
		if (ch == L'\n')
		{
			dem++;
		}
	}
	return dem;
}
void xoa(wchar_t s[], int vt)
{
	int n = wcslen(s);
	for (int i = vt; i < n; i++)
	{
		s[i] = s[i + 1];
	}
	s[n - 1] = '\0';

}
void xoakep(wchar_t s[])
{
	int n = wcslen(s), i;
	for (i = 0; i < n; i++)
	{
		while (s[i] == '"' && s[i + 1] == ',' && s[i + 2] == '"')
		{
			xoa(s, i);
			s[i] = ',';
			s[i + 1] = ' ';
		}
		while (s[i] == '"')
		{
			xoa(s, i);
		}
	}
}
void readfile(FILE *f, int &dem)
{
	sv SV[100];
	wchar_t str[2400];
	wchar_t *token;
	wchar_t s[4] = L",";
	int i;
	int sosothich[1000];
	for (i = 1; i <= dem; i++)
	{
		fgetws(str, 2400, f);
		sosothich[i] = 0;
		token = wcstok(str, s); xoakep(token);  wcscpy(SV[i].mssv, token);
		token = wcstok(NULL, s); xoakep(token); wcscpy(SV[i].hoten, token);
		token = wcstok(NULL, s); xoakep(token); wcscpy(SV[i].khoa, token);
		token = wcstok(NULL, s); xoakep(token); wcscpy(SV[i].nienkhoa, token);
		token = wcstok(NULL, s); xoakep(token); wcscpy(SV[i].ngaysinh, token);
		token = wcstok(NULL, s); xoakep(token); wcscpy(SV[i].image, token);
		token = wcstok(NULL, s); xoakep(token); wcscpy(SV[i].email, token);
		token = wcstok(NULL, L"\"\""); wcscpy(SV[i].mota, token);
		token = wcstok(NULL, L"\n");//lay tat ca thong tin con lai
		while (token != NULL)
		{
			sosothich[i]++;
			if (sosothich[i] == 1)
			{
				xoakep(token);
				wcscpy(SV[i].sothich, token);
			}
			token = wcstok(NULL, L"\0");
		}
	}
}
void xuatdssv(sv SV[100], int sosv)
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
		wprintf(L"\n-Sở thích %d: ", SV[i].sothich);
	}	
}
// tuy chon profile page
struct Choose
{
	int MSSV;
	int Ten;
	int Khoa;
	int Email;
	int Ngaysinh;
	int Hinhanh;
	int Motabanthan;
	int Sothich;
};
void Choice(Choose &luachon)
{
	// 0: không chọn || 1: có chọn
	do
	{
		wprintf(L"In tên: ");
		scanf_s("%d", &luachon.Ten);
	} while (luachon.Ten != 0 && luachon.Ten != 1);
	do
	{
		wprintf(L"In MSSV: ");
		scanf_s("%d", &luachon.MSSV);
	} while (luachon.MSSV != 0 && luachon.MSSV != 1);
	do
	{
		wprintf(L"In Khoa: ");
		scanf_s("%d", &luachon.Khoa);
	} while (luachon.Khoa != 0 && luachon.Khoa != 1);
	do
	{
		wprintf(L"In Email: ");
		scanf_s("%d", &luachon.Email);
	} while (luachon.Email != 0 && luachon.Email != 1);
	do
	{
		wprintf(L"In Năm Sinh: ");
		scanf_s("%d", &luachon.Ngaysinh);
	} while (luachon.Ngaysinh != 0 && luachon.Ngaysinh != 1);
	do
	{
		wprintf(L"In Ảnh Đại Diện : ");
		scanf_s("%d", &luachon.Hinhanh);
	} while (luachon.Hinhanh != 0 && luachon.Hinhanh != 1);
	do
	{
		wprintf(L"In Mô tả: ");
		scanf_s("%d", &luachon.Motabanthan);
	} while (luachon.Motabanthan != 0 && luachon.Motabanthan != 1);
	do
	{
		wprintf(L"In Sở Thích: ");
		scanf_s("%d", &luachon.Sothich);
	} while (luachon.Sothich != 0 && luachon.Sothich != 1);
}
void ThayThe(sv SV, wchar_t *b)
{
	Choose c;
	Choice(c);
	wchar_t tmp[] = L"\0";	//Chuỗi rỗng
	if (c.MSSV == 1)
		TimKiemVaThayThe(L"1212123", SV.mssv, b);
	else
		TimKiemVaThayThe(L"1212123", tmp, b);
	if (c.Ten == 1)
	{
		TimKiemVaThayThe(L"Nguyễn Văn A", SV.hoten, b);
		TimKiemVaThayThe(L"NGUYỄN VĂN A", SV.hoten, b);
	}
	else TimKiemVaThayThe(L"Nguyễn Văn A", tmp, b);
	if (c.Khoa == 1)
	{
		TimKiemVaThayThe(L"CÔNG NGHỆ THÔNG TIN", wcsupr(SV.khoa), b);
		TimKiemVaThayThe(L"Công nghệ thông tin", SV.khoa, b);
	}
	else
		TimKiemVaThayThe(L"Công nghệ thông tin", tmp, b);
	if (c.Email == 1)
		TimKiemVaThayThe(L"nva@gmail.com", SV.email, b);
	else
		TimKiemVaThayThe(L"nva@gmail.com", tmp, b);
	if (c.Hinhanh == 1)
		TimKiemVaThayThe(L"HinhCaNhan.jpg", SV.image, b);
	else
		TimKiemVaThayThe(L"HinhCaNhan.jpg", tmp, b);
	if (c.Ngaysinh == 1)
		TimKiemVaThayThe(L"20/01/1994", SV.ngaysinh, b);
	else
		TimKiemVaThayThe(L"20/01/1994", tmp, b);
	if (c.Motabanthan == 1)
		TimKiemVaThayThe(L"Tôi là một người rất thân thiện.", SV.mota, b);
	else
		TimKiemVaThayThe(L"Tôi là một người rất thân thiện.", tmp, b);
	if (c.Sothich == 1)
	{
		TimKiemVaThayThe(L"Hobbies ", SV.sothich, b);
	}
	else
		TimKiemVaThayThe(L"Hobbies ", tmp, b);
}
void xuatHTML(sv SV, wchar_t a[1000])
{
	wchar_t filename[30];
	wcscpy(filename, L"Website\\");
	wcscat(filename, SV.mssv);
	wcscat(filename, L".html");
	FILE* fp = _wfopen(filename, L"w, ccs=UTF-8");
	wchar_t *b = wcsdup(a);
	ThayThe(SV, b);
	fputws(b, fp);
	fclose(fp);
}
void wmain()
{
	//Doc unicode
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	sv SV[100];
	wchar_t *a = NULL;
	int n;
	FILE* fpds = _wfopen(L"test.csv", L"r, ccs=UTF-8");
	FILE* fphtml = _wfopen(L"1212123.htm", L"r,ccs=UTF-8");
	if (!fpds || !fphtml)
	{
		wprintf(L"Không thể đọc file \n");
		return;
	}
	else
	{
		n = sosv(fpds);
		wprintf(L"Danh sách chứa %d sinh viên\n", n);
		if (n == 0)
			printf("Empty\n");
		else
		{
			readfile(fpds,n);
			xuatdssv(SV, n);
			wprintf(L"Xin mời bạn lựa chọn có xuất thông tin hay không. \nChọn: 1. \nKhông chọn: 0 ");
			for (int i = 0; i < n; i++)
				xuatHTML(SV[i], a);
		}
	}
	free(SV);
	free(a);
	fcloseall();
	system("pause");
}
