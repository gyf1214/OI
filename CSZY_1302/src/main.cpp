//Created At: Fri May 27 11:28:05 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 30000
using namespace std;

struct DLX {
	int n, m, size;
	int sum[mm];
	int col[mm], row[mm];
	int l[mm], r[mm], u[mm], d[mm];
	int ans[mm];

	void init(int m) {
		n = 0;
		this -> m = m;
		size = m + 1;
		rep(i, 0, m) {
			l[i] = i - 1;
			r[i] = i + 1;
			u[i] = d[i] = i;
		}
		r[m] = 0;
		l[0] = m;
		clr(sum, 0);
	}

	void add(const vector<int> &cc) {
		++n;
		int first = size;
		rep(i, 0, cc.size() - 1) {
			int j = cc[i];
			l[size] = size - 1;
			r[size] = size + 1;
			u[size] = u[j];
			d[size] = j;
			d[u[size]] = u[j] = size;
			col[size] = j;
			row[size] = n;
			++sum[j];
			++size;
		}
		r[size - 1] = first;
		l[first] = size - 1;
	}

	void remove(int j) {
		l[r[j]] = l[j];
		r[l[j]] = r[j];
		for (int i = d[j]; i != j; i = d[i]) {
			for (int k = r[i]; k != i; k = r[k]) {
				u[d[k]] = u[k];
				d[u[k]] = d[k];
				--sum[col[k]];
			}
		}
	}

	void restore(int j) {
		for (int i = u[j]; i != j; i = u[i]) {
			for (int k = l[i]; k != i; k = l[k]) {
				++sum[col[k]];
				d[u[k]] = k;
				u[d[k]] = k;
			}
		}
		r[l[j]] = j;
		l[r[j]] = j;
	}

	bool dfs(int depth) {
		if (r[0] == 0) return true;
		int p = r[0];
		for (int i = r[p]; i; i = r[i]) {
			if (sum[i] < sum[p]) p = i;
		}
		remove(p);
		for (int i = d[p]; i != p; i = d[i]) {
			ans[depth] = row[i];
			for (int j = r[i]; j != i; j = r[j]) remove(col[j]);
			if (dfs(depth + 1)) return true;
			for (int j = l[i]; j != i; j = l[j]) restore(col[j]);
		}
		restore(p);
		return false;
	}
}dlx;

int x[mm], y[mm], num[mm];
int ans[20][20];
vector<int> row;
char str[20];

void ins(int i, int j, int t) {
	row.clear();
	row.push_back(i * 16 + j + 1);
	row.push_back(i * 16 + t + 16 * 16 + 1);
	row.push_back(j * 16 + t + 16 * 16 * 2 + 1);
	int k = i / 4 * 4 + j / 4;
	row.push_back(k * 16 + t + 16 * 16 * 3 + 1);
	dlx.add(row);
	x[dlx.n] = i;
	y[dlx.n] = j;
	num[dlx.n] = t;
}

bool pre() {
	dlx.init(16 * 16 * 4);
	rep(i, 0, 15) {
		if (scanf("%s", str) == EOF) return false;
		rep(j, 0, 15) {
			if (str[j] == '-') {
				rep(k, 0, 15) ins(i, j, k);
			} else ins(i, j, str[j] - 'A');
		}
	}
	return true;
}

void work() {
	dlx.dfs(0);
	rep(i, 0, 255) {
		int r = dlx.ans[i];
		ans[x[r]][y[r]] = num[r];
	}
	rep(i, 0, 15) rep(j, 0, 15) {
		printf("%c%s", 'A' + ans[i][j], j == 15 ? "\n" : "");
	}
	printf("\n");
}

int main() {
	while(pre()) work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
