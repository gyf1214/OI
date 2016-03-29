//Created At: Mon Mar 28 20:17:52 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm
using namespace std;

int factor(int x) {
	int ans = 0;
	while(x > 1) {
		int t = sqrt(x);
		int i;
		for (i = 2; i <= t; ++i) {
			if (x % i == 0) break;
		}
		if (i > t) break;
		++ans;
		while(x % i == 0) x /= i;
	}
	if (ans > 0 && x > 1) ++ans;
	return ans;
}

priority_queue<pair<int, int> > pq1;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq2;


int main() {
	int n;
	scanf("%d", &n);
	rep(t, 1, n) {
		rep(t2, 1, 10) {
			int x;
			scanf("%d", &x);
			int y = factor(x);
			pq1.push(make_pair(y, x));
			pq2.push(make_pair(y, x));
		}
		printf("%d %d\n", pq1.top().second, pq2.top().second);
		pq1.pop();
		pq2.pop();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
