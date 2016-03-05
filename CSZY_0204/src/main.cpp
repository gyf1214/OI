//Created At: Sat Mar 5 14:00:28 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
using namespace std;

const int TypeCount = 5;

const char *TypeName[] = {
	"dragon", "ninja", "iceman", "lion", "wolf"
};

const char * TeamName[] = {"red", "blue"};

const int BuildList[][TypeCount] = {
	2, 3, 4, 1, 0,
	3, 0, 1, 2, 4
};

int TypeLife[TypeCount];

int LeastLife;

class Headquarters {
	int life, team, now, tot;
	bool stop;
	int count[TypeCount];
public:
	Headquarters(int m, int team) : life(m), team(team), stop(false), tot(0), now(TypeCount - 1) {
		clr(count, 0);
	}

	bool isStopped() {
		return stop;
	}

	void Build(int tick) {
		if (stop) return;
		if (life < LeastLife) {
			printf("%03d %s headquarter stops making warriors\n", tick, TeamName[team]);
			stop = true;
		} else {
			for (now = (now + 1) % TypeCount;
				life < TypeLife[BuildList[team][now]]; now = (now + 1) % TypeCount);
			int next = BuildList[team][now];
			life -= TypeLife[next];
			++count[next]; ++tot;
			printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
				tick, TeamName[team], TypeName[next], tot, TypeLife[next],
				count[next], TypeName[next], TeamName[team]);
		}
	}
};

int main() {
	int t, m;
	scanf("%d", &t);
	rep(i, 1, t) {
		LeastLife = infi;
		scanf("%d", &m);
		rep(i, 0, TypeCount - 1) {
			scanf("%d", TypeLife + i);
			LeastLife = min(LeastLife, TypeLife[i]);
		}
		Headquarters red(m, 0), blue(m, 1);
		printf("Case:%d\n", i);
		int tick = 0;
		while (!(red.isStopped() && blue.isStopped())) {
			red.Build(tick); blue.Build(tick++);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
