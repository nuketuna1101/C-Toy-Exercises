#include <stdio.h>
#include <stdlib.h>

#define	MAX_TERM	100

typedef int POLY[MAX_TERM];									// 배열로 다항식 자료형 정의
// 다항식이 배열에 있어서, 배열의 인덱스가 지수값, 배열 내 정수데이터가 계수값

void zeroPoly(POLY p);
void addTerm(POLY p, int coef, int exp);
void inputPoly(POLY p);
void printPoly(POLY p);
void addPoly(POLY p, POLY q);
void multPoly(POLY p, POLY q);

int main()
{
	POLY	polyA, polyB;
	POLY	polyC, polyD;

	printf("Enter # of terms of A(x) : ");
	inputPoly(polyA);
	printf("A(x) = ");
	printPoly(polyA);

	printf("Enter # of terms of B(x) : ");
	inputPoly(polyB);
	printf("B(x) = ");
	printPoly(polyB);

	zeroPoly(polyC);
	addPoly(polyC, polyA);

	zeroPoly(polyD);
	addPoly(polyD, polyA);

	printf("\n");
	printf("C(x) = A(x) + B(x)\n");
	printf("     = ");
	addPoly(polyC, polyB);
	printPoly(polyC);

	printf("\n");
	printf("D(x) = A(x) * B(x)\n");
	printf("     = ");
	multPoly(polyD, polyB);
	printPoly(polyD);


	return 0;
}



void zeroPoly(POLY p) {										// 다항식 초기화
	for (int exp = 0; exp < MAX_TERM; exp++)
		p[exp] = 0;	// 계수를 0으로 초기화
}

void addTerm(POLY p, int coef, int exp) {					// 다항식에 항 더하기
	p[exp] += coef;
}

void inputPoly(POLY p) {									// 다항식 입력 함수
	int	size, coef, exp;

	zeroPoly(p);		// 다항식 초기화
	scanf_s("%d", &size);	// 항의 갯수 입력

	printf("Enter terms <coef,exp>*  : ");

	// 각 항의 계수와 지수 입력
	for (int i = 0; i < size; i++) {
		scanf_s("%d %d", &coef, &exp);
		p[exp] = coef;
	}
}

void printPoly(POLY p) {									// 다항식 출력 함수
	int  coef, exp;
	for (exp = MAX_TERM - 1; exp >= 0; exp--) {
		coef = p[exp];
		if (coef > 0)		// 계수가 +인 경우, 출력
			printf("+%dx^%d ", coef, exp);
		else if (coef < 0)	// 계수가 -인 경우, 출력
			printf("%dx^%d ", coef, exp);
	}
	printf("\n");
}

void addPoly(POLY p, POLY q) {								// 다항식 덧셈 :: 로직은 같은 지수값끼리 계수 덧셈
	for (int i = 0; i < MAX_TERM; i++) {
		addTerm(p, q[i], i);
	}
}

void multPoly(POLY p, POLY q) {								// 다항식 곱셈 :: 로직은 q의 각 항에 대하여 
	POLY r;
	zeroPoly(r);

	for (int i = 0; i < MAX_TERM; i++) {
		for (int j = 0; j < MAX_TERM; j++) {
			addTerm(r, p[i]*q[j], i+j);
		}
	}
	zeroPoly(p);
	addPoly(p, r);
}





/*

typedef struct Poly {
	int coef;				// 계수
	int exp;				// 지수
}Poly;
 
void ViewPoly(Poly* P, int termP);

int main() {

	int termA, termB;										// 두 다항식의 항 개수
	Poly* A, *B;											// 두 다항식 A, B로 명명 - 항 개수만큼 메모리를 동적할당해야함

	// 1번 다항식 입력받기
	printf("Enter # of terms of A(x) :  ");
	scanf_s("%d", &termA);
	A = (Poly*)malloc(sizeof(Poly) * termA);				//동적할당

	printf("Enter terms <coef, exp>* :  ");
	for (int i = 0; i < termA; i++) {
		scanf_s("%d %d", &A[i].coef, &A[i].exp);
	}
	ViewPoly(A, termA);

	// 2번 다항식 입력받기
	printf("Enter # of terms of B(x) :  ");
	scanf_s("%d", &termB);
	B = (Poly*)malloc(sizeof(Poly) * termB);

	printf("Enter terms <coef, exp>* :  ");
	for (int j = 0; j < termA; j++) {
		scanf_s("%d %d", &B[j].coef, &B[j].exp);
	}
	ViewPoly(B, termB);



	// 덧셈 결과 출력

	// 곱셈 결과 출력

	return 0;
}



void ViewPoly(Poly * P, int termP) {
	for (int i = 0; i < termP; i++) {
		if (P[i].coef > 0) {
			printf("+");
		}
		printf("%dx^%d ", P[i].coef, P[i].exp);
	}
}

void AddPoly(Poly * P, Poly * Q) {

}

void MultiPoly() {

}
*/