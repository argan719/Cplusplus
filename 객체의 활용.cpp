/*
// 2��
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
	cout << name << "������" << endl;
	if (chief != NULL)
		cout << "������ " << chief->getName() << endl;
	else
		cout << "������ ���� �����ϴ�\n";
	if (manager != NULL)
		cout << "�ѹ��� " << manager->getName() << endl;
	else
		cout << "�ѹ��� ���� �����ϴ�\n";
}
int main()
{
	Lab lab("���� ó��");
	Student *p = new Student("��ö��", "011-123-5678");
	lab.setChief(p);
	lab.setManager(p);
	lab.print();
	delete p;
}
*/


/*
// 3��
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
		cout << "�������: " << su << endl;
		cout << "�Ǹż���: " << myMoney << endl << endl;
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
		cout << "�����ܾ�: " << myMoney << endl;
		cout << "�������: " << su << endl << endl;
	}
};

int main(void)
{
	Seller seller;
	seller.init(1000, 20, 0);
	Buyer buyer;
	buyer.init(5000);
	buyer.buyApples(seller, 2000);

	cout << "�����Ǹ�������Ȳ" << endl;
	seller.sellerDisp();
	cout << "���ϱ���������Ȳ" << endl;
	buyer.buy_disp();
	return 0;
}
*/



/*
// 12������ - ����Ǯ��
// 1��
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

	cout << "time1 �� �ð��� (�ð� �� ��) ";
	cin >> h; cout << ":"; cin >> m; cout << ":"; cin >> s;
	cout << endl;
	t1.set_time(h, m, s);
	cout << "time2 �� �ð��� (�ð� �� ��) ";
	cin >> h; cout << ":"; cin >> m; cout << ":"; cin >> s;
	cout << endl;
	t2.set_time(h, m, s);

	if (t1.compare(t2)) {
		cout << "�� ���� �ð��� �����ϴ�.\n";
	}
	else cout << "�� ���� �ð��� �ٸ��ϴ�.\n";
}
*/

/*
// 2��
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
	cout << "������ �̸� : " << name << endl;
	cout << "������ ���� : " << b.get_y() << "�� " << b.get_m() << "�� " << b.get_d() << "��\n";
	cout << "������ �Ի��� : " << h.get_y() << "�� " << h.get_m() << "�� " << h.get_d() << "��\n";
}

void main()
{
	Date bir(1987, 4, 27);
	Date hir(2011, 2, 05);
	Employee emp("ȫ�浿", bir, hir);
	emp.print();
}
*/

/*
// 3��
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
			cout << "Circle [" << i << ", " << k << "] �� ������ " << c[i][k].get_width() << endl;
		}
	}
}
*/


/*
// 4��
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
		cout << "ȸ����ȣ : ";
		cin >> id;
		if (id < 0) { cout << endl << endl; break; }
		cout << "�̸��Է� : ";  cin >> name;
		cout << "ü���Է� : ";  cin >> kg;
		f[i] = new Fitness;
		f[i]->init(id, name, kg);
		cout << endl;
	}

	cout << "�� ȸ���� : " << i  << endl;
	cout << "���ü�� : ";
	double wsum = 0;
	double max = 0;
	int maxi;
	for (int k = 0; k < i; k++) {
		kg = f[k]->weigh();
		wsum += kg;
		if (max < kg) { max = kg; maxi = k; }
	}
	cout << (wsum / i ) << endl;
	cout << "ü���� ���� ���ſ� ȸ����\n";
	f[maxi]->prn();
	delete f;
}
*/



/*

// 7������ 6��
// ����
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
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n" << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a': cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p': if (st.isempty()) cout << "������ ��� �ֽ��ϴ�.\n";
				  else {
					st.pop(po);
					cout << "#" << po << "�ֹ����� ó���߽��ϴ�.\n";
				  }
				  break;

		}
		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n" << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "Bye\n";
	return 0;
}

*/


/*
// 14������ - ����Ǯ��
// 5��

#include<iostream>
#include<string>
using namespace std;

class Happy {
private:
	char name[20];  // �̸�
	int sum;  // �ܾ�
	char *list[100];  // ��� ����
	int index;  // ��� ������ ������ ��ġ ���
public:
	void init(char *np);  // �ʱ�ȭ
	void use(char *lp, int n);  // ����Լ�(��볻���� �ݾ��� �޴´�)
	int winner(Happy &br);  // �ܾ��� ���ϴ� �ɹ��Լ�
	void prn();  // ���
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
	cout << "�̸� : " << name << endl;
	cout << "�ܾ� : " << sum << endl;
	cout << "��볻�� : ";
	for (int i = 0; i < index; i++)
		cout << list[i] << "  ";
}

void main()
{
	Happy chul, mtur;
	chul.init("ö��");
	mtur.init("����");
	char buy_chul[20];
	char buy_mtur[20];
	int pay;
	cout << "ö�̰� ���� �������ϴ�...\n";
	while (1) {
		cout << "���Գ���:";
		cin >> buy_chul;
		if (strcmp(buy_chul, "��") == 0) break;
		cout << "�ݾ��Է�:";
		cin >> pay;
		chul.use(buy_chul, pay);
	}
	cout << endl;
	cout << "������ ���� �������ϴ�...\n";
	while (1) {
		cout << "���Գ���:";
		cin >> buy_mtur;
		if (strcmp(buy_mtur, "��") == 0) break;
		cout << "�ݾ��Է�:";
		cin >> pay;
		mtur.use(buy_mtur, pay);
	}
	cout << "\n�������ڴ�?\n";
	if (chul.winner(mtur) == 1) chul.prn();
	else mtur.prn();
}
*/


/*
// 6��
#include<iostream>
#include"stack.h"
using namespace std;
void main()
{
	Stack st;
	customer cus;
	char ch;
	int sum = 0;
	cout << "������: A  ������: D  ����: Q => ";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a': cout << "������ ���� �̸� �Է� : ";
			cin >> cus.fullname;
			cout << "���� ������ �ݾ� �Է� : ";
			cin >> cus.payment;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(cus);
			break;
		case 'D':
		case 'd': if (st.isempty()) cout << "������ ��� �ֽ��ϴ�.\n";
				  else {
			st.pop(cus);  sum += cus.payment;
			cout << "... ���ݱ��� ���� �� �ݾ��� " << sum << "���Դϴ�.\n";
		}
				  break;

		}
		cout << "\n������: A  ������: D  ����: Q => ";
	}
	cout << "... ���ݱ��� ���� �� �ݾ��� " << sum << "���Դϴ�.\n";
}
*/




/*
// 7��  
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
		cout << "1. �����Ի�\n" << "2. ��������Ʈ\n" << "3. �������\n" << "4. ������ �Ի��� ����\n" << "5. ����\n";
		cout << "==> ";
		cin >> num;
		if (num == 5) { cout << "����Ǿ����ϴ�."; break; }
		switch (num)
		{
		case 1:
			cout << "�Ի��� ������ �̸� : ";  cin >> e.name;
			cout << "����⵵ : ";  cin >> e.Bir;
			cout << "�Ի糯¥ : ";  cin >> e.date;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
			{
				st.push(e);
				name[index] = e.name;
				index++;
			}
			break;
		case 2:
			cout << "\n== ������� == \n";
			for (int i = 0; i < index; i++)
				cout << name[i] << endl;
			break;
		case 3:
			if (st.isempty()) cout << "������ ��� �ֽ��ϴ�.\n";
			else {
				st.pop(e);
				cout << e.name << "  " << e.Bir << "  " << e.date << endl;
				cout << "������ ����߽��ϴ�.\n";
			}
			break;
		case 4:
			cout << "���������� �Ի��� ������\n";
			e = st.peek();
			cout << e.name << "  " << e.Bir << "  " << e.date << endl;
			cout << "�����Դϴ�.\n";
			break;
		}
		cout << endl;
	}
}
*/
