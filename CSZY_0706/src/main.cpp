//Created At: Fri Apr 1 14:40:03 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm
using namespace std;

typedef set<pair<int, int> > container;
typedef container::iterator iter;

container a;

class comp {
	int x;
public:
	comp(int x) : x(x) {}
	bool operator ()(const iter &a, const iter &b) {
		return make_pair(abs(a -> first - x), a -> second)
			< make_pair(abs(b -> first - x), b -> second);
	}
};

iter find(int x) {
	iter i = a.lower_bound(make_pair(x, -infi));
	iter j = a.upper_bound(make_pair(x, infi));

	if (i != j) return i;

	if (i != a.begin()) --i;
	i = a.lower_bound(make_pair(i -> first, -infi));
	if (j == a.end()) return i;

	j = a.lower_bound(make_pair(j -> first, -infi));

	return min(i, j, comp(x));
}

void work() {
	a.insert(make_pair(1000000000, 1));
	int n;
	scanf("%d", &n);
	rep(i, 1, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		iter z = find(y);
		printf("%d %d\n", x, z -> second);
		a.insert(make_pair(y, x));
	}
}

int main() {
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
