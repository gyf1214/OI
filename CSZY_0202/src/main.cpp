//Created At: Sat Mar 5 13:25:18 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int
	val = 123) : val(val) {}

	A &GetObj(void) {
		return *this;
	}
};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}
