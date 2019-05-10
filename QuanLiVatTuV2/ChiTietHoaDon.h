#pragma once
#include"lib.h"
#define MAX 500
struct cthd
{
	string mavt = "";
	int soluong, dongia, vat;
};
typedef struct cthd CTHD;
struct DanhSachChiTietHoaDon
{
	int n = 0;
	CTHD node[MAX];
};
typedef struct NodeCTHD* LISTCTHD;