/*
// 1��
// === main.cpp

#include<iostream>
#include "mytime.h"
using namespace std;
int main()
{
	Time time0;
	Time time1(2, 40);
	Time time2(5, 55);
	Time total;

	cout << "planning time = ";
	time0.show();
	cout << endl;

	cout << "coding time = ";
	time1.show();
	cout << endl;

	cout << "fixing time = ";
	time2.show();
	cout << endl;

	total = time1 + time2; //time1.operator(time2)
	// ������ ǥ��
	cout << "time1 + time2 = ";
	total.show();
	cout << endl;

	Time time3(3, 28);
	cout << "time3 = ";
	time3.show();
	cout << endl;
	// total = time3.operator + (total);
	total = time3 + total;
	cout << "time3.operator + (total) = ";
	total.show();
	cout << endl;

	total = time1.operator+ (time2.operator+(time3));
	cout << "time1.operator + (time2.operator + (time3)) = ";
	total.show();
	cout << endl;

	total = time1 + time2 + time3;
	cout << "time1+time2+time3 = ";
	total.show();
	cout << endl;
	return 0;
}
*/

/*
// 3��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;  this->punch = punch;
	}
	void show();
	Power operator+ (Power op2);  // + ������ �Լ� ����
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power Power::operator+(Power op2) {
	Power tmp;  // �ӽ� ��ü ����
	tmp.kick = this->kick + op2.kick;  // kick ���ϱ�
	tmp.punch = this->punch + op2.punch; // punch ���ϱ�
	return tmp; // ���� ��� ����
}
int main()
{
	Power a(3, 5), b(4, 6), c;
	c = a + b;  // �Ŀ� ��ü + ����
	a.show();
	b.show();
	c.show();
}
*/

/*
// 4��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;  this->punch = punch;
	}
	void show();
	bool operator == (Power op2);  // == ������ �Լ� ����
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
bool Power::operator==(Power op2) {
	if (this->kick == op2.kick && this->punch == op2.punch) return true;
	else return false;
}
int main()
{
	Power a(3, 5), b(3, 5);  // 2���� ������ �Ŀ� ��ü ����
	Power c(5, 5), d(3, 5);
	a.show();
	b.show();
	if (a == b) cout << "�� �Ŀ��� ����. " << endl;
	else cout << "�� �Ŀ��� ���� �ʴ�. " << endl;
	if (c == d) cout << "�� �Ŀ��� ����. " << endl;
	else cout << "�� �Ŀ��� ���� �ʴ�. " << endl;
}
*/
/*
// 5��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;   this->punch = punch;
	}
	void show();
	Power operator+= (Power op2);  // +=������ �Լ� ����
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power Power::operator+= (Power op2) {
	kick = kick + op2.kick;  // kick ���ϱ�
	punch = punch + op2.punch;  // punch ���ϱ�
	return *this;  // ���� ��� ����
}
int main()
{
	Power a(3, 5), b(4, 6), c;
	a.show();
	b.show();
	c = a += b; // Power ��ü ���ϱ�
	a.show();
	c.show();
}
*/

/*
// 6��
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;   this->punch = punch;
	}
	void show();
	Power operator++ ();  // ���� ++ ������ �Լ� ����
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power Power::operator++() {
	kick++;
	punch++;
	return *this;  // ����� ��ü �ڽ�(��ü a) ����
}
int main()
{
	Power a(3, 5), b;
	a.show();
	b.show();
	b = ++a;  // ���� ++ ������ ���
	a.show();
	b.show();
}
*/
/*
// 8��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;  this->punch = punch;
	}
	void show();
	Power operator++ (int x);  // ���� ++ ������ �Լ� ����
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power Power::operator++(int x) {
	Power tmp = *this;  // ���� ���� ��ü ���¸� ����
	kick++;
	punch++;
	return tmp; // ���� ���� ��ü ���� ����
}
int main()
{
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a++;  // ���� ++ ������ ���
	a.show(); // a�� 1������
	b.show(); // b�� a�� �����Ǳ� ���� ���¸� ����
}
*/
/*
// 6��, 8��
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;  this->punch = punch;
	}
	void show();
	Power operator++ ();	// ���� ++������ �Լ� ����
	Power operator++ (int x);	// ���� ++������ �Լ� ����

};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator++(){
	cout << "��������\n";
	kick++;
	punch++;
	return *this;  // ����� ��ü �ڽ�(��ü a)����
}
Power Power::operator++(int x) {
	cout << "��������" << endl;
	Power tmp = *this;
	kick++;
	punch++;
	return tmp;  
}
int main()
{
	Power a(3, 5), b, c;
	a.show();
	b.show();
	b = ++a;  // ���������� ���
	cout << "b=++a\n";
	a.show();
	b.show();
	c = b++; // ���������� ���
	cout << "c=b++\n";
	a.show();
	b.show();
	c.show();
}
*/
/*
// 7��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;  this->punch = punch;
	}
	void show();
	bool operator! ();  // ! ������ �Լ� ����
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
bool Power::operator!() {
	if (kick == 0 && punch == 0) return true;
	else return false;
}
int main()
{
	Power a(0, 0), b(5, 5);
	if (!a) cout << "a�� �Ŀ��� 0�̴�." << endl;  // ! ������ ȣ��
	else cout << "a�� �Ŀ��� 0�� �ƴϴ�." << endl;
	if (!b) cout << "b�� �Ŀ��� 0�̴�." << endl;  // ! ������ ȣ��
	else cout << "b�� �Ŀ��� 0�� �ƴϴ�." << endl;
}
*/
/*
// 9��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+(int n);
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power Power::operator+(int n) {
	Power temp;
	temp.kick = this->kick + n;
	temp.punch = this->punch + n;
	return temp;
}

int main()
{
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2;
	cout << endl;
	a.show();
	b.show();
}
*/

/*
// 10��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;  this->punch = punch;
	}
	void show();
	friend Power operator + (int op1, Power op2);
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(int op1, Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}

int main()
{
	Power a(3, 5), b;
	a.show();
	b.show();
	b = 2 + a; // 2�� �տ� ���� 2�� ����� 2�� ���� ���� ������ friend ����ؼ� �ؾߵ�.
	a.show();
	b.show();
}
*/
/*
// 11��
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;  this->punch = punch;
	}
	void show();
	friend Power operator+(Power op1, Power op2);  // ������ ����
};
void Power::show() {
	cout << "kick=" << kick << "," << "punch=" << punch << endl;
}
Power operator+(Power op1, Power op2) {
	Power tmp;  // �ӽ� ��ü ����
	tmp.kick = op1.kick + op2.kick;  // kick ���ϱ�
	tmp.punch = op1.punch + op2.punch; // punch ���ϱ�
	return tmp;  // �ӽ� ��ü ����
}
int main()
{
	Power a(3, 5), b(4, 6), c;
	c = a + b;  // Power��ü ���ϱ� ����
	a.show();
	b.show();
	c.show();
}
*/
/*
// 12��
// ++�������Լ��� ������� �ۼ�
#include<iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick;  this->punch = punch; }
	void show();
	friend Power operator++(Power &op);  // ���� ++������ �Լ� ������ ����
	friend Power operator++(Power &op, int x);  // ���� ++ ������ �Լ� ������ ����
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power operator++(Power &op) {	// ����++������ �Լ� ����  ( *this�� �� ���� ������ &���)
	op.kick++;
	op.punch++;
	return op;  // ���� ��� ����
}
Power operator++(Power &op, int x) {	// ����++������ �Լ� ����   (int x�� ������� - ���������� �����ϱ� ���� �뵵)
	Power tmp = op;  // �����ϱ� ���� op ���� ����
	op.kick++;
	op.punch++;
	return tmp;  // ���������� op ����
}
int main()
{
	Power a(3, 5), b;
	b = ++a;  // ���� ++ ������
	a.show();   b.show();

	b = a++;  // ���� ++ ������
	a.show();   b.show();
}
*/

/*
// 13��
#include<iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator*(int times) {
		Point pos(xpos*times, ypos*times);
		return pos;
	}
	friend Point operator*(int times, Point &ref);
};
Point operator*(int times, Point &ref) {
	return ref * times;
}
int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = 3 * pos;
	cpy.showPosition();

	cpy = 2 * pos * 3;
	cpy.showPosition();
	return 0;
}
*/





/*
// 14������ - ����Ǯ��
// 1��
#include<iostream>
using namespace std;

class Num {
	int su;
public:
	Num(int s) : su(s) {}
	int operator+(Num );
	int operator-(Num );
	int operator*(Num );
	int operator/(Num );
};
int Num::operator+(Num b) {
	int tmp = su + b.su;
	return tmp;
}
int Num::operator-(Num b) {
	int tmp = su - b.su;
	return tmp;
}
int Num::operator*(Num b) {
	int tmp = su * b.su;
	return tmp;
}
int Num::operator/(Num b) {
	int tmp = su / b.su;
	return tmp;
}
void main()
{
	Num Kim(40), Lee(10);
	int n1, n2, n3, n4;
	n1 = Kim + Lee;   // a=operator +(Kim,Lee);
	n2 = Kim - Lee;
	n3 = Kim * Lee;
	n4 = Kim / Lee;
	cout << "a+b = " << n1 << endl;
	cout << "a-b = " << n2 << endl;
	cout << "a*b = " << n3 << endl;
	cout << "a/b = " << n4 << endl;
}
*/
/*
// 2��
#include<iostream>
using namespace std;

class op {
	int num;
public:
	op(int n) : num(n) {}
	friend int operator+(op, op);
	friend int operator-(op, op);
	friend int operator*(op, op);
	friend int operator/(op, op);
};
int operator+(op a, op b) {
	return a.num + b.num;
}
int operator-(op a, op b) {
	return a.num - b.num;
}
int operator*(op a, op b) {
	return a.num * b.num;
}
int operator/(op a, op b) {
	return a.num / b.num;
}

void main()
{
	op Kim(40), Lee(10);
	cout << "a+b = " << Kim + Lee << endl;
	cout << "a-b = " << Kim - Lee << endl;
	cout << "a*b = " << Kim * Lee << endl;
	cout << "a/b = " << Kim / Lee << endl;

}
*/

/*
// 3��
#include<iostream>
using namespace std;

class OIL {
	char irum[11];
	int gab;
public:
	OIL() {}
	OIL(char *n, int g) {
		strcpy(irum, n);
		gab = g;
	}
	OIL operator+=(int n);
	void Disp() {
		cout << irum << " : " << gab << "��\n";
	}
};
OIL OIL::operator+=(int n) {
	gab += n;
	return *this;
}

void main()
{
	OIL A("����", 650), k;
	A.Disp();
	A += 50;  // A.operator+=(50);
	A.Disp();
	k = A;
	k.Disp();
}
*/

/*
// 4��
#include<iostream>
using namespace std;

class String {
	char str[255];
	int len;
public:
	String() {}
	String(char *s) {
		strcpy(str, s);
		len = strlen(str);
	}
	String operator+(String s);
	void Disp() {
		cout << str << " �� ���� = " << len << endl;
	}
};
String String ::operator+(String s) {
	String tmp;
	strcpy(tmp.str, str);
	strcpy(&tmp.str[len], s.str);
	tmp.len = len + s.len;
	return tmp;
}

void main()
{
	String A("apple"), B("banana");
	A.Disp();
	B.Disp();
	A = B + A;
	A.Disp();
	//cout << A.GetChar(0) << endl;
}
*/

/*
// 5��
#include<iostream>
#include<string>
using namespace std;

class money {
	string name;
	int m;
public:
	money(string s, int c) : name(s), m(c) {}
	void operator+(money);
	void prn() {
		cout << name << " : " << m << endl;
	}
};
void money::operator+(money f) {
	m = m + f.m;
}

void main()
{
	money a("ö��", 100), b("����", 200);
	a.prn();
	b.prn();
	a + b;
	a.prn();
}
*/

/*
// 6��
#include<iostream>
#include<string>
using namespace std;
class money {
	string name;
	int m;
public:
	money() {}
	money(string n, int mo) : name(n), m(mo) {}
	void operator=(money a) {
		m = a.m;
	}
	void prn() {
		cout << name << " : " << m << endl;
	}

};

void main()
{
	money a("ö��", 100), b("����", 500), temp;
	cout << "=�ٲ����\n";
	a.prn();
	b.prn();
	
	temp = a;
	a = b;
	b = temp;

	cout << "\n\n=�ٲ� ��\n";
	a.prn();
	b.prn();
}
*/

/*
// 7��
#include<iostream>
using namespace std;

class Num {
	int su;
public:
	Num(int s) : su(s) {}
	Num operator+=(Num b) {
		su = su + b.su;
		return *this;
	}
	Num operator-=(Num b) {
		su = su - b.su;
		return *this;
	}
	void Disp() {
		cout << "su=" << su << endl;
	}

};

void main()
{
	Num p1(10), p2(2);
	p1 += p2;
	p1.Disp();
	p1 -= p2;
	p1.Disp();
}
*/
/*
// 8��
#include<iostream>
using namespace std;

class Num {
	int su;
public:
	Num(int s) : su(s) {}
	bool operator==(Num b) {
		if (su == b.su) return true;
		else false;
	}
	bool operator!=(Num b) {
		if (su != b.su) return true;
		else false;
	}
};

void main()
{
	Num p1(10), p2(2);
	if (p1 != p2) cout << "�����ʴ�" << endl;
	if (p1 == p2) cout << "����" << endl;
}
*/

/*
// 9��
#include<iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point() {}
	Point(int a, int b) : x(a), y(b) {}
	Point operator+ (Point b) {
		Point tmp;
		tmp.x = x + b.x;
		tmp.y = y + b.y;
		return tmp;
	}
	Point operator-(Point b) {
		Point tmp;
		tmp.x = x - b.x;
		tmp.y = y - b.y;
		return tmp;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

int main() {
	Point p5(5, 8);
	Point p6(2, 7);
	Point p7;
	p7 = p5 + p6;
	Point p8 = p5 - p6;
	cout << "(" << p5.getX() << "   " << p5.getY() << ")" << endl;
	cout << "(" << p6.getX() << "   " << p6.getY() << ")" << endl;
	cout << "(" << p7.getX() << "   " << p7.getY() << ")" << endl;
	cout << "(" << p8.getX() << "   " << p8.getY() << ")" << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
*/



/*
// 10�� 
// === main.cpp
#include<iostream>
using namespace std;
#include "stringbad.h"

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
	StringBad headline("������ �ֿ䴺�� ~");
	StringBad economy("��������");
	StringBad sports("����������");
	cout << "headline : " << headline << endl;
	cout << "economy : " << economy << endl;
	cout << "sports : " << sports << endl;

	callme1(headline);
	cout << "headline: " << headline << endl; 
	callme2(economy);
	cout << "economy: " << economy << endl;
	cout << endl;

	cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ:\n";
	StringBad back1 = headline;
	cout << "back1: " << back1 << endl;

	//cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ����:\n";
	//StringBad back2;
	//back2 = headline;
	//cout << "back2: " << back2 << endl; 

	return 0;
}

void callme1(StringBad & rsb)
{
	cout << "������ ���޵� StringBad: ";
	cout << "   \"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
	cout << "������ ���޵� StringBad: ";
	cout << "  \"" << sb << "\"\n";
}
*/


