/*
// 1��
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
	Shape *ps = new Rectangle();		// ��������ȯ
	ps->setOrigin(10, 10);
	ps->draw();
	((Rectangle*)ps)->setWidth(100);   // ��������ȯ
	((Rectangle*)ps)->draw();
	ps->draw();

	delete ps;
}
*/

/*
// 2�� - 1
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
// 2��-2
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
// 3��
#include<iostream>
using namespace std;

class AA {
protected: int a;
public:
	AA(int a1 = 0) { a = a1; }
	~AA() {}
	void dispA() { cout << "a=" << a << endl; }
	virtual void disp()  = 0;  // ���������Լ�
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
// 4��
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
public:
	GrandFather(int a) { len = a; }
	void setLen(int a) { len = a; }
	void disp() { cout << "����=" << len << endl; }
};
class Father : public GrandFather
{
protected:
	int headlight;
public:
	Father(int a = 0, int b = 0) : GrandFather(a), headlight(b) {}
	void setLight(int a) { headlight = a; }
	void disp() { cout << "��� ����Ʈ=" << headlight << "��\n"; }
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
// 5��
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
public:
	GrandFather(int a) { len = a; }
	void setLen(int a) { len = a; }
	void disp() { cout << "����=" << len << endl; }
};
class Father :public GrandFather {
protected:
	int headlight;
public:
	Father(int a = 0, int b = 0) : GrandFather(a), headlight(b) {}
	void setLight(int a) { headlight = a; }
	void disp() { cout << "��� ����Ʈ=" << headlight << "��\n"; }
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

// 6��
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
public:
	GrandFather(int a) { len = a; }
	void setLen(int a) { len = a; }
	void disp() { cout << "����=" << len << endl; }
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
		cout << "��� ����Ʈ=" << headlight << "��\n";
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
// 7��
#include<iostream>
using namespace std;
class AA {
public:
	virtual void draw() {}
};
class circle : public AA {
public:
	void draw() {
		cout << "���� �׸��ϴ�~" << endl;
	}
};
class rect : public AA {
public:
	void draw() {
		cout << "�簢���� �׸��ϴ�~" << endl;
	}
};
class line : public AA {
public:
	void draw() {
		cout << "������ �׸��ϴ�~" << endl;
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
// 9��
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
// 12������ - ����Ǯ��
// 1��
#include<iostream>
using namespace std;

class Converter {
	double ratio;
public:
	virtual double convert(double src) = 0;		// ���� �޷��� ��ȯ�Ѵ�.
};

class WonToDoller : public Converter {
	int ratio;
	int won;
public:
	WonToDoller(int r) : ratio(r) {}
	double convert(double src) {
		cout << "��ȯ��� : " << won * src << " �޷�" << endl;
		return 0;
	}
	void run() {
		cout << "���� �޷��� �ٲߴϴ�. ���� �Է��ϼ��� : ";
		cin >> won;
		Converter *c = this;
		c->convert(9.9/won);
	}
};

int main()
{
	WonToDoller wd(1010);  // 1�޷��� 1010��
	wd.run();
}
*/

/*
//2��
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
		cout << "��ǰ�� : " << name << endl;
		cout << "��  �� : " << price << endl;
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
// 3��
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
		if (money < m) cout << "�ܾ��� �����մϴ�\n";
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
		cout << "--- ���࿹�� ����\n";
		cout << "���ݾ� : " << (int)get_money() << endl;
	}
};
class CheckingAcct : public BankAcct {
public:
	CheckingAcct(double m) : BankAcct(m, 0.05) {}
	double getInterest() {
		return (get_money() * get_ratio());
	}
	void print() {
		cout << "--- ���¿��� ����\n";
		cout << "���ݾ� : " << (int)get_money() << endl;
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
	cout << "���ھ� : " << sa.getInterest() << endl;
	ca.print();
	cout << "���ھ� : " << ca.getInterest() << endl;
	
	return 0;
}
*/


/*
// 4��
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
		cout << "���� : " << (int)price << endl;
		cout << "�𵨸� : " << model << endl;
		cout << "����Ŀ : " << maker << endl;
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
// 5��
#include<iostream>
#include<string>
using namespace std;
class LoopAdder {  // �߻� Ŭ����
	string name;  // ������ �̸�
	int x, y, sum;
	void read();  // x,y ���� �о� ���̴� �Լ�
	void write();  // sum�� ����ϴ� �Լ�
protected:
	LoopAdder(string name = "") {  // ������ �̸��� �޴´�. �ʱ갪�� ""
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;  // ���� ���� �Լ�. ������ ���鼭 ���� ���ϴ� �Լ�
public:
	void run();  // ������ �����ϴ� �Լ�
};
void LoopAdder::read() {   // x,y�Է�
	cout << name << ":" << endl;
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}
void LoopAdder::write() {  // ��� sum ���
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
}
void LoopAdder::run() {
	read();  // x,y�� �д´�.
	sum = calculate();  // �������鼭 ����Ѵ�
	write(); // ��� sum�� ����Ѵ�.
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
// 6��
#include<iostream>
#include<string>
using namespace std;

class Shape {
protected:
	string name;		// ������ �̸�
	int width, height;		// ������ �����ϴ� �簢���� �ʺ�� ����
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
		cout << getName() << " ���̴� " << width * width*3.14 << endl;
		return 0;
	}
};

class Rect : public Shape {
public:
	Rect(string n, int w, int h) : Shape(n, w, h) {}
	double getArea() {
		cout << getName() << " ���̴� " << width * height << endl;
		return 0;
	}
};

class Tria : public Shape {
public: 
	Tria(string n, int w, int h) : Shape(n, w, h) {}
	double getArea() {
		cout << getName() << " ���̴� " << width *height*0.5 << endl;
		return 0;
	}
};

int main()
{
	Oval circle("��붱", 5, 10);
	Rect rectangle("����", 4, 8);
	Tria triangle("�佺Ʈ", 11, 15);
	circle.getArea();
	rectangle.getArea();
	triangle.getArea();
}
*/





/*
// 7�� 
#include<iostream>
#include<string>
using namespace std;

class Shape {
protected:
	string name;		// ������ �̸�
	int width, height;		// ������ �����ϴ� �簢���� �ʺ�� ����
	int x, y;  // ������
	int mx, my;  // �̵���
public:
	Shape(string n = "", int w = 0, int h = 0) {
		name = n;
		width = w;
		height = h;
	}
	virtual double getArea() { return 0; }
	virtual void draw() {}	// ����Լ�
	void move(int addx, int addy) {
		x = x + addx;
		y = y + addy;
	}  // ������ ������ �̵�
	string getName() { return name; }
};


class Rectangle : public Shape {
public:
	void draw() {
		cout << "Rectangle Draw\n" << "������ : ";
		cin >> x >> y; 
		cout << "�̵��� : ";
		cin >> mx >> my;
		move(mx, my);
		cout << "���� : " << getArea();
		cout << "\n������ : ( " << x << ", " << y << " )\n";
	}
	double getArea() {
		return mx * my;
	}
};

class Circle : public Shape {
public:
	void draw() {
		cout << "\nCircle Draw\n"<<"������ : ";
		cin >> x >> y;
		cout << "�̵��� : ";
		cin >> mx >> my;
		move(mx, my);
		cout << "���� : " << getArea();
		cout << "\n������ : ( " << x << ", " << y << " )\n";
	}
	double getArea() {
		return 2 * 3.14 * mx;
	}
};

class Triangle : public Shape {
public:
	void draw() {
		cout << "\nTriangle Draw\n" << "������ : ";
		cin >> x >> y;
		cout << "�̵��� : ";
		cin >> mx >> my;
		move(mx, my);
		cout << "���� : " << getArea();
		cout << "\n������ : ( " << x << ", " << y << " )\n";
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
// 8�� 
#include<iostream>
#include<string>
using namespace std;

class Shape {
protected:
	string name;		// ������ �̸�
	int width, height;		// ������ �����ϴ� �簢���� �ʺ�� ����
	int x, y;  // ������
	int mx, my;  // �̵���
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
	virtual Shape* createShape() { return this; }// ���� - �������� Ŭ�������� �� �ٸ��� (Shape,Rectangle, Circle..) �׷� �������̵� �ȵǴµ�
	virtual double getArea() { return 0; }			// =>>> ������ �ٸ��� �������̵� �ȵǴ� �� ����!!
	virtual void draw() {}	// ����Լ�				// =>> Shape* ������ ���ϰ��Ȱ��� ����  (Shape ������ ������ ������)
	void move(int addx, int addy) {				//=>> �����ϱ� ���� �� �Լ����� Shape�� ��ĳ�����ѵ� �� Shape �����͸� ������
		x = x + addx;
		y = y + addy;
	}  // ������ ������ �̵�
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
	((Rectangle *)pr)->setWidth(4);   // �������̵� ������ �� ȣ���ϱ� ���� down-casting �Ѱ���.
	((Rectangle *)pr)->setHeight(2);
	pe->setOrigin(3,3);
	((Ellipse *)pe)->setWidth(4);
	((Ellipse *)pe)->setHeight(2);
	pt->setOrigin(2, 2);
	((Triangle *)pt)->setWidth(4);
	((Triangle *)pt)->setHeight(2);
	pr->draw();
	cout << "�� �� : " << pr->getArea() << endl;
	pr->move(2, 1);
	pe->draw();
	cout << "�� �� : " << pe->getArea() << endl;
	pe->move(2, 0);
	pt->draw();
	cout << "�� �� : " << pt->getArea() << endl;
	pt->move(0, 1);
	return 0;
}
*/




/*
// 9�� 
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
		cout << "ȣ���� �׸��ϴ�.\n";
	}
};

class Titan : public Character {
public:
	void print() {
		cout << "Ÿ��ź�� �׸��ϴ�.\n";
	}
};

class Shaman : public Character {
public:
	void print() {
		cout << "�ּ��縦 �׸��ϴ�.\n";
	}
};

// �̷��� �ϴ� �� ����
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
// 10�� 
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
		cout << "���� : " << radius * radius * 3.14 << endl;
	}

};
class Rectangle : public TwoDimShape {
public:
	Rectangle(int w, int h) { width = w; height = h; }
	void getArea() {
		cout << "Rectangle\n";
		cout << "���� : " << width * height << endl;
	}
};
class Triangle : public TwoDimShape {
public:
	Triangle(int w, int h) { width = w; height = h; }
	void getArea() {
		cout << "Triangle\n";
		cout << "���� : " << width * height * 0.5 << endl;
	}
};


class Shpere : public ThreeDimShape {
public:
	Shpere(int r) { radius = r; }
	void getVolume() {
		cout << "Shpere\n";
		cout << "ä�� : " << 0.75*radius*radius*radius*3.14 << endl;
	}
};
class Cube : public ThreeDimShape {
public:
	Cube(int w, int h, int b) { width = w; height = h; base = b; }
	void getVolume() {
		cout << "Cube\n";
		cout << "ä�� : " << width*height*base << endl;
	}

};
class Cylinder : public ThreeDimShape {
public:
	Cylinder(int r, int h) { radius = r; height = h; }
	void getVolume() {
		cout << "Cylinder\n";
		cout << "ä�� : " << radius*radius*3.14*height << endl;
	}
};

// �̷��� �ϴ� �� ���� // �迭 overiding�� ���� ������ ������ '������' �迭�� �ؾ��� (new�� �����Ҵ� �� ���̱� ������)
// �����Ҵ� (new)�Ҳ��� *�ۿ� �ȵ�. (���� ���ϴ� ��ü new�ؼ� �� ��ü�� �ּҰ� �� ���� ������)
// �����迭�� �׻� ������ �迭�� ��� �� �ε������� ���� ���ϴ� ��ü new���༭ �������̵� �ؾߵ�.
int main()
{
	// �迭 ���°� �� ��� ����� ����.
	Shape *arr[6];  // ������ �迭
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
// 11��
#include<iostream>
#include<string>
using namespace std;

class Book {
protected: 
	int number;  // ������ȣ
	string title;  // ����
	string author;  // ����
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
		cout << "������ȣ : " << number << endl;
		cout << "��    �� : " << title << endl;
		cout << "��    �� : " << author << endl;
	}

};
class Poet : public Book {
public:
	Poet(int n, string t, string a) { number = n; title = t; author = a; }
	int getLateFees(int days) {
		return days * 200;
	}
	void print() {
		cout << "������ȣ : " << number << endl;
		cout << "��    �� : " << title << endl;
		cout << "��    �� : " << author << endl;
	}
};
class ScienceFiction : public Book {
public:
	ScienceFiction(int n, string t, string a) { number = n; title = t; author = a; }
	int getLateFees(int days) {
		return days * 600;
	}
	void print() {
		cout << "������ȣ : " << number << endl;
		cout << "��    �� : " << title << endl;
		cout << "��    �� : " << author << endl;
	}
};

int main(void) {
	Book *b1 = new Novel(1111, "�Ҽ�å", "�Ҽ�����");
	Book *b2 = new Poet(1111, "����", "����");
	Book *b3 = new ScienceFiction(1111, "�������å", "��������");
	b1->print();
	cout << b1->getLateFees(3) << "��" << endl;
	b2->print();
	cout << b2->getLateFees(4) << "��" << endl;
	b3->print();
	cout << b3->getLateFees(5) << "��" << endl;
}
*/

/*
// 12��
#include<iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0;  // �� ������ �� ����
	virtual int subtract(int a, int b) = 0;  // �� ������ �� ����
	virtual double average(int a[], int size) = 0;  // �迭a�� ��� ����/ size�� �迭�� ũ��
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
// 13�� 
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

void set_score(Score *arr[], int index) {  // ��� �ű��
	for (int i = 0; i < index; i++) {
		arr[i]->initScore();			// �Ź� ��� �ű�� �� ��� ��� 1�� �ʱ�ȭ
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
	if (i == index) cout << "�ش�Ǵ� ��ȣ�� �����ϴ�.\n";
}

int main()
{
	int n, num;
	int sub; // ����,�̰�
	string name;
	int kor, eng, math;
	int social, history, science; 
	Score *arr[100];
	int index = 0;
	for (;;) {
		cout << "\n=== �޴� ===\n";
		cout << "1. �Է�\n";
		cout << "2. ��ü����ǥ\n";
		cout << "3. ���μ���ǥ\n";
		cout << "4. ����\n";
		cout << "����=>";
		cin >> n;

		if(n==1) {
			cout << "1.���� 2.�̰�=> "; cin >> sub;
			if (sub == 1) arr[index] = new Liberal;
			else arr[index] = new Science;
			cout << "��ȣ : "; cin >> num;
			cout << "�̸� : "; cin >> name;
			cout << "���� ���� ���� : "; cin >> kor >> eng >> math;
			arr[index]->set_num(num);
			arr[index]->set_name(name);
			arr[index]->set_score(kor, eng, math);
			if (sub == 1) {
				cout << "��ȸ ���� : "; cin >> social >> history;
				arr[index]->set_social(social, history);
			}
			else {
				cout << "���� : "; cin >> science;
				arr[index]->set_science(science);
			}
			index++;
		}
		else if(n==2) {
			set_score(arr, index);
			cout <<setw(40) << "*** ����ǥ ***\n";
			cout << "=================================================================\n";
			cout << "��ȣ" << " " << "�̸�" << "  " << "����" << "  " << "����" << "  " << "����" << "  " << "����" << "  "
				<< "��ȸ" << "  " << "�ѱ���" << "  " << "����" << "  " << "���" << "  " << "���\n";
			cout << "=================================================================\n";
			for (int i = 0; i < index; i++)
				arr[i]->print();
		}
		else if (n == 3) {
			cout << "��ȣ�� �Է��ϼ��� : ";
			cin >> num;
			search(arr, index, num);
		}
		else { cout << "���α׷��� ����Ǿ����ϴ�.\n"; break; }
	}
	delete [] *arr;
}
*/