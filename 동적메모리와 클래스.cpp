/*
// 1번
#include<iostream>
using namespace std;

int main() {
	int *p;
	p = new int;
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}
	*p = 5;  // 할당 받은 정수 공간에 5 삽입
	int n = *p;
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;

	delete p;
}
*/

/*
// 3번
#include<iostream>
using namespace std;
class Score {
	int kor;
public:
	int eng;
	void setK(int a) { kor = a; }
	void setE(int b) { eng = b; }
	void set(int a, int b) { setK(a); setE(b); }
	void dispK() { cout << "국어=" << kor << "점\n"; }
	void dispE() { cout << "영어=" << eng << "점\n"; }
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
// 8번
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
	void dispK() { cout << "국어=" << kor << "점\n"; }
	void dispE() { cout << "영어=" << eng << "점\n"; }
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
	cout << "총점 = " << (M->*cp)() << endl;
	delete M;
}
*/

/*
// 11번
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
		cout << mon << "월" << day << "일입니다\n";
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
// 4번
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
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
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
// 9페이지
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
// 9페이지 12번
// ATM기계 - 원형QUEUE
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

	cout << "사례 연구: 미래 은행의 ATM\n";
	cout << "큐의 최대 길이를 입력하십시오: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "시뮬레이션 시간 수를 입력하십시오: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "시간당 평균 고객 수를 입력하십시오: ";
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
		cout << "  큐에 줄을 선 고객 수: " << customers << endl;
		cout << "  거래를 처리한 고객 수: " << served << endl;
		cout << "  발길을 돌린 고객 수: " << turnaways << endl;
		cout << "  평균 큐의 길이: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "  평균 대기 시간: " << (double)line_wait / served << "분\n";
	}
	else
		cout << "  고객이 한 명도 없습니다!\n";
	cout << "  완료!\n";
	return 0;
}
bool newcustomer(double x) {
	return (rand() * x / RAND_MAX < 1);
}
*/





/*
// 19페이지 - 문제풀이
// 5번
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
	cout << "가장 큰 수는 " << max << endl;
}
*/

/*
// 6번
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
	cout << "몇 명의 전화번호를 입력하시겠습니까? : ";
	cin >> n;
	Person *p = new Person[n];
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "번째 친구의 이름과 전화번호를 입력 하세요 : ";
		cin >> name;
		cin >> tell;
		p[i].set(name, tell);
	}
	cout << "입력된 전화번호\n";
	for (int i = 0; i < n; i++)
	{
		p[i].print();
	}
	for (;;)
	{
		cout << "1. 검색  2. 종료 \n";
		cin >> num;
		if (num == 1) {
			cout << "검색할 이름 : ";
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
// 9번
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
		cout << mon << "월" << day << "일입니다\n";;
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
// 10번
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
		cout << "국어=" << kor << "점\n";
	}
	void dispE() {
		cout << "영어=" << eng << "점\n";
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
	cout << "총점=" << s->kor + s->eng <<"점\n";
}
*/
