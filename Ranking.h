// - 함수 - 
// 21페이지 18번 
// 퍼즐게임

// === Ranking.h

#include<cstdio>

struct PlayInfo {
	char name[200];		// 선수의 이름
	int nMove;		// 퍼즐 조각을 움직인 횟수
	double tElapsed;	// 경기 소요 시간
};

extern void loadRanking(char* filename);
extern void storeRanking(char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);