#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset
{
	char a[bitNum/8+1];
	MyBitset() { memset(a,0,sizeof(a));};
	void Set(int i,int v) {
		char & c = a[i/8];
		int bp = i % 8;
		if( v )
			c |= (1 << bp);
		else
			c &= ~(1 << bp);
	}

	bool Get(int i) {
		int bp = i % 8;
		return (a[i / 8] >> bp) & 1;
	}

	class iterator {
		MyBitset *self;
		int bit;
		iterator(MyBitset *self, int bit) : self(self), bit(bit) {}
		friend class MyBitset;
	public:
		operator bool() {
			return self -> Get(bit);
		}
		iterator operator =(bool x) {
			self -> Set(bit, x);
			return *this;
		}
		iterator operator =(iterator x) {
			self -> Set(bit, x);
			return *this;
		}
	};

	iterator operator [](int index) {
		return iterator(this, index);
	}

	void Print() {
		for(int i = 0;i < bitNum; ++i)
			cout << (*this) [i];
		cout << endl;
	}
};

int main()
{
	int n;
	int i,j,k,v;
	while( cin >>  n) {
		MyBitset<20> bs;
		for(int i = 0;i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t,1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}
