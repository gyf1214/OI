//Created At: Sat Mar 5 13:35:57 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
	int *buf;
	int n, m;

	void copy(const Array2 &src) {
		n = src.n; m = src.m;
		buf = new int[n * m];
		memcpy(buf, src.buf, n * m * sizeof(int));
	}

public:
	Array2() : buf(NULL) {}

	Array2(int n, int m) : n(n), m(m) {
		buf = new int[n * m];
	}

	Array2(const Array2 &src) {
		copy(src);
	}

	~Array2() {
		if (buf) delete []buf;
	}

	int *operator [](int index) {
		return buf + m * index;
	}

	int &operator ()(int i, int j) {
		return buf[i * m + j];
	}

	Array2 &operator =(const Array2 &src) {
		if (buf) delete []buf;
		copy(src);
		return *this;
	}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
