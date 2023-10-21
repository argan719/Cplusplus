
/*
// 3번
#include<iostream>
#include<string>
using namespace std;
class Point {
	int x, y;
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void showPoint() {
		cout << "x=" << x << "y=" << y << endl;
	}
};
class ColorPoint :public Point {
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColor() {
		cout << "color=" << color << " :";
		showPoint();
	}
};

int main()
{
	ColorPoint cp;
	ColorPoint *pDer = &cp;
	Point *pBase = pDer;

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColor();
}
*/

/*
// 4번
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
private: void handCart1() { cout << "할아버지 Pri손수레" << endl; }
protected: void handCart2() { cout << "할아버지 Pro손수레" << endl; }
public: void handCart3() { cout << "할아버지 Pub손수레" << endl; }
};

class Father : public GrandFather {
protected: int headlight;
private: void bicycle1() { cout << "아빠 Pri자전거" << endl; }
protected: void bicycle2() { cout << "아빠 Pro자전거" << endl; }
public: void bicycle3() { cout << "아빠 Pub자전거" << endl; }
public: void bicycle4() { handCart2(); handCart3(); }
};

class My : public Father {
protected: int speed;
private: void car1() { cout << "나의 Pri자동차" << endl; }
protected: void car2() { cout << "나의 Pro자동차" << endl; }
public: void car3() { cout << "나의 Pub자동차" << endl; }
public: void car4() { handCart2(); handCart3(); }
};

void main()
{
	My Kim;
	Kim.handCart3();
	Kim.bicycle3();
	Kim.car3();
}
*/

/*
// 5번
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
private: void handCart1() { cout << "할아버지 Pri손수레" << endl; }
protected: void handCart2() { cout << "할아버지 Pro손수레" << endl; }
public: void handCart3() { cout << "할아버지 Pub손수레" << endl; }
};

class Father : protected GrandFather {
protected: int headlight;
private: void bicycle1() { cout << "아빠 Pri자전거" << endl; }
protected: void bicycle2() { cout << "아빠 Pro자전거" << endl; }
public: void bicycle3() { cout << "아빠 Pub자전거" << endl; }
public: void bicycle4() { handCart2(); handCart3(); }
};

class My : public Father {
protected: int speed;
private: void car1() { cout << "나의 Pri자동차" << endl; }
protected: void car2() { cout << "나의 Pro자동차" << endl; }
public: void car3() { cout << "나의 Pub자동차" << endl; }
public: void car4() { handCart2(); handCart3(); }
};

void main()
{
	My Kim;
	Kim.handCart3();
	Kim.bicycle3();
	Kim.car3();
}
*/

/*
// 6번
#include<iostream>
#include<cstring>
using namespace std;

class GrandFather {
protected: int len;
private: void handCart1() { cout << "할아버지 Pri손수레" << endl; }
protected: void handCart2() { cout << "할아버지 Pro손수레" << endl; }
public: void handCart3() { cout << "할아버지 Pub손수레" << endl; }
};

class Father : private GrandFather {
protected: int headlight;
private: void bicycle1() { cout << "아빠 Pri자전거" << endl; }
protected: void bicycle2() { cout << "아빠 Pro자전거" << endl; }
public: void bicycle3() { cout << "아빠 Pub자전거" << endl; }
public: void bicycle4() { handCart2(); handCart3(); }
};

class My : public Father {
protected: int speed;
private: void car1() { cout << "나의 Pri자동차" << endl; }
protected: void car2() { cout << "나의 Pro자동차" << endl; }
public: void car3() { cout << "나의 Pub자동차" << endl; }
public: void car4() { bicycle4(); }
};

void main()
{
	My Kim;
	Kim.handCart1();
	Kim.handCart3();
	Kim.bicycle1();
	Kim.bicycle2();
	Kim.bicycle3();
	Kim.car2();
	Kim.car3()
}
*/


/*
// 8번
#include<iostream>
using namespace std;
class KE {
protected:
	int kor, eng;
public:
	KE(int a = 0, int b = 0):kor(a), eng(b) {
	}
	void dispKE() {
		cout << "국어 = " << kor << " 영어=" << eng << endl;
	}
};
class KEM : public KE {
	int mat;
public:
	KEM(int a = 0, int b = 0, int c = 0) : KE(a,b), mat(c) {
	}
	void dispM() {
		cout << " 수학=" << mat << endl;
	}
	void dispKEM() {
		cout << "국어=" << kor << " 영어=" << eng << endl;
		dispM();
	}
};

void main()
{
	KEM Kim(10, 20, 30);
	Kim.dispM();
	Kim.dispKE();
	Kim.dispKEM();
}
*/

/*
// 9번
#include<iostream>
#include<string>
using namespace std;
class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class ColorPoint :public Point {
	string color;
public:
	ColorPoint(int x, int y, string color) : Point(x, y) {
		this->color = color;
	}
	void setPoint(int x, int y) {
		move(x, y);
	}
	void setColor(string color) {
		this->color = color;
	}
	void show() {
		cout << color << "색으로 " << '(' << getX() << ',' << getY() << ')' << "에 위치한 점입니다." << endl;
	}
};

int main()
{
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}
*/

/*
// 10번
#include<iostream>
#include<cstring>
using namespace std;
class Base {
private:
	int baseNum;
public:
	Base() : baseNum(20) {
		cout << "Base()" << endl;
	}
	Base(int n) : baseNum(n) {
		cout << "Base(int n)" << endl;
	}
	void showBase() {
		cout << baseNum << endl;
	}
};
class Derived : public Base {
private:
	int num;
public:
	Derived() : num(30) {
		cout << "Derived()" << endl;
	}
	Derived(int n) :num(n) {
		cout << "Derived(int n)" << endl;
	}
	Derived(int n1, int n2) : Base(n1), num(n2) {
		cout << "Derived(int n1, int n2)" << endl;
	}
	void showDerive()
	{
		showBase();
		cout << num << endl;
	}
};

int main(void)
{
	cout << "case1..." << endl;
	Derived dr1;
	dr1.showDerive();
	cout << "------------------" << endl;
	cout << "case2..." << endl;
	Derived dr2(12);
	dr2.showDerive();
	cout << "------------------" << endl;
	cout << "case3..." << endl;
	Derived dr3(23, 24);
	dr3.showDerive();
}
*/

/*
// 11번
#include<iostream>
#include<cstring>
using namespace std;
class Name {
protected: char irum[12];
public: void set(char *ap) { strcpy(irum, ap);}
		void dispIrum() {
			cout << "이름=" << irum << endl;
		}
};
class NKE :public Name {
protected: int kor, eng;
public:
	void set(int a) {
		kor = a;
	}
	void set(int c, int d) {
		set(c);
		eng = d;
	}
	void set(char *ap, int e, int f) {
		Name::set(ap);
		set(e, f);
	}
	void dispKor() {
		cout << "국어=" << kor << endl;
	}
	void dispEng() {
		cout << "영어=" << eng << endl;
	}
	void dispNKE() {
		dispIrum();
		dispKor();
		dispEng();
	}
};

int main()
{
	NKE Kim, Lee;
	Kim.Name::set("순희");
	Kim.set(10, 20);
	Lee.set("영희", 30, 40);
	Kim.dispNKE();  Lee.dispNKE();
}
*/


/*
// 12번
#include<iostream>
#include<string>
using namespace std;

class GrandFather {
protected: char irum[12];
public: void dispG() { cout << "할아버지이름=" << irum << endl; }
};

class Father : public GrandFather {
protected: char irum[12];
public:
	void set(char *ap, char *bp) {
		strcpy(GrandFather::irum, ap);
		strcpy(irum, bp);
	}
	void dispF() { cout << "아빠이름=" << irum << endl; }
	void dispGF() {
		cout << "할아버지이름=" << GrandFather::irum << endl;
		cout << "아빠이름=" << Father::irum << endl;
	}
};

void main()
{
	Father Lee;
	Lee.set("성계", "방원");
	Lee.dispGF();
}
*/



/*
// 13번
#include<iostream>
#include<string>
using namespace std;

class GrandFather {
protected: int len;
public:
	GrandFather(int a) { len = a; }
	void setLen(int a) { len = a; }
	void disp() { cout << "길이= " << len << endl; }
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

void main()
{
	Father Cycle(250, 2);
	Cycle.GrandFather::disp();
	Cycle.dispGF();
	Cycle.disp();
}
*/



/*
// 14번
#include<iostream>
using namespace std;

class Person {
public:
	void sleep() { cout << "sleep" << endl; }
};

class Student :public Person {
public:
	void study() { cout << "study" << endl; }
};

class PartTimeStudent :public Student {
public:
	void work() { cout << "work" << endl; }
};

int main(void)
{
	Person *ptr11 = new Person();
	Person *ptr12 = new Student();
	Person *ptr13 = new PartTimeStudent();

	ptr11->sleep();
	ptr12->sleep();
	ptr13->sleep();

	cout << endl;
	Student *ptr21 = new Person(); // error
	Student *ptr22 = new Student();
	Student * ptr23 = new PartTimeStudent();
	ptr22->sleep();
	ptr22->study();
	cout << endl;

	ptr23->sleep();
	ptr23->study();
	cout << endl;

	PartTimeStudent * ptr31 = new PartTimeStudent();
	ptr31->sleep();
	ptr31->study();
	ptr31->work();
}
*/



/*
// 15번
#include<iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) { return a + b; }
};

class Subtractor {
protected: 
	int minus(int a, int b) { return a - b; }
};

class Calculator :public Adder, public Subtractor {  // 다중상속
public:
	int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
	int res = 0;
	switch (op) {
	case '+': res = add(a, b); break;
	case '-': res = minus(a, b); break;
	}
	return res;
}
int main() {
	Calculator handCalculator;
	cout << "2 + 4 = " << handCalculator.calc('+', 2, 4) << endl;
	cout << "100 - 8 = " << handCalculator.calc('-', 100, 8) << endl;
}
*/



/*
// 16번
#include<iostream>
using namespace std;

class BaseIO {
public:
	int mode;
};

class In : public BaseIO {
public:
	int readPos;
};

class Out :public BaseIO {
public:
	int writePos;
};

class InOut :public In, public Out {
public:
	bool safe;
	void disp() {
		cout << mode << "  " << readPos << "  " << writePos << "  " << safe << endl;
		cout << readPos << "  " << writePos << "  " << safe << endl;
	}
};

int main()
{
	InOut ioObj;

	ioObj.readPos = 10;
	ioObj.writePos = 20;
	ioObj.safe = true;
	ioObj.mode = 5;
	ioObj.disp();
}
*/

/*
// 17번 - 가상상속
#include<iostream>
#include<cstring>
using namespace std;

class Base {
public:
	int mode;
};
class In : virtual public Base {
public:
	int read;
	void inDisp() {
		cout << "inDisp mode=" << mode << "  " << read << endl;
	}
};
class Out : virtual public Base {
public:
	int write;
	void outDisp() {
		cout << "outDisp mode=" << mode << "  " << write << endl;
	}
};
class InOut : public In, public Out {
public:
	int safe;
	void disp() {
		cout << mode << "  " << read << "  " << write << "  " << safe << endl;
	}
};

int main()
{
	InOut k;
	k.read = 10;
	k.write = 20;
	k.safe = 100;
	k.mode = 5;

	k.inDisp();
	k.outDisp();
	k.disp();
}
*/



/*
// 20페이지 19번,20번 - 회원관리
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class RegularPerson {
	int attend;
public:
	RegularPerson() : attend(0) {}
	void set(int a) {
		attend = a;
	}
	int get_attend() { return attend; }
};

class SpecialPerson {
	string teacher;
	double muscle;
public:
	SpecialPerson() :teacher("-"), muscle(0) {}
	void set(string t, double m) {
		teacher = t;
		muscle = m;
	}
	string get_teahcer() { return teacher; }
	double get_muscle() { return muscle; }
};

class Person : public RegularPerson, public SpecialPerson{
	int id;
	string name;
	string tell;
	double weight;
	int ranking;
public:
	void set(int i, string n, string t, double w) {
		id = i;
		name = n;
		tell = t;
		weight = w;
	}
	void initrank() {
		ranking = 1;
	}
	void addrank() {
		ranking++;
	}
	int get_id() { return id; }
	string get_name() { return name; }
	string get_tell() { return tell; }
	double get_weight() { return weight; }
	int get_rank() { return ranking; }
};

 

class Control {
	Person person[100];
	int id, num;
	string name, tell;
	double weight;
public:
	void set(int i) {
		cout << "NAME : "; cin >> name;
		cout << "ID : "; cin >> id;
		cout << "TELL : "; cin >> tell;
		cout << "WEIGHT : "; cin >> weight;
		person[i].set(id, name, tell, weight);
		type(i);
	}
	void type(int i) {
		cout << "정규회원으로 등록을 원하시면 1, 특별회원(PT)으로 등록을 원하시면 2 를 눌러주세요...\n";
		cin >> num;
		if (num == 1) {
			cout << "몇 회를 끊으시겠습니까 ? : ";
			cin >> id;
			person[i].RegularPerson::set(id);
		}
		else if (num == 2) {
			cout << "강사님 이름을 입력하세요 : ";
			cin >> name;
			cout << "현재 근육량을 입력하세요 : ";
			cin >> weight;
			person[i].SpecialPerson::set(name, weight);
		}
		else cout << "다시 입력바랍니다.\n";
		rank(i);
	}
	void rank(int i)
	{
		for (int k = 0; k <= i; k++) {
			person[k].initrank();
		}
		for (int a = 0; a <= i; a++) {
			for (int b = 0; b <= i; b++) {
				if (person[a].get_weight() < person[b].get_weight()) person[a].addrank();
			}
		}
	}
	void print(int k)
	{
		cout << "ID\t" << "NAME\t" << "TELL\t" << "WEIGHT\t" << "ATTEND\t" << "TEACHER\t" << "MUSCLE\t" << "RANKING\n";
		for (int i = 0; i < k; i++) {
			cout << person[i].get_id() << "\t" << person[i].get_name() << "\t" << person[i].get_tell() << "\t";
			cout << person[i].get_weight() << "\t" << person[i].get_attend() << "\t";
			cout << person[i].get_teahcer() << "\t" << person[i].get_muscle() << "\t" << person[i].get_rank() << endl;
		}
	}
};

int main()
{
	int num;
	Control c;
	for (int i = 0;; i++) {
		cout << "1. 회원등록  2. 회원현황  3. 종료\n";
		cin >> num;
		if (num == 3) { cout << "종료되었습니다.\n";  break; }
		if (num == 1) { c.set(i); }
		if (num == 2) { c.print(i); }
	}
}
*/



/*
// 27페이지 22번
// 다중상속을 하여 몬스터 프로그램을 작성하여 봅시다.
// 몬스터 종류             특징   
// 좀비					정신없이 돌아다닌다.
//						- 현재 위치에서 인접한 8방향으로 무작위로 움직인다.
//뱀파이어				약간은 정신을 차리고 돌아다닌다. 
//						- 상하좌우로 인접한 4방향으로만 움직인다.
//강시					한쪽(또는 반대) 방향으로만 열심히 달린다.
//						- 좌우로 움직이거나 상하로만 움직인다.
//						- 한꺼번에 여러칸을 움직일 수 있다.
//처녀귀신				갑자기 나타난다. 즉, 공간 이동을 할 수 있다.
//						- 현재 좌표에 상관없이 다음에 어디든 갈 수 있다.  

#include "MonsterWorld.h"
#include"VariousMonster.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("허접한좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("못먹어도고", "⟷", rand() % w, rand() % h, true));
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));
	game.play(500, 10);
	printf("------게임 종료--------------------------\n");
}
*/






/*
// 33페이지 문제풀이
// 1번
#include<iostream>
#include<string>
using namespace std;
class AA {
public:
	char name[11];
public:
	AA(char *ap = "no") {
		strcpy(name, ap);
	}
	void set(char *ap) {
		strcpy(name, ap);
	}
	void dispName() {
		cout << "name=" << name << endl;
	}
};
class BB :public AA {
public:
	int age;
public:
	BB(char *bp="no1", int a=0):AA(bp),age(a){ }
	void dispAge() {
		cout << "age=" << age << endl;
	}
	void dispNameAge() {
		dispName();
		dispAge();
	}
	void set(int a) {
		age = a;
	}
	void set(char *cp, int b) {
		AA::set(cp);
		set(b);
	}
};
int main()
{
	BB B;
	B.dispNameAge();
	B.AA::set("Prodo");
	B.set(5);
	B.dispNameAge();
}
*/

/*
// 2번
#include<iostream>
#include<string>
using namespace std;
class AA {
private: int a;
public:
	static char ALP[50];
protected:
	AA(int a1 = 1) {
		a = a1;
		strcat(ALP, "A");
	}
	int GetA() { return a; }
public:
	void Ya() {
		strcat(ALP, "B");
	}
};
char AA::ALP[50] = "수행순서: ";
class BB :public AA {
protected:
	int b;
public:
	BB(int b1 = 2, int c1 = 3) : AA(b1) {
		b = c1 + GetA();
		strcat(ALP, "C");
	}
	void Ho() {
		Ya();
		strcat(ALP, "D");
	}
};
class CC :public BB
{
protected:
	int c;
public:
	CC(int d1 = 4, int e1 = 5, int f1 = 6) : BB(d1, e1) {
		c = f1 + b;
		strcat(ALP, "E");
	}
	void Sin() {
		Ya();
		Ho();
		strcat(ALP, "F");
	}
	void AII() {
		Sin();
		cout << "맴버합=" << GetA() + b + c << endl;
	}
};
int main()
{
	CC Kim(3, 6, 9);
	Kim.Ya();
	Kim.Ho();
	Kim.Sin();  Kim.AII();
	cout << AA::ALP << endl;
}
*/

/*
// 3번
#include<iostream>
#include<string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
class NameCircle :public Circle {
	string name;
public:
	NameCircle(int a, string n): Circle(a), name(n){}
	void show() {
		cout << "반지름이" << getRadius() << "인" << name << endl;
	}
};

int main()
{
	NameCircle waffle(3, "waffle");
	waffle.show();
}
*/

/*
// 4번
#include<iostream>
#include<string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
class NamedCircle : public Circle {
	string name;
public:
	void setPizza(int a, string n){
		setRadius(a);
		name = n;
	}
	void BigPizza() {
		cout << "가장 면적이 넓은 피자는" << name << "입니다." << endl;
	}
};

int main()
{
	NamedCircle pizza[5];
	string name;
	int a;
	cout << "5개의 정수 반지름과 원의 이름을 입력하시오=>\n";
	for (int i = 0; i < 5; i++) {
		cout << '[' << i+1 << ']';
		cin >> a;
		getline(cin, name);
		pizza[i].setPizza(a, name);
	}
	cout << endl << endl;
	double max = 0;
	NamedCircle Big;
	for (int i = 0; i < 5; i++) {
		if (max < pizza[i].getArea()) {
			max = pizza[i].getArea();
			Big = pizza[i];
		}
	}
	Big.BigPizza();
}
*/

/*
// 5번 
#include<iostream>
using namespace std;

class A {
	int x;
	int y;
public:
	A() :x(1), y(1) {}
	A(int a) : x(a), y(1) {}
	A(int a, int b) : x(a), y(b) {}
	void disp() {
		cout << "x=" << x << "  y=" << y << endl;
	}
};
class B : public A {
	int x;
	int y;
public:
	B() :A(),x(1), y(1) {}
	B(int a) : A(), x(a), y(1) {}
	B(int a, int b) :A(), x(a), y(b) {}
	B(int a, int b, int c) :A(c), x(a), y(b) {}
	B(int a, int b, int c, int d) : A(c, d), x(a), y(b) {}
	void disp() {
		cout << "x=" << x << "  y=" << y << "  ";
		A::disp();
	}
};

void main()
{
	B bp;
	B bp1(10);
	B bp2(10, 20);
	B bp3(10, 20, 30);
	B bp4(10, 20, 30, 40);

	bp.disp();
	bp1.disp();
	bp2.disp();
	bp3.disp();
	bp4.disp();
}
*/

/*
// 6번
#include<iostream>
using namespace std;

class BaseArray {
private:
	int capacity;  // 동적 할당된 메모리 용량
	int *mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;  mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyQueue : public BaseArray {
	int front;
	int rear;
public:
	MyQueue(int i) : BaseArray(i), front(0), rear(0) {}
	void enqueue(int n) {
		put(rear, n);
		rear++;
	}
	int dequeue() {
		return get(front++);
	}
	int length() {
		return (rear-front);
	}
	int capacity() { return getCapacity(); }
};
int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);  // 큐에 삽입
	}
	cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << "  ";  // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기: " << mQ.length() << endl;
}
*/

/*
// 7번
#include<iostream>
#include<string>
using namespace std;

class A {
	string name;
	string id;
public:
	A(string n, string i) : name(n), id(i) {}
	string get_name() { return name; }
	string get_id() { return id; }
};
class B {
	double height;
	double weight;
	double eyesight;
public:
	B(double h, double w, double e): height(h), weight(w), eyesight(e){}
	double get_h() { return height; }
	double get_w() { return weight; }
	double get_e() { return eyesight; }
};
class Person : public A, public B {
	int kor;
	int eng;
	int math;
public:
	Person(string n, string i, double h, double w, double e, int k, int en, int m) :A(n, i), B(h, w, e), kor(k), eng(en), math(m) {}
	int get_sum() { return kor + eng + math; }
	int get_aver() { return (get_sum() / 3); }
	int get_kor() { return kor; }
	int get_eng() { return eng; }
	int get_math() { return math; }
};

int main()
{
	string name, id;
	double w, h, e;
	int k, eng, m;
	cout << "이름 : ";  cin >> name;
	cout << "주민번호 : ";  cin >> id;
	cout << "키 : ";  cin >> h;
	cout << "몸무게 : ";  cin >> w;
	cout << "시력 : ";  cin >> e;
	cout << "국어 : ";  cin >> k;
	cout << "영어 : ";  cin >> eng;
	cout << "수학 : ";  cin >> m;
	Person p(name, id, h, w, e, k, eng, m);

	cout << "\n이름 : " << p.get_name() << endl;
	cout << "=============" << endl;
	cout << "주민번호 : " << p.get_id() << endl;
	cout << "키 : " << p.get_h() << endl;
	cout << "몸무게 : " << p.get_w() << endl;
	cout << "시력 : " << p.get_e() << endl;
	cout << endl << endl;
	cout << "국어: " << p.get_kor() << "  " << "영어: " << p.get_eng() << "  ";
	cout << "수학: " << p.get_math() << endl;
	cout << "총점: " << p.get_sum() << "  " << "평균: " << p.get_aver() << endl;
}
*/

/*
// 8번
#include<iostream>
#include<string>
using namespace std;

class pay {
private:
	char name[100];
	int kum;
public:
	pay(char n[], int m) : kum(m) { strcpy(name, n); }
	void showKum() const { // 이름과 급여 출력
		cout << name << "\t\t" << kum << endl;
	}
	int get_kum() { return kum; }
};
class emp {
private:
	pay * emplist[50];
	int empnum;
public:
	emp() : empnum(0) {}
	void empAdd(pay * emp) {
		emplist[empnum++] = emp;
	}
	void print(){
		for (int i = 0; i < empnum; i++) {
			emplist[i]->showKum();
		}
	}
	int sum_kum() {
		int sum = 0;
		for (int i = 0; i < empnum; i++) {
			sum += emplist[i]->get_kum();
		}
		return sum;
	}
};

int main(void) {
	emp sawon;
	int num, money;
	char name[100];
	for (int i = 0;; i++) {
		cout << "\n<< 메뉴 >>\n";
		cout << "1. 직원등록\n2. 급여내역\n3. 급여총액\n4. 종료\n";
		cout << "==>선택 ";
		cin >> num;
		if (num == 4) { cout << "종료되었습니다.\n"; break; }
		else if (num == 1) {
			cout << "\n이름 : ";
			cin >> name;
			cout << "급여 : ";
			cin >> money;
			sawon.empAdd(new pay(name, money));
		}
		else if (num == 2) {
			cout << "이  름" << "\t\t" << "급  여\n";
			cout << "=======================\n";
			sawon.print();
		}
		else if (num == 3) {
			cout << "\n급여총액 : " << sawon.sum_kum() << "원"<< endl;
		}
		else break;
	}
}
*/

/*
// 9번
#include<iostream>
#include<string>
using namespace std;

class Employee {
	string name;
public:
	Employee(string n) : name(n) {}
};
class Regular : public Employee {

};
class Temporal : public Employee {

};

class Service : public Regular {

};

class control {

};

void main()
{
	int num;
	for (int i = 0;; i++) {
		cout << "\n=== 메뉴\n";
		cout << "1. 정규직등록\n2. 임시직등록\n3. 영업직등록\n4. 급여명세서출력\n5. 종료\n";
		cout << "선택=> ";
		cin >> num;
		switch (num) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		default: cout << "프로그램이 종료되었습니다\n"; break;
		}
	}
}
*/

/*
// 10번
#include<iostream>
#include<string>
using namespace std;

class Printer {
private:
	string model;  // 모델명
	string company;  // 제조사
	int pages;  // 인쇄매수
	int paper;  // 인쇄종이잔량
public:
	Printer(string m,string c, int p) : model(m), company(c),pages(0), paper(p) {}
	int print(int p) {
		if (paper < p) {
			cout << "용지가 부족하여 프린트 할 수 없습니다 ㅠㅠ \n";  return 0;
		}
		else {
			pages += p;
			paper -= p;
			return 1;
		}
	}
	void print_state() {
		cout << model << ", " << company << ", 남은종이 " << paper << "장, ";
	}
};

class Inkjet : public Printer {
	int ink; // 잉크잔량
public:
	Inkjet(string m, string c, int p, int i ) : Printer(m,c,p), ink(i) {}
	void printInkjet(int p) {
		if (Printer::print(p)) {
			ink -= p;
			cout << "프린트하였습니다~~\n";
		}
	}
	void print() {
		cout << "잉크젯 : ";
		print_state();
		cout << "남은잉크 " << ink << endl;
	}
};

class Laser : public Printer {
	int toner;  // 토너잔량
public:
	Laser(string m, string c, int p, int t) : Printer(m,c,p),toner(t) {}
	void printLaser(int p) {
		if (Printer::print(p)) {
			toner -= p;
			cout << "프린트하였습니다~~\n";
		}
	}
	void print() {
		cout << "레이저 : ";
		print_state();
		cout << "남은토너 " << toner << endl;
	}
};

void main()
{
	cout << "현재 작동중인 2대의 프린터\n\n";
	Inkjet pInkjet("V40", "HP", 5, 10);
	Laser pLaser("S500", "삼성전자", 3, 20);

	pInkjet.print();
	pLaser.print();
	int num1, num2;
	char c;

	for (;;) {
		cout << "\n프린터(1.잉크젯  2.레이저)와 매수 입력 >> ";
		cin >> num1;		
		cin >> num2;
		if (num1 == 1) {
			pInkjet.printInkjet(num2);
		}
		else if(num1==2) {
			pLaser.printLaser(num2);
		}
		else cout << "잘못 입력하셨습니다. 다시 입력바랍니다.\n";
		pInkjet.print();
		pLaser.print();
		cout << "계속 프린트하시겠습니까? (y/n) : ";
		cin >> c;
		if (c == 'y') continue;
		else { cout << "종료되었습니다.\n";  break; }
	}
}
*/

/*
// 11번
#include<iostream>
#include<string>
using namespace std;

class Seat {
	string name;
public:
	Seat() : name("__") {}
	void reservation(string n) {
		if (name != "__") cout << "이미 예약된 좌석입니다~~\n";
		else name = n;
	}
	void print() {
		cout << name << "  ";
	}
	void cancel(string n) {
		if (name == n) {
			cout << name << "님, 예약이 취소되었습니다\n"; name = "__";
		}
		else {
			cout << "예약되지 않은 회원입니다. 정보가 올바른지 확인해주세요.\n";
		}
	}
};

class Airplane {
	Seat seat[8];
public:
	void reservation(int s, string n) {
		seat[s].reservation(n);
	}
	void print() {
		for (int i = 0; i < 8; i++)
			seat[i].print();
		cout << endl;
	}
	void cancel(int s, string n) {
		seat[s].cancel(n);
	}
};

class KoreanAir {
	Airplane airplane[3];
public:
	void reservation(int a, int s, string n) {
		airplane[a].reservation(s, n);
	}
	void print(int air) {
		cout << endl;
		cout << air+1 << "호기 ";
		airplane[air].print();
	}
	void cancel(int a, int s, string n) {
		airplane[a].cancel(s, n);
	}
};

void main()
{
	int num;
	int airnum, seatnum;
	string name;
	KoreanAir Air;
	for (;;) {
		cout << "*** 대한항공에 오신것을 환영합니다. ***\n";
		cout << endl;
		cout << "예약:1  취소:2  현황:3  종료:4    >>   ";
		cin >> num;
		if (num == 1) {
			cout << "7시-1호기  12시-2호기  17시-3호기    >>  ";
			cin >> airnum; Air.print(airnum - 1);
			cout << "좌석번호 >> ";  cin >> seatnum;  
			cout << "이름입력 >> ";  cin >> name;
			Air.reservation(airnum-1, seatnum-1, name);
		}
		else if (num == 2) {
			cout << "7시-1호기  12시-2호기  17시-3호기    >>  ";
			cin >> airnum; Air.print(airnum - 1);
			cout << "좌석번호 >> ";  cin >> seatnum;
			cout << "이름입력 >> ";  cin >> name;
			Air.cancel(airnum - 1, seatnum - 1, name);
		}
		else if (num == 3) {
			for (int i = 0; i < 3; i++)
				Air.print(i);
		}
		else {
			cout << "*** 감사합니다. ***" << endl; break;
		}
		cout << endl;
	}
}
*/



// 12번


/*
// 13번
#include<iostream>
#include<string>
using namespace std;

class Person {
	string name;
	string num;  // 계좌번호
	double Inmoney;  // 입금액
	double Outmoney;  // 출금액
	double totmoney;  // 잔고
public:
	Person() : Inmoney(0), Outmoney(0), totmoney(0) {}
	void set_new(string n, string n2) {  //계좌개설시
		name = n;
		num = n2;
	}
	void In(double m) {
		Inmoney += m;
		totmoney += m;
		print_totmoney();
	}
	void Out(double m) {
		if (totmoney < m) cout << "잔액이 부족합니다.";
		else { Outmoney += m;  totmoney -= m; }
		print_totmoney();
	}
	void print_totmoney() {
		cout << name << "님의 현재 잔액은 "<< (char)92 << totmoney << "입니다.\n";
	}
	void print() {
		cout << num << "\t" << name << "\t" << Inmoney << "\t" << Outmoney << "\t" << totmoney << endl;
	}
	string get_num() {
		return num;
	}
	string get_name() {
		return name;
	}
	double get_money() {
		return totmoney;
	}
};

class Bank {
	Person person[100];
	int k;
	double money;
	double sum;
public:
	int set_new(int i, string name, string num) {
		for (k = 0; k <= i; k++) {
			if (person[k].get_num() == num) { cout << "중복되는 계좌번호입니다. 다른 번호로 입력해주세요.\n"; return 0; }
		}
		if (i < k) { person[i].set_new(name, num); return 1; }
	}
	void search_for_in(int i, string id) {
		for (k = 0; k < i; k++) {
			if (person[k].get_num() == id) {
				cout << person[k].get_name() << "님의 계좌입니다.\n";
				cout << "입금액 : ";  cin >> money;  person[k].In(money);
				break;
			}
		}
		if (k == i) cout << "계좌번호 오류\n";
	}
	void search_for_out(int i, string id) {
		for (k = 0; k < i; k++) {
			if (person[k].get_num() == id) {
				cout << person[k].get_name() << "님의 계좌입니다.\n";
				cout << "출금액 : ";  cin >> money;  person[k].Out(money);
				break;
			}
		}
		if (k == i) cout << "계좌번호 오류\n";
	}
	void print(int i) {
		for (k = 0; k < i; k++)
			person[k].print();
	}
	double sum_totmoney(int i) {
		sum = 0;
		for (k = 0; k < i; k++)
			sum += person[k].get_money();
		return sum;
	}
};

void main()
{
	int num;
	string id, name;
	double moeny;
	Bank bank;
	for (int i=0;;) {
		cout << "---메뉴---\n";
		cout << "1. 계좌개설\n2. 입금\n3. 출금\n4. 계좌정보 전체출력\n5. 은행 총 잔고 출력\n6. 프로그램 종료\n";
		cout << "선택 : ";  cin >> num;
		switch (num) {
		case 1: {
			cout << "계좌번호 : ";  cin >> id;
			cout << "이  름 : ";  cin >> name;
			if (bank.set_new(i, name, id)) { i++; }
		} break;
		case 2: {
			cout << "계좌번호 : "; cin >> id;
			bank.search_for_in(i, id);
		}break;
		case 3: {
			cout << "계좌번호 : "; cin >> id;
			bank.search_for_out(i, id);
		} break;
		case 4: {
			cout << "계좌번호" << "  " << "고객명" << "  " << "입금액" << "  " << "출금액" << "  " << "잔액\n";
			cout << "==========================================\n";
			bank.print(i);
		}break;
		case 5: {
			cout << "\n=> 우리은행의 고객은 " << i << "명이고 총 잔고는 " << (char)92 << bank.sum_totmoney(i) << endl;
		}break;
		default: {cout << "프로그램이 종료되었습니다.\n"; num = 6; } break;
		}
		cout << endl << endl;
		if (num == 6) break;
	}
}
*/


/*
// 23페이지 21번
// 움직이는 그림판을 만들어 봅시다.

// === main.cpp
#include "Shapes.h"
void main()
{
	Canvas myCanvas(25, 15);
	Line I(2, 2, 8, 4);
	Rect r(2, 9, 6, 3);
	HLine h(1, 7, 23);
	VLine v(12, 1, 13);
	Square s(17, 1, 4);
	Circle c(19, 11, 2);

	do {
		myCanvas.clear();
		I.draw(myCanvas, "●");
	    r.draw(myCanvas, "▣");
	    v.draw(myCanvas, " | ");
		h.draw(myCanvas, "--");
		s.draw(myCanvas, "■");
		c.draw(myCanvas);
		myCanvas.print("나의 사랑스런 그림판");

		I.move(rand() % 3 - 1, rand() % 3 - 1);
		r.move(rand() % 3 - 1, rand() % 3 - 1);
		s.move(rand() % 3 - 1, rand() % 3 - 1);
		c.move(rand() % 3 - 1, rand() % 3 - 1);
	} while (getchar() != 'q');
}
*/

