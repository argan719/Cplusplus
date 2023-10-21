

/*
// 5��
#include<iostream>
#include<string>
using namespace std;
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {
		cout << "������ ȣ��" << endl;
	}
	void print() {
		cout << "�ӵ�: " << speed << " ���: " << gear << " ����: " << color << endl;
	}
	~Car() {
		cout << "�Ҹ��� ȣ��" << endl;
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
		cout << "�ӵ�: " << speed << "���: " << gear << " ����: " << color << endl;
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
// 11��
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
	cout << "���ݱ��� ������ �ڵ��� �� = " << Car::count << endl;

	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	cout << "���ݱ��� ������ �ڵ��� �� = " << Car::count << endl;

	Car c3(0, 0, "red");
	cout << "���ݱ��� ������ �ڵ��� �� = " << c1.count << endl;
	cout << "���ݱ��� ������ �ڵ��� �� = " << c2.count << endl;

	return 0;
}
*/

/*
// 9������ 12��
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
	cout << "���ݱ��� ������ �ڵ��� �� = " << n << endl;
	return 0;
}
*/

/*
// 6������ 9��
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
		cout << "����=" << kor << " ����=" << eng << endl;
	}
};
void swapObjects(Score &r1, Score &r2) {
	// ��ü�� �����ڿ� ���Ͽ� �����ȴ�.
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
// 10��
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
		cout << title << "å�� " << value << "��" << endl;
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
	Kim.set("�Ҽ�", 500);
	Lee.set("����", 300);
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
// 11��
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
	cout << "���ݱ��� ������ �ڵ��� �� = " << Car::count << endl;

	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	cout << "���ݱ��� ������ �ڵ��� �� = " << Car::count << endl;

	Car c3(0, 0, "red");
	cout << "���ݱ��� ������ �ڵ��� �� = " << c1.count << endl;
	cout << "���ݱ��� ������ �ڵ��� �� = " << c2.count << endl;

	return 0;
}
*/





/*
// 11������ - ����Ǯ��
// 1��
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
		cout << id << "�κ� ������ " << egy << endl;
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
// 2��
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
		cout << id << "�κ� ������ " << egy << endl;
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
// 3��
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
		cout << id << "�κ� ������ " << egy << endl;
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
// 4��
#include<iostream>
using namespace std;
class Circle {
	int radius;
	double width;
public:
	Circle() {}
	Circle(int r) {
		radius = r;
		cout << "������ ���� radius = " << radius << endl;
		get_width();
	}
	void get_width() {
		width = 3.14*radius * radius;
		cout << "���� ������ " << width << endl;
	}
	~Circle() {
		cout << "�Ҹ��� ���� radius = " << radius << endl << endl;
	}

};
void main()
{
	int r;
	for (;;) {
		cout << "���������� �Է�(�����̸� ����) : ";
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
// 5��
#include<iostream>
#include<string>
using namespace std;
class Bank {
	string name;
	int money;
public:
	Bank(string n, int m) :name(n), money(m) {
	}
	// ����
	void add_money(int add) {
		money += add;
		cout << name << "���� ���� �ܾ��� " << add << "��ŭ�� �����Ͽ� ��" << money << "���Դϴ�." << endl;
	}
	// ����
	void use_money(int use) {
		if (money < use) cout << "�ܾ��� �����մϴ�." << endl;
		else {
			money -= use;
			cout << use << "���� ����Ǿ����ϴ�." << endl;
		}
	}
	void print() {
		cout << name << "   " << money << endl;
	}
};

void main()
{
	Bank people[3] = { Bank("Prodo",15000),Bank("Sally",23000),Bank("Brown",40000) };
	cout << "�̸�" << "   " << "���������" << endl;
	cout << "==================" << endl;
	for (int i = 0; i < 3; i++) {
		people[i].print();
	}
}
*/

/*
// 6��
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
		cout << "Circle " << i + 1 << " �� ������ " << circleArray[i].getWidth() << endl;
	}
}
*/

/*
// 7��
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
		cout << name << "å�� " << price << "��" << endl;
	}
};
void swap(Book *ap, Book *bp);
void swap(Book &a, Book &b);

void main()
{
	Book Kim, Lee, Park;
	Kim.set("�Ҽ�", 5000);
	Lee.set("����", 3000);
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
// 8��
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Account {
	string id;		// ���¹�ȣ
	string name;	// �̸�
	int money;		// �ܾ�
	int add_money; // �Աݾ�
	int use_money; // ��ݾ�
public:
	Account() {
		money = 0;
		add_money = 0;
		use_money = 0;
	}
	void set(string i, string n, int m) {
		id = i; name = n;  add_money = m; money = m;
		cout << "���°� �����Ǿ����ϴ�!" << endl;
	}
	void add(int m) {
		add_money += m;
		money += m;
		cout << "\n�ԱݿϷ�!\n";
	}
	void use(int m) {
		if (money < m) {
			cout << "�ܾ��� �����մϴ�!\n";
		}
		else {
			use_money += m;
			money -= m;
			cout << "\n��ݿϷ�!\n";
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
		cout << "\n----�޴�----\n";
		cout << "1. ���°���\n";
		cout << "2. �Ա�\n";
		cout << "3. ���\n";
		cout << "4. �������� ��ü���\n";
		cout << "5. ���α׷� ����\n";
		cout << "���� : ";
		cin >> num;
		if (num == 5) { cout << "\n���α׷��� ����Ǿ����ϴ�." << endl; break; }
		if (num == 1) {
			cout << "\n[���°���]\n";
			cout << "���¹�ȣ : ";
			cin >> id;
			if (search_id(accArr, id, index)) {
				cout << "�̸� : ";
				cin >> name;
				cout << "�Աݾ� : ";
				cin >> money;
				accArr[index].set(id, name, money);
				index++;
			}
		}
		else if (num == 2) {
			cout << "\n[�Ա�]\n";
			cout << "���¹�ȣ : ";
			cin >> id;
			int i = exist_id(accArr, id, index);
			if ( 0<=i) {
				cout << "�Աݾ� : ";
				cin >> money;
				accArr[i].add(money);
			}
			else if(i<0) {
				cout << "���¹�ȣ ����\n";
			}
		}
		else if (num == 3) {
			cout << "\n[���]\n";
			cout << "���¹�ȣ : ";
			cin >> id;
			int i = exist_id(accArr, id, index);
			if ( 0<=i) {
				cout << "��ݾ� : ";
				cin >> money;
				accArr[i].use(money);
			}
			else if(i<0) {
				cout << "���¹�ȣ ����\n";
			}
		}
		else if (num == 4) {
			int addsum=0, usesum=0, moneysum = 0;
			cout  << "ID" << "\t" << "�� ��" <<"\t"<< "�Աݾ�" <<"\t"<< "��ݾ�" <<"\t"<< "�� ��" << endl;
			for (int i = 0; i < index; i++) {
				accArr[i].print();
				addsum += accArr[i].get_add();
				usesum += accArr[i].get_use();
				moneysum += accArr[i].get_money();
			}
			cout << "�հ�" << "\t" <<"   "<<"\t"<< addsum <<"\t"<< usesum<<"\t" << moneysum <<"\t"<< endl;
		}
	}
}

bool search_id(Account arr[],string id, int index) {
	int i = 0;
	for (; i <= index; i++) {
		if (id == arr[i].get_id()) {
			cout << "����� �� ���� ���¹�ȣ�Դϴ�.\n";
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
// 18������ 10��  + ģ���α� ��� �߰�
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
	// �ʱ�ȭ
	string n[4] = { "Prodo","Muji","Neo","Sally" };
	for (int i = 0; i < 4; i++) {
		people[i].set_name(n[i]);
		people[i].set_friend("����");
		people[i].set_popularity(0);
	}
	cout << setw(13)<< "�̸�   " << "��ģ��   " << "�α⵵   " << endl;
	for (int i = 0; i < 4; i++) {
		people[i].print();
	}
	cout << endl;
	// ��ũ�� ����Ʈ�� ��ü�� �ʱ�ȭ
	list facebook[4];
	for (int i = 0; i < 4; i++) {
		facebook[i].people = people[i];
		facebook[i].sp = facebook[i].ep = NULL;
	}


	for (;;) {
		cout << "\n1. ���Ը��  2. ģ�� �α�  3. ����� �˻�  4. ���ƿ�  5. ���� \n";
		cin >> a;
		if (a == 5) break;
		if (a == 1) {
			cout << setw(13) << "�̸�   " << "��ģ��   " << "�α⵵   " << endl;
			for (int i = 0; i < 4; i++) {
				cout <<setw(10)<< facebook[i].people.get_name() << "  ";
				print_list(facebook[i]);
				cout << "  \t\t "<< facebook[i].people.get_popularity() << endl;
			}
			cout << endl;
		}
		else if (a == 2) {
			cout << "���� �̸� : ";
			cin >> name;
			cout << "ģ�� �̸� : ";
			cin >> f;
			make_friend(facebook, name, f);
		}
		else if (a == 3) {
			cout << "�˻��� ����� �̸� : ";
			cin >> name;
			search(facebook, name);
		}
		else if (a == 4) {
			cin.get();
			cout << "������ �Խñۿ� ���ƿ並 �����ðڽ��ϱ� ?  : ";
			getline(cin, name);
			like(facebook, name);
			cout << name << "�Կ��� ���ƿ䰡 �ݿ��Ǿ����ϴ�!" << endl;
		}
	}


}
void make_friend(list facebook[], string me, string you)   // 2. ģ���α�
{
	// ������ ģ�� ����
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
	// ģ������ ���� ����
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
	cout << me << "�԰� " << you << "���� ģ���� �ξ������ϴ�!" << endl;
}

void like(list facebook[], string name) // 4. ���ƿ�
{
	for (int i = 0; i < 4; i++) {
		if (facebook[i].people.get_name() == name) facebook[i].people.add_popularity();
	}
}


void search(list facebook[], string search)	// 3. ����� �˻�
{
	for (int i = 0; i < 4; i++) {
		if (facebook[i].people.get_name() == search) {
			cout << "�̸� : " << facebook[i].people.get_name() << endl;
			cout << "ģ�� : ";
			print_list(facebook[i]); cout << endl;
			cout << "�α⵵ : " << facebook[i].people.get_popularity() << endl;
		}
	}
}

void print_list(list f)		// ��ũ�帮��Ʈ- ģ�����
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
// 11��
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
// 12�� 
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


	cout << kilo << " ų�ι��ʹ� " << MyMetric::KiloToMile(kilo) << "�Դϴ�.\n";
	cout << mile<< " ������ " << MyMetric::MileToKilo(mile) << "�Դϴ�.\n";
}
*/



/*
// 13��
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
string Student::teacher = "ȫ�浿";
int Student::teacher_age = 30;
void main()
{
	Student s[3] = { Student(1, "Prodo"),Student(2, "Neo"), Student(3, "Sally") };
	cout << "��ȣ\t" << "�̸�\t" << "�� ��\t" << "�����Գ���\n";
	for (int i = 0; i < 3; i++) {
		cout << s[i].get_id() << "\t" << s[i].get_name() << "\t" << Student::get_teacher_name() << "\t" << Student::get_teacher_age() << endl;
	}

}
*/
