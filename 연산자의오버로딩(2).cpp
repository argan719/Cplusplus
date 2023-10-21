
/*
// 1번
#include<iostream>
namespace mystd {
	using namespace std;

	// 오버라이딩 - << 뒤에 있는 거랑 맞는 형 찾아서 printf해줌
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
	ostream cout;  // cout 이라는 객체인거임  cout 은 객체임!! ostream이라는 클래스의 객체
}
int main(void) {
	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";  // cout.operator << ("Simple String");
	cout << endl;
	cout << 3.14;
	cout << endl;  // endl는 함수임
	cout << 123;
	endl(cout);
	return 0;
}
*/

/*
// 2번
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
// 3번부터 notion에 필기
// 3번
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
	pos1 << cout;  //pos1.operator << (cout);   주석처리한거는 왼쪽 내용과 주석처리한 내용이 같은 거라는 의미
}					// 이렇게 써도 되고 이렇게 써도 되고
*/

/*
// 4번
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
// 5번
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
	cout << "여행일시 :" << t1 << "화요일\n";
}
*/

/*
// 6번
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
// 7번 

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

	// 내가 작성한 대입연산자
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
// 9번
// === main.cpp
#include<stdio.h>
#include"myin.h"
void main()
{
	char irum[12];
	int nai;
	double ki;

	printf("이름입력:");
	cin >> irum;
	printf("나이입력:");
	cin >> nai;
	printf("키 입력:");
	cin >> ki;
	printf("이름=%s 나이=%d 키=%.2f입니다.\n", irum, nai, ki);
	cin.input("이름입력:", irum);
	cin.input("나이입력:", nai);
}
*/



/*
// 9페이지 - 문제풀이
// 1번
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

	cout << "Aida와 Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;		// operator+()
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;   // 맴버 operator*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0*tosca << endl;

	return 0;
}
*/

/*
// 2번 
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
	cout << "X, Y 좌표 순으로 입력 : ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "X, Y 좌표 순으로 입력 : ";
	cin >> pos2;
	cout << pos2;
}
*/

/*
// 3번
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
		cout << hour << "시간 " << min << "분\n";
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
	Time a(5, 50), b(3, 30), c;  // 5시간 50분  3시간 30분

	c = a + b;
	a.show();
	b.show();
	c.show();

	a++;		// 1분 증가
	a.show();
}
*/

/*   
// 4번 
#include<iostream>
#include<string>
using namespace std;

class San {
private:
	char *name;  // 동적할당 산이름 저장
	int height;  // 산의 높이
public:
	San();  // 디폴트 생성자
	San(const char *np, int h);   // 오버로딩 생성자
	San(const San &br);   // 복사 생성자
	~San();  // 소멸자
	San & operator=(const San &br);  // 대입연산자 맴버함수
	int high();   // 산의 높이를 리턴하는 맴버함수
	void prn();   // 산의 이름과 높이를 출력
};

San::San() {}
San::San(const char *np, int h) {
	name = new char[strlen(np)+1];		// 이렇게 size잡아야함
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
	cout << "이름 : " << name << endl;
	cout << "높이 : " << height << endl;
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
		cout << "산이름 입력 : ";
		cin >> name;
		cout << "높이 입력 : ";
		cin >> h;
		arr[i] = new San(name, h);
	}
	cout << endl << endl;
	sort(arr);
	cout << "높은 산 순서로 출력합니다.\n";
	for (int i = 0; i < 5; i++) {
		arr[i]->prn();
	}
}
*/


/*
// 5번 
#include<iostream>
#include<string>
using namespace std;

class MyString {
private:
	char *str;   // 문자열을 연결할 포인터멤버
	int len;		// 문자열의 길이를 저장
public:
	MyString();		// 디폴트 생성자
	MyString(const char *cp);	// 오버로디드 생성자
	MyString(const MyString &br);  // 복사 생성자
	~MyString();		// 소멸자
	MyString &operator=(const MyString &br);  // 대입연산자 멤버함수
	MyString operator+(const MyString &br);   // 덧셈 연산자
	bool operator>(const MyString &br);  // 관계연산자 멤버함수
	void operator<<(ostream &os);    // 출력연산자 멤버함수
	void operator>>(istream &is);    // 입력연산자 멤버함수
};
ostream &operator<<(ostream &os, MyString &br);	// 출력연산자 일반함수
istream &operator>>(istream &is, MyString &br);   // 입력연산자 일반함수

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
	strcpy(this->str, tmp);		// strcpy는 string에는 못씀 char* 배열에만 사용가능
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
	MyString ary[5];			// 객체배열

	int i;
	cout << "5개의 과일이름 입력 : ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];			// 입력연산자 사용
	}

	cout << "첫번째와 두번째 중 긴 과일이름 : ";
	if (ary[0] > ary[1]) {			// 관계연산자 사용
		cout << ary[0] << endl;		// 출력연산자 사용
	}
	else {
		cout << ary[1] << endl;
	}

	ary[0] = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];	// 덧셈연산자 사용 

	cout << "모든 문자열 출력..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}
	return 0;
}
*/


/*
// 6번
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
	if (person.money < m) cout << "기부할 잔액이 부족합니다ㅠㅠ\n";
	else {
		person.give_money += m; person.money -= m;
	}
}

int main()
{
	Giver chul("철이", 100);
	Giver mtur("머털", 500);
	cout << "기부전 잔액...\n";
	cout << chul << endl;
	cout << mtur << endl;

	char a;
	for (;;) {
		cout << "\n얼마를 기부할까요?\n";
		cout << "철이 : ";  cin >> chul;
		cout << "머털 : "; cin >> mtur;

		cout << endl << endl;
		cout << "기부후 잔액...\n";
		cout << chul << endl;
		cout << mtur << endl;
		cout << endl;
		cout << "계속? ";  cin >> a;
		if (a == 'y' || a == 'Y') continue;
		else break;
	}
	cout << "철이님은 " << chul.get_give() << " 기부하셨습니다~\n";
	cout << "머털님은 " << mtur.get_give() << " 기부하셨습니다~\n";
}
*/

/*
// 7번
#include<iostream>
using namespace std;

class Time {
	int hour;
	int min;
public:
	Time() {}
	Time(int h, int m) : hour(h), min(m) {}
	void operator<<(ostream &os) {
		os << hour << "시간 " << min << "분";
	}
	void operator>>(istream &is) {
		is >> hour >> min;
	}
	Time operator+ (double t) {	  // 객체 + 실수
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
	Time operator+(Time);    // 객체+객체
	friend Time operator+(double t, Time b);  // 실수 + 객체
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
	cout << "# a의 시간 입력 : ";
	cin >> a;

	cout << "a의 시간 => " << a << endl;
	cout << "b의 시간 => " << b << endl;
	cout << "a + b => " << a + b << endl;
	cout << "a + 1.5 => " << a + 1.5 << endl;
	cout << "1.5 + b => " << 1.5 + b << endl;
}
*/
