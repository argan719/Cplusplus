
/*
// �Լ� ������
// 5��
#include<iostream>
using namespace std;
double parn(int);
double(*pf)(int);

void main()
{
	pf = parn;

	double x = parn(4);
	double y1 = (*pf)(5);
	double y2 = pf(6);		// ���� ����

	cout << "x= " << x << endl;
	cout << "y1= " << y1 << endl;
	cout << "y2= " << y2 << endl;
}

double parn(int n)
{
	return n * n;
}
*/



// 1������ (1�� ~ 4��)

/*
// 1��
#include<iostream>
void cheers(int);
double cube(double x);
int main(void)
{
	using namespace std;
	cheers(5);
	cout << "�ϳ��� ���� �Է��Ͻʽÿ�: ";
	double side;
	cin >> side;
	double volume = cube(side);
	cout << "�� ���� ���̰� " << side << " ��Ƽ������ ������ü�� ���Ǵ� ";
	cout << volume << " ��������Ƽ�����Դϴ�.\n";
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
// 2��
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
		cout << "�������� �Է��Ͻʽÿ�: ";
		double factor;
		while (!(cin >> factor))
		{
			cout << "�߸� �Է��߽��ϴ�. ��ġ�� �Է��ϼ���: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "���α׷��� �����մϴ�.\n";
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
		cout << (i + 1) << "�� �ε����� ����: \n";
		cin >> temp;
		if (!cin)		// �Է� �ҷ�
		{
			cout << "�Է� �ҷ�; �Է� ������ �����ڽ��ϴ�.\n";
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
		cout << (i + 1) << "�� �ε���: \\";
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
// 3��
#include<iostream>
const int ArSize = 8;
int sum_arr(const int *begin, const int *end);
int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "���� ���� �� �հ�: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "ó�� �� ����� ����" << sum << "���� �Ծ����ϴ�.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "������ �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n";
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

// 4��




/*
// �Լ� ������
// 5��
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
// 6��
#include<iostream>
double gildong(int);
double moonsoo(int);
void estimate(int lines, double(*pf)(int));

int main()
{
	using namespace std;
	int code;

	cout << "�ʿ��� �ڵ��� �� ���� �Է��Ͻʽÿ�: ";
	cin >> code;
	cout << "ȫ�浿�� �ð� ����:\n";
	estimate(code, gildong);
	cout << "�ڹ����� �ð� ����:\n";
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
	cout << lines << "���� �ۼ��ϴ� �� ";
	cout << (*pf)(lines) << "�ð��� �ɸ��ϴ�.\n";
}
*/



/*
// 7��
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

	cout << "�Լ� ������:\n";
	cout << "�ּ� ��\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
	
	const double *(*pa[3])(const double *, int) = { f1,f2,f3 };
	const double *(**pb)(const double *, int) = pa;
	cout << "\n�Լ� �����͸� ���ҷ� ������ �迭:\n";
	cout << "�ּ� ��\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;

	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
	
	cout << "\n�����͸� ���ҷ� ������ �迭�� ����Ű�� ������:\n";
	cout << "�ּ� ��\n";
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
// 8��
#include<iostream>
using namespace std;
void KK(int N = 1)
{
	cout << N << "��";
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
// 20������
// 17�� - ���ӽ���ð��� üũ�ϴ� ���α׷� �ۼ�
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

	printf(" ���� ����: %d��\n", score);
	printf(" �ɸ� �ð�: %1f��\n", duration);
}
*/




/*
// 21������
// 18�� - �������
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
// �Լ� �ߺ�
// 10������ 9��
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
// 10��
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
	cout << "������" << M.name << " ������" << M.home << " Ű" << M.height << endl;
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
// 11��
#include<iostream>
template <class Any>		// �Ǵ� typename Any
void Swap(Any &a, Any &b);
using namespace std;

int main()
{
	int i = 10;
	int j = 20;
	cout << "i,j = " << i << ", " << j << ".\n";
	cout << "�ΰ��� ������ �����͸� ��ȯ\n";
	Swap(i, j);
	cout << "��ȯ��=> i,j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "\nx, y = " << x << ", " << y << ".\n";
	cout << "�ΰ��� �Ǽ��� �����͸� ��ȯ\n";
	Swap(x, y);
	cout << "��ȯ�� => x, y = " << x << ", " << y << ".\n";
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
// 12��
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
	cout << "��ȯ�� i, j = " << i << ", " << j << ".\n";
	Swap(i, j);
	cout << "��ȯ�� i, j = " << i << ", " << j << ".\n";

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,6,2,0,1,9,6,9 };
	cout << "\n���� �迭:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "��ȯ�� �迭:\n";
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
// 13��
#include<iostream>
using namespace std;
template<class T>		// �Ǵ� ���ø�<typename T>
T lesser(T a, T b)		// #1
{
	cout << "���ø� �Լ�" << endl;
	return a < b ? a : b;
}

int lesser(int a, int b)	// #2
{
	cout << "�Ϲ��Լ�" << endl;
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

	cout << lesser(m, n) << endl;		// #2�� ����Ѵ�
	cout << lesser(x, y) << endl;		// double�� �Բ� #1�� ����Ѵ�
	cout << lesser<int>(m, n) << endl;		// int�� �Բ� #1�� ����Ѵ�
	cout << lesser<int>(x, y) << endl;		// int�� �Բ� #1�� ����Ѵ�

	return 0;
}
*/


/*
// 14��
#include<iostream>
using namespace std;
struct Job {
	char name[40];
	double salary;
	int floor;
};

void swap(Job &, Job &);	// ���ø��� �ƴ� ����
template <typename T>	//���ø� ����
void swap(T &, T &);	// Job���� ���� ����� Ư��ȭ

void swap(Job &j1, Job &j2)
{
	cout << "���ø��� �ƴ� ����~~~" << endl;
	Job j;
	j = j1;
	j1 = j2;
	j2 = j;
 }
template<typename T>	// ���ø� ����
void swap(T &t1, T &t2)
{
	cout << "���ø� ����~~~" << endl;
	T t;
	t = t1;
	t1 = t2;
	t2 = t;
}

void main()
{
	struct Job j1 = { "prodo", 1000, 1 };
	struct Job j2 = { "brown", 2000, 2 };

	cout << "== ��ȯ �� " << endl;
	cout << "j1= " << j1.name << " " << j1.salary << " " << j1.floor << endl;
	cout << "j2= " << j2.name << " " << j2.salary << " " << j2.floor << endl;

	cout << "== ��ȯ �� " << endl;
	swap(j1, j2);
	cout << "j1= " << j1.name << " " << j1.salary << " " << j1.floor << endl;
	cout << "j2= " << j2.name << " " << j2.salary << " " << j2.floor << endl;

}
*/

/*
// 15��
#include<iostream>
template < typename T>
void Swap(T &a, T &b);
using namespace std;
struct job {
	char name[40];
	double salary;
	int floor;
};


// ����� Ư��ȭ
 void Swap(job &j1, job &j2);
void Show(job &j);

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << " " << j << "\n";

	Swap(i, j);			// void Swap(int &, int &)�� �����Ѵ�
	cout << "i, j = " << i << " " << j << "\n\n";

	job j1 = { "prodo", 10000, 7 };
	job j2 = { "brown", 20000, 9 };
	cout << "job ��ȯ ��:\n";
	Show(j1);
	Show(j2);
	Swap(j1, j2);		// void Swap(job &, job &)�� ����Ѵ�
	cout << "job ��ȯ ��:\n";
	Show(j1);
	Show(j2);
	return 0;
}

template<typename T>
void Swap(T &a, T &b)  // �Ϲ� ����
{
	cout << "�Ϲݹ��� swap() ��� \n";
	T temp;
	temp = a;
	a = b;
	b = temp;
}


// job ����ü�� salary�� floor �ɹ��� ��ȯ�Ѵ�
void Swap(job &j1, job &j2)  // Ư��ȭ ����
{
	cout << "Ư��ȭ ���� swap() ��� \n";
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
	cout << j.name << ": (" << j.floor << "���� ����) " << " " << j.salary << endl;
}
*/


/*
// 16��
// --- ���ø� �����ε�
#include<iostream>

template < typename T >  // ���ø� A
void ShowArray(T arr[], int n);

template <typename T >	// ���ø� B
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

	cout << "��� ���:\n";
	ShowArray(things, 6);		// ���ø� A�� ����Ѵ�
	cout << "ä�� ���:\n";
	ShowArray(pd, 3);		// �� Ư��ȭ�� ���ø� B�� ����Ѵ�
	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "���ø� A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
	using namespace std;
	cout << "���ø� B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}
*/





/*
// 27������ 
// 1��
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
// 2��
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
// 3��
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
// 4��
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
// 5��
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
// 6��
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
// 7��
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
	cout << "�� ���� �Է� : ";
	cin >> a >> b;
	swap(a, b);
	cout << "�ٲ� ���� �� : " << a << " " << b << endl;
	cout << "\n\n";
	cout << "�� �Ǽ� �Է� : ";
	cin >> f1 >> f2;
	swap(f1, f2);
	cout << "�ٲ� �Ǽ� �� : " << f1 << " " << f2 << endl;
}
*/

/*
// 8��
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

	cout << "�� �Ǽ� �Է� : ";
	cin >> a >> b;
	cout << "ū �� : " << max(a, b) << endl;
	cout << "\n\n";
	cout << "�� ���ڿ� �Է� : ";
	cin.get();
	cin.getline(ap, 50);
	cin.getline(bp,50);
	cout << "�� ���ڿ� : " << max(ap, bp) << endl;
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
// 9��
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

	cout << "���� ū int �� : " << max(ints, 5) << endl;
	cout << "���� ū double �� : " << max(dbls, 5) << endl;
}
*/



/*
// 10��
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
	cout << "���� ū int ��: " << maxn(ints, 6) << endl;
	cout << "���� ū double ��: " << maxn(dbls, 4) << endl;
	cout << "���� �� ���ڿ�: " << maxn(pstr, 5) << endl;
}
*/




/*
// 11��
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
		{"��������", 2400},
		{"��������", 1300},
		{"��������", 1800}
	};

	double *pd[3];
	for (int i = 0; i < 3; i++) 
		pd[i] = &mr_E[i].amount;
		
		
	cout << "ȫ�浿�� ��� �հ�: " << ShowArray(things, 6) << endl;
	cout << "ȫ�浿�� ä�� �հ�: " << ShowArray(pd, 3) << endl;
}
*/



/*
// 12��
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
	cout << "���� �Է� : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "���� �Է� : ";
	cin >> ch;
	str_pm(str);
	str_pm(str, ch);
	return 0;

}
*/

/*
// 12�� - �����ε� ���
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
	cout << "���� �Է� : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "���� �Է� : ";
	cin >> ch;
	str_pm(str);
	str_pm(str, ch);
	return 0;

}
*/

/*
// 13��
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
// 14�� - ���þ� �귿
// main.cpp
#include "RussianRoulette.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
void main()
{
	using namespace std;
	int people;	// ���� �ο�
	int bullet; // �Ѿ� ����

	int ran_people;
	int ran_bullet;

	int Gun[6] = { 0, };  // �� - �迭 (�Ѿ��� ������ 0, ������ 1)

	cout << "���� �ο� (��:2) == > ";
	cin >> people;
	cout << "�Ѿ� ���� (6�̸�) == > ";
	cin >> bullet;
	if (bullet < 1 || 5 < bullet) {
		cout << "�Ѿ� ������ �������� �ʽ��ϴ�. 1���� 5������ ���� �Է��ϼ���.";
		cout << "�Ѿ� ���� (6�̸�) == > ";
		cin >> bullet;
	}

	srand(time(NULL));
	// bullet�� ��ŭ�� �Ѿ��� �ѱ��� ���� ����
	for (int i = 0; i < bullet; i++)
	{
		ran_bullet = rand() % 6 + 0;
		if (Gun[ran_bullet] == 0) { Gun[ran_bullet] = 1; }
		else i--;
	}


	cout << endl;
	cin.get();
	cout << "���� ���Ƚ��ϴ�. 1������ �����մϴ�." << endl;
	for (int i=1; ;i++)
	{
		cout << "[" << i << "��]  ";
		cout << "źâ�� �������� ���Ƚ��ϴ�." << endl;
		cout << "���͸� ������ �ݹߵ˴ϴ�..." << endl;
		cin.get();

	
		ran_people = rand() % 6 + 0;
		if (playRussianRoulette(i, Gun[ran_people]) != 0) {
			cout << "-----> " << i << "�� �����ڰ� �ѿ� �¾ҽ��ϴ�." << endl;
			break;
		}

		if (i == people) i = 0;
	}

}

*/

