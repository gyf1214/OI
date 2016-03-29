#include <iostream>
using namespace std;
class MyCin
{
	bool end;
public:
	MyCin() : end(false) {}
	MyCin &operator >>(int &x) {
		if (end) return *this;
		int y;
		cin >> y;
		if (y == -1) end = true; else x = y;
		return *this;
	}
	operator bool() {
		return !end;
	}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2)
        cout  << n1 << " " << n2 << endl;
    return 0;
}
