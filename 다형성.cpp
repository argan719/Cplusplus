/*
// 1번
#include<iostream>
using namespace std;
class Shape {
protected:
	int x, y;
public:
	void draw() {
		cout << "Shape Draw" << endl;
	}
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
class Rectangle : public Shape {
private:
	int width, height;
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}
	void draw() {
		cout << "Rectangle Draw" << endl;
	}
};
class Circle : public Shape {
private:
	int radius;
public:
	void setRadius(int r) {
		radius = r;
	}
	void draw() {
		cout << "Circle Draw" << endl;
	}
};
int main()
{
	Shape *ps = new Rectangle();		// 상향형변환
	ps->setOrigin(10, 10);
	ps->draw();
	((Rectangle*)ps)->setWidth(100);   // 하향형변환
	((Rectangle*)ps)->draw();
	ps->draw();

	delete ps;
}
*/

/*
// 2번 - 1
#include<iostream>
using namespace std;

class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	void f(){ cout << "Derived::f() called" << endl; }
};

int main()
{
	Derived d, *pDer;
	pDer = &d;
	pDer->f();

	Base *pBase;
	pBase = pDer;
	pBase->f();
}
*/

/*
// 2번-2
#include<iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; }
};
int main()
{
	Derived d, *pDer;
	pDer = &d;
	pDer->f();

	Base * pBase;
	pBase = pDer;
	pBase->f();
}
*/

/*
// 3번
#include<iostream>
using namespace std;

class AA {
protected: int a;
public:
	AA(int a1 = 0) { a = a1; }
	~AA() {}
	void dispA() { cout << "a=" << a << endl; }
	virtual void disp()  = 0;  // 순수가상함수
	void show() {
		dispA();
		disp();
	}
};

class BB : public AA {
	int b;
public:
	BB(int a1 = 1, int b1 = 2) : AA(a1) { b = b1; }
	~BB() {}
	void dispb() { cout << "b=" << b << endl; }
	virtual void disp() { cout << "b=" << b << endl; }
};

int main()
{
	BB B(10, 20);
	B.show();
}
*/


/*
// 4번
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
public:
	GrandFather(int a) { len = a; }
	void setLen(int a) { len = a; }
	void disp() { cout << "길이=" << len << endl; }
};
class Father : public GrandFather
{
protected:
	int headlight;
public:
	Father(int a = 0, int b = 0) : GrandFather(a), headlight(b) {}
	void setLight(int a) { headlight = a; }
	void disp() { cout << "헤드 라이트=" << headlight << "개\n"; }
	void dispGF() {
		GrandFather::disp();
		Father::disp();
	}
};
int main()
{
	Father Cycle(250, 2);
	Cycle.GrandFather::disp();
	Cycle.dispGF();
	Cycle.disp();
}
*/

/*
// 5번
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
public:
	GrandFather(int a) { len = a; }
	void setLen(int a) { len = a; }
	void disp() { cout << "길이=" << len << endl; }
};
class Father :public GrandFather {
protected:
	int headlight;
public:
	Father(int a = 0, int b = 0) : GrandFather(a), headlight(b) {}
	void setLight(int a) { headlight = a; }
	void disp() { cout << "헤드 라이트=" << headlight << "개\n"; }
	void dispGF() {
		GrandFather::disp();
		Father::disp();
	}
};
int main()
{
	Father Cycle(250, 2);
	Cycle.GrandFather::disp();
	Cycle.dispGF();
	Cycle.disp();
}
*/

/*

// 6번
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
public:
	GrandFather(int a) { len = a; }
	void setLen(int a) { len = a; }
	void disp() { cout << "길이=" << len << endl; }
};
class Father : public GrandFather {
protected: 
	int headlight;
public:
	Father(int a = 0, int b = 0) : GrandFather(a), headlight(b) {}
	void set(int a) {
		headlight = a;
	}
	void set(int a, int b) {
		GrandFather::set(a);
		set(b);
	}
	void dispLight() {
		cout << "헤드 라이트=" << headlight << "개\n";
	}
	void dispGF() {
		dispLen();
		dispLight();
	}
};

int main()
{
	Father Cycle(250, 2);
	Cycle.dispGF();
	Cycle.GrandFather::setLen(150);
	Cycle.set(1);
	Cycle.dispGF();
}
*/

/*
// 7번
#include<iostream>
using namespace std;
class AA {
public:
	virtual void draw() {}
};
class circle : public AA {
public:
	void draw() {
		cout << "원을 그립니다~" << endl;
	}
};
class rect : public AA {
public:
	void draw() {
		cout << "사각형을 그립니다~" << endl;
	}
};
class line : public AA {
public:
	void draw() {
		cout << "직선을 그립니다~" << endl;
	}
};

void paint(AA *p) {
	p->draw();
}

int main()
{
	circle k1;
	k1.draw();
	rect k2;
	k2.draw();
	line k3;
	k3.draw();

	paint(new circle());
	paint(new rect());
	paint(new line());
}
*/

/*
// 9번
// === main.cpp
#include<iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

int main() {
	Shape *pStart = NULL;
	Shape *pLast;

	pStart = new Circle();
	pLast = pStart;

	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Circle());
	pLast = pLast->add(new Line());
	pLast = pLast->add(new Rect());

	Shape* p = pStart;
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}

	p = pStart;
	while (p != NULL) {
		Shape * q = p->getNext();
		delete p;
		p = q;
	}
}
*/


/*
// 12페이지 - 문제풀이
// 1번
#include<iostream>
using namespace std;

class Converter {
	double ratio;
public:
	virtual double convert(double src) = 0;		// 원을 달러로 변환한다.
};

class WonToDoller : public Converter {
	int ratio;
	int won;
public:
	WonToDoller(int r) : ratio(r) {}
	double convert(double src) {
		cout << "변환결과 : " << won * src << " 달러" << endl;
		return 0;
	}
	void run() {
		cout << "원을 달러로 바꿉니다. 원을 입력하세요 : ";
		cin >> won;
		Converter *c = this;
		c->convert(9.9/won);
	}
};

int main()
{
	WonToDoller wd(1010);  // 1달러에 1010원
	wd.run();
}
*/

/*
//2번
#include<iostream>
#include<string>

using namespace std;

class Product {
protected:
	string name;
	double price;
public:
	Product() {}
	Product(string n, double p) : name(n), price(p) {}
	virtual double getPrice() {
		return  price;
	}
	void print() {
		cout << "상품명 : " << name << endl;
		cout << "가  격 : " << price << endl;
	}
};
class DiscountProduct : public Product {
private:
	double discount;
public:
	DiscountProduct(string n, double p, double d) { name = n;  price = p; discount = d; }
	double getPrice() {
		price -= price * (discount / 100);
		return price;
	}
};

int main(void) {
	Product *p1 = new Product("toothbrush", 3000);
	Product *p2 = new DiscountProduct("toothbrush", 3000, 15);

	cout << p1->getPrice() << endl;
	cout << p2->getPrice() << endl;
}
*/

/*
// 3번
#include<iostream>
using namespace std;

class BankAcct {
private:
	double money;
	double rate;
	double interest;
public:
	BankAcct() {}
	BankAcct(double m, double r) : money(m), rate(r) {}
	void deposit(double m) {
		money += m;
	}
	void withdraw(double m) {
		if (money < m) cout << "잔액이 부족합니다\n";
		else money -= m;
	}
	virtual double getInterest() = 0;
	double get_money() {
		return money;
	}
	double get_ratio() {
		return rate;
	}
};

class SavingAcct: public BankAcct {
public:
	SavingAcct(double m):  BankAcct(m,0.09){ }
	double getInterest() {
		return (get_money() * get_ratio());
	}
	void print() {
		cout << "--- 저축예금 계좌\n";
		cout << "예금액 : " << (int)get_money() << endl;
	}
};
class CheckingAcct : public BankAcct {
public:
	CheckingAcct(double m) : BankAcct(m, 0.05) {}
	double getInterest() {
		return (get_money() * get_ratio());
	}
	void print() {
		cout << "--- 당좌예금 계좌\n";
		cout << "예금액 : " << (int)get_money() << endl;
	}
};

int main()
{
	SavingAcct sa(1000000);
	CheckingAcct ca(1000000);
	sa.deposit(800000);
	ca.deposit(5500000);
	sa.withdraw(300000);
	ca.withdraw(1500000);
	sa.print();
	cout << "이자액 : " << sa.getInterest() << endl;
	ca.print();
	cout << "이자액 : " << ca.getInterest() << endl;
	
	return 0;
}
*/


/*
// 4번
#include<iostream>
#include<string>
using namespace std;

class HomeAppliance {
	double price;
	string model;
	string maker;
public:
	HomeAppliance(double p, string mo, string ma) : price(p), model(mo), maker(ma) {}
	void print() {
		cout << "가격 : " << (int)price << endl;
		cout << "모델명 : " << model << endl;
		cout << "메이커 : " << maker << endl;
	}
	virtual void tiele() {

	}

};

class Television : public HomeAppliance {
public:
	Television(double p, string m, string make) : HomeAppliance(p, m, make) {}
	void print() {
		cout << "\tTelevision\t\n";
		cout << "========================\n";
		HomeAppliance::print();
		cout << "========================\n";
	}
};
class Refrigerator : public HomeAppliance {
public:
	Refrigerator(double p, string m, string make) : HomeAppliance(p, m, make) {}
	void print() {
		cout << "\tRefrigerator\t\n";
		cout << "========================\n";
		HomeAppliance::print();
		cout << "========================\n";
	}

};

int main()
{
	Television t1(1500000, "72LEX9", "LG");
	Television t2(2000000, "LN57F91BD", "SAMSUNG");
	Refrigerator r1(950000, "SRT746ZWKPZ", "SAMSUNG");
	Refrigerator r2(850000, "R-T758LHHSI", "LG");
	t1.print();
	t2.print();
	r1.print();
	r2.print();
	return 0;
}
*/

/*
// 5번
#include<iostream>
#include<string>
using namespace std;
class LoopAdder {  // 추상 클래스
	string name;  // 루프의 이름
	int x, y, sum;
	void read();  // x,y 값을 읽어 들이는 함수
	void write();  // sum을 출력하는 함수
protected:
	LoopAdder(string name = "") {  // 루프의 이름을 받는다. 초깃값은 ""
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;  // 순수 가상 함수. 루프를 돌면서 합을 구하는 함수
public:
	void run();  // 연산을 진행하는 함수
};
void LoopAdder::read() {   // x,y입력
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write() {  // 결과 sum 출력
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}
void LoopAdder::run() {
	read();  // x,y를 읽는다.
	sum = calculate();  // 루프돌면서 계산한다
	write(); // 결과 sum을 출력한다.
}



class ForLoopAdder : public LoopAdder{
public:
	ForLoopAdder(string n) : LoopAdder(n) {}
	int calculate() {
		int sum = 0;
		for (int i = getX(); i <= getY(); i++)
			sum += i;
		return sum;
	}
};

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}
*/

/*
// 6번
#include<iostream>
#include<string>
using namespace std;

class Shape {
protected:
	string name;		// 도형의 이름
	int width, height;		// 도형에 내접하는 사각형의 너비와 높이
public:
	Shape(string n = "", int w = 0, int h = 0) {
		name = n;
		width = w;
		height = h;
	}
	virtual double getArea() { return 0; }
	string getName() { return name; }
};

class Oval : public Shape {
public:
	Oval(string n, int w, int h) : Shape(n, w, h) {}
	double getArea() {
		cout << getName() << " 넓이는 " << width * width*3.14 << endl;
		return 0;
	}
};

class Rect : public Shape {
public:
	Rect(string n, int w, int h) : Shape(n, w, h) {}
	double getArea() {
		cout << getName() << " 넓이는 " << width * height << endl;
		return 0;
	}
};

class Tria : public Shape {
public: 
	Tria(string n, int w, int h) : Shape(n, w, h) {}
	double getArea() {
		cout << getName() << " 넓이는 " << width *height*0.5 << endl;
		return 0;
	}
};

int main()
{
	Oval circle("빈대떡", 5, 10);
	Rect rectangle("찰떡", 4, 8);
	Tria triangle("토스트", 11, 15);
	circle.getArea();
	rectangle.getArea();
	triangle.getArea();
}
*/





/*
// 7번 
#include<iostream>
#include<string>
using namespace std;

class Shape {
protected:
	string name;		// 도형의 이름
	int width, height;		// 도형에 내접하는 사각형의 너비와 높이
	int x, y;  // 시작점
	int mx, my;  // 이동점
public:
	Shape(string n = "", int w = 0, int h = 0) {
		name = n;
		width = w;
		height = h;
	}
	virtual double getArea() { return 0; }
	virtual void draw() {}	// 출력함수
	void move(int addx, int addy) {
		x = x + addx;
		y = y + addy;
	}  // 도형의 기준점 이동
	string getName() { return name; }
};


class Rectangle : public Shape {
public:
	void draw() {
		cout << "Rectangle Draw\n" << "시작점 : ";
		cin >> x >> y; 
		cout << "이동점 : ";
		cin >> mx >> my;
		move(mx, my);
		cout << "면적 : " << getArea();
		cout << "\n시작점 : ( " << x << ", " << y << " )\n";
	}
	double getArea() {
		return mx * my;
	}
};

class Circle : public Shape {
public:
	void draw() {
		cout << "\nCircle Draw\n"<<"시작점 : ";
		cin >> x >> y;
		cout << "이동점 : ";
		cin >> mx >> my;
		move(mx, my);
		cout << "면적 : " << getArea();
		cout << "\n시작점 : ( " << x << ", " << y << " )\n";
	}
	double getArea() {
		return 2 * 3.14 * mx;
	}
};

class Triangle : public Shape {
public:
	void draw() {
		cout << "\nTriangle Draw\n" << "시작점 : ";
		cin >> x >> y;
		cout << "이동점 : ";
		cin >> mx >> my;
		move(mx, my);
		cout << "면적 : " << getArea();
		cout << "\n시작점 : ( " << x << ", " << y << " )\n";
	}
	double getArea() {
		return mx * my*0.5;
	}
};

int main()
{
	Shape *ap = new Rectangle;
	Shape *bp = new Circle;
	Shape *cp = new Triangle;
	ap->draw();
	bp->draw();
	cp->draw();
	delete ap, bp, cp;
}
*/




/*
// 8번 
#include<iostream>
#include<string>
using namespace std;

class Shape {
protected:
	string name;		// 도형의 이름
	int width, height;		// 도형에 내접하는 사각형의 너비와 높이
	int x, y;  // 시작점
	int mx, my;  // 이동점
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}
	void setOrigin(int a, int b) {
		x = a;
		y = b;
	}
	virtual Shape* createShape() { return this; }// 질문 - 리턴형이 클래스마다 다 다른데 (Shape,Rectangle, Circle..) 그럼 오버라이딩 안되는데
	virtual double getArea() { return 0; }			// =>>> 리턴형 다르면 오버라이딩 안되는 거 맞음!!
	virtual void draw() {}	// 출력함수				// =>> Shape* 형으로 리턴값똑같이 통일  (Shape 포인터 변수를 리턴함)
	void move(int addx, int addy) {				//=>> 통일하기 위해 각 함수에서 Shape로 업캐스팅한뒤 그 Shape 포인터를 리턴함
		x = x + addx;
		y = y + addy;
	}  // 도형의 기준점 이동
};

class Rectangle : public Shape{
public:
	Shape* createShape() {
		Shape *p  = new Rectangle;
		return p;
	}
	double getArea() {
		return width * height;
	}
};
class Ellipse : public Shape {
public:
	Shape* createShape() {
		Shape *p = new Ellipse;
		return p;
	}
	double getArea() {
		return 3.14*width*height;
	}
};
class Triangle : public Shape {
public:
	Shape * createShape() {
		Shape *p = new Triangle;
		return p;
	}
	double getArea() {
		return width * height*0.5;
	}
};

int main()
{
	Rectangle r;
	Ellipse e;
	Triangle t;
	Shape *pr = r.createShape();
	Shape *pe = e.createShape();
	Shape *pt = t.createShape();
	pr->setOrigin(3, 5);
	((Rectangle *)pr)->setWidth(4);   // 오버라이딩 안했을 시 호출하기 위해 down-casting 한거임.
	((Rectangle *)pr)->setHeight(2);
	pe->setOrigin(3,3);
	((Ellipse *)pe)->setWidth(4);
	((Ellipse *)pe)->setHeight(2);
	pt->setOrigin(2, 2);
	((Triangle *)pt)->setWidth(4);
	((Triangle *)pt)->setHeight(2);
	pr->draw();
	cout << "면 적 : " << pr->getArea() << endl;
	pr->move(2, 1);
	pe->draw();
	cout << "면 적 : " << pe->getArea() << endl;
	pe->move(2, 0);
	pt->draw();
	cout << "면 적 : " << pt->getArea() << endl;
	pt->move(0, 1);
	return 0;
}
*/




/*
// 9번 
#include<iostream>
#include<string>
using namespace std;

class Character {
public:
	virtual void print() {}
};

class Hobbit : public Character {
public:
	void print() {
		cout << "호빗을 그립니다.\n";
	}
};

class Titan : public Character {
public:
	void print() {
		cout << "타이탄을 그립니다.\n";
	}
};

class Shaman : public Character {
public:
	void print() {
		cout << "주술사를 그립니다.\n";
	}
};

// 이렇게 하는 거 맞음
int main() {
	Character *arr[10];
	arr[0] = new Hobbit;
	arr[1] = new Titan;
	arr[2] = new Shaman;
	for (int i = 0; i < 3; i++)
		arr[i]->print();
}
*/



/*
// 10번 
#include<iostream>
using namespace std;

class Shape {
public:
	virtual void run() {}
};

class TwoDimShape : public Shape {
protected:
	int radius;
	int width, height;
public:
	virtual void getArea() {}
	void run() {
		getArea();
	}
};

class ThreeDimShape : public Shape {
protected:
	int radius;
	int width, height;
	int base;
public:
	virtual void getVolume() {}
	void run() {
		getVolume();
	}
};


class Ellipse : public TwoDimShape {
public:
	Ellipse(int r) { radius = r; }
	void getArea() {
		cout << "Ellipse\n";
		cout << "면적 : " << radius * radius * 3.14 << endl;
	}

};
class Rectangle : public TwoDimShape {
public:
	Rectangle(int w, int h) { width = w; height = h; }
	void getArea() {
		cout << "Rectangle\n";
		cout << "면적 : " << width * height << endl;
	}
};
class Triangle : public TwoDimShape {
public:
	Triangle(int w, int h) { width = w; height = h; }
	void getArea() {
		cout << "Triangle\n";
		cout << "면적 : " << width * height * 0.5 << endl;
	}
};


class Shpere : public ThreeDimShape {
public:
	Shpere(int r) { radius = r; }
	void getVolume() {
		cout << "Shpere\n";
		cout << "채적 : " << 0.75*radius*radius*radius*3.14 << endl;
	}
};
class Cube : public ThreeDimShape {
public:
	Cube(int w, int h, int b) { width = w; height = h; base = b; }
	void getVolume() {
		cout << "Cube\n";
		cout << "채적 : " << width*height*base << endl;
	}

};
class Cylinder : public ThreeDimShape {
public:
	Cylinder(int r, int h) { radius = r; height = h; }
	void getVolume() {
		cout << "Cylinder\n";
		cout << "채적 : " << radius*radius*3.14*height << endl;
	}
};

// 이렇게 하는 거 맞음 // 배열 overiding할 때는 무조건 선조의 '포인터' 배열로 해야함 (new로 동적할당 할 것이기 때문에)
// 동적할당 (new)할꺼면 *밖에 안됨. (내가 원하는 객체 new해서 그 객체의 주소가 들어갈 꺼기 때문에)
// 선조배열은 항상 포인터 배열로 잡고 각 인덱스마다 내가 원하는 객체 new해줘서 오버라이딩 해야됨.
int main()
{
	// 배열 쓰는거 이 방법 말고는 없음.
	Shape *arr[6];  // 포인터 배열
	arr[0] = new Ellipse(2);
	arr[1] = new Rectangle(6, 2);
	arr[2] = new Triangle(3, 10);
	arr[3] = new Shpere(5);
	arr[4] = new Cube(5, 2, 7);
	arr[5] = new Cylinder(4,3);

	for (int i = 0; i < 6; i++)
		arr[i]->run(); 
}
*/


/*
// 11번
#include<iostream>
#include<string>
using namespace std;

class Book {
protected: 
	int number;  // 관리번호
	string title;  // 제목
	string author;  // 저자
public:
	virtual int getLateFees(int) { return 0; }
	virtual void print() {}
};

class Novel : public Book {
public:
	Novel(int n, string t, string a) { number = n; title = t; author = a; }
	int getLateFees(int days) {
		return days * 300;
	}
	void print() {
		cout << "관리번호 : " << number << endl;
		cout << "제    목 : " << title << endl;
		cout << "저    자 : " << author << endl;
	}

};
class Poet : public Book {
public:
	Poet(int n, string t, string a) { number = n; title = t; author = a; }
	int getLateFees(int days) {
		return days * 200;
	}
	void print() {
		cout << "관리번호 : " << number << endl;
		cout << "제    목 : " << title << endl;
		cout << "저    자 : " << author << endl;
	}
};
class ScienceFiction : public Book {
public:
	ScienceFiction(int n, string t, string a) { number = n; title = t; author = a; }
	int getLateFees(int days) {
		return days * 600;
	}
	void print() {
		cout << "관리번호 : " << number << endl;
		cout << "제    목 : " << title << endl;
		cout << "저    자 : " << author << endl;
	}
};

int main(void) {
	Book *b1 = new Novel(1111, "소설책", "소설저자");
	Book *b2 = new Poet(1111, "시집", "시인");
	Book *b3 = new ScienceFiction(1111, "공상과학책", "공상저자");
	b1->print();
	cout << b1->getLateFees(3) << "원" << endl;
	b2->print();
	cout << b2->getLateFees(4) << "원" << endl;
	b3->print();
	cout << b3->getLateFees(5) << "원" << endl;
}
*/

/*
// 12번
#include<iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0;  // 두 정수의 합 리턴
	virtual int subtract(int a, int b) = 0;  // 두 정수의 차 리턴
	virtual double average(int a[], int size) = 0;  // 배열a의 평균 리턴/ size는 배열의 크기
};

class GoodCalc : public Calculator {
public:
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}
	double average(int a[], int size) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};

int main()
{
	int a[] = { 1,2,3,4,5 };
	Calculator *p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}
*/

/*
// 13번 
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Score {
protected:
	int num;
	string name;
	int kor, eng, math;
	int score = 1;
public:
	virtual void print() = 0;
	virtual void set_social(int, int) {}
	virtual void set_science(int) {}
	virtual int getSum() { return 0; }
	void set_num(int n) { num = n; }
	void set_name(string s) { name = s; }
	void set_score(int k, int e, int m) { kor = k; eng = e; math = m; }
	int getScore() { return score; }
	int getNum() { return num; }
	void addScore() { score++; }
	void initScore() { score = 1; }
};

class Liberal : public Score {
	int social, history;
public:
	void set_social(int s, int h) {
		social = s;
		history = h;
	}
	int getSum() {
		int sum = 0;
		sum += kor + eng + math + social + history;
		return sum;
	}
	double getAver() {
		return (getSum() / 5.0);
	}
	void print() {
		cout << fixed;
		cout << num << "    " << name << "    " << kor << "    " << eng << "    " << math << "    " << " \t  " << "   " << social << "   "
			<< history << "      " << getSum() << "   " << setprecision(2) << getAver() << "   " << getScore() << endl;
	}
};

class Science : public Score {
	int science;
public:
	void set_science(int s) {
		science = s;
	}
	int getSum() {
		int sum = 0;
		sum += kor + eng + math + science;
		return sum;
	}
	double getAver() {
		return (getSum() / 4.0);
	}
	void print() {
		cout << fixed;
		cout << num << "    " << name << "    " << kor << "    " << eng << "    " << math << "    " << science << "   "
			<< "  \t " << "   " << "   " << "   " << getSum() << "   " << setprecision(2) << getAver() << "   " << getScore() <<  endl;
	}
};

void set_score(Score *arr[], int index) {  // 등수 매기기
	for (int i = 0; i < index; i++) {
		arr[i]->initScore();			// 매번 등수 매기기 전 모든 등수 1로 초기화
	}
	for (int i = 0; i < index; i++)
	{
		for (int k = 0; k < index; k++) {
			if ( arr[i]->getSum() < arr[k]->getSum()) arr[i]->addScore();
		}
	}
}

void search(Score *arr[], int index, int num) {
	int i;
	for (i = 0; i < index; i++) {
		if (arr[i]->getNum() == num) { arr[i]->print(); break; }
	}
	if (i == index) cout << "해당되는 번호가 없습니다.\n";
}

int main()
{
	int n, num;
	int sub; // 문과,이과
	string name;
	int kor, eng, math;
	int social, history, science; 
	Score *arr[100];
	int index = 0;
	for (;;) {
		cout << "\n=== 메뉴 ===\n";
		cout << "1. 입력\n";
		cout << "2. 전체성적표\n";
		cout << "3. 개인성적표\n";
		cout << "4. 종료\n";
		cout << "선택=>";
		cin >> n;

		if(n==1) {
			cout << "1.문과 2.이과=> "; cin >> sub;
			if (sub == 1) arr[index] = new Liberal;
			else arr[index] = new Science;
			cout << "번호 : "; cin >> num;
			cout << "이름 : "; cin >> name;
			cout << "국어 영어 수학 : "; cin >> kor >> eng >> math;
			arr[index]->set_num(num);
			arr[index]->set_name(name);
			arr[index]->set_score(kor, eng, math);
			if (sub == 1) {
				cout << "사회 역사 : "; cin >> social >> history;
				arr[index]->set_social(social, history);
			}
			else {
				cout << "과학 : "; cin >> science;
				arr[index]->set_science(science);
			}
			index++;
		}
		else if(n==2) {
			set_score(arr, index);
			cout <<setw(40) << "*** 성적표 ***\n";
			cout << "=================================================================\n";
			cout << "번호" << " " << "이름" << "  " << "국어" << "  " << "영어" << "  " << "수학" << "  " << "과학" << "  "
				<< "사회" << "  " << "한국사" << "  " << "총점" << "  " << "평균" << "  " << "등수\n";
			cout << "=================================================================\n";
			for (int i = 0; i < index; i++)
				arr[i]->print();
		}
		else if (n == 3) {
			cout << "번호를 입력하세요 : ";
			cin >> num;
			search(arr, index, num);
		}
		else { cout << "프로그램이 종료되었습니다.\n"; break; }
	}
	delete [] *arr;
}
*/