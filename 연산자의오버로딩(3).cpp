
/*
// 1번
#include<iostream>
#include<cstdlib>
using namespace std;
class IntArray {
private:
	int *arr;
	int arrlen;
public:
	IntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "범위를 벗어났습니다" << endl;
			exit(1);
		}
		return arr[idx];
	}
	~IntArray() {
		delete[]arr;
	}
};

int main(void) {
	IntArray A(5);
	for (int i = 0; i < 5; i++)
		A.operator[] (i) = (i + 1) * 11;		// A[i]=(i+1)*11;
	for (int i = 0; i < 6; i++)
		cout << A[i] << endl;
}
*/


/*
// 2번 
#include<iostream>
#include<cstdlib>
using namespace std;
class IntArray {
private:
	int *arr;
	int arrlen;
	IntArray(const IntArray & arr) {}
	IntArray & operator=(const IntArray & arr) {}
public:
	IntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "범위를 벗어났습니다" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int getArrLen() const {
		return arrlen;
	}
	~IntArray() {
		delete [] arr;
	}
};
void showAllData(IntArray & ref) {
	int len = ref.getArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;   
}
int main(void)
{
	IntArray A(5);
	for (int i = 0; i < 5; i++)
		A[i] = (i + 1) * 11;
	showAllData(A);
}
*/


/*
// 3번 
#include<iostream>
using namespace std;
class IntArray {
private:
	int *arr;
	int arrlen;

	IntArray(const IntArray& arr) {}
	IntArray& operator=(const IntArray& arr) {}
public:
	IntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[] (int idx) {
		cout << "const 아님 " << endl;
		if (idx < 0 || idx >= arrlen) {
			cout << "범위를 벗어났습니다" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int& operator[] (int idx) const {
		cout << "const 맞음 " << endl;
		if (idx < 0 || idx >= arrlen) {
			cout << "범위를 벗어났습니다" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int getArrLen() const {
		return arrlen;
	}
	~IntArray() {
		delete[]arr;
	}
};
void showAllData(const IntArray& ref) {
	int len = ref.getArrLen();

	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;
}
int main(void)
{
	IntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 10;
	for (int i = 0; i < 5; i++)
		cout << arr[i] << "  ";
	cout << endl;
	showAllData(arr);
	return 0;
}
*/

/*
// 4번
// 4-1
#include<iostream>
#include<cstdlib>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream & operator<<(ostream & os, const Point& pos);
};
ostream &operator<< (ostream &os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
} 

class PointArray {
private:
	Point *arr;
	int arrlen;

	PointArray(const PointArray& arr) { }
	PointArray& operator=(const PointArray& arr) { }
public:
	PointArray(int len) : arrlen(len) {
		arr = new Point[len];
	}
	Point& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "범위를 벗어났습니다" << endl;
			exit(1);
		}
		return arr[idx];
	}
	Point operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "범위를 벗어났습니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
	int getArrLen() const {
		return arrlen;
	}
	~PointArray() {
		delete[]arr;
	}
};

int main(void)
{
	PointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);
	for (int i = 0; i < arr.getArrLen(); i++)
		cout << arr[i];
}
*/



/*
// 4-2 
#include<iostream>
#include<cstdlib>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream& operator<< (ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

typedef Point * POINT_PTR;

class PointArray {
private:
	POINT_PTR * arr;    // 그럼 이거는 지금 * 두개 사용?
	int arrlen;

	PointArray(const PointArray& arr) { }
	PointArray& operator=(const PointArray& arr) { }
public:
	PointArray(int len) : arrlen(len) {
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "범위를 벗어났습니다" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen)
		{
			cout << "범위를 벗어났습니다" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const {
		return arrlen;
	}
	PointArray() {
		delete[]arr;
	}
};

int main(void)
{
	PointArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << *(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];
}
*/

/*
// 5번
#include<iostream>
using namespace std;
class Number {
private:
	int num;
public:
	Number(int n) : num(n) { }
	void showData() { cout << num << endl; }
	Number * operator->() {
		return this;
	}
	Number & operator*() {
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.showData();
	(num.operator*()) = 30;  //(*num)=30;
	num.operator->()->showData();  // num->showData();
	(*num).showData();
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
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
		cout << "Point 객체 생성" << endl;
	}
	~Point() {
		cout << "Point 객체 소멸" << endl;
	}
	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr {
private:
	Point * posptr;
public:
	SmartPtr(Point * ptr) : posptr(ptr)
	{ }
	Point& operator*() const {
		return *posptr;
	}
	Point* operator->() const {
		return posptr;
	}
	SmartPtr() {
		delete posptr;
	}
};

int main(void)
{
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->setPos(10, 20);
	sptr2->setPos(30, 40);
	sptr3->setPos(50, 60);
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}
*/

/*
// 7번
#include<iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	Point operator+(const Point& pos) const {
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}
	friend ostream& operator<< (ostream& os, const Point& pos);
};
ostream& operator<< (ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class Adder {
public: 
	int operator()(const int &n1, const int &n2) {
		return n1 + n2;
	}
	double operator()(const double &e1, const double &e2) {
		return e1 + e2;
	}
	Point operator()(const Point &pos1, const Point &pos2) {
		return pos1 + pos2;
	}
};

int main(void)
{
	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9));
}
*/


/*
// 8번  - 공부하고 notion에 필기
#include<iostream>
using namespace std;
class SortRule {
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule {		// 오름차순
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2) 
			return true;
		else 
			return false;
	}
};
class DescendingSort : public SortRule {	// 내림차순
public:
	bool operator()(int num1, int num2) const {
		if (num1 < num2)
			return true;
		else
			return false;
	}
};
class DataStorage {			// for int data
private:
	int *arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen) {
		arr = new int[MAX_LEN];
	}
	void addData(int num) {
		if (MAX_LEN <= idx) {
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[idx++] = num;
	}
	void showAllData() {
		for (int i = 0; i < idx; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	void sortData(const SortRule & functor) {
		for (int i = 0; i < (idx - 1); i++) {	// Bubble sort
			for (int j = 0; j < (idx - 1) - i; j++) {	
				if (functor(arr[j], arr[j + 1])) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);
	storage.addData(40);
	storage.addData(30);
	storage.addData(50);
	storage.addData(20);
	storage.addData(10);

	storage.sortData(AscendingSort());
	storage.showAllData();

	storage.sortData(DescendingSort());
	storage.showAllData();
	return 0;
}
*/


/*
// 9번
#include<iostream>
using namespace std;
class Number {
private:
	int num;
public:
	Number(int n = 0) : num(n) {
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number &ref) {
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	void showNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;
	num.operator=(Number(30));	 // num=30;
	num.showNumber();
	return 0;
}
*/


/*
// 10번  
#include<iostream>
using namespace std;

class Number {
private:
	int num;
public:
	Number(int n = 0) : num(n) {
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(int ref) {
		cout << "operator=()" << endl;
		num = ref;
		return *this;
	}
	//operator int() {		// 형 변환 연산자의 오버로딩
	//	return num;
	//}
	Number operator+(int n) {
		Number tmp;
		tmp.num = this->num + n;
		return tmp;
	}
	void showNumber() { cout << num << endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;
	num1.showNumber();

	Number num2 = num1 + 20;
	num2.showNumber();
	return 0;
}
*/


/*
// 11번 
#include<iostream>
using namespace std;

class Time {
	int hour;
	int min;
public:
	Time(int hour = 0, int min = 0) {
		this->hour = hour;
		this->min = min;
	}
	Time(double t) {
		cout << "생성자 호출";
		hour = int(t);
		min = int((t - hour)*60.0);
	}
	//Time& operator=(double t) {
	//	cout << "  =대입연산 호출  ";
	//	this->hour = (int)t;
	//	this->min = int((t - hour)*60.0);
	//	return *this;
	//}
	//operator double() {		// 매개변수와 리턴형이 없다.
	//	cout << "     형변환호출";
	//	double temp;
	//	temp = hour + min / 60.0;
	//	return temp;			// 리턴형은 없지만 값은 리턴해야 한다.
	//}
	friend ostream& operator<<(ostream &os, Time t);
};

ostream& operator<< (ostream& os, Time t)
{
	os << t.hour << "시간 " << t.min << "분";
	return os;
}
int main()
{
	Time t1(4.5), t2;
	t1 = 3.5;
	t1 = t1 + 5;
	cout << t1 << endl;

	t2 = 1.5;
	t2 = 1.5 + t1;
	cout << t2 << endl;
}
*/


/*
// 문제풀이
// 1번
#include<iostream>
using namespace std;
class Array {
private:
	int len;
	int *arr;
public:
	Array(int n) : len(n) {
		arr = new int[len];
		for (int i = 0; i < len; i++) {
			arr[i] = 0;
		}
	}
	~Array() {
		delete arr;
	}
	int& operator[](int idx) {
		if (len <= idx) {
			cout << "더 이상 저장이 불가능합니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
	friend ostream& operator<<(ostream&, const Array&);

	bool operator==(const Array &a) {
		int max, i;
		(this->len > a.len) ? max = this->len : max = a.len;
		for (i = 0; i < max; i++) {
			if (this->arr[i] != a.arr[i]) return 0;
		}
		if (i == max) return 1;
	}
	bool operator!=(const Array &a) {
		int max, i;
		(this->len > a.len) ? max = this->len : max = a.len;
		for (i = 0; i < max; i++) {
			if (this->arr[i] != a.arr[i]) return 1;
		}
		if (i == max) return 0;
	}
	void operator=(const Array &a) {
		delete this->arr;
		this->arr = new int[a.len];
		for (int i = 0; i < this->len; i++) {
			this->arr[i] = a.arr[i];
		}
		this->len = a.len;
	}
};

ostream& operator<<(ostream& os, const Array& a) {
	for (int i = 0; i < a.len; i++)
	{
		os << a.arr[i] << " ";
	}
	return os;
}
int main()
{
	Array a1(10), a2(10), a3(10);

	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;

	a2[0] = 1;
	a2[1] = 2;
	a2[2] = 3;
	a2[3] = 4;

	a3 = a1;
	a3[3] = 5;
	cout << "a1 배열은 : ";
	cout << a1 << endl;
	cout << "a2 배열은 : ";
	cout << a2 << endl;
	cout << "a3 배열은 : ";
	cout << a3 << endl;
	cout << "출력 연산자 >>을 오버로딩 : ";
	cout << a1 << endl;
	cout << "a1 == a2 을 오버로딩 : ";
	cout << (a1 == a2) << endl;
	cout << "a1 != a3 을 오버로딩 : ";
	cout << (a1 != a3) << endl;
	cout << "a3 = a1 을 오버로딩 : ";
	a3 = a1;
	cout << a3 << endl;
}
*/

/*
// string 클래스를 내가 직접 구현해봄
// 2번
#include<iostream>
#include<string>
using namespace std;

class String {
	char * text;
public:
	String() { text = NULL; }
	String(char *s) {
		text = new char[strlen(s)+1];
		strcpy(text, s);
	}
	String & operator+(String &a) {
		String tmp;
		tmp.text = new char[strlen(text) + strlen(a.text) + 1];
		strcpy(tmp.text, text);
		strcat(tmp.text, a.text);
		return tmp;
	}
	bool operator!() {
		if (text == NULL) return true;
		else false;
	}
	bool operator==(String &a) {
		if (strcmp(text,a.text)==0) return true;
		else return false;
	}
	bool operator!=(String &a) {
		if (strcmp(text, a.text) == 0) return false;
		else return true;
	}
	bool operator<(String &a) {
		if (strcmp(text, a.text) == -1) return true;
		else return false;
	}
	bool operator>(String &a) {
		if (strcmp(text, a.text) == 1) return true;
		else return false;
	}
	bool operator<=(String &a) {
		if (strcmp(text, a.text) == 1) return false;
		else return true;
	}
	bool operator>=(String &a) {
		if (strcmp(text, a.text) == -1) return false;
		else return true;
	}

	void print()
	{
		cout << text << endl;
	}
};

int main()
{
	String s1("Hello ");
	String s2("World!");
	String s3 = s1 + s2;
	String s4;
	String s5("Hello ");
	s1.print();
	s2.print();
	s3.print();

	cout << "String s4 : ";
	cout << (!s4) << endl;

	cout << "s1(Hello) == s5(Hello) : ";
	cout << (s1 == s5) << endl;
	cout << "s1(Hello) != s5(Hello) : ";
	cout << (s1 != s5) << endl;
	cout << "s1(Hello) < s2(World!) : ";
	cout << (s1 < s2) << endl;
	cout << "s1(Hello) > s2(World!) : ";
	cout << (s1 > s2) << endl;
	cout << "s1(Hello) <= s2(World!) : ";
	cout << (s1 <= s2) << endl;
	cout << "s1(Hello) >= s2(World!) : ";
	cout << (s1 >= s2) << endl;
	return 0;
}
*/

/*
// 3번
#include<iostream>
using namespace std;

class Date {
private:
	int year;
	int mon;
	int day;
public:
	Date() {}
	Date(int y, int m, int d) : year(y), mon(m), day(d) {}
	Date operator++(int x) {
		Date tmp;
		tmp.year = year;
		tmp.mon = mon;
		tmp.day = day;
		day = day + 1;
		return tmp;
	}
	Date operator--() {
		day = day - 1;
		return *this;
	}
	friend void operator<<(ostream &, Date &);
};

void operator<<(ostream &os, Date &a)
{
	os << a.year << "년" << a.mon << "월" << a.day << "일\n";
}

int main()
{
	Date d(1987, 4, 27);
	cout << d;
	cout << "++ 연산자 : ";   // ++은 후위로 --는 전위로 해보기 
	cout << d++;
	cout << "-- 연산자 : ";
	cout << --d;
	cout << "-- 연산자 : ";
	cout << --d;


	return 0;
}
*/

/*
 //4번부터 끝까지 문제 마저 다 풀어오기
// 4번
#include<iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h=0, int m=0, int s=0) : hour(h), min(m), sec(s) {}
	Time& operator+(int se) {
		Time tmp;
		tmp.hour = this->hour;
		tmp.min = this->min;
		tmp.sec = this->sec;
		int m = se / 60;
		int s = se % 60;
		tmp.min += m;
		tmp.sec += s;
		if (tmp.min > 60) {
			for (;;) {
				tmp.min = tmp.min - 60;
				tmp.hour += 1;
				if (tmp.min < 60) break;
			}
		}
		return tmp;
	}
	Time & operator-(int se) {
		Time tmp;
		tmp.hour = this->hour;
		tmp.min = this->min;
		tmp.sec = this->sec;
		int m = se / 60;
		int s = se % 60;
		tmp.min -= m;
		tmp.sec -= s;
		if (tmp.min < 0) {
			tmp.hour -= 1;
			tmp.min += 60;
		}
		if (tmp.sec < 0) {
			tmp.min -= 1;
			tmp.sec += 60;
		}
		return tmp;
	}
	bool operator<(Time &a) {
		if (this->hour < a.hour) return 1;
		else if (this->hour > a.hour) return 0;
		else {
			if (this->min < a.min) return 1;
			else if (this->min > a.min) return 0;
			else {
				if (this->sec < a.sec) return 1;
				else return 0;
			}
		}
	}
	bool operator>(Time &a) {
		if (this->hour > a.hour) return 1;
		else if (this->hour < a.hour) return 0;
		else {
			if (this->min > a.min) return 1;
			else if (this->min < a.min) return 0;
			else {
				if (this->sec > a.sec) return 1;
				else return 0;
			}
		}
	}
	void display()
	{
		cout << hour << " : " << min << " : " << sec << endl;
	}
	friend void operator>> (istream&, Time &);

};

void operator>>(istream &is, Time &a) {
	int time;
	is >> time;
	a.min = time / 60;
	a.sec = time % 60;
	if (a.min > 60) {
		for (;;) {
			a.min -= 60;
			a.hour += 1;
			if (a.min < 60) break;
		}
	}
}
int main()
{
	Time start(1, 0, 0);
	cout << "end = start + 1000" << endl;
	Time end = start + 1000;   // 1000초 후
	end.display();
	cout << "end = end - 500" << endl;
	end = end - 500;
	end.display();
	bool temp = start < end;
	cout << "start < end : " << temp << endl;
	temp = start > end;
	cout << "start > end : " << temp << endl;
	Time t;
	cout << "cin>> ";
	cin >> t;
	cout << "cout<< ";
	t.display();

	return 0;
}
*/

/*
// 5번
#include<iostream>
using namespace std;

class Fraction {
private:
	int parent;
	int child;
public:
	Fraction() {}
	Fraction(int a, int b) : child(a), parent(b) {}
	Fraction& operator+ (Fraction &a) {
		Fraction tmp;
		if (this->parent != a.parent) {
			int p = this->parent * a.parent;
			int thisc = this->child * a.parent;
			int ac = a.child * this->parent;
			tmp.parent = p;
			tmp.child = thisc + ac;
		}
		else {
			tmp.parent = this->parent;
			tmp.child = this->child + a.child;
		}
		return tmp;
	}

	void display()
	{
		cout << child << "/" << parent << endl;
	}
};

int main()
{
	Fraction a(3, 6);
	Fraction b(1, 8);
	Fraction c;
	c = a + b;
	cout << "a = ";
	a.display();
	cout << "b = ";
	b.display();
	cout << "a + b = ";
	c.display();
	return 0;
}
*/


/*
// 6번
#include<iostream>
using namespace std;
class Set {
private:
	int arr[100];
	int idx = 0;
public:
	Set() {}
	void operator+(int value) {
		int i;
		for (i = 0; i < idx; i++)
		{
			if (arr[i] == value) {
				cout << "중복입니다.\n"; break;
			}
		}
		if (idx == i) arr[idx++] = value;
	}
	void operator-(int value) {
		int i;
		for (i = 0; i < idx; i++)
		{
			if (arr[i] == value) {
				for (int k = i; k < idx-1; k++) {
					arr[k] = arr[k + 1];
				}
				idx--;
				break;
			}
		}
		//if (i == idx) cout << "삭제할 수 없습니다.\n";
	}
	void display() {
		cout << '{';
		for (int i = 0; i < idx; i++) {
			cout << arr[i] << ", ";
		}
		cout << "}\n";
	}
	Set& operator|(Set &a) {
		Set tmp;
		int k;
		for (int i = 0; i < idx; i++) {
			tmp.arr[i] = this->arr[i];
			tmp.idx++;
		}
		for (int i = 0; i < a.idx; i++) {
			for (k = 0; k < tmp.idx; k++) {
				if (a.arr[i] == tmp.arr[k]) break;
			}
			if (k == tmp.idx) tmp.arr[tmp.idx++] = a.arr[i];
		}
		return tmp;
	}
	Set& operator&(Set &a) {
		Set tmp;
		for (int i = 0; i < this->idx; i++) {
			for (int k = 0; k < a.idx; k++) {
				if (this->arr[i] == a.arr[k]) {
					tmp.arr[tmp.idx++] = this->arr[i]; break;
				}
			}
		}
		return tmp;
	}
	bool operator==(Set &a) {
		if (this->idx == a.idx) {
			int k, i;
			for (k = 0; k < this->idx; k++) {
				for (i = 0; i < a.idx; i++) {
					if (this->arr[k] == a.arr[i]) break;
				}
				if (i == a.idx) return false;
			}
			if (k == this->idx) return true;
		}
		return false;
	}
	friend void operator<< (ostream&, Set&);
	friend void operator>>(istream&, Set&);
};
void operator<<(ostream & os, Set &a) {
	os << '{';
	for (int i = 0; i < a.idx; i++) {
		os << a.arr[i] << ", ";
	}
	os << '}' << endl;
}
void operator>>(istream& is, Set &a) {
	int num;
	is >> num;
	a + num;
}
int main()
{
	Set A, B, C;

	cout << "집합 A의 원소는 : " << endl;
	A + 3;
	A.display();
	A + 4;
	A.display();
	A + 4;
	A.display();
	A - 4;
	A.display();
	A + 4;
	A.display();


	cout << "집합 B의 원소는 : " << endl;
	B + 3;
	B.display();
	B + 4;
	B.display();
	B + 5;
	B.display();
	
	
	cout << "집합 A와 B의 합집합 : " << endl;

	C = A | B;
	C.display();
	
	cout << "집합 A와 B의 교집합 : " << endl;
	C = A & B;
	C.display();

	cout << "집합 A와 B의 ==연산자 : " << endl;
	bool tmp = A == B;
	if (tmp == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	cout << "집합 A의 <<연산자 : " << endl;
	cout << A;
	cout << "집합 A의 >>연산자 : " << endl;
	cin >> A;
	A.display();
	
	return 0;
}
*/


/*
// 7번
#include<iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point() {}
	Point(int x, int y) : xpos(x), ypos(y) {}
	void display() {
		cout << '(' << xpos << ", " << ypos << ')' << endl;
	}
	Point operator+(Point &a) {
		Point tmp;
		tmp.xpos = this->xpos + a.xpos;
		tmp.ypos = this->ypos + a.ypos;
		return tmp;
	}
	Point operator-(Point &a) {
		Point tmp;
		tmp.xpos = this->xpos - a.xpos;
		tmp.ypos = this->ypos - a.ypos;
		return tmp;
	}
};

int main()
{
	Point p1(100, 200);
	Point p2(200, 300);
	Point p3;

	cout << "p1 = ";
	p1.display();
	cout << "p2 = ";
	p2.display();

	p3 = p1 + p2;
	cout << "p1 + p2 = ";
	p3.display();
	p3 = p1 - p2;
	cout << "p1 - p2 = ";
	p3.display();

	return 0;
}
*/


/*
// 8번
#include<iostream>
using namespace std;
typedef struct symbol {
	string name;
	int num;
}str;

class SymbolTable {
private:
	int idx = 0;
	str arr[100];
public:
	SymbolTable() {}
	void add(string s, int n) {
		arr[idx].name = s;
		arr[idx++].num = n;
	}
	void del(string s) {
		for (int i = 0; i < idx; i++) {
			if (arr[i].name == s) {
				for (int k = i; k < idx - 1; k++)
					arr[k] = arr[k + 1];
				idx--;
				break;
			}
		}
	}
	int operator[](string s) {
		for (int i = 0; i < idx; i++) {
			if (arr[i].name == s) return arr[i].num;
		}
		return 0;
	}
};

int main()
{
	SymbolTable table;
	table.add("house", 100);
	table.add("mouse", 200);
	table.add("korea", 300);
	table.del("mouse");
	cout << table["house"] << endl;
	return 0;
}
*/

/*
// 9번
#include<iostream>
#include<string>
using namespace std;
class Employee {
private:
	string name;
	int salary;
public:
	Employee(string n, int s) : name(n), salary(s) {}
	operator int() {
		return salary;
	}
	void display() {
		cout << "Name : " << name << endl;
		cout << "Salary : " << salary << endl;
	}
};

int main()
{
	Employee e("홍길동", 100);
	int salary = (int)e;  // salary에 100이 저장된다

	e.display();
	cout << "int salary = " << salary << endl;

	return 0;
}
*/

