// - �Լ� - 
// 20������ 17�� 
// ���ӽ���ð��� üũ�ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.

// === myFunctions.cpp

#include<stdio.h>
#include<conio.h>
int playUpAndDown(int n, int min, int max)
{
	int input, i;
	for (i = 0; i < 10; i++) {
		printf("[%2dȸ]  %2d ~ %2d ������ �� ���� =>", i + 1, min, max);
		scanf("%d", &input);

		if (n == input) break;
		else if (n > input) {
			printf("�� ū �����Դϴ�!\n");
			min = input;
		}
		else {
			printf("�� ���� �����Դϴ�!\n");
			max = input;
		}
	}
	return 10 * (10 - i);
}