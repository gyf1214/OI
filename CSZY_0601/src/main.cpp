//Created At: Mon Mar 28 08:45:19 CST 2016
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

class BaseUnit;
class IFactory;
template <class T> class Factory;
class City;
class HQ;
class Game;

class BaseUnit {
protected:
    int life, atk, type, side, id;
    int weapon[3];
    City *city;
    Game *game;
    const char *team(void);
    const char *name(void);
public:
    BaseUnit(Game *, int, int);
    virtual ~BaseUnit(void);
    City *getCity(void);
    HQ *getHQ(void);
    bool dead(void);

    virtual void afterBorn(void);
    virtual void beforeMarch(void);
    virtual void march(void);
    virtual void afterMarch(void);
    virtual void beforeShot(void);
    virtual void shot(void);
    virtual void beforeBattle(BaseUnit *);
    virtual void attack(BaseUnit *, bool);
    virtual void hurt(BaseUnit *, int, bool);
    virtual void afterBattle(BaseUnit *, bool);
    virtual void report(void);
};

class Dragon : public BaseUnit {
    double morale;
public:
    Dragon(Game *, int);
    void afterBorn(void);
    void afterBattle(BaseUnit *, bool);
};

class Ninja : public BaseUnit {
public:
    Ninja(Game *, int);
    void afterBorn(void);
    void hurt(BaseUnit *, int, bool);
};

class Iceman : public BaseUnit {
public:
    Iceman(Game *, int);
    void afterBorn(void);
    void afterMarch(void);
};

class Lion : public BaseUnit {
    int loyalty;
    int lastLife;
public:
    void afterBorn(void);
    void beforeMarch(void);
    void beforeBattle(BaseUnit *);
    void afterBattle(BaseUnit *, bool);
};

class Wolf : public BaseUnit {
public:
    void afterBorn(void);
    void afterBattle(BaseUnit *, bool);
};

class IFactory {
public:
    virtual BaseUnit *create(void) = 0;
};

template <class T>
class Factory {
public:
    BaseUnit *create(void);
};

class City {
    int life, flag, lastWinner;
public:
    City(void);
    BaseUnit *unit[2];
    void battle(void);
};

class HQ {
    int life, currentUnit;
public:
    HQ(void);
    int reward(void);
    int addLife(void);
    BaseUnit *build(void);
};

class Game {
    int time;
    int arrowAtk, lionDec, endTime;
    int life[Types], atk[Types];
    City *cities;
    HQ hq[2];
public:
    Game(void);
    void initialize(void);
    bool tick(void);
    void printTime(void);
    HQ *getHQ(int);
    City *getCity(int);
}

int main() {
	fclose(stdin);
	fclose(stdout);
	return 0;
}
