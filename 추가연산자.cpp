/*
#include<iostream>
#include<iomanip>
using namespace std;
int a = 5;
void KK() { a++; }
void MM()
{
	int a = 10;
	::a++;	a += 2;
	cout << setw(3) << a << endl;
}

void main()
{
	KK(); MM();
	cout << setw(3) << ::a << setw(3) << a << endl;
}
*/


/*
#include<iostream>
#include<iomanip>
using namespace std;
class Date
{
	int month, day;
	static int year;
public:
	Date(int m = 0, int d = 0) :month(m), day(d) { }
	static void Title() {
		cout << setw(10) << "년" << setw(10) << "월" << setw(10) << "일" << endl;
	}
	void Disp();
};

int Date::year = 1919;
void Date::Disp() {
	cout << setw(10) << year << setw(10) << month << setw(10) << day << endl;
}

void main()
{
	Date Kor(3, 1);
	Date::Title();
	Kor.Disp();
}
*/


/*
#include<iostream>
int main()
{
	using namespace std;
	int nights = 1001;
	int *pt = new int;
	*pt = 1001;

	cout << "nights의 값 = ";
	cout << nights << ": 메모리 위치 " << &nights << endl;
	cout << "int 형";
	cout << "값 = " << *pt << ": 메모리 위치 = " << pt << endl;

	double *pd = new double;
	*pd = 10000001.0;

	cout << "double 형";
	cout << "값 = " << *pd << ":메모리 위치 = " << pd << endl;
	cout << "포인터 pd의 메모리 위치: " << &pd << endl;
	cout << "pt의 크기 = " << sizeof(pt);
	cout << ": *pt의 크기 = " << sizeof(*pt) << endl;
	cout << "pd의 크기 = " << sizeof(pd);
	cout << ": *pd의 크기 = " << sizeof(*pd) << endl;
	return 0;
}
*/


/*
#include<iostream>
using namespace std;
void main()
{
	char *ap;
	ap = new char;
	*ap = 'A';
	cout << (int)ap << endl << *ap << endl;
}
*/


/*
#include<iostream>
using namespace std;
void main()
{
	int *p = new int[5];
	for (int i = 0; i < 5; i++)
		p[i] = (i + 1) * 10;

	for (int i = 0; i < 5; i++)
		cout << p[i] << " ";
}
*/


/*
#include<iostream>
using namespace std;
typedef struct KT
{
	int month, day;
}Gu;

void main()
{
	Gu M = { 5, 12 };
	Gu *ap = new Gu;
	*ap = M;
	cout << ap->month << "월" << ap->day << "일" << endl;
}
*/


/*
#include<iostream>
#include<cstring>
using namespace std;
void KK(char *ap, char *bp)
{
	char *cp;
	int len = strlen(ap) + strlen(bp);	cp = new char[len + 1];
	strcpy(cp, ap);  strcat(cp, bp);	cout << cp << endl;		delete[] cp;
}

void main()
{
	char M[] = "LOVE";		char N[] = "KOREA";
	KK(N, M);
}
*/


/*
#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
void KK(char *ap)
{
	char *M = new char[strlen(ap) + 1];
	strcpy(M, ap);	_strrev(M);		
	if (islower(M[0])) M[0] = toupper(M[0]);
	strcpy(ap, M);	cout << M << endl;		delete[] M;
}

void main()
{
	char K[] = "abcd";
	KK(K); KK(K);
}
*/


/*
#include<iostream>
#include<cstring>
using namespace std;
void Swap(char ap[], char bp[])
{
	int N = strlen(ap) > strlen(bp) ? strlen(ap) : strlen(bp);
	char *imp = new char[N + 1];
	strcpy(imp, ap);	strcpy(ap, bp);		strcpy(bp, imp);
	delete[] imp;
}

void main()
{
	char M[5] = "AB", N[5] = "CDE";
	Swap(M, N);
	cout << M << endl << N << endl;
}
*/


/*
#include<iostream>
int main()
{
	using namespace std;
	double * p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1]은 " << p3[1] << "입니다.\n";
	p3 = p3 + 1;
	cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
	cout << "p3[1]이 " << p3[1] << "입니다.\n";
	p3 = p3 - 1;
	delete[] p3;
	return 0;
}
*/




/*
// 9번
#include<iostream>
int main()
{
	using namespace std;
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3,2,1 };

	//배열의 주소를 알아내는 두 가지 방법
	double * pw = wages;
	short * ps = &stacks[0];
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "pw 포인터에 1을 더함: \n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps 포인터에 1을 더함:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << "배열 표기로 두 원소에 접근\n";
	cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
	
	cout << "포인터 표기로 두 원소에 접근\n";
	cout << "*stacks = " << *stacks
		<< ", *(stacks+1) = " << *(stacks + 1) << endl;

	cout << sizeof(wages) << " = wages 배열의 크기\n";
	cout << sizeof(pw) << " = pw 포인터의 크기\n";
	return 0;
}
*/



/*
// 10번  질문
#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	char animal[20] = "bear";
	const char * bird = "wren";
	char *ps;

	cout << animal << " and ";
	cout << bird << "\n";
	// cout << ps << "\n";

	cout << "동물의 종류를 입력하십시오: ";
	cin >> animal;
	// cin >> ps;

	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() 사용 전:\n";
	cout << (int *)animal << ": " << animal << endl;
	cout << (int *)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "strcpy() 사용 후:\n";
	cout << (int *)animal << ": " << animal << endl;
	cout << (int *)ps << ": " << ps << endl;
	delete[] ps;
	return 0;

}
*/





// 문제풀이 14페이지~

/*
// 1번
#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	char text[50];
	char point;
	int num = 0;
	int before_num;
	cout << "문자열 입력 : ";
	cin.getline(text, 50);

	cout << endl << "문자열의 길이 : " << strlen(text) << endl;
	cout << endl<< "문자입력 : ";
	cin >> point;

	int i;
	for (i = 0; i < strlen(text); i++)
	{
		if (text[i] == point) {
			before_num = num; break;
		}
		num++;
	}
	if (i == strlen(text)) {
		cout << "입력하신 문자가 문자열에 존재하지 않습니다." << endl;
	}
	else {
		cout << point << " 이전까지의 길이 : " << before_num << endl;
	}

}
*/




/*
// 2번
#include<iostream>
#include<string>
using namespace std;
char *Add(char *bp, char ch)
{
	char *tmp = new char[strlen(bp)+1];
	strcpy(tmp, bp);
	bp = new char[strlen(tmp) + 2];
	strcpy(bp, tmp);
	bp[strlen(tmp)] = ch;
	bp[strlen(tmp)+1] = '\0';

	return bp;
}

int main()
{
	char word;
	char *text = new char[1];
	text[0]='\0';
	cout << "문자를 입력 : ";
	//
	//do {
	//	//Add(text, word);
	//	word = cin.get();
	//	if (word == EOF) break;
	//} while (1); 1);

	do {
		word = cin.get();
		if (word =='.') break;
		text=Add(text, word);
	} while (1);

	cout << "입력된 문자열 = " << text;
}
*/


/*
// 2번 
#include<iostream>
#include<cstring>
using namespace std;
void Add(char **ap, char word)
{

	char *tmp = new char[strlen(*ap)+1];
	strcpy(tmp, *ap);
	*ap = new char[strlen(tmp) + 2];
	strcpy(*ap, tmp);
	(*ap)[strlen(tmp)] = word;
	(*ap)[strlen(tmp) + 1] = '\0';

}

int main()
{
	char word;
	char *text;
	text = new char[1];
	text[0] = '\0';
	cout << "문자를 입력 : ";
	word = cin.get();
	while (word != '.')
	{
		Add(&text, word);
		word = cin.get();
	}
	cout << "입력된 문자열 = " << text << endl;
}
*/






/*
// 3번
#include<iostream>
#include<iomanip>
using namespace std;
float sum(int *score)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += score[i];
	return sum / 3.0;
}
int main()
{
	int score[3];
	cout << "세 과목의 점수 입력 : ";
	cin >> score[0] >> score[1] >> score[2];
	float aver = sum(score);
	cout << fixed;
	cout << "세 과목의 평균 : " << setprecision(2) << aver << endl;
}
*/







/*
// 9번
#include<iostream>
using namespace std;

struct Profile {
	char name[20];
	int age;
	double height;
	char *intro;
};

void input(Profile *pr);
void prn(const Profile *cpr);

int main()
{
	Profile person;
	// 입력
	input(&person); 
	// 출력
	prn(&person);
}

void input(Profile *pr)
{
	char s[100];
	cout << "이름입력 : ";
	cin >> pr->name;
	cout << "나이입력 : ";
	cin >> pr->age;
	cout << "키 입력 : ";
	cin >> pr->height;
	cin.get();		// 인사말 입력 먹어서 넣어줌
	cout << "인사말 : ";
	cin.getline(s, 100);		// -> 이런식으로 100으로 배열 해놓고 입력받아서 길이 확인후 동적할당해도 되는건지 질문 -> 맞음
	pr->intro = new char[strlen(s)+1];  
	strcpy(pr->intro, s);
}

void prn(const Profile *cpr)
{
	cout << endl << endl;
	cout << "이름 : " << cpr->name << endl;
	cout << "나이 : " << cpr->age << endl;
	cout << "키 : " << cpr->height << endl;
	cout << cpr->intro << endl;

}
*/







/*
// 10번
#include<iostream>
using namespace std;

int main()
{
	char *text;
	text = new char[50];   // 전체 문자열
	char find[30];		// 찾을 문자열
	char change[30];	// 바꿀 문자열
	cout << "문자열을 입력하세요 : ";
	cin.getline(text, 50);
	cout << "찾을 문자열 : ";
	cin.getline(find, 30);
	cout << "바꿀 문자열 : ";
	cin.getline(change, 30);
	int index = 0;
	char tmp[50];
	char after[50];

	char *start = text;
	for (int i = 0; ; i++)
	{
		if (*text == 32 || *text == '\0') {
			tmp[index] = '\0';
			if (strcmp(tmp, find) == 0) {
				strcpy(after, text);
				text -= strlen(tmp);
				strcpy(text, change);
				text += strlen(change);
				strcat(text, after);
			}
			if (*text == NULL) break;
			index = 0;
			text++;
		}

		tmp[index++] = *text++;

	}

	cout << "결과 : " << start;

}

*/




// 14페이지 문제풀이
// 11번  - O 
// 13번 - O
// (포인터 이용) 2문제 풀기


/*
// 11번
#include<iostream>
using namespace std;

void sub_string(char *s, int start, int n, char *result);

void main()
{
	char s[100];
	int start;
	int n;
	char result[100];
	cout << "문자열을 입력하세요 : ";
	cin.getline(s, 100);
	cout << "시작위치 : ";
	cin >> start;
	cout << "길이 : ";
	cin >> n;
	sub_string(s, start, n, result);
	cout << "결과 : ";
	cout << result << endl;

}

void sub_string(char *s, int start, int n, char *result)
{
	int num, k;
	for (int i = 0; i < strlen(s); i++)
	{
		if (i == start - 1) {
			for (num = 0, k = i; num < n; num++, k++)
			{
				if (s[k] == '\0') {
					cout << "원하는 길이만큼의 문자가 존재하지 않습니다.";
					break;
				}
				result[num] = s[k];
			}
			result[num] = '\0';
			break;
		}
	}
}
*/


/*
// 13번
#include<iostream>
using namespace std;
void swap(char &ap, char &bp);

void main()
{
	char *ap = "apple";
	char *bp = "banana";

	cout << "바꾸기 전의 문자열 : ";
	cout << ap << "  " << bp << endl;
	swap(ap, bp);
	cout << "바꾼 후의 문자열 : ";
	cout << ap << "  " << bp << endl;
}

void swap(char &ap, char &bp)
{
	char *tmp = '\0';
	*tmp = ap;
	ap = bp;
	bp = *tmp;
}
*/



// reference 변수 & 리턴
// 7페이지

/*
// 11번
#include<iostream>
using namespace std;
void main()
{
	int a = 5;
	int b = a;
	int &c = a;
	c = 35;
	cout << "a=" << a << " b=" << b << " c=" << c << endl;
	cout << (int)&a << " " << (int)&b << " " << (int)&c << endl;
}
*/

/*
// 12번
#include<iostream>
using namespace std;
void main()
{
	int a = 5;
	int &b = a;
	int &c = b;
	c += b += a;
	cout << "a=" << a << " b=" << b << " c=" << c << endl;
	cout << (int)&a << " " << (int)&b << " " << (int)&c << endl;
}
*/

/*
// 13번
#include<iostream>
using namespace std;
void KK(int &c)
{
	c = 20;
}
void main()
{
	int a = 5;
	KK(a);
	cout << "a=" << a << endl;
}
*/


/*
// 14번
#include<iostream>
using namespace std;

int day = 3;
int &KK(int su)
{
	day += su;
	return(day);
}
void main()
{
	int a;
	cout << KK(2) << endl;
	a = KK(3);
	KK(4) += 5;
	cout << "a=" << a << " day=" << day << endl;
}
*/


/*
// 15번
#include<iostream>
void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);
int main()
{
	using namespace std;
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "참조를 이용하여 내용들을 교환:\n";
	swapr(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << "지갑 2 = " << wallet2 << "원\n";

	cout << "포인터를 이용하여 내용들을 다시 교환:\n";
	swapp(&wallet1, &wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "값으로 전달하여 내용 교환 시도:\n";
	swapv(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";
	return 0;
}

// 참조 이용
void swapr(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

// 포인터 이용
void swapp(int *p, int *q)
{
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

// 값 이용 - 교환 안됨
void swapv(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
*/


/*
// 16번
#include<iostream>
double cube(double a);
double refcube(double &ra);
int main()
{
	using namespace std;
	double x = 3.0;

	cout << cube(x);
	cout << " = " << x << "의 세제곱\n";
	cout << refcube(x);
	cout << " = " << x << "의 세제곱\n";
	return 0;
}

double cube(double a)
{
	a *= a * a;
	return a;
}

double refcube(double &ra)
{
	ra *= ra * ra;
	return ra;
}
*/


/*
// 17번
#include<iostream>
#include<string>
using namespace std;
struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws &source);

int main()
{
	// 부분 초기화 - 맴버는 0에 세팅된 상태로 남는다
	free_throws one = { "Prodo", 13, 14 };
	free_throws two = { "Brown", 10, 16 };
	free_throws three = { "Neo", 7, 9 };
	free_throws four = { "Coni", 5, 9 };
	free_throws five = { "Sally", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };
	// 초기화하지 않음
	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
	cout << endl;
	//리턴 값을 매개변수로 사용한다
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	cout << endl;
	//리턴 값을 대입 값으로 사용한다
	dup = accumulate(team, five);
	cout << " team 출력:\n";
	display(team);
	cout << " 대입 이후 dup 출력:\n";
	display(dup);
	set_pc(four);
	cout << endl;
	// 문제의 소지가 있는 대입
	accumulate(dup, five) = four;
	cout << "문제의 소지가 있는 대입 이후 dup 출력:\n";
	display(dup);
	return 0;
}

// 출력용 함수
void display(const free_throws & ft)
{
	using std::cout;
	cout << "Name: " << ft.name << "\n";
	cout << "Made: " << ft.made << "\t";
	cout << "Attempts: " << ft.attempts << "\t";
	cout << "Percent: " << ft.percent << "\n";
}

void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
*/


/*
// 18번
#include<iostream>
using namespace std;

char c = 'K';

char &r() {
	return (c);
}

void main()
{
	r() = 'B';
	cout << c << endl;
}
*/


/*
// 19번
#include<iostream>
using namespace std;

char &find(char s[], int index) {
	return s[index];	// 참조리턴
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';	// name[0]='S'로 변경
	cout << name << endl;

	char &ref = find(name, 2);
	ref = 't';	// name = "Site";
	cout << name << endl;
}
*/





// 14페이지~ 문제풀이
// 참조변수, 리턴

/*
// 4번
#include<iostream>
using namespace std;
int k;
void KK1(int a) { k += ++a; }
void KK2(int *a) { k += ++*a; }
void KK3(int &a) { k += ++a; }

void main()
{
	int b = 10, c = 20, d = 30;

	KK1(b);
	KK2(&c);
	KK3(d);
	k += (b + c + d);
	cout << k << endl;
}
*/

/*
// 5번
#include<iostream>
#include<cstring>
using namespace std;
int year = 2003;
char M[] = "ABCD";
int Get1() { return(year); }
int & Get2() { return(year); }
char Get3(int a) { return(M[a]); }
char * Get4(int a) { return (M + a); }
char & Get5(int a) { return(M[a]); }
void main()
{
	int b;
	char K[10] = { 0 };
	Get2()++;
	b = Get1() + Get2();
	K[0] = Get3(1);
	K[1] = Get5(0);
	cout << K[1];
	Get5(2) = 'Y';
	strcpy(K + 2, M + 1);
	Get5(1) += 32;
	cout << "M=" << M;
	cout << " K=" << K << endl;
}
*/

/*
// 6번
#include<iostream>
using namespace std;
void main()
{
	int a = 5;
	int &b;
	b = a;
	cout << "a=" << a << " b=" << b << endl;
}
*/

/*
// 7번
#include<iostream>
#include<cstring>
using namespace std;
int &counter();
int cnt = 0;
int main()
{
	int res;
	res = counter();
	cout << res << endl;
	counter() = 10;
	cout << cnt << endl;
	counter()++;
	cout << cnt << endl;
	cout << counter() + 5 << endl;
	return 0;
}

int &counter()
{
	cnt++;
	return cnt;
}
*/


/*
// 8번 (1)
#include<iostream>
using namespace std;
int &Ref(int &ref) {
	ref++;
	return ref;
}
int main(void)
{
	int num1 = 1;
	int &num2 = Ref(num1);
	num1++;
	num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
*/

/*
// 8번 (2)
#include<iostream>
using namespace std;
int Ref(int &ref) {
	ref++;
	return ref;
}
int main(void)
{
	int num1 = 1;
	int num2 = Ref(num1);
	num1++;
	num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
*/

/*
// 12번
#include<iostream>
using namespace std;
struct Savings {
	int w500;
	int w100;
	int w50;
	int w10;
};

void init(Savings &s);  // 초기화용 함수
void save(Savings &s, int u, int n);
int total(Savings &s);

void main()
{
	int money, num;
	Savings s;
	init(s);
	for (;;)
	{
		cout << "동전의 금액 :";
		cin >> money;
		if (money < 0) break;
		cout << "동전의 개수 :";
		cin >> num;
		//저장
		save(s, money, num);
		cout << endl;
	}
	cout<< endl << endl;
	cout << "==>총 저금액 " << total(s) << endl;

}

void init(Savings &s)
{
	s = { 0 };
}

void save(Savings &s, int u, int n)
{
	switch (u) {
	case(500): s.w500 += n; break;
	case(100): s.w100 += n; break;
	case(50): s.w50 += n; break;
	case(10): s.w10 += n; break;
	}
}

int total(Savings &s)
{
	int sum = 0;
	sum += 500 * s.w500;
	sum += 100 * s.w100;
	sum += 50 * s.w50;
	sum += 10 * s.w10;
	return sum;
}
*/


/*
// 14번
#include<iostream>
#include<ctime>
using namespace std;

struct Goods {
	char item[50];	// 품목
	int price;		// 단가
	int year;	// 유통기한(년도)
	int mon;	// 유통기한(월)
	int day;	// 유통기한(일)
	int discount;	// 할인율
};

void input(Goods &s);		// 입력함수
void selling_price(Goods &s, int buy, int limit);	// 할인율과 판매가격결정함수
void prn(const Goods &s);	// 출력함수

int tit_days(int y, int m, int d);	// 년,월,일로 총일수 계산
int leep_check(int year);	// 해당년도가 윤년인지 검사



void main()
{
	time_t now;
	tm *tp;

	time(&now);
	tp = localtime(&now);	// 현재 날짜를 구한다

	Goods s;
	input(s);
	int buy_date = tit_days(tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday);	// 오늘까지 총 날짜수 구하기
	int limit_date = tit_days(s.year, s.mon, s.day);		// 유통기한까지 총 날짜수 구하기
	selling_price(s, buy_date, limit_date);
	prn(s);
}

void input(Goods &s)
{
	cout << "품목입력 : ";
	cin >> s.item;
	cout << "단가입력 : ";
	cin >> s.price;
	cout << "유통기한입력 : ";
	cin >> s.year >> s.mon >> s.day;
}

void prn(const Goods &s)
{
	cout << s.item << "의 할인율" << endl;
	cout << "품명 : " << s.item << endl;
	cout << "단가 : " << s.price << endl;
	cout << "유통기한 : " << s.year << "-" << s.mon << "-" << s.day << endl;
	cout << "할인율 : " << s.discount << "%" << endl;
}

int tit_days(int y, int m, int d)
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	for (int i = 1; i < y; i++)
	{
		sum += leep_check(i);
	}
	for (int i = 1; i < m; i++)
	{
		sum += month[i];
		if ((leep_check(y) == 366) && i==2) sum += 1;
	}
	sum += d;
	return sum;
}

int leep_check(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 366;
	}
	else return 365;
}

void selling_price(Goods &s, int buy, int limit)
{
	int left = limit - buy;
	if (left < 0) {
		cout << "유통기한이 지났습니다!" << endl;
		s.price = 000;
		s.discount = 0;
	}
	else if (0 <= left && left <= 3) {
		s.price -= s.price*0.5;
		s.discount = 50;
	}
	else if (3 < left && left <= 10) {
		s.price -= s.price*0.2;
		s.discount = 20;
	}
	else if( 10 <left) s.discount = 0;
}
*/

