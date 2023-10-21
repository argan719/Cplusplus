
/*
// 1번
#include<iostream>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() {
		return 3.14*radius*radius;
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
};

Circle::Circle() {
	radius = 1;
	cout << "생성자실행()radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자실행(int)radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자실행radius = " << radius << endl;
}
void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}
int main()
{
	Circle waffle(30);
	Circle k = waffle;
	increase(waffle);
	cout << waffle.getRadius() << endl;
}
*/

/*
// 2번
#include<iostream>
#include<cstring>
using namespace std;
class Person {
	char *name;
	int id;
public:
	Person(int id, char *name);
	~Person();
	void changeName(char *name);
	void show() {
		cout << id << ',' << name << endl;
	}
};
Person::Person(int id, char *name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
Person::~Person() {
	if (name)
		delete[] name;
}
void Person::changeName(char *name) {
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}
int main()
{
	Person father(1, "Brown");
	Person daughter(father);
	cout << "daughter 객체생성직후----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Sally");
	cout << "daughter 이름을 Sally로 변경한 후----" << endl;
	father.show();
	daughter.show();
}
*/

/*
// 3번
#include<iostream>
#include<cstring>
using namespace std;
class Person {
	char *name;
	int age;
public:
	Person(char * myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "이름" << name << endl;
		cout << "나이" << age << endl;
	}
	~Person() {
		delete[] name;
		cout << "called destructor!" << endl;
	}
};
int main()
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;  // 얕은복사
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}
*/



/*
// 4번 질문 후 notion에 필기해놓기
// 디폴트 복사생성자의 문제점을 해결하여 봅시다.(깊은 복사생성자 - 내가 작성)
#include<iostream>
#include<cstring>
using namespace std;
class Person {
	char *name;
	int id;
public:
	Person(int id, char *name);
	Person(Person & person);   // 복사생성자
	~Person();
	void changeName(char *name);
	void show() { cout << id << "," << name << endl; }
};
Person::Person(int id, char *name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
Person::Person(Person &person) {		// 복사생성자  (매개변수에 참조(&) 꼭 붙여야 함)
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사생성자실행 원본객체의이름" << this->name << endl;
}
Person::~Person() {
	if (name)
		delete[] name;
}
void Person::changeName(char *name) {
	if (strlen(name) > strlen(this->name))
		return;		//  값없는 리턴 -> 함수 실행 종료됨(void형 함수의 종료)
	strcpy(this->name, name);
}
int main()
{
	Person father(1, "Kitae");
	Person daughter(father);
	Person d2 = daughter;

	cout << "daughter 객체생성직후" << endl;
	father.show();
	daughter.show();
	d2.show();

	daughter.changeName("Grace");
	cout << "daughter 이름을 변경한 후" << endl;
	father.show();
	daughter.show();
	d2.show();
}
*/


/*
// 5번
#include<iostream>
using namespace std;
class Score {
	int kor, eng;
public:
	Score(int a = 0, int b = 0) : kor(a), eng(b) {
		cout << "생성자 콜" << endl;
	}
	Score(const Score & M) {
		kor = M.kor;
		eng = M.eng;
		cout << "복사생성자 콜\n";
	}
	~Score() {
		cout << "소멸자 콜" << endl;
	}
	void disp() {
		cout << "국어=" << kor << " 영어=" << eng << endl;
	}
	void dispTot(Score M) {
		cout << "총점= " << kor + eng << endl;
	}
	Score get() {
		return (*this);
	}
};

void main()
{
	Score Kim(90, 95);
	Score Lee;
	Lee.dispTot(Lee);
	Lee = Kim.get();
	Lee.disp();
}
*/

/*
// 6번
#include<iostream>
using namespace std;
class Temporary {
private: 
	int num;
public:
	Temporary(int n) : num(n) {
		cout << "객체생성: " << num << endl;
	}
	~Temporary()
	{
		cout << "객체소멸: " << num << endl;
	}
	void showTempInfo() {
		cout << "My num is " << num << endl;
	}
};
int main(void)
{
	Temporary a(1), b(2), c(3);
	Temporary(100);
	cout << "********** 생성완료 !" << endl << endl;

	Temporary(200).showTempInfo();
	cout << "********** 임시객체생성완료 !" << endl << endl;

	const Temporary &ref = Temporary(300);
	cout << "********** end of main !" << endl << endl;
	return 0;
}
*/

/*
// 7번  
#include<iostream> 
#include<cstring>
using namespace std;
class Person {
	char *name;
	int id;
public:
	Person(int id, char *name);
	Person(Person &person);
	~Person();
	void changeName(char *name);
	void show() { cout << id << "," << name << endl; }
};
Person::Person(int id, char *name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
Person::Person(Person &person) {
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행 " << this->name << endl;
}
Person::~Person() {
	if (name)
		delete[] name;
}
void Person::changeName(char *name) {
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}
void f(Person person) {
	person.changeName("Sally");
}
Person g() {
	Person mother(2, "Neo");
	return mother;
}

int main() {
	Person father(1, "Brown");
	Person son = father;		// 복사 생성자 호출
	f(father);					// 복사 생성자 호출
	Person a = g();				// 복사 생성자 호출
	a.show();
}
*/



/*
// 8페이지 - 문제풀이 다 해오기
// 1번
#include<iostream>
#include<math.h>
using namespace std;
class Time {
private:
	int hour;
	int min;
public:
	Time();		// 디폴트 생성자
	Time(int h, int m);  // 시간, 분으로 초기화하는 생성자
	Time(double t);   // 시간을 실수값으로 초기화하는 생성자
	Time(const Time &tr);  // 복사 생성자
	Time plus(const Time &tr);  // 두 객체의 시간을 더해서 리턴한다.
	void show();  // 출력 맴버함수
};
Time::Time() : hour(0), min(0) {}
Time::Time(int h, int m) : hour(h), min(m) {}
Time::Time(double t) {

	hour = (int)t;
	t -= hour;
	min = (int)(60*t);
}
Time::Time(const Time &tr) {
	hour = tr.hour;
	min = tr.min;
}

Time Time::plus(const Time &tr) {
	Time p;
	p.hour = hour + tr.hour;
	p.min = min + tr.min;
	int i = 0;
	if (p.min > 60) {
		while(59 < p.min){
			p.min -= 60;
			i++;
		}
	}
	p.hour += i;
	return p;
}
void Time::show() {
	cout << hour << "시간 " << min << "분\n";
}

int main()
{
	Time a(3, 20), b(4.7);

	a.show();
	b.show();

	Time res = a.plus(b);
	cout << "두 시간을 더하면 : ";
	res.show();
	return 0;
}
*/

/*
// 2번
#include<iostream>
using namespace std;

class San {
private:
	char *name;
	int height;
public:
	San();	// 디폴트 생성자
	San(const char *np, int h);  // 오버로디드 생성자
	San(const San &sr);	// 복사 생성자
	void prn();		// 출력 맴버함수
};
San::San() {
}
San::San(const char *np, int h) {
	name = new char[strlen(np)+1];
	strcpy(name, np);
	height = h;
}
San::San(const San &sr) {
	name = new char[strlen(sr.name) + 1];
	strcpy(name, sr.name);
	height = sr.height;
}
void San::prn() {
	cout << "이름 : " << name << endl;
	cout << "높이 : " << height << endl;
}

int main()
{
	San a("관악", 629);
	San b = a;
	b.prn();
	return 0;
}
*/



/*
// 3번
#include<iostream>
#include<string>
using namespace std;

class MyString {
private:
	char *str;
	int len;
public:
	MyString();  // 디폴트 생성자
	MyString(const char *sp);   // 오버로디드 생성자
	MyString(const MyString &sr); // 복사 생성자
	~MyString();  // 소멸자
	int length();  // 문자열의 길이를 리턴하는 함수
	void prn();   // 저장된 문자열과 길이를 출력
};
MyString::MyString() {}
MyString::MyString(const char *sp) {
	str = new char[strlen(sp) + 1];
	strcpy(str, sp);
	len = strlen(str);
}
int MyString::length() {
	return len;
}

MyString::MyString(const MyString &sr) {
	str = new char[sr.len+1];
	strcpy(str, sr.str);
	len = strlen(str);
}


MyString::~MyString() {
	delete str;
}

void MyString::prn() {
	cout << str << " (" << len << ")" << endl;
}

MyString longer(MyString x, MyString y) {
	cout << "더 긴 문자열은 : ";
	return (y.length() <= x.length()) ? x : y;
}

int main(void)
{
	char input[100];
	cout << "첫 번째 문자열 입력 : ";
	cin.getline(input, 100);
	MyString a(input);
	cout << "두 번째 문자열 입력 : ";
	cin.getline(input, 100);
	MyString b(input);
	longer(a, b).prn();
}
*/



/*
// 4번
#include<iostream>
using namespace std;

typedef int Item;

class MyIntStack {
private:
	enum { MAX = 10 };	// 클래스용 상수
	Item items[MAX];  // 스택 항목들을 저장한다
	int top;         // 스택의 꼭대기 항목을 나타낸다
public:
	MyIntStack();
	bool isempty()const;
	bool isfull() const;
	// push()는 스택이 가득 차 있으면 false를, 아니면 true를 리던한다
	bool push(const Item & item);   // 스택에 항목을 추가한다
	// pop()는 스택이 비어 있으면 false를, 아니면 true를 리턴한다
	bool pop(Item &item);   // 꼭대기 항목을 꺼내 item에 넣는다
};
MyIntStack::MyIntStack() {
	top = 0;
}
bool MyIntStack::isempty() const {
	return top == 0;
}
bool MyIntStack::isfull() const {
	return top == MAX;
}
bool MyIntStack::push(const Item &item) {
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}
bool MyIntStack::pop(Item &item) {
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else return false;
}
void main()
{
	MyIntStack number;
	int i = 0;
	while (!number.isfull()) {
		number.push(i);
		cout << i << "  ";
		i++;
	}
	cout << endl;
	int out;
	while (!number.isempty()) {
		number.pop(out);
		cout << out << "  ";
	}
}
*/


/*
// 5번  - 맞게 한건지 질문
#include<iostream>
using namespace std;
typedef int Item;

class MyIntStack {
private:
	int MAX;
	Item *items;  // 스택 항목들을 저장한다
	int top;         // 스택의 꼭대기 항목을 나타낸다
public:
	MyIntStack();
	bool isempty()const;
	bool isfull() const;
	// push()는 스택이 가득 차 있으면 false를, 아니면 true를 리던한다
	bool push(const Item & item);   // 스택에 항목을 추가한다
	// pop()는 스택이 비어 있으면 false를, 아니면 true를 리턴한다
	bool pop(Item &item);   // 꼭대기 항목을 꺼내 item에 넣는다
	void set(int size);  // 스택의 크기를 전달받아서 스택 설정
	MyIntStack(MyIntStack &s);  // 복사생성자
};
MyIntStack::MyIntStack() {
	top = 0;
}
bool MyIntStack::isempty() const {
	return top == 0;
}
bool MyIntStack::isfull() const {
	return top == MAX;
}
bool MyIntStack::push(const Item &item) {
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}
bool MyIntStack::pop(Item &item) {
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else return false;
}

// 이렇게 동적으로 할당하는 거 맞는지 질문 ( 스택 사이즈) - 맞음
void MyIntStack::set(int size) {
	MAX = size;
	items = new int[MAX];
}
// 복사생성자 - 이런식으로 값 복사하는 거 맞는지 질문(for로 하나씩 복사) - 맞음
MyIntStack::MyIntStack(MyIntStack &s) {
	items = new int[s.MAX];
	for (int i = 0; i < MAX; i++)
		items[i] = s.items[i];
}
void main()
{
	MyIntStack a;
	int s, num;
	cout << "스택사이즈 : ";
	cin >> s;
	a.set(s); cout << "push : ";
	for (int i = 0; i < s; i++) {
		cin >> num;
		a.push(num);
	}
	cout << endl;
	MyIntStack b = a;
	a.pop(num);
	cout << "A 스택에서 팝한 값 " << num << endl;
	b.pop(num);
	cout << "B 스택에서 팝한 값 " << num << endl;
}
*/

