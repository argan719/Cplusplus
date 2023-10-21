
/*
// 1번 - notion필기
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v[0] = 10;
	int n = v[2];
	v.at(2) = 5;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
*/

/*
// 2번-notion필기
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> sv;
	string name;

	cout << "이름을 5개 입력하시오" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">>";
		getline(cin, name);
		sv.push_back(name);
	}
	name = sv.at(0);
	for (int i = 1; i < sv.size(); i++) {
		if (name < sv[i])
			name = sv[i];
	}
	cout << "사전에서 가장 뒤에 나오는 이름은 " << name << endl;
}
*/


/*
// 3번-notion필기
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<double> scores(10);    // 벡터 사이즈 설정 가능
	// cout << scores.size() << endl;  // 10

	for (int i = 0; i < scores.size(); i++) {
		cout << "성적을 입력하시오: ";
		cin >> scores[i];    // 인덱스 차원으로 벡터 접근 가능
	}
	double highest = scores[0];
	for (int i = 1; i < scores.size(); i++)
		if (scores[i] > highest)
			highest = scores[i];
	cout << "최고 성적은 " << highest << "입니다.\n";

}
*/

/*
// 4번
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<double> scores;
	while (true) {
		double value = 0.0;
		cout << "성적을 입력하시오(종료는 -1): ";
		cin >> value;
		if (value < 0.0) break;
		scores.push_back(value);
	}
	double highest = scores[0];
	for (int i = 1; i < scores.size(); i++)
		if (scores[i] > highest)
			highest = scores[i];
	cout << "최고 성적은 " << highest << "입니다.\n";
	return 0;
}
*/





/*
// 5번 - notion필기
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<double> scores;
	while (true) {
		double value = 0.0;
		cout << "성적을 입력하시오(종료는 -1): ";
		cin >> value;
		if (value < 0.0) break;
		scores.push_back(value);
	}
	double highest = -100;
	vector<double>::iterator it;
	for (it = scores.begin(); it < scores.end(); it++)
		if (*it > highest)
			highest = *it;
	cout << "최고 성적은 " << highest << "입니다.\n";
}
*/

/*
// 6번
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> vec;

	vec.push_back("MILK");		// 벡터의 끝에 자료를 저장한다.
	vec.push_back("BREAD");
	vec.push_back("BUTTER");
	vector<string>::iterator it;		// 벡터를 순회하기 위하여 반복자를 선언한다.
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	vec.insert(vec.begin() + 1 , "APPLE");		// 벡터의 첫부분에 자료를 저장한다.
	vec.pop_back();			// 벡터의 끝에서 자료를 삭제한다.
	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
*/

/*
// 7번 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Movie {
private:
	string title;
	double rating;
public:
	Movie(string t = "", double r = 0.0) { title = t; rating = r; }
	void print_movie() { cout << title << ": " << rating << endl; }
};

int main()
{
	vector<Movie> movies;
	Movie m("titinic", 9.9);
	movies.push_back(m);
	movies.push_back(Movie("gone with the wind", 9.6));
	movies.push_back(Movie("terminator", 9.7));

	vector<Movie> ::iterator it;
	for (it = movies.begin(); it != movies.end(); ++it)
		it->print_movie();
	return 0;
}
*/

/*
// 8번
#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
	// 전체 벡터를 출력하기
	for (typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << endl;
	}
}

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);
	cout << "---------------------------------" << endl;

	// vec[2] 앞에 15 추가
	vec.insert(vec.begin() + 2, 15);
	print_vector(vec);

	cout << "---------------------------------" << endl;
	// vec[3] 제거
	vec.erase(vec.begin() + 3);
	print_vector(vec);
}
*/


/*
// 9번
#include<iostream>
#include<vector>

template<typename T>
void print_vector(std::vector<T>& vec) {
	// 전체 벡터를 출력하기
	std::cout << "[ ";
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << "]";
}
int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(20);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);

	std::vector<int>::iterator itr = vec.begin();
	std::vector<int>::iterator end_itr = vec.end();

	//for (; itr != end_itr; ++itr) {
	//	if (*itr == 20) {
	//		vec.erase(itr);
	//	}
	//}

	for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
		if (vec[i] == 20) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}

	std::cout << "값이 20인 원소를 지운다!" << std::endl;
	print_vector(vec);
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
	vector<int> v;

	cout << "5개의 정수를 입력하세요>> ";
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++)
		cout << *it << ' ';
	cout << endl;
}
*/


/*
// 11번
#include<iostream>
#include<iterator>
#include<vector>

int main()
{
	using namespace std;

	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);
	// 배열에서 벡터로 복사한다
	copy(casts, casts + 10, dice.begin());
	// ostream 이터레이터를 생성한다
	ostream_iterator<int, char> out_iter(cout, " ");
	// 벡터에서 출력 스트림으로 복사한다
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "역방향 이터레이터의 암시적 사용:\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "역방향 이터레이터의 명시적 사용:\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;
	return 0;
}
*/

/*
// 12번 
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
	queue<int> qu;
	qu.push(100);
	qu.push(200);
	qu.push(300);
	while (!qu.empty()) {
		cout << qu.front() << endl;  //맨 앞 요소 가리킴
		qu.pop();  //맨 앞 요소 제거
	}
	return 0;
}
*/

/*
// 13번
#include<iostream>
#include<list>
using namespace std;
void print_list(list<int>& li);
int main()
{
	list<int> my_list;
	my_list.push_back(10);
	my_list.push_back(20);
	my_list.push_back(30);
	my_list.push_back(40);
	my_list.insert(my_list.begin(), 5);
	my_list.insert(my_list.end(), 45);
	print_list(my_list);
	return 0;
}

void print_list(list<int>& li)
{
	list<int>::iterator it;
	for (it = li.begin(); it != li.end(); ++it)
		cout << *it << " ";
	cout << endl;
}
*/


/*
// 14번
#include<iostream>
#include<string>
#include<list>
using namespace std;
class Movie {
private:
	string title;
	int year;
public:
	Movie(string t = "", int y = 0) { title = t; year = y; }
	void display() { cout << title << ": " << year << endl; }
	double getYear() { return year; }
};
void print_list(list<Movie>& li) {
	list<Movie>::iterator it;
	for (it = li.begin(); it != li.end(); ++it)
		it->display();
	cout << endl;
}

int main()
{
	list<Movie> movies;
	movies.push_back(Movie("사운드오브뮤직", 1939));
	movies.push_back(Movie("터미네이터", 1984));
	movies.push_back(Movie("타이타닉", 1998));
	list<Movie> old_movie;
	list<Movie> new_movie;
	list<Movie>::iterator it;
	it = movies.begin();
	while (it != movies.end()) {
		if (it->getYear() > 1980)
			new_movie.push_back(*it);  // 참조값을 푸쉬백. 
		else                        // (푸쉬백하면 알아서 커서가 다음 값 넣을 자리에 가 있음)
			old_movie.push_back(*it);
		it = movies.erase(it);  
	}
	cout << "고전 영화" << endl;
	print_list(old_movie);
	cout << "최근 영화" << endl;
	print_list(new_movie);
	return 0;
}
*/


/*
// 15번
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>  // for_each

using namespace std;
void outint(int n) { cout << n << " "; }

int main()
{
	using namespace std;
	list<int> one(5, 2);	// 5개의 2로 구성된 리스트 ( 2가 5개 들어감 )
	//  // list one 출력해봄
	//list<int>::iterator it;
	//it = one.begin();
	//while (it != one.end()) {
	//	outint(*it);         // 출력결과  2 2 2 2 2
	//	it++;
	//}
	
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);  // list.insert(list.begin(), arr, arr + std::size(arr)); 
	int more[6] = { 6,4,2,4,6,5 };                // -> list의 0번째부터 arr의 값이 전부 삽입됨
	list<int> three(two);
	three.insert(three.end(), more, more + 6); // three의 마지막 위치부터 이어서 more의 값이 전부 들어감

	cout << "리스트 one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "리스트 two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	three.remove(2);      // 2 찾아서 모두 삭제
	cout << endl << "리스트 three에서 2들을 삭제: ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);   // one을 three의 처음에 붙임
	cout << endl << "접목 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);  // 2 2 2 2 2 1 4 8 6 6 4 4 6 5
	cout << endl << "리스트 one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();   // 같은 수가 '연속'으로 나오면 하나만 남기고 중복되는 수 제거 
	cout << endl << "단일화 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);  // 2 1 4 8 6 4 6 5
	three.sort();     // 오름차순으로 정렬
	three.unique();
	cout << endl << "정렬과 단일화 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);   // 오름차순으로 정렬된 두 리스트를 병합 
	cout << endl << "정렬된 리스트 two를 리스트 three에 합병: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	return 0;
}
*/

/*
// 16번
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>

int main()
{
	using namespace std;
	const int N = 6;
	string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
	string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };

	set<string> A(s1, s1 + N);  // s1 배열의 값이 정렬되서 들어감
	set<string> B(s2, s2 + N);  // s2 배열의 값이 정렬되서 들어감

	ostream_iterator <string, char> out(cout, " ");
	cout << "집합  A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "집합 B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 합집합: \n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 교집합: \n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 차집합: \n"; // A - B
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	cout << "집합 C:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
	copy(C.begin(), C.end(), out);  // C에는 A와 B의 합집합이 들어감
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "삽입한 후의 집합 C:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "특정한 범위를 표시:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;
	return 0;
}
*/


/*
// 17번
#include<iostream>
#include<set>
using namespace std;
template <typename T>
void print_list(const T& container);

int main()
{
	set<int> my_set;
	multiset<int> my_multiset; // 중복허용

	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(3);

	my_multiset.insert(my_set.begin(), my_set.end()); // 1 2 3
	my_multiset.insert(3);
	my_multiset.insert(4);

	print_list(my_set);   // 1 2 3
	print_list(my_multiset);  // 1 2 3 3 4
	return 0;
}

template <typename T>
void print_list(const T& container) {
	T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		cout << *it << " ";
	cout << endl;
}
*/

/*
// 18번
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> my_set;

	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(3);

	set<int>::iterator pos = my_set.find(2);
	if (pos != my_set.end())
		cout << "값 " << *pos << "가 발견되었음" << endl;
	else
		cout << "값이 발견되지 않았음" << endl;
	return 0;
}

// 실행결과  값 2가 발견되었음
*/

/*
// 19번
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<string, string> dic;
	dic["boy"] = "소년";
	dic["school"] = "학교";
	dic["office"] = "직장";
	dic["house"] = "집";
	dic["morning"] = "아침";
	dic["evening"] = "저녁";

	cout << "house의 의미는 " << dic["house"] << endl;    // 등록이 된 단어
	cout << "morning의 의미는 " << dic["morning"] << endl;   // 등록이 된 단어
	cout << "unknown의 의미는 " << dic["unknown"] << endl;    // 등록이 안된 단어
	return 0;
}
*/

/*
// 20번
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

typedef int KeyType;
typedef pair<const KeyType, string> Pair;
typedef multimap<KeyType, string> MapCode;

int main()
{
	MapCode codes;   // multimap<int, string> codes;

	codes.insert(Pair(415, "샌프란시스코")); // .insert(pair<const int, string>(415, "샌프란시스코"));
	codes.insert(Pair(510, "오클랜드"));
	codes.insert(Pair(718, "브루클린"));
	codes.insert(Pair(718, "스태든 섬"));
	codes.insert(Pair(415, "샌라파엘"));
	codes.insert(Pair(510, "버클리"));

	cout << "지역 코드가 415인 도시 수: "
		<< codes.count(415) << endl;
	cout << "지역 코드가 718인 도시 수: "
		<< codes.count(718) << endl;
	cout << "지역 코드가 510인 도시 수: "
		<< codes.count(510) << endl;
	cout << "지역 코드  도시\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << "   " << (*it).first << "   "
		<< (*it).second << endl;

	pair<MapCode::iterator, MapCode::iterator> range
		= codes.equal_range(718);
	cout << "지역 코드가 718인 도시들:\n";
	for (it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;

	return 0;
}
*/

/*
// 21번
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack<string> st;
	string sayings[3] = {
		"The grass is greener on the other side of the fence",
		"Even the greatest make mistakes",
		"To see is to believe"
	};

	for (int i = 0; i < 3; ++i)
		st.push(sayings[i]);

	while (!st.empty()) {
		cout << st.top() << endl;  // 삭제될 데이터 - top데이터 삭제 전 출력
		st.pop();  // top데이터 삭제 (삭제만 되고 출력은 안됨 - FILO)
	}
	return 0;
}
*/

/*
// 22번
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
	queue<int> qu;
	qu.push(100);
	qu.push(200);
	qu.push(300);
	while (!qu.empty()) {
		cout << qu.front() << endl;   // 삭제될 데이터 출력 - front데이터
		qu.pop();  // front데이터 삭제  (FIFO - 앞에서부터 삭제)
	}
	return 0;
}
*/

/*
// 23번
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
	priority_queue<int> pq;
	pq.push(100);
	pq.push(200);
	pq.push(300);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}
*/


/*
// 24번
#include<iostream>
#include<deque>

using namespace std;

int main() {
	deque<int> dq;

	for (int i = 0; i < 5; i++)
		dq.push_back((i + 1) * 10);

	//iterator 선언
	deque<int>::iterator iter;

	//[default 출력]
	cout << "[Default] : ";
	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	//[test1] : 앞 뒤 삽입
	cout << "[Test1] push_front & end : ";

	dq.push_front(1);
	dq.push_front(2);
	dq.push_back(100);
	dq.push_back(200);

	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	//[test2] : 역으로 출력
	cout << "[Test2] reverse_iterator : ";

	deque<int>::reverse_iterator riter;

	for (riter = dq.rbegin(); riter != dq.rend(); riter++)
		cout << *riter << " ";
	cout << endl;

	return 0;
}
*/




// 문제풀이 23페이지

/*
// 1번
#include<iostream>
#include<vector>
#include<random>
using namespace std;

int main()
{
	vector<int> vec;
	random_device rd;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	mt19937 gen(rd());

	// 1부터 100 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis(1, 100);

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		vec.push_back(dis(gen));
		sum += vec[i];
	}

	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "sum= " << sum << endl;
}
*/

/*
// 2번
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> v;
	string name;
	cout << "이름5개를 입력하세요\n";
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << " : ";
		cin >> name;
		v.push_back(name);
	}

	vector<string>::iterator it;
	it = v.begin();
	string max = v[0];
	while (it != v.end()) {
		if (max < *it) max = *it;
		it++;
	}
	cout << "사전에서 가장 뒤에 나오는 이름은 " << max << endl;
}
*/

/*
// 3번
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;
	it = v.begin();
	while (it != v.end()) {
		*it = *it * 2;
		cout << *it << " ";
		it++;
	}
}
*/

/*
// 4번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int num;
	cout << "5개의 정수를 입력 하세요 >> ";
	for (int i = 0; i < 5; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << "정렬 후 : ";
	for (int i = 0; i < 5; i++)
		cout << v[i] << " ";
	cout << endl;
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
	vector<double> score;
	double s, sum = 0;
	for (int i = 0; i < 10; i++) {
		cout << "점수를 입력하세요 : ";
		cin >> s;
		score.push_back(s);
	}
	// 최저점과 최고점은 합계에서 제외하기 위해 sort후 맨 첫값과 끝 값 계산에서 제외
	sort(score.begin(), score.end());
	
	vector<double>::iterator it;
	it = score.begin() + 1;
	while (it != score.end() - 1) {
		sum += *it;
		it++;
	}
	cout << "최종점수 : " << sum << endl;
}
*/


/*
// 6번
// map으로 구현
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	map<string, string> dictionary;
	string word;
	string meaning;
	int a;
	for (;;) {
		cout << "\n1. 단어추가  2. 단어검색  3. 단어삭제  4. 종료\n";
		cin >> a;
		if (a == 4) { cout << "사전이 종료되었습니다.\n"; break; }
		else if (a == 1) {
			cout << "단어입력 : ";
			cin >> word;
			cin.get();
			cout << "뜻 입력 : ";
			getline(cin, meaning);
			//dictionary[word] = meaning;
			dictionary.insert(pair<string, string>(word, meaning));
		}
		else if (a == 2) {
			cout << "단어입력 : ";
			cin >> word;
			cout << word << "의 뜻 : " << dictionary[word] << endl;
		}
		else if (a == 3) {
			cout << "삭제할 단어입력 : ";
			cin >> word;
			dictionary.erase(word);
			cout << word << "단어가 사전에서 삭제되었습니다\n";
		}
		else { cout << "사전이 종료되었습니다.\n"; break; }
	}
}
*/


/*
// 7번
// list를 사용하여 작성하시오.
#include<iostream>
#include<list>
#include<string>
using namespace std;
class Student {
private:
	string name;     // 학생이름
	string address;  // 주소
	int num;	     // 학번
	string tell;     // 전화번호
public:
	Student() {}
	void set(string n, string a, int numm, string t) {
		name = n;
		address = a;
		num = numm;
		tell = t;
	}
	string get_name() { return name; }
	string get_address() { return address;}
	int get_num() { return num; }
	string get_tell() { return tell; }

};
int main()
{
	list<Student> student;
	list<Student>::iterator it;
	string name, address, tell;
	Student tmp;
	int num;
	int a;
	for (;;) {
		cout << "\n1. 추가  2. 검색  3. 삭제  4. 종료\n";
		cout << "=> ";
		cin >> a;
		if (a == 4) { cout << "종료되었습니다.\n"; break; }
		else if (a == 1) {
			cout << "학생이름 : ";  cin >> name;
			cout << "주 소 : ";  cin >> address;
			cout << "학 번 : ";  cin >> num;
			cout << "전화번호 : ";  cin >> tell;
			tmp.set(name, address, num, tell);
			student.push_back(tmp);
		}
		else if (a == 2) {
			cout << "학생이름 : ";
			cin >> name;
			it = student.begin();
			while (it != student.end()) {
				if ((*it).get_name() == name) {
					cout << "\n=== 검색결과 ===\n";
					cout << "학생이름 : " << (*it).get_name() << endl;
					cout << "주 소 : " << (*it).get_address() << endl;
					cout << "학 번 : " << (*it).get_num() << endl;
					cout << "전화번호 : " << (*it).get_tell() << endl;
					break;
				}
				it++;
			}
			if (it == student.end()) cout << "검색에 실패하였습니다. 등록되지 않은 학생입니다.\n";
		}
		else if (a == 3) {
			cout << "학생이름 : ";
			cin >> name;
			it = student.begin();
			while (it != student.end()) {
				if ((*it).get_name() == name) {
					student.erase(it);
					cout << name << " 학생 정보가 삭제되었습니다." << endl;
					break;
				}
				else it++;
			}
		}
		else{ cout << "종료되었습니다.\n"; break; }
	}
}
*/




/*
// 8번 - 질문 - 이렇게 매번 while문 돌려서 2,3,5,7의 배수 따로따로 삭제하는 방법 말고 더 간단하게 한번에 할 수 있는 방법은 없는지?
// 없음. 이렇게 만들라고 했으니 이렇게 만들면 됨. 문제에서 원하는 방법이 이 방법임. 맞게 한거임.
// list 사용
#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> prime;
	list<int>::iterator it;
	// 2~100 숫자 삽입
	for (int i = 2; i < 101; i++) {
		prime.push_back(i);
	}


	// 2의 배수 삭제
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it)!=2 && (*it) % 2 == 0) {
			it = prime.erase(it); 
		}
		else it++;
	}
	// 3의 배수 삭제
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it) != 3 && (*it) % 3 == 0) {
			it = prime.erase(it);
		}
		else it++;
	}
	// 5의 배수 삭제
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it) != 5 && (*it) % 5 == 0) {
			it = prime.erase(it);
		}
		else it++;
	}
	// 7의 배수 삭제
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it) != 7 && (*it) % 7 == 0) {
			it = prime.erase(it);
		}
		else it++;
	}

	cout << "== 에라스토테네스 체 알고리즘 실행결과 ==\n";
	it = prime.begin();
	while (it != prime.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;
}
*/


/*
// 9번
// set을 사용하시오
#include<iostream>
#include<random>
#include<set>
using namespace std;
int main()
{
	set<int> lotto;
	set<int>::iterator it;
	int r;
	std::random_device rd;
	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());

	// 1 부터 45 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(1, 45);

	cout << "로또 번호 발생기\n";
	for (int i = 0; i < 6; i++) {
		r = dis(gen);
		if (lotto.find(r) == lotto.end()) lotto.insert(r);
		else i--;
	}
	cout << "로또번호 : ";
	it = lotto.begin();
	while (it != lotto.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;
}
*/

/*
// 10번
// vector를 사용하시오
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Book {
private:
	int year;
	string name;
	string author;
public:
	void set(int y, string n, string a) {
		year = y;  name = n;  author = a;
	}
	int get_year() { return year; }
	string get_name() { return name; }
	string get_author() { return author; }
};

int main()
{
	vector<Book> v;
	vector<Book>::iterator it;
	int a, year;
	string name, author;
	Book tmp;

	for (;;) {
		cout << "\n=== 메뉴 ===\n";
		cout << "1. 입력\n" << "2. 검색\n" << "3. 종료\n";
		cout << "=> ";
		cin >> a;
		if (a == 3) { cout << "종료되었습니다.\n"; break; }
		else if (a == 1) {
			cout << "년도 : ";  cin >> year;
			cout << "책이름 : ";  cin >> name;
			cout << "저자 : ";  cin >> author;
			tmp.set(year, name, author);
			v.push_back(tmp);
			cout << "책이 입고되었습니다!\n";
		}
		else if (a == 2) {
			cout << "저자이름 : ";  cin >> name;
			cout << "년도 : ";  cin >> year;
			it = v.begin();
			while (it != v.end()) {
				if ((*it).get_author() == name && (*it).get_year() == year) {
					cout << (*it).get_name() << "  " << (*it).get_author() << "  " << (*it).get_year() << endl;
					break;
				}
				it++;
			}
			if (it == v.end()) cout << "검색하신 결과를 찾을 수 없습니다.\n";
		}
		else { cout << "종료되었습니다.\n"; break; }
	}
}
*/

/*
// 11번
// vector를 사용하시오
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Circle {
private:
	double radius;
	string name;
public:
	void set(double r, string n) {
		radius = r;  name = n;
	}
	double get_radius() { return radius; }
	string get_name() { return name; }
};

int main()
{
	vector<Circle> c;
	vector<Circle>::iterator it;

	Circle tmp;
	int a, r;
	string name;
	for (;;) {
		cout << "\n1. 삽입\n2. 삭제\n3. 모두보기\n4. 종료\n";
		cout << "==> ";
		cin >> a;
		if (a == 4) { cout << "종료되었습니다\n"; break; }
		else if (a == 1) {
			cout << "원의 반지름 : ";  cin >> r;
			cout << "원의 이름 : ";  cin >> name;
			tmp.set(r, name);
			c.push_back(tmp);
			cout << endl;
		}
		else if (a == 2) {
			cout << "원의 이름 : ";  cin >> name;
			it = c.begin();
			while (it != c.end()) {
				if ((*it).get_name() == name) {
					it = c.erase(it);
					cout << "삭제되었습니다!\n";
				}
				else it++;
			}
		}
		else if (a == 3) {
			int i = 0;
			it = c.begin();
			cout << "\n== 원 전체보기 ==\n";
			while (it != c.end()) {
				i++;
				cout << "[ " << i << " ] "<< "원의 이름 : " << (*it).get_name() << "  반지름 : " << (*it).get_radius() << endl;
				it++;
			}
			cout << endl;
		}
		else { cout << "종료되었습니다\n"; break; }
	}
}
*/

/*
// 12번 - 벡터를 사용하여 구현
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> man;
	vector<string> female;

	string name;
	char gender;

	cout << "** 미팅 주선 프로그램 **\n";
	for (;;) {
		cout << "\n고객이름 : ";  cin >> name;
		cout << "성별을 입력하세요(f or m) : ";  cin >> gender;
		if (gender == 'm') { 
			if (!female.empty()) {
				cout << "커플이 탄생했습니다! " << name << "과 " << female[0] << endl;
				female.erase(female.begin());
			}
			else {
				man.push_back(name);
				cout << "아직 대상자가 없습니다. 기다려 주십시오.\n";
			}
		}
		else if (gender == 'f') {
			female.push_back(name);
			if (!man.empty()) {
				cout << "커플이 탄생했습니다! " << man[0] << "과 " << female[0] << endl;
				female.erase(female.begin());
				man.erase(man.begin());
			}
		}
		else cout << "성별을 다시 입력하세요\n";
	}
}
*/

/*
// 12번 - 큐를 사용하여 구현
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	queue<string> man;
	queue<string> female;

	string name;
	char gender;

	cout << "** 미팅 주선 프로그램 **\n";
	for (;;) {
		cout << "\n고객이름 : ";  cin >> name;
		cout << "성별을 입력하세요(f or m) : ";  cin >> gender;
		if (gender == 'm') {
			if (!female.empty()) {
				cout << "커플이 탄생했습니다! " << name << "과 " << female.front() << endl;
				female.pop();
			}
			else {
				man.push(name);
				cout << "아직 대상자가 없습니다. 기다려 주십시오.\n";
			}
		}
		else if (gender == 'f') {
			female.push(name);
			if (!man.empty()) {
				cout << "커플이 탄생했습니다! " << man.front() << "과 " << female.front() << endl;
				female.pop();
				man.pop();
			}
		}
		else cout << "성별을 다시 입력하세요\n";
	}
}
*/


/*
// 12번 - deque를 사용하여 구현 (+즉시 원함 기능 추가)
#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main()
{
	deque<string> man;
	deque<string> female;

	string name;
	char gender, instant;

	cout << "** 미팅 주선 프로그램 **\n";
	for (;;) {
		cout << "\n고객이름 : ";  cin >> name;
		cout << "성별을 입력하세요(f or m) : ";  cin >> gender;
		cout << "즉시 미팅을 원하십니까?(y/n) : ";  cin >> instant;
		if (gender == 'm') {
			if (instant == 'y') man.push_front(name);
			else man.push_back(name);
			if (!female.empty()) {
				cout << "커플이 탄생했습니다! " << man.front() << "과 " << female.front() << endl;
				female.pop_front();
				man.pop_front();
			}
			else cout << "아직 대상자가 없습니다. 기다려 주십시오.\n";
		}
		else if (gender == 'f') {
			if (instant == 'y') female.push_front(name);
			else female.push_back(name);
			if (!man.empty()) {
				cout << "커플이 탄생했습니다! " << man.front() << "과 " << female.front() << endl;
				female.pop_front();
				man.pop_front();
			}
		}
		else cout << "성별을 다시 입력하세요\n";
	}
}

// 잘 작동하는데 이런 문제가 발생함

// 홍길동이 먼저 와서 즉시 미팅 원했고
// 그다음에 이순신이 와서 이순신도 즉시 미팅 원했다고 하자,
// 여자 한명이 오면 홍길동이 먼저 주선되는게 맞는데 위 코드대로 하면 이순신이 먼저 주선됨. 
// 홍길동, 이순신 모두 push_front로 했기 때문에

// => 어떻게 할 수 없음. 어쩔 수 없다. push_front를 썼기 때문에

*/