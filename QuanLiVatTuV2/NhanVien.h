#pragma once
#include"lib.h"
#include "HoaDon.h"
#include "ChiTietHoaDon.h"
#include "XuLiThaoTacVaDoHoa.h"
#define MAX_NHAN_VIEN 500
struct NhanVien
{
	string manv = "", ho = "", ten = "";
	bool phai = true;
	LISTHD dshd = NULL;
};
typedef struct NhanVien NHANVIEN;

struct DanhSachNhanVien
{
	int n = 0;
	NHANVIEN *nodes[MAX_NHAN_VIEN];
};


//Danh Sách Hàm
bool KiemTraRong(DanhSachNhanVien ds);
bool KiemTraDay(DanhSachNhanVien ds);
int TimKiemNhanVien(DanhSachNhanVien ds, string manv);
int TimViTriThichHop(DanhSachNhanVien ds, string ho, string ten);
bool ThemNhanVienVaoViTriX(DanhSachNhanVien &ds, NHANVIEN nv, int idx);
bool ThemNhanVienSapXepTheoTen(DanhSachNhanVien &ds, NHANVIEN nv);
bool XoaNhanVienTheoViTri(DanhSachNhanVien &ds, int idx);
//Xử Lí file
void tachChuoi(DanhSachNhanVien temp, string line);
void importWord(DanhSachNhanVien &ds, string line);
void readf(DanhSachNhanVien &ds);
void writef(DanhSachNhanVien ds);