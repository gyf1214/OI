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
class Dragon;
class Ninja;
class Iceman;
class Lion;
class Wolf;
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
    virtual int getAtk(bool);
    bool decideBomb(void);
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
    virtual void takeLife(void);
    virtual void shot(void);
    virtual void beforeBattle(void);
    virtual void attack(bool);
    virtual void hurt(BaseUnit *, int, bool);
    virtual void afterBattle(void);
    virtual void reward(void);
    virtual void report(void);

    friend class Lion;
    friend class Wolf;
};

class Dragon : public BaseUnit {
    double morale;
public:
    Dragon(Game *, int);
    void afterBorn(void);
    void afterBattle(void);
};

class Ninja : public BaseUnit {
public:
    Ninja(Game *, int);
    int getAtk(bool);
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
    virtual BaseUnit *create(Game *, int) = 0;
};

template <class T>
class Factory : public IFactory {
public:
    BaseUnit *create(Game *, int);
};

class City {
    Game *game;
    BaseUnit *lastUnit[2];
    BaseUnit *unit[2];
    int life, flag, lastWinner;
public:
    City(Game *);
    ~City(void);
    int getLife(void);
    BaseUnit *getUnit(int);
    BaseUnit *getAttacker(void);
    City *next(int);

    void clear(void);
    void beforeMarch(void);
    void march(void);
    void battle(void);
    bool win(int);

    friend class BaseUnit;
};

class HQ {
    Game *game;
    int life, currentUnit;
    int count, side;
public:
    BaseUnit *takingUnit;
    HQ(Game *, int, int);
    ~HQ(void);
    int reward(void);
    void addLife(int);
    int getLife(void);
    int getCount(void);
    void build(void);
    void report(void);
};

class Game {
    int hour, minute;
    int lifeHQ, cityCount, arrowAtk, lionDec, endTime;
    int life[Types], atk[Types];
    bool win;
    City *cities;
    HQ *hqs;
public:
    Game(void);
    void dispose(void);
    ~Game(void);
    HQ *getHQ(int);
    City *getCity(int);
    City *getHQCity(int);
    int getCityId(City *);
    int getLife(int);
    int getAtk(int);
    int getArrowAtk(void);
    int getLionDec(void);
    void printTime(void);
    void setWin(void);

    void initialize(void);
    void tick(void);
    void run(void);
    bool stop(void);
};

const char *BaseUnit::team() {
    return Teams[side];
}

const char *BaseUnit::name() {
    return Names[type];
}

void BaseUnit::printName() {
    printf("%s %s %d", team(), name(), id);
}

BaseUnit *BaseUnit::enemy() {
    return city -> unit[side ^ 1];
}

int BaseUnit::getAtk(bool b) {
    return b ? (atk + weapon[0]) : (atk / 2 + weapon[0]);
}

bool BaseUnit::decideBomb() {
    if (enemy() -> dead()) return false;
    if (city -> getAttacker() == this) {
        return getAtk(true) < enemy() -> life &&
            enemy() -> getAtk(false) >= life;
    } else {
        return enemy() -> getAtk(true) >= life;
    }
}

void BaseUnit::initWeapon(int i) {
    weapon[i] = (i == 0 ? atk / 5 : (i == 1 ? 1 : 3));
}

BaseUnit::BaseUnit(Game *game, int type, int side)
: game(game), type(type), side(side), killing(false) {
    id = getHQ() -> getCount();
    life = game -> getLife(type);
    atk = game -> getAtk(type);
    city = game -> getHQCity(side);
    city -> unit[side] = this;
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
    return this == NULL || life <= 0;
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
    if (inEnemyHQ()) return;
    city = city -> next(side);
}

void BaseUnit::afterMarch() {
    //if (city -> lastUnit[side] == this) return;
    game -> printTime();
    printName();
    if (!inEnemyHQ()) {
        printf(" marched to city %d", getCityId());
    } else {
        printf(" reached %s headquarter", Teams[side ^ 1]);
    }
    printf(" with %d elements and force %d\n", life, atk);
    if (inEnemyHQ() && getHQ() -> takingUnit) {
        game -> printTime();
        printf("%s headquarter was taken\n", Teams[side ^ 1]);
        game -> setWin();
    } else if (inEnemyHQ()) {
        city -> unit[side] = NULL;
        city = NULL;
        getHQ() -> takingUnit = this;
    }
}

void BaseUnit::takeLife() {
    if (enemy() -> dead()) {
        int x = city -> getLife();
        getHQ() -> addLife(x);
        game -> printTime();
        printName();
        printf(" earned %d elements for his headquarter\n", x);
    }
}

void BaseUnit::shot() {
    BaseUnit *enemy = city -> next(side) -> unit[side ^ 1];
    if (weapon[2] > 0 && enemy) {
        --weapon[2];
        enemy -> hurt(this, game -> getArrowAtk(), false);
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
    if (!dead() && weapon[1] > 0 && decideBomb()) {
        life = enemy() -> life = 0;
        game -> printTime();
        printName();
        printf(" used a bomb and killed ");
        enemy() -> printName();
        printf("\n");
    }
}

void BaseUnit::attack(bool b) {
    if (dead() || enemy() -> dead()) return;

    game -> printTime();
    printName();
    printf(" %s ", b ? "attacked" : "fought back against");
    enemy() -> printName();
    printf(" in city %d", getCityId());
    if (b) printf(" with %d elements and force %d", life, atk);
    printf("\n");

    enemy() -> hurt(this, getAtk(b), b);
    weapon[0] = weapon[0] * 4 / 5;
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
        BaseUnit::takeLife();
        if (enemy() -> dead()) {
            killing = true;
            if (city -> win(side)) {
                game -> printTime();
                printf("%s flag raised in city %d\n", team(), getCityId());
            }
        }
     }
}

void BaseUnit::reward() {
    if (killing) life += getHQ() -> reward();
}

void BaseUnit::report() {
    game -> printTime();
    printName();
    printf(" has ");
    bool flag = false;
    for (int i = 2; i >= 0; --i) {
        if (weapon[i] > 0) {
            printf("%s%s", flag ? "," : "", Weapons[i]);
            flag = true;
            if (i != 1) printf("(%d)", weapon[i]);
        }
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
        if (morale > 0.8 && city -> getAttacker() == this) {
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

int Ninja::getAtk(bool b) {
    return b ? (atk + weapon[0]) : 0;
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
    if (!inEnemyHQ() && loyalty <= 0) {
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
    if (lastLife > 0 && dead() && !enemy() -> dead()) {
		enemy() -> life += lastLife;
	}
    if (!enemy() -> dead()) loyalty -= game -> getLionDec();
    BaseUnit::afterBattle();
}

Wolf::Wolf(Game *game, int side): BaseUnit(game, 4, side) {}

void Wolf::afterBattle() {
    if (!dead() && enemy() -> dead()) {
        for (int i = 0; i < 3; ++i) {
            weapon[i] = weapon[i] ? weapon[i] : enemy() -> weapon[i];
        }
    }
    BaseUnit::afterBattle();
}

template <class T>
BaseUnit *Factory<T>::create(Game *game, int side) {
    return new T(game, side);
}

City::City(Game *game)
:game(game), life(0), flag(-1), lastWinner(-1) {
    unit[0] = unit[1] = NULL;
}

City::~City() {
    for (int i = 0; i < 2; ++i) {
        if (unit[i]) delete unit[i];
    }
}

int City::getLife() {
    int ret = life;
    life = 0;
    return ret;
}

BaseUnit *City::getUnit(int side) {
    return unit[side];
}

BaseUnit *City::getAttacker() {
    int side = (flag >= 0 ? flag : (game -> getCityId(this) + 1) % 2);
    return unit[side];
}

City *City::next(int side) {
    return this + (side ^ 1) * 2 - 1;
}

void City::clear() {
    for (int i = 0; i < 2; ++i) {
        if (unit[i] -> dead()) {
            delete unit[i];
            unit[i] = NULL;
        }
    }
}

void City::beforeMarch() {
    for (int i = 0; i < 2; ++i) {
        lastUnit[i] = unit[i];
        unit[i] = NULL;
    }
}

void City::march() {
    for (int i = 0; i < 2; ++i) {
        if (!lastUnit[i] -> dead() && lastUnit[i] -> getCity()) {
            lastUnit[i] -> march();
            lastUnit[i] -> getCity() -> unit[i] = lastUnit[i];
        }
        // } else if (!lastUnit[i] -> dead()) {
        //     unit[i] = lastUnit[i];
        // }
    }
    life += 10;
}

void City::battle() {
    if (unit[0] -> dead() && unit[1] -> dead()) return;
    if (!unit[0] || !unit[1]) return;

    unit[0] -> beforeBattle();
    unit[1] -> beforeBattle();
    getAttacker() -> attack(true);
    unit[0] -> afterBattle();
    unit[1] -> afterBattle();

    if (!unit[0] -> dead() && !unit[1] -> dead()) lastWinner = -1;
}

bool City::win(int side) {
    int x = lastWinner;
    lastWinner = side;
    bool ret = x == side && side != flag;
    if (ret) flag = side;
    return ret;
}

HQ::HQ(Game *game, int life, int side)
: game(game), life(life), side(side),
count(0), currentUnit(0), takingUnit(NULL) {}

HQ::~HQ() {
    if (takingUnit) delete takingUnit;
}

int HQ::reward() {
    if (life < 8) return 0;
    life -= 8;
    return 8;
}

void HQ::addLife(int x) {
    life += x;
}

int HQ::getLife() {
    return life;
}

int HQ::getCount() {
    return count;
}

void HQ::build() {
    static IFactory *factory[] = {
        new Factory<Dragon>(), new Factory<Ninja>(),
        new Factory<Iceman>(), new Factory<Lion>(),
        new Factory<Wolf>()
    };

    int type = List[side][currentUnit];
    if (game -> getLife(type) <= life) {
        life -= game -> getLife(type);
        currentUnit = (currentUnit + 1) % Types;
        ++count;
        BaseUnit *unit = factory[type] -> create(game, side);
        unit -> afterBorn();
    }
}

void HQ::report() {
    game -> printTime();
    printf("%d elements in %s headquarter\n", life, Teams[side]);
}

Game::Game() : cities(NULL), hqs(NULL) {}

void Game::dispose() {
    if (cities) {
        for (int i = 0; i < cityCount; ++i) (cities + i) -> ~City();
        free(cities);
        cities = NULL;
    }
    if (hqs) {
        for (int i = 0; i < 2; ++i) (hqs + i) -> ~HQ();
        free(hqs);
        cities = NULL;
    }
}

Game::~Game() {
    dispose();
}

HQ *Game::getHQ(int side) {
    return hqs + side;
}

City *Game::getCity(int id) {
    return cities + id;
}

City *Game::getHQCity(int side) {
    int id = side ? cityCount + 1 : 0;
    return cities + id;
}

int Game::getCityId(City *city) {
    return city - cities;
}

int Game::getLife(int type) {
    return life[type];
}

int Game::getAtk(int type) {
    return atk[type];
}

int Game::getArrowAtk() {
    return arrowAtk;
}

int Game::getLionDec() {
    return lionDec;
}

void Game::printTime() {
    printf("%03d:%02d ", hour, minute);
}

void Game::setWin() {
    win = true;
}

void Game::initialize() {
    dispose();
    scanf("%d%d%d%d%d", &lifeHQ, &cityCount, &arrowAtk, &lionDec, &endTime);
    for (int i = 0; i < Types; ++i) scanf("%d", &life[i]);
    for (int i = 0; i < Types; ++i) scanf("%d", &atk[i]);
    hqs = (HQ *)malloc(2 * sizeof(HQ));
    for (int i = 0; i < 2; ++i) new(hqs + i) HQ(this, lifeHQ, i);
    cities = (City *)malloc((2 + cityCount) * sizeof(City));
    for (int i = 0; i < cityCount + 2; ++i) new(cities + i) City(this);
    hour = minute = 0, win = false;
}

#define NN(x) if (x) x
#define repC(i) rep(i, 0, cityCount + 1)
#define repCM(i) rep(i, 1, cityCount)
#define vC(i) (cities + i)
#define vU(i, j) NN(cities[i].getUnit(j))
#define allCity repC(i) vC(i)
#define roadCity repCM(i) vC(i)
#define allUnit repC(i) rep(j, 0, 1) vU(i, j)
#define roadUnit repCM(i) rep(j, 0, 1) vU(i, j)
#define GG if (stop()) return

void Game::tick() {
    hqs[0].build();
    hqs[1].build();

    minute = 5;GG;
    allUnit -> beforeMarch();
    allCity -> clear();

    minute = 10;GG;
    allCity -> beforeMarch();
    allCity -> march();
    allUnit -> afterMarch();

    if (win) return;

    minute = 30;GG;
    roadUnit -> takeLife();

    minute = 35;GG;
    roadUnit -> shot();

    minute = 38;GG;
    roadUnit -> beforeBattle();

    minute = 40;GG;
    roadCity -> battle();
    roadCity -> clear();

    for (int i = cityCount; i >= 1; --i) {
        vU(i, 0) -> reward();
    }

    repCM(i) vU(i, 1) -> reward();

    minute = 50;GG;
    hqs[0].report();
    hqs[1].report();

    minute = 55;GG;
    repC(i) vU(i, 0) -> report();
    NN(hqs[0].takingUnit) -> report();
    NN(hqs[1].takingUnit) -> report();
    repC(i) vU(i, 1) -> report();

    ++hour;
    minute = 0;
}

void Game::run() {
    while (!stop()) tick();
}

bool Game::stop() {
    return win || hour * 60 + minute > endTime;
}

Game game;

int main() {
    int t;
    scanf("%d", &t);
    rep(i, 1, t) {
        printf("Case %d:\n", i);
        game.initialize();
        game.run();
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
