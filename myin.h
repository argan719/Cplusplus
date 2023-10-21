
// 연산자의오버로딩(2)
// 7페이지 9번
// === myin.h

#include<conio.h>
#include<stdio.h>
class myin {
public:
	myin & operator>> (char &a) { scanf("%c", &a); return(*this); }
	myin & operator>> (int &a) { scanf("%d", &a); return(*this); }
	myin & operator>> (double &a) { scanf("%lf", &a); return(*this); }
	myin & operator>> (char *a) { scanf("%s", a); return(*this); }
	myin & input(char *ap, char &a) {
		printf(ap);
		fflush(stdin);
		scanf("%c", &a);
		return(*this);
	}
	myin & input(char *ap, int &a) {
		printf(ap);
		scanf("%d", &a);
		return(*this);
	}
	myin & input(char *ap, double &a) {
		printf(ap);
		scanf("%lf", &a);
		return(*this);
	}
	myin & input(char *ap, char *a) {
		printf(ap);
		scanf("%s", a);
		return(*this);
	}
	myin & ignore() {
		fflush(stdin);
		return(*this);
	}
};
myin cin;