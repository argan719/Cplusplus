/*
// 1��
#include<iostream>
#include<string>
using namespace std;
class Company {
private:
	int sales, profit;

	friend void sub(Company &c);
public:
	Company() : sales(0), profit(0) {}
};

void sub(Company & c)
{
	cout << c.profit << endl;
}
int main()
{
	Company c1;
	sub(c1);
	return 0;
}
*/

/*
// 2��
#include<iostream>
using namespace std;
class Date {
	friend bool equals(Date d1, Date d2);
private:
	int year, month, day;
public:
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};
bool equals(Date d1, Date d2)
{
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}
int main()
{
	Date d1(1960, 5, 23), d2(2002, 7, 23);
	cout << equals(d1, d2) << endl;
}
*/

/*
// 3��
#include<iostream>
using namespace std;
class Complex {
public:
	friend Complex add(Complex, Complex);
	Complex(double r, double i) { re = r; im = i; }
	Complex(double r) { re = r; im = 0; }
	Complex() { re = im = 0; }
	void Output() {
		cout << re << " + " << im << "i" << endl;
	}
private:
	double re, im;
};
Complex add(Complex a1, Complex a2)
{
	return Complex(a1.re + a2.re, a1.im + a2.im);
}

int main()
{
	Complex c1(1, 2), c2(3, 4);
	Complex c3 = add(c1, c2);
	c3.Output();
	return 0;
}
*/

/*
// 4��
#include<iostream>
using namespace std;

class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width;  this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s)
{
	if (r.width == s.width  && r.height == s.height) return true;
	else return false;
}

int main()
{
	Rect a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
*/

/*
// 5��
#include<iostream>
using namespace std;

class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s);
	void copy(Rect &dest, Rect& src);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager; // RectManager Ŭ������ ��� �Լ��� ������ �Լ��� ����
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect & dest, Rect& src) {  // src�� dest�� ����
	dest.width = src.width;   dest.height = src.height;
}

int main()
{
	Rect a(3, 4), b(5, 6);
	RectManager man;

	man.copy(b, a);
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
*/

/*
// 6��
#include<iostream>
using namespace std;
class Num {
	int bun;
public:
	Num(int a = 0) : bun(a) {}
	void setBun(int a) { bun = a; }
	void dispBun() {
		cout << "��ȣ=" << bun << endl;
	}
	friend void KK();
};

class Sung : public Num {
	int kor;
public:
	Sung(int a = 0, int b = 0) : Num(a), kor(b) {}
	void setK(int a) { kor = a; }
	void dispK() {
		cout << "����=" << kor << endl;
	}
	//friend void KK();
};

void KK()
{
	Sung Kim;
	Kim.bun = 1;
	Kim.setK(90);
	Kim.dispBun();  Kim.dispK();

	Kim.kor = 100;
	Kim.dispBun();  Kim.dispK();
}

void main()
{
	KK();
}
*/




/*
// 9������ - ����Ǯ��
// 1��
#include<iostream>
using namespace std;

class Rect {
	int width, height;
public:
	Rect(int w, int h) : width(w), height(h) {}
	friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}
int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "�� ��ü�� �����ϴ�. " << endl;
	else cout << "�� ��ü�� ���� �ʽ��ϴ�. " << endl;
}
*/

/*
// 2��
#include<iostream>
using namespace std;
class Sung;

class KE {
	int kor, eng;
	friend Sung;
};
class Sung : public KE {
	int tot;
public:
	Sung(int k, int e) { set(k, e); }
	void set(int k, int e) {
		kor = k;
		eng = e;
		tot = kor + eng;
	}
	void disp() const {
		cout << "����=" << kor << endl;
		cout << "����=" << eng << endl;
		cout << "����=" << tot << endl;
	}
};

void main()
{
	Sung Kim(80, 90);
	Kim.disp();
}
*/

/*
// 3��
#include<iostream>
#include<cstring>
using namespace std;

class Jusik {
	char irum[11];
	double jisu;
public:
	Jusik(char *ap = "no", double a = 0) {
		strcpy(irum, ap);
		jisu = a;
	}
	void set(char *ap) { strcpy(irum, ap); }
	void set(double a) { jisu = a; }
	char *getIrum() { return(irum); }
	double getJisu() { return(jisu); }
	void disp() {
		cout << "���� " << irum << "����=" << jisu << endl;
	}
	friend void down(Jusik &, double);
};

Jusik & Up(Jusik &K, double a1) {
	K.set(K.getJisu() + a1);
	cout << K.getIrum() << "����=" << a1 << "����Ʈ ��\n";
	return K;
}

void down(Jusik &K, double a1) {
	K.jisu -= a1;
	cout << K.irum << "����=" << a1 << "����Ʈ �ٿ�\n";
}

void main()
{
	Jusik B("�ڽ���", 120.5);
	B.disp();
	Up(B, 2);
	down(B, 4);
	B.disp();
	down(Up(B, 2), 4);
	B.disp();
}
*/

/*
// 4��
#include<iostream>
using namespace std;
const int max = 20;
class Manager;

class Car {
	int chair[max] = { 0, };
	int possible_chair = max;
	friend Manager;
};

class Manager {
	Car ch;
public:
	void reserve(int seat) {
		seat -= 1;
		if (ch.chair[seat] == 0) {
			ch.chair[seat] = 1; cout << seat + 1 << "�� �¼� ����Ǿ����ϴ�!\n"; 
			ch.possible_chair -= 1;
			disp();
		}
		else cout << seat + 1 << "�� �¼��� �̹� ����Ǿ����ϴ�.\n";
	}
	void cancel(int seat) {
		seat -= 1;
		if (ch.chair[seat] == 1) {
			ch.chair[seat] = 0; cout << seat + 1 << "�� �¼� �������!\n";
			ch.possible_chair += 1;
			disp();
		}
		else cout << seat + 1 << "�� �¼��� ����Ǿ� ���� �ʽ��ϴ�~~\n";
	}
	void disp() {
		cout << "\n��ü�ڸ��� : " << max << "   " << "���� �ڸ��� : " << ch.possible_chair << endl;
		cout << "��ü�¼���Ȳ\n";
		cout << "-�¼���ȣ : ";  for (int i = 1; i < 21; i++) cout << i << " ";
		cout << "\n-������� : ";  for (int i = 0; i < max; i++) cout << ch.chair[i] << " ";
		cout << endl;
	}
};

void main()
{
	int c, num;
	Manager train;
	for (;;) {
		cout << "\n=== �޴�\n";
		cout << "1. �¼���Ȳ\n2. �¼�����\n3. �¼����\n4. ����\n";
		cout << "==>"; cin >> c;
		if (c == 1) {
			train.disp();
		}
		else if (c == 2) {
			cout << "�¼���ȣ�Է�: ";  cin >> num;
			train.reserve(num);
		}
		else if (c == 3) {
			cout << "�¼���ȣ�Է�: ";  cin >> num;
			train.cancel(num);
		}
		else { cout << "����Ǿ����ϴ�.\n"; break; }
	}
}
*/

/*
// 7��
// === main.cpp

#include<iostream>
#include "Tv.h"
int main()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV�� �ʱ� ������:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\n42\" TV�� ����� ������:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n������ ��� �� 42\" TV�� ������:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" TV�� ������:\n";
	s58.settings();
	return 0;
}
*/
