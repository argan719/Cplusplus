/*
// 1번
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char name[10], dept[20];
	int sid;
	cout << "이름>>";
	cin >> name;
	cout << "학번(숫자로)>>";
	cin >> sid;
	cout << "학과>>";
	cin >> dept;
	ofstream fout("c:\\temp\\student.txt");
	if (!fout) {
		cout << "student.txt 파일을 열 수 없다.";
		return 0;
	}
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;
	fout.close();
}
*/
/*
// 2번
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fin;
	fin.open("c:\\temp\\student.txt");
	if (!fin) {
		cout << "파일을 열 수 없다";
		return 0;
	}
	char name[10], dept[20];
	int sid;
	fin >> name;
	fin >> sid;
	fin >> dept;
	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;
	fin.close();
}
*/


/*
// 3번
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char* file = "c:\\windows\\system.ini";
	ifstream fin(file);
	if (!fin) {
		cout << file << " 열기 오류" << endl;
		return 0;
	}
	int count = 0;
	int c;
	while ((c = fin.get()) != EOF) {
		cout << (char)c;
		count++;
	}

	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();
}
*/


/*
// 4번
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char* firstFile = "c:\\temp\\student.txt";
	char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);	// 쓰기 모드로 파일 열기
	if (!fout) {
		cout << firstFile << " 열기 오류";
		return 0;
	}
	fstream fin(secondFile, ios::in);  // 읽기 모드로 파일 열기
	if (!fin) {
		cout << secondFile << " 열기 오류";
		return 0;
	}
	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c);
	}
	fin.close();
	fout.close();
}
*/

/*
// 5번
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "c:\\windows\\system.ini 열기 실패" << endl;
		return 0;
	}
	char buf[81];  // 한 라인이 최대 80개의 문자로 구성된다고 가정
	while (true) {
		fin.getline(buf, 81);  // 한 라인이 최대 80개의 문자로 구성
		if (fin.eof()) break;
		cout << buf << endl;
	}
	fin.close();
}
*/

/*
// 6번
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void fileRead(vector<string> &v, ifstream &fin) {
	string line;
	while (true) {
		getline(fin, line);
		if (fin.eof()) break;
		v.push_back(line);
	}
}
void search(vector<string> & v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);
		if (index != -1)
			cout << v[i] << endl;
	}
}
int main()
{
	vector<string> wordVector;
	ifstream fin("c:\\temp\\words.txt");
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다" << endl;
		return 0;
	}
	fileRead(wordVector, fin);
	fin.close();
	cout << "words.txt 파일을 읽었습니다." << endl;
	while (true) {
		cout << "검색할 단어를 입력하세요 >>";
		string word;
		getline(cin, word);
		if (word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "프로그램을 종료합니다." << endl;
}
*/

/*
// 7번
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char* srcFile = "c:\\temp\\apple.jpg";
	char* destFile = "c:\\temp\\copyapple.jpg";
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " 열기 오류" << endl;
		return 0;
	}
	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " 열기 오류" << endl;
		return 0;
	}

	int c;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
}
*/

/*
// 8번
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char *file = "c:\\temp\\words.txt";
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if (!fin) {
		cout << "파일 열기 오류";
		return 0;
	}
	int count = 0;
	char s[32];
	while (!fin.eof()) {
		fin.read(s, 32);
		int n = fin.gcount();
		cout.write(s, n);
		count += n;
	}
	cout << endl << "읽은 바이트 수는 " << count << endl;
	fin.close();
}
*/

/*
// 9번
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char* srcFile = "c:\\data\\apple.jpg";
	char* destFile = "c:\\data\\apple2.jpg";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " 열기 오류" << endl;
		return 0;
	}
	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " 열기 오류" << endl;
		return 0;
	}
	char buf[1024];
	while (!fsrc.eof()) {
		fsrc.read(buf, 1024);
		int n = fsrc.gcount();
		fdest.write(buf, n);
	}
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
}
*/


/*
// 10번
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char *file = "c:\\Temp\\data.dat";
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if (!fout) {
		cout << "파일 열기 오류";
		return 0;
	}
	int n[] = { 0,1,2,3,4,5,6,7,8,9 };
	double d = 3.15;
	fout.write((char*)n, sizeof(n));
	fout.write((char*)(&d), sizeof(d));
	fout.close();
	ifstream fin(file, ios::in);
	if (!fin) {
		cout << "파일 열기 오류";
		return 0;
	}

	fin.read((char*)n, sizeof(n));
	fin.read((char*)(&d), sizeof(d));

	for (int i = 0; i < 10; i++)
		cout << n[i] << ' ';
	cout << endl << d << endl;
	fin.close();
}
*/

/*
// 11번
#include<iostream>
#include<fstream>
using namespace std;

void showStreamState(ios & stream) {
	cout << "eof() " << stream.eof() << endl;
	cout << "fail() " << stream.fail() << endl;
	cout << "bad() " << stream.bad() << endl;
	cout << "good() " << stream.good() << endl;
}

int main()
{
	char* noExistFile = "noexist.txt";  // 존재하지 않는 파일명
	char* existFile = "c:\\Temp\\student.txt";  // 존재하는 파일명

	ifstream fin(noExistFile);  // 존재하지 않는 파일 열기
	if (!fin) {  // 열기 실패 검사
		cout << noExistFile << " 열기 오류" << endl;
		showStreamState(fin);  // 스트림 상태 출력
		cout << existFile << " 파일 열기" << endl;
		fin.open(existFile);
		showStreamState(fin);  // 스트림 상태 출력
		cout << endl;
	}

	// 스트림을 끝까지 읽고 화면에 출력
	int c;
	while ((c = fin.get()) != EOF)
		cout.put((char)c);

	cout << endl << endl;
	showStreamState(fin);  // 스트림 출력

	fin.close();
}
*/




/*
// 12번 
#include<iostream>
#include<fstream>
using namespace std;

const int SIZE = 1000;
void init_table(int table[], int size);

int main()
{
	int table[SIZE];
	int data;
	long pos;

	init_table(table, SIZE);

	// 이진 파일을 쓰기 모드로 연다.
	ofstream os;
	os.open("c:\\Temp\\test.dat", ofstream::binary);
	if (os.fail()) {
		cout << "test.dat 파일을 열 수 없습니다." << endl;
		exit(1);
	}

	os.write((char*)table, sizeof(table));
	os.close();

	ifstream is;
	is.open("c:\\Temp\\test.dat", ofstream::binary);
	if (is.fail()) {
		cout << "test.dat 파일을 열 수 없습니다." << endl;
		exit(1);
	}

	while (1) {
		cout << "파일에서의 위치를 입력하십시요 (0에서 999, 종료-1): ";
		cin >> pos;
		if (pos = -1) break;
		is.seekg(ios::beg + pos * sizeof(int));
		is.read((char *)&data, sizeof(int));
		cout << pos << " 위치의 값은" << data << " 입니다." << endl;
	}
	is.close();
	return 0;
}
// 배열을 인덱스의 제곱으로 채운다
void init_table(int table[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		table[i] = i * i;
}

*/


/*
// 13번 - 시저-암호

#include<iostream>
#include<fstream>
using namespace std;		 // 파일 이름 두개 명령어 라인으로 입력받음
int main(int argc, char *argv[])   // Ex) C > Cipher input.txt  output.txt
{
	if (argc != 3)
	{
		cout << "잘못 입력하셨습니다." << endl;
		exit(1);
	}
	ifstream is;
	is.open(argv[1]);
	ofstream os;
	os.open(argv[2]);
	char c;
	char tmp;
	while (!is.eof())
	{
		is.get(c);
		if (c != ' ')
			tmp = c - 29;
		else
			tmp = c;
		os << tmp;
	}
	cout << "시저 암호로 암호화하였습니다." << endl;
	is.close();		os.close();
	return 0;
}
*/





/*
// 문제풀이 12페이지
// 1번
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("c:\\Temp\\test.txt");
	if (!fin) {
		cout << "파일을 열 수 없음" << endl;
		return 0;
	}
	string s1, s2;
	getline(fin, s1);
	getline(fin, s2);
	
	cout << s1 << endl << s2 << endl;
	
	fin.close();
}
*/

/*
// 2번
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("c:\\Temp\\test.txt");
	if (!fin) {
		cout << "파일을 열 수 없음" << endl;
		return 0;
	}
	string s1;
	getline(fin, s1);
	for (int i = 0; i < s1.length(); i++)
		s1[i] = toupper(s1[i]);
	cout << s1 << endl;
}
*/

/*
// 3번
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int SIZE = 100;

int main()
{
	int arr[SIZE];
	string a;
	int i, tmp;
	int size = 0;

	ifstream fin;
	fin.open("c:\\Temp\\test.txt");
	if (!fin) {
		cout << "파일을 열 수 없음" << endl;
		return 0;
	}
	for (i = 0; ; i++)
	{
		if (fin.eof()) break;
		fin >> arr[i];
		size++;
	}

	for (i = 0; i < size-1; i++) {
		for(int k=i;k<size; k++)
			if (arr[i] > arr[k]) {
				tmp = arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
			}
	}
	ofstream fout("c:\\Temp\\test.txt");

	for (int i = 0; i < size; i++)
	{
		fout << arr[i] << endl;
	}

	fin.close();
	fout.close();

}
*/




/*
// 5번
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 100;

typedef struct A {
	int n;
	string name;
	string tell;
	string mail;
}Person;

int main()
{
	int a, i;
	char c;
	Person person[MAX];
	Person tmp;
	char *filename = "c:\\Temp\\person.txt";

	ifstream fin;
	fstream fout(filename, ios::out | ios::app);	// 쓰기 모드로 파일 열기
	if (!fout) {
		cout << filename << " 열기 오류";
		return 0;
	}

	for (i=0;;) {
		cout << "번호를 입력하세요 : ";
		cin >> tmp.n;
		cout << "이름을 입력하세요 : ";
		cin >> tmp.name;
		cout << "전화번호를 입력하세요 : ";
		cin >> tmp.tell;
		cout << "메일주소를 입력하세요 : ";
		cin >> tmp.mail;

		fout << tmp.n << " " << tmp.name << " " << tmp.tell << " " << tmp.mail << endl;
		 
		i++;
		cout << "계속 (y/n) : ";
		cin >> c;
		if (c == 'y') continue;
		else break;
	}

	cout << endl << "검색번호 : ";
	cin >> a;
	
	fin.open(filename);
	for (int k=0;k<i;k++) {
		if (fin.eof()) break;
		fin >> person[k].n;
		fin >> person[k].name;
		fin >> person[k].tell;
		fin >> person[k].mail;
	}
	
	for (int k = 0; k < i; k++) {
		if (person[k].n == a) cout << person[k].n << "  " << person[k].name << "  " << person[k].tell << "  " << person[k].mail << endl;
	}
}
*/


/*
// 6번
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 100;

int main()
{
	string fruit[MAX];
	string find;
	ifstream fin;
	fin.open("c:\\Temp\\input.txt");
	if (!fin) {
		cout << "파일 열수 없음";
		return 0;
	}

	cout << "찾을 과일 이름을 입력하세요 : ";
	cin >> find;

	for (int i=0;;i++) {
		if (fin.eof()) {
			cout << "해당 과일을 찾을 수 없습니다.\n"; break;
		}
		getline(fin, fruit[i]);
		if (fruit[i] == find) {
			cout << "input.txt : " << (i + 1) << " " << fruit[i] << endl;
			break;
		}
	}
}
*/

/*
// 7번
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
const int MAX = 100;

int main()
{
	string fruit[MAX];
	ifstream fin;
	fin.open("c:\\Temp\\input.txt");
	if (!fin) {
		cout << "파일 열수 없음";
		return 0;
	}

	for (int i = 0;; i++) {
		if (fin.eof()) break;
		getline(fin, fruit[i]);
		cout << setw(6) << right << (i + 1) << ": " << fruit[i] << endl;
	}
	fin.close();
}
*/


/*
// 8번   
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	int charnum = 0, wordnum = 0, linenum;
	string word;
	ifstream fin;
	fin.open("c:\\Temp\\text.txt");
	if (!fin) {
		cout << "파일을 열 수 없음.";
		return 0;
	}
	 
	// getline으로 한문장씩 받아서 - 문장이 가장 큰 단위니까
	// 한문장을 분해해서 문자, 단어수 count
	for (linenum=0;;linenum++) {
		getline(fin, word);
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == 32) wordnum++;
			charnum++;
		}
		wordnum++;
		if (fin.eof()) break;
	}

	wordnum = wordnum - (linenum - 1);
	
	cout << "문자수 : " << charnum << endl;
	cout << "단어수 : " << wordnum << endl;
	cout << "문장수 : " << linenum << endl;

	fin.close();
}
*/





/*
// 명령어 라인 쓰는 방법 - 중요 notion에 필기
#include<iostream>
#include<fstream>
using namespace std;

int main(int n, char *arr[])
{
	cout << "입력자료 ";

	cout <<"개수 :"<< n<<"  "<< arr[0]<<"  "<< arr[1];
	cin.get();
	cin.get();
}
*/



/*
// 9번  
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int n, char *argv[])
{

	char *filename1 = argv[1];
	char *filename2 = argv[2];
	char *newfile = argv[3];

	char w;

	ifstream fin(filename1);
	ofstream fout(newfile, ios::out | ios::app);
	for (;;) {
		if (fin.eof()) break;
		fin.get(w);
		fout << w;
	}
	fin.close();
	 
	
	fin.open(filename2);
	for (;;) {
		if (fin.eof()) break;
		fin.get(w);
		fout << w;
	}
	fin.close();
	
}
*/


/*
// 10번 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int n, char *argv[]) {
	char *filename1 = argv[1];
	char *filename2 = argv[2];

	ifstream fin1(filename1);
	ifstream fin2(filename2);
	for (;;) {
		if (fin1.eof()) break;
		else if (fin2.eof()) break;
		if (fin1.get() != fin2.get()) {
			cout << "두개의 파일은 다릅니다.\n"; exit(1);
		}
	}
	cout << "두개의 파일은 일치합니다.\n";

	fin1.close();
	fin2.close();
}
*/




/*
// 11번
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char* filename1 = "c:\\Temp\\Red_Apple1.jpg";
	char* filename2 = "c:\\Temp\\Red_Apple2.jpg";
	fstream image1(filename1, ios::in | ios::binary);
	fstream image2(filename2, ios::in | ios::binary);

	for (;;) {
		if (image1.eof()) break;
		else if (image2.eof()) break;

		if (image1.get() != image2.get()) {
			cout << "두 이미지 파일은 다릅니다." << endl;
			return 0;
		}
	}
	cout << "두 이미지 파일은 같습니다." << endl;

	image1.close();
	image2.close();
}
*/









/*
// 12번 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> word;
	ifstream fin("c:\\Temp\\word.txt");
	if (!fin) { cout << "파일 열 수 없음.\n"; return 0; }

	string search;
	string line;      
	while (1) {
		fin >> line;
		word.push_back(line);
		if (fin.eof()) break;               
	}
	fin.close();
	cout << "words.txt 파일 로딩 완료" << endl;
	cout << "검색을 시작합니다. 단어를 입력해주세요." << endl;
	cout << "단어 : ";
	cin >> search;

	
	int flag;
	for (int i = 0; i < word.size(); i++) {
		// 한 글자만 다른 단어 찾기 
		flag = 0;
		if (search == word[i]) {}
		else {
			for (int k = 0; k < search.length(); k++) {
				if (search[k] != word[i][k]) flag++;
				if (flag > 1) break;
			}
			if (flag == 1) cout << word[i] << endl;
		}
	}
	
}
*/

/*
// 13번
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

typedef struct Person {
	string name;
	string tell;
}p;

int main()
{
	int num, i;
	p tmp;
	vector<p> person;
	ifstream fin("c:\\Temp\\person.txt");
	while (1) {
		fin >> tmp.name;
		fin >> tmp.tell;
		person.push_back(tmp);
		if (fin.eof()) break;
	}
	fin.close();
	cout << "person.txt 파일 로딩 완료" << endl;

	for (;;) {
		cout << "=== 메뉴\n";
		cout << "1. 연락처 추가\n";
		cout << "2. 연락처 탐색\n";
		cout << "3. 연락처 변경\n";
		cout << "4. 연락처 삭제\n";
		cout << "5. 종료\n";
		cout << "번호를 선택하세요: ";
		cin >> num;
		if (num == 5) break;
		switch (num) {
		case 1: {
			cout << "이름을 입력하세요 : ";
			cin >> tmp.name;
			cout << "번호를 입력하세요 : ";
			cin >> tmp.tell;
			person.push_back(tmp);
		} break;
		case 2: {
			cout << "검색할 회원의 이름을 입력하세요 : ";
			cin >> tmp.name;
			for (i = 0; i < person.size(); i++) {
				if (tmp.name == person[i].name) {
					cout << "번호는 " << person[i].tell << "입니다.\n"; break;
				}
			}
			if (i == person.size()) cout << "해당 회원을 찾을 수 없습니다.\n";
		} break;
		case 3: {
			cout << "연락처를 변경할 회원의 이름을 입력하세요 : ";
			cin >> tmp.name;
			for (i = 0; i < person.size(); i++) {
				if (tmp.name == person[i].name) {
					cout << "새로 변경할 연락처를 입력하세요 : ";
					cin >> tmp.tell;
					person[i].tell = tmp.tell;
					cout << "변경되었습니다.\n";
				}
			}
		} break;
		case 4: {
			cout << "삭제할 회원의 이름을 입력하세요 : ";
			cin >> tmp.name;
			for (i = 0; i < person.size(); i++) {
				if (tmp.name == person[i].name) {
					person.erase(person.begin() + i);
					cout << "삭제되었습니다.\n";
				}
			}
		} break;
		default: break;
		}
	}

	ofstream fout("c:\\Temp\\person.txt");
	for (int k = 0; k < person.size(); k++) {
		fout << person[k].name << " " << person[k].tell << endl;
	}

	fout.close();
}
*/


/*
// 14번 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	char w;
	string line;
	ifstream fin("c:\\Temp\\test.txt");
	for (;;) {
		if (fin.eof()) break;
		getline(fin, line);
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != '"' && line[i + 1] == '/' && line[i + 2] == '/') break;
			else cout << line[i];
		}
		cout << endl;
	}
}
*/




/*
// 15번 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin("c:\\windows\\system.ini");
	string line;
	char c;
	int words = 0;  // 총 문자수
	// 총 문자수 count
	for (;;) {
		if (fin.eof()) break;   // eof라는건 파일 맨 끝에 커서가 가 있는게 아니라 null만나서 아예 파일 밖으로 나간거임
		getline(fin, line);          // 한번 eof를 만났으면 seekg로 커서를 이동 못시키는 거임. 이미 파일 밖으로 나갔기 때문에
		words += line.length() - 1;     // 이럴 때는 그냥 파일 close했다가 다시 open 해서 하면 됨 
	}
	fin.close();

	fin.open("c:\\windows\\system.ini");

	int percent = 0;
	int tenpercent = words * 0.1;
	ofstream fout("c:\\Temp\\system.txt");
	for (int i = 0;;) {
		if (fin.eof()) break;
		fin.get(c);
		fout.put(c);
		i++;
		if (i % tenpercent == 0) {
			percent++;
			cout << "." << tenpercent << "B " << percent * 10 << "%\n";
		}
	}
	cout << words << "B 복사 완료\n";
	
	fin.close();
	fout.close();
}
*/




/*
// 16번               // 메모장 utf문제 ( input.txt 파일 utf-16으로 되어 있는걸 utf-8로 바꿔야 함)
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	char str[] = "Blessed is he who has found his work;let him ask no other blessedness";
	
	ofstream fout("c:\\Temp\\input.txt"); 
	for (int i = (sizeof(str) / sizeof(str[0]))-1; 0 <= i; i--) {
		fout << str[i];
	}
	fout.close();

	string reverse;
	ifstream fin("c:\\Temp\\input.txt");
	getline(fin, reverse);
	cout << reverse;
	fin.close();
}
*/




/*
// 17번
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) { return 0; }
	string line;

	for (int i = 1;; i++) {
		if (fin.eof()) break;
		getline(fin, line);
		cout << i << " : " << line << endl;
	}

	fin.close();
}
*/

/*
// 18번
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) { return 0; }
	string line[100];
	string tmp;
	int n;

	for(int i = 0;; i++) {
		if (fin.eof()) break;
		getline(fin, tmp);
		line[i] = tmp;
	}
	fin.close();

	cout << "c:\\windows\\system.ini 파일 읽기 완료\n";
	cout << "라인 번호를 입력하세요. 1보다 작은 값을 입력하면 종료\n";
	for (;;) {
		cout << ": ";
		cin >> n;
		if (n < 1) { cout << "종료합니다.\n"; break; }
		cout << line[n - 1] << endl;
	}
}
*/


/*
// 19번 - 행맨 게임
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<vector>
using namespace std;

int main()
{
	vector<string> v;
	ifstream fin("c:\\Temp\\words.txt");
	string line, answer;
	string next = "";
	char a;
	int cnt = 0;
	int r;
	while (!fin.eof()) {
		getline(fin, line);
		v.push_back(line);
		cnt++;
	}
	cout << "vector에 로딩 완료..";
	fin.close();

	srand(time(NULL));

	cout << "행맨 게임을 시작합니다.. (힌트:과일)\n";
	r = rand() % cnt;
	answer = v[r];
	for (int i = 0; i < answer.length(); i++) {
		next += "_";
	}
	for (int k = 0; k < next.length(); k++) {
		cout << next[k] << " ";
	}
	cout << endl;
	for (;;) {
		cout << "\n알파벳을 입력하세요 : ";
		cin >> a;
		for (int i = 0; i < answer.length(); i++) {
			if (answer[i] == a) { next[i] = answer[i]; }
		}
		for (int k = 0; k < next.length(); k++) {
			cout << next[k] << " ";
		}
		if (next == answer) {
			cout << "정답을 맞췄습니다! 게임종료\n"; break;
		}
	}

}
*/




/*
// 20번
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> v;
	string word;
	ifstream fin("c:\\Temp\\words.txt");
	if (!fin) { return 0; }

	for (;;) {
		if (fin.eof()) break;
		fin >> word;
		v.push_back(word);
	}
	cout << "... words.txt 파일 로딩 완료\n";
	cout << "검색을 시작합니다. 단어를 입력해주세요.\n";

	int i, k;
	for (;;) {
		cout << "단어>> ";
		cin >> word;
		if (word == "exit") { cout << "종료되었습니다.\n"; break; }
		for (i = 0; i < v.size(); i++) {
			for (k = 0; k < word.length(); k++)
			{
				if (word[k] != v[i][k]) break;
			}
			if (k == word.length()) cout << v[i] << endl;
		}
	}

}
*/

/*
// 21번
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	char s[30];
	int byte = 0;
	ifstream fin("c:\\windows\\system.ini");
	while (!fin.eof()) {
		fin.read(s, 30);
		byte += fin.gcount();
		cout << fin.gcount() << endl;
	}

	cout << "c:\\windows\\system.ini 파일의 크기는 " << byte << "바이트\n";
}
*/




/*
// 22번
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
typedef struct p {
	int num;
	int size;
}Table;
int main()
{
	ifstream fin("c:\\Temp\\student.txt");
	ofstream fout("c:\\Temp\\student.txt", ios::app);

	string tmp;
	int num; string name;
	int kor, eng, math;
	int n;
	int cnt = 0;

	int move;

	Table table[100];
	int i;
	for (i=0;;i++) {
		if (fin.eof()) break;
		getline(fin, tmp);
		table[i].num = i + 1;
		table[i].size = tmp.length() + 2;
		cnt++;
	}
	for (int k = 0; k < i; k++)
		cout << table[k].size << endl;



	for (;;) {
		cout << "=== 메뉴\n";
		cout << "1. 성적입력\n";
		cout << "2. 번호검색\n";
		cout << "3. 성적표 출력\n";
		cout << "4. 종료\n";
		cout << "==> ";
		cin >> n;
		if (n == 4) { cout << "종료되었습니다.\n"; break; }
		else if (n == 1) {
			cout << "번호 : ";
			cin >> num;
			cout << "이름 : ";
			cin >> name;
			cout << "국어 영어 수학 : ";
			cin >> kor >> eng >> math;
			fout << num << " " << name << " " << kor << " " << eng << " " << math << endl;
		}
		else if (n == 2) {
			//fin.seekg(ios::beg + 0);
			cout << "검색할 번호를 입력하세요 : ";
			cin >> num;
			if (num > cnt) cout << "out of range\n";
			else {
				move = 0;
				for (int k = 1; k < num; k++) {
					move += table[k - 1].size;
				}
				fin.seekg(ios::beg + move);
				getline(fin, tmp);
				cout << tmp << endl;
			}
		}
		else break;
	}
}
*/

