//Created At: Thu Mar 10 13:16:05 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
using namespace std;
class Point {
	private:
		int x;
		int y;
	public:
		Point() { };
		friend istream &operator >>(istream &i, Point &p) {
			i >> p.x >> p.y;
			return i;
		}

		friend ostream &operator <<(ostream &o, Point &p) {
			o << p.x << "," << p.y;
			return o;
		}
};
int main()
{
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
