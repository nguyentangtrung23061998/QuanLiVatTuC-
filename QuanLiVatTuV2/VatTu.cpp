#include"VatTu.h"
int TimViTriThichHop(DanhSachVatTu ds, string tenVT) {
	for (int i = 0; i < ds.n; i++) {
		if (ds.nodes[i].tenVT == tenVT) {
			return i;
		}
	}
	return ds.n;
}
int TimViTriVatTu(DanhSachVatTu ds, char maVT[10]) {
	for (int i = 0; i < ds.n; i++) {
		if (ds.nodes[i].maVT == maVT) return i;
	}
	return -1;
}
bool ThemVatTuVaoViTriX(DanhSachVatTu &ds, VATTU vt, int index) {
	if (index<0 || index>ds.n || ds.n == MAXVT) return false;
	for (int i = ds.n; i > index; i--) {
		ds.nodes[i] = ds.nodes[i - 1];
	}
	ds.nodes[index] = vt;
	ds.n++;
	return true;
}
bool ThemVatTuSapXepTheoTen(DanhSachVatTu &ds, VATTU vt) {
	int index = TimViTriThichHop(ds, vt.tenVT);
	bool kq = ThemVatTuVaoViTriX(ds, vt, index);
	return kq;
}
void PreOrder(NodeVatTuTree* root, DanhSachVatTu &ds) {
	if (root != NULL) {
		ThemVatTuSapXepTheoTen(ds, root->vattu);
		PreOrder(root->left, ds);
		PreOrder(root->right, ds);
	}
}
void DemSoLuongVatTu(VATTUTREE root, int &dem) {
	if (root != NULL) {
		dem++;
		DemSoLuongVatTu(root->left, dem);
		DemSoLuongVatTu(root->right, dem);
	}
}
int Height(VATTUTREE root) {
	if (root != NULL) {
		return 0;
	}
	return root->height;
}
int Max(int a, int b) {
	return a > b ? a : b;
}
VATTUTREE NewNode(VATTU vt) {
	VATTUTREE vtTree = new NodeVatTuTree();
	vtTree->vattu = vt;
	vtTree->left = NULL;
	vtTree->right = NULL;
	vtTree->height = 1;
	return vtTree;
}
VATTUTREE RightRotate(VATTUTREE y) {
	VATTUTREE x = y->left;
	VATTUTREE T2 = x->right;
	x->right = y;
	y->left = T2;
	// cap nhat chieu cao cay
	y->height = Max(Height(y->left), Height(y->right)) + 1;
	x->height = Max(Height(x->left), Height(x->right)) + 1;
	return x;
}
VATTUTREE LeftRotate(VATTUTREE x) {
	VATTUTREE y = x->right;
	VATTUTREE T2 = y->left;
	y->left = x;
	x->right = T2;
	// cap nhat chieu cao cay
	x->height = Max(Height(x->left), Height(x->right)) + 1;
	y->height = Max(Height(y->left), Height(y->right)) + 1;
	return y;
}
int GetBalance(VATTUTREE root) {
	if (root == NULL) return 0;
	return (Height(root->left) - Height(root->right));
}
VATTUTREE ThemVaoCay(VATTUTREE &listNode, VATTU &vt) {
	if (listNode == NULL) {
		return NewNode(vt);
	}
	if (vt.maVT < listNode->vattu.maVT)
		listNode->left = ThemVaoCay(listNode->left, vt);
	if (vt.maVT > listNode->vattu.maVT)
		listNode->right = ThemVaoCay(listNode->right, vt);
	else
		return listNode;
	listNode->height = Max(Height(listNode->left), Height(listNode->right)) + 1;
	int balance = GetBalance(listNode);
	// mat can bang trai-trai
	if (balance > 1 && vt.maVT < listNode->left->vattu.maVT)
		return RightRotate(listNode);
	// mat can bang phai-phai    
	if (balance < -1 && vt.maVT > listNode->right->vattu.maVT)
		return LeftRotate(listNode);
	// mat can bang trai-phai    
	if (balance > 1 && vt.maVT > listNode->left->vattu.maVT)
	{
		listNode->left = LeftRotate(listNode->left);
		return RightRotate(listNode);
	}
	// mat can bang phai-trai
	if (balance < -1 && vt.maVT < listNode->vattu.maVT)
	{
		listNode->right = RightRotate(listNode->right);
		return LeftRotate(listNode);
	}
	return listNode;
}
VATTUTREE XoaNodeCuaCay(VATTUTREE &node, char maVT[10]) {
	if (node == NULL) return node;
	if (maVT < node->vattu.maVT) {
		XoaNodeCuaCay(node->left, maVT);
	}
	if (maVT > node->vattu.maVT) {
		XoaNodeCuaCay(node->right, maVT);
	}
	if (maVT == node->vattu.maVT) {
		if ((node->left == NULL) || (node->right == NULL)) {
			VATTUTREE temp;
			if (temp = node->left) return temp = node->left;
			if (temp = node->right) return temp = node->right;
			if (temp == NULL) {
				temp = node;
				node = NULL;
			}
			else {
				*node = *temp;
			}
			delete temp;
		}
		else {
			VATTUTREE current = node;
			VATTUTREE temp;
			while (current->left != NULL) {
				current = current->left;
			}
			temp = current;
			node->vattu = temp->vattu;
			//node->right = XoaNodeCuaCay(node->right, temp->vattu.maVT);
		}
	}
}
VATTUTREE TimkiemVatTu(VATTUTREE node, VATTU vt) {
	VATTUTREE temp = node;
	while (temp != NULL && (temp->vattu.maVT != vt.maVT)) {
		if (vt.maVT > temp->vattu.maVT) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return temp;
}
VATTUTREE TimkiemMaVatTu(VATTUTREE node, char maVT[10]) {
	VATTUTREE temp = node;
	while (temp != NULL && temp->vattu.maVT != maVT) {
		if (maVT < temp->vattu.maVT) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return temp;
}

void tachChuoi(VATTUTREE temp, string line) {
	int d = 0;
	int i = 0;
	string tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	strcpy_s(temp->vattu.maVT, (char *)tach.c_str());
	cout << temp->vattu.maVT;
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	temp->vattu.tenVT = tach;
	cout << temp->vattu.tenVT << "\n";
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	temp->vattu.dvt = tach;
	cout << tach << "\n";
	tach = "";

	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	stringstream str2num(tach);
	int x = 0;
	str2num >> x;
	temp->vattu.soluongton = x;
	cout << temp->vattu.soluongton << "\n";
	tach = "";
}
void importWord(VATTUTREE &tree, string line) {
	tree = new NodeVatTuTree();
	tachChuoi(tree, line);
	tree->left = NULL;
	tree->right = NULL;
}
void readf(VATTUTREE &node) {
	ifstream fi("vattu.txt");
	string line;
	if (!fi) {
		cerr << "Error while opening file\n";
		return;
	}
	while (getline(fi, line)) {
		importWord(node, line);
	}
	fi.close();
}
void writef(VATTUTREE node) {
	ofstream fo("vattu.txt");
	string data;
	if (!fo)return;
	DanhSachVatTu ds;
	ds.n = 0;
	PreOrder(node, ds);
	for (int i = 0; i < ds.n; i++) {
		if (i > 0) fo << endl;
		fo << ds.nodes[i].maVT;
		fo << "@" << ds.nodes[i].tenVT;
		fo << "@" << ds.nodes[i].dvt;
		fo << "@" << ds.nodes[i].soluongton<<"@";
	}
	fo.close();
}
void XoaCay(VATTUTREE &root) {
	if (root == NULL) return;
	XoaCay(root->left);
	XoaCay(root->right);
	delete root;
}
int SoLuongVatTuTonKhoCuaMaVT(VATTUTREE &root, string mavt)
{
	VATTUTREE p = root;
	while (p != NULL && p->vattu.maVT != mavt)
	{
		if (mavt < p->vattu.maVT)
		{
			p = p->left;
		}
		else if (mavt > p->vattu.maVT)
		{
			p = p->right;
		}
	}
	return p->vattu.soluongton;
}
void InVatTu(VATTUTREE root) {
	DanhSachVatTu ds;
	PreOrder(root, ds);
	if (ds.n == 0)
	{
		string s = "Danh Sach Vat Tu Rong";
		cout << s;
		return;
	}
	string str;
	//int vtdau = (trang - 1) * 10;
	VATTU vt;
	int tam = 0;
	for (int i = 0; i < ds.n; i++)
	{
		vt = ds.nodes[i];
		tam++;
		// mavt
		cout << vt.maVT;
		// tenvt
		cout << vt.tenVT;
		// dvt
		cout << vt.dvt;
		// soluongton
		cout << vt.soluongton;
		cout << "\n";
	}
}
void ThemMoiVatTu(VATTUTREE &root, int &flag, string &mavt) {
	VATTU vt;
	int c;
	int idx = 0;
	string soluongstr = "";
	VATTUTREE temp;
	/*vt.soluongton = 0;
	DanhSachVatTu ds;
	ds.n = 0;
	cout << ds.nodes<<endl;*/
	cout << "\nVui long nhap ma vat tu";
	cin.getline(vt.maVT, 10);
	cout << "\nVui long nhap ten vat tu";
	getline(cin, vt.tenVT);
	cout << "\nVui long  nhap don vi tinh";
	getline(cin, vt.dvt);
	cout << "\nVui long nhap so luong ton";
	cin >> vt.soluongton;
	temp = TimkiemMaVatTu(root, vt.maVT);
	if (temp == NULL) {
		root = ThemVaoCay(root, vt);
		flag = 1;
		mavt = vt.maVT;
		cout << "\nThem thanh cong";
		writef(root);
	}
	else {
		cout << "\nMa Vat tu them khong ton tai";
		idx = 0;
	}
	flag = 0;
}