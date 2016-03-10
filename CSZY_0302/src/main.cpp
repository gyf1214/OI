//Created At: Thu Mar 10 13:44:32 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
using namespace std;
struct A {
	int nouse;
        int n;

	A(int i):n(i) { };
	A() { }
};
int mysort(void * a,int n,int w,
	int (* compare)(const void * e1,const void * e2)) {
	char *tmp = new char[w];
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			char *x = (char *)a + i * w, *y = (char *)a + j * w;
			if (compare(x, y) > 0) {
				for (int k = 0; k < w; ++k) tmp[k] = x[k];
				for (int k = 0; k < w; ++k) x[k] = y[k];
				for (int k = 0; k < w; ++k) y[k] = tmp[k];
			}
		}
	}
	delete []tmp;
	return 0;
}

int MyCompare1( const void * e1,const void * e2)
{
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	return * p1 - * p2;
}
int MyCompare2( const void * e1,const void * e2)
{
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	return (* p1 %10) - (* p2 % 10);
}
int MyCompare3( const void * e1,const void * e2)
{
	A * p1 = (A*) e1;
	A * p2 = (A*) e2;
	return p1->n - p2->n;
}
int a[20];
A b[20];
int main ()
{
	int n;
	while(cin >> n) {
		for(int i = 0;i < n; ++i) {
			cin >> a[i];
			b[i] = a[i];
		}
		mysort(a,n,sizeof(int),MyCompare1);
		for(int i = 0;i < n; ++i)
			cout << a[i] << "," ;
		cout << endl;
		mysort(a,n,sizeof(int),MyCompare2);
		for(int i = 0;i < n; ++i)
			cout << a[i] << "," ;
		cout << endl;
		mysort(b,n,sizeof(A),MyCompare3);
		for(int i = 0;i < n; ++i)
			cout << b[i].n << "," ;
		cout << endl;
	}
	return 0;
}
