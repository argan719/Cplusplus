/*
// 2번
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
	
	cout << "국어=" << Kim.kor_getter() << "점\n";
	cout << "영어=" << Kim.eng_getter() << "점\n";
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
	void dispK() { cout << "국어=" << kor << "점\n"; }
	void dispG() { cout << "학점=" << gd << endl; }
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
		cout << "국어=" << kor++ << "점\n"; 
	}
	void dispE()const { cout << "영어=" << eng << "점\n";}
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
// 16페이지 - 문제풀이
// 1번
#include<iostream>
#include<string>
using namespace std;
class Book {
public:
	string title;
	string name;

	void show()
	{   
		cout << "책제목 : " << title << endl;
		cout << "저자 : " << name << endl;
	}
};


void main()
{
	Book book;
	book.name = "Prodo";
	book.title = "C++ 프로그래밍";
	book.show();
}
*/


/*
// 2번
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
	cout << "가로 : ";
	cin >> w;
	r.set(w);
	cout << "넓이 : " << r.calcArea() << endl;
}
*/



/*
// 3번
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
		cout << "주사위를 던졌습니다 --> ";
		srand(time(NULL));
		d.roll();
		face=d.show();
		cout << face;
		dice[face - 1]++;
		cout << "\n계속? 멈추려면 q를 누르세요 ";
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

	cout << "가장 많이 나온 면은 " << max_face << endl;
}
*/


/*
// 4번
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

	cout << "이름 : ";
	cin >> name;
	cout << "전화번호 : ";
	cin >> tell;
	cout << "연봉 : ";
	cin >> salary;
	person.set(name, tell, salary);

	cout << "====================" << endl;
	cout << "이름    " << person.get_name() << endl;
	cout << "전화번호    " << person.get_tell() << endl;
	cout << "연봉    " << person.get_salary() << endl;
}
*/


/*
// 5번
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
	cout << "모델명 : ";
	cin >> model;
	cout << "제조회사 : ";
	cin >> company;
	cout << "색상 : ";
	cin >> color;
	cout << "전원 : ";
	cin >> battery;
	cout << "카메라장착여부 : ";
	cin >> camera;
	
	myPhone.set(model, company, color, battery, camera);
	cout << "전원을 켜시려면 1, 끄시려면 0을 입력하시오 : ";
	cin >> flag;
	myPhone.turn(flag);
	cout << "현재 myPhone의 전원은 " << myPhone.onoff() << " 입니다." << endl;

}
*/


/*
// 6번
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
	cout << "이름 입력 : ";
	cin >> name;
	cout << "국어점수입력 : ";
	cin >> kor;
	cout << "영어점수입력 : ";
	cin >> eng;
	cout << "수학점수입력 : ";
	cin >> math;

	s.set(name, kor, eng, math);
	cout << endl << endl;
	cout << "총점 = " << s.print_total() << endl;
	cout << "평균 = " << s.print_aver() << endl;
	cout << "학점 = " << s.print_grade() << endl;

}
*/




/*
// 7번
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
	cout << "자동차색상 : ";
	cin >> color;
	cout << "현재기어 : ";
	cin >> gear;
	cout << "현재속도 : ";
	cin >> speed;
	myCar.set(color, gear, speed);

	do {
		cout << "현재 " << myCar.print_gear() << "기어로 " << myCar.print_speed() << "의 속도로 주행중입니다.." << endl;
		cout << "어떤 옵션을 선택하시겠습니까? (1. 기어바꾸기  2. 감속하기  3. 가속하기  4.종료 )  :  ";
		cin >> num;
		switch (num) {
		case 1: { cout << "기어를 몇으로 변경하시겠습니까? : "; cin >> gear; myCar.change_gear(gear); 
			cout << "변경되었습니다" << endl; }; break;
		case 2: {myCar.speed_low(); cout << "감속되었습니다" << endl; } break;
		case 3: {myCar.speed_high(); cout << "가속되었습니다" << endl; } break;
		default: { num = 4; cout << "주행이 끝났습니다. 안녕히 돌아가십시오. " << endl; } break;
		}
	} while(num!=4);
}
*/



/*
// 8번
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
	cout << "= 초기값" << endl;
	cout << "채널 : " << tv.get_channel() << endl;
	cout << "볼륨 : " << tv.get_volume() << endl;

	for (;;)
	{
		cout << "1. 채널UP  2. 채널DOWN  3. 볼륨UP  4. 볼륨DOWN  5. 종료  : " << endl;
		cin >> a;
		if (a == 5) { cout << "종료되었습니다. \n"; break; }
		if (a == 1) {
			tv.set_channel(1); cout << "채널 UP" << endl;
		}
		else if(a == 2) {
			tv.set_channel(0);
			cout << "채널 DOWN " << endl;
		}
		else if (a == 3) {
			tv.set_volume(1);
			cout << "볼륨 UP" << endl;
		}
		else if (a == 4) {
			tv.set_volume(0);
			cout << "볼륨 DOWN " << endl;
		}
		cout << "채널 : " << tv.get_channel() << endl;
		cout << "볼륨 : " << tv.get_volume() << endl;
		cout << endl << endl;

	}
}
*/


/*
// 9페이지 11번
// === main.cpp
#include<iostream>
using namespace std;
#include "Circle.h"
int main()
{
	Circle donut;
	double area = donut.getarea();
	cout << "donut 면적은 ";
	cout << area << endl;
	Circle pizza;
	area = pizza.getarea();
	cout << "pizza 면적은";
	cout << area << endl;
}
*/

/*
// 12번
// === main.cpp
#include<iostream>
using namespace std;
#include "Circle.h"
#include "Circle.h"

int main()
{
	Cricle donut;
	double area = donut.getarea();
	cout << "donut 면적은";
	cout << area << endl;
	Circle pizza;
	area = pizza.getarea();
	cout << "pizza 면적은";
	cout << area << endl;
}

*/

/*
// 19페이지 10번
// === main.cpp
#include<iostream>
#include "Calculator.h"
using namespace std;

void main()
{
	Calculator c;
	int x, y;
	cout << "두 개의 정수를 입력하시오 : ";
	cin >> x >> y;
	cout << "합 = " << c.run(x, y) << endl;
}
*/

/*
// 11번 
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
	cout << "두 정수와 연산자를 입력하세요 : ";
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
// 14번
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
		cout << "상품 일련번호 : ";
		cin >> id;
		cin.get();
		cout << "상품 이름 : ";
		getline(cin, name);
		cout << "상품 가격 : ";
		cin >> price;
		if (i == 0) num1.input(id, name, price);
		else if (i == 1) num2.input(id, name, price);
	}
	if (num1.isCheaper(num2)) num1.print();
	else num2.print();
}

*/



/*
// 11페이지 13번
// hangman 게임
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
// 20페이지 12번
#include<iostream>
#include<cstring>
#include "Robot.h"
using namespace std;


int main()
{
	Robot a;  // 객체 생성
	a.init("태권브이", 100);	// 객체 초기화
	a.go();		// 전진
	a.turn();	// 회전
	a.jump();	// 점프
	a.back();	// 후진
	a.charge(50);		// 에너지 충전
	a.back();		// 후진
	return 0;
}
*/


/*
// 13번
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
	(car.get_speed() < speed) ? cout << "Car1이 이겼습니다!" << endl : cout << "Car2가 이겼습니다!" << endl;
}
void main()
{
	Car Car1, Car2;
	int gear;
	string color;
	cout << "=== Car1" << endl;
	cout << "속도 : " << Car1.get_speed() << endl;
	cout << "기어 : ";
	cin >> gear;
	Car1.set_gear(gear);
	cout << "색상 : ";
	cin >> color;
	Car1.set_color(color);
	cout << "\n\n=== Car2" << endl;
	cout << "속도 : " << Car2.get_speed() << endl;
	cout << "기어 : ";
	cin >> gear;
	Car2.set_gear(gear);
	cout << "색상 : ";
	cin >> color;
	Car2.set_color(color);

	cout << "\n=== 경주결과" << endl;
	Car1.compare_speed(Car2);

}
*/



/*
// 24페이지 16번
#include<iostream>
#include<string>
using namespace std;

class Fruit {
	string name;
	int money;		// 매입가격
	int num;		// 수량
	int sell_money;	// 판매단가
	int earn_money;	// 매출액

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
		if (num < n) cout << "재고가 부족합니다. 현재수량" << num << endl;
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
	cout << "과일 한 상자를 사옵니다." << endl;
	cout << "품목입력 : ";
	cin >> name;
	cout << "매입금액 : ";
	cin >> money;
	cout << "수량 : ";
	cin >> num;
	Fruit f(name, money, num);

	cout << "\n\n장사를 시작합니다." << endl;
	for (;;)
	{
		cout << "항목선택 [판매-1  반품-2  종료-3] : ";
		cin >> num;
		if (num == 3) break;
		else if (num == 1) {
			cout << "판매수량 : ";
			cin >> money;
			f.sell(money);
		}
		else if (num == 2) {
			cout << "반품수량 : ";
			cin >> money;
			f.resell(money);
		}
		cout << endl;
	}

	cout << "\n\n==영업결과==\n";
	cout << "품목 : " << f.get_name() << endl;
	cout << "남은수량 : " << f.get_num() << endl;
	cout << "매입가격 : " << f.get_price() << endl;
	cout << "매출액 : " << f.get_earn() << endl;
	cout << "순이익 : " << f.get_profit() << endl;
}
*/


