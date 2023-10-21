/*
// 1번
#include<iostream>
using namespace std;
class Score {
	int kor, eng;
public:
	Score() {
		cout << "오브젝트가 생성되었습니다." << endl;
	}
	void disp() {
		cout << "국어=" << kor << " 영어=" << eng << endl;
	}
};

void main()
{
	Score Kim;
	Kim.disp();
}
*/


/*
// 4번
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
		cout << "총점=" << tot << endl;
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
// 5번
#include<iostream>
using namespace std;

class Score {
	int kor, eng;
public:
	Score() {
		cout << "객체가 생성되었습니다." << endl;
	}
	~Score() {
		cout << "객체가 소멸되었습니다." << endl;
	}
};
void main()
{
	Score Kim;
	cout << "안녕 ~~\n";
}
*/


/*
// 6번
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
		cout << "소멸자 호출" << endl;
		delete[]name;
	}
	void set(char *ap) {
		if (name != NULL)
			delete[]name;
		name = new char[strlen(ap) + 1];
		strcpy(name, ap);
	}
	void disp() {
		cout << "이름=" << name << " 국어=" << kor << "점\n";
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
// 7번
#include<iostream>
using namespace std;
class Score {
	int kor, eng;
public:
	Score(int a = 0, int b = 0) :kor(a), eng(b) {
		cout << "생성자 콜됨\n";
	}
	~Score() {
		cout << "소멸자 콜됨\n";
	}
	void disp() {
		cout << "국어=" << kor << " 영어=" << eng << endl;
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
// 9번
#include<iostream>
#include<string>
using namespace std;
class Point {
	int x, y;
public:
	Point(int a, int b) :x(a), y(b) {
		cout << "포인트 생성자" << endl;
	}
};

class Rectangle {
	Point p1, p2;
public:
	Rectangle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {
		cout << "rectangle 생성자 " << endl;
	}
};

int main()
{
	Rectangle(10, 10, 100, 100);
	return 0;
}
*/





/*
// 14페이지 - 문제풀이
// 1번
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

	if (rect1.isSquare()) cout << "rect1은 정사각형이다" << endl;
	if (rect2.isSquare()) cout << "rect2는 정사각형이다" << endl;
	if (rect3.isSquare()) cout << "rect3은 정사각형이다" << endl;
}
*/

 
/*
// 4번
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
// 5번
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
		cout << "식별번호 : " << id << endl;
		cout << "모델 : " << model << endl;
		cout << "승객수 : " << passenger << endl;
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


// 6번
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
	cout << "박스 1 부피는 : " << box1.get_volume() << endl;
	cout << "박스 2 부피는 : " << box2.get_volume() << endl;
	cout << "박스 3 부피는 : " << box3.get_volume() << endl;
	cout << "박스 4 부피는 : " << box4.get_volume() << endl;
	cout << "==============================\n";
	cout << "박스 " << (box = box4.compare(box3.compare(box1.compare(box2)))).get_id() << "의 부피가 가장 큽니다 : " << box.get_volume() << endl;
}
*/


/*
// 9번
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

		cout << "송신자 : " << person << endl;
		cout << "시각 : " << tp->tm_hour << ":" << tp->tm_min << endl;
		cout << "메시지 : " << text << endl;
	}
	
};

int main()
{
	char answer;
	string person;
	string text;
	for (;;) {
		cout << "메세지를 전송하시겠습니까? (y/n) : ";
		cin >> answer;
		if (answer != 'y') break;
		else {
			cout << "송신자 번호를 입력하시오 : ";
			cin >> person;
			cin.get();
			cout << "메세지 내용을 입력하시오 : ";
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
// 10번
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
		address = "기재하지 않음";
	}
	Friends(string num1, string num2, string num3, string num4) {
		name = num1;
		num = num2;
		tell = num3;
		address = num4;
	}
	void print() {
		cout << endl << endl;
		cout << "당신의 이름은 " << name << "주민번호는 " << num << endl;
		cout << "전화번호 : " << tell << endl;
		cout << "주소 : " << address << endl;
	}
	
};

void main()
{
	string name, num, tell, address;
	cout << "이름 : ";
	cin >> name;
	cout << "주민등록번호 : ";
	cin >> num;
	cout << "전화번호 : ";
	cin >> tell;
	cin.get();
	cout << "주소 : ";
	getline(cin,address);
	Friends f(name, num, tell, address);
	f.print();
}
*/

/*
// 12번
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
	cout << "-- 2에서 10까지의 랜덤정수 10개\n";
	srand(time(NULL));
	EvenRandom er;
}
*/



/*
// 14번
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

 