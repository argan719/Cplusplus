/*
// 1��
#include<iostream>
using namespace std;

int main() {
	int *p;
	p = new int;
	if (!p) {
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}
	*p = 5;  // �Ҵ� ���� ���� ������ 5 ����
	int n = *p;
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;

	delete p;
}
*/

/*
// 3��
#include<iostream>
using namespace std;
class Score {
	int kor;
public:
	int eng;
	void setK(int a) { kor = a; }
	void setE(int b) { eng = b; }
	void set(int a, int b) { setK(a); setE(b); }
	void dispK() { cout << "����=" << kor << "��\n"; }
	void dispE() { cout << "����=" << eng << "��\n"; }
	void disp() { dispK(); dispE(); }
};

void main()
{
	Score *ap;
	ap = new Score;
	ap->setK(10);		ap->setE(20);
	ap->dispK();		ap->dispE();
	delete ap;
	ap = new Score;
	ap->set(90, 95);
	ap->disp();
	delete ap;
}
*/

/*
// 8��
#include<iostream>
using namespace std;
class Score {
	int kor;
	int eng;
public:
	void setK(int a) { kor = a; }
	void setE(int b) { eng = b; }
	void set(int a, int b) { setK(a); setE(b); }
	int getK() { return(kor); }
	int getE() { return(eng); }
	int getT() { return(kor + eng); }
	void dispK() { cout << "����=" << kor << "��\n"; }
	void dispE() { cout << "����=" << eng << "��\n"; }
	void disp() { dispK(); dispE(); }
};
void main()
{
	Score *M = new Score;
	void (Score::*ap)(int, int);
	void (Score::*bp)();
	int (Score::*cp)();

	ap = &Score::set;
	bp = &Score::disp;
	cp = &Score::getT;

	(M->*ap)(90, 95);
	(M->*bp) ();
	cout << "���� = " << (M->*cp)() << endl;
	delete M;
}
*/

/*
// 11��
#include<iostream>
using namespace std;
class Yaho {
	int mon, day;
public:
	void setMonth(int a) {mon = a;}
	void setDay(int a) { day = a; }
	void setMonthDay(int a, int b) { setMonth(a); setDay(b); }
	void disp()
	{
		cout << mon << "��" << day << "���Դϴ�\n";
	}
};

void main()
{
	Yaho M, *ap;
	void(Yaho::*mfp)(int);
	void(Yaho::*dp)();
	ap = &M;
	mfp = &Yaho::setMonth;
	(M.*mfp)(1);
	mfp = &Yaho::setDay;
	(ap->*mfp)(26);

	dp = &Yaho::disp;
	(M.*dp)();
	(ap->*dp)();

	ap = new Yaho;
	ap->setMonthDay(11, 13);
	(ap->*dp)();
	delete ap;
}
*/

/*
// 4��
#include<iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
};
Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}
int main()
{
	Circle *p, *q;
	p = new Circle;
	q = new Circle(30);
	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q;
}
*/

/*
// 9������
#include<iostream>
using namespace std;

class Cal {
	int a, b;
public:
	void set(int a1, int b1) { a = a1; b = b1; }
	void upA(int a1) { a += a1; }
	void upB(int b1) { b += b1; }
	void disp() { cout << "a=" << a << " b=" << b << "\n"; }
};
void main()
{
	Cal Kim;
	void (Cal::*ap)(int);
	Kim.set(10, 20);
	ap = &Cal::upA;
	(Kim.*ap)(5);
	Kim.disp();
}
*/


/*
// 9������ 12��
// ATM��� - ����QUEUE
// === main.cpp
#include<iostream>
#include<ctime>
#include "queue.h"

const int MIN_PER_HR = 60;
using namespace std;
bool newcustomer(double x);
int main()
{
	srand(time(0));

	cout << "��� ����: �̷� ������ ATM\n";
	cout << "ť�� �ִ� ���̸� �Է��Ͻʽÿ�: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "�ùķ��̼� �ð� ���� �Է��Ͻʽÿ�: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "�ð��� ��� �� ���� �Է��Ͻʽÿ�: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (line.isfull())
				turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty()) {
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}
	if (customers > 0) {
		cout << endl;
		cout << "  ť�� ���� �� �� ��: " << customers << endl;
		cout << "  �ŷ��� ó���� �� ��: " << served << endl;
		cout << "  �߱��� ���� �� ��: " << turnaways << endl;
		cout << "  ��� ť�� ����: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "  ��� ��� �ð�: " << (double)line_wait / served << "��\n";
	}
	else
		cout << "  ���� �� �� �����ϴ�!\n";
	cout << "  �Ϸ�!\n";
	return 0;
}
bool newcustomer(double x) {
	return (rand() * x / RAND_MAX < 1);
}
*/





/*
// 19������ - ����Ǯ��
// 5��
#include<iostream>
using namespace std;
class INT {
	int num;
public:
	void set(int n) { num = n; }
	int get() { return num; }
};
void main()
{
	int num;
	int max = 0;
	INT *arr = new INT[10];
	for (int i = 0; i < 10; i++) {
		cin >> num;
		arr[i].set(num);
		if (max < arr[i].get()) max = arr[i].get();
	}
	cout << "���� ū ���� " << max << endl;
}
*/

/*
// 6��
#include<iostream>
#include<string>
using namespace std;
class Person {
	char *name;
	char *tell;
public:
	void set(char* n, char* t) {
		name = new char(strlen(n) + 1);
		tell = new char(strlen(n) + 1);
		strcpy(name, n);
		strcpy(tell, t);
	}
	void print() {
		cout << name << "   " << tell << endl;
	}
	char * get_name() {
		return name;
	}
	char * get_tel() {
		return tell;
	}
};
void search(Person *p, char *name, int index);
void main()
{
	int n;
	int num;
	char name[10];
	char tell[10];
	cout << "�� ���� ��ȭ��ȣ�� �Է��Ͻðڽ��ϱ�? : ";
	cin >> n;
	Person *p = new Person[n];
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "��° ģ���� �̸��� ��ȭ��ȣ�� �Է� �ϼ��� : ";
		cin >> name;
		cin >> tell;
		p[i].set(name, tell);
	}
	cout << "�Էµ� ��ȭ��ȣ\n";
	for (int i = 0; i < n; i++)
	{
		p[i].print();
	}
	for (;;)
	{
		cout << "1. �˻�  2. ���� \n";
		cin >> num;
		if (num == 1) {
			cout << "�˻��� �̸� : ";
			cin >> name;
			search(p,name,n);
		}
		if (num == 2) break;
	}
}

void search(Person *p, char *name, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (*(p[i].get_name()) == *name) cout << "\n" << p[i].get_tel() << endl;
	}
}
*/

/*
// 9��
#include<iostream>
using namespace std;
class Yaho
{
	int mon, day;
public:
	void setMonth(int a) {
		mon = a;
	}
	void setDay(int a) {
		day = a;
	}
	void setMonthDay(int a, int b) {
		setMonth(a);
		setDay(b);
	}
	void disp() {
		cout << mon << "��" << day << "���Դϴ�\n";;
	}
};
void main()
{
	Yaho M, *ap;
	void(Yaho::*mfp)(int);
	void(Yaho::*dp)();
	ap = &M;
	mfp = &Yaho::setMonth;
	(M.*mfp)(1);
	mfp = &Yaho::setDay;
	(ap->*mfp)(26);
	dp = &Yaho::disp;
	(M.*dp)();
	(ap->*dp)();
	ap = new Yaho;
	ap->setMonthDay(11, 13);
	(ap->*dp)();
	delete ap;
}
*/

/*
// 10��
#include<iostream>
using namespace std;
class Score {
public:
	int kor;
	int eng;
	void setK(int a) {
		kor = a;
	}
	void setE(int b) {
		eng = b;
	}
	void set(int a, int b) {
		setK(a);
		setE(b);
	}
	void dispK() {
		cout << "����=" << kor << "��\n";
	}
	void dispE() {
		cout << "����=" << eng << "��\n";
	}
	void disp() {
		dispK();
		dispE();
	}
};

void main()
{
	Score *s = new Score;
	void(Score::*ap)(int, int);
	void(Score::*bp)();

	ap = &Score::set;
	bp = &Score::disp;

	(s->*ap)(90, 95);
	(s->*bp)();
	cout << "����=" << s->kor + s->eng <<"��\n";
}
*/
