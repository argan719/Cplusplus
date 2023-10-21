class Robot {
private:
	char *name;  // 이름 저장
	int energy;  // 에너지량 저장
	void err_prn();  // 에러메시지 출력

public:
	void init(char *np, int e);		// 초기화 함수
	void go();  // 전진 함수
	void back();  // 후진 함수
	void turn();  // 회전 함수
	void jump();  // 점프 함수
	void charge(int c);  // 충전 함수
};