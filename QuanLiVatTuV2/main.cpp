#include"VatTu.h"
#include "NhanVien.h"
int main() {
	//---------------------------Vật Tư --------------------------------//
	VATTUTREE tree;
	VATTU vt;
	readf(tree);
	int n = 0;
	 tree->vattu;
	 cout << tree->vattu.maVT << endl;
	 cout << tree->vattu.tenVT << endl;
	 cout << tree->vattu.dvt << endl;
	 cout << tree->vattu.soluongton << endl;
	DemSoLuongVatTu(tree, n);
	int flag = 1;
	string maVT = "";
	ThemMoiVatTu(tree, flag, maVT);
	InVatTu(tree);
	//convert();
	//---------------------------Nhân Viên -------------------------------//
	//DanhSachNhanVien ds;
	//readf(ds);
	system("pause");
}