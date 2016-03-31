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
    "arrow", "bomb", "sword"
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
    bool killing;
    int weapon[3];
    City *city;
    Game *game;
    const char *team(void);
    const char *name(void);
    void printName(void);
    BaseUnit *enemy(void);
    int getAtk(bool);
    bool decideBomb(BaseUnit *);
    void initWeapon(int);
public:
    BaseUnit(Game *, int, int);
    virtual ~BaseUnit(void);
    City *getCity(void);
    int getCityId(void);
    HQ *getHQ(void);
    bool dead(void);
    bool inEnemyHQ(void);

    virtual void afterBorn(void);
    virtual void beforeMarch(void);
    virtual void march(void);
    virtual void afterMarch(void);
    virtual void shot(void);
    virtual void beforeBattle(void);
    virtual void attack(bool);
    virtual void hurt(BaseUnit *, int, bool);
    virtual void afterBattle(void);
    virtual void reward(void);
    virtual void report(void);
};

class Dragon : public BaseUnit {
    double morale;
public:
    Dragon(Game *, int);
    void afterBorn(void);
    void afterBattle(bool);
};

class Ninja : public BaseUnit {
public:
    Ninja(Game *, int);
    void hurt(BaseUnit *, int, bool);
};

class Iceman : public BaseUnit {
    bool flag;
public:
    Iceman(Game *, int);
    void afterMarch(void);
};

class Lion : public BaseUnit {
    int loyalty;
    int lastLife;
public:
    Lion(Game *, int);
    void afterBorn(void);
    void beforeMarch(void);
    void beforeBattle(void);
    void afterBattle(void);
};

class Wolf : public BaseUnit {
public:
    Wolf(Game *, int);
    void afterBattle(void);
};

class IFactory {
public:
    virtual BaseUnit *create(Game *, int, int) = 0;
};

template <class T>
class Factory : public IFactory {
public:
    BaseUnit *create(Game *, int, int);
};

class City {
    int life, flag, lastWinner;
public:
    City(void);
    BaseUnit *unit[2];
    void battle(void);
    int getLife(void);
    int getAttacker(void);
    bool win(int);
    City *next(int);
};

class HQ {
    int life, currentUnit;
    int count, side;
public:
    HQ(int);
    int reward(void);
    void addLife(int);
    int getLife(void);
    int build(void);
    int getCount(void);
};

class Game {
    int time, cityCount;
    int arrowAtk, lionDec, endTime;
    int life[Types], atk[Types];
    City *cities;
    HQ hq[2];
public:
    Game(void);
    HQ *getHQ(int);
    City *getCity(int);
    City *getHQCity(int);
    int getCityId(City *);
    int getLife(int);
    int getAtk(int);

    void initialize(void);
    bool tick(void);
    void printTime(void);
}

const char *BaseUnit::team() {
    return Teams[side];
}

const char *BaseUnit::name() {
    return Names[side];
}

void BaseUnit::printName() {
    printf("%s %s %d", team(), name(), id);
}

BaseUnit *BaseUnit::enemy() {
    return city -> unit[side ^ 1];
}

int BaseUnit::getAtk(bool b) {
    return b ? (atk + weapon[2]) : (atk / 2 + weapon[2]);
}

bool BaseUnit::decideBomb() {
    if (enemy() -> dead()) return false;
    if (city -> getAttacker() == side) {
        return getAtk(true) < enemy() -> life &&
            enemy() -> getAtk(false) >= life;
    } else {
        return enemy() -> getAtk(true) >= life;
    }
}

void BaseUnit::initWeapon(int i) {
    weapon[i] = i == 2 ? atk / 5 : (i == 1 ? 1 : 3);
}

BaseUnit::BaseUnit(Game *game, int type, int side)
: game(game), type(type), side(side) {
    id = getHQ() -> getCount();
    life = game -> getLife(type);
    atk = game -> getAtk(type);
    city = game -> getHQCity(side);
    memset(weapon, 0, 3 * sizeof(int));
}

BaseUnit::~BaseUnit() {}

City *BaseUnit::getCity() {
    return city;
}

int BaseUnit::getCityId() {
    return game -> getCityId(city);
}

HQ *BaseUnit::getHQ() {
    return game -> getHQ(side);
}

bool BaseUnit::dead() {
    return this != NULL && life <= 0;
}

bool BaseUnit::inEnemyHQ() {
    return city == game -> getHQCity(side ^ 1);
}

void BaseUnit::afterBorn() {
    game -> printTime();
    printName();
    printf(" born\n");
}

void BaseUnit::beforeMarch() {
    killing = false;
}

void BaseUnit::march() {
    if (!inEnemyHQ()) city = city -> next(side);
    game -> printTime();
    printName();
    if (!inEnemyHQ()) {
        printf(" marched to city %d", getCityId());
    } else {
        printf(" reached %s headquarter", Teams[side ^ 1]);
    }
    printf(" with %d elements and force %d\n", life, atk);
}

void BaseUnit::afterMarch() {
    if (enemy() -> dead()) {
        int x = city -> getLife();
        getHQ() -> addLife(x);
        game -> printTime();
        printName();
        printf(" earned %d elements for his headquarter\n");
    }
}

void BaseUnit::shot() {
    BaseUnit *enemy = city -> next(side) -> unit[side ^ 1];
    if (weapon[0] > 0 && enemy) {
        --weapon[0];
        enemy -> hurt(this, game -> arrowAtk, false);
        game -> printTime();
        printName();
        printf(" shot");
        if (enemy -> dead()) {
            printf(" and killed ");
            enemy -> printName();
        }
        printf("\n");
    }
}

void BaseUnit::beforeBattle() {
    if (weapon[1] > 0 && decideBomb()) {
        life = enemy() -> life = 0;
        game -> printTime();
        printName();
        printf(" used a bomb and killed ");
        enemy() -> printName();
        printf("\n");
    }
}

void BaseUnit::attack(bool b) {
    if (enemy() -> dead()) return;

    game -> printTime();
    printName();
    printf(" %s ", b ? " attacked " : " fought back against ");
    enemy() -> printName();
    printf("in city %d", getCityId());
    if (b) printf(" with %d elements and force %d", life, atk);
    printf("\n");

    enemy() -> hurt(this, getAtk(b), b);
    weapon[2] = weapon[2] * 4 / 5;
    if (enemy() -> dead()) killing = true;
}

void BaseUnit::hurt(BaseUnit *enemy, int a, bool b) {
    life -= a;
    if (enemy == this -> enemy() && dead()) {
        game -> printTime();
        printName();
        printf(" was killed in city %d\n", getCityId());
    }
    if (!dead() && b) attack(false);
}

void BaseUnit::afterBattle() {
    if (!dead()) {
        BaseUnit::afterMarch();
        if (enemy() -> dead() && city -> win(side)) {
            game -> printTime();
            printf("%s flag raised in city %d\n", team(), getCityId());
        }
     }
}

void BaseUnit::report() {
    game -> printTime();
    printName();
    printf(" has ");
    bool flag = false;
    for (int i = 0; i < 3; ++i) {
        if (weapon[i] > 0) {
            printf("%s%s", flag ? "" : ",", Weapons[i]);
            flag = true;
        }
        if (i != 1) printf("(%d)", weapon[i]);
    }
    printf("%s\n", flag ? "" : "no weapon");
}

Dragon::Dragon(Game *game, int side)
: BaseUnit(game, 0, side) {
    morale = (double)getHQ() -> getLife() / (double) life;
    initWeapon(id % 3);
}

void Dragon::afterBorn() {
    BaseUnit::afterBorn();
    printf("Its morale is %.2lf\n", morale);
}

void Dragon::afterBattle() {
    if (!dead()) {
        morale += enemy() -> dead() ? 0.2 : -0.2;
        if (morale > 0.8 && city -> getAttacker() == side) {
            game -> printTime();
            printName();
            printf(" yelled in city %d\n", getCityId());
        }
    }
    BaseUnit::afterBattle();
}

Ninja::Ninja(Game *game, int side)
: BaseUnit(game, 1, side) {
    initWeapon(id % 3);
    initWeapon((id + 1) % 3);
}

void Ninja::hurt(BaseUnit *enemy, int a, bool b) {
    BaseUnit::hurt(enemy, a, false);
}

Iceman::Iceman(Game *game, int side)
:BaseUnit(game, 2, side), flag(false) {
    initWeapon(id % 3);
}

void Iceman::afterMarch() {
    if (flag) {
        life = life <= 9 ? 1 : life - 9;
        atk += 20;
    }
    flag = !flag;
    BaseUnit::afterMarch();
}

Lion::Lion(Game *game, int side)
: BaseUnit(game, 3, side) {
    loyalty = getHQ() -> getLife();
}

void Lion::afterBorn() {
    BaseUnit::afterBorn();
    printf("Its loyalty is %d\n", loyalty);
}

void Lion::beforeMarch() {
    BaseUnit::beforeMarch();
    if (loyalty <= 0) {
        life = -1;
        game -> printTime();
        printName();
        printf(" ran away\n");
    }
}

void Lion::beforeBattle() {
    BaseUnit::beforeBattle();
    lastLife = life;
}

void Lion::afterBattle() {
    if (enemy() -> killing) enemy() -> life += lastLife;
}

Wolf::Wolf(Game *game, int side): BaseUnit(game, 4, side) {}

void Wolf::afterBattle() {
    if (!dead() && enemy() -> dead()) {
        for (int i = 0; i < 3; ++i) {
            weapon[i] = weapon[i] ? weapon[i] : enemy() -> weapon[i];
        }
    }
}

int main() {
	fclose(stdin);
	fclose(stdout);
	return 0;
}
