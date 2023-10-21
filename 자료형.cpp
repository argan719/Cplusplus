/*
#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n_int = INT_MAX;	// n_int를 int 형의 최대값으로 초기화
	short n_short = SHRT_MAX;	// limits.h 파일에 정의딘 기호 상수
	long n_long = LONG_MAX;

	cout << "int는 " << sizeof(int) << " 바이트이다." << endl;
	cout << "short는 " << sizeof n_short << " 바이트이다." << endl;
	cout << endl;

	cout << "최대값: " << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl << endl;
	cout << "long long: " << n_long << endl << endl;
	cout << "int의 최소값 = " << INT_MIN << endl;
	cout << "char의 비트 수 = " << CHAR_BIT << endl;
	return 0;
}
*/


/*
#include<iostream>
#define ZERO 0
#include<climits>
int main()
{
	using namespace std;
	short Dohee = SHRT_MAX;
	unsigned short Insuk = Dohee;

	cout << "도희의 계좌에는 " << Dohee << " 원이 들어 있고.";
	cout << "인숙이의 계좌에도 " << Insuk << " 원이 들어 있다." << endl;
	cout << "각각의 계좌에 1원씩 입금한다." << endl << "이제 ";
	Dohee = Dohee + 1;		Insuk = Insuk + 1;
	cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << Insuk << "원이 되었다." << endl;
	cout << "이럴수가! 도희가 나 몰래 대출을 했나?" << endl;
	Dohee = ZERO;		Insuk = ZERO;
	cout << "도희의 계좌에는 " << Dohee << "원이 들어 있고, ";
	cout << "인숙이의 계좌에도 " << Insuk << "원이 들어 있다. " << endl;
	cout << "각각의 계좌에서 1원씩 인출한다." << endl << "이제 ";
	Dohee = Dohee - 1;
	Insuk = Insuk - 1;
	cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << Insuk << "원이 되었다." << endl;
	cout << "이럴수가! 인숙이가 복권에 당첨되었나?" << endl;
	return 0;
}
*/


/*
//4번 
#include<iostream>
using namespace std;
int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "손님 몸매는 한마디로 끝내 줍니다!" << endl;
	cout << "가슴둘레 " << chest << " (10진수)" << endl;
	cout << hex;
	cout << "허리둘레 " << waist << " (16진수)" << endl;
	cout << oct;
	cout << "인심길이 " << inseam << " (8진수)" << endl;
	return 0;
}
*/


/*
// 5번
#include<iostream>
int main()
{
	using namespace std;
	char ch = 'M';

	int i = ch;
	cout << ch << " 의 ASCII 코드는 " << i << "입니다." << endl;

	cout << "이 문자 코드에 1을 더해 보겠습니다." << endl;
	ch = ch + 1;
	i = ch;
	cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

	cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
	cout.put(ch);

	cout.put('!');

	cout << endl << "종료" << endl;
	return 0;

}
*/


/*
// 6번
#include<iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;		//int형을 float형으로 변환
	int guess(3.9832);	//float형을 int형으로 변환
	int debt = 7.2E12;	// 범위 벗어난 값
	
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	return 0;
	
}
*/


/*
// 7번
#include<iostream>
int main()
{
	using namespace std;
	int auks, bats, coots;

	// 다음 구문은 두 값을 double형으로 더한 후에
	// 그 합을 int형으로 변환하여 대입한다
	auks = 19.99 + 11.99;

	// 다음 두 구문은 두 값을 int형으로 변환한 후에 더한다
	bats = (int)19.99 + (int) 11.99;	// 구식 C 스타일
	coots = int(19.99) + int(11.99);	// 신식 C++ 스타일
	
	cout << "바다오리 = " << auks << ", 박쥐 = " << bats;
	cout << ", 검둥오리 = " << coots << endl;

	char ch = 'Z';
	cout << "코드 " << ch << " 의 값은 ";  // char형으로 출력
	cout << int(ch) << endl;		// int형으로 출력
	cout << "코드 Z의 값은 ";
	cout << static_cast<int>(ch) << endl;	// int형으로 출력
	return 0;
}
*/


/*
// 8번
#include<iostream>
#include<string>	// strlen() 함수를 사용하기 위해
int main()
{
	using namespace std;
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";
	cout << "안녕하세요! 저는 " << name2;
	cout << "입니다! 실례하지만 성함이?\n";
	cin >> name1;
	cout << "아, " << name1 << " 씨! 당신의 이름은 ";
	cout << strlen(name1) << "자입니다만 \n";
	cout << sizeof(name1) << "바이트 크기의 배열에 저장되었습니다. \n";
	cout << "이름이 " << name1[0] << "자로 시작하는군요.\n";
	name2[3] = '\0';
	cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
	cout << name2 << endl;
	return 0;
}
*/

/*
// 9번
#include<iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	inflatable guest ={ "Glorious Gloria", 1.88, 29.99 };
	inflatable pal = { "Audacious Arthur", 3.12, 32.99 };

	cout << "지금 판매하고 있는 모형풍선은\n" << guest.name;
	cout << "와 " << pal.name << "입니다.\n";
	cout << "두 제품을 $";
	cout << guest.price + pal.price << "에 드리겠습니다!\n";
	return 0;
}
*/




/*
// 10번
#include<iostream>
enum Dates{SUN=100, MON, TUE=3, WED, THU, FRI, SAT};
using namespace std;

int main() {
	cout << SUN;
	cout << THU;
	cout << "오늘 요일을 입력하세요. " << endl;
	cout<< "SUN 0, MON 1, TUE 2, WED 3, THU 4, FRI 5, SAT 6" << endl;
	int today = 0;
	cin >> today;
	cout << "몇일 후의 요일을 원하십니까 입력하세요. " << endl;
	int input = 0;
	cin >> input;
	cout << input << "일 이후는  ";

	switch (((input + today) % 7)) {
		case SUN: cout << "SUNDAY" << endl; break;
		case MON: cout << "MONDAY" << endl; break;
		case TUE: cout << "TUESDAY" << endl; break;
		case WED: cout << "WENDS" << endl; break;
		case THU: cout << "THURSDAY" << endl; break;
		case FRI: cout << "FRIDAY" << endl; break;
		case SAT: cout << "SATURDAY" << endl; break;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
*/




// 8페이지~ 문제 풀이 시작


/*
// 8페이지 1번 
#include<iostream>
#include<iomanip>
int main()
{
	using namespace std;
	float num1, num2;
	cout << "실수 2개 입력 : ";
	cin >> num1 >> num2;
	cout << endl;
	cout << fixed;
	
	cout << setprecision(2);
	cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
	cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
	cout << num1 << " * " << num2 << " = " << (num1*num2) << endl;
	cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;

}
*/



/*
// 8페이지 2번
#include<iostream>
#include<ctime>
#include<iomanip>
#include<climits>
int main()
{
	using namespace std;
	int numlist[101] = { 0 };
	int num;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		if (i % 20 == 0) cout << endl;
		num = rand() % 101 + 0;
		cout <<left<< setw(5) << num;
		numlist[num]++;
	}
	int max = INT_MIN;
	int max_num;
	for (int k = 0; k < 101; k++)
	{
		if (max < numlist[k]) {
			max = numlist[k];
			max_num = k;
		}
	}
	cout << endl << endl << "==> 가장 많이 생성된 값 : " << max_num << endl;

}
*/





/*
// 8페이지 3번   -> 못함. 다시하기 (tic-tac-toe 게임)
#include<iostream>
#include<time.h>
typedef struct A{
	int a;
	int b;
}block;

typedef struct B {
	block three_block[3];
}line;


int main()
{
	using namespace std;
	int ground[3][3] = { 0 };

	int row, col;
	int i = 0;
	int user_num = -1;
	int computer_num = -1;

	block user[9];
	block computer[9];

	line bingo[8] = {
		{0,0,1,0,2,0},
		{0,1,1,1,2,1},
		{0,2,1,2,2,2},
		{0,0,0,1,0,2},
		{1,0,1,1,1,2},
		{2,0,2,1,2,2},
		{0,0,1,1,2,2},
		{0,2,1,1,2,0}
	};

	while (i < 10)
	{
		cout << "사용자 : 'O'를 둘 곳을 입력하세요 (0 ~ 2 정수 2개 입력)  ";
		cin >> row;
		cin >> col;
		if (row < 0 || 2 < row || col < 0 || 2 < col) {
			cout << "잘못 입력하셨습니다. 0,1,2 중 하나를 입력하세요" << endl;
			i--;
		}
		else {
			if (ground[row][col] != 0) {
				cout << "이미 말이 있는 자리입니다. 다른 곳을 입력하세요" << endl;
				i--;
			}
			else {
				ground[row][col] = 1;
				i++;
				user_num++;
				cout << "컴퓨터가 입력 중입니다.." << endl;
				// 컴퓨터가 처음으로 말을 둘 경우
				if (i == 1) {
					if (0 < row) row -= 1;
					else if (0 < col) col -= 1;
					else row += 1, col += 1;

					ground[row][col] = 2;
					i++;
					computer_num++;
				}
				// 컴퓨터가 2번째 이상 말을 둘 경우
				else {
					for (int a = 0; a < 3; a++)
					{
						for (int b = 0; b < 3; b++)
						{
							// 사용자가 둔 말의 위치 저장
							if (ground[a][b] == 1) {
								user[user_num] = { a, b };
								break;
							}
						}
					}
					int flag;
					for (int j = 0; j <= user_num; j++)
					{
						for (int k = 0; k < 8; k++)
						{
							flag = 0;
							for (int l = 0; l < 3; l++) {
								if (bingo[k].three_block[l].a == user[j].a  && bingo[k].three_block[l].b == user[j].b) flag++;
							}
							if (flag == 2) {
								int p;
								for (p = 0; p < 3; p++)
								{
									if (ground[bingo[k].three_block[p].a][bingo[k].three_block[p].b] == 0) {
										row = bingo[k].three_block[p].a;
										col = bingo[k].three_block[p].b;
										break;
									}
								}
								if (p == 3) {
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 3; b++)
										{
											// 컴퓨터가  둔 말의 위치 저장
											if (ground[a][b] == 1) {
												computer[computer_num] = { a, b };
												break;
											}
										}
									}
									int flag;
									for (int j = 0; j <= user_num; j++)
									{
										for (int k = 0; k < 8; k++)
										{
											flag = 0;
											for (int l = 0; l < 3; l++) {
												if (bingo[k].three_block[l].a == computer[j].a  && bingo[k].three_block[l].b == computer[j].b) flag++;
											}
											if (flag == 2) {
												int p;
												for (p = 0; p < 3; p++)
												{
													if (ground[bingo[k].three_block[p].a][bingo[k].three_block[p].b] == 0) {
														row = bingo[k].three_block[p].a;
														col = bingo[k].three_block[p].b;
														ground[row][col] = 2;
														i++;
														computer_num++;
														break;
													}
												}
											}
										}
									}

								}

							}

						}
					

					}
				}

			}
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << "  ";
					if (ground[a][a] == 0) cout << " -  ";
					else if (ground[a][b] == 1) cout << "O  ";
					else if (ground[a][b] == 2) cout << "X  ";
				}
				cout << endl;
			}
		}
	}

}
*/


// 8페이지 3번 다시







// 9페이지 4번
#include<iostream>
#include<string>
#include<iomanip>
#include<climits>


// 학생 한명당 정보 저장하기 위한 구조체 
typedef struct person {
	int num;
	int score[3]; // 3개 시험 점수
	int sum = 0;
	int max_score = INT_MIN; // 최고점수
	int min_score = INT_MAX; // 최저점수
	float aver_score; // 평균점수
	int grade = 1; // 등수 - > 평균을 보고 매긴다
}student;



// 시험 하나당 정보 저장하기 위한 구조체
typedef struct three_test {
	int sum = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	float aver;
}grade;


int main()
{
	using namespace std;
	student st[10];
	student *p = st;

	cout << st[0].sum;
	cout << p->sum;

	grade g[3];   // 시험3개
	// 학번, 시험점수 초기값 설정
	st[0] = { 1,{30,10,11} };
	st[1] = { 2,{40,90,32} };
	st[2] = { 3,{70,65,56} };
	st[3] = { 4,{70,43,32} };
	st[4] = { 5,{80,10,89} };

	// 시험 3개 통계 처리 
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 5; i++)
		{
			g[k].sum += st[i].score[k];
			if (g[k].max < st[i].score[k]) g[k].max = st[i].score[k];
			if (st[i].score[k] < g[k].min) g[k].min = st[i].score[k];
		}
		g[k].aver = g[k].sum / 5.0;
	}
	

	// 학생 5명 통계 처리 (max,min,aver)
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			st[i].sum += st[i].score[k];
			if (st[i].max_score < st[i].score[k]) st[i].max_score = st[i].score[k];
			if (st[i].score[k] < st[i].min_score) st[i].min_score = st[i].score[k];
		}
		st[i].aver_score = (st[i].sum / 3.0);
	}


	// 학생 등수 처리
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (st[i].aver_score < st[k].aver_score) st[i].grade++;
		}
	}
	cout << fixed;
	// 출력하기
	cout << "    학번  " << " 시험 #1  " << "  시험 #2  " << "  시험 #3  " << "  최고점수  " << "  최저점수  " << "  평균  " << "  등수  " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << left << setw(5);
		cout << "  " << st[i].num;
		for (int k = 0; k < 3; k++)
			cout <<setw(8)<<"    " << st[i].score[k];
		cout <<setw(11)<< "    " << st[i].max_score << setw(10)<<"    " << st[i].min_score << setw(6)<<
			setprecision(2)<<"    " << st[i].aver_score << setw(6)<< "    " << st[i].grade << "  "  << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			if (i == 0) {
				if (a == 0) { cout << "  최고점수  "; }
				cout << setw(2)<<"  " << g[a].max << "    ";
			}
			else if (i == 1) { 
				if (a == 0) { cout << "  최저점수  "; }
				cout << setw(2)<<"  " << g[a].min << "    ";
			}
			else { 
				if(a==0){ cout << "  평균점수  "; }
				 cout <<"  " <<setprecision(2)<< g[a].aver<<" " ;
			}
		}
		cout << endl;
	}
}





/*
// 9페이지 5번
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	char text[100];
	int chart[26] = { 0 };
	cout << "문자열을 입력하세요 : ";
	cin.getline(text, 100);

	for (int k = 0; k < strlen(text); k++)
	{
		if (97 <= text[k] && text[k] <= 122 || 65 <= text[k] && text[k] <= 90) {
			if (isupper(text[k])) text[k] = tolower(text[k]);
			chart[text[k] - 97]++;
		}
	}
	for (int k = 0; k < 26; k++)
	{
		if (chart[k] != 0) cout << char(97+k) << " : " << chart[k] << endl;
	}
}
*/

