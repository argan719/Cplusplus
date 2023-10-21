/*
// 2번
#include<iostream>
#include<string>
using namespace std;
class Student {
private:
	string name;
	string telephone;
public:
	Student(const string n = "", const string t = "");
	string getName() const;
	void setName(const string n);
};
Student::Student(const string n, const string t) {
	name = n;
	telephone = t;
}
string Student::getName() const {
	return name;
}

class Lab {
	string name;
	Student *chief;
	Student *manager;
public:
	Lab(string n = "");
	void setChief(Student *p);
	void setManager(Student *p);
	void print() const;
};
Lab::Lab(const string n) {
	name = n;
	chief = NULL;
	manager = NULL;
}
void Lab::setChief(Student *p) {
	chief = p;
}
void Lab::setManager(Student *p) {
	manager = p;
}
void Lab::print() const {
	cout << name << "연구실" << endl;
	if (chief != NULL)
		cout << "실장은 " << chief->getName() << endl;
	else
		cout << "실장은 현재 없습니다\n";
	if (manager != NULL)
		cout << "총무는 " << manager->getName() << endl;
	else
		cout << "총무는 현재 없습니다\n";
}
int main()
{
	Lab lab("영상 처리");
	Student *p = new Student("김철수", "011-123-5678");
	lab.setChief(p);
	lab.setManager(p);
	lab.print();
	delete p;
}
*/


/*
// 3번
#include<iostream>
using namespace std;
class Seller {
private:
	int A_price;
	int su;
	int myMoney;
public:
	void init(int price, int num, int money) {
		A_price = price;
		su = num;
		myMoney = money;
	}
	int saleApples(int money) {
		int num = money / A_price;
		su -= num;
		myMoney += money;
		return num;
	}
	void sellerDisp() {
		cout << "남은사과: " << su << endl;
		cout << "판매수익: " << myMoney << endl << endl;
	}
};

class Buyer {
	int myMoney;
	int su;
public:
	void init(int money) {
		myMoney = money;
		su = 0;
	}
	void buyApples(Seller &seller, int money) {
		su += seller.saleApples(money);
		myMoney -= money;
	}
	void buy_disp() {
		cout << "현재잔액: " << myMoney << endl;
		cout << "사과개수: " << su << endl << endl;
	}
};

int main(void)
{
	Seller seller;
	seller.init(1000, 20, 0);
	Buyer buyer;
	buyer.init(5000);
	buyer.buyApples(seller, 2000);

	cout << "과일판매자의현황" << endl;
	seller.sellerDisp();
	cout << "과일구매자의현황" << endl;
	buyer.buy_disp();
	return 0;
}
*/



/*
// 12페이지 - 문제풀이
// 1번
#include<iostream>
using namespace std;
class Time {
private:
	int hour;
	int minute;
	int second;
public:
	void set_time(int, int, int);
	int get_hour() { return hour; }
	int get_min() { return minute; }
	int get_second() { return second; }
	bool compare(Time &t);
};
void Time::set_time(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}
bool Time::compare(Time &t)
{
	if (get_hour() == t.get_hour()) {
		if (get_min() == t.get_min()) {
			if (get_second() == t.get_second()) {
				return true;
			}
		}
	}
	return false;
}
void main()
{
	int h, m, s;
	Time t1, t2;
	Time &tt1 = t1, &tt2 = t2;
	Time *pt1 = &t1, *pt2 = &t2;

	cout << "time1 의 시간은 (시간 분 초) ";
	cin >> h; cout << ":"; cin >> m; cout << ":"; cin >> s;
	cout << endl;
	t1.set_time(h, m, s);
	cout << "time2 의 시간은 (시간 분 초) ";
	cin >> h; cout << ":"; cin >> m; cout << ":"; cin >> s;
	cout << endl;
	t2.set_time(h, m, s);

	if (t1.compare(t2)) {
		cout << "두 개의 시간은 같습니다.\n";
	}
	else cout << "두 개의 시간은 다릅니다.\n";
}
*/

/*
// 2번
#include<iostream>
#include<string>
using namespace std;

class Date {
private:
	int year;
	int mon;
	int day;
public:
	Date::Date() {}
	Date::Date(int y, int m, int d) : year(y), mon(m), day(d) {}
	int get_y() { return year; }
	int get_m() { return mon; }
	int get_d() { return day; }
};

class Employee {
private:
	string name;
	Date b;
	Date h;
public:
	Employee(string, Date, Date);
	void print();
};

Employee::Employee(string n, Date  birth, Date start) {
	name = n;
	b = birth;
	h = start;
}
void Employee::print()  {
	cout << "직원의 이름 : " << name << endl;
	cout << "직원의 생일 : " << b.get_y() << "년 " << b.get_m() << "월 " << b.get_d() << "일\n";
	cout << "직원의 입사일 : " << h.get_y() << "년 " << h.get_m() << "월 " << h.get_d() << "일\n";
}

void main()
{
	Date bir(1987, 4, 27);
	Date hir(2011, 2, 05);
	Employee emp("홍길동", bir, hir);
	emp.print();
}
*/

/*
// 3번
#include<iostream>
using namespace std;
class Circle {
	int r;
	double w;
public:
	void set_radius(int radius) {
		r = radius;
	}
	double get_width() {
		return r * r * 3.14;
	}
};

void main()
{
	Circle c[2][3];
	int a = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++) {
			c[i][k].set_radius(a);
			a++;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++) {
			cout << "Circle [" << i << ", " << k << "] 의 면적은 " << c[i][k].get_width() << endl;
		}
	}
}
*/


/*
// 4번
#include<iostream>
#include<string>
#include "Fitness.h"
using namespace std;

void main()
{
	int id;
	char name[15];
	double kg;
	Fitness * f[100];
	int i = 0;
	for (;;i++) {
		cout << "회원번호 : ";
		cin >> id;
		if (id < 0) { cout << endl << endl; break; }
		cout << "이름입력 : ";  cin >> name;
		cout << "체중입력 : ";  cin >> kg;
		f[i] = new Fitness;
		f[i]->init(id, name, kg);
		cout << endl;
	}

	cout << "총 회원수 : " << i  << endl;
	cout << "평균체중 : ";
	double wsum = 0;
	double max = 0;
	int maxi;
	for (int k = 0; k < i; k++) {
		kg = f[k]->weigh();
		wsum += kg;
		if (max < kg) { max = kg; maxi = k; }
	}
	cout << (wsum / i ) << endl;
	cout << "체중이 가장 무거운 회원은\n";
	f[maxi]->prn();
	delete f;
}
*/



/*

// 7페이지 6번
// 스택
// === main.cpp

#include<iostream>
#include<cctype>
#include "stack.h"
int main()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P,\n" << "종료하려면 Q를 입력하십시오.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a': cout << "추가할 주문서의 번호를 입력하십시오: ";
			cin >> po;
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p': if (st.isempty()) cout << "스택이 비어 있습니다.\n";
				  else {
					st.pop(po);
					cout << "#" << po << "주문서를 처리했습니다.\n";
				  }
				  break;

		}
		cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P,\n" << "종료하려면 Q를 입력하십시오.\n";
	}
	cout << "Bye\n";
	return 0;
}

*/


/*
// 14페이지 - 문제풀이
// 5번

#include<iostream>
#include<string>
using namespace std;

class Happy {
private:
	char name[20];  // 이름
	int sum;  // 잔액
	char *list[100];  // 사용 내역
	int index;  // 사용 내역을 저장할 위치 기억
public:
	void init(char *np);  // 초기화
	void use(char *lp, int n);  // 사용함수(사용내역과 금액을 받는다)
	int winner(Happy &br);  // 잔액을 비교하는 맴버함수
	void prn();  // 출력
};
void Happy::init(char *n)
{
	strcpy(name, n);
	sum = 10000;
	index = 0;
}
void Happy::use(char *n, int p)
{
	list[index] = new char[20];
	strcpy(list[index], n);
	sum -= p;
	index++;
}
int Happy::winner(Happy &br)
{
	return (br.sum < sum) ? 1 : 0;
}
void Happy::prn()
{
	cout << "이름 : " << name << endl;
	cout << "잔액 : " << sum << endl;
	cout << "사용내역 : ";
	for (int i = 0; i < index; i++)
		cout << list[i] << "  ";
}

void main()
{
	Happy chul, mtur;
	chul.init("철이");
	mtur.init("머털");
	char buy_chul[20];
	char buy_mtur[20];
	int pay;
	cout << "철이가 돈을 마구씁니다...\n";
	while (1) {
		cout << "구입내역:";
		cin >> buy_chul;
		if (strcmp(buy_chul, "끝") == 0) break;
		cout << "금액입력:";
		cin >> pay;
		chul.use(buy_chul, pay);
	}
	cout << endl;
	cout << "머털이 돈을 마구씁니다...\n";
	while (1) {
		cout << "구입내역:";
		cin >> buy_mtur;
		if (strcmp(buy_mtur, "끝") == 0) break;
		cout << "금액입력:";
		cin >> pay;
		mtur.use(buy_mtur, pay);
	}
	cout << "\n최종승자는?\n";
	if (chul.winner(mtur) == 1) chul.prn();
	else mtur.prn();
}
*/


/*
// 6번
#include<iostream>
#include"stack.h"
using namespace std;
void main()
{
	Stack st;
	customer cus;
	char ch;
	int sum = 0;
	cout << "고객입장: A  고객퇴장: D  종료: Q => ";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a': cout << "입장한 고객의 이름 입력 : ";
			cin >> cus.fullname;
			cout << "고객이 지불할 금액 입력 : ";
			cin >> cus.payment;
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else
				st.push(cus);
			break;
		case 'D':
		case 'd': if (st.isempty()) cout << "스택이 비어 있습니다.\n";
				  else {
			st.pop(cus);  sum += cus.payment;
			cout << "... 지금까지 매출 총 금액은 " << sum << "원입니다.\n";
		}
				  break;

		}
		cout << "\n고객입장: A  고객퇴장: D  종료: Q => ";
	}
	cout << "... 지금까지 매출 총 금액은 " << sum << "원입니다.\n";
}
*/




/*
// 7번  
#include<iostream>
#include "stack.h"
using namespace std;

void main()
{
	int num;
	Employee e;
	string name[50];
	int index = 0;
	Stack st;
	for (;;) {
		cout << "1. 직원입사\n" << "2. 직원리스트\n" << "3. 직원퇴사\n" << "4. 마지막 입사한 직원\n" << "5. 종료\n";
		cout << "==> ";
		cin >> num;
		if (num == 5) { cout << "종료되었습니다."; break; }
		switch (num)
		{
		case 1:
			cout << "입사한 직원의 이름 : ";  cin >> e.name;
			cout << "출생년도 : ";  cin >> e.Bir;
			cout << "입사날짜 : ";  cin >> e.date;
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else
			{
				st.push(e);
				name[index] = e.name;
				index++;
			}
			break;
		case 2:
			cout << "\n== 직원명단 == \n";
			for (int i = 0; i < index; i++)
				cout << name[i] << endl;
			break;
		case 3:
			if (st.isempty()) cout << "스택이 비어 있습니다.\n";
			else {
				st.pop(e);
				cout << e.name << "  " << e.Bir << "  " << e.date << endl;
				cout << "직원이 퇴사했습니다.\n";
			}
			break;
		case 4:
			cout << "마지막으로 입사한 직원은\n";
			e = st.peek();
			cout << e.name << "  " << e.Bir << "  " << e.date << endl;
			cout << "직원입니다.\n";
			break;
		}
		cout << endl;
	}
}
*/
