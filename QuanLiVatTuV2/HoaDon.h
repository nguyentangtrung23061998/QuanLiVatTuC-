#pragma once
#include"lib.h"
#include"ChiTietHoaDon.h"
struct HoaDon
{
	string sohd;
	char loai = 'N';
	LISTCTHD dscthd = NULL;

};
typedef struct HoaDon HOADON;
struct NodeHD
{
	HOADON infohd;
	NodeHD *next;
};
typedef struct NodeHD* LISTHD;