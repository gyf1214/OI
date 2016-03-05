//Created At: Sat Mar 5 13:27:48 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
using namespace std;
class A {
public:
    int val;

	A(int val = 0) : val(val) {}

	A &GetObj(void) {
		return *this;
	}
};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}
