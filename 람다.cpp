
/*
// 1��
#include<iostream>
#include<string>
using namespace std;

// �Ϲ� �Լ� ����
void sum1(int a, int b)
{
	cout << "�Լ� : " << a + b << endl;
}

int main(void) {
	 
	//�Ϲ� �Լ� ȣ��
	sum1(10, 20);

	//�����Լ�
	[](int a, int b)
	{
		cout << "���� : " << a + b << endl;
	}(30, 40);

	return 0;
}
*/

/*
// 2��
#include<array>
#include<algorithm>
#include<iostream>

using namespace std;
// �Լ� ��ü�� ����
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
	cout << "�Լ���ü�� �հ��" << sum << endl;

	sum = 0;

	// lambda�� ����
	for_each(numbers.begin(), numbers.end(), [&sum](int &number) {
		sum += number;
	});
	cout << "���ٷ� �հ�� " << sum << endl;

	return 0;
}
*/
/*
// 3��
#include<iostream>
#include<string>
using namespace std;

int main()
{
	[](string name) {
		cout << "My name is " << name << endl;
	}("ȫ�浿");

	// My name is ȫ�浿
	return 0;
}
*/


/*
// 4��
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int result1 = 1;
	int result2 = 2;
	int result3 = 3;
	int result4 = 4;
	// ���� �ȿ����� �� �������� ��� ����(���� �����Լ� �ȿ� �ִ��� ���x. ���� �ܺ��̱� ������)
	// => ĸ�ĸ� �ϸ� �� �� ����.

	// �Ϻ� ����
	cout << "1. Ư������ ����" << endl;
	[result1, result2](int a, int b) { // �̷��� ĸ���ϴ� �� copy��� ��. ���� ���ο��� �� ���� ������ �� ������ ����.
		cout << "result1=" << result1 << "  result2" << result2 << endl;
		cout << "a=" << a << "  b=" << b << endl;
		cout << "result1 + a + b : " << result1 + a + b << endl;
		// result1,2 ĸ���߱� ������ ���� �ȿ��� ��밡��.
		//cout << result1++;  �̷� ���� ����. copy�̱� ������(�������߸� ����)

		// ������ �������� ���� �Ұ���
		// result1 = a + b;
		// result2 = 99999;
	}(10, 20);

	cout << endl;
	// �Ϻ� ����
	cout << "2. Ư������ ����" << endl;
	[&result3, &result4](int a, int b) {  // ���� ĸ��
		cout << "result3=" << result3 << "  result4=" << result4 << endl;
		result3 = 22222;  // ����ĸ�� �߱� ������ result3,4 �� ���� ����
		cout << "(����) result3=" << result3 << "  result4 = " << result4 << endl;
		result4 = a + b;
	}(10, 20);

	cout << "(�ܺ�) result3=" << result3 << "  result4=" << result4 << endl;
	// ���� ĸ�ĸ� �߱� ������ ���� �ȿ��� ������ ���� ���� �ܺο����� �״�� �����.(�ݿ���)
	return 0;
}
*/



/*
// 5��  -������
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
	cout << "a=" << a << " b=" << b << " ���=" << R << endl;
}
*/

/*
// 6��
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int result1 = 1;
	int result2 = 2;
	int result3 = 3;
	int result4 = 4;

	// ��ü ����
	cout << "3. ��ü ����" << endl;
	[=](int x)
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "�Ű����� : " << x << endl;
	}(30);
	cout << endl;

	// ��ü ����
	[&](int y)
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "�Ű����� : " << y << endl;

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
// 7��
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int result1 = 1;
	int result2 = 2;
	int result3 = 3;
	int result4 = 4;

	// ��ü ����, �Ϻ� ����
	cout << "��ü ����, �Ϻ� ����" << endl;

	[=, &result3, &result4](int x)  // ��ü ����, result3,4 �� ����
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "�Ű����� : " << x << endl;

		// result1 += x;   // ��ü ����
		// result2 += x;   // ��ü ����
		result3 += x;  // �Ϻ� ����
		result4 += x;  // �Ϻ� ����
	}(30);

	cout << "result1, 2 : " << result1 << ", " << result2 << endl;
	cout << "result3, 4 : " << result3 << ", " << result4 << endl;

	cout << endl;


	// ��ü ����, �Ϻ� ����
	cout << "��ü ����, �Ϻ� ����" << endl;  //��ü ����, result1, 2 �� ����

	[&, result1, result2](int y)
	{
		cout << "result1, 2 : " << result1 << ", " << result2 << endl;
		cout << "result3, 4 : " << result3 << ", " << result4 << endl;
		cout << "�Ű����� : " << y << endl;

		// result1 += y;   // �Ϻ� ����
		// result2 += y;   // �Ϻ� ����
		result3 += y;   // ��ü ����
		result4 += y;  // ��ü ����
	}(99);

	cout << "result1, 2 : " << result1 << ", " << result2 << endl;
	cout << "result3, 4 : " << result3 << ", " << result4 << endl;

	return 0;
}
*/


/*
// 8�� - ������
#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int sum = 0;

int main() {
	array<int, 5> numbers = { 1,2,3,4,5 };

	// ���� ���� sum�� ������ ĸó -error��!
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
// 9�� - ������
#include<iostream>
using namespace std;

int main() {
	// implicit return type
	auto foo = [] { return 3.14; };

	// explicit return type
	auto bar = []()->float { return 3.14f; };

	// warning. double���� float���� �Ͻ��� ����ȯ.
	float x = foo();
	cout << x << endl;
	// ����
	float y = bar();
	cout << y << endl;
	return 0;
}
*/


/*
// 10�� -  ������
#include<iostream>
#include<functional>

int main()
{
	using namespace std;

	// �ڵ������� ���ٽ� �Ҵ�
	auto f1 = [](int x, int y) { return x + y; };

	cout << f1(2, 3) << endl;

	// �Լ���ü�� ���ٽ� �Ҵ� 
	function<int(int, int)> f2 = [](int x, int y) { return x + y; };
	// function<int(int,int)>  => ��ȯ���� int�̰� ���ڰ� int 2���� �Լ��� ��� �Լ� Ŭ����

	cout << f2(3, 4) << endl;
}
*/


/*
// 11��
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
// 12��
#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

bool compare(int a, int b) { return a > b; }

int main(void) {
	array<int, 10> arr1 = { 5,4,2,1,100,32,2,4,6,9 };
	array<int, 10> arr2 = { 5,4,2,1,100,32,2,4,6,9 };
	array<int, 10> arr3 = { 5,4,2,1,100,32,2,4,6,9 };

	// sort�Լ�
	// ��������
	sort(arr1.begin(), arr1.end());
	cout << "std::sort(arr1, arr1 + 10)" << endl;
	for (int val : arr1)
	{
		cout << val << " ";
	}
	cout << endl << endl;


	// sort�Լ��� �Ϲ� �Լ� �̿� 
	// ��������
	cout << "std::sort(arr, arr+10, compare) ; " << endl;
	sort(arr2.begin(), arr2.end(), compare);
	for (int val : arr2)
	{
		cout << val << " ";
	}
	cout << endl << endl;


	// sort�Լ��� ���� �Լ� �̿� 
	// ��������
	cout << "std::sort(arr, arr + 10, [](int a, int b) { return a > b; })" << endl;
	sort(arr3.begin(), arr3.end(), [](int a, int b) { return a > b; });
	for (int val : arr3) {
		cout << val << " ";
	}

	return 0;
}
*/


/*
// 13��
#include<iostream>
#include<functional>

std::function<void(void)> getLambda() {  
	return []() { std::cout << "Hello lambda!" << std::endl; };
}			// ���� �Լ� ������ ��ȯ�� ���� ���ڵ� ���� ������ function<void(void)>

int main() {
	auto foo = getLambda();

	foo();  // Hello lambda!

	return 0;
}
*/

/*
// 14��
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
// 15��
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
// 16��
#include<iostream>
#include<string>

class Person {
public:
	Person(std::string name) : name(name) {}
	void introduce() {  // [this]�� ĸ���߱� ������ ���� �ȿ��� Ŭ���� Person�� ��� private����, �޼ҵ� �� ��밡��
		[this]() {std::cout << "My name is " << name << std::endl; }();
	}   // this-> Ŭ������ �ּ�. Person�� �ּ�
private:
	std::string name;
};

int main() {
	Person* devkoriel = new Person("ȫ�浿");
	devkoriel->introduce();    // My name is ȫ�浿

	return 0;
}
*/

/*
// 17��
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
// 18��
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
// 19��
#include<iostream>
#include<array>
#include<algorithm>

using namespace std;
int main()
{
	std::array<int, 5> numbers = { 1,2,3,4,5 };
	int sum = 0;

	// sum�� ������ ĸ��
	for_each(numbers.begin(), numbers.end(), [&sum](int &number) {  //���ͷ����Ͱ� �̵��ϸ鼭 array���� �ϳ��� ������ �Ű����� number�� ����
		sum += number;
	});

	cout << sum << endl;
	return 0;
}
*/

//NULL == nullptr

/*
// 20��
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
// 21��
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
	}          // ���ͷ����Ͱ� �̵��ϸ鼭 ������ �Ű����� n���� ���� ���Ұ� �ϳ��� ����
	           // �Ű������� ���Ͱ� �ϳ��� �޾Ƽ� ����
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
// 22��
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


using VecDataType = std::vector<DataType>;  // typedef���� ����. vector<DataType> = VecDataType ������ ������ 
using namespace std;                                 // vector<DataType>�� VecDataType�̶�� �θ��ڴ�.


int main()
{
	auto print = [](const VecDataType& d, const string& strMsg = "") {
		cout << strMsg;
		copy(begin(d), end(d), ostream_iterator<DataType>(cout, " "));  // d.begin()�� copy�ȿ��� begin(d)�� �� �� ����
		cout << endl;
	};

	VecDataType vecData{ {7,2}, {1,3}, {2,6}, {3,2}, {5,1}, {1,1} };

	print(vecData, "���Ϳ� ����� ��ü�� : ");
	cout << endl;
	sort(begin(vecData), end(vecData), fnPredicator<DataType>);
	print(vecData, "�Լ���� ������������: ");
	cout << endl;

	sort(begin(vecData), end(vecData), [](const DataType& d1, const DataType& d2) { return d1.dist() > d2.dist(); }); // sort�� ���ٸ� ����
	print(vecData, "lambda��� ������������ : ");
	cout << endl;

	sort(begin(vecData), end(vecData), FOPredicator());  // functor���
	print(vecData, "�Լ���ü��� ������������ : ");
	return 0;
}
*/





// ����Ǯ�� 19������
/*
// 1��
#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "���� 2�� �Է� : ";
	cin >> a >> b;

	[](int a, int b) {
		cout << "ū �� : ";
		(a > b) ? (cout << a) : (cout << b);
		cout << "\n������ : ";
		(a > b) ? (cout << b) : (cout << a);
	}(a,b);

}
*/

/*
// 2��
#include<iostream>
using namespace std;

int main()
{
	[](int value) {
		int abvalue;
		abvalue = value * -1;
		cout << "���밪 : " << abvalue;
	}(-109);
}
*/

/*
// 3��
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
// 4��
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

	cout << "¦������(functor) : ";
	cout << Even<int>()(vec) << endl;
	cout << "¦������(lambda) : ";
	cout << f(vec) << endl;
}
*/

/*
// 5��
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

	cout << "������ : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	for_each(vec.begin(), vec.end(), [](int &d) {
		d = d * -1;
	});

	cout << "\n������ : ";
	for_each(vec.begin(), vec.end(), [](int &d) {
		cout << d << " ";
	});
}
*/

/*
// 6�� - �Լ���ü�� �ۼ�
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
	cout << "���Ͱ� : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	Plus<vector<int>>()(vec);
	cout << "\n������ : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}
*/
/*
// 6�� - ���ٷ� �ۼ�
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
	cout << "���Ͱ� : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	for_each(vec.begin(), vec.end(), [](int &d) {
		d += 100; });

	cout << "\n������ : ";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}
*/

/*
// 7��
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
				cout << "\n����Ʈ�� ù��° ¦���� => " << d << endl;
				it = mylist.end();
			}
			else it++;
		}(*it);
	}
}
*/

/*
// 8��
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
	cout << "���� : ";
	cin >> start;
	cout << "���� : ";
	cin >> end;

	cout << start << " ~ " << end << " �� ���� : " << foo(start, end) << endl;
}
*/

/*
// 9��
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
			cout << d << ".. ¦��\n"; even++;
		}
		else cout << d << ".. Ȧ��\n"; });

	cout << "\n¦�� ���� : " << even << endl;
}
*/


/*
// ���� ���� () ���ָ� ���������� ���������� ����Ǹ鼭 �� �ѹ� �����
// ���� ���� ������ ���� ȣ���Ϸ��� ������ �־���� ��� ��.
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
// 10��
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

	cout << "ó�� vec ���� -----\n";
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

	cout << "\n���Ϳ��� Ȧ���� ���� ���� -----\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << "[" << vec[i] << "] ";
	}

	cout << endl << endl;
}
*/


/*
// 11��
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

	cout << "ó�� vec ���� -----\n";
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

	cout << "\n���Ϳ��� Ȧ���� ���� ���� -----\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << "[" << vec[i] << "] ";
	}

	cout << endl << endl;
}
*/

/*
// 12��
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
	cout << "�Է��� �ڷ��� ���� : ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "x, y �Է� : ";
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
// 13��
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

	cout << "���� : ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "  ";
	}

	for_each(vec.begin(), vec.end(), [](int d) {
		if (d % 3 == 2) cout << "\n3 ���� ���� �������� 2 �� ���Ҵ� : " << d << " �̴�.\n";
	});

}
*/


/*
// 14��
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
			if (v[i] == 3) { cout << "3 �� " << i + 1 << "��° ����"; break; }
		}
	};

	cout << "���� : ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "  ";
	}

	cout << endl;
	foo(vec);   // ���� ȣ��
}
*/




// C++ ��.