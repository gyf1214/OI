//Created At: Fri Mar 11 13:56:12 CST 2016
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
#define mm
using namespace std;

const int Types = 5;
const char *Names[] = {
	"dragon", "ninja", "iceman", "lion", "wolf"
};
const char *Weapons[] = {
    "sword", "bomb", "arrow"
};
const char *Teams[] = { "red", "blue" };
const int List[][Types] = {
	2, 3, 4, 1, 0,
	3, 0, 1, 2, 4
};
int least, tick;

class HQ;

class Man {
protected:
    int life, type, side, id;
    const char *Team(void);
    const char *Name(void);
public:
    Man(int);
    virtual ~Man(void);
    virtual void Print(HQ *);
    static Man *Instance(int);
    static void Life(int, int);
    static int Life(int);
};

template<int t>
class Unit : public Man {
    Unit();
public:
    void Print(HQ *);
    void Extra(HQ *);
    static Man *Inst();
};

class HQ {
    int life, side, now, tot;
    int count[Types];
    int fetch(void);
public:
	HQ(int, int);
    bool Build(void);
    friend class Man;
    template<int t> friend class Unit;
};

typedef Unit<0> Dragon;
typedef Unit<1> Ninja;
typedef Unit<2> Iceman;
typedef Unit<3> Lion;
typedef Unit<4> Wolf;

inline int next(int i) {
    return (i + 1) % Types;
}

HQ::HQ(int m, int side) : life(m), side(side), tot(0), now(Types - 1) {
    clr(count, 0);
}

int HQ::fetch() {
    for (now = next(now); life < Man::Life(List[side][now]); now = next(now));
    int next = List[side][now];
    life -= Man::Life(next);
    ++count[next]; ++tot;
    return next;
}

bool HQ::Build() {
    if (life < least) {
        if (life >= 0) {
            printf("%03d %s headquarter stops making warriors\n", tick, Teams[side]);
            life = -1;
        }
        return false;
    }
    int type = fetch();
    Man::Instance(type) -> Print(this);
    return true;
}

const char *Man::Team() {
    return Teams[side];
}

const char *Man::Name() {
    return Names[type];
}

Man::Man(int type) : type(type) {}

Man::~Man() {}

Man *Man::Instance(int type) {
    static Man *list[] = {
        Dragon::Inst(), Ninja::Inst(), Iceman::Inst(), Lion::Inst(), Wolf::Inst()
    };
    return list[type];
}

void Man::Life(int type, int life) {
    Instance(type) -> life = life;
}

int Man::Life(int type) {
    return Instance(type) -> life;
}

void Man::Print(HQ *hq) {
    id = hq -> tot;
    side = hq -> side;
    printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
    tick, Team(), Name(), id, life, hq -> count[type], Name(), Team());
}

template<int t>
Unit<t>::Unit() : Man(t) {}

template<int t>
void Unit<t>::Print(HQ *hq) {
    Man::Print(hq);
    Extra(hq);
}

template<int t>
Man *Unit<t>::Inst() {
    static Unit<t> inst;
    return &inst;
}

template<> void Dragon::Extra(HQ *hq) {
    int w = id % 3;
    double mor = (double)hq -> life / (double)life;
    printf("It has a %s,and it's morale is %.2lf\n", Weapons[w], mor);
}

template<> void Ninja::Extra(HQ *hq) {
    int w1 = id % 3, w2 = (id + 1) % 3;
    printf("It has a %s and a %s\n", Weapons[w1], Weapons[w2]);
}

template<> void Iceman::Extra(HQ *hq) {
    int w = id % 3;
    printf("It has a %s\n", Weapons[w]);
}

template<> void Lion::Extra(HQ *hq) {
    int loy = hq -> life;
    printf("It's loyalty is %d\n", loy);
}

template<> void Wolf::Extra(HQ *hq) {}

int main() {
    int t;
    scanf("%d", &t);
    rep(i, 1, t) {
        printf("Case:%d\n", i);
        tick = 0;
        int m;
        scanf("%d", &m);
        HQ red(m, 0), blue(m, 1);
        least = infi;
        rep(i, 0, 4) {
            scanf("%d", &m);
            Man::Life(i, m);
            least = min(least, m);
        }
        bool a, b;
        do {
            a = red.Build();
            b = blue.Build();
            ++tick;
        } while (a || b);
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
