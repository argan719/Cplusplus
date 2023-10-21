
/*
// 1번
#include<iostream>
#include<string>
using namespace std;

// 일반 함수 정의
void sum1(int a, int b)
{
	cout << "함수 : " << a + b << endl;
}

int main(void) {
	 
	//일반 함수 호출
	sum1(10, 20);

	//람다함수
	[](int a, int b)
	{
		cout << "람다 : " << a + b << endl;
	}(30, 40);

	return 0;
}
*/

/*
// 2번
#include<array>
#include<algorithm>
#include<iostream>

using namespace std;
// 함수 객체로 구현
struct SumFunctor {
	SumFunctor(int &number) : sum(number) {}

	void operator()(int & number) {
		sum += number;
	}

private:
	int& sum;
};

int main()
{
	array<int, 5> numbers = { 1,2,3,4,5 };
	int sum = 0;

	for_each(numbers.begin(), numbers.end(), SumFunctor(sum));
	cout << "함수객체로 합계산" << sum << endl;

	sum = 0;

	// lambda로 구현
	for_each(numbers.begin(), numbers.end(), [&sum](int &number) {
		sum += number;
	});
	cout << "람다로 합계산 " << sum << endl;

	return 0;
}
*/
/*
// 3번
#include<iostream>
#include<string>
using namespace std;

int main()
{
	[](string name) {
		cout << "My name is " << name << endl;
	}("홍길동");

	// My name is 홍길동
	return 0;
}
*/


/*
// 4번
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int result1 = 1;
	int result2 = 2;
	int result3 = 3;
	int result4 = 4;
	// 람다 안에서는 이 변수들을 사용 못함(같은 메인함수 안에 있더라도 사용x. 람다 외부이기 때문에)
	// => 캡쳐를 하면 쓸 수 있음.

	// 일부 복사
	cout << "1. 특정변수 복사" << endl;
	[result1, result2](int a, int b) { // 이렇게 캡쳐하는 걸 copy라고 함. 람다 내부에서 쓸 수는 있지만 값 변경은 못함.
		cout << "result1=" << result1 << "  result2" << result2 << endl;
		cout << "a=" << a << "  b=" << b << endl;
		cout << "result1 + a + b : " << result1 + a + b << endl;
		// result1,2 캡쳐했기 때문에 람다 안에서 사용가능.
		//cout << result1++;  이런 연산 못함. copy이기 때문에(참조여야만 가능)

		// 복사한 변수에는 대입 불가능
		// result1 = a + b;
		// result2 = 99999;
	}(10, 20);

	cout << endl;
	// 일부 참조
	cout << "2. 특정변수 참조" << endl;
	[&result3, &result4](int a, int b) {  // 참조 캡쳐
		cout << "result3=" << result3 << "  result4=" << result4 << endl;
		result3 = 22222;  // 참조캡쳐 했기 때문에 result3,4 값 변경 가능
		cout << "(내부) result3=" << result3 << "  result4 = " << result4 << endl;
		result4 = a + b;
	}(10, 20);

	cout << "(외부) result3=" << result3 << "  result4=" << result4 << endl;
	// 참조 캡쳐를 했기 때문에 람다 안에서 변경한 값이 람다 외부에서도 그대로 적용됨.(반영됨)
	return 0;
}
*/



/*
// 5번  -설명듣기
#include<iostream>
using namespace std;

void main()
{
	int a = 10;
	int b = 20;
	int R = [a, &b](int c)->int
	{
		b = a + b + c;
		return b;
	}(1);
	cout << "a=" << a << " b=" << b << " 결과=" << R << endl;
}
*/

/*
// 6번
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int result1 = 1;
	int result2 = 2;
	int result3 = 3;
	int result4 = 4;

	// 전체 복사
	cout << "3. 전체 복사" << endl;
	[=](int x)
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "매개변수 : " << x << endl;
	}(30);
	cout << endl;

	// 전체 참조
	[&](int y)
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "매개변수 : " << y << endl;

		result1 += y;
		result2 += y;
		result3 += y;
		result4 += y;
	}(99);

	cout << "result1, 2 : " << result1 << ", " << result2 << endl;
	cout << "result3, 4 : " << result3 << ", " << result4 << endl;

	return 0;
}
*/

/*
// 7번
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int result1 = 1;
	int result2 = 2;
	int result3 = 3;
	int result4 = 4;

	// 전체 복사, 일부 참조
	cout << "전체 복사, 일부 참조" << endl;

	[=, &result3, &result4](int x)  // 전체 복사, result3,4 는 참조
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "매개변수 : " << x << endl;

		// result1 += x;   // 전체 복사
		// result2 += x;   // 전체 복사
		result3 += x;  // 일부 참조
		result4 += x;  // 일부 참조
	}(30);

	cout << "result1, 2 : " << result1 << ", " << result2 << endl;
	cout << "result3, 4 : " << result3 << ", " << result4 << endl;

	cout << endl;


	// 전체 참조, 일부 복사
	cout << "전체 참조, 일부 복사" << endl;  //전체 참조, result1, 2 는 복사

	[&, result1, result2](int y)
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "매개변수 : " << y << endl;

		// result1 += y;   // 일부 복사
		// result2 += y;   // 일부 복사
		result3 += y;   // 전체 참조
		result4 += y;  // 전체 참조
	}(99);

	cout << "result1, 2 : " << result1 << ", " << result2 << endl;
	cout << "result3, 4 : " << result3 << ", " << result4 << endl;

	return 0;
}
*/


/*
// 8번 - 설명듣기
#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int sum = 0;

int main() {
	array<int, 5> numbers = { 1,2,3,4,5 };

	// 전역 변수 sum을 참조로 캡처 -error남!
	//for_each(numbers.begin(), numbers.end(), [&sum](int& number) {
	//	sum += number;
	//});

	for_each(numbers.begin(), numbers.end(), [](int & number) {
		// OK
		sum += number;
	});
	cout << sum << endl;
	return 0;
	
}
*/



/*
// 9번 - 설명듣기
#include<iostream>
using namespace std;

int main() {
	// implicit return type
	auto foo = [] { return 3.14; };

	// explicit return type
	auto bar = []()->float { return 3.14f; };

	// warning. double에서 float으로 암시적 형변환.
	float x = foo();
	cout << x << endl;
	// 가능
	float y = bar();
	cout << y << endl;
	return 0;
}
*/


/*
// 10번 -  설명듣기
#include<iostream>
#include<functional>

int main()
{
	using namespace std;

	// 자동변수에 람다식 할당
	auto f1 = [](int x, int y) { return x + y; };

	cout << f1(2, 3) << endl;

	// 함수객체에 람다식 할당 
	function<int(int, int)> f2 = [](int x, int y) { return x + y; };
	// function<int(int,int)>  => 반환형이 int이고 인자가 int 2개인 함수를 담는 함수 클래스

	cout << f2(3, 4) << endl;
}
*/


/*
// 11번
#include<iostream>
#include<functional>

template<typename T>
void templateFunc(T func) {
	func();
}

int main() {
	//std::function<void(void)>
	auto foo = []() {std::cout << "Hello lambda!" << std::endl; };

	templateFunc(foo);

	return 0;
}
*/


/*
// 12번
#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

bool compare(int a, int b) { return a > b; }

int main(void) {
	array<int, 10> arr1 = { 5,4,2,1,100,32,2,4,6,9 };
	array<int, 10> arr2 = { 5,4,2,1,100,32,2,4,6,9 };
	array<int, 10> arr3 = { 5,4,2,1,100,32,2,4,6,9 };

	// sort함수
	// 오름차순
	sort(arr1.begin(), arr1.end());
	cout << "std::sort(arr1, arr1 + 10)" << endl;
	for (int val : arr1)
	{
		cout << val << " ";
	}
	cout << endl << endl;


	// sort함수와 일반 함수 이용 
	// 내림차순
	cout << "std::sort(arr, arr+10, compare) ; " << endl;
	sort(arr2.begin(), arr2.end(), compare);
	for (int val : arr2)
	{
		cout << val << " ";
	}
	cout << endl << endl;


	// sort함수와 람다 함수 이용 
	// 내림차순
	cout << "std::sort(arr, arr + 10, [](int a, int b) { return a > b; })" << endl;
	sort(arr3.begin(), arr3.end(), [](int a, int b) { return a > b; });
	for (int val : arr3) {
		cout << val << " ";
	}

	return 0;
}
*/


/*
// 13번
#include<iostream>
#include<functional>

std::function<void(void)> getLambda() {  
	return []() { std::cout << "Hello lambda!" << std::endl; };
}			// 람다 함수 내용이 반환값 없고 인자도 없기 때문에 function<void(void)>

int main() {
	auto foo = getLambda();

	foo();  // Hello lambda!

	return 0;
}
*/

/*
// 14번
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

int main() {
	std::vector<std::function<void(void)>> funcs;

	funcs.push_back([]() {std::cout << "Hello" << std::endl; });
	funcs.push_back([]() {std::cout << "lambda!" << std::endl; });

	for (auto& func : funcs) {
		func();
	}
	//Hello
	//lambda!
}
*/

/*
// 15번
#include<iostream>
using namespace std;
class CTest {
public:
	int m_Value;
	int Func()
	{
		// return[this](int arg)-> int
		return[=](int arg)->int
		{
			return m_Value + arg; 
		}(1);
	}
};

void main()
{
	CTest t;
	t.m_Value = 10;
	cout << t.Func() << endl;  // 11
}
*/


/*
// 16번
#include<iostream>
#include<string>

class Person {
public:
	Person(std::string name) : name(name) {}
	void introduce() {  // [this]를 캡쳐했기 때문에 람다 안에서 클래스 Person의 모든 private변수, 메소드 다 사용가능
		[this]() {std::cout << "My name is " << name << std::endl; }();
	}   // this-> 클래스의 주소. Person의 주소
private:
	std::string name;
};

int main() {
	Person* devkoriel = new Person("홍길동");
	devkoriel->introduce();    // My name is 홍길동

	return 0;
}
*/

/*
// 17번
#include<iostream>
#include<functional>

int main()
{
	std::function<int(int)> factorial = [&factorial](int x) -> int {
		return x <= 1 ? 1 : x * factorial(x - 1);
	};

	std::cout << "factorial(5): " << factorial(5) << std::endl;
	// factorial(5): 120
}
*/

/*
// 18번
#include<iostream>
using namespace std;
int main()
{
	int timestwoplusthree = [](int x) { 
		return [](int y) { return y * 2; }(x) + 3; 
	}(5);
	cout << timestwoplusthree << endl;   // 13
}
*/


/*
// 19번
#include<iostream>
#include<array>
#include<algorithm>

using namespace std;
int main()
{
	std::array<int, 5> numbers = { 1,2,3,4,5 };
	int sum = 0;

	// sum을 참조로 캡쳐
	for_each(numbers.begin(), numbers.end(), [&sum](int &number) {  //이터레이터가 이동하면서 array값을 하나씩 람다의 매개변수 number로 보냄
		sum += number;
	});

	cout << sum << endl;
	return 0;
}
*/

//NULL == nullptr

/*
// 20번
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	vector<int>::const_iterator iter = v.begin();
	vector<int>::const_iterator iter_end = v.end();
	int total_elements = 0;
	while (iter != iter_end) {
		total_elements += *iter;
		++iter;
	}

	cout << total_elements << endl;
}
*/

/*
// 21번
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Scale {
private:
	int _scale;

public:
	explicit Scale(int scale) : _scale(scale) {}

	void ApplyScale(const vector<int>& v) const
	{
		for_each(v.begin(), v.end(), [=](int n) {cout << n * _scale << endl; });
	}          // 이터레이터가 이동하면서 람다의 매개변수 n으로 벡터 원소값 하나씩 보냄
	           // 매개변수로 벡터값 하나씩 받아서 연산
};

int main()
{
	vector<int> values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	Scale s(3);
	s.ApplyScale(values);
}
*/


/*
// 22번
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>

struct DataType {
	int x;
	int y;
	double dist() const { return std::sqrt(x * x + y * y); }
	const std::string str() const {
		return '(' + std::to_string(x) + ',' + std::to_string(y) + ')';
	}
};

bool operator<(const DataType& d1, const DataType& d2) { return d1.dist() < d2.dist(); }

std::ostream& operator<< (std::ostream& os, const DataType& d)
{
	os << d.str();
	return os;
}

template<typename T>
bool fnPredicator(const T& val1, const T& va12)
{
	return val1 < val2;
}

struct FOPredicator {
	template<typename T>
	bool operator()(const T& val, const T& val2) const
	{
		return val1 < val2;
	}
};


using VecDataType = std::vector<DataType>;  // typedef같은 개념. vector<DataType> = VecDataType 완전히 같은거 
using namespace std;                                 // vector<DataType>을 VecDataType이라고 부르겠다.


int main()
{
	auto print = [](const VecDataType& d, const string& strMsg = "") {
		cout << strMsg;
		copy(begin(d), end(d), ostream_iterator<DataType>(cout, " "));  // d.begin()을 copy안에서 begin(d)로 쓸 수 있음
		cout << endl;
	};

	VecDataType vecData{ {7,2}, {1,3}, {2,6}, {3,2}, {5,1}, {1,1} };

	print(vecData, "벡터에 저장된 객체들 : ");
	cout << endl;
	sort(begin(vecData), end(vecData), fnPredicator<DataType>);
	print(vecData, "함수사용 오름차순정렬: ");
	cout << endl;

	sort(begin(vecData), end(vecData), [](const DataType& d1, const DataType& d2) { return d1.dist() > d2.dist(); }); // sort에 람다를 넣음
	print(vecData, "lambda사용 내림차순정렬 : ");
	cout << endl;

	sort(begin(vecData), end(vecData), FOPredicator());  // functor사용
	print(vecData, "함수객체사용 오름차순정렬 : ");
	return 0;
}
*/





// 문제풀이 19페이지
/*
// 1번
#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "숫자 2개 입력 : ";
	cin >> a >> b;

	[](int a, int b) {
		cout << "큰 값 : ";
		(a > b) ? (cout << a) : (cout << b);
		cout << "\n작은값 : ";
		(a > b) ? (cout << b) : (cout << a);
	}(a,b);

}
*/

/*
// 2번
#include<iostream>
using namespace std;

int main()
{
	[](int value) {
		int abvalue;
		abvalue = value * -1;
		cout << "절대값 : " << abvalue;
	}(-109);
}
*/

/*
// 3번
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> vec;
	vec.push_back("apple");
	vec.push_back("banana");
	vec.push_back("grape");
	vec.push_back("orange");
	vec.push_back("kiwi");

	cout << "vector : ";
	for_each(vec.begin(), vec.end(), [](string val) {
		cout << val << "  "; });
}
*/

/*
// 4번
#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Even {
	int even = 0;
public:
	int operator()(vector<T> v) {
		for (int i = 0; i < v.size(); i++)
			if (v[i] % 2 == 0) even++;
		return even;
	}

};

int main()
{
	vector<int> vec;
	for (int i = 1; i <= 10; i++)
		vec.push_back(i);
	cout << "Vector : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "  ";
	cout << endl;

	auto f = [](vector<int> v) ->int{
		int even = 0;
		for (int i = 0; i < v.size(); i++)
			if (v[i] % 2 == 0) even++;
		return even;
	};

	cout << "짝수개수(functor) : ";
	cout << Even<int>()(vec) << endl;
	cout << "짝수개수(lambda) : ";
	cout << f(vec) << endl;
}
*/

/*
// 5번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(34);
	vec.push_back(-43);
	vec.push_back(56);

	cout << "변경전 : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	for_each(vec.begin(), vec.end(), [](int &d) {
		d = d * -1;
	});

	cout << "\n변경후 : ";
	for_each(vec.begin(), vec.end(), [](int &d) {
		cout << d << " ";
	});
}
*/

/*
// 6번 - 함수객체로 작성
#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Plus {
	void operator()(T& v) {
		for (int i = 0; i < v.size(); i++)
			v[i] = v[i] + 100;
	}
};
int main()
{
	vector<int>vec;
	for (int i = 1; i < 6; i++) {
		vec.push_back(i * 10);
	}
	cout << "벡터값 : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	Plus<vector<int>>()(vec);
	cout << "\n변경후 : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}
*/
/*
// 6번 - 람다로 작성
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int>vec;
	for (int i = 1; i < 6; i++) {
		vec.push_back(i * 10);
	}
	cout << "벡터값 : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	for_each(vec.begin(), vec.end(), [](int &d) {
		d += 100; });

	cout << "\n변경후 : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}
*/

/*
// 7번
#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> mylist;
	mylist.push_back(13);
	mylist.push_back(17);
	mylist.push_back(42);
	mylist.push_back(46);
	mylist.push_back(99);

	list<int>::iterator it;
	it = mylist.begin();
	cout << "numbers : ";
	while (it != mylist.end()) {
		cout << *it << " ";
		it++;
	}

	it = mylist.begin();
	while (it != mylist.end()) {
		[&](int d) {
			if (d % 2 == 0) {
				cout << "\n리스트의 첫번째 짝수는 => " << d << endl;
				it = mylist.end();
			}
			else it++;
		}(*it);
	}
}
*/

/*
// 8번
#include<iostream>
using namespace std;

int main()
{
	auto foo = [](int s, int e)->int {
		int sum = 0;
		for (int i = s; i <= e; i++)
			sum += i;
		return sum;
	};

	int start, end;
	cout << "시작 : ";
	cin >> start;
	cout << "끝값 : ";
	cin >> end;

	cout << start << " ~ " << end << " 의 합은 : " << foo(start, end) << endl;
}
*/

/*
// 9번
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
using namespace std;

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 100);

	vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(dis(gen));
	}
	int even = 0;
	for_each(vec.begin(), vec.end(), [&even](int d) {
		if (d % 2 == 0) {
			cout << d << ".. 짝수\n"; even++;
		}
		else cout << d << ".. 홀수\n"; });

	cout << "\n짝수 개수 : " << even << endl;
}
*/


/*
// 람다 끝에 () 써주면 순차적으로 위에서부터 실행되면서 딱 한번 실행됨
// 내가 원할 때마다 람다 호출하려면 변수에 넣어놓고 써야 함.
#include<iostream>
using namespace std;

int main()
{
	[] {
		cout << "Lambda\n";
	}();
	
}
*/


/*
// 10번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int>vec;
	vector<int>::iterator it;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "처음 vec 상태 -----\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << "[" << vec[i] << "] ";
	}

	it = vec.begin();
	while (it != vec.end()) {
		[&](vector<int>::iterator &i) {
			if (*i % 2 != 0) i = vec.erase(i);
			else i++;
		}(it);
	}

	cout << "\n벡터에서 홀수인 원소 제거 -----\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << "[" << vec[i] << "] ";
	}

	cout << endl << endl;
}
*/


/*
// 11번
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>vec;
	vector<int>::iterator it;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "처음 vec 상태 -----\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << "[" << vec[i] << "] ";
	}

	int flag = 0;
	it = vec.begin();
	while (it != vec.end()) {
		[&](vector<int>::iterator &i) {
			if (*i % 2 != 0 && flag<2) { i = vec.erase(i); flag++; }
			else i++;
		}(it);
	}

	cout << "\n벡터에서 홀수인 원소 제거 -----\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << "[" << vec[i] << "] ";
	}

	cout << endl << endl;
}
*/

/*
// 12번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Pos {
	int x;
	int y;
};
int main()
{
	int size;
	Pos pos;
	vector<Pos> vec;
	cout << "입력할 자료의 개수 : ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "x, y 입력 : ";
		cin >> pos.x >> pos.y;
		vec.push_back(pos);
	}

	cout << endl << endl;
	sort(vec.begin(), vec.end(), [](Pos a, Pos b)->bool {
		return ((a.x + a.y) < (b.x + b.y));
	});

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].x << " " << vec[i].y << endl;
}
*/


/*
// 13번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "벡터 : ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "  ";
	}

	for_each(vec.begin(), vec.end(), [](int d) {
		if (d % 3 == 2) cout << "\n3 으로 나눈 나머지가 2 인 원소는 : " << d << " 이다.\n";
	});

}
*/


/*
// 14번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	auto foo = [=](vector<int> &v) {
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 3) { cout << "3 은 " << i + 1 << "번째 원소"; break; }
		}
	};

	cout << "벡터 : ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "  ";
	}

	cout << endl;
	foo(vec);   // 람다 호출
}
*/




// C++ 끝.