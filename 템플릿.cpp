
/*
// 3번
#include<iostream>
using namespace std;
template <class T>
void print(T a) {
	cout << a << "입니다" << endl;
	cout << sizeof(T) << "바이트 " << endl << endl;
}

void main()
{
	print(12);
	print(12.45);
	print('A');
	print("ABCEDFG");
}
*/
/*
// 4번
#include<iostream>
using namespace std;
template<class T>
void print(T a) {
	cout << a << "입니다\n";
}
template<class T>
T print(T a, int N, int b = 0) {
	for (int c = 1; c <= N; c++)
		cout << a;
	if (b) cout << endl;
	return(a);
}

void main() {
	print('A', 3, 1);
	print('A');
}
*/

/*
// 5번
#include<iostream>
using namespace std;
template<typename MIJ1, typename MIJ2>
void sum(MIJ1 a, MIJ2 b) {
	cout << a << "+" << b << "=" << a + b << "입니다!!\n";
}
void sum(double a, double b) {
	cout << a << "+" << b << "=" << a + b << "이네요~~\n";
}
void main()
{
	sum(2, 3.5);
	sum(3.5, 2);
	sum(2.0, 3.5);
	sum(2, 3);
}
*/

/*
// 6번
#include<iostream>
#include<string>
using namespace std;
template<typename MIJ>
class num {
	MIJ data;
public:
	num(MIJ a = 0) { data = a; }
	void set(MIJ a) { data = a; }
	MIJ get() { return(data); }
	void disp() { cout << data << "입니다\n"; }
};
void main()
{
	num <int> Kim(12);
	num <string> Lee("Neo");
	Kim.disp();
	Lee.disp();
	cout << Kim.get();
	cout << Lee.get();
}
*/

/*
// 7번
#include<iostream>
using namespace std;
template<class MIJ>
class Num {
	MIJ data;
public:
	Num(MIJ a = 0);
	void set(MIJ a);
	MIJ get();
	void disp();
	void show();
};
template <class MIJ> Num<MIJ>::Num(MIJ a) { data = a; }
template <class MIJ> void  Num<MIJ>::set(MIJ a) { data = a; }
template <class MIJ> MIJ Num<MIJ>::get() { return(data); }
template <class MIJ> void Num<MIJ>::disp() { cout << data << "\n"; }
template <class MIJ> void Num<MIJ>::show() { cout << "보인다\n"; }

void main() {
	Num <int> Kim(12);
	Kim.disp();
	Kim.show();
	cout << Kim.get();
}
*/


/*
// 8번
#include<iostream>
using namespace std;
template<class MIJ1, class MIJ2, class MIJ3>
class Num {
	MIJ1 su1;
	MIJ2 su2;
	MIJ3 res;
public:
	Num(MIJ1 a = 0, MIJ2 b = 0);
	void set();
	void disp();
};
template<class MIJ1, class MIJ2, class MIJ3>
Num<MIJ1, MIJ2, MIJ3>::Num(MIJ1 a, MIJ2 b)
{
	su1 = a;  su2 = b;  set();
}
template<class MIJ1, class MIJ2, class MIJ3>
void Num<MIJ1, MIJ2, MIJ3 >::set()
{
	res = su1 + su2;
}
template<class MIJ1, class MIJ2, class MIJ3>
void Num<MIJ1, MIJ2, MIJ3>::disp()
{
	cout << res << "입니다.\n";
}

void main()
{
	Num < int, int, int >Kim(10, 20);
	Num < int, double, double > Lee(10, 20.5);
	Num <double, int, double> Park(20.5, 10);
	Num < double, double, double > Choi(10.5, 20.3);
	Kim.disp();
	Lee.disp();
	Park.disp();
	Choi.disp();
}
*/

/*
// 11번
// === main.cpp
#include<iostream>
#include "array.h"
using namespace std;
int main()
{
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10>twodee;
	int i, j;
	for (i = 0; i < 10; i++) {
		sums[i] = 0;
		for (j = 0; j < 5; j++) {
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			cout.width(5);
			cout << twodee[i][j] << ' ';
		}
		cout << ": 합계 = ";
		cout.width(3);
		cout << sums[i] << ", 평균 = " << aves[i] << endl;
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}
*/


/*
// 9번
// Stack 구현
// === main.cpp
#include<iostream>    
#include<string>
#include<cctype>
#include "stack.h"
using namespace std;
int main()
{
	Stack<string> st;
	char ch;
	string po;
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
		case 'a': {cout << "추가할 주문서의 번호를 입력하십시오: ";   cin >> po;
			if (st.isfull()) cout << "스택이 가득 차 있습니다.\n";
			else st.push(po); }
			break;
		case 'P':
		case 'p': { if (st.isempty()) cout << "스택이 비어 있습니다.\n";
				  else { st.pop(po);   cout << "#" << po << " 주문서를 처리했습니다.\n"; }}
			break;
	
		}
		cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n 종료하려면 Q를 입력하십시오.\n";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}
*/

/*
// 10번
// === main.cpp
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "stack.h"
const int Num = 10;
using namespace std;
int main()
{
	srand(time(0));
	cout << "스택의 크기를 입력하십시오: ";
	int stacksize;
	cin >> stacksize;
	Stack<const char *> st(stacksize);
	const char * in[Num] = {
		"1: 노미호", "2: 주리혜",
		"3: 이몽룡", "4: 성춘향",
		"5: 이수일", "6: 심순애",
		"7: 박문수", "8: 홍길동",
		"9: 김두한", "10: 하야시"
	};
	const char * out[Num];
	int processed = 0;
	int nextin = 0;
	while (processed < Num) {
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (rand() % 2 && nextin < Num)    // 확률 50 : 50
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		cout << out[i] <<  endl;
	cout << "프로그램을 종료합니다. \n";
	return 0;
}
*/


/*
// 11번
// === main.cpp
#include<iostream>
#include "array.h"
using namespace std;
int main()
{
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;
	int i, j;
	for (i = 0; i < 10; i++) {
		sums[i] = 0;
		for (j = 0; j < 5; j++) {
			twodee[i][j] = (i + 1)*(j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": 합계 = ";
		cout.width(3);
		cout << sums[i] << ", 평균 = " << aves[i] << endl;
	}
	
	cout << "프로그램을 종료합니다.\n";
	return 0;
}
*/



/*
// 12페이지 문제풀이
// 1번
#include<iostream>
using namespace std;

template<class T>
T bigger(T a, T b) {
	return (a > b) ? a : b;
}
int main()
{
	int a = 20, b = 50;
	char c = 'a', d = 'z';
	cout << "bigger(20,50)의 결과는 " << bigger(a, b) << endl;
	cout << "biger('a','z')의 결과는 " << bigger(c, d) << endl;
}
*/

/*
// 2번
#include<iostream>
using namespace std;

template<class T, class D>
class Pair {
private:
	T one;
	D second;
public:
	Pair() {}
	Pair(T a, D b) : one(a), second(b) {};
	T get_one();
	D get_two();
	void set(T, D);
};
template<class T, class D>
T Pair<T,D>::get_one() {
	return one;
}
template<class T, class D>
D Pair<T, D>::get_two() {
	return second;
}
template<class T, class D>
void Pair<T, D>::set(T a, D b) {
	one = a;
	second = b;
}

int main()
{
	Pair <int, int> a(1, 2);
	Pair <int, double> b(3, 4.5);
	Pair <double, int> c;
	Pair <double, double> d;
	c.set(6.7, 8);
	d.set(9.1, 2.3);

	cout << a.get_one() << ", " << a.get_two() << endl;
	cout << b.get_one() << ", " << b.get_two() << endl;
	cout << c.get_one() << ", " << c.get_two() << endl;
	cout << d.get_one() << ", " << d.get_two() << endl;
}
*/

/*
// 3번
#include<iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template<class T>
void myswap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int a = 4, b = 5;
	double c = 0.3, d = 12.5;
	char *name1 = "apple";
	char *name2 = "banana";
	Circle donut(5), pizza(20);

	cout << "=== 교환 전\n";
	cout << "a=" << a << "  " << "b=" << b << endl;
	cout << "c=" << c << "  " << "d=" << d << endl;
	cout << "donut반지름= " << donut.getRadius() << "  " << "pizza반지름= " << pizza.getRadius() << endl;
	cout << "name1= " << name1 << "  " << "name2= " << name2 << endl;

	myswap(a, b);
	myswap(c, d);
	myswap(name1, name2);
	myswap(donut, pizza);

	cout << "\n\n=== 교환 후\n";
	cout << "a=" << a << "  " << "b=" << b << endl;
	cout << "c=" << c << "  " << "d=" << d << endl;
	cout << "donut반지름= " << donut.getRadius() << "  " << "pizza반지름= " << pizza.getRadius() << endl;
	cout << "name1= " << name1 << "  " << "name2= " << name2 << endl;
}
*/


/*
// 4번 
#include<iostream>
using namespace std;
template<class T>
T add(T arr[], int n) {			  
	T sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };

	cout << "sum of x[] = " << add(x, 5) << endl;   // 배열 x와 원소 5개의 합을 계산
	cout << "sum of d[] = " << add(d, 6) << endl;   // 배열 d와 원소 6개의 합을 계산
}
*/


/*
// 5번
#include<iostream>
using namespace std;
template<class A, class B>
void mcopy(A &x, B &y, int n) {
	for (int i = 0; i < n; i++) {
		y[i] = x[i];
	}
}

int main()
{
	int x[] = { 1,2,3,4,5 };
	double d[5];
	char c[5] = { 'H', 'e', 'l','l','o' }, e[5];

	mcopy(x, d, 5);  // int x[]의 원소5개를 double d[]에 복사
	mcopy(c, e, 5);  // char c[]의 원소5개를 char e[]에 복사

	cout << "<새 배열 d>\n";
	for (int i = 0; i < 5; i++) cout << d[i] << ' ';    // d[] 출력
	cout << endl;
	cout << "<새 배열 e>\n";
	for (int i = 0; i < 5; i++) cout << e[i] << ' ';    // e[] 출력
	cout << endl;
}
*/


/*
// 6번
#include<iostream>
using namespace std;
template<class T>
T biggest(T arr[], int size) {
	T max = arr[0];
	for (int i = 0; i < size; i++) {
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
int main() {
	int x[] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;  // 5는 배열x의 크기
	double y[] = { 6.4, 3.3, -200.6, 7.7, 8.8, 20.3 };
	cout << biggest(y, 6);  // 6는 배열y의 크기
}
*/

/*
// 7번
#include<iostream>
using namespace std;
template<class T>
bool equalArrays(T a[], T b[], int x1, int x2) {
	if (x1 != x2) return false;
	else {
		for (int i = 0; i < x1; i++) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
}

int main()
{
	int x1[] = { 1,10,100,5,4 };
	int x2[] = { 1,10,100,5,4 };

	if (equalArrays(x1, x2, sizeof(x1)/sizeof(x1[0]),sizeof(x2)/sizeof(x2[0])))
		cout << "두개의 배열은 같습니다." << endl;
	else
		cout << "두개의 배열은 다릅니다. " << endl;
	double y1[] = { 6.4, 3.3, -200.6, 7.7, 8.8, 20.3 };
	double y2[] = { 6.4, 3.4, -200.6, 7.7, 8.8, 20.3 };
	if (equalArrays(y1, y2, sizeof(y1) / sizeof(y1[0]), sizeof(y2) / sizeof(y2[0])))
		cout << "두개의 배열은 같습니다." << endl;
	else
		cout << "두개의 배열은 다릅니다." << endl;
}
*/

/*
// 8번
#include<iostream>
using namespace std;
template<class T>
void reverseArray(T arr[], int n) {
	T tmp;
	for (int i = 0; i < n / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}

int main()
{
	int x[] = { 1,2,3,4,5 };
	char y[] = "apple";


	cout << "== 뒤집기 전\n";
	for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
		cout << x[i] << "  ";
	}
	cout << endl;
	cout << y << endl;
	
	reverseArray(x, sizeof(x)/sizeof(x[0]));
	reverseArray(y, strlen(y));

	cout << "== 뒤집기 후\n";
	for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
		cout << x[i] << "  ";
	}
	cout << endl;
	cout << y << endl;
}
*/

/*
// 9번
#include<iostream>
using namespace std;
template<class T>
T* concat(T a[], int a_len, T b[], int b_len) {
	T *p = new T[a_len + b_len];
	int i, k;
	for (i = 0; i < a_len; i++) {
		p[i] = a[i];
	}
	for (int k = i, j=0; j < b_len; k++,j++) {
		p[k] = b[j];
	}
	return p;
}

int main()
{
	int x[] = { 1,2,3 };
	int y[] = { 6,7,8,9 };
	int *p = concat(x, 3, y, 4);

	char a[] = { 'L','o','v','e' };
	char b[] = { 'C','+','+' };
	char *q = concat(a, 4, b, 3);

	
	for (int i = 0; i < sizeof(x) / sizeof(x[0]) + sizeof(y) / sizeof(y[0]); i++) 
		cout << p[i] << " ";
	cout << endl;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0]); i++)
		cout << q[i] << " ";
	cout << endl;
}
*/




/*
// 양방향 연결리스트 - 클래스 템플릿 사용 - 다양한 타입의 객체들을 Node 객체에 저장하여 연결리스트 만들고 테스트
// 10번  - 맞게 한건지 질문 !! 꼭 - 맞게한거임
#include<iostream>
using namespace std;
template<class T>
class Node {
public:
	T data;
	Node *previous;
	Node *next;
	Node() {}
};

int main() {
	Node <int> *sp, *ep, *cp;
	sp = ep = NULL;
	int input;
	for (int i = 0; i < 4; i++)
	{
		printf("%d번째 정수값 : ", i + 1);
		scanf("%d", &input);
		if (sp == NULL)
		{
			sp = (Node<int> *)malloc(sizeof(Node<int>));
			ep = sp;
			ep->previous = NULL;
		}
		else {
			ep->next = (Node<int> *)malloc(sizeof(Node<int>));
			ep->next->previous = ep;
			ep = ep->next;
		}
		ep->data = input;
		ep->next = NULL;
	}

	cp = sp;
	cout << "== int형 정방향 출력\n";
	while (cp != NULL)
	{
		printf("%d", cp->data);
		cp = cp->next;
	}

	cp = ep;
	cout << "\n\n== int형 역방향 출력\n";
	while (cp != NULL)
	{
		printf("%d", cp->data);
		cp = cp->previous;
	}
	cout << endl << endl;


	Node <double> *ap, *bp, *dp;
	ap = bp = NULL;
	double d;
	for (int i = 0; i < 4; i++)
	{
		printf("%d번째 실수값 : ", i + 1);
		scanf("%lf", &d);
		if (ap == NULL)
		{
			ap = (Node<double> *)malloc(sizeof(Node<double>));
			bp = ap;
			bp->previous = NULL;
		}
		else {
			bp->next = (Node<double> *)malloc(sizeof(Node<double>));
			bp->next->previous = bp;
			bp = bp->next;
		}
		bp->data = d;
		bp->next = NULL;
	}

	dp = ap;
	cout << "== double형 정방향 출력\n";
	while (dp != NULL)
	{
		printf("%.1f  ", dp->data);
		dp = dp->next;
	}

	dp = bp;
	cout << "\n\n== double형 역방향 출력\n";
	while (dp != NULL)
	{
		printf("%.1f  ", dp->data);
		dp = dp->previous;
	}
	cout << endl;
}
*/


/*
// 11번
#include<iostream>
#include<ctime>
using namespace std;
template<class T>
class RandomList {
private:
	int idx;
	int size;
	T *arr;
public:
	RandomList() { idx = 0; }
	void set(int n) {
		arr = new T[n];
		size = n;
	}
	T get(int i) { return arr[i]; }
	T select();
	void add(T val);
};
template<class T>
T RandomList<T>::select() {
	int r = rand() % size;
	return arr[r];
}
template<class T>
void RandomList<T>::add(T val) {
	arr[idx++] = val;
}
int main()
{
	int size, val;
	RandomList <int> list;
	srand(time(NULL));
	cout << "(int)랜덤리스트의 사이즈를 입력하시오: ";
	cin >> size;
	list.set(size);
	for (int i = 0; i < size; i++) {
		cout << "리스트에 넣을 값 입력: ";
		cin >> val;
		list.add(val);
	}
	cout << "List 삽입 원소 : ";
	for (int i = 0; i < size; i++) {
		cout << list.get(i) << "  ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "랜덤출력 값 : " << list.select() << endl;
	}

	double input;
	RandomList<double> list2;
	cout << "\n\n(double)랜덤리스트의 사이즈를 입력하시오: ";
	cin >> size;
	list2.set(size);
	for (int i = 0; i < size; i++) {
		cout << "리스트에 넣을 값 입력: ";
		cin >> input;
		list2.add(input);
	}
	cout << "List 삽입 원소 : ";
	for (int i = 0; i < size; i++) {
		cout << list2.get(i) << "  ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "랜덤출력 값 : " << list2.select() << endl;
	}
}
*/

/*
// 12번 - 원형큐사용
#include<iostream>
using namespace std;
template<class T, int size>
class Queue {
	T data;
	T arr[size];
	int front, rear;
public:
	Queue() { front = 0; rear = 0; }
	void enqueue(T val);
	T dequeue();
};
template<class T, int size>
void Queue<T, size>::enqueue(T val) {
	if ((rear+1)%size == front) cout << "큐가 가득 찼습니다\n";
	else arr[(++rear)%size] = val;
}
template<class T, int size>
T Queue<T, size>::dequeue() {
	try {
		if (front == rear) { throw "큐가 비어있습니다\n";}
		else return arr[(++front) % size];
	}
	catch (char *e) { cout << e; return 0; }
}

int main()
{
	Queue <int,10> q;
	int a;
	int val;
	for (;;) {
		cout << "1. enqueue  2. dequeue  3. 종료\n";
		cin >> a;
		if (a == 1) {
			cout << "큐에 삽입할 값을 입력하시오: ";
			cin >> val;
			q.enqueue(val);
		}
		else if (a == 2) {
			cout << "dequeue: " << q.dequeue() << endl;
		}
		else { cout << "종료되었습니다\n"; break; }
	}
}
*/


/*
// 13번
#include<iostream>
using namespace std;
const int SIZE = 100;
template<class T>
class Set {
private:
	T arr[SIZE];
	int idx;
public:
	Set() { idx = 0; }
	void add(T val);
	void prn();
};
template<class T>
void Set<T>::add(T val) {
	int i;
	for (i = 0; i < idx; i++) {
		if (arr[i] == val) { cout << "이미 중복된 데이터가 존재합니다.\n"; break; }
	}
	if(i==idx) arr[idx++] = val;
}
template<class T>
void Set<T>::prn() {
	cout << "Set =  [ ";
	for (int i = 0; i < idx; i++) {
		cout << arr[i] << "  ";
	}
	cout << " ]\n";
}

int main()
{
	Set <int> set;
	int a, val;
	for (;;) {
		cout << "1. ADD  2. PRINT  3. EXIT\n";
		cin >> a;
		if (a == 1) {
			cout << "집합에 추가할 값을 입력하시오: ";
			cin >> val;
			set.add(val);
		}
		else if (a == 2) {
			set.prn();
		}
		else { cout << "종료되었습니다.\n"; break; }
	}
}
*/