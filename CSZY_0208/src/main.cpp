//Created At: Sat Mar 5 14:49:07 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;

class CHugeInt {
	int buf[210];

	int &operator [](int index) {
		return buf[index];
	}

	int operator [](int index) const {
		return buf[index];
	}
public:
	CHugeInt(int n) {
		memset(buf, 0, 210 * sizeof(int));
		for (int i = 0; n; n /= 10) buf[i++] = n % 10;
	}

	CHugeInt(const char *ch) {
		memset(buf, 0, 210 * sizeof(int));
		int len = strlen(ch) - 1;
		for (int i = 0; len >= 0; --len) buf[i++] = ch[len] - '0';
	}

	CHugeInt operator +(const CHugeInt &other) const{
		CHugeInt ret = *this;
		for (int i = 0; i < 210; ++i) {
			ret[i] += other[i];
			if (i + 1 < 210) ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}
		return ret;
	}

	CHugeInt &operator ++() {
		*this = *this + 1;
		return *this;
	}

	CHugeInt operator ++(int) {
		CHugeInt ret = *this;
		++(*this);
		return ret;
	}

	friend ostream &operator <<(ostream &o, const CHugeInt &x) {
		int len = 210;
		for (--len; !x[len] && len > 0; --len);
		for (; len >= 0; --len) cout << x[len];
		return o;
	}

	CHugeInt &operator +=(const CHugeInt &other) {
		*this = *this + other;
		return *this;
	}

	friend CHugeInt operator +(int a, const CHugeInt &b) {
		return b + a;
	}
};

int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
