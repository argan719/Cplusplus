
/*
// 함수 포인터
// 5번
#include<iostream>
using namespace std;
double parn(int);
double(*pf)(int);

void main()
{
	pf = parn;

	double x = parn(4);
	double y1 = (*pf)(5);
	double y2 = pf(6);		// 위와 동일

	cout << "x= " << x << endl;
	cout << "y1= " << y1 << endl;
	cout << "y2= " << y2 << endl;
}

double parn(int n)
{
	return n * n;
}
*/



// 1페이지 (1번 ~ 4번)

/*
// 1번
#include<iostream>
void cheers(int);
double cube(double x);
int main(void)
{
	using namespace std;
	cheers(5);
	cout << "하나의 수를 입력하십시오: ";
	double side;
	cin >> side;
	double volume = cube(side);
	cout << "한 변의 길이가 " << side << " 센티미터인 정육면체의 부피는 ";
	cout << volume << " 세제곱센티미터입니다.\n";
	cheers(cube(2));
	return 0;
}

void cheers(int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << "Cheers! ";
	cout << endl;
}

double cube(double x)
{
	return x * x * x;
}
*/

/*
// 2번
#include<iostream>
const int Max = 5;
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

using namespace std;
int main()
{
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "재평가율을 입력하십시오: ";
		double factor;
		while (!(cin >> factor))
		{
			cout << "잘못 입력했습니다. 수치를 입력하세요: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "프로그램을 종료합니다.\n";
	cin.get();
	cin.get();
	return 0;
}

int fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << (i + 1) << "번 부동산의 가격: \n";
		cin >> temp;
		if (!cin)		// 입력 불량
		{
			cout << "입력 불량; 입력 과정을 끝내겠습니다.\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}

void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << "번 부동산: \\";
		cout << ar[i] << endl;
	}
}

void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}
*/

/*
// 3번
#include<iostream>
const int ArSize = 8;
int sum_arr(const int *begin, const int *end);
int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "먹은 과자 수 합계: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "처음 세 사람은 과자" << sum << "개를 먹었습니다.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다.\n";
	return 0;
}

int sum_arr(const int *begin, const int *end)
{
	const int *pt;
	int total = 0;

	for (pt = begin; pt != end; pt++)
		total = total + *pt;
	return total;
}
*/

// 4번




/*
// 함수 포인터
// 5번
#include<iostream>
using namespace std;
double pam(int);
double(*pf)(int);

void main()
{
	pf = pam;

	double x = pam(4);
	double y1 = (*pf)(5);
	double y2 = pf(6);

	cout << "x= " << x << endl;
	cout << "y1= " << y1 << endl;
	cout << "y2= " << y2 << endl;
}
double pam(int n)
{
	return n * n;
}
*/

/*
// 6번
#include<iostream>
double gildong(int);
double moonsoo(int);
void estimate(int lines, double(*pf)(int));

int main()
{
	using namespace std;
	int code;

	cout << "필요한 코드의 행 수를 입력하십시오: ";
	cin >> code;
	cout << "홍길동의 시간 예상:\n";
	estimate(code, gildong);
	cout << "박문수의 시간 예상:\n";
	estimate(code, moonsoo);
	return 0;
}

double gildong(int lns)
{
	return 0.05*lns;
}

double moonsoo(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double(*pf)(int))
{
	using namespace std;
	cout << lines << "행을 작성하는 데 ";
	cout << (*pf)(lines) << "시간이 걸립니다.\n";
}
*/



/*
// 7번
#include<iostream>
const double * f1(const double ar[], int n);
const double * f2(const double[], int);
const double * f3(const double *, int);
int main()
{
	using namespace std;
	double av[3] = { 100,200,300 };

	const double *(*p1)(const double *, int) = f1;
	const double *(*p2)(const double *, int) = f2;

	cout << "함수 포인터:\n";
	cout << "주소 값\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
	
	const double *(*pa[3])(const double *, int) = { f1,f2,f3 };
	const double *(**pb)(const double *, int) = pa;
	cout << "\n함수 포인터를 원소로 가지는 배열:\n";
	cout << "주소 값\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;

	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
	
	cout << "\n포인터를 원소로 가지는 배열을 가리키는 포인터:\n";
	cout << "주소 값\n";
	const double *(*(*pc)[3])(const double *, int) = &pa;
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;

	const double *(*(*pd)[3])(const double *, int) = &pa;
	const double * pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;

	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
	return 0;
}

const double * f1(const double *ar, int n)
{
	return ar;
}

const double * f2(const double ar[], int n)
{
	return ar + 1;
}

const double * f3(const double ar[], int n)
{
	return ar + 2;
} 
*/


/*
// 8번
#include<iostream>
using namespace std;
void KK(int N = 1)
{
	cout << N << "살";
}

void KK1(int a, int b = 0)
{
	cout << a;
	if (b) cout << "\n";
}

void KK2(int a = 1, int b = 2, int c = 3)
{
	cout << a + b + c << endl;
}

void main()
{
	KK();
	KK(2);

	KK1(4, 1);
	KK1(5);

	KK2(5, 4, 3);
	KK2(10, 20);
	KK2(100);
	KK2();
}
*/






/*
// 20페이지
// 17번 - 게임실행시간을 체크하는 프로그램 작성
// === main.cpp

#include "myFunctions.h"
#include<stdio.h>
#include<time.h>

void main()
{
	clock_t t1 = clock();
	int score = playUpAndDown(43, 0, 99);
	clock_t t2 = clock();
	double duration = (double)(t2 - t1) / CLOCKS_PER_SEC;

	printf(" 게임 점수: %d점\n", score);
	printf(" 걸린 시간: %1f초\n", duration);
}
*/




/*
// 21페이지
// 18번 - 퍼즐게임
// === main.cpp

#include "Ranking.h"
extern int playFifteenPuzzle();
void main()
{
	loadRanking("ranking.txt");
	int rank = playFifteenPuzzle();
	printRanking(); 
	storeRanking("ranking.txt");
}
*/



/*
// 함수 중복
// 10페이지 9번
#include<iostream>
using namespace std;
void MyFunc(void)
{
	cout << "MyFunc(void) called" << endl;
}

void MyFunc(char c)
{
	cout << "MyFunc(char c) called" << endl;
}

void MyFunc(int a, int b)
{
	cout << "MyFunc(int a, int b) called" << endl;
}

int main(void)
{
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;
}
*/

/*
// 10번
#include<iostream>
#include<cstring>
using namespace std;
typedef char * PSTR;
typedef struct Animal
{
	char name[20];
	int height;
	char home[8];
}Ani;
Ani A, B;

void Dog(const Ani &M) {
	cout << "개종류" << M.name << " 원산지" << M.home << " 키" << M.height << endl;
}
void Dog(PSTR ap, Ani &M) {
	sprintf(M.home, "%s", ap);
}
void Dog(Ani &M, int a) { M.height = a; }
void Dog(Ani &M, PSTR ap) { strcpy(M.name, ap); }
void Dog(Ani &M, PSTR ap, int a) { Dog(M, ap); Dog(M, a); }
void Dog(Ani &M, int a, PSTR ap, PSTR bp)
{
	Dog(M, a);
	Dog(M, ap);	Dog(bp, M);
}
void main()
{
	Dog("China", A);
	Dog(A, "Pug", 25);
	Dog(B, 18, "Chihuahua", "Mexico");
	Dog(A); Dog(B);
}
*/


/*
// 11번
#include<iostream>
template <class Any>		// 또는 typename Any
void Swap(Any &a, Any &b);
using namespace std;

int main()
{
	int i = 10;
	int j = 20;
	cout << "i,j = " << i << ", " << j << ".\n";
	cout << "두개의 정수형 데이터를 교환\n";
	Swap(i, j);
	cout << "교환후=> i,j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "\nx, y = " << x << ", " << y << ".\n";
	cout << "두개의 실수형 데이터를 교환\n";
	Swap(x, y);
	cout << "교환후 => x, y = " << x << ", " << y << ".\n";
	return 0;
}

template<class Any>
void Swap(Any &a, Any &b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}
*/



/*
// 12번
#include<iostream>
template <typename T>
void Swap(T &a, T &b);
template<typename T>
void Swap(T *a, T *b, int n);

void Show(int a[]);
const int Lim = 8;
int main()
{
	using namespace std;
	int i = 10, j = 20;
	cout << "교환전 i, j = " << i << ", " << j << ".\n";
	Swap(i, j);
	cout << "교환후 i, j = " << i << ", " << j << ".\n";

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,6,2,0,1,9,6,9 };
	cout << "\n원본 배열:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "교환된 배열:\n";
	Show(d1);
	Show(d2);
	return 0;
}

template<typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}
*/

/*
// 13번
#include<iostream>
using namespace std;
template<class T>		// 또는 템플릿<typename T>
T lesser(T a, T b)		// #1
{
	cout << "템플릿 함수" << endl;
	return a < b ? a : b;
}

int lesser(int a, int b)	// #2
{
	cout << "일반함수" << endl;
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}

int main()
{
	using namespace std;
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;

	cout << lesser(m, n) << endl;		// #2를 사용한다
	cout << lesser(x, y) << endl;		// double과 함께 #1을 사용한다
	cout << lesser<int>(m, n) << endl;		// int와 함께 #1을 사용한다
	cout << lesser<int>(x, y) << endl;		// int와 함께 #1을 사용한다

	return 0;
}
*/


/*
// 14번
#include<iostream>
using namespace std;
struct Job {
	char name[40];
	double salary;
	int floor;
};

void swap(Job &, Job &);	// 템플릿이 아닌 원형
template <typename T>	//템플릿 원형
void swap(T &, T &);	// Job형을 위한 명시적 특수화

void swap(Job &j1, Job &j2)
{
	cout << "템플릿이 아닌 원형~~~" << endl;
	Job j;
	j = j1;
	j1 = j2;
	j2 = j;
 }
template<typename T>	// 템플릿 원형
void swap(T &t1, T &t2)
{
	cout << "템플릿 원형~~~" << endl;
	T t;
	t = t1;
	t1 = t2;
	t2 = t;
}

void main()
{
	struct Job j1 = { "prodo", 1000, 1 };
	struct Job j2 = { "brown", 2000, 2 };

	cout << "== 교환 전 " << endl;
	cout << "j1= " << j1.name << " " << j1.salary << " " << j1.floor << endl;
	cout << "j2= " << j2.name << " " << j2.salary << " " << j2.floor << endl;

	cout << "== 교환 후 " << endl;
	swap(j1, j2);
	cout << "j1= " << j1.name << " " << j1.salary << " " << j1.floor << endl;
	cout << "j2= " << j2.name << " " << j2.salary << " " << j2.floor << endl;

}
*/

/*
// 15번
#include<iostream>
template < typename T>
void Swap(T &a, T &b);
using namespace std;
struct job {
	char name[40];
	double salary;
	int floor;
};


// 명시적 특수화
 void Swap(job &j1, job &j2);
void Show(job &j);

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << " " << j << "\n";

	Swap(i, j);			// void Swap(int &, int &)를 생성한다
	cout << "i, j = " << i << " " << j << "\n\n";

	job j1 = { "prodo", 10000, 7 };
	job j2 = { "brown", 20000, 9 };
	cout << "job 교환 전:\n";
	Show(j1);
	Show(j2);
	Swap(j1, j2);		// void Swap(job &, job &)를 사용한다
	cout << "job 교환 후:\n";
	Show(j1);
	Show(j2);
	return 0;
}

template<typename T>
void Swap(T &a, T &b)  // 일반 버전
{
	cout << "일반버전 swap() 사용 \n";
	T temp;
	temp = a;
	a = b;
	b = temp;
}


// job 구조체의 salary와 floor 맴버만 교환한다
void Swap(job &j1, job &j2)  // 특수화 버전
{
	cout << "특수화 버전 swap() 사용 \n";
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job &j)
{
	using namespace std;
	cout << j.name << ": (" << j.floor << "층에 거주) " << " " << j.salary << endl;
}
*/


/*
// 16번
// --- 템플릿 오버로딩
#include<iostream>

template < typename T >  // 템플릿 A
void ShowArray(T arr[], int n);

template <typename T >	// 템플릿 B
void ShowArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main(void)
{
	using namespace std;
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] = {
		{"prodo", 2400.0},
		{"neo", 1300.0},
		{"sally", 1800.0}
	};
	double *pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "재산 목록:\n";
	ShowArray(things, 6);		// 템플릿 A를 사용한다
	cout << "채무 목록:\n";
	ShowArray(pd, 3);		// 더 특수화된 템플릿 B를 사용한다
	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "템플릿 A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
	using namespace std;
	cout << "템플릿 B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}
*/





/*
// 27페이지 
// 1번
#include<iostream>
using namespace std;
void MySet(char *const ap, char ch = 0, int N = 1)
{
	for (int a = 0; a < N; a++)
		ap[a] = ch;
	ap[N] = NULL;
}

void main()
{
	char M[5], N[5];
	MySet(M, 'A');
	MySet(N, 'B', 3);
	cout << M << endl << N << endl;
}
*/

/*
// 2번
#include<iostream>
using namespace std;
char KK(char ap[], int a) { return(ap[a]); }
char KK(char ap[][4], int a) { return (ap[a][a]); }
char KK(char ap[][2][4], int a) { return (ap[a][a][a]); }
void main()
{
	char A[] = "ABC";
	char B[2][4] = { "DEF", "GHI" };
	char C[2][2][4] = { {"JKL","MNO"}, {"PQR","STU"} };
	char D[7] = { 0, };
	D[0] = KK(A, 1);
	D[1] = KK(B, 1);
	D[2] = KK(C, 1);
	D[3] = KK(B[1], 1);
	D[4] = KK(C[1][1], 1);
	D[5] = KK(C[1], 1);
	cout << D << endl;
}
*/

/*
// 3번
#include<iostream>
using namespace std;
#define mytoupper1(a) ((a) >=97 && ((a) <=122) ? ((a)-32):(a))
inline char mytoupper2(char a) { return (a >= 97 && 122 ? a - 32 : a); }
void main()
{
	cout << mytoupper1(98.5) << endl;
	cout << mytoupper2(98.5) << endl;
}
*/

/*
// 4번
#include<iostream>
using namespace std;
#include<cstring>
void myStrCpy(char *ap, char *bp) { strcpy(ap, bp); }
void myStrCpy(char *ap, char *bp, int n) { strncpy(ap, bp, n); ap[n] = NULL; }
void myStrCpy(char *ap, char ch, int n) { for (int a = 0; a < n; ap[a++] = ch); }
void main()
{
	char M[3][5] = { 0, };
	char S[20] = { 0, };
	myStrCpy(M[0], "ABC");
	myStrCpy(M[1], "DEFGH", 4);
	myStrCpy(M[2], 'Y', 3);
	myStrCpy(S, M[1], 2);
	myStrCpy(S + strlen(S), M[0] + 1, 2);
	myStrCpy(S + strlen(S), M[2], 2);
	cout << S << endl;
}
*/

/*
// 5번
#include<iostream>
using namespace std;
enum Boolean { False, True };

void myPut(int N, char ch = 32, Boolean M = False)
{
	for (int a = 1; a <= N; a++)
		cout << ch;
	if (M) cout << endl;
}

void ButterFly(int N = 1)
{
	for (int a = 1; a < N; a++)
	{
		myPut(N);
		myPut(a, '*');
		myPut((N - a) * 2 - 1);
		myPut(a, '*', True);
	}
	for (int a = 4; a >= 1; a--)
	{
		myPut(N);
		myPut(a, '*');
		if (a == N) cout << "\b";
		myPut((N - a) * 2 - 1);
		myPut(a, '*', True);
	}
}

void HourGlass(int N = 1, int a = 0)
{
	myPut(N);
	myPut(a);
	myPut((N - a) * 2 - 1, '*', True);
	if (a + 1 == N) return HourGlass(N, a + 1);
	myPut(N);
	myPut(a);
	myPut((N - a) * 2 - 1, '*', True);
}

void main()
{
	ButterFly(4);
	cout << "\n\n";
	HourGlass(4);
}
*/

/*
// 6번
#include<iostream>
using namespace std;
void KK(int a = 1, int b = 2)
{
	cout << "a=" << a << "  b=" << b << endl;
}
void main()
{
	KK(); KK(3); KK(4, 5);
}
*/

/*
// 7번
#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swap(double &a, double &b)
{
	double temp;
	temp = a;
	a = b;
	b = temp;
}
void main()
{
	int a, b;
	double f1, f2;
	cout << "두 정수 입력 : ";
	cin >> a >> b;
	swap(a, b);
	cout << "바뀐 정수 값 : " << a << " " << b << endl;
	cout << "\n\n";
	cout << "두 실수 입력 : ";
	cin >> f1 >> f2;
	swap(f1, f2);
	cout << "바뀐 실수 값 : " << f1 << " " << f2 << endl;
}
*/

/*
// 8번
#include<iostream>
#include<cstring>
using namespace std;
double max(double a, double b);
char* max(char *ap, char *bp);

void main()
{
	double a, b;
	char ap[50] = { 0, };
	char bp[50] = { 0, };

	cout << "두 실수 입력 : ";
	cin >> a >> b;
	cout << "큰 값 : " << max(a, b) << endl;
	cout << "\n\n";
	cout << "두 문자열 입력 : ";
	cin.get();
	cin.getline(ap, 50);
	cin.getline(bp,50);
	cout << "긴 문자열 : " << max(ap, bp) << endl;
}

double max(double a, double b)
{
	return { (b <= a) ? a : b };
}

char * max(char *ap, char *bp)
{
	return { (strlen(bp) <= strlen(ap)) ? ap : bp };
}
*/

/*
// 9번
#include<iostream>
using namespace std;
template <class T>
T max(T array[], int five)
{
	T max_num = array[0];
	for (int i = 0; i < five; i++)
	{
		if (max_num < array[i]) max_num = array[i];
	}
	return max_num;
}

int main()
{
	int ints[5] = { 123,431,231,560,323 };
	double dbls[5] = { 3.71, 5.84, 37.8, 5.59, 2.11 };

	cout << "가장 큰 int 값 : " << max(ints, 5) << endl;
	cout << "가장 큰 double 값 : " << max(dbls, 5) << endl;
}
*/



/*
// 10번
#include<iostream>
#include<cstring>
using namespace std;
template <class T>
T maxn(T array[], int num)
{
	T max_num = array[0];
	for (int i = 0; i < num; i++)
	{
		if (max_num < array[i]) max_num = array[i];
	}
	return max_num;
}

char * maxn(char * array[], int num)
{
	int max_num = 0;
	char *max = NULL;
	for (int i = 0; i < num; i++)
	{
		if (max_num < strlen(array[i])) {
			max_num = strlen(array[i]);
			max = array[i];
		}
	}
	return max;
}

int main()
{
	int ints[6] = { 123,431,231,560,323,212 };
	double dbls[4] = { 3.71, 5.84, 37.8, 5.59 };
	char * pstr[5] = {
		"Seong-il Yoon",
		"Technical Communication Laboratory",
		"Technical Editor",
		"C++ Primer Plus Fourth Edition",
		"Correctness is another name of TCL"
	};
	cout << "가장 큰 int 값: " << maxn(ints, 6) << endl;
	cout << "가장 큰 double 값: " << maxn(dbls, 4) << endl;
	cout << "가장 긴 문자열: " << maxn(pstr, 5) << endl;
}
*/




/*
// 11번
#include<iostream>
using namespace std;
struct debts {
	char *bank;
	double amount;
};

template <class T>
T ShowArray(T array[], int num)
{
	T sum = 0;
	for (int i = 0; i < num; i++)
		sum += array[i];
	return sum;
}

template<class T>
T ShowArray(T * array[], int num)
{
	T sum = 0;
	for (int i = 0; i < num; i++)
		sum += *array[i];
	return sum;
}

int main()
{
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] = {
		{"신한은행", 2400},
		{"제일은행", 1300},
		{"국민은행", 1800}
	};

	double *pd[3];
	for (int i = 0; i < 3; i++) 
		pd[i] = &mr_E[i].amount;
		
		
	cout << "홍길동의 재산 합계: " << ShowArray(things, 6) << endl;
	cout << "홍길동의 채무 합계: " << ShowArray(pd, 3) << endl;
}
*/



/*
// 12번
#include<iostream>
using namespace std;
void str_pm(char *str, char ch='\0')
{
	char tmp[80];
	int i;

	for (i = 0; ; i++)
	{
		tmp[i] = str[i];
		if (str[i] == ch) {
			tmp[i] = NULL;
			break;
		}
	}
	cout << tmp << endl;
	
}

int main()
{
	char str[80];
	cout << "문장 입력 : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	str_pm(str);
	str_pm(str, ch);
	return 0;

}
*/

/*
// 12번 - 오버로딩 사용
#include<iostream>
using namespace std;
void str_pm(char *str)
{
	cout << str << endl;
}
void str_pm(char *str, char ch)
{
	char tmp[80];
	int i;

	for (i = 0; ; i++)
	{
		tmp[i] = str[i];
		if (str[i] == ch) {
			tmp[i] = NULL;
			break;
		}
	}
	cout << tmp << endl;
}

int main()
{
	char str[80];
	cout << "문장 입력 : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	str_pm(str);
	str_pm(str, ch);
	return 0;

}
*/

/*
// 13번
#include<iostream>
using namespace std;
char * left(char *ap, int n)
{
	char *tmp;
	tmp = new char[n+1];
	int i;
	for (i = 0; i < n; i++)
	{
		tmp[i] = ap[i];
	}
	tmp[i] = NULL;
	return tmp;
}
long left(long ap, int n)
{
	int p = 1;
	int num;
	long tmp = ap;
	for (;tmp>0;)
	{
		p *= 10;
		tmp = tmp / 10;
	}
	p = p / 10;
	if (n == 1) {
		 num = p / n;
	}
	else {
		int a = 1;
		for (int k = 0; k < n - 1; k++)
			a *= 10;
		num = p / a; 
	}

	long re = ap / num;
	return re;
}


int main()
{
	char *trip = "Hawaii!!";
	unsigned long n = 12345678;

	for (int i = 0; i < strlen(trip); i++)
	{
		cout << left(n, i + 1) << endl;
		cout << left(trip, i+1) << endl;
	}
}
*/






/*
// 14번 - 러시안 룰렛
// main.cpp
#include "RussianRoulette.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
void main()
{
	using namespace std;
	int people;	// 게임 인원
	int bullet; // 총알 개수

	int ran_people;
	int ran_bullet;

	int Gun[6] = { 0, };  // 총 - 배열 (총알이 없으면 0, 있으면 1)

	cout << "게임 인원 (예:2) == > ";
	cin >> people;
	cout << "총알 개수 (6미만) == > ";
	cin >> bullet;
	if (bullet < 1 || 5 < bullet) {
		cout << "총알 개수가 적합하지 않습니다. 1에서 5사이의 수를 입력하세요.";
		cout << "총알 개수 (6미만) == > ";
		cin >> bullet;
	}

	srand(time(NULL));
	// bullet개 만큼의 총알을 총구에 랜덤 배정
	for (int i = 0; i < bullet; i++)
	{
		ran_bullet = rand() % 6 + 0;
		if (Gun[ran_bullet] == 0) { Gun[ran_bullet] = 1; }
		else i--;
	}


	cout << endl;
	cin.get();
	cout << "총을 돌렸습니다. 1번부터 시작합니다." << endl;
	for (int i=1; ;i++)
	{
		cout << "[" << i << "번]  ";
		cout << "탄창을 무작위로 돌렸습니다." << endl;
		cout << "엔터를 누르면 격발됩니다..." << endl;
		cin.get();

	
		ran_people = rand() % 6 + 0;
		if (playRussianRoulette(i, Gun[ran_people]) != 0) {
			cout << "-----> " << i << "번 참가자가 총에 맞았습니다." << endl;
			break;
		}

		if (i == people) i = 0;
	}

}

*/

