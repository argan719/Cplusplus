/*
// 2��
#include<iostream>
using namespace std;
class Score {
private:
	int kor;
	int eng;
public:
	void setter(int k, int e) {
		kor = k;
		eng = e;
	}
	int kor_getter() {
		return kor;
	}
	int eng_getter() {
		return eng;
	}
};

int main()
{
	class Score Kim;
	Kim.setter(80, 90);
	
	cout << "����=" << Kim.kor_getter() << "��\n";
	cout << "����=" << Kim.eng_getter() << "��\n";
}
*/

/*
#include<iostream>
using namespace std;
class Score {
	int kor;
	char gd;
public:
	void set(int a) { kor = a; }
	void set(char b) { gd = b; }
	void set(int c, char d) {
		set(c);
		set(d);
	}
	void dispK() { cout << "����=" << kor << "��\n"; }
	void dispG() { cout << "����=" << gd << endl; }
	void dispKG() { dispK();  dispG(); }
};


int main()
{
	Score Kim;
	Kim.set(80);
	Kim.set('B');
	Kim.dispKG();
}
*/


/*
#include<iostream>
using namespace std;
class Score {
	int kor;
	int eng;
public:
	void setK(int a = 0) { kor = a; }
	void setE(int b = 0) { eng = b; }
	void setKE(int c = 0, int d = 0) {
		setK(c);
		setE(d);
	}
	void dispK()const {
		eng = 100;
		cout << "����=" << kor++ << "��\n"; 
	}
	void dispE()const { cout << "����=" << eng << "��\n";}
	void dispKE() const {
		dispK();
		dispE();
	}
};


int main()
{
	//const int a = 10;
	//a++;
	Score Kim;
	Kim.setKE(80);
	Kim.dispKE();
}
*/






/*
// 16������ - ����Ǯ��
// 1��
#include<iostream>
#include<string>
using namespace std;
class Book {
public:
	string title;
	string name;

	void show()
	{   
		cout << "å���� : " << title << endl;
		cout << "���� : " << name << endl;
	}
};


void main()
{
	Book book;
	book.name = "Prodo";
	book.title = "C++ ���α׷���";
	book.show();
}
*/


/*
// 2��
#include<iostream>
using namespace std;

class Rectangle {
	int width;
	int length;
public:
	void set(int w)
	{
		width = w;
	}
	int calcArea() {
		length = width * width;
		return length;
	}
};

void main()
{
	Rectangle r;
	int w;
	cout << "���� : ";
	cin >> w;
	r.set(w);
	cout << "���� : " << r.calcArea() << endl;
}
*/



/*
// 3��
#include<iostream>
#include<time.h>
using namespace std;
class Dice {
	int face;
public:
	void roll() { face = (int)(rand() % 6 + 1); }
	int show() { return face; }
};

void main()
{
	Dice d;
	int dice[6] = { 0, };
	int face;
	char a;
	for (;;) {
		cout << "�ֻ����� �������ϴ� --> ";
		srand(time(NULL));
		d.roll();
		face=d.show();
		cout << face;
		dice[face - 1]++;
		cout << "\n���? ���߷��� q�� �������� ";
		cin >> a;
		if (a == 'q') break;
	}
	int max = dice[0];
	int max_face;
	for (int i = 0; i < 6; i++)
		if (max <= dice[i]) {
			max = dice[i];
			max_face = i + 1;
		}

	cout << "���� ���� ���� ���� " << max_face << endl;
}
*/


/*
// 4��
#include<iostream>
#include<string>
using namespace std;
class Employee {
	string name;
	string tell;
	int salary;

public:
	void set(string n, string t, int s)
	{
		name = n;
		tell = t;
		salary = s;
	}
	string get_name()
	{
		return name;
	}
	string get_tell()
	{
		return tell;
	}
	int get_salary()
	{
		return salary;
	}
};

void main()
{
	Employee person;
	string name, tell;
	int salary;

	cout << "�̸� : ";
	cin >> name;
	cout << "��ȭ��ȣ : ";
	cin >> tell;
	cout << "���� : ";
	cin >> salary;
	person.set(name, tell, salary);

	cout << "====================" << endl;
	cout << "�̸�    " << person.get_name() << endl;
	cout << "��ȭ��ȣ    " << person.get_tell() << endl;
	cout << "����    " << person.get_salary() << endl;
}
*/


/*
// 5��
#include<iostream>
#include<string>
using namespace std;
class CellPhone {
	string model;
	string company;
	string color;
	string battery;
	string camera;

	void set_model(string str)
	{
		model = str;
	}
	void set_company(string str)
	{
		company = str;
	}
	void set_color(string str)
	{
		color = str;
	}
	void set_battery(string str)
	{
		battery = str;
	}
	void set_camera(string str)
	{
		camera = str;
	}
public:
	void set(string m, string c, string c2, string b, string c3)
	{
		set_model(m);
		set_company(c);
		set_color(c2);
		set_battery(b);
		set_battery(c3);
	}
	void turn(int flag)
	{
		if (flag == 1) set_battery("On");
		else set_battery("Off");
	}
	string onoff()
	{
		return battery;
	}
};

void main()
{
	CellPhone myPhone;
	string model, company, color, battery, camera;
	int flag;
	cout << "�𵨸� : ";
	cin >> model;
	cout << "����ȸ�� : ";
	cin >> company;
	cout << "���� : ";
	cin >> color;
	cout << "���� : ";
	cin >> battery;
	cout << "ī�޶��������� : ";
	cin >> camera;
	
	myPhone.set(model, company, color, battery, camera);
	cout << "������ �ѽ÷��� 1, ���÷��� 0�� �Է��Ͻÿ� : ";
	cin >> flag;
	myPhone.turn(flag);
	cout << "���� myPhone�� ������ " << myPhone.onoff() << " �Դϴ�." << endl;

}
*/


/*
// 6��
#include<iostream>
#include<string>
using namespace std;
class Student {
	string name;
	int kor;
	int eng;
	int math;
	void set_name(string str) {
		name = str;
	}
	void set_kor(int k)
	{
		kor = k;
	}
	void set_eng(int e)
	{
		eng = e;
	}
	void set_math(int m)
	{
		math = m;
	}
	
public:
	void set(string str, int k, int e, int m) {
		set_name(str);
		set_kor(k);
		set_eng(e);
		set_math(m);
	}
	int print_total()
	{
		return kor + eng + math;
	}
	int print_aver()
	{
		return (print_total() / 3);
	}
	char print_grade()
	{
		int aver = print_aver();
		switch (aver/10) {
		case 9: return 'A'; break;
		case 8: return 'B'; break;
		case 7: return 'C'; break;
		default: return 'F'; break;
		}
	}
};

void main()
{
	Student s;
	string name;
	int kor, eng, math;
	cout << "�̸� �Է� : ";
	cin >> name;
	cout << "���������Է� : ";
	cin >> kor;
	cout << "���������Է� : ";
	cin >> eng;
	cout << "���������Է� : ";
	cin >> math;

	s.set(name, kor, eng, math);
	cout << endl << endl;
	cout << "���� = " << s.print_total() << endl;
	cout << "��� = " << s.print_aver() << endl;
	cout << "���� = " << s.print_grade() << endl;

}
*/




/*
// 7��
#include<iostream>
#include<string>
using namespace std;
class Car {
	string color;
	int gear;
	int speed;
public:
	void change_gear(int g) {
		gear = g;
	}
	void speed_low() {
		speed--;
	}
	void speed_high() {
		speed++;
	}
	int print_gear() {
		return gear;
	}
	int print_speed() {
		return speed;
	}
	void set(string c, int g, int s) {
		color = c;
		gear = g;
		speed = s;
	}
};

void main()
{
	Car myCar;
	string color;
	int gear;
	int speed;
	int num;
	cout << "�ڵ������� : ";
	cin >> color;
	cout << "������ : ";
	cin >> gear;
	cout << "����ӵ� : ";
	cin >> speed;
	myCar.set(color, gear, speed);

	do {
		cout << "���� " << myCar.print_gear() << "���� " << myCar.print_speed() << "�� �ӵ��� �������Դϴ�.." << endl;
		cout << "� �ɼ��� �����Ͻðڽ��ϱ�? (1. ���ٲٱ�  2. �����ϱ�  3. �����ϱ�  4.���� )  :  ";
		cin >> num;
		switch (num) {
		case 1: { cout << "�� ������ �����Ͻðڽ��ϱ�? : "; cin >> gear; myCar.change_gear(gear); 
			cout << "����Ǿ����ϴ�" << endl; }; break;
		case 2: {myCar.speed_low(); cout << "���ӵǾ����ϴ�" << endl; } break;
		case 3: {myCar.speed_high(); cout << "���ӵǾ����ϴ�" << endl; } break;
		default: { num = 4; cout << "������ �������ϴ�. �ȳ��� ���ư��ʽÿ�. " << endl; } break;
		}
	} while(num!=4);
}
*/



/*
// 8��
#include<iostream>
using namespace std;
class MyTv2 {
	string isPowerOn;
	int channel;
	int volume;
public:
	void set_default()
	{
		channel = 10;
		volume = 20;
	}
	void set_channel(int flag)
	{
		if (flag == 1) channel++;
		else channel--;
	}
	void set_volume(int flag) {
		if (flag == 1) volume++;
		else volume--;
	}
	string get_power()
	{
		return isPowerOn;
	}
	int get_channel()
	{
		return channel;
	}
	int get_volume()
	{
		return volume;
	}
};

void main()
{
	MyTv2 tv;
	int a;
	tv.set_default();
	cout << "= �ʱⰪ" << endl;
	cout << "ä�� : " << tv.get_channel() << endl;
	cout << "���� : " << tv.get_volume() << endl;

	for (;;)
	{
		cout << "1. ä��UP  2. ä��DOWN  3. ����UP  4. ����DOWN  5. ����  : " << endl;
		cin >> a;
		if (a == 5) { cout << "����Ǿ����ϴ�. \n"; break; }
		if (a == 1) {
			tv.set_channel(1); cout << "ä�� UP" << endl;
		}
		else if(a == 2) {
			tv.set_channel(0);
			cout << "ä�� DOWN " << endl;
		}
		else if (a == 3) {
			tv.set_volume(1);
			cout << "���� UP" << endl;
		}
		else if (a == 4) {
			tv.set_volume(0);
			cout << "���� DOWN " << endl;
		}
		cout << "ä�� : " << tv.get_channel() << endl;
		cout << "���� : " << tv.get_volume() << endl;
		cout << endl << endl;

	}
}
*/


/*
// 9������ 11��
// === main.cpp
#include<iostream>
using namespace std;
#include "Circle.h"
int main()
{
	Circle donut;
	double area = donut.getarea();
	cout << "donut ������ ";
	cout << area << endl;
	Circle pizza;
	area = pizza.getarea();
	cout << "pizza ������";
	cout << area << endl;
}
*/

/*
// 12��
// === main.cpp
#include<iostream>
using namespace std;
#include "Circle.h"
#include "Circle.h"

int main()
{
	Cricle donut;
	double area = donut.getarea();
	cout << "donut ������";
	cout << area << endl;
	Circle pizza;
	area = pizza.getarea();
	cout << "pizza ������";
	cout << area << endl;
}

*/

/*
// 19������ 10��
// === main.cpp
#include<iostream>
#include "Calculator.h"
using namespace std;

void main()
{
	Calculator c;
	int x, y;
	cout << "�� ���� ������ �Է��Ͻÿ� : ";
	cin >> x >> y;
	cout << "�� = " << c.run(x, y) << endl;
}
*/

/*
// 11�� 
// === main.cpp
#include<iostream>
#include "Calculator.h"
using namespace std;
void main()
{
	Calculator c;
	char quest[20];
	char first[10];
	char second[10];
	char op;
	cout << "�� ������ �����ڸ� �Է��ϼ��� : ";
	cin.getline(quest, 20);
	int x, y;
	int flag = 1;
	int fk;
	for (int k=0, i = 0;; i++,k++)
	{
		if (flag == 1) {
			if (quest[i] == 32) first[k] = NULL;
			else first[k] = quest[i];
		}
		else if (flag == 2) {
			if(quest[i]!=32) second[k] = quest[i];
		}
		else if (flag == 3) {
			if (k == 0) second[fk] = NULL;
			if (quest[i] == NULL) break;
			else op = quest[i];
		}

		if (quest[i] == 32) {
			flag++;
			fk = k+1;
			k = -1;
		}
	}
	c.set(atoi(first), atoi(second), op);
	cout << endl << c.process() << endl;

}
*/


/*
// 14��
#include<iostream>
#include "Product.h"

using namespace std;
void main()
{
	int id;
	string name;
	int price;
	Product num1, num2;
	for (int i = 0; i < 2; i++)
	{
		cout << "��ǰ �Ϸù�ȣ : ";
		cin >> id;
		cin.get();
		cout << "��ǰ �̸� : ";
		getline(cin, name);
		cout << "��ǰ ���� : ";
		cin >> price;
		if (i == 0) num1.input(id, name, price);
		else if (i == 1) num2.input(id, name, price);
	}
	if (num1.isCheaper(num2)) num1.print();
	else num2.print();
}

*/



/*
// 11������ 13��
// hangman ����
// === main.cpp
#include "Hangman.h"
void main()
{
	string arr[] = { "cat", "dlephant", "wolf" , "rabbit","lion","pig","tiger" };
	srand(time(NULL));
	int rnd = rand() % (arr->length() - 1);
	Hangman game;
	game.play(arr[rnd]);
}
*/



/*
// 20������ 12��
#include<iostream>
#include<cstring>
#include "Robot.h"
using namespace std;


int main()
{
	Robot a;  // ��ü ����
	a.init("�±Ǻ���", 100);	// ��ü �ʱ�ȭ
	a.go();		// ����
	a.turn();	// ȸ��
	a.jump();	// ����
	a.back();	// ����
	a.charge(50);		// ������ ����
	a.back();		// ����
	return 0;
}
*/


/*
// 13��
#include<iostream>
#include<time.h>
#include<string>
using namespace std;

class Car {
private:
	int speed;
	int gear;
	string color;
public:
	void set_speed();
	void set_gear(int g);
	void set_color(string c);
	int get_speed();
	void compare_speed(Car car);
};

int Car::get_speed() {
	set_speed();
	return speed;
}

void Car::set_speed() {
	srand(time(NULL));
	speed = rand() % 199;
}
void Car::set_gear(int g)
{
	gear = g;
}
void Car::set_color(string c) {
	color = c;
}
void Car::compare_speed(Car car)
{
	(car.get_speed() < speed) ? cout << "Car1�� �̰���ϴ�!" << endl : cout << "Car2�� �̰���ϴ�!" << endl;
}
void main()
{
	Car Car1, Car2;
	int gear;
	string color;
	cout << "=== Car1" << endl;
	cout << "�ӵ� : " << Car1.get_speed() << endl;
	cout << "��� : ";
	cin >> gear;
	Car1.set_gear(gear);
	cout << "���� : ";
	cin >> color;
	Car1.set_color(color);
	cout << "\n\n=== Car2" << endl;
	cout << "�ӵ� : " << Car2.get_speed() << endl;
	cout << "��� : ";
	cin >> gear;
	Car2.set_gear(gear);
	cout << "���� : ";
	cin >> color;
	Car2.set_color(color);

	cout << "\n=== ���ְ��" << endl;
	Car1.compare_speed(Car2);

}
*/



/*
// 24������ 16��
#include<iostream>
#include<string>
using namespace std;

class Fruit {
	string name;
	int money;		// ���԰���
	int num;		// ����
	int sell_money;	// �ǸŴܰ�
	int earn_money;	// �����

	void set_sellmoney() {
		int n = money;
		n += n * 0.4;
		sell_money = n / num;
	}
public:
	Fruit(string a, int m, int n) {
		name = a;
		money = m;
		num = n;
		earn_money = 0;
		set_sellmoney();
	}
	void sell(int n){
		if (num < n) cout << "��� �����մϴ�. �������" << num << endl;
		else {
			num -= n; 
			earn_money += n * sell_money;
		}
	}
	void resell(int n) {
		num += n;
		earn_money -= n * sell_money;
	}
	string get_name() {
		return name;
	}
	int get_num() {
		return num;
	}
	int get_price() {
		return money;
	}
	int get_earn() {
		return earn_money;
	}
	int get_profit() {
		return (earn_money - money);
	}

};

void main()
{
	string name;
	int money;
	int num;
	cout << "���� �� ���ڸ� ��ɴϴ�." << endl;
	cout << "ǰ���Է� : ";
	cin >> name;
	cout << "���Աݾ� : ";
	cin >> money;
	cout << "���� : ";
	cin >> num;
	Fruit f(name, money, num);

	cout << "\n\n��縦 �����մϴ�." << endl;
	for (;;)
	{
		cout << "�׸��� [�Ǹ�-1  ��ǰ-2  ����-3] : ";
		cin >> num;
		if (num == 3) break;
		else if (num == 1) {
			cout << "�Ǹż��� : ";
			cin >> money;
			f.sell(money);
		}
		else if (num == 2) {
			cout << "��ǰ���� : ";
			cin >> money;
			f.resell(money);
		}
		cout << endl;
	}

	cout << "\n\n==�������==\n";
	cout << "ǰ�� : " << f.get_name() << endl;
	cout << "�������� : " << f.get_num() << endl;
	cout << "���԰��� : " << f.get_price() << endl;
	cout << "����� : " << f.get_earn() << endl;
	cout << "������ : " << f.get_profit() << endl;
}
*/


