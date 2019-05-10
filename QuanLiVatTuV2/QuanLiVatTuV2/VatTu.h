#pragma once
#include"lib.h"
#define MAXVT 300
struct Date
{
	int ngay, thang, nam;
};
//Date LayGioHeThong()
//{
//	time_t t = time(0);
//	struct tm * now = localtime(&t);
//	Date date;
//	date.ngay = now->tm_mday;
//	date.thang = now->tm_mon + 1;
//	date.nam = now->tm_year + 1900;
//	return date;
//}
struct ThongKe
{
	int idx = 0;
	int soluongxuat = 0;
};
struct VatTu
{
	char maVT[10];
	//string maVT;
	string tenVT;
	string dvt;
	int soluongton;
};
typedef struct VatTu VATTU;
struct NodeVatTuTree
{
	VATTU vattu;
	NodeVatTuTree* left;
	NodeVatTuTree* right;
	int height;
};
typedef struct NodeVatTuTree* VATTUTREE;
struct DanhSachVatTu
{
	int n = 0;
	VATTU nodes[MAXVT];
};
//cấu trúc thêm , xóa,tìm kiếm
int TimViTriThichHop(DanhSachVatTu ds, string tenVT);
int TimViTriVatTu(DanhSachVatTu ds, char maVT[10]);
bool ThemVatTuVaoViTriX(DanhSachVatTu &ds, VATTU vt, int idx);
bool ThemVatTuSapXepTheoTen(DanhSachVatTu &ds, VATTU vt);
void PreOrder(VATTUTREE* root, DanhSachVatTu &ds);
void DemSoLuongVatTu(VATTUTREE root, int &dem);
int Height(VATTUTREE root);
int Max(int a, int b);
VATTUTREE NewNode(VATTU vt);
VATTUTREE RightRotate(VATTUTREE y);
VATTUTREE LeftRotate(VATTUTREE x);
int GetBalance(VATTUTREE root);	
VATTUTREE ThemVaoCay(VATTUTREE &listNode, VATTU &vt);
VATTUTREE XoaNodeCuaCay(VATTUTREE &node, char maVT[10]);
VATTUTREE TimkiemVatTu(VATTUTREE node, VATTU vt);
VATTUTREE TimkiemMaVatTu(VATTUTREE node, char maVT[10]);
//đọc file
void tachChuoi(VATTUTREE temp, string line);
void importWord(VATTUTREE &tree, string line);
void readf(VATTUTREE &node);
void writef(VATTUTREE node);
void XoaCay(VATTUTREE &root);
int SoLuongVatTuTonKhoCuaMaVT(VATTUTREE &root, string mavt);
void InVatTu(VATTUTREE root);
void ThemMoiVatTu(VATTUTREE &root, int &flag, string &mavt);