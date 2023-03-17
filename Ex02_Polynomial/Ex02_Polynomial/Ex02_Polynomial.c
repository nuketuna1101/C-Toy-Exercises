#include <stdio.h>
#include <stdlib.h>

#define	MAX_TERM	100

typedef int POLY[MAX_TERM];									// �迭�� ���׽� �ڷ��� ����
// ���׽��� �迭�� �־, �迭�� �ε����� ������, �迭 �� ���������Ͱ� �����

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



void zeroPoly(POLY p) {										// ���׽� �ʱ�ȭ
	for (int exp = 0; exp < MAX_TERM; exp++)
		p[exp] = 0;	// ����� 0���� �ʱ�ȭ
}

void addTerm(POLY p, int coef, int exp) {					// ���׽Ŀ� �� ���ϱ�
	p[exp] += coef;
}

void inputPoly(POLY p) {									// ���׽� �Է� �Լ�
	int	size, coef, exp;

	zeroPoly(p);		// ���׽� �ʱ�ȭ
	scanf_s("%d", &size);	// ���� ���� �Է�

	printf("Enter terms <coef,exp>*  : ");

	// �� ���� ����� ���� �Է�
	for (int i = 0; i < size; i++) {
		scanf_s("%d %d", &coef, &exp);
		p[exp] = coef;
	}
}

void printPoly(POLY p) {									// ���׽� ��� �Լ�
	int  coef, exp;
	for (exp = MAX_TERM - 1; exp >= 0; exp--) {
		coef = p[exp];
		if (coef > 0)		// ����� +�� ���, ���
			printf("+%dx^%d ", coef, exp);
		else if (coef < 0)	// ����� -�� ���, ���
			printf("%dx^%d ", coef, exp);
	}
	printf("\n");
}

void addPoly(POLY p, POLY q) {								// ���׽� ���� :: ������ ���� ���������� ��� ����
	for (int i = 0; i < MAX_TERM; i++) {
		addTerm(p, q[i], i);
	}
}

void multPoly(POLY p, POLY q) {								// ���׽� ���� :: ������ q�� �� �׿� ���Ͽ� 
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
	int coef;				// ���
	int exp;				// ����
}Poly;
 
void ViewPoly(Poly* P, int termP);

int main() {

	int termA, termB;										// �� ���׽��� �� ����
	Poly* A, *B;											// �� ���׽� A, B�� ��� - �� ������ŭ �޸𸮸� �����Ҵ��ؾ���

	// 1�� ���׽� �Է¹ޱ�
	printf("Enter # of terms of A(x) :  ");
	scanf_s("%d", &termA);
	A = (Poly*)malloc(sizeof(Poly) * termA);				//�����Ҵ�

	printf("Enter terms <coef, exp>* :  ");
	for (int i = 0; i < termA; i++) {
		scanf_s("%d %d", &A[i].coef, &A[i].exp);
	}
	ViewPoly(A, termA);

	// 2�� ���׽� �Է¹ޱ�
	printf("Enter # of terms of B(x) :  ");
	scanf_s("%d", &termB);
	B = (Poly*)malloc(sizeof(Poly) * termB);

	printf("Enter terms <coef, exp>* :  ");
	for (int j = 0; j < termA; j++) {
		scanf_s("%d %d", &B[j].coef, &B[j].exp);
	}
	ViewPoly(B, termB);



	// ���� ��� ���

	// ���� ��� ���

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