//#include<iostream>
//int main(void)
//{
//	int num = 20;
//	std::cout << "Hello World!" << std::endl;
//	std::cout << "Hello " << "World!" << std::endl;
//	std::cout << num << ' ' << 'A';
//	std::cout << ' ' << 3.14 << std::endl;
//	return 0;
//}

/*
#include<iostream>
int main(void)
{
	int val1; 
	std::cout << "첫 번째 숫자입력: ";
	std::cin >> val1;
	int val2;
	std::cout << "두 번쨰 숫자입력: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈결과: " << result << std::endl;

	char str[100];
	std::cin >> str;
	std::cout << str << std::endl;
	return 0;
}

#include<iostream>
int main()
{
	char str[80];
	char ch;
	int i = 0;
	std::cout << " 문장을 입력 하세요 :";
	ch = std::cin.get(); //getchar()
	while (ch != '\n')
	{
		str[i] = ch;
		i++;
		ch = std::cin.get();
	}
	str[i] = '\0';
	std::cout << "입력된 문장은 :" << str << std::endl;

	std::cout << "새로운 문장을 입력 하세요 :";
	std::cin.getline(str, sizeof(str)); // 공백을 포함한 문자열 입력 가능 gets()
	std::cout << "새로 입력된 문장은 :" << str << std::endl;
	return 0;
}

*/

/*
#include<iostream>
#include<cctype>
using namespace std;
int main()
{
	char ch;

	cout << "한문자를 입력하십시오. (끝내려면 @)\n";
	cin.get(ch);
	while (ch != '@') {
		if (isalnum(ch))
		{
			if (isdigit(ch))
				;
			else if (islower(ch))
				cout.put(toupper(ch));
			else
				cout.put(tolower(ch));
		}
		else cout.put(ch); //한문자출력 putchar()
		cin.get(ch);
	}
	return 0;
}
*/

/*
#include<iostream>
int main(void)
{
	using namespace std;
	int ch; 
	int count = 0;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}
	cout << count << " 문자를 읽었습니다.\n";
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

int main() {
	cout << "주소를 입력하세요>>";

	char address[100];
	cin.getline(address, 100, '.'); //키보드로부터 주소 읽기

	cout << "주소는 " << address << "입니다\n"; //주소 출력
}
*/

/*
#include<iostream>
#include<string>
const int SIZE = 20;
int main()
{
	using namespace std;
	char firstName[SIZE];
	char lastName[SIZE];
	char fullName[2 * SIZE + 1];

	cout << "퍼스트 네임(이름)을 입력하시오: ";
	cin.getline(firstName, SIZE);
	cout << "라스트 네임(성)을 입력하시오: ";
	cin.getline(lastName, SIZE);
	strncpy(fullName, lastName, SIZE);
	strcat(fullName, ", ");
	strncat(fullName, firstName, SIZE);
	fullName[2 * SIZE] = '\0';
	cout << "하나의 문자열로 만들면: "
		<< fullName << endl;
	return 0;

}
*/



// 4페이지 9번

 /* 필기 해놓기 - Stirng 으로 선언했을 때와 문자 배열로 선언해서 사용할 때의 차이점 */
 //  string            char str[100]
 //무한대길이          정해진길이
 //s="akafkl"          strcpy(s, "afkalkf")
 //s+="111"             strcat(s,"111")
 //s.length              strlen(s)
//getline(cin, str);    cin.getline()

/*
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	char charr[20];
	string str;

	cout << "입력 이전에 charr에 있는 문자열의 길이: "
		<< strlen(charr) << endl;
	cout << "입력 이전에 str에 있는 문자열의 길이: "
		<< str.size() << endl;

	cout << "텍스트 한 행을 입력하시오:\n";
	cin.getline(charr, 20);
	cout << "입력한 텍스트: " << charr << endl;

	cout << "또 다른 텍스트 한 행을 입력하시오:\n";
	getline(cin, str);			// 이제 cin은 길이 지정자가 아니라 매개변수
	cout << "입력한 텍스트: " << str << endl;
	cout << "입력 이후에 charr에 있는 문자열의 길이: "
		<< strlen(charr) << endl;
	cout << "입력 이후에 str에 있는 문자열의 길이: "
		<< str.size() << endl;

	return 0;
}

*/


/*
// 6페이지 12번
#include<iostream>
using namespace std;
#include<iomanip>
#define LINE(n) {int i; for(i=0; i<n; i++) cout << '='; cout << endl;}
int main()
{
	char name[20];
	int kor, eng, mat, tot;
	double avg;

	cout << "이름 입력 : ";
	cin.getline(name, sizeof(name));
	cout << "세 과목의 점수 입력 : ";
	cin >> kor >> eng >> mat;
	tot = kor + eng + mat;
	avg = tot / 3.0;

	cout << setw(40) << "=====< 성적표 >=====" << "\n\n";
	LINE(60);
	cout << setw(10) << "이름" << setw(10) << left << "국어" << setw(10) << "영어"
		<< setw(10) << "수학" << setw(10) <<"총점" << setw(10) << "평균" << endl;
	LINE(60);
	cout << fixed;
	cout << setw(10) << name << setw(10) << kor << setw(10) << eng << setw(10)
		<< mat << setw(10) << tot << setw(10) << setprecision(4) << avg << endl;

	return 0;
}
*/


/*
// 7페이지 13번
#include<iostream>
using namespace std;

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}
int main(void)
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;

	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;

	using namespace ABC;
	cout << num1;
	return 0;
}
*/


/*
#include<iostream>
int main(void)
{
	int num = 20;
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	
}
*/

/*
// 4페이지 8번
#include<iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름을 입력하십시오:\n";
	cin.get(name, ArSize).get();
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin.get(dessert, ArSize).get();
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << "님!\n";
	return 0;
}
*/


/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	string song = "Falling in love with you";
	string elvis("Elvis Presley");
	string singer; //문자열 singer

	cout << song + "를 부른 가수는";
	cout << "(힌트: 첫 글자는 " << elvis[0] <<  ")?";

	getline(cin, singer);	//string 타입의 C++ 문자열을 입력받기 위한 전역함수
	if (singer == elvis)
		cout << "맞았습니다";
	else
		cout << "틀렸습니다" + elvis + "입니다" << endl;
}
*/

/*
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy(charr1, charr2);

	str1 += " paste";
	strcat(charr1, " juice");

	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << str1 << " 문자열에는 " << len1 << "개의 문자가 들어 있다.\n";
	cout << charr1 << " 문자열에는 " << len2 << "개의 문자가 들어 있다.\n";
}
*/







/*
// 8페이지 1번
#include<iostream>
#include<iomanip>
int main()
{
	using namespace std;
	for (int i = 1; i <= 100; i++) {
		cout << left << setw(10) << i;
		if (i % 10 == 0) cout << endl;
	}
}
*/



/*
//2번
#include<iostream>
int main()
{
	using namespace std;
	float num;
	float max;
	cout << "5개의 실수를 입력 하세요 : ";
	cin >> max;
	for (int index = 1; index < 5; index++) {
		cin >> num;
		if (max < num) max = num;
	}
	cout << endl;
	cout << "제일 큰 수 = " << max;
}
*/



/*
//3번
#include<iostream>
const int SIZE = 100;
int main()
{
	using namespace std;
	char str[SIZE];
	int index = 0;
	int sum = 0;
	cout << "100개 미만의 문자들을 입력 하세요 : ";
	cin.getline(str,SIZE);
	while (str[index] != '\0') {
		if (str[index] == 'x') sum++;
		index++;
	}
	cout << "x의 개수는 " << sum << endl;
}
*/




/*
//4번
#include<iostream>
#include<string>
const int SIZE = 100;
int main()
{
	using namespace std;
	char ch1[SIZE];
	char ch2[SIZE];
	
	cout << "암호를 입력하세요 : ";
	cin.getline(ch1, SIZE);
	cout << "암호를 다시 한번 입력하세요 : ";
	cin.getline(ch2, SIZE);
	if (strcmp(ch1, ch2) == 0) cout << "암호가 맞았습니다." << endl;
	else cout << "암호가 틀렸습니다." << endl;

}
*/



/*
// 5번
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string yes = "yes";
	string input;

	for (;;)
	{
		cout << "종료하고 싶으면 \'yes\'를 입력하세요 : ";
		getline(cin, input);
		if (yes == input) {
			cout << "종료합니다" << endl;
			break;
		}
	}
}
*/



/*
// 6번
#include<iostream>
#include<string>
const int SIZE = 100;
int main()
{
	using namespace std;
	char text[SIZE];  // 입력받는 문자열
	string person[5]; // 각각 이름 저장하기 위한 배열
	int len[5];	// 각각 이름 길이 저장하기 위한 배열
	cout << "5명의 이름을 ; 으로 구분하여 입력하세요" << endl;
	cin.getline(text, SIZE);
	string name;  // 이름 구분해서 임시 저장하기 위한 string
	int num = 0; // 이름 개수
	for (int i = 0; i < strlen(text); i++)
	{
		// ; 나왔을 경우 끊어주기
		if (text[i] == ';') {
			person[num] = name;
			len[num] = name.length();
			num++;
			cout << num << "  :  " << name << endl;
			name = ""; // 저장용 string 초기화
		}
		else {
			name += text[i];
		}
	}
	int max = 0;
	string long_name;
	for (int k = 0; k < 5; k++)
	{
		if (max < len[k]) {
			max = len[k];
			long_name = person[k];
		}
	}
	cout << "가장 긴 이름은 " << long_name;

}
*/



/*
// 7번
#include<iostream>
int main()
{
	using namespace std;
	char str[100];
	cout << "문자열 입력 : ";
	cin.getline(str, 100);
	int index = 0;
	while (str[index] != '\0') {
		for (int i = 0; i <= index; i++) {
			cout << str[i];
		}
		cout << endl;
		index++;
	}
}
*/





/*
// 8번  

#include<iostream>
#include<string>
int main()
{
	using namespace std;
	int num1, num2;
	char num[20];
	char first_num[10];
	int first_index = 0;
	char second_num[10];
	int second_index = 0;
	int flag = 1;
	int calculate;

	cout << "? ";
	cin.getline(num, 20);
	for (int i = 0; i < strlen(num); i++)
	{
		// 공백인 경우
		if (num[i] == 32) {
			flag++;
		}
		// 연산자인 경우
		else if ((37 <= num[i] && num[i] <= 47) && flag==2)  {
			switch (num[i]) {
			case 43: calculate = 1; break;
			case 45: calculate = 2; break;
			case 42: calculate = 3; break;
			case 47: calculate = 4; break;
			case 37: calculate = 5; break;
			}
		}
		//정수인경우
		else {
			// 첫번째 정수일경우
			if (flag == 1) {
				first_num[first_index] = num[i];
				first_index++;
			}
			// 두번째 정수일경우
			else {
				second_num[second_index] = num[i];
				second_index++;
			}
		}
	}

	num1 = atoi(first_num);
	num2 = atoi(second_num);

	cout << num1 << " ";
	if (num2 < 0 && calculate == 2) { cout << " + " << -num2 << " = " << num1 + -num2; }
	else {
		switch (calculate) {
		case 1: cout << "+ " << num2 << " = " << num1 + num2; break;
		case 2: cout << " - " << num2 << " = " << num1 - num2; break;
		case 3: cout << " * " << num2 << " = " << num1 * num2; break;
		case 4: if (num2 != 0) { cout << " / " << num2 << " = " << num1 / num2; } break;
		case 5: cout << " % " << num2 << " = " << num1 % num2; break;
		}
	}
	cout << endl;
	
}
*/






/*
// 9번
#include<iostream>
#include<string>
#include<iomanip>
const int SIZE = 10000;
int main()
{
	using namespace std;
	char text[SIZE];
	int number[26] = { 0 };
	int index;
	int total = 0;
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl << "텍스트의 끝은 ;입니다. 10000개까지 가능합니다." << endl;
	
	cin.getline(text, SIZE, ';');

	//cout << "총 알파벳 수 " << strlen(text) << endl;
	
	for (index = 0; index < strlen(text); index++)
	{
		// 대문자는 소문자로 변환
		if (isupper(text[index])) {
			text[index] = tolower(text[index]);
		}
		// 알파벳 개수 세기
		if (97 <= text[index] && text[index] <= 122) {
			total++;
			number[text[index] - 97]++;
		}
	}
	//히스토그램 출력
	cout << "\n\n총 알파벳 수 " << total << endl;
	for (int i = 0; i < 26; i++)
	{
		cout.put(97+i) << "(" << number[i] << ")"  <<setw(5)<<"  :  ";
		for (int k = 0; k < number[i]; k++) {
			cout << '*';
		}
		cout << endl;
	}
}
*/




#include<iostream>
using namespace std;

void swap(int& p1, int& p2) {
	cout << "p1 : " << p1 << endl;
	cout << "p2 : " << p2 << endl;
}

int main(void) {
	int a = 5;
	int b = 10;

	swap(a, b);

}