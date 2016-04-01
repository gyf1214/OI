//Created At: Fri Apr 1 13:10:09 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 30
using namespace std;

int inputNumber(void);
string inputString(void);

string strs[mm];
int n;

string copy() {
	int n = inputNumber();
	int x = inputNumber();
	int l = inputNumber();
	return strs[n].substr(x, l);
}

int stringToNumber(const string &s) {
	stringstream ss;
	ss << s;
	int x;
	char y;
	if (!(ss >> x)) return -1;
	if (ss >> y) return -1;
	return x;
}

string numberToString(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

string add() {
	string s1 = inputString();
	string s2 = inputString();
	int x1 = stringToNumber(s1), x2 = stringToNumber(s2);
	if (x1 >= 0 && x1 <= 99999 && x2 >= 0 && x2 <= 99999) {
		return numberToString(x1 + x2);
	} else return s1 + s2;
}

int find() {
	string s = inputString();
	int n = inputNumber();
	int ret = strs[n].find(s);
	return ret == string::npos ? strs[n].length() : ret;
}

int rfind() {
	string s = inputString();
	int n = inputNumber();
	int ret = strs[n].rfind(s);
	return ret == string::npos ? strs[n].length() : ret;
}

string inputString() {
	string x;
	cin >> x;
	if (x == "copy") return copy();
	if (x == "add") return add();
	return x;
}

int inputNumber() {
	string x;
	cin >> x;
	if (x == "find") return find();
	if (x == "rfind") return rfind();
	return stringToNumber(x);
}

void insert() {
	string s = inputString();
	int n = inputNumber();
	int x = inputNumber();
	strs[n].insert(x, s);
}

void reset() {
	string s = inputString();
	int n = inputNumber();
	strs[n] = s;
}

void print() {
	int n = inputNumber();
	cout << strs[n] << endl;
}

void printAll() {
	for (int i = 1; i <= n; ++i) {
		cout << strs[i] << endl;
	}
}

bool run() {
	string x;
	cin >> x;
	switch (x[0]) {
		case 'r':
		reset();
		break;
		case 'i':
		insert();
		break;
		case 'p':
		if (x.length() == 5) {
			print();
		} else {
			printAll();
		}
		break;
		default:
		return false;
	}
	return true;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> strs[i];
}

int main() {
	init();
	while (run());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
