
/*
// 1번
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string fruits[5] = { "사과", "토마토", "배", "수박", "키위" };
	vector<string> vec(&fruits[0], &fruits[5]);  // 벡터 선언할 때 배열 값으로 초기화 - 이런식으로 한다.(배열을 벡터에 넣음)

	vector<string>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	it = find(vec.begin(), vec.end(), "수박"); // 3
	if (it != vec.end())
		cout << "수박이 " << distance(vec.begin(), it) << "번째에 있습니다." << endl;
	return 0;
}
*/


/*
// 2번
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool checkKim(string s)
{
	if (s.find("김") != string::npos)
		return true;
	else
		return false;
}
int main()
{
	string names[5] = { "김철수", "박문수", "강감찬", "김유신", "이순신" };
	vector<string> vec(&names[0], &names[5]);

	vector<string>::iterator it;
	it = vec.begin();

	while (true) {
		it = find_if(it, vec.end(), checkKim);
		if (it == vec.end())			// 탐색 실패
			break;
		cout << "위치 " << distance(vec.begin(), it) << "에서 " << *it << "를 탐색하였음 " << endl;
		it++;
	}
}
*/

/*
// 3번
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

	for (int d : vec)  // 범위 기반 for 문(ranged-based for statement) vector의 값이 하나씩 int d 로 옮겨짐. 벡터가 끝날때까지
		cout << d << "  ";

	cout << endl;
	list<int> ilist;
	for (int i = 3; i < 6; i++)		// ilist = (3,4,5)
		ilist.push_back(i);

	vector<int>::iterator it;
	it = search(vec.begin(), vec.end(), ilist.begin(), ilist.end());  // 3 4 5가 통으로(그대로) vector에 들어있어야 찾을수있음
																					// 3 4 5 가 시작되는 위치 - 3의 위치 반환
	if (it != vec.end()) {
		cout << *it << "구간은 " << distance(vec.begin(), it) << "번째에 있습니다." << endl;
	}
}
*/

/*
// 4번
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
	size_t n2 = count_if(vec.begin(), vec.end(), is_even<int>); // vec.begin ~ vec.end 까지 범위내에서 is_even함수가 쭉 실행됨

	cout << "값이 'o'인 요소의 개수: " << n1 << endl;
	cout << "값이 짝수인 요소의 개수: " << n2 << endl;
}
*/

/*
// 5번
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
		cout << wanted << "을 찾았음 " << endl;
	else {
		it = lower_bound(vec.begin(), vec.end(), wanted); // lower_bound : 정렬을 깨지 않도록 순서에 맞게 wanted가 들어가야 하는 위치 반환
		vec.insert(it, wanted);
	}
	print(vec);

	return 0;
}
*/

/*
// 6번
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
	// vec1의 +2부터 vec1의 +5까지의 구간과 (3,4,5)
	// vec2의 +2부터 3개를 비교함 (3,4,5)  
	// '구간비교'

	if (isEqual == true)
		cout << "두 개의 구간이 동일함" << endl;
}
*/


/*
// 7번
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
	
	cout << "fill() 이전의 값 ";
	print(v1);
	fill(v1.begin(), v1.end(), 0);

	cout << "fill() 이후의 값 ";
	print(v1);
}
*/


/*
// 8번
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string names[5] = { "사과", "배", "키위", "레몬", "포도" };
	vector<string> fruits(5);
	vector<string>::iterator it;

	copy(&names[0], &names[5], fruits.begin());  // names[0]부터 names[5]까지의 값을 fruit.begin()에다가 집어넣음
	reverse(fruits.begin(), fruits.end());  // 거꾸로 바꿈

	for (it = fruits.begin(); it != fruits.end(); ++it)  // reverse했기 때문에 begin부터 end까지 찍는데 역행으로 나옴.
		cout << *it << " ";
}

// 실행결과   포도 레몬 키위 배 사과
*/

/*
// 9번
#include<iostream>
#include<algorithm>  // for_each
#include<vector>
using namespace std;
// 각 요소에 대하여 호출되는 함수
void display(int element)
{
	cout << element << ' ';
}

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	for_each(vec.begin(), vec.end(), display); // 범위 내의(vec.begin() ~ end()-1) 벡터값이 (vec[i]) display의 int element로 보내짐
	cout << endl;			// 범위 내에서 iterator가 한 칸씩 이동하면서 벡터값에 대해(역참조) display() 실행 
	return 0;
}

// for_each(vec.begin(), vec.end(), display);는 

// for(int i=begin; i<end ; i++)
//		v[i].display();
// 이거랑 같다고 생각하면 됨.
*/


/*
// 10번
#include<iostream>
#include<algorithm>
#include<vector>
#include "myheader.h"
using namespace std;

// 각 요소에 대하여 호출되는 함수
int increment(int element)  // 근데 여기서 int &element로 쓰면 vec값에도 ++된게 반영됨
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
	transform(vec.begin(), vec.end(), result.begin(), increment); // increment함수 실행한 값을 result.begin()부터 넣음
	print(result);
	//cout << endl << endl;
	//print(vec);  vec값에는 변함이 없음
}
*/

/*
// 11번
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include "myheader.h"
using namespace std;

int main()
{
	string names[5] = { "사과", "배", "키위", "레몬","포도" };
	vector<string> fruits(5);
	copy(&names[0], &names[5], fruits.begin());
	print(fruits, "삭제전\n");  // 삭제전  (사과 배 키위 레몬 포도)
	vector<string>::iterator it;
	it = remove(fruits.begin(), fruits.end(), "레몬");
	print(fruits, "remove() 후\n");  // remove() 후  (사과 배 키위 포도)
	fruits.erase(it, fruits.end()); 
	print(fruits, "erase() 후\n");  // erase() 후  (사과 배 키위 포도)
}
*/


/*
// 12번
#include<iostream>
#include<algorithm>
#include<vector>
#include "myheader.h"
using namespace std;

int main()
{
	int value[10] = { 82, 25, 26, 7, 67, 55, 31, 19, 99 };

	vector<int> v1(&value[0], &value[10]);
	print(v1, "초기리스트\n");
	sort(v1.begin(), v1.end());
	print(v1, "sort() 적용 후 리스트\n");

	vector<int> v2(&value[0], &value[10]);
	stable_sort(v2.begin(), v2.end());
	print(v2, "stable_sort() 적용 후 리스트\n");

	vector<int> v3(&value[0], &value[10]);
	partial_sort(v3.begin(), v3.begin() + 3, v3.end());
	print(v3, "partial_sort() 적용 후 리스트\n");

	vector<int> v4(&value[0], &value[10]);
	nth_element(v4.begin(), v4.begin() + 5, v4.end());
	print(v4, "nth_element() 적용 후 리스트\n");
	return 0;
}
*/

/*
// 13번
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

	std::cout << "정렬 전 ----" << std::endl;
	print(vec.begin(), vec.end());
	std::sort(vec.begin(), vec.end(), int_compare()); // int_compare구조체 안에 있는 operator() 호출

	std::cout << "정렬 후 ----" << std::endl;
	print(vec.begin(), vec.end());
}
*/

/*
// 14번
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "myheader.h"
using namespace std;
// 문자열의 길이를 가지고 정렬한다. - 길이 오름차순
bool is_less(const string& s1, const string& s2)
{
	return s1.length() < s2.length();
	// true를 반환하면 위치 안바꾸는 거고 false이면 위치 바꾸는 거임.
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

	print(vec1, "처음 문자열\n");

	sort(vec1.begin(), vec1.end(), is_less);
	stable_sort(vec2.begin(), vec2.end(), is_less);

	print(vec1, "sort()이후 문자열\n");
	print(vec2, "stable_sort()이후 문자열\n");
	return 0;
}
*/


/*
// 15번 
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

	sum = accumulate(&v1[0], &v1[8], 0.0); // 0.0에다가 v1[0]~ v1[4]까지의 값을 더함
	cout << "누적합= " << sum << endl;

	vector<double> v2;
	partial_sum(&v1[1], &v1[4], back_inserter(v2)); //  누적해서 더함- 누적한 값을 매번 출력 
	// back_inserter로 v2에 그 값을 넣는 거임.
	// 구간을 (v1[1] ~ v1[4] 로 정했으면 2 2+3=5  5+4=9 => 2 5 9 출력됨)
	print(v2, "부분합=");
}
*/



/*
// 16번
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
// 문제풀이 13페이지
// 1번
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
		if (vec[i] == 3) cout << vec[i] << " 는 " << i + 1 << " 번째 원소\n";
	}

}
*/

/*
// 2번
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
	if (it == year.end()) cout << "못 찾았습니다\n";
	else cout << "1990~2019년 사이의 첫 번째 윤년 : " << (*it) << endl;
}
*/

/*
// 3번
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

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, 99);


	for (int i = 0; i < vec.size(); i++) {
		r = dis(gen);
		vec[i] = r;
	}
	cout << "벡터 내 난수 출력\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "  ";
	}
	for (int d : vec) {
		if (isEven(d)) rnum++;
	}

	cout << "\n\n벡터 내의 난수의 짝수의 개수 : " << rnum << endl;

	//it = vec.begin();
	//int rnum = -1;
	//while (it != vec.end()) {
	//	it = find_if(it, vec.end(), isEven); 
	//	if (it != vec.end()) rnum++;
	//	it++;
	//}
	//cout << "벡터 내의 난수의 짝수의 개수 : " << rnum << endl;
}
*/

/*
// 4번
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

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	// 5 부터 55555 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(555, 55555);

	int r;
	for (int i = 0; i < 100; i++) {
		r = dis(gen);
		vec.push_back(r);
	}
	cout << "벡터 내 난수 출력\n";
	for (int i = 0; i < 100; i++) {
		cout << vec[i] << "  ";
	}
	cout << endl << endl;

	it = min_element(vec.begin(), vec.end());
	cout << "난수의 최소값 : " << (*it) << endl;

	it = max_element(vec.begin(), vec.end());
	cout << "난수의 최대값 : " << (*it) << endl;
	
}
*/


/*
// 5번 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int merge(int a, int b) {
	return a + b;
}
int  main()
{
	// a가 더 긴경우 에러남. 
	// a길이를 기준으로 가는데 a는 보낼 값이 있는데 b는 더 이상 보낼 값이 없기 때문에 에러남
	// (b가 더길면 상관없음 transform에서 a.begin()~a.end()를 앞에 썼기 때문에 딱 그만큼만 실행하고 b남은건 그냥 병합안하는거임)
	int a_arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int b_arr[] = { 10,11,12,13,14,15,16,17,18,19,100,200 };

	vector<int> a(&a_arr[0], &a_arr[sizeof(a_arr) / sizeof(a_arr[0])]);
	vector<int> b(&b_arr[0], &b_arr[sizeof(b_arr) / sizeof(b_arr[0])]);
	vector<int> c(20);  // c 크기를 미리 잡아놔야 함. transform은 push_back하는게 아니라 그냥 insert하기 때문.
	//vector<int> c;
	vector<int>::iterator it;


	// 기준은 앞에꺼
	transform(a.begin(), a.end(), b.begin(), c.begin(), merge);  // 길이 기준은 맨 앞에 적어논 a.begin()~a.end() 가 기준임
	// b.begin() 만 써주면 b.begin() 부터 알아서 a.begin() ~ a.end() 길이 만큼 b.begin부터 이터레이터가 이동. b.end()를 쓰지 x
	// merge함수로부터 리턴값을 받아다가 c벡터에 push_back이 아닌 그냥 값을 넣는거기 때문에
	// c벡터에 메모리가 이미 잡혀 있어야 함. 그래야 값이 들어감

	cout << endl;
	it = c.begin();
	while (it != c.end()) {
		cout << *it << "  ";
		it++;
	}
}
*/



/*
// 6번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int arr[] = { 5,3,1,6,4,7,2 };
	vector<int>vec(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])]);
	vector<int>::iterator it;

	cout << "정렬 전 ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}
	sort(vec.begin(), vec.end());
	cout << "\n\n정렬 후 ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;

}
*/

/*
// 7번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	vector<int>vec(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])]);
	vector<int>::iterator it;

	cout << "정렬 전 ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}

	partial_sort(vec.begin()+3, vec.begin()+7, vec.end());

	cout << "\n\n정렬 후 ---- \n";
	it = vec.begin();
	while (it != vec.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;
}
*/



/*
// 8번 
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
	return (a.age < b.age);           // **** 질문 - 여기서 true면 앞뒤 위치 안바꾸는 거고 false면 위치 바꾸는 건지  = > 맞음!!
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

	cout << "정렬 전 ----\n";
	for (int i = 0; i < 6; i++) {
		print(vec[i]);
	}

	stable_sort(vec.begin(), vec.end(), compareAge);
	cout << "\n\nstable_sort 정렬 후 ----\n";
	for (int i = 0; i < 6; i++) {
		print(vec[i]);
	}

	cout << endl << endl;
}
*/



/*
// 9번
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

	cout << "처음 vec 상태 -----\n";
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
	cout << "\n\n벡터에서 값이 3인 원소 제거 -----\n";
	it = vec.begin();
	while (it != vec.end()) {
		print(*it);
		it++;
	}

	cout << endl << endl;
}
*/

/*
// 10번
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

	cout << "처음 vec 상태 -----\n";
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
	cout << "\n\n벡터에서 홀수인 원소 제거 -----\n";
	it = vec.begin();
	while (it != vec.end()) {
		print(*it);
		it++;
	}

	cout << endl << endl;
}
*/

/*
// 11번
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
	cout << "문장을 입력하세요(엔터입력시 종료)\n";
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

	cout << "\n\n크기가 6이상인 단어의 수 : " << num << endl;
	it = longword.begin();
	while (it != longword.end()) {
		cout << *it << endl;
		it++;
	}
	cout << endl << endl;
}
*/






/*
// 마저 문제풀이하기
// 12번
// 은행에서 고객이 들어와서 서비스를 받고 나가는 과정을 시뮬레이션하여 봅시다. 
// 고객의 대기행렬은 큐로 구현
#include<iostream>
#include<queue>
#include<random>
using namespace std;

struct guest {
	int entrance;   // 고객이 큐에 들어온 시각 - random하게 결정
	int poptime;  // 고객이 큐에서 나간 시각
	int service;  // 고객이 서비스 받는데 걸린시간 - random하게 결정
	//int wait_time;  // 고객이 기다린 시간
};
int main()
{
	const int TIME = 60;  // min - 총 시뮬레이션 시간: 60분
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> in(0, 10);  // 고객은 랜덤한 간격으로 큐에 들어온다.
	std::uniform_int_distribution<int> service(3, 20);  // 고객의 서비스 시간 

	int r, wtime = 0;
	int num = 0;  // 제한시간 동안 들어온 총 고객수
	int w = 0;  // 총 대기 시간
	queue<guest> Q;  // 고객 리스트
	vector<int> entrance_time;  // 고객이 들어온 시간 저장
	vector<int> service_time;   // 고객의 서비스 받는 시간 저장 
	guest g;
	
	// 다시 짜기
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
	



	cout << "\n고객이 서비스 받는 시간 : ";
	for (int i = 0; i < service_time.size(); i++)
		cout << service_time[i] << " ";

	cout << "\n\n고객이 들어온 시간 : ";
	for (int i = 0; i < entrance_time.size(); i++)
		cout << entrance_time[i] << " ";

	cout << "\n\n고객의 평균 대기 시간 : ";
	cout << w / num << "분\n";

}
*/



/*
// 13번- 끝냄.
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

	cout << "철수친구 : ";
	for (it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
		s3.push_back(*it);
	}
	cout << "\n영희친구 : ";
	for (it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
		s3.push_back(*it);
	}

	cout << "\n철수와 영희 친구의 합 : ";
	for (it = s3.begin(); it != s3.end(); it++) {
		cout << *it << " ";
	}

	s2.merge(s1);
	s2.unique();
	s3 = s2;

	cout << "\n철수와 영희 친구의 합<중복제거> : ";
	for (it = s3.begin(); it != s3.end(); it++) {
		cout << *it << " ";
	}
	
}
*/





/*

// 제자반 조편성 프로그램
#include<iostream>
#include<iomanip>
#include<time.h>
#include<string>
using namespace std;
int main()
{
	// 또래별 이름 명단
	string student[4][3] = {
	{ "박주영", "이채은", "전지현" },
	{ "윤진희", "이재용", "최유진" },   
	{ "박종명", "서윤하", "이수정" },   
	{ "권예림", "신지은", "신홍민" },
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
	cout << "===== 2022 제자반 조편성 =====\n";
	for (i = 0; i < 12; i++) {
		if (i % 3 == 0) cout << "\n\n[ " << k++ << "조 ]\t";
		cout << list[i] << " ";
	}
	
	cout << endl << endl << endl << endl << endl;
}

*/





