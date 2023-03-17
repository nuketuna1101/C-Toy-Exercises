#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node* link;
}Node;


typedef struct Poly {
    Node* head;
    int term;
}Poly;


Poly* InitPoly();
void PrintPoly(Poly* p);
void InsertNode(Poly* p, int coef, int exp);
void addTerm(Poly* p, int coef, int exp);
void addPoly(Poly* p, Poly* q);
Poly* multTerm(Poly* p, int coef, int exp);
Poly* multPoly(Poly* p, Poly* q);


int main() {
    Poly* A = InitPoly();
    Poly* B = InitPoly();
    Poly* C = InitPoly();
    Poly* D = InitPoly();


    int termA, termB;
    int tempcoef, tempexp;


    printf("Enter # of terms of A(x) : ");
    scanf_s("%d", &termA);

    printf("Enter terms <coef, exp>* : ");
    for (int i = 0; i < termA; i++) {
        scanf_s("%d %d", &tempcoef, &tempexp);
        addTerm(A, tempcoef, tempexp);
    }
    printf("A(x) = ");
    PrintPoly(A);

    printf("Enter # of terms of B(x) : ");
    scanf_s("%d", &termB);

    printf("Enter terms <coef, exp>* : ");
    for (int i = 0; i < termB; i++) {
        scanf_s("%d %d", &tempcoef, &tempexp);
        addTerm(B, tempcoef, tempexp);
    }
    printf("B(x) = ");
    PrintPoly(B);


    addPoly(C, A);
    printf("C(x) = A(x) + C(x)\n");
    printf("     = ");
    addPoly(C, B);
    PrintPoly(C);

    /*
    D = multTerm(A, 3, 3);
    printf("D(x) = A(x) * 3x^3\n");
    printf("     = ");
    PrintPoly(D);
    */
    
    printf("D(x) = A(x) * C(x)\n");
    printf("     = ");
    D = multPoly(A, B);
    PrintPoly(D);
    

    return 0;
}

Poly* InitPoly() {
    Poly* newpoly = (Poly*)malloc(sizeof(Poly));
    newpoly->head = NULL;
    newpoly->term = 0;

    return newpoly;
}

void PrintPoly(Poly * p) {
    Node* search = p->head;

    while (search != NULL) {
        if (search->coef > 0)
            printf("+");
        printf("%dx^%d ", search->coef, search->exp);
        search = search->link;
    }
    printf("\n\n");
}


void InsertNode(Poly * p, int coef, int exp) {
    Node* new = (Node*)malloc(sizeof(Node));
    Node* search = p->head;                                         // Ž���� search. ������ �����ؼ� tail ��� Ž��


    new->coef = coef;
    new->exp = exp;
    new->link = NULL;

    if (p->head == NULL) {                                          // �־��� ���׽��� �������� ���
        p->head = new;
    }
    else {                                                          // �������� �ƴ϶�� Ž���ذ��� �� �ڿ� �߰����ֱ�
        while (search->link != NULL) {
            search = search->link;
        }
        search->link = new;
    }
    p->term++;
}

void addTerm(Poly * p, int coef, int exp) {                         // ���׽Ŀ� ���� ���ϴ� ����
    Node* new = (Node*)malloc(sizeof(Node));
    Node* search = p->head;       // Ž����
    Node* prev = p->head;
    int needtoLink = 1;

    new->coef = coef;
    new->exp = exp;
    new->link = NULL;

    if (p->head == NULL) {                                          // �־��� ���׽��� �������� ���
        p->head = new;
    }
    else if ((p->head)->exp < exp){                  // ��� �� ù ����� �������� ũ�ٴ� �� �� �տ� �پ���Ѵٴ� ��
        new->link = p->head;
        p->head = new;
    }
    else if ((p->head)->exp == exp) {
        (p->head)->coef += coef;
        if ((p->head)->coef == 0) {
            p->head = p->head->link;
        }
    }
    else {
        while (search->link != NULL) {                              // ���� Ž���� ���� ��尡 ��, �� ���� Ž���Ⱑ ������ �����
            prev = search;
            search = search->link;          // Ž���� ���� ���� ���� Ž���⸦ �̵�

            if (search->exp == exp) {       // ��ġ�ϸ�, new ��带 �̾��� �ʿ䰡 ������
                search->coef += coef;
                needtoLink = 0;
                if (search->coef == 0) {
                    prev->link = search->link;
                }
                break;
            }
            //
            else if (search->exp < exp) {
                new->link = search;
                prev->link = new;
                needtoLink = 0;
                break;
            }
            //
        }
        if (needtoLink == 1)
            search->link = new;
    }

}

void addPoly(Poly * p, Poly * q) {
    Node* curnode = q->head;

    while (curnode->link != NULL) {
        addTerm(p, curnode->coef, curnode->exp);
        curnode = curnode->link;
    }
    addTerm(p, curnode->coef, curnode->exp);
}

Poly* multTerm(Poly * p, int coef, int exp) {
    int tempcoef, tempexp;
    Poly* r = InitPoly();
    Node* curnode = p->head;


    while (curnode->link != NULL) {
        tempcoef = curnode->coef * coef;
        tempexp = curnode->exp + exp;
        addTerm(r, tempcoef, tempexp);
        curnode = curnode->link;
    }
    tempcoef = curnode->coef * coef;
    tempexp = curnode->exp + exp;
    addTerm(r, tempcoef, tempexp);

    return r;
}


Poly* multPoly(Poly* p, Poly* q) {
    Poly* r = InitPoly();
    Node* curnode = q->head;

    while (curnode->link != NULL) {
        addPoly(r, multTerm(p, curnode->coef, curnode->exp));
        curnode = curnode->link;
    }
    addPoly(r, multTerm(p, curnode->coef, curnode->exp));

    return r;
}
