/*
// 1��
#include<iostream>
using namespace std;
class Score {
	int kor, eng;
public:
	Score() {
		cout << "������Ʈ�� �����Ǿ����ϴ�." << endl;
	}
	void disp() {
		cout << "����=" << kor << " ����=" << eng << endl;
	}
};

void main()
{
	Score Kim;
	Kim.disp();
}
*/


/*
// 4��
#include<iostream>
using namespace std;
class Score {
	int kor, eng, tot;
public:
	Score(int a = 0, int b = 0) : kor(a), eng(b) {
		calc();
	}
	void calc() {
		tot = kor + eng;
	}
	void set(int c, int d) {
		kor = c;
		eng = d;
		calc();
	}
	void disp() {
		cout << "����=" << tot << endl;
	}
};

void main()
{
	Score * Kim = new Score(90, 95);
	Kim->disp();
	delete Kim;
}
*/

/*
// 5��
#include<iostream>
using namespace std;

class Score {
	int kor, eng;
public:
	Score() {
		cout << "��ü�� �����Ǿ����ϴ�." << endl;
	}
	~Score() {
		cout << "��ü�� �Ҹ�Ǿ����ϴ�." << endl;
	}
};
void main()
{
	Score Kim;
	cout << "�ȳ� ~~\n";
}
*/


/*
// 6��
#include<iostream>
#include<cstring>
using namespace std;
class Score {
	char *name;
	int kor;
public:
	Score(char *ap = "no", int a = 0) {
		name = new char[strlen(ap) + 1];
		strcpy(name, ap);
		kor = a;
	}
	~Score() {
		cout << "�Ҹ��� ȣ��" << endl;
		delete[]name;
	}
	void set(char *ap) {
		if (name != NULL)
			delete[]name;
		name = new char[strlen(ap) + 1];
		strcpy(name, ap);
	}
	void disp() {
		cout << "�̸�=" << name << " ����=" << kor << "��\n";
	}
};

void showdisp() {
	Score Kim("Sally", 90);
	Kim.disp();
}
void main() {
	showdisp();
	showdisp();
	showdisp();
	showdisp();
}
*/


/*
// 7��
#include<iostream>
using namespace std;
class Score {
	int kor, eng;
public:
	Score(int a = 0, int b = 0) :kor(a), eng(b) {
		cout << "������ �ݵ�\n";
	}
	~Score() {
		cout << "�Ҹ��� �ݵ�\n";
	}
	void disp() {
		cout << "����=" << kor << " ����=" << eng << endl;
	}
};

void showDisp() {
	Score Lee(90, 95);
	Lee.disp();
}

void main()
{
	Score Kim;
	showDisp();
	Kim.disp();
}
*/


/*
// 9��
#include<iostream>
#include<string>
using namespace std;
class Point {
	int x, y;
public:
	Point(int a, int b) :x(a), y(b) {
		cout << "����Ʈ ������" << endl;
	}
};

class Rectangle {
	Point p1, p2;
public:
	Rectangle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {
		cout << "rectangle ������ " << endl;
	}
};

int main()
{
	Rectangle(10, 10, 100, 100);
	return 0;
}
*/





/*
// 14������ - ����Ǯ��
// 1��
#include<iostream>
using namespace std;
class Rectangle {
	int x, y;
public:
	Rectangle() {
		x = 0;
		y = 0;
	}
	Rectangle(int x) {
		this->x = x;
		this->y = x;
	}
	Rectangle(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool isSquare() {
		return (x == y) ?  true : false;
	}
};

int main()
{
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1�� ���簢���̴�" << endl;
	if (rect2.isSquare()) cout << "rect2�� ���簢���̴�" << endl;
	if (rect3.isSquare()) cout << "rect3�� ���簢���̴�" << endl;
}
*/

 
/*
// 4��
#include<iostream>
using namespace std;

class AB {
	int a, b;
	double x, y;
public:
	AB() {
		a = 100;
		b = 200;
		cout << "a=" << a << "  b=" << b << endl;
	}
	AB(int a, int b) {
		this->a = a;
		this->b = b;
		cout << "a=" << a << "  b=" << b << endl;

	}
	AB(int a, double b) {
		this->a = a;
		y = b;
		cout << "a=" << a << "  b=" << y << endl;
	}
	AB(double a, double b) {
		x = a;
		y = b;
		cout << "a=" << x << "  b=" << y << endl;
	}
};

void main()
{
	AB();
	AB(10, 210);
	AB(100, 50.5);
	AB(30.6, 60.8);
}
*/


/*
// 5��
#include<iostream>
#include<string>
using namespace std;

class Plane {
	int id;
	string model;
	int passenger;
public:
	Plane() {
		id = 0;
	}
	Plane(int i) {
		id = i;
	}
	Plane(int i, string m) {
		id = i;
		model = m;
	}
	Plane(int i, string m, int p) {
		id = i;
		model = m;
		passenger = p;
	}
	void setModel(string m) {
		model = m;
	}
	void setPassenger(int p) {
		passenger = p;
	}
	void print()
	{
		cout << "�ĺ���ȣ : " << id << endl;
		cout << "�� : " << model << endl;
		cout << "�°��� : " << passenger << endl;
	}
};

int main()
{
	Plane p1, p2(1), p3(2, "B-747"), p4(3, "A-330", 80);
	p1.setModel("A-380");
	p1.setPassenger(60);
	p2.setModel("B-787");
	p2.setPassenger(120);
	p3.setPassenger(140);
	p1.print();
	p2.print();
	p3.print();
	p4.print();
	return 0;
}
*/


// 6��
/*
#include<iostream>
using namespace std;

class Box {
	int id;
	int height;
	int width;
	int volume;
	void getVolume() {
		volume = height * width;
	}
public:
	Box() {}
	Box(int i,int x, int y) {
		id = i;
		height = x;
		width = y;
		getVolume();
	}
	bool empty() {
		return true;
	}
	int get_volume() {
		return volume;
	}
	Box compare(Box box) {
		return (box.get_volume() < volume) ? *this : box;
	}
	int get_id() {
		return id;
	}

};

void main()
{
	Box box;
	Box box1(1,100,20), box2(2,40,10), box3(3,150,30), box4(4,50,80);
	cout << "\n==============================\n";
	cout << "�ڽ� 1 ���Ǵ� : " << box1.get_volume() << endl;
	cout << "�ڽ� 2 ���Ǵ� : " << box2.get_volume() << endl;
	cout << "�ڽ� 3 ���Ǵ� : " << box3.get_volume() << endl;
	cout << "�ڽ� 4 ���Ǵ� : " << box4.get_volume() << endl;
	cout << "==============================\n";
	cout << "�ڽ� " << (box = box4.compare(box3.compare(box1.compare(box2)))).get_id() << "�� ���ǰ� ���� Ů�ϴ� : " << box.get_volume() << endl;
}
*/


/*
// 9��
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
time_t now;
tm *tp;

class SMS {
	string person;
	string text;
public:
	SMS(string p) {
		person = p;
	}
	void setText(string t) {
		text = t;
	}
	void print() {
		time(&now);
		tp = localtime(&now);

		cout << "�۽��� : " << person << endl;
		cout << "�ð� : " << tp->tm_hour << ":" << tp->tm_min << endl;
		cout << "�޽��� : " << text << endl;
	}
	
};

int main()
{
	char answer;
	string person;
	string text;
	for (;;) {
		cout << "�޼����� �����Ͻðڽ��ϱ�? (y/n) : ";
		cin >> answer;
		if (answer != 'y') break;
		else {
			cout << "�۽��� ��ȣ�� �Է��Ͻÿ� : ";
			cin >> person;
			cin.get();
			cout << "�޼��� ������ �Է��Ͻÿ� : ";
			getline(cin, text);
			SMS message(person);
			message.setText(text);
			cout << endl;
			message.print();
			cout << endl;
		}
	}
}
*/

/*
// 10��
#include<iostream>
#include<string>
using namespace std;

class Friends {
	string name;
	string num;
	string tell;
	string address;
public:
	Friends(string num1, string num2, string num3) {
		name = num1;
		num = num2;
		tell = num3;
		address = "�������� ����";
	}
	Friends(string num1, string num2, string num3, string num4) {
		name = num1;
		num = num2;
		tell = num3;
		address = num4;
	}
	void print() {
		cout << endl << endl;
		cout << "����� �̸��� " << name << "�ֹι�ȣ�� " << num << endl;
		cout << "��ȭ��ȣ : " << tell << endl;
		cout << "�ּ� : " << address << endl;
	}
	
};

void main()
{
	string name, num, tell, address;
	cout << "�̸� : ";
	cin >> name;
	cout << "�ֹε�Ϲ�ȣ : ";
	cin >> num;
	cout << "��ȭ��ȣ : ";
	cin >> tell;
	cin.get();
	cout << "�ּ� : ";
	getline(cin,address);
	Friends f(name, num, tell, address);
	f.print();
}
*/

/*
// 12��
#include<iostream>
#include<time.h>
using namespace std;

class EvenRandom {
	int ran_num;
	void even(int r) {
		if (r % 2 == 0) ran_num = r;
		else {
			int a = rand() % 2 + 0;
			if (a == 0) ran_num = r - 1;
			else ran_num = r + 1;
		}
		print(ran_num);
	}
	void random() {
		int r;
		r = rand() % 9 + 2;
		even(r);
	}
public:
	EvenRandom() {
		for (int i = 0; i < 10; i++)
			random();
	}
	void print(int num) {
		cout << num << "  ";
	}
};

int main() {
	cout << "-- 2���� 10������ �������� 10��\n";
	srand(time(NULL));
	EvenRandom er;
}
*/



/*
// 14��
#include<iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int v) {
		value = 0;
		value += v;
	}
	Accumulator &add(int v) {
		value += v;
		return *this;
	}
	int get() {
		return value;
	}
};

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get() << endl;
}
*/

 