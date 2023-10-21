

/*
// 5번
#include<iostream>
#include<string>
using namespace std;
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {
		cout << "생성자 호출" << endl;
	}
	void print() {
		cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
	}
	~Car() {
		cout << "소멸자 호출" << endl;
	}
};

void swapObjects(Car c1, Car c2) {
	Car tmp;
	tmp = c1;
	c1 = c2;
	c2 = tmp;
}
int main()
{
	Car red(0, 1, "red");
	Car blue(30, 2, "blue");

	swapObjects(red,blue);
	red.print();
	blue.print();
	return 0;
}
*/

/*
#include<iostream>
#include<string>
using namespace std;
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {}
	void print() {
		cout << "속도: " << speed << "기어: " << gear << " 색상: " << color << endl;
	}
};

void swap(Car *p1, Car *p2) {
	Car tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



int main()
{
	Car red(0, 1, "red");
	Car blue(0, 1, "blue");
	swap(&red, &blue);
	red.print();
	blue.print();
	return 0;
}
*/

/*
// 11번
#include<iostream>
#include<string>
using namespace std;
class Car {
	int speed;
	int gear;
	string color;
public:
	static int count;
	Car(int s = 0, int g = 1, string c = "white") :speed(s), gear(g), color(c) {
		count++;
	}
	~Car() {
		count--;
	}
};

int Car::count = 0;
int main()
{
	cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;

	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;

	Car c3(0, 0, "red");
	cout << "지금까지 생성된 자동차 수 = " << c1.count << endl;
	cout << "지금까지 생성된 자동차 수 = " << c2.count << endl;

	return 0;
}
*/

/*
// 9페이지 12번
#include<iostream>
#include<string>
using namespace std;
class Car {
	int speed;
	int gear;
	string color;
public:
	static int count;
	Car(int s = 0, int g = 1, string c = "white") :speed(s), gear(g), color(c) {
		count++;
	}
	~Car() {
		count--;
	}
	static int getCount() {
		return count;
	}
};
int Car::count = 0;
int main()
{
	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	int n = Car::getCount();
	cout << "지금까지 생성된 자동차 수 = " << n << endl;
	return 0;
}
*/

/*
// 6페이지 9번
#include<iostream>
using namespace std;
class Score {
	int kor, eng;
public:
	Score(int a = 0, int b = 0) {
		kor = a;
		eng = b;
	}
	void disp() {
		cout << "국어=" << kor << " 영어=" << eng << endl;
	}
};
void swapObjects(Score &r1, Score &r2) {
	// 객체가 참조자에 의하여 참조된다.
	Score tmp;
	tmp = r1;
	r1 = r2;
	r2 = tmp;
}
int main()
{
	Score red(10, 10);
	Score blue(30, 30);

	swapObjects(red, blue);
	red.disp();
	blue.disp();
	return 0;
}
*/

/*
// 10번
#include<iostream>
#include<cstring>
using namespace std;
class Book {
	char title[12];
	int value;
public:
	void set(char *a) {
		strcpy(title, a);
	}
	void set(int b) {
		value = b;
	}
	void set(char *ap, int b) {
		set(ap);
		set(b);
	}
	void disp() {
		cout << title << "책은 " << value << "원" << endl;
	}
};
void change(Book *ap, Book *bp) {
	Book im = *ap;
	*ap = *bp;
	*bp = im;
}
void swap(Book &A, Book &B) {
	Book im = A;
	A = B;
	B = im;
}
void main()
{
	Book Kim, Lee, Park;
	Book *ap;
	Kim.set("소설", 500);
	Lee.set("잡지", 300);
	Park.set("C", 800);

	ap = &Kim;
	ap->disp();

	change(&Kim, &Lee);
	Kim.disp();
	Lee.disp();

	swap(Kim, Park);
	Kim.disp();
	Park.disp();
}
*/

/*
// 11번
#include<iostream>
#include<string>
using namespace std;
class Car {
	int speed;
	int gear;
	string color;
public:
	static int count;
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {
		count++;
	}
	~Car() {
		count--;
	}
};
int Car::count = 0;
int main()
{
	cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;

	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;

	Car c3(0, 0, "red");
	cout << "지금까지 생성된 자동차 수 = " << c1.count << endl;
	cout << "지금까지 생성된 자동차 수 = " << c2.count << endl;

	return 0;
}
*/





/*
// 11페이지 - 문제풀이
// 1번
#include<iostream>
using namespace std;
class Robot {
private:
	long id;
	long egy;
public:
	Robot(long i = 0, long e = 0) :id(i), egy(e) {}
	long getid() {
		return (id);
	}
	long getEgy() {
		return(egy);
	}
	void setid(long a) {
		id = a;
	}
	void setEgy(long b) {
		egy = b;
	}
	void set(long c, long d) {
		id = c; egy = d;
	}
	void dispRobot() {
		cout << id << "로봇 에너지 " << egy << endl;
	}
};

int main()
{
	Robot A[2];
	Robot B[3] = { Robot(2601,100),Robot(2602),Robot() };
	A[0].dispRobot();
	A[1].dispRobot();
	for (int a = 0; a < 3; a++)
		B[a].dispRobot();

	A->set(2501, 50);
	(A + 1)->set(2502, 60);
	A[0].dispRobot();
	A[1].dispRobot();
}
*/

/*
// 2번
#include<iostream>
using namespace std;
class Robot {
private:
	long id;
	long egy;
public:
	Robot(long i = 0, long e = 0) :id(i), egy(e) {}
	long getid() {
		return (id);
	}
	long getEgy() {
		return(egy);
	}
	void setid(long a) {
		id = a;
	}
	void setEgy(long b) {
		egy = b;
	}
	void set(long c, long d) {
		id = c; egy = d;
	}
	void dispRobot() {
		cout << id << "로봇 에너지 " << egy << endl;
	}
};

void main()
{
	Robot A[3];
	Robot *ap = A;
	ap->set(2601, 100);
	ap++;
	ap++->set(2602, 200);
	ap->set(2603, 300);
	ap -= 2;
	for (int a = 0; a < 3; a++)
		A[a].dispRobot();
	cout << "***\n";
	ap[0].dispRobot();
	(ap + 1)->dispRobot();
	ap[2].dispRobot();
}
*/

/*
// 3번
#include<iostream>
using namespace std;
class Robot {
private:
	long id;
	long egy;
public:
	Robot(long i = 0, long e = 0) :id(i), egy(e) {}
	long getid() {
		return (id);
	}
	long getEgy() {
		return(egy);
	}
	void setid(long a) {
		id = a;
	}
	void setEgy(long b) {
		egy = b;
	}
	void set(long c, long d) {
		id = c; egy = d;
	}
	void dispRobot() {
		cout << id << "로봇 에너지 " << egy << endl;
	}
};

void main()
{
	Robot M[3];
	Robot *ap[3] = { M, M + 1,M + 2 };
	M[0].set(1, 10);
	M[1].set(2, 20);
	M[2].set(3, 30);
	(*(ap + 1))->dispRobot();
	for (int a = 0; a < 3; a++)
		ap[a]->dispRobot();
	ap[1] = M + 2;
	ap[2] = M + 1;
	for (int a = 0; a < 3; a++)
		ap[a]->dispRobot();
}
*/

/*
// 4번
#include<iostream>
using namespace std;
class Circle {
	int radius;
	double width;
public:
	Circle() {}
	Circle(int r) {
		radius = r;
		cout << "생성자 실행 radius = " << radius << endl;
		get_width();
	}
	void get_width() {
		width = 3.14*radius * radius;
		cout << "원의 면적은 " << width << endl;
	}
	~Circle() {
		cout << "소멸자 실행 radius = " << radius << endl << endl;
	}

};
void main()
{
	int r;
	for (;;) {
		cout << "정수반지름 입력(음수이면 종료) : ";
		cin >> r;
		if (r < 0) break; 
		else {
			Circle *c = new Circle(r);
			delete (c);
		}
	}
}
*/

/*
// 5번
#include<iostream>
#include<string>
using namespace std;
class Bank {
	string name;
	int money;
public:
	Bank(string n, int m) :name(n), money(m) {
	}
	// 저금
	void add_money(int add) {
		money += add;
		cout << name << "님의 현재 잔액은 " << add << "만큼이 증가하여 총" << money << "원입니다." << endl;
	}
	// 인출
	void use_money(int use) {
		if (money < use) cout << "잔액이 부족합니다." << endl;
		else {
			money -= use;
			cout << use << "원이 인출되었습니다." << endl;
		}
	}
	void print() {
		cout << name << "   " << money << endl;
	}
};

void main()
{
	Bank people[3] = { Bank("Prodo",15000),Bank("Sally",23000),Bank("Brown",40000) };
	cout << "이름" << "   " << "저금통장액" << endl;
	cout << "==================" << endl;
	for (int i = 0; i < 3; i++) {
		people[i].print();
	}
}
*/

/*
// 6번
#include<iostream>
using namespace std;

class Circle {
	int radius;
	double width;
public:
	void setRadius(int r) {
		radius = r;
	}
	double getWidth() {
		return radius * radius*3.14;
	}
};
void main()
{
	Circle circleArray[3];
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i + 1 << " 의 면적은 " << circleArray[i].getWidth() << endl;
	}
}
*/

/*
// 7번
#include<iostream>
#include<string>
using namespace std;

class Book {
	string name;
	int price;
public:
	Book() {}
	Book(string n) {
		name = n;
	}
	Book(int p) {
		price = p;
	}
	Book(string n, int p) {
		set(n, p);
	}
	void set(string n, int p) {
		name = n;
		price = p;
	}
	void print()
	{
		cout << name << "책은 " << price << "원" << endl;
	}
};
void swap(Book *ap, Book *bp);
void swap(Book &a, Book &b);

void main()
{
	Book Kim, Lee, Park;
	Kim.set("소설", 5000);
	Lee.set("잡지", 3000);
	Park.set("C", 8000);
	Kim.print();
	Lee.print();
	Park.print();
	cout << endl;
	swap(&Kim, &Lee);
	swap(Park, Lee);
	Kim.print();
	Lee.print();
	Park.print();
}

void swap(Book *ap, Book *bp) {
	Book tmp;
	tmp = *ap;
	*ap = *bp;
	*bp = tmp;
}
void swap(Book &a, Book &b) {
	Book c;
	c = a;
	a = b;
	b = c;
}
*/

/*
// 8번
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Account {
	string id;		// 계좌번호
	string name;	// 이름
	int money;		// 잔액
	int add_money; // 입금액
	int use_money; // 출금액
public:
	Account() {
		money = 0;
		add_money = 0;
		use_money = 0;
	}
	void set(string i, string n, int m) {
		id = i; name = n;  add_money = m; money = m;
		cout << "계좌가 개설되었습니다!" << endl;
	}
	void add(int m) {
		add_money += m;
		money += m;
		cout << "\n입금완료!\n";
	}
	void use(int m) {
		if (money < m) {
			cout << "잔액이 부족합니다!\n";
		}
		else {
			use_money += m;
			money -= m;
			cout << "\n출금완료!\n";
		}
	}
	void print() {
		cout << id << "\t"<< name <<"\t"<< add_money <<"\t"<< use_money<<"\t" << money << endl;
	}
	string get_id() {
		return id;
	}
	int get_money() {
		return money;
	}
	int get_add() {
		return add_money;
	}
	int get_use() {
		return use_money;
	}
};
bool search_id(Account arr[], string id, int index);
int exist_id(Account arr[], string id, int index);

void main()
{
	Account accArr[100];
	int index = 0;
	int num;
	string id, name;
	int money;
	for (;;) {
		cout << "\n----메뉴----\n";
		cout << "1. 계좌개설\n";
		cout << "2. 입금\n";
		cout << "3. 출금\n";
		cout << "4. 계좌정보 전체출력\n";
		cout << "5. 프로그램 종료\n";
		cout << "선택 : ";
		cin >> num;
		if (num == 5) { cout << "\n프로그램이 종료되었습니다." << endl; break; }
		if (num == 1) {
			cout << "\n[계좌개설]\n";
			cout << "계좌번호 : ";
			cin >> id;
			if (search_id(accArr, id, index)) {
				cout << "이름 : ";
				cin >> name;
				cout << "입금액 : ";
				cin >> money;
				accArr[index].set(id, name, money);
				index++;
			}
		}
		else if (num == 2) {
			cout << "\n[입금]\n";
			cout << "계좌번호 : ";
			cin >> id;
			int i = exist_id(accArr, id, index);
			if ( 0<=i) {
				cout << "입금액 : ";
				cin >> money;
				accArr[i].add(money);
			}
			else if(i<0) {
				cout << "계좌번호 오류\n";
			}
		}
		else if (num == 3) {
			cout << "\n[출금]\n";
			cout << "계좌번호 : ";
			cin >> id;
			int i = exist_id(accArr, id, index);
			if ( 0<=i) {
				cout << "출금액 : ";
				cin >> money;
				accArr[i].use(money);
			}
			else if(i<0) {
				cout << "계좌번호 오류\n";
			}
		}
		else if (num == 4) {
			int addsum=0, usesum=0, moneysum = 0;
			cout  << "ID" << "\t" << "이 름" <<"\t"<< "입금액" <<"\t"<< "출금액" <<"\t"<< "잔 액" << endl;
			for (int i = 0; i < index; i++) {
				accArr[i].print();
				addsum += accArr[i].get_add();
				usesum += accArr[i].get_use();
				moneysum += accArr[i].get_money();
			}
			cout << "합계" << "\t" <<"   "<<"\t"<< addsum <<"\t"<< usesum<<"\t" << moneysum <<"\t"<< endl;
		}
	}
}

bool search_id(Account arr[],string id, int index) {
	int i = 0;
	for (; i <= index; i++) {
		if (id == arr[i].get_id()) {
			cout << "사용할 수 없는 계좌번호입니다.\n";
			return false;
		}
	}
	if (index < i) return true;
}

int exist_id(Account arr[], string id, int index) {
	int i = 0;
	for (; i <= index; i++) {
		if (id == arr[i].get_id()) {
			return i;
		}
	}
	if (index < i) return -1;
}
*/






/*
// 18페이지 10번  + 친구맺기 기능 추가
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Community {
	string name;
	string f;
	int popularity;
public:
	void set_name(string name) {
		this->name = name;
	}
	void set_friend(string y) {
		f = y;
	}
	void set_popularity(int p) {
		popularity = p;
	}
	void print() {
		cout <<setw(10) << name << "     " << f << "     " << popularity << endl;
	}
	string get_name() {
		return name;
	}
	int get_popularity() {
		return popularity;
	}
	void add_popularity() {
		popularity++;
	}
};

// linked list
struct list {
	Community people;
	list * next;
	list *sp, *ep;
};

void like(list facebook[], string name);
void make_friend(list facebook[], string me, string you);
void search(list facebook[], string search);
void print_list(list f);

void main()
{
	Community people[4];
	string name, f;
	int a;
	// 초기화
	string n[4] = { "Prodo","Muji","Neo","Sally" };
	for (int i = 0; i < 4; i++) {
		people[i].set_name(n[i]);
		people[i].set_friend("없음");
		people[i].set_popularity(0);
	}
	cout << setw(13)<< "이름   " << "내친구   " << "인기도   " << endl;
	for (int i = 0; i < 4; i++) {
		people[i].print();
	}
	cout << endl;
	// 링크드 리스트의 객체만 초기화
	list facebook[4];
	for (int i = 0; i < 4; i++) {
		facebook[i].people = people[i];
		facebook[i].sp = facebook[i].ep = NULL;
	}


	for (;;) {
		cout << "\n1. 가입명단  2. 친구 맺기  3. 사용자 검색  4. 좋아요  5. 종료 \n";
		cin >> a;
		if (a == 5) break;
		if (a == 1) {
			cout << setw(13) << "이름   " << "내친구   " << "인기도   " << endl;
			for (int i = 0; i < 4; i++) {
				cout <<setw(10)<< facebook[i].people.get_name() << "  ";
				print_list(facebook[i]);
				cout << "  \t\t "<< facebook[i].people.get_popularity() << endl;
			}
			cout << endl;
		}
		else if (a == 2) {
			cout << "본인 이름 : ";
			cin >> name;
			cout << "친구 이름 : ";
			cin >> f;
			make_friend(facebook, name, f);
		}
		else if (a == 3) {
			cout << "검색할 사용자 이름 : ";
			cin >> name;
			search(facebook, name);
		}
		else if (a == 4) {
			cin.get();
			cout << "누구의 게시글에 좋아요를 누르시겠습니까 ?  : ";
			getline(cin, name);
			like(facebook, name);
			cout << name << "님에게 좋아요가 반영되었습니다!" << endl;
		}
	}


}
void make_friend(list facebook[], string me, string you)   // 2. 친구맺기
{
	// 나한테 친구 연결
	for (int i = 0; i < 4; i++) {
		if (facebook[i].people.get_name() == me) {
			if (facebook[i].sp == NULL) {
				facebook[i].sp = new list;
				facebook[i].ep = facebook[i].sp;
			}
			else {
				facebook[i].ep->next = new list;
				facebook[i].ep = facebook[i].ep->next;
			}
			for (int k = 0; k < 4; k++) {
				if (facebook[k].people.get_name() == you) {
					facebook[i].ep->people = facebook[k].people;
					break;
				}
			}
			facebook[i].ep->next = NULL;
		}
	}
	// 친구에게 나를 연결
	for (int i = 0; i < 4; i++) {
		if (facebook[i].people.get_name() == you) {
			if (facebook[i].sp == NULL) {
				facebook[i].sp = new list;
				facebook[i].ep = facebook[i].sp;
			}
			else {
				facebook[i].ep->next = new list;
				facebook[i].ep = facebook[i].ep->next;
			}
			for (int k = 0; k < 4; k++) {
				if (facebook[k].people.get_name() == me) {
					facebook[i].ep->people = facebook[k].people;
					break;
				}
			}
			facebook[i].ep->next = NULL;
		}
	}
	cout << me << "님과 " << you << "님이 친구로 맺어졌습니다!" << endl;
}

void like(list facebook[], string name) // 4. 좋아요
{
	for (int i = 0; i < 4; i++) {
		if (facebook[i].people.get_name() == name) facebook[i].people.add_popularity();
	}
}


void search(list facebook[], string search)	// 3. 사용자 검색
{
	for (int i = 0; i < 4; i++) {
		if (facebook[i].people.get_name() == search) {
			cout << "이름 : " << facebook[i].people.get_name() << endl;
			cout << "친구 : ";
			print_list(facebook[i]); cout << endl;
			cout << "인기도 : " << facebook[i].people.get_popularity() << endl;
		}
	}
}

void print_list(list f)		// 링크드리스트- 친구출력
{
	list *cp;
	cp = f.sp;
	while (cp != NULL) {
		cout << cp->people.get_name() << "   ";
		cp = cp->next;
	}
}
*/


/*
// 11번
#include<iostream>
using namespace std;

class MyMath {
	static double PI;
public:
	static void print() {
		cout << PI << endl;
	}
};

double MyMath::PI = 3.141592;
void main()
{
	MyMath::print();
}
*/



/*
// 12번 
#include<iostream>
using namespace std;

class MyMetric {

public:
	static double KiloToMile(double kilo) {
		return kilo * 0.621371;
	}
	static double MileToKilo(double mile) {
		return  mile / 0.621371;
	}
};
void main()
{
	double kilo = 0.7234;
	double mile = 3.24242;


	cout << kilo << " 킬로미터는 " << MyMetric::KiloToMile(kilo) << "입니다.\n";
	cout << mile<< " 마일은 " << MyMetric::MileToKilo(mile) << "입니다.\n";
}
*/



/*
// 13번
#include<iostream>
#include<string>
using namespace std;

class Student {
	int id;
	string name;
	static string teacher;
	static int teacher_age;
public:
	Student(int i, string n) : id(i), name(n) {}
	int get_id() {
		return id;
	}
	string get_name() {
		return name;
	}
	static string get_teacher_name() {
		return teacher;
	}
	static int get_teacher_age() {
		return teacher_age;
	}

};
string Student::teacher = "홍길동";
int Student::teacher_age = 30;
void main()
{
	Student s[3] = { Student(1, "Prodo"),Student(2, "Neo"), Student(3, "Sally") };
	cout << "번호\t" << "이름\t" << "담 임\t" << "선생님나이\n";
	for (int i = 0; i < 3; i++) {
		cout << s[i].get_id() << "\t" << s[i].get_name() << "\t" << Student::get_teacher_name() << "\t" << Student::get_teacher_age() << endl;
	}

}
*/
