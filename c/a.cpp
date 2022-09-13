#include<iostream>
using namespace std;

int main()
{
	char a[4] = "ི";
	cout << a << endl;
	cout << int(a[0]) << " " << int(a[1]) << " " << int(a[2]) << endl;
	char b[4];
	b[0] = char(-32); b[1] = char(-67); b[2] = char(-128); b[3] = '\0';
	cout << "b = " << b << endl;
	char space = ' ';
	cout << "----" << space << "----" << int(space) << endl;
	return 0;
}
