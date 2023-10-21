
/*
// 1�� - notion�ʱ�
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
// 2��-notion�ʱ�
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> sv;
	string name;

	cout << "�̸��� 5�� �Է��Ͻÿ�" << endl;
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
	cout << "�������� ���� �ڿ� ������ �̸��� " << name << endl;
}
*/


/*
// 3��-notion�ʱ�
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<double> scores(10);    // ���� ������ ���� ����
	// cout << scores.size() << endl;  // 10

	for (int i = 0; i < scores.size(); i++) {
		cout << "������ �Է��Ͻÿ�: ";
		cin >> scores[i];    // �ε��� �������� ���� ���� ����
	}
	double highest = scores[0];
	for (int i = 1; i < scores.size(); i++)
		if (scores[i] > highest)
			highest = scores[i];
	cout << "�ְ� ������ " << highest << "�Դϴ�.\n";

}
*/

/*
// 4��
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<double> scores;
	while (true) {
		double value = 0.0;
		cout << "������ �Է��Ͻÿ�(����� -1): ";
		cin >> value;
		if (value < 0.0) break;
		scores.push_back(value);
	}
	double highest = scores[0];
	for (int i = 1; i < scores.size(); i++)
		if (scores[i] > highest)
			highest = scores[i];
	cout << "�ְ� ������ " << highest << "�Դϴ�.\n";
	return 0;
}
*/





/*
// 5�� - notion�ʱ�
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<double> scores;
	while (true) {
		double value = 0.0;
		cout << "������ �Է��Ͻÿ�(����� -1): ";
		cin >> value;
		if (value < 0.0) break;
		scores.push_back(value);
	}
	double highest = -100;
	vector<double>::iterator it;
	for (it = scores.begin(); it < scores.end(); it++)
		if (*it > highest)
			highest = *it;
	cout << "�ְ� ������ " << highest << "�Դϴ�.\n";
}
*/

/*
// 6��
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> vec;

	vec.push_back("MILK");		// ������ ���� �ڷḦ �����Ѵ�.
	vec.push_back("BREAD");
	vec.push_back("BUTTER");
	vector<string>::iterator it;		// ���͸� ��ȸ�ϱ� ���Ͽ� �ݺ��ڸ� �����Ѵ�.
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	vec.insert(vec.begin() + 1 , "APPLE");		// ������ ù�κп� �ڷḦ �����Ѵ�.
	vec.pop_back();			// ������ ������ �ڷḦ �����Ѵ�.
	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
*/

/*
// 7�� 
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
// 8��
#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
	// ��ü ���͸� ����ϱ�
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

	cout << "ó�� ���� ����" << std::endl;
	print_vector(vec);
	cout << "---------------------------------" << endl;

	// vec[2] �տ� 15 �߰�
	vec.insert(vec.begin() + 2, 15);
	print_vector(vec);

	cout << "---------------------------------" << endl;
	// vec[3] ����
	vec.erase(vec.begin() + 3);
	print_vector(vec);
}
*/


/*
// 9��
#include<iostream>
#include<vector>

template<typename T>
void print_vector(std::vector<T>& vec) {
	// ��ü ���͸� ����ϱ�
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

	std::cout << "ó�� ���� ����" << std::endl;
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

	std::cout << "���� 20�� ���Ҹ� �����!" << std::endl;
	print_vector(vec);
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
	vector<int> v;

	cout << "5���� ������ �Է��ϼ���>> ";
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
// 11��
#include<iostream>
#include<iterator>
#include<vector>

int main()
{
	using namespace std;

	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);
	// �迭���� ���ͷ� �����Ѵ�
	copy(casts, casts + 10, dice.begin());
	// ostream ���ͷ����͸� �����Ѵ�
	ostream_iterator<int, char> out_iter(cout, " ");
	// ���Ϳ��� ��� ��Ʈ������ �����Ѵ�
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "������ ���ͷ������� �Ͻ��� ���:\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "������ ���ͷ������� ����� ���:\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;
	return 0;
}
*/

/*
// 12�� 
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
		cout << qu.front() << endl;  //�� �� ��� ����Ŵ
		qu.pop();  //�� �� ��� ����
	}
	return 0;
}
*/

/*
// 13��
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
// 14��
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
	movies.push_back(Movie("����������", 1939));
	movies.push_back(Movie("�͹̳�����", 1984));
	movies.push_back(Movie("Ÿ��Ÿ��", 1998));
	list<Movie> old_movie;
	list<Movie> new_movie;
	list<Movie>::iterator it;
	it = movies.begin();
	while (it != movies.end()) {
		if (it->getYear() > 1980)
			new_movie.push_back(*it);  // �������� Ǫ����. 
		else                        // (Ǫ�����ϸ� �˾Ƽ� Ŀ���� ���� �� ���� �ڸ��� �� ����)
			old_movie.push_back(*it);
		it = movies.erase(it);  
	}
	cout << "���� ��ȭ" << endl;
	print_list(old_movie);
	cout << "�ֱ� ��ȭ" << endl;
	print_list(new_movie);
	return 0;
}
*/


/*
// 15��
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>  // for_each

using namespace std;
void outint(int n) { cout << n << " "; }

int main()
{
	using namespace std;
	list<int> one(5, 2);	// 5���� 2�� ������ ����Ʈ ( 2�� 5�� �� )
	//  // list one ����غ�
	//list<int>::iterator it;
	//it = one.begin();
	//while (it != one.end()) {
	//	outint(*it);         // ��°��  2 2 2 2 2
	//	it++;
	//}
	
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);  // list.insert(list.begin(), arr, arr + std::size(arr)); 
	int more[6] = { 6,4,2,4,6,5 };                // -> list�� 0��°���� arr�� ���� ���� ���Ե�
	list<int> three(two);
	three.insert(three.end(), more, more + 6); // three�� ������ ��ġ���� �̾ more�� ���� ���� ��

	cout << "����Ʈ one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "����Ʈ two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);
	three.remove(2);      // 2 ã�Ƽ� ��� ����
	cout << endl << "����Ʈ three���� 2���� ����: ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);   // one�� three�� ó���� ����
	cout << endl << "���� ���� ����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);  // 2 2 2 2 2 1 4 8 6 6 4 4 6 5
	cout << endl << "����Ʈ one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();   // ���� ���� '����'���� ������ �ϳ��� ����� �ߺ��Ǵ� �� ���� 
	cout << endl << "����ȭ ���� ����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);  // 2 1 4 8 6 4 6 5
	three.sort();     // ������������ ����
	three.unique();
	cout << endl << "���İ� ����ȭ ���� ����Ʈ three: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);   // ������������ ���ĵ� �� ����Ʈ�� ���� 
	cout << endl << "���ĵ� ����Ʈ two�� ����Ʈ three�� �պ�: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	return 0;
}
*/

/*
// 16��
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

	set<string> A(s1, s1 + N);  // s1 �迭�� ���� ���ĵǼ� ��
	set<string> B(s2, s2 + N);  // s2 �迭�� ���� ���ĵǼ� ��

	ostream_iterator <string, char> out(cout, " ");
	cout << "����  A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "���� B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;

	cout << "A�� B�� ������: \n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A�� B�� ������: \n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A�� B�� ������: \n"; // A - B
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	cout << "���� C:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
	copy(C.begin(), C.end(), out);  // C���� A�� B�� �������� ��
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "������ ���� ���� C:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "Ư���� ������ ǥ��:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;
	return 0;
}
*/


/*
// 17��
#include<iostream>
#include<set>
using namespace std;
template <typename T>
void print_list(const T& container);

int main()
{
	set<int> my_set;
	multiset<int> my_multiset; // �ߺ����

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
// 18��
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
		cout << "�� " << *pos << "�� �߰ߵǾ���" << endl;
	else
		cout << "���� �߰ߵ��� �ʾ���" << endl;
	return 0;
}

// ������  �� 2�� �߰ߵǾ���
*/

/*
// 19��
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<string, string> dic;
	dic["boy"] = "�ҳ�";
	dic["school"] = "�б�";
	dic["office"] = "����";
	dic["house"] = "��";
	dic["morning"] = "��ħ";
	dic["evening"] = "����";

	cout << "house�� �ǹ̴� " << dic["house"] << endl;    // ����� �� �ܾ�
	cout << "morning�� �ǹ̴� " << dic["morning"] << endl;   // ����� �� �ܾ�
	cout << "unknown�� �ǹ̴� " << dic["unknown"] << endl;    // ����� �ȵ� �ܾ�
	return 0;
}
*/

/*
// 20��
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

	codes.insert(Pair(415, "�������ý���")); // .insert(pair<const int, string>(415, "�������ý���"));
	codes.insert(Pair(510, "��Ŭ����"));
	codes.insert(Pair(718, "���Ŭ��"));
	codes.insert(Pair(718, "���µ� ��"));
	codes.insert(Pair(415, "�����Ŀ�"));
	codes.insert(Pair(510, "��Ŭ��"));

	cout << "���� �ڵ尡 415�� ���� ��: "
		<< codes.count(415) << endl;
	cout << "���� �ڵ尡 718�� ���� ��: "
		<< codes.count(718) << endl;
	cout << "���� �ڵ尡 510�� ���� ��: "
		<< codes.count(510) << endl;
	cout << "���� �ڵ�  ����\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << "   " << (*it).first << "   "
		<< (*it).second << endl;

	pair<MapCode::iterator, MapCode::iterator> range
		= codes.equal_range(718);
	cout << "���� �ڵ尡 718�� ���õ�:\n";
	for (it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;

	return 0;
}
*/

/*
// 21��
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
		cout << st.top() << endl;  // ������ ������ - top������ ���� �� ���
		st.pop();  // top������ ���� (������ �ǰ� ����� �ȵ� - FILO)
	}
	return 0;
}
*/

/*
// 22��
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
		cout << qu.front() << endl;   // ������ ������ ��� - front������
		qu.pop();  // front������ ����  (FIFO - �տ������� ����)
	}
	return 0;
}
*/

/*
// 23��
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
// 24��
#include<iostream>
#include<deque>

using namespace std;

int main() {
	deque<int> dq;

	for (int i = 0; i < 5; i++)
		dq.push_back((i + 1) * 10);

	//iterator ����
	deque<int>::iterator iter;

	//[default ���]
	cout << "[Default] : ";
	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	//[test1] : �� �� ����
	cout << "[Test1] push_front & end : ";

	dq.push_front(1);
	dq.push_front(2);
	dq.push_back(100);
	dq.push_back(200);

	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	//[test2] : ������ ���
	cout << "[Test2] reverse_iterator : ";

	deque<int>::reverse_iterator riter;

	for (riter = dq.rbegin(); riter != dq.rend(); riter++)
		cout << *riter << " ";
	cout << endl;

	return 0;
}
*/




// ����Ǯ�� 23������

/*
// 1��
#include<iostream>
#include<vector>
#include<random>
using namespace std;

int main()
{
	vector<int> vec;
	random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	mt19937 gen(rd());

	// 1���� 100 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
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
// 2��
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> v;
	string name;
	cout << "�̸�5���� �Է��ϼ���\n";
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
	cout << "�������� ���� �ڿ� ������ �̸��� " << max << endl;
}
*/

/*
// 3��
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
// 4��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int num;
	cout << "5���� ������ �Է� �ϼ��� >> ";
	for (int i = 0; i < 5; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << "���� �� : ";
	for (int i = 0; i < 5; i++)
		cout << v[i] << " ";
	cout << endl;
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
	vector<double> score;
	double s, sum = 0;
	for (int i = 0; i < 10; i++) {
		cout << "������ �Է��ϼ��� : ";
		cin >> s;
		score.push_back(s);
	}
	// �������� �ְ����� �հ迡�� �����ϱ� ���� sort�� �� ù���� �� �� ��꿡�� ����
	sort(score.begin(), score.end());
	
	vector<double>::iterator it;
	it = score.begin() + 1;
	while (it != score.end() - 1) {
		sum += *it;
		it++;
	}
	cout << "�������� : " << sum << endl;
}
*/


/*
// 6��
// map���� ����
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
		cout << "\n1. �ܾ��߰�  2. �ܾ�˻�  3. �ܾ����  4. ����\n";
		cin >> a;
		if (a == 4) { cout << "������ ����Ǿ����ϴ�.\n"; break; }
		else if (a == 1) {
			cout << "�ܾ��Է� : ";
			cin >> word;
			cin.get();
			cout << "�� �Է� : ";
			getline(cin, meaning);
			//dictionary[word] = meaning;
			dictionary.insert(pair<string, string>(word, meaning));
		}
		else if (a == 2) {
			cout << "�ܾ��Է� : ";
			cin >> word;
			cout << word << "�� �� : " << dictionary[word] << endl;
		}
		else if (a == 3) {
			cout << "������ �ܾ��Է� : ";
			cin >> word;
			dictionary.erase(word);
			cout << word << "�ܾ �������� �����Ǿ����ϴ�\n";
		}
		else { cout << "������ ����Ǿ����ϴ�.\n"; break; }
	}
}
*/


/*
// 7��
// list�� ����Ͽ� �ۼ��Ͻÿ�.
#include<iostream>
#include<list>
#include<string>
using namespace std;
class Student {
private:
	string name;     // �л��̸�
	string address;  // �ּ�
	int num;	     // �й�
	string tell;     // ��ȭ��ȣ
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
		cout << "\n1. �߰�  2. �˻�  3. ����  4. ����\n";
		cout << "=> ";
		cin >> a;
		if (a == 4) { cout << "����Ǿ����ϴ�.\n"; break; }
		else if (a == 1) {
			cout << "�л��̸� : ";  cin >> name;
			cout << "�� �� : ";  cin >> address;
			cout << "�� �� : ";  cin >> num;
			cout << "��ȭ��ȣ : ";  cin >> tell;
			tmp.set(name, address, num, tell);
			student.push_back(tmp);
		}
		else if (a == 2) {
			cout << "�л��̸� : ";
			cin >> name;
			it = student.begin();
			while (it != student.end()) {
				if ((*it).get_name() == name) {
					cout << "\n=== �˻���� ===\n";
					cout << "�л��̸� : " << (*it).get_name() << endl;
					cout << "�� �� : " << (*it).get_address() << endl;
					cout << "�� �� : " << (*it).get_num() << endl;
					cout << "��ȭ��ȣ : " << (*it).get_tell() << endl;
					break;
				}
				it++;
			}
			if (it == student.end()) cout << "�˻��� �����Ͽ����ϴ�. ��ϵ��� ���� �л��Դϴ�.\n";
		}
		else if (a == 3) {
			cout << "�л��̸� : ";
			cin >> name;
			it = student.begin();
			while (it != student.end()) {
				if ((*it).get_name() == name) {
					student.erase(it);
					cout << name << " �л� ������ �����Ǿ����ϴ�." << endl;
					break;
				}
				else it++;
			}
		}
		else{ cout << "����Ǿ����ϴ�.\n"; break; }
	}
}
*/




/*
// 8�� - ���� - �̷��� �Ź� while�� ������ 2,3,5,7�� ��� ���ε��� �����ϴ� ��� ���� �� �����ϰ� �ѹ��� �� �� �ִ� ����� ������?
// ����. �̷��� ������ ������ �̷��� ����� ��. �������� ���ϴ� ����� �� �����. �°� �Ѱ���.
// list ���
#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> prime;
	list<int>::iterator it;
	// 2~100 ���� ����
	for (int i = 2; i < 101; i++) {
		prime.push_back(i);
	}


	// 2�� ��� ����
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it)!=2 && (*it) % 2 == 0) {
			it = prime.erase(it); 
		}
		else it++;
	}
	// 3�� ��� ����
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it) != 3 && (*it) % 3 == 0) {
			it = prime.erase(it);
		}
		else it++;
	}
	// 5�� ��� ����
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it) != 5 && (*it) % 5 == 0) {
			it = prime.erase(it);
		}
		else it++;
	}
	// 7�� ��� ����
	it = prime.begin();
	while (it != prime.end()) {
		if ((*it) != 7 && (*it) % 7 == 0) {
			it = prime.erase(it);
		}
		else it++;
	}

	cout << "== �������׳׽� ü �˰��� ������ ==\n";
	it = prime.begin();
	while (it != prime.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;
}
*/


/*
// 9��
// set�� ����Ͻÿ�
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
	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());

	// 1 ���� 45 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> dis(1, 45);

	cout << "�ζ� ��ȣ �߻���\n";
	for (int i = 0; i < 6; i++) {
		r = dis(gen);
		if (lotto.find(r) == lotto.end()) lotto.insert(r);
		else i--;
	}
	cout << "�ζǹ�ȣ : ";
	it = lotto.begin();
	while (it != lotto.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << endl;
}
*/

/*
// 10��
// vector�� ����Ͻÿ�
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
		cout << "\n=== �޴� ===\n";
		cout << "1. �Է�\n" << "2. �˻�\n" << "3. ����\n";
		cout << "=> ";
		cin >> a;
		if (a == 3) { cout << "����Ǿ����ϴ�.\n"; break; }
		else if (a == 1) {
			cout << "�⵵ : ";  cin >> year;
			cout << "å�̸� : ";  cin >> name;
			cout << "���� : ";  cin >> author;
			tmp.set(year, name, author);
			v.push_back(tmp);
			cout << "å�� �԰�Ǿ����ϴ�!\n";
		}
		else if (a == 2) {
			cout << "�����̸� : ";  cin >> name;
			cout << "�⵵ : ";  cin >> year;
			it = v.begin();
			while (it != v.end()) {
				if ((*it).get_author() == name && (*it).get_year() == year) {
					cout << (*it).get_name() << "  " << (*it).get_author() << "  " << (*it).get_year() << endl;
					break;
				}
				it++;
			}
			if (it == v.end()) cout << "�˻��Ͻ� ����� ã�� �� �����ϴ�.\n";
		}
		else { cout << "����Ǿ����ϴ�.\n"; break; }
	}
}
*/

/*
// 11��
// vector�� ����Ͻÿ�
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
		cout << "\n1. ����\n2. ����\n3. ��κ���\n4. ����\n";
		cout << "==> ";
		cin >> a;
		if (a == 4) { cout << "����Ǿ����ϴ�\n"; break; }
		else if (a == 1) {
			cout << "���� ������ : ";  cin >> r;
			cout << "���� �̸� : ";  cin >> name;
			tmp.set(r, name);
			c.push_back(tmp);
			cout << endl;
		}
		else if (a == 2) {
			cout << "���� �̸� : ";  cin >> name;
			it = c.begin();
			while (it != c.end()) {
				if ((*it).get_name() == name) {
					it = c.erase(it);
					cout << "�����Ǿ����ϴ�!\n";
				}
				else it++;
			}
		}
		else if (a == 3) {
			int i = 0;
			it = c.begin();
			cout << "\n== �� ��ü���� ==\n";
			while (it != c.end()) {
				i++;
				cout << "[ " << i << " ] "<< "���� �̸� : " << (*it).get_name() << "  ������ : " << (*it).get_radius() << endl;
				it++;
			}
			cout << endl;
		}
		else { cout << "����Ǿ����ϴ�\n"; break; }
	}
}
*/

/*
// 12�� - ���͸� ����Ͽ� ����
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

	cout << "** ���� �ּ� ���α׷� **\n";
	for (;;) {
		cout << "\n���̸� : ";  cin >> name;
		cout << "������ �Է��ϼ���(f or m) : ";  cin >> gender;
		if (gender == 'm') { 
			if (!female.empty()) {
				cout << "Ŀ���� ź���߽��ϴ�! " << name << "�� " << female[0] << endl;
				female.erase(female.begin());
			}
			else {
				man.push_back(name);
				cout << "���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n";
			}
		}
		else if (gender == 'f') {
			female.push_back(name);
			if (!man.empty()) {
				cout << "Ŀ���� ź���߽��ϴ�! " << man[0] << "�� " << female[0] << endl;
				female.erase(female.begin());
				man.erase(man.begin());
			}
		}
		else cout << "������ �ٽ� �Է��ϼ���\n";
	}
}
*/

/*
// 12�� - ť�� ����Ͽ� ����
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

	cout << "** ���� �ּ� ���α׷� **\n";
	for (;;) {
		cout << "\n���̸� : ";  cin >> name;
		cout << "������ �Է��ϼ���(f or m) : ";  cin >> gender;
		if (gender == 'm') {
			if (!female.empty()) {
				cout << "Ŀ���� ź���߽��ϴ�! " << name << "�� " << female.front() << endl;
				female.pop();
			}
			else {
				man.push(name);
				cout << "���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n";
			}
		}
		else if (gender == 'f') {
			female.push(name);
			if (!man.empty()) {
				cout << "Ŀ���� ź���߽��ϴ�! " << man.front() << "�� " << female.front() << endl;
				female.pop();
				man.pop();
			}
		}
		else cout << "������ �ٽ� �Է��ϼ���\n";
	}
}
*/


/*
// 12�� - deque�� ����Ͽ� ���� (+��� ���� ��� �߰�)
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

	cout << "** ���� �ּ� ���α׷� **\n";
	for (;;) {
		cout << "\n���̸� : ";  cin >> name;
		cout << "������ �Է��ϼ���(f or m) : ";  cin >> gender;
		cout << "��� ������ ���Ͻʴϱ�?(y/n) : ";  cin >> instant;
		if (gender == 'm') {
			if (instant == 'y') man.push_front(name);
			else man.push_back(name);
			if (!female.empty()) {
				cout << "Ŀ���� ź���߽��ϴ�! " << man.front() << "�� " << female.front() << endl;
				female.pop_front();
				man.pop_front();
			}
			else cout << "���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n";
		}
		else if (gender == 'f') {
			if (instant == 'y') female.push_front(name);
			else female.push_back(name);
			if (!man.empty()) {
				cout << "Ŀ���� ź���߽��ϴ�! " << man.front() << "�� " << female.front() << endl;
				female.pop_front();
				man.pop_front();
			}
		}
		else cout << "������ �ٽ� �Է��ϼ���\n";
	}
}

// �� �۵��ϴµ� �̷� ������ �߻���

// ȫ�浿�� ���� �ͼ� ��� ���� ���߰�
// �״����� �̼����� �ͼ� �̼��ŵ� ��� ���� ���ߴٰ� ����,
// ���� �Ѹ��� ���� ȫ�浿�� ���� �ּ��Ǵ°� �´µ� �� �ڵ��� �ϸ� �̼����� ���� �ּ���. 
// ȫ�浿, �̼��� ��� push_front�� �߱� ������

// => ��� �� �� ����. ��¿ �� ����. push_front�� ��� ������

*/