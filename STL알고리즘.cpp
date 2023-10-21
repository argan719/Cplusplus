
/*
// 1��
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string fruits[5] = { "���", "�丶��", "��", "����", "Ű��" };
	vector<string> vec(&fruits[0], &fruits[5]);  // ���� ������ �� �迭 ������ �ʱ�ȭ - �̷������� �Ѵ�.(�迭�� ���Ϳ� ����)

	vector<string>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	it = find(vec.begin(), vec.end(), "����"); // 3
	if (it != vec.end())
		cout << "������ " << distance(vec.begin(), it) << "��°�� �ֽ��ϴ�." << endl;
	return 0;
}
*/


/*
// 2��
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool checkKim(string s)
{
	if (s.find("��") != string::npos)
		return true;
	else
		return false;
}
int main()
{
	string names[5] = { "��ö��", "�ڹ���", "������", "������", "�̼���" };
	vector<string> vec(&names[0], &names[5]);

	vector<string>::iterator it;
	it = vec.begin();

	while (true) {
		it = find_if(it, vec.end(), checkKim);
		if (it == vec.end())			// Ž�� ����
			break;
		cout << "��ġ " << distance(vec.begin(), it) << "���� " << *it << "�� Ž���Ͽ��� " << endl;
		it++;
	}
}
*/

/*
// 3��
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	vector<int> vec;
	int arr[] = { 1,2,3,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 12; i++)		
		vec.push_back(arr[i]);

	for (int d : vec)  // ���� ��� for ��(ranged-based for statement) vector�� ���� �ϳ��� int d �� �Ű���. ���Ͱ� ����������
		cout << d << "  ";

	cout << endl;
	list<int> ilist;
	for (int i = 3; i < 6; i++)		// ilist = (3,4,5)
		ilist.push_back(i);

	vector<int>::iterator it;
	it = search(vec.begin(), vec.end(), ilist.begin(), ilist.end());  // 3 4 5�� ������(�״��) vector�� ����־�� ã��������
																					// 3 4 5 �� ���۵Ǵ� ��ġ - 3�� ��ġ ��ȯ
	if (it != vec.end()) {
		cout << *it << "������ " << distance(vec.begin(), it) << "��°�� �ֽ��ϴ�." << endl;
	}
}
*/

/*
// 4��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
bool is_even(const T& num)
{
	return (num % 2) == 0;
}

int main()
{
	char *s = "I go to the school";
	vector<int> vec;
	for (int i = 0; i < 10; i++)  
		vec.push_back(i);    // 0 ~ 9

	size_t n1 = count(s, s + strlen(s), 'o');
	size_t n2 = count_if(vec.begin(), vec.end(), is_even<int>); // vec.begin ~ vec.end ���� ���������� is_even�Լ��� �� �����

	cout << "���� 'o'�� ����� ����: " << n1 << endl;
	cout << "���� ¦���� ����� ����: " << n2 << endl;
}
*/

/*
// 5��
#include<iostream>
#include<vector>
#include<algorithm>
#include "myheader.h"
using namespace std;

int main()
{
	const int wanted = 13;
	int values[9] = { 1,3,5,5,5,8,11,20,30 };
	vector<int> vec(&values[0], &values[9]);
	vector<int>::iterator it;

	print(vec);
	bool isInIt = binary_search(vec.begin(), vec.end(), wanted);

	if (isInIt == true)
		cout << wanted << "�� ã���� " << endl;
	else {
		it = lower_bound(vec.begin(), vec.end(), wanted); // lower_bound : ������ ���� �ʵ��� ������ �°� wanted�� ���� �ϴ� ��ġ ��ȯ
		vec.insert(it, wanted);
	}
	print(vec);

	return 0;
}
*/

/*
// 6��
#include<iostream>
#include<vector>
#include<algorithm>
#include "myheader.h"
using namespace std;

int main()
{
	int values1[9] = { 1,2,3,4,5,6,7,8,9 };
	int values2[9] = { 9,9,3,4,5,9,9,9,9 };
	vector<int> vec1(&values1[0], &values1[9]);
	vector<int> vec2(&values2[0], &values2[9]);
	print(vec1);
	print(vec2);
	bool isEqual = equal(vec1.begin() + 2, vec1.begin() + 5, vec2.begin() + 2); 
	// vec1�� +2���� vec1�� +5������ ������ (3,4,5)
	// vec2�� +2���� 3���� ���� (3,4,5)  
	// '������'

	if (isEqual == true)
		cout << "�� ���� ������ ������" << endl;
}
*/


/*
// 7��
#include<iostream>
#include<vector>
#include<algorithm>
#include "myheader.h"
using namespace std;

int main()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	
	cout << "fill() ������ �� ";
	print(v1);
	fill(v1.begin(), v1.end(), 0);

	cout << "fill() ������ �� ";
	print(v1);
}
*/


/*
// 8��
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string names[5] = { "���", "��", "Ű��", "����", "����" };
	vector<string> fruits(5);
	vector<string>::iterator it;

	copy(&names[0], &names[5], fruits.begin());  // names[0]���� names[5]������ ���� fruit.begin()���ٰ� �������
	reverse(fruits.begin(), fruits.end());  // �Ųٷ� �ٲ�

	for (it = fruits.begin(); it != fruits.end(); ++it)  // reverse�߱� ������ begin���� end���� ��µ� �������� ����.
		cout << *it << " ";
}

// ������   ���� ���� Ű�� �� ���
*/

/*
// 9��
#include<iostream>
#include<algorithm>  // for_each
#include<vector>
using namespace std;
// �� ��ҿ� ���Ͽ� ȣ��Ǵ� �Լ�
void display(int element)
{
	cout << element << ' ';
}

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	for_each(vec.begin(), vec.end(), display); // ���� ����(vec.begin() ~ end()-1) ���Ͱ��� (vec[i]) display�� int element�� ������
	cout << endl;			// ���� ������ iterator�� �� ĭ�� �̵��ϸ鼭 ���Ͱ��� ����(������) display() ���� 
	return 0;
}

// for_each(vec.begin(), vec.end(), display);�� 

// for(int i=begin; i<end ; i++)
//		v[i].display();
// �̰Ŷ� ���ٰ� �����ϸ� ��.
*/


/*
// 10��
#include<iostream>
#include<algorithm>
#include<vector>
#include "myheader.h"
using namespace std;

// �� ��ҿ� ���Ͽ� ȣ��Ǵ� �Լ�
int increment(int element)  // �ٵ� ���⼭ int &element�� ���� vec������ ++�Ȱ� �ݿ���
{
	return ++element;
}
int main()
{
	vector<int> vec;
	vector<int> result(10);
	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	print(vec);
	transform(vec.begin(), vec.end(), result.begin(), increment); // increment�Լ� ������ ���� result.begin()���� ����
	print(result);
	//cout << endl << endl;
	//print(vec);  vec������ ������ ����
}
*/

/*
// 11��
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include "myheader.h"
using namespace std;

int main()
{
	string names[5] = { "���", "��", "Ű��", "����","����" };
	vector<string> fruits(5);
	copy(&names[0], &names[5], fruits.begin());
	print(fruits, "������\n");  // ������  (��� �� Ű�� ���� ����)
	vector<string>::iterator it;
	it = remove(fruits.begin(), fruits.end(), "����");
	print(fruits, "remove() ��\n");  // remove() ��  (��� �� Ű�� ����)
	fruits.erase(it, fruits.end()); 
	print(fruits, "erase() ��\n");  // erase() ��  (��� �� Ű�� ����)
}
*/


/*
// 12��
#include<iostream>
#include<algorithm>
#include<vector>
#include "myheader.h"
using namespace std;

int main()
{
	int value[10] = { 82, 25, 26, 7, 67, 55, 31, 19, 99 };

	vector<int> v1(&value[0], &value[10]);
	print(v1, "�ʱ⸮��Ʈ\n");
	sort(v1.begin(), v1.end());
	print(v1, "sort() ���� �� ����Ʈ\n");

	vector<int> v2(&value[0], &value[10]);
	stable_sort(v2.begin(), v2.end());
	print(v2, "stable_sort() ���� �� ����Ʈ\n");

	vector<int> v3(&value[0], &value[10]);
	partial_sort(v3.begin(), v3.begin() + 3, v3.end());
	print(v3, "partial_sort() ���� �� ����Ʈ\n");

	vector<int> v4(&value[0], &value[10]);
	nth_element(v4.begin(), v4.begin() + 5, v4.end());
	print(v4, "nth_element() ���� �� ����Ʈ\n");
	return 0;
}
*/

/*
// 13��
#include<iostream>
#include<vector>
#include<algorithm>

template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}
struct int_compare {
	bool operator() (const int& a, const int& b) const { return a > b; }
};

int main()
{
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);

	std::cout << "���� �� ----" << std::endl;
	print(vec.begin(), vec.end());
	std::sort(vec.begin(), vec.end(), int_compare()); // int_compare����ü �ȿ� �ִ� operator() ȣ��

	std::cout << "���� �� ----" << std::endl;
	print(vec.begin(), vec.end());
}
*/

/*
// 14��
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "myheader.h"
using namespace std;
// ���ڿ��� ���̸� ������ �����Ѵ�. - ���� ��������
bool is_less(const string& s1, const string& s2)
{
	return s1.length() < s2.length();
	// true�� ��ȯ�ϸ� ��ġ �ȹٲٴ� �Ű� false�̸� ��ġ �ٲٴ� ����.
}
int main()
{
	vector<string> vec1;
	vector<string> vec2;

	vec1.push_back("AAAA");
	vec1.push_back("AAAAAA");
	vec1.push_back("BBBB");
	vec1.push_back("AAA");
	vec1.push_back("AA");
	vec1.push_back("A");
	vec2 = vec1;

	print(vec1, "ó�� ���ڿ�\n");

	sort(vec1.begin(), vec1.end(), is_less);
	stable_sort(vec2.begin(), vec2.end(), is_less);

	print(vec1, "sort()���� ���ڿ�\n");
	print(vec2, "stable_sort()���� ���ڿ�\n");
	return 0;
}
*/


/*
// 15�� 
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include "myheader.h"
using namespace std;
int main()
{
	double v1[8] = { 1.0, 2.0, 3.0, 4.0, 5.0 , 6.0, 7.0, 8.0};
	double sum;

	sum = accumulate(&v1[0], &v1[8], 0.0); // 0.0���ٰ� v1[0]~ v1[4]������ ���� ����
	cout << "������= " << sum << endl;

	vector<double> v2;
	partial_sum(&v1[1], &v1[4], back_inserter(v2)); //  �����ؼ� ����- ������ ���� �Ź� ��� 
	// back_inserter�� v2�� �� ���� �ִ� ����.
	// ������ (v1[1] ~ v1[4] �� �������� 2 2+3=5  5+4=9 => 2 5 9 ��µ�)
	print(v2, "�κ���=");
}
*/



/*
// 16��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> container;

	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;   // 0

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;   // 9
}
*/




/*
// ����Ǯ�� 13������
// 1��
#include<iostream>
#include<vector>
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

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 3) cout << vec[i] << " �� " << i + 1 << " ��° ����\n";
	}

}
*/

/*
// 2��
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

bool find_year(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main()
{
	list<int>year;
	for (int y = 1990; y < 2020; y++) {
		year.push_back(y);
	}
	list<int>::iterator it;

	it = find_if(year.begin(), year.end(), find_year);
	if (it == year.end()) cout << "�� ã�ҽ��ϴ�\n";
	else cout << "1990~2019�� ������ ù ��° ���� : " << (*it) << endl;
}
*/

/*
// 3��
#include<iostream>
#include<vector>
#include<random>
using namespace std;
bool isEven(int r) {
	return (r % 2 == 0);
}

int main()
{
	vector<int> vec(100);
	vector<int>::iterator it;
	int r;
	int rnum = 0;
	std::random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());
	// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> dis(0, 99);


	for (int i = 0; i < vec.size(); i++) {
		r = dis(gen);
		vec[i] = r;
	}
	cout << "���� �� ���� ���\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "  ";
	}
	for (int d : vec) {
		if (isEven(d)) rnum++;
	}

	cout << "\n\n���� ���� ������ ¦���� ���� : " << rnum << endl;

	//it = vec.begin();
	//int rnum = -1;
	//while (it != vec.end()) {
	//	it = find_if(it, vec.end(), isEven); 
	//	if (it != vec.end()) rnum++;
	//	it++;
	//}
	//cout << "���� ���� ������ ¦���� ���� : " << rnum << endl;
}
*/

/*
// 4��
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vector<int>::iterator it;

	std::random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());
	// 5 ���� 55555 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> dis(555, 55555);

	int r;
	for (int i = 0; i < 100; i++) {
		r = dis(gen);
		vec.push_back(r);
	}
	cout << "���� �� ���� ���\n";
	for (int i = 0; i < 100; i++) {
		cout << vec[i] << "  ";
	}
	cout << endl << endl;

	it = min_element(vec.begin(), vec.end());
	cout << "������ �ּҰ� : " << (*it) << endl;

	it = max_element(vec.begin(), vec.end());
	cout << "������ �ִ밪 : " << (*it) << endl;
	
}
*/


/*
// 5�� 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int merge(int a, int b) {
	return a + b;
}
int  main()
{
	// a�� �� ���� ������. 
	// a���̸� �������� ���µ� a�� ���� ���� �ִµ� b�� �� �̻� ���� ���� ���� ������ ������
	// (b�� ����� ������� transform���� a.begin()~a.end()�� �տ� ��� ������ �� �׸�ŭ�� �����ϰ� b������ �׳� ���վ��ϴ°���)
	int a_arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int b_arr[] = { 10,11,12,13,14,15,16,17,18,19,100,200 };

	vector<int> a(&a_arr[0], &a_arr[sizeof(a_arr) / sizeof(a_arr[0])]);
	vector<int> b(&b_arr[0], &b_arr[sizeof(b_arr) / sizeof(b_arr[0])]);
	vector<int> c(20);  // c ũ�⸦ �̸� ��Ƴ��� ��. transform�� push_back�ϴ°� �ƴ϶� �׳� insert�ϱ� ����.
	//vector<int> c;
	vector<int>::iterator it;


	// ������ �տ���
	transform(a.begin(), a.end(), b.begin(), c.begin(), merge);  // ���� ������ �� �տ� ����� a.begin()~a.end() �� ������
	// b.begin() �� ���ָ� b.begin() ���� �˾Ƽ� a.begin() ~ a.end() ���� ��ŭ b.begin���� ���ͷ����Ͱ� �̵�. b.end()�� ���� x
	// merge�Լ��κ��� ���ϰ��� �޾ƴٰ� c���Ϳ� push_back�� �ƴ� �׳� ���� �ִ°ű� ������
	// c���Ϳ� �޸𸮰� �̹� ���� �־�� ��. �׷��� ���� ��

	cout << endl;
	it = c.begin();
	while (it != c.end()) {
		cout << *it << "  ";
		it++;
	}
}
*/



/*
// 6��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int arr[] = { 5,3,1,6,4,7,2 };
	vector<int>vec(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])]);
	vector<int>::iterator it;

	cout << "���� �� ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}
	sort(vec.begin(), vec.end());
	cout << "\n\n���� �� ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;

}
*/

/*
// 7��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	vector<int>vec(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])]);
	vector<int>::iterator it;

	cout << "���� �� ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}

	partial_sort(vec.begin()+3, vec.begin()+7, vec.end());

	cout << "\n\n���� �� ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;
}
*/



/*
// 8�� 
// stable_sort
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Age {
	string name;
	int age;
};

void print(Age a) {
	cout << a.name << ", " << a.age << "  ";
}

bool compareAge(Age a, Age b) {
	return (a.age < b.age);           // **** ���� - ���⼭ true�� �յ� ��ġ �ȹٲٴ� �Ű� false�� ��ġ �ٲٴ� ����  = > ����!!
}

int main()
{
	vector<Age> vec;
	Age ex[6]{
		{"ccc", 30}, {"bbb", 10}, {"aaa", 10},
		{"ddd", 40}, {"eee", 50}, {"aaa", 20}
	};
	for (int i = 0; i < 6; i++) {
		vec.push_back(ex[i]);
	}

	cout << "���� �� ----\n";
	for (int i = 0; i < 6; i++) {
		print(vec[i]);
	}

	stable_sort(vec.begin(), vec.end(), compareAge);
	cout << "\n\nstable_sort ���� �� ----\n";
	for (int i = 0; i < 6; i++) {
		print(vec[i]);
	}

	cout << endl << endl;
}
*/



/*
// 9��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int a)
{
	cout << "[" << a << "]" << "  ";
}
int main()
{
	int arr[] = { 3,6,1,9,2,3,3,3 };
	vector<int>vec(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])]);
	vector<int>::iterator it;

	cout << "ó�� vec ���� -----\n";
	it = vec.begin();
	while (it != vec.end()) {
		print(*it);
		it++;
	}

	it = vec.begin();
	while (it != vec.end()) {
		if ((*it) == 3) it = vec.erase(it);
		else it++;
	}
	cout << "\n\n���Ϳ��� ���� 3�� ���� ���� -----\n";
	it = vec.begin();
	while (it != vec.end()) {
		print(*it);
		it++;
	}

	cout << endl << endl;
}
*/

/*
// 10��
#include<iostream>
#include<vector>
using namespace std;

bool isOdd(int d) {
	return (d % 2 != 0);
}

void print(int a)
{
	cout << "[" << a << "]" << "  ";
}

int main()
{
	int arr[] = { 5,3,1,2,3,4 };
	vector<int>vec(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])]);
	vector<int>::iterator it;

	cout << "ó�� vec ���� -----\n";
	it = vec.begin();
	while (it != vec.end()) {
		print(*it);
		it++;
	}

	it = vec.begin();
	while (it != vec.end()) {
		if (isOdd(*it) ) it = vec.erase(it);
		else it++;
	}
	cout << "\n\n���Ϳ��� Ȧ���� ���� ���� -----\n";
	it = vec.begin();
	while (it != vec.end()) {
		print(*it);
		it++;
	}

	cout << endl << endl;
}
*/

/*
// 11��
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> vec;
	vector<string>::iterator it;
	string text;
	string tmp = "";
	cout << "������ �Է��ϼ���(�����Է½� ����)\n";
	getline(cin, text);
	int i;
	for (i = 0; i < text.length()+1; i++) {
		if (text[i] == 32 || text[i]==NULL ) { vec.push_back(tmp); tmp.clear(); tmp = ""; }
		else tmp += text[i];
	}

	vector<string> longword;
	int num = 0;
	it = vec.begin();
	while (it != vec.end()) {
		if ((*it).length() >= 6) { num++; longword.push_back((*it)); }
		it++;
	}

	cout << "\n\nũ�Ⱑ 6�̻��� �ܾ��� �� : " << num << endl;
	it = longword.begin();
	while (it != longword.end()) {
		cout << *it << endl;
		it++;
	}
	cout << endl << endl;
}
*/






/*
// ���� ����Ǯ���ϱ�
// 12��
// ���࿡�� ���� ���ͼ� ���񽺸� �ް� ������ ������ �ùķ��̼��Ͽ� ���ô�. 
// ���� �������� ť�� ����
#include<iostream>
#include<queue>
#include<random>
using namespace std;

struct guest {
	int entrance;   // ���� ť�� ���� �ð� - random�ϰ� ����
	int poptime;  // ���� ť���� ���� �ð�
	int service;  // ���� ���� �޴µ� �ɸ��ð� - random�ϰ� ����
	//int wait_time;  // ���� ��ٸ� �ð�
};
int main()
{
	const int TIME = 60;  // min - �� �ùķ��̼� �ð�: 60��
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> in(0, 10);  // ���� ������ �������� ť�� ���´�.
	std::uniform_int_distribution<int> service(3, 20);  // ���� ���� �ð� 

	int r, wtime = 0;
	int num = 0;  // ���ѽð� ���� ���� �� ����
	int w = 0;  // �� ��� �ð�
	queue<guest> Q;  // �� ����Ʈ
	vector<int> entrance_time;  // ���� ���� �ð� ����
	vector<int> service_time;   // ���� ���� �޴� �ð� ���� 
	guest g;
	
	// �ٽ� ¥��
	//for (int t = 0;t<TIME; t++, wtime--) {
	//	if (wtime < 0) wtime = 0;
	//	r = in(gen);
	//	if (r < 3) {
	//		if(!Q.empty()) w += wtime;
	//		g.entrance = t;  g.service = service(gen);
	//		entrance_time.push_back(t);  service_time.push_back(g.service);
	//		Q.push(g);
	//		num++;
	//		wtime += Q.front().service;
	//	}
	//	if (Q.front().entrance + Q.front().service == t) {

	//		Q.pop();
	//	}
	//}
	



	cout << "\n���� ���� �޴� �ð� : ";
	for (int i = 0; i < service_time.size(); i++)
		cout << service_time[i] << " ";

	cout << "\n\n���� ���� �ð� : ";
	for (int i = 0; i < entrance_time.size(); i++)
		cout << entrance_time[i] << " ";

	cout << "\n\n���� ��� ��� �ð� : ";
	cout << w / num << "��\n";

}
*/



/*
// 13��- ����.
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
	string chulsu[] = { "CSK", "BHJ", "RDJ" };
	string younghee[] = { "CSK", "LYD", "SJW", "BHJ"};

	list<string> s1;
	s1.insert(s1.begin(),chulsu, chulsu + (sizeof(chulsu) / sizeof(chulsu[0])));
	list<string> s2;
	s2.insert(s2.begin(),younghee, younghee + (sizeof(younghee) / sizeof(younghee[0])));
	list<string>::iterator it;
	list<string> s3;

	s1.sort();
	s2.sort();

	cout << "ö��ģ�� : ";
	for (it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
		s3.push_back(*it);
	}
	cout << "\n����ģ�� : ";
	for (it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
		s3.push_back(*it);
	}

	cout << "\nö���� ���� ģ���� �� : ";
	for (it = s3.begin(); it != s3.end(); it++) {
		cout << *it << " ";
	}

	s2.merge(s1);
	s2.unique();
	s3 = s2;

	cout << "\nö���� ���� ģ���� ��<�ߺ�����> : ";
	for (it = s3.begin(); it != s3.end(); it++) {
		cout << *it << " ";
	}
	
}
*/





/*

// ���ڹ� ���� ���α׷�
#include<iostream>
#include<iomanip>
#include<time.h>
#include<string>
using namespace std;
int main()
{
	// �Ƿ��� �̸� ���
	string student[4][3] = {
	{ "���ֿ�", "��ä��", "������" },
	{ "������", "�����", "������" },   
	{ "������", "������", "�̼���" },   
	{ "�ǿ���", "������", "��ȫ��" },
	};

	string list[12];
	int idx = 0;
	int r, i, k;
	srand(time(NULL));

	for (i = 0; i < 12; i++) {
		r = rand() % 3;
		for (k = 0; k < idx; k++) {
			if (student[i % 4][r] == list[k]) { i--; break; }
		}
		if (k == idx) list[idx++] = student[i % 4][r];
		
	}
	k = 1;
	cout << "===== 2022 ���ڹ� ���� =====\n";
	for (i = 0; i < 12; i++) {
		if (i % 3 == 0) cout << "\n\n[ " << k++ << "�� ]\t";
		cout << list[i] << " ";
	}
	
	cout << endl << endl << endl << endl << endl;
}

*/





