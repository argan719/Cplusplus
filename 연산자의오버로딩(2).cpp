
/*
// 1��
#include<iostream>
namespace mystd {
	using namespace std;

	// �������̵� - << �ڿ� �ִ� �Ŷ� �´� �� ã�Ƽ� printf����
	class ostream {
	public:
		void operator << (char *str) {
			printf("%s", str);
		}
		void operator << (char str) {
			printf("%c", str);
		}
		void operator << (int num) {
			printf("%d", num);
		}
		void operator << (double e) {
			printf("%g", e);
		}
		void operator << (ostream &(*fp) (ostream & ostm)) {
			fp(*this);
		}
	};
	ostream& endl(ostream &ostm) {
		ostm << "\n";
		//fflush(stdout);
		return ostm;
	}
	ostream cout;  // cout �̶�� ��ü�ΰ���  cout �� ��ü��!! ostream�̶�� Ŭ������ ��ü
}
int main(void) {
	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";  // cout.operator << ("Simple String");
	cout << endl;
	cout << 3.14;
	cout << endl;  // endl�� �Լ���
	cout << 123;
	endl(cout);
	return 0;
}
*/

/*
// 2��
#include<iostream>
namespace mystd {
	using namespace std;

	class ostream {
	public:
		ostream & operator<< (char * str) {
			printf("%s", str);
			return *this;
		}
		ostream & operator<< (char str) {
			printf("%c", str);
			return *this;
		}
		ostream & operator<< (int num) {
			printf("%d", num);
			return *this;
		}
		ostream & operator<< (double e) {
			printf("%g", e);
			return *this;
		}
		ostream & operator<< (ostream& (*fp)(ostream &ostm)) {
			return fp(*this);
		}
	};

	ostream& endl(ostream &ostm) {
		ostm << "\n";
		fflush(stdout);
		return ostm;
	}
	ostream cout;
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;

	cout << 3.14 << endl << 123 << endl;
}
*/


/*
// 3������ notion�� �ʱ�
// 3��
#include<iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void operator<< (ostream &os) {
		os << xpos << "  " << ypos;
	}
};
int main(void)
{
	Point pos1(1, 3);
	pos1 << cout;  //pos1.operator << (cout);   �ּ�ó���ѰŴ� ���� ����� �ּ�ó���� ������ ���� �Ŷ�� �ǹ�
}					// �̷��� �ᵵ �ǰ� �̷��� �ᵵ �ǰ�
*/

/*
// 4��
#include<iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	friend void operator<<(ostream&, const Point&);
};

void operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
}
int main(void)
{
	Point pos1(1, 3);
	cout << pos1;  // operator <<(cout, pos1);
	Point pos2(101, 303);
	cout << pos2;
}
*/

/*
// 5��
#include<iostream>
using namespace std;
class Time {
private:
	int hours;
	int minuts;
public:
	Time(int hours = 0, int minuts = 0) : hours(hours), minuts(minuts)
	{ }
	void operator<< (ostream &os) {
		os << hours << "  " << minuts;
	}
};
ostream &operator<< (ostream &os, Time &br) {
	br << os;   // br.operator<<(os);
	return os;
}
int main(void)
{
	Time t1(1, 30);
	Time t2(2, 20);

	(cout << t1) << t2;
	cout << endl;
	cout << t1 << t2;
	cout << endl;
	cout << "�����Ͻ� :" << t1 << "ȭ����\n";
}
*/

/*
// 6��
#include<iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void operator <<(ostream &os) {
		os << xpos << "  " << ypos;
	}
	void operator >>(istream &is) {
		is >> xpos >> ypos;
	}
};
int main(void)
{
	Point pos1;
	pos1 >> cin;
	pos1 << cout;  //pos1.operator <<(cout);
}
*/


/*
// 7�� 

#include<iostream>
using namespace std;

class First {
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{ }
	void showData() { cout << num1 << ", " << num2 << endl; }
};

class Second {
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{ }
	void showData() { cout << num3 << ", " << num4 << endl; }

	// ���� �ۼ��� ���Կ�����
	Second& operator=(const Second& ref){
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	
};

int main(void)
{
	First A1(111, 222);
	First A2;
	Second B1(333, 444);
	Second B2;

	A2 = A1;
	B2 = B1;   // B2.operator =(B1);
	A2.showData();
	B2.showData();

	First F1, F2;

	F1 = F2 = A1;
	F1.showData();
	F2.showData();

	Second S1, S2;
	S1 = S2 = B1;

	S1.showData();
	S2.showData();
}
*/

/*
// 9��
// === main.cpp
#include<stdio.h>
#include"myin.h"
void main()
{
	char irum[12];
	int nai;
	double ki;

	printf("�̸��Է�:");
	cin >> irum;
	printf("�����Է�:");
	cin >> nai;
	printf("Ű �Է�:");
	cin >> ki;
	printf("�̸�=%s ����=%d Ű=%.2f�Դϴ�.\n", irum, nai, ki);
	cin.input("�̸��Է�:", irum);
	cin.input("�����Է�:", nai);
}
*/



/*
// 9������ - ����Ǯ��
// 1��
// === main.cpp
#include<iostream>
#include "time.h"

int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida�� Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;		// operator+()
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;   // �ɹ� operator*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0*tosca << endl;

	return 0;
}
*/

/*
// 2�� 
#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	void operator<<(ostream &os) {
		os << '[' << xpos << ", " << ypos << "]" << endl;
	}
	void operator>>(istream &is) {
		is >> xpos >> ypos;
	}
};

void operator<<(ostream &os, Point &p) {
	p << os;
}
void operator>> (istream &is, Point &p) {
	p >> is;
}
int main()
{
	Point pos1;
	cout << "X, Y ��ǥ ������ �Է� : ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "X, Y ��ǥ ������ �Է� : ";
	cin >> pos2;
	cout << pos2;
}
*/

/*
// 3��
#include<iostream>
using namespace std;

class Time {
	int hour;
	int min;
public:
	Time() {}
	Time(int h, int m) : hour(h), min(m) {}
	void show()
	{
		cout << hour << "�ð� " << min << "��\n";
	}
	Time operator+ (Time b) {
		Time temp;
		temp.hour = hour + b.hour;
		temp.min = min + b.min;
		if (temp.min > 60) {
			int i;
			for (i = 0;; i++) {
				if (temp.min < 60) break;
				temp.min -= 60;
			}
			temp.hour += i;
		}
		return temp;
	}
	void operator++ (int x) {
		min += 1;
	}
};

int main()
{
	Time a(5, 50), b(3, 30), c;  // 5�ð� 50��  3�ð� 30��

	c = a + b;
	a.show();
	b.show();
	c.show();

	a++;		// 1�� ����
	a.show();
}
*/

/*   
// 4�� 
#include<iostream>
#include<string>
using namespace std;

class San {
private:
	char *name;  // �����Ҵ� ���̸� ����
	int height;  // ���� ����
public:
	San();  // ����Ʈ ������
	San(const char *np, int h);   // �����ε� ������
	San(const San &br);   // ���� ������
	~San();  // �Ҹ���
	San & operator=(const San &br);  // ���Կ����� �ɹ��Լ�
	int high();   // ���� ���̸� �����ϴ� �ɹ��Լ�
	void prn();   // ���� �̸��� ���̸� ���
};

San::San() {}
San::San(const char *np, int h) {
	name = new char[strlen(np)+1];		// �̷��� size��ƾ���
	strcpy(name, np);
	height = h;
}
San::San(const San &br) {
	this->name = new char[strlen(br.name)+1];
	strcpy(this->name, br.name);
	this->height = br.height;
}
San::~San() {
	delete name;
}
San& San:: operator=(const San &br) {
	delete name;
	this->name = new char[strlen(br.name)+1];
	strcpy(this->name, br.name);
	this->height = br.height;
	return *this;
}
int San::high() {
	return height;
}
void San::prn() {
	cout << "�̸� : " << name << endl;
	cout << "���� : " << height << endl;
}
void sort(San *arr[]) {
	San *tmp = new San();
	// select sort
	for (int i = 0; i < 4; i++)
	{		
		for (int k = i+1; k < 5; k++) {
			if (arr[i]->high() < arr[k]->high()) {
				tmp = arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
			}
		}
	}
}

int main()
{
	San *arr[5];
	San tmp;
	char name[20];
	int h;
	for (int i = 0; i < 5; i++)
	{
		cout << "���̸� �Է� : ";
		cin >> name;
		cout << "���� �Է� : ";
		cin >> h;
		arr[i] = new San(name, h);
	}
	cout << endl << endl;
	sort(arr);
	cout << "���� �� ������ ����մϴ�.\n";
	for (int i = 0; i < 5; i++) {
		arr[i]->prn();
	}
}
*/


/*
// 5�� 
#include<iostream>
#include<string>
using namespace std;

class MyString {
private:
	char *str;   // ���ڿ��� ������ �����͸��
	int len;		// ���ڿ��� ���̸� ����
public:
	MyString();		// ����Ʈ ������
	MyString(const char *cp);	// �����ε�� ������
	MyString(const MyString &br);  // ���� ������
	~MyString();		// �Ҹ���
	MyString &operator=(const MyString &br);  // ���Կ����� ����Լ�
	MyString operator+(const MyString &br);   // ���� ������
	bool operator>(const MyString &br);  // ���迬���� ����Լ�
	void operator<<(ostream &os);    // ��¿����� ����Լ�
	void operator>>(istream &is);    // �Է¿����� ����Լ�
};
ostream &operator<<(ostream &os, MyString &br);	// ��¿����� �Ϲ��Լ�
istream &operator>>(istream &is, MyString &br);   // �Է¿����� �Ϲ��Լ�

MyString::MyString() {}
MyString::MyString(const char *cp) {
	this->str = new char[strlen(cp) + 1];
	strcpy(this->str, cp);
	this->len = strlen(str);
}
MyString::MyString(const MyString &br) {
	this->str = new char[br.len + 1];
	strcpy(this->str, br.str);
	this->len = strlen(str);
}
MyString::~MyString() {
	delete str;
}
MyString & MyString::operator=(const MyString &br) {
	delete this->str;
	this->str = new char[br.len+1];
	strcpy(str, br.str);
	this->len = strlen(str);
	return *this;
}
MyString MyString::operator+(const MyString &br) {  
	MyString tmp;
	tmp.str = new char[this->len + br.len+1];
	strcpy(tmp.str, this->str);
	strcat(tmp.str, br.str);
	tmp.len = strlen(tmp.str);
	return tmp;
}
bool MyString::operator>(const MyString &br) {
	return (this->len > br.len) ? true : false;
}
void MyString::operator<<(ostream &os) {
	os << this->str << "(" << this->len << ")";
}
void MyString::operator>>(istream &is) {
	char tmp[100];
	is >> tmp;
	this->str = new char[strlen(tmp)+1];
	strcpy(this->str, tmp);		// strcpy�� string���� ���� char* �迭���� ��밡��
	this->len = strlen(str);
}
ostream & operator<<(ostream &os, MyString &br) {
	br << os;
	return os;
}
istream & operator>>(istream &is, MyString &br) {
	br >> is;
	return is;
}

int main()
{
	MyString ary[5];			// ��ü�迭

	int i;
	cout << "5���� �����̸� �Է� : ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];			// �Է¿����� ���
	}

	cout << "ù��°�� �ι�° �� �� �����̸� : ";
	if (ary[0] > ary[1]) {			// ���迬���� ���
		cout << ary[0] << endl;		// ��¿����� ���
	}
	else {
		cout << ary[1] << endl;
	}

	ary[0] = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];	// ���������� ��� 

	cout << "��� ���ڿ� ���..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}
	return 0;
}
*/


/*
// 6��
#include<iostream>
#include<string>
using namespace std;

class Giver {
	string name;
	int money;
	int give_money;
public:
	Giver() {}
	Giver(string n, int m) : name(n), money(m), give_money(0) {}
	friend ostream& operator<< (ostream &, const Giver&);
	friend void operator>>(istream &, Giver&);
	int get_give() {
		return give_money;
	}

};

ostream & operator<<(ostream &os, const Giver& person) {
	os << person.name << " : " << person.money;
	return os;
}

void operator>> (istream &is, Giver& person) {
	int m;
	is >> m;
	if (person.money < m) cout << "����� �ܾ��� �����մϴ٤Ф�\n";
	else {
		person.give_money += m; person.money -= m;
	}
}

int main()
{
	Giver chul("ö��", 100);
	Giver mtur("����", 500);
	cout << "����� �ܾ�...\n";
	cout << chul << endl;
	cout << mtur << endl;

	char a;
	for (;;) {
		cout << "\n�󸶸� ����ұ��?\n";
		cout << "ö�� : ";  cin >> chul;
		cout << "���� : "; cin >> mtur;

		cout << endl << endl;
		cout << "����� �ܾ�...\n";
		cout << chul << endl;
		cout << mtur << endl;
		cout << endl;
		cout << "���? ";  cin >> a;
		if (a == 'y' || a == 'Y') continue;
		else break;
	}
	cout << "ö�̴��� " << chul.get_give() << " ����ϼ̽��ϴ�~\n";
	cout << "���д��� " << mtur.get_give() << " ����ϼ̽��ϴ�~\n";
}
*/

/*
// 7��
#include<iostream>
using namespace std;

class Time {
	int hour;
	int min;
public:
	Time() {}
	Time(int h, int m) : hour(h), min(m) {}
	void operator<<(ostream &os) {
		os << hour << "�ð� " << min << "��";
	}
	void operator>>(istream &is) {
		is >> hour >> min;
	}
	Time operator+ (double t) {	  // ��ü + �Ǽ�
		Time tmp;
		int h = t / 1;   double m = t - h;
		m = (int)(60 * m);
		tmp.hour = this->hour +h;
		tmp.min = this->min + m;
		if (tmp.min >= 60) {
			int i;
			for (i = 0;;i++) {
				if (tmp.min < 60) break;
				tmp.min = tmp.min - 60;
			}
			tmp.hour += i;
		}
		return tmp;
	}
	Time operator+(Time);    // ��ü+��ü
	friend Time operator+(double t, Time b);  // �Ǽ� + ��ü
};

Time Time::operator+(Time t) {
	Time tmp;
	tmp.hour = this->hour + t.hour;
	tmp.min = this->min + t.min;
	if (tmp.min >= 60) {
		int i;
		for (i = 0;; i++) {
			if (tmp.min < 60) break;
			tmp.min = tmp.min - 60;
		}
		tmp.hour += i;
	}
	return tmp;
}
Time operator+(double t, Time b) {
	Time tmp;
	int h = t / 1;   double m = t - h;
	m = (int)(60 * m);
	tmp.hour = h + b.hour;
	tmp.min = m + b.min;
	if (tmp.min >= 60) {
		int i;
		for (i = 0;; i++) {
			if (tmp.min < 60) break;
			tmp.min = tmp.min - 60;
		}
		tmp.hour += i;
	}
	return tmp;
}
ostream & operator<<(ostream &os, Time &t) {
	t << os;
	return os;
}
void operator>>(istream &is, Time &t) {
	t >> is;
}

int main()
{
	Time a, b(3, 45);
	cout << "# a�� �ð� �Է� : ";
	cin >> a;

	cout << "a�� �ð� => " << a << endl;
	cout << "b�� �ð� => " << b << endl;
	cout << "a + b => " << a + b << endl;
	cout << "a + 1.5 => " << a + 1.5 << endl;
	cout << "1.5 + b => " << 1.5 + b << endl;
}
*/
