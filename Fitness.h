#ifndef FITNESS_H
#define FITNESS_H
class Fitness {
private:
	int num;		// 회원번호
	char name[20];  // 이름
	double weight;  // 체중
public:
	void init(int n, char *ap, double w);  // 초기화 맴버함수
	double weigh();  // 체중을 리턴한다.
	void prn();  // 객체의 내용 출력
};

#endif // !FITNESS_H
