//Created At: Sat Mar 5 15:33:49 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	char name[30];
	int age, id;
	int score[4];
	double avr;

	void input_num(int &x) {
		x = 0;
		for (char ch = getchar(); ch != ',' && ch != '\n'; ch = getchar()) {
			x = x * 10 + ch - '0';
		}
	}

	void input_name() {
		int i = 0;
		for (char ch = getchar(); ch != ',' && ch != '\n'; ch = getchar()) {
			name[i++] = ch;
		}
		name[i] = 0;
	}
public:
	void input(void) {
		input_name();
		input_num(age); input_num(id);
		for (int i = 0; i < 4; ++i) input_num(score[i]);
	}

	void calculate(void) {
		avr = 0;
		for (int i = 0; i < 4; ++i) avr += score[i];
		avr /= (double)4;
	}

	void output(void) {
		printf("%s,%d,%d,%lg\n", name, age, id, avr);
	}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
