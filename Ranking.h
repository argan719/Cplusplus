// - �Լ� - 
// 21������ 18�� 
// �������

// === Ranking.h

#include<cstdio>

struct PlayInfo {
	char name[200];		// ������ �̸�
	int nMove;		// ���� ������ ������ Ƚ��
	double tElapsed;	// ��� �ҿ� �ð�
};

extern void loadRanking(char* filename);
extern void storeRanking(char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);