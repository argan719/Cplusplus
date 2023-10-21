
/*
// 1번
#include<iostream>
using namespace std;

int Plus(int a, int b)
{
	return a + b;
} 
struct CPlus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void main()
{
	int result;
	int(*pPlus)(int, int) = Plus;
	CPlus oPlus;

	result = Plus(10, 20);  // 1. 함수호출
	cout << result << endl;

	result = pPlus(10, 20);   // 2. 함수 포인터로 호출
	cout << result << endl;

	result = oPlus(10, 20);   // 3. 함수자(functor)로 호출
	cout << result << endl;
}
*/


/*
// 2번
#include<iostream>
using namespace std;
class Plus {
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus plus;
	cout << "plus(10,20): " << plus(10, 20) << endl;
	return 0;
}
*/


/*
// 3번
#include<iostream>
using namespace std;
class Equal
{
public:
	int operator()(int a, int b)
	{
		return a == b;
	}
};

int main()
{
	Equal cmp;
	cout << "pls(5,5): " << cmp(5, 5) << endl;  //암묵적호출
	cout << " cmp.operator()(10,20): " << cmp.operator()(10, 20) << endl;  //명시적호출
	cout << "Equal()(10,10): " << Equal()(10, 10) << endl;   // 임시객체를 통한 암묵적 호출
	return 0;
}
*/


/*
// 4번
#include<iostream>
#include<functional>
using namespace std;

int main()
{
	plus<int> add;
	cout << add(11, 22) << endl;
	cout << plus<int>()(100, 200) << endl;
	return 0;
}
*/


/*
// 5번 
// 1)
#include<iostream>
using namespace std;
int mySum(int num1)
{
	int sumRet = 0;
	sumRet += num1;
	return sumRet;
}

int main(void)
{
	int num1 = 10;
	int num2 = 20;

	auto ret = mySum(num1);
	cout << ret << endl;

	ret = mySum(num2);
	cout << ret << endl;

	return 0;
}
*/

/*
// 2)
#include<iostream>
using namespace std;
class MySum
{
	int sumRet = 0;
public:
	int operator()(int num1_)
	{
		sumRet += num1_;
		return sumRet;
	}
};

int main(void)
{
	int num1 = 10;
	int num2 = 20;

	// 2. 함수 객체 이용
	MySum sumP;
	int ret = sumP(num1);
	cout << ret << endl;

	ret = sumP(num2);
	cout << ret << endl;

	return 0;
}
*/

/*
// 6번 
#include<iostream>
using namespace std;
class Linear {
	double a;
	double b;
public:
	Linear(double s = 1, double y = 0) : a(s), b(y) {}
	double operator()(double x) { return b + a * x; }
};

int main()
{
	Linear f1;
	Linear f2(2.5, 10.0);
	double y1 = f1(12.5);
	double y2 = f2(0.4);
	cout << y1 << " " << y2 << endl;
	return 0;
}
*/

/*
// 7번
#include<iostream>
using namespace std;

class Money {
private:
	int _Money = 0;
public:
	int operator() () {
		return this->_Money;
	}
	void operator()(int N) {
		this->_Money += N;
	}
};

int main(void) {
	Money money;
	money(100);   //void operator()(int)
	int M = money();  // int operator()()
	cout << M;
}
*/

/*
// 8번
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

struct Plus {
	int operator()(int a, int b) const {
		return a + b;
	}
};

void main()
{
	vector<int> v1;
	vector<int> v2;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), Plus());

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";    // 11 22 33
	cout << endl;
}
*/


/*
// 9번 
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>

using namespace std;

template<typename T>
struct Plus
{
	T operator()(const T&a, const T&b) const
	{
		return a + b;
	}
};

void main()
{
	vector<int> v1;
	vector<int> v2;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), Plus<int>()); // transform에서 함수 대신 구조체의 operator() 호출

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";   // 11 22 33
	cout << endl;
}
*/


/*
// 10번
#include<iostream>
#include<functional>
using namespace std;

int main()
{
	equal_to<int> comp;
	greater_equal<int> ge;

	cout << comp(10, 10) << endl;   // 1
	cout << comp(10, 20) << endl;   // 0

	cout << ge(5, 3) << endl;   // 1
	cout << ge(3, 5) << endl;   // 0
}
*/


/*
// 조건자 함수를 사용하여 50보다 큰 정수만 검색하여 출력
// 11번 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

bool isGreaterThan50(int e) {
	return (e > 50);
}
int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(rand() % 100);  // 0~99 난수 10개 벡터에 삽입
	vector<int>::iterator it;

	// 이 부분- for문 잘 봐두기 - vector에서 이터레이터 이동시키면서 find_if쓰는 형태
	for (it = vec.begin(); ; it++) {
		it = find_if(it, vec.end(), isGreaterThan50);
		if (it == vec.end()) break;
		cout << *it << "발견" << endl;
	}
	return 0;
}
*/


/*
// 12번 
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

template<typename T>
void print(const T&v)
{
	typename T::const_iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main()
{
	vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(rand() % 100);

	print(vec);

	sort(vec.begin(), vec.end(), greater<int>()); // 함수에서 함수 호출
	print(vec);
	
	sort(vec.begin(), vec.end(), less<int>());
	print(vec);
	return 0;
}
*/

/*
// 13번
#include<iostream>
#include<algorithm>
using namespace std;

bool Compare(int N1, int N2) {
	if (N1 < N2) {   // 오름차순 정렬
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	int Array[] = { 5,3,2,1,7,8 };
	std::sort(Array, Array + 6, Compare);

	for (int i = 0; i < sizeof(Array) / sizeof(Array[0]); i++)
		cout << Array[i] << "  ";    // 1  2  3  5  7  8
}
*/

/*
// 14번 -logical_and
#include<iostream>
#include<functional>
using namespace std;

void main()
{
	int result;

	logical_and<int> and;
	result = and (10 == 10, 1 < 2);  // 객체 생성 후 호출
	cout << result << endl;

	result = logical_and<int>()(10 > 20, 'A' < 'B');  // 임시 객체 생성 후 호출
	cout << result << endl;

	if (logical_and<int>()(1, 1))
		cout << "true" << endl;
}
*/

/*
// 15번
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void main()
{
	vector<bool> v1;
	vector<bool> v2;
	vector<bool> v3(3);

	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);

	v2.push_back(false);
	v2.push_back(false);
	v2.push_back(true);

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), logical_and<bool>());

	for (int i = 0; i < v3.size(); i++)
	{
		if (v3[i])
			cout << "true  ";
		else
			cout << "false  ";
	}
	cout << endl;
	// false  false  true
}
*/

/*
// 16번
#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

void add10(int& elem)
{
	elem += 10;
}

void outint(int n) { cout << n << " "; }

int main()
{
	list<int> values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	for_each(values.begin(), values.end(), outint);
	for_each(values.begin(), values.end(), add10);
	cout << endl;

	for_each(values.begin(), values.end(), outint);
}
*/

/*
// 17번 
#include<iostream>
#include<algorithm>
#include<list>

using namespace std;
class Add {
private:
	int _v;

public:
	Add(int v) : _v(v) {}
	void operator() (int &elem) const {
		elem += _v;
	}
};

void outint(int n) { cout << n << " "; }

int main() {
	list <int> values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	for_each(values.begin(), values.end(), outint);
	for_each(values.begin(), values.end(), Add(50)); // 리스트 각각의 값에 50씩 더함 - 사용자가 더하는 값 변경 가능
	cout << endl;
	for_each(values.begin(), values.end(), outint);
}
*/




/*
// 문제풀이 15페이지
// 1번
#include<iostream>
#include<functional>
using namespace std;

bool Compare(int a, int b) {
	return a == b;
}

int main()
{
	equal_to<int> e;
	bool(*compare)(int, int) = &Compare;
	cout << "함수객체로 10과 20을 비교 : " << e(10, 20) << endl;
	cout << "함수로 10과 20을 비교 : " << equal_to<int>()(10, 20) << endl;
	cout << "함수포인터로 10과 20을 비교 : " << compare(10, 20) << endl;

}
*/

/*
// 2번
#include<iostream>
using namespace std;
class MoneyBox {
private:
	int num;
public:
	MoneyBox() { num = 0; }
	int operator()(int n) {
		num += n;
		return num;
	}
};

int main()
{
	MoneyBox moneyBox;
	cout << "moneyBox(100): " << moneyBox(100) << endl;
	cout << "moneyBox(500): " << moneyBox(500) << endl;
	cout << "moneyBox(2000): " << moneyBox(2000) << endl;
	return 0;
}
*/

/*
// 3번
#include<iostream>
using namespace std;

template<class T>
class Multiple {
public:
	int operator()(T a, T b) {
		return a * b;
	}
};

int main()
{
	Multiple<int> m;
	cout << "2 * 7 = " << m(2, 7) << endl;
	cout << "3 * 5 = " << m(3, 5) << endl;

}
*/

/*
// 4번
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void print(int d)
{
	cout << d << " ";
}
int main()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3(10);

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	cout << "V1 : ";
	for (int i = 0; i < v1.size(); i++) {
		print(v1[i]);
	}
	cout << endl << endl;
	cout << "V2 : ";
	for (int i = 0; i < v2.size(); i++) {
		print(v2[i]);
	}
	cout << endl << endl;
	cout << "V1 + V2 : ";

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
	for (int i = 0; i < v1.size(); i++) {
		print(v3[i]);
	}
}
*/

/*
// 5번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Sum {
private:
	int sum = 0;  // 누적합
public:
	int operator()(int v) {
		sum += v;
		return sum;
	}
};
int main()
{
	vector<int> v;
	Sum sum;  // 누적해서 더해져야 하기 때문에 한 객체에 대해 ( ) 호출해야 함.
	v.push_back(10);  // 그래야지 한 객체의 필드에 계속 더해지기 때문에
	v.push_back(20);
	v.push_back(30);
	
	for (int i = 0; i < v.size(); i++) {
		cout << sum(v[i]) << " ";   // 10 30 60
	}
}
*/

/*
// 6번
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void print(int d)
{
	cout << d << " ";
}
int main()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3(10);

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	cout << "V1 : ";
	for (int i = 0; i < v1.size(); i++) {
		print(v1[i]);
	}
	cout << endl << endl;
	cout << "V2 : ";
	for (int i = 0; i < v2.size(); i++) {
		print(v2[i]);
	}
	cout << endl << endl;
	cout << "V1 + V2 : ";

	transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), plus<int>());
	for (int i = 0; i < v1.size(); i++) {
		print(v1[i]);
	}
}
*/

/*
// 7번
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int>vec;
	vec.push_back(100);
	vec.push_back(1000);
	vec.push_back(1020);
	vec.push_back(500);

	cout << "sort전 : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	sort(vec.begin(), vec.end(), greater<int>());

	cout << "\n\nsort후 : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}
*/

/*
// 8번
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

struct Minus {
	int operator()(int a, int b) {
		return a - b;
	}
};
struct mul {
	int num = 1;
	int operator()(int n) {
		num *= n;
		return num;
	}
};

int main()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3(5);

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);  
	v1.push_back(50);

	v2.push_back(1);
	v2.push_back(2);  
	v2.push_back(3); 
	v2.push_back(4); 
	v2.push_back(5);

	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\n\nv2 : ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	cout << "\n\nv1+v2 : ";
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\nv1*v2 : ";
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), multiplies<int>());
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\n-v1 : ";
	transform(v1.begin(), v1.end(), v3.begin(), negate<int>());
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\nv1 인접 원소와의 차 : ";
	for (int i = 0; i < v1.size(); i++) { // 자신의 오른쪽 원소와의 차를 구하고 맨 마지막 원소는 자신의 왼쪽 원소와의 차를 구함.
		if(i <4) v3[i] = Minus()(v1[i], v1[i + 1]);
		else v3[i] = Minus()(v1[i - 1], v1[i]);
	}
	//transform(v1.begin(), v1.end(), v3.begin(), minus<int>()); 오류남. 벡터한개 더 설정해야 minus가능(벡터 두개로 해야 transform사용가능)
	// 한 벡터 안에서의 차를 구하려면 minus못씀. - 내가 직접 만들어서 써야 함.
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	mul a;
	cout << "\n\nv1 원소의 곱 누적 : ";
	for (int i = 0; i < v1.size(); i++) {
		v3[i]=a(v1[i]);
	}
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	mul m;
	int sum;
	cout << "\n\nv1 모든 원소의 곱 : ";
	for (int i = 0; i < v1.size(); i++) {
		sum= m(v1[i]);
	}
	cout << sum << " ";
}
*/

/*
// 9번
#include<iostream>
#include<list>
using namespace std;
template<class T>
class Compare {
public:
	bool operator()(T elem) {
		return (elem >= 10);  // true면 삭제
	}
};

int main()
{
	list<int> my_list;
	list<int>::iterator it;
	my_list.push_back(10);
	my_list.push_back(100);
	my_list.push_back(5);
	my_list.push_back(4);
	my_list.push_back(70);
	my_list.push_back(2);

	cout << "삭제전 list : ";
	it = my_list.begin();
	while (it != my_list.end()) {
		cout << *it << "  ";
		it++;
	}

	Compare<int> compare;
	it = my_list.begin();
	while (it != my_list.end()) {
		if (compare(*it)) it = my_list.erase(it);
		else it++;
	}


	cout << "\n\n삭제후 list : ";
	it = my_list.begin();
	while (it != my_list.end()) {
		cout << *it << "  ";
		it++;
	}

}
*/

/*
// 10번
#include<iostream>
#include<array>
using namespace std;

class sumOdd {
	int sum= 0;
public:
	int operator()(int a) {
		if (a % 2 != 0) {
			sum += a; 
		}
		return sum;
	}
};
class sumEven {
	int sum = 0;
public:
	int operator()(int a) {
		if (a % 2 == 0) {
			sum += a;
		}
		return sum;
	}
};

int main()
{
	array<int, 10> theList = { 1,2,3,4,5,6,7,8,9,10 };
	int sum_odd, sum_even;
	sumEven even;
	sumOdd odd;
	
	cout << "짝수합: ";
	for (int i = 0; i < theList.size(); i++) {
		sum_even = even(theList[i]);
	}
	cout << sum_even;

	cout << "\n\n홀수합: ";
	for (int i = 0; i < theList.size(); i++) {
		sum_odd = odd(theList[i]);
	}
	cout << sum_odd << endl;
}
*/


