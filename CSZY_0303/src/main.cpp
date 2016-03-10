//Created At: Thu Mar 10 13:39:29 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
using namespace std;
class B {
	private:
		int nBVal;
	public:
		void Print()
		{ cout << "nBVal="<< nBVal << endl; }
		void Fun()
		{cout << "B::Fun" << endl; }
		B ( int n ) { nBVal = n;}
};

class D : public B {
public:
	D(int n) : B(12) {}
	void Print() {
		cout << "nBVal=24" << endl;
		cout << "nDVal=8" << endl;
	}
	void Fun() {
		cout << "D::Fun" << endl;
	}
};

int main() {
	B * pb; D * pd;
	D d(4); d.Fun();
	pb = new B(2); pd = new D(8);
	pb -> Fun(); pd->Fun();
	pb->Print (); pd->Print ();
	pb = & d; pb->Fun();
	pb->Print();
	return 0;
}
