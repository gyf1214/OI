//Created At: Thu Mar 10 13:10:54 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
using namespace std;
class MyInt
{
	int nVal;
	public:
	MyInt( int n) { nVal = n ;}

	operator int() {
		return nVal;
	}

	MyInt &operator -(int n) {
		nVal -= n;
		return *this;
	}
};
int Inc(int n) {
	return n + 1;
}
int main () {
	int n;
	while(cin >>n) {
		MyInt objInt(n);
		objInt-2-1-3;
		cout << Inc(objInt);
		cout <<",";
		objInt-2-1;
		cout << Inc(objInt) << endl;
	}
	return 0;
}
