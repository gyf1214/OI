#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
    class Iter2D {
		T *st;
		int z;
	public:
		Iter2D(T *st, int z) : st(st), z(z) {}
		T *operator [](int i) {
			return st + i * z;
		}
        operator T *() {
            return st;
        }
	};

	T *p;
	int x, y, z;
public:
	CArray3D(int x, int y, int z) : x(x), y(y), z(z) {
		p = new T[x * y * z];
	}
	~CArray3D() {
		delete []p;
	}
	Iter2D operator [](int i) {
		return Iter2D(p + i * y * z, z);
	}
    void PrintAll() {
        for (int i = 0; i < x; ++i) {
            cout << "layer " << i << ":\n";
            for (int j = 0; j < y; ++j) {
                for (int k = 0; k < z; ++k) cout << p[i * y * z + j * z + k] << ",";
                cout << endl;
            }
        }
    }
};

int main()
{
	CArray3D<int> a(3,4,5);
	int No = 0;
	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 4; ++j )
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
	a.PrintAll();
	memset(a[1],-1 ,20*sizeof(int));
	a.PrintAll();
	memset(a[1][1],0 ,5*sizeof(int));
	a.PrintAll();
	CArray3D<double> b(3,2,2);
	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	b.PrintAll();
	return 0;
}
