#include"XuLiThaoTacVaDoHoa.h"
int KeyPressed()
{
	int a = _getch();
	if (a == 0 || a == 224)
	{
		a = 256 + _getch();
	}
	return a;
}
void ChuanHoaChuoi(string &s)
{
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
	}
	if (s[0] == ' ') s.erase(0, 1);
	if (s[s.length() - 1] == ' ') s.erase(s.length() - 1, 1);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
			i--;
		}
	}
	if (s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			if (s[i + 1] >= 'a' && s[i + 1] <= 'z') s[i + 1] -= 32;
		}
	}
}
void XoaKhoangTrang(string &s)
{
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
	}
}
void ChuanHoaMa(string &s)
{
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
}