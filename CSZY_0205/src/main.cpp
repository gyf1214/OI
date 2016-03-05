//Created At: Sat Mar 5 13:29:35 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }

	Complex(const char *ch) {
		r = ch[0] - '0';
		i = ch[2] - '0';
	}

	Complex() : r(0), i(0) {}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
