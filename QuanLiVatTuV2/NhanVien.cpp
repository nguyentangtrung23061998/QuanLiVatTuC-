#include "NhanVien.h"
bool KiemTraRong(DanhSachNhanVien ds)
{
	if (ds.n == 0) return true;
	return false;
}
bool KiemTraDay(DanhSachNhanVien ds)
{
	if (ds.n == MAX_NHAN_VIEN) return true;
	return false;
}
//tim kiem NV theo ma, co thi tra ve vitri, khong thi return -1
int TimKiemNhanVien(DanhSachNhanVien ds, string manv)
{
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.nodes[i]->manv == manv) return i;
	}
	return -1;
}
int TimViTriThichHop(DanhSachNhanVien ds, string ho, string ten)
{
	string t1 = ten + ho;
	string t2;
	for (int i = 0; i < ds.n; i++)
	{
		t2 = ds.nodes[i]->ten + ds.nodes[i]->ho;
		if (t2 >= t1) return i;// chi lay vi tri, chua lam gi
	}
	return ds.n;
}
bool ThemNhanVienVaoViTriX(DanhSachNhanVien &ds, NHANVIEN nv, int idx)
{
	if (idx < 0 || idx > ds.n || KiemTraDay(ds)) return false;
	ds.nodes[ds.n] = new NHANVIEN;
	for (int i = ds.n; i > idx; i--)
	{
		*ds.nodes[i] = *ds.nodes[i - 1];
	}
	*ds.nodes[idx] = nv;
	ds.n++;
	return true;
}
bool ThemNhanVienSapXepTheoTen(DanhSachNhanVien &ds, NHANVIEN nv)
{
	ChuanHoaChuoi(nv.ten); ChuanHoaChuoi(nv.ho);
	int idx = TimViTriThichHop(ds, nv.ho, nv.ten);
	bool kq = ThemNhanVienVaoViTriX(ds, nv, idx);
	return kq;
}
bool XoaNhanVienTheoViTri(DanhSachNhanVien &ds, int idx)
{
	if (idx < 0 || idx > ds.n || KiemTraRong(ds)) return false;

	for (int i = idx; i < ds.n - 1; i++)
	{
		*ds.nodes[i] = *ds.nodes[i + 1];
	}
	delete ds.nodes[ds.n - 1];
	ds.n--;
	return true;
}


//------------------------HD-------------------------//
void ChenHDVaoDauDanhSach(LISTHD &first, string soHD) {
	//T?o 1 nút trung gian
	//LISTHD p = new LISTHD();
	NodeHD *p = new NodeHD();
	p->infohd.sohd = soHD;
	p->next = NULL;
	////tru?ng h?p ds chua có ph?n t? nào
	if (first == NULL) {
		first = p;
	}
	else {
		p->next = first;
		first = p;
	}
}
//xử lí file
void tachChuoi(NhanVien nv, string line) {
	int k = 0;
	int i = 0;
	string tach = "";
	boolean sex = true;
	DanhSachNhanVien *dsnv = new DanhSachNhanVien();
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	nv.manv = tach;
	tach = "";

	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	nv.ho = tach;
	tach = "";

	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	nv.ten = tach;
	tach = "";

	while (line[i] != '@') {
		tach += line[i];
		i++;
		if (tach == "Nam") {
			sex = true;
		}
		else {
			sex = false;
		}
	}
	i++;
	if (sex)
		nv.phai = "Nam";
	else
		nv.phai = "Nu";
	tach = "";

	/*nv.dshd->pHead = NULL;
	while (line[i] != NULL) {
		tach = "";
		while (line[i] != '@') {
			tach += line[i];
			i++;
		}
		i++;
		ChenHDVaoDauDanhSach(nv.dshd->pHead, tach);
	}
	cout << typeid(nv).name()<<endl;
	cout << typeid(dsnv).name() << endl;*/
	//dsnv->nodes[k++] = nv;
	//dsnv.nodes[k] = nv;
	//k++;
}
void importWord(DanhSachNhanVien &ds, string line) {
	/*tachChuoi(ds, line);
	cout << "OK\n";*/
}
void readf(DanhSachNhanVien &ds) {
	ifstream fi("nhanvien.txt");
	NhanVien nv;
	string line;
	if (!fi) {
		cerr << "Error while opening file\n";
		return;
	}
	while (getline(fi, line)) {
		//importWord(ds, line);
		tachChuoi(nv, line);
	}
	fi.close();
}