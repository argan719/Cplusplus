
/*
// 1��
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
	cout << "�����ڽ���()radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "�����ڽ���(int)radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ��ڽ���radius = " << radius << endl;
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
// 2��
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
	cout << "daughter ��ü��������----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Sally");
	cout << "daughter �̸��� Sally�� ������ ��----" << endl;
	father.show();
	daughter.show();
}
*/

/*
// 3��
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
		cout << "�̸�" << name << endl;
		cout << "����" << age << endl;
	}
	~Person() {
		delete[] name;
		cout << "called destructor!" << endl;
	}
};
int main()
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;  // ��������
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}
*/



/*
// 4�� ���� �� notion�� �ʱ��س���
// ����Ʈ ����������� �������� �ذ��Ͽ� ���ô�.(���� ��������� - ���� �ۼ�)
#include<iostream>
#include<cstring>
using namespace std;
class Person {
	char *name;
	int id;
public:
	Person(int id, char *name);
	Person(Person & person);   // ���������
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
Person::Person(Person &person) {		// ���������  (�Ű������� ����(&) �� �ٿ��� ��)
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "��������ڽ��� ������ü���̸�" << this->name << endl;
}
Person::~Person() {
	if (name)
		delete[] name;
}
void Person::changeName(char *name) {
	if (strlen(name) > strlen(this->name))
		return;		//  ������ ���� -> �Լ� ���� �����(void�� �Լ��� ����)
	strcpy(this->name, name);
}
int main()
{
	Person father(1, "Kitae");
	Person daughter(father);
	Person d2 = daughter;

	cout << "daughter ��ü��������" << endl;
	father.show();
	daughter.show();
	d2.show();

	daughter.changeName("Grace");
	cout << "daughter �̸��� ������ ��" << endl;
	father.show();
	daughter.show();
	d2.show();
}
*/


/*
// 5��
#include<iostream>
using namespace std;
class Score {
	int kor, eng;
public:
	Score(int a = 0, int b = 0) : kor(a), eng(b) {
		cout << "������ ��" << endl;
	}
	Score(const Score & M) {
		kor = M.kor;
		eng = M.eng;
		cout << "��������� ��\n";
	}
	~Score() {
		cout << "�Ҹ��� ��" << endl;
	}
	void disp() {
		cout << "����=" << kor << " ����=" << eng << endl;
	}
	void dispTot(Score M) {
		cout << "����= " << kor + eng << endl;
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
// 6��
#include<iostream>
using namespace std;
class Temporary {
private: 
	int num;
public:
	Temporary(int n) : num(n) {
		cout << "��ü����: " << num << endl;
	}
	~Temporary()
	{
		cout << "��ü�Ҹ�: " << num << endl;
	}
	void showTempInfo() {
		cout << "My num is " << num << endl;
	}
};
int main(void)
{
	Temporary a(1), b(2), c(3);
	Temporary(100);
	cout << "********** �����Ϸ� !" << endl << endl;

	Temporary(200).showTempInfo();
	cout << "********** �ӽð�ü�����Ϸ� !" << endl << endl;

	const Temporary &ref = Temporary(300);
	cout << "********** end of main !" << endl << endl;
	return 0;
}
*/

/*
// 7��  
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
	cout << "���� ������ ���� " << this->name << endl;
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
	Person son = father;		// ���� ������ ȣ��
	f(father);					// ���� ������ ȣ��
	Person a = g();				// ���� ������ ȣ��
	a.show();
}
*/



/*
// 8������ - ����Ǯ�� �� �ؿ���
// 1��
#include<iostream>
#include<math.h>
using namespace std;
class Time {
private:
	int hour;
	int min;
public:
	Time();		// ����Ʈ ������
	Time(int h, int m);  // �ð�, ������ �ʱ�ȭ�ϴ� ������
	Time(double t);   // �ð��� �Ǽ������� �ʱ�ȭ�ϴ� ������
	Time(const Time &tr);  // ���� ������
	Time plus(const Time &tr);  // �� ��ü�� �ð��� ���ؼ� �����Ѵ�.
	void show();  // ��� �ɹ��Լ�
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
	cout << hour << "�ð� " << min << "��\n";
}

int main()
{
	Time a(3, 20), b(4.7);

	a.show();
	b.show();

	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : ";
	res.show();
	return 0;
}
*/

/*
// 2��
#include<iostream>
using namespace std;

class San {
private:
	char *name;
	int height;
public:
	San();	// ����Ʈ ������
	San(const char *np, int h);  // �����ε�� ������
	San(const San &sr);	// ���� ������
	void prn();		// ��� �ɹ��Լ�
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
	cout << "�̸� : " << name << endl;
	cout << "���� : " << height << endl;
}

int main()
{
	San a("����", 629);
	San b = a;
	b.prn();
	return 0;
}
*/



/*
// 3��
#include<iostream>
#include<string>
using namespace std;

class MyString {
private:
	char *str;
	int len;
public:
	MyString();  // ����Ʈ ������
	MyString(const char *sp);   // �����ε�� ������
	MyString(const MyString &sr); // ���� ������
	~MyString();  // �Ҹ���
	int length();  // ���ڿ��� ���̸� �����ϴ� �Լ�
	void prn();   // ����� ���ڿ��� ���̸� ���
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
	cout << "�� �� ���ڿ��� : ";
	return (y.length() <= x.length()) ? x : y;
}

int main(void)
{
	char input[100];
	cout << "ù ��° ���ڿ� �Է� : ";
	cin.getline(input, 100);
	MyString a(input);
	cout << "�� ��° ���ڿ� �Է� : ";
	cin.getline(input, 100);
	MyString b(input);
	longer(a, b).prn();
}
*/



/*
// 4��
#include<iostream>
using namespace std;

typedef int Item;

class MyIntStack {
private:
	enum { MAX = 10 };	// Ŭ������ ���
	Item items[MAX];  // ���� �׸���� �����Ѵ�
	int top;         // ������ ����� �׸��� ��Ÿ����
public:
	MyIntStack();
	bool isempty()const;
	bool isfull() const;
	// push()�� ������ ���� �� ������ false��, �ƴϸ� true�� �����Ѵ�
	bool push(const Item & item);   // ���ÿ� �׸��� �߰��Ѵ�
	// pop()�� ������ ��� ������ false��, �ƴϸ� true�� �����Ѵ�
	bool pop(Item &item);   // ����� �׸��� ���� item�� �ִ´�
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
// 5��  - �°� �Ѱ��� ����
#include<iostream>
using namespace std;
typedef int Item;

class MyIntStack {
private:
	int MAX;
	Item *items;  // ���� �׸���� �����Ѵ�
	int top;         // ������ ����� �׸��� ��Ÿ����
public:
	MyIntStack();
	bool isempty()const;
	bool isfull() const;
	// push()�� ������ ���� �� ������ false��, �ƴϸ� true�� �����Ѵ�
	bool push(const Item & item);   // ���ÿ� �׸��� �߰��Ѵ�
	// pop()�� ������ ��� ������ false��, �ƴϸ� true�� �����Ѵ�
	bool pop(Item &item);   // ����� �׸��� ���� item�� �ִ´�
	void set(int size);  // ������ ũ�⸦ ���޹޾Ƽ� ���� ����
	MyIntStack(MyIntStack &s);  // ���������
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

// �̷��� �������� �Ҵ��ϴ� �� �´��� ���� ( ���� ������) - ����
void MyIntStack::set(int size) {
	MAX = size;
	items = new int[MAX];
}
// ��������� - �̷������� �� �����ϴ� �� �´��� ����(for�� �ϳ��� ����) - ����
MyIntStack::MyIntStack(MyIntStack &s) {
	items = new int[s.MAX];
	for (int i = 0; i < MAX; i++)
		items[i] = s.items[i];
}
void main()
{
	MyIntStack a;
	int s, num;
	cout << "���û����� : ";
	cin >> s;
	a.set(s); cout << "push : ";
	for (int i = 0; i < s; i++) {
		cin >> num;
		a.push(num);
	}
	cout << endl;
	MyIntStack b = a;
	a.pop(num);
	cout << "A ���ÿ��� ���� �� " << num << endl;
	b.pop(num);
	cout << "B ���ÿ��� ���� �� " << num << endl;
}
*/

