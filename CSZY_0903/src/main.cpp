#include <iostream>

using namespace std;
template <class T>
struct MySharedPtr
{
private:
	T *p;
	int *cnt;

	void init(T *p) {
		this -> p = p;
		cnt = new int(1);
	}
public:
	MySharedPtr() : p(NULL), cnt(NULL) {}
	MySharedPtr(T *p) {
		init(p);
	}
	MySharedPtr(const MySharedPtr &s) : p(s.p), cnt(s.cnt) {
		if (p) ++(*cnt);
	}

	T *get() {
		return p;
	}

	void reset() {
		if (p) {
			--(*cnt);
			if (!*cnt) {
				delete p;
				delete cnt;
			}
			p = NULL;
			cnt = NULL;
		}
	}

	void reset(T *sp) {
		reset();
		init(sp);
	}

	~MySharedPtr() {
		reset();
	}

	MySharedPtr &operator =(const MySharedPtr &s) {
		if (s.p == p) return *this;
		reset();
		p = s.p;
		cnt = s.cnt;
		if (p) ++(*cnt);
		return *this;
	}

	operator bool() {
		return p;
	}

	T *operator ->() {
		return p;
	}

	T &operator *() {
		return *p;
	}
};

struct A   {
 	 int n;
	 A(int v = 0):n(v){ }
	 ~A() { cout << n << " destructor" << endl; }
};
int main()
{
	MySharedPtr<A> sp1(new A(2));
	MySharedPtr<A> sp2(sp1);
	cout << "1)" << sp1->n  << "," << sp2->n << endl;
	MySharedPtr<A> sp3;
	A * p = sp1.get();
	cout << "2)" << p->n << endl;
	sp3 = sp1;
	cout << "3)" << (*sp3).n << endl;
	sp1.reset();
	if( !sp1 )
		cout << "4)sp1 is null" << endl; //会输出
	A * q = new A(3);
	sp1.reset(q); //
	cout << "5)" << sp1->n << endl;
	MySharedPtr<A> sp4(sp1);
	MySharedPtr<A> sp5;
	sp5.reset(new A(8));
	sp1.reset();
	cout << "before end main" <<endl;
	sp4.reset();
	cout << "end main" << endl;
	return 0; //程序结束，会delete 掉A(2)
}
