#include <iostream>
using namespace std;
class MyCin
{
public:
	operator bool() {
		return (bool)cin;
	}
	template <class T>
	friend MyCin &operator >>(MyCin &i, T &x) {
		cin >> x;
		return i;
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
