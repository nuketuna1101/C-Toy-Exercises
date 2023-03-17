#include <stdio.h>
#include <stdlib.h>


typedef struct hand {
	int rank;
	char highcard;
}hand;


int SuitToNum(char suit);
int CharToNum(char cnum);
char NumToChar(int num);
void checkHands(char* str);;
int isFlush(int(*cards)[2]);
int isFoCard(int* recordNum);
int isTriple(int* recordNum);
int Pair(int* recordNum);
int isStraight(int* recordNum);
int pairHighcard(int* recordNum);
int straightHighcard(int* recordNum);
int Rank(int(*cards)[2], int* recordNum);
void ShowRank(int(*cards)[2], int* recordNum);



int main() {


	/*
		//char *str1 = "C6 H2 D3 SJ C5";
	char* str1 = "C6 H6 D6 SJ C6";
	//char* str1 = "C3 HJ D6 SJ C6";
	//char* str1 = "S9 SQ S8 S7 SA";
	//char* str1 = "DK DQ DT DA DJ";

	printf("str1 : %s\n\n", str1);
	checkHands(str1);
	*/
	checkHands("C6 H2 D3 SJ C5");
	checkHands("CA H2 D3 SJ CA");
	checkHands("H7 D3 S7 CA S3");
	checkHands("C4 H4 D3 S4 CA");
	checkHands("CK HK DK SK CA");
	checkHands("CA H5 DA SA C5");
	checkHands("C9 H6 D8 S7 C5");
	checkHands("S9 SQ S8 S7 SA");
	checkHands("D9 DT D8 D7 DJ");
	checkHands("DK DQ DT DA DJ");


	return 0;
}




int SuitToNum(char suit) {				// ī�� ������ �о�� �ش� ������ �ø���ѹ��� �ٲ�. Ŭ�ι�->1, ��Ʈ->2, ���̾�->3, �����̵�->4
	int suitno;

	if (suit == 'C') {
		suitno = 1;
	}
		//suitno = 1;
	else if (suit == 'H')
		suitno = 2;
	else if (suit == 'D')
		suitno = 3;
	else if (suit == 'S')
		suitno = 4;

	return suitno;
}


int CharToNum(char cnum) {				// ī���� ����,���ڸ� ���� ���ڷ� ��ȯ
	int num;

	if (cnum == 'A')
		num = 1;
	else if (cnum == '2')
		num = 2;
	else if (cnum == '3')
		num = 3;
	else if (cnum == '4')
		num = 4;
	else if (cnum == '5')
		num = 5;
	else if (cnum == '6')
		num = 6;
	else if (cnum == '7')
		num = 7;
	else if (cnum == '8')
		num = 8;
	else if (cnum == '9')
		num = 9;
	else if (cnum == 'T')
		num = 10;
	else if (cnum == 'J')
		num = 11;
	else if (cnum == 'Q')
		num = 12;
	else if (cnum == 'K')
		num = 13;

	return num;
}


char NumToChar(int num) {
	char cnum;

	if (num == 1)
		cnum = 'A';
	else if (num >= 2 && num <= 9)
		cnum = '0' + num;
	else if (num == 10)
		cnum = 'T';
	else if (num == 11)
		cnum = 'J';
	else if (num == 12)
		cnum = 'Q';
	else if (num == 13)
		cnum = 'K';

	return cnum;
}

	
void checkHands(char* str) {
	int cards[5][2];						// cards �迭�� �÷��̾��� ������ ����, id0�� ��������, id1�� ��������
	int recordNum[13] = {0,};

	for (int i = 0; i < 5; i++) {
		cards[i][0] = SuitToNum(str[3*i]);				// 2���� �迭 cards�� ��������
		cards[i][1] = CharToNum(str[3*i + 1]);			// 2���� �迭 cards�� ���ڱ�������
	}
	
	// cards �迭 ����� ����
	printf("2���� �迭 cards ���\n");
	for (int j = 0; j < 5; j++) {
		printf("cards[%d][0] = %d		cards[%d][1] = %d\n", j, cards[j][0], j, cards[j][1]);
	}

	for (int k = 0; k < 13; k++) {						// recordNum �迭�� ���� ���ڸ� ���� ī�� ��� ���
		for (int m = 0; m < 5; m++) {
			if (cards[m][1] == k + 1) {
				recordNum[k]++;
			}
		}
	}

	// recordNum �迭 ����� ����
	for (int p = 0; p < 13; p++) {
		printf("recordNum[%2d] :: ���� %2d ī��� %d ��\n", p, p+1, recordNum[p]);
	}


	/*
		isFoCard(recordNum);
	isTriple(recordNum);
	Pair(recordNum);

	printf("isFlush���� %d\n", isFlush(cards));
	if (isFlush(cards) == 1) {
		printf("�÷���\n");
	}

	printf("isStraight���� %d\n", isStraight(recordNum));

	if (isFlush(cards) != -1) {
		printf("%d ��Ʈ����Ʈ\n", isStraight(recordNum));
	}
	*/

	ShowRank(cards, recordNum);


	printf("\n\nEnd\n");
}


// �÷��ð� �´ٸ� 1, �÷��ð� �ƴ� ���� -1
int isFlush(int (* cards)[2]) {
	if (cards[0][0] == cards[1][0]
		&& cards[1][0] == cards[2][0]
		&& cards[2][0] == cards[3][0]
		&& cards[3][0] == cards[4][0])
		return 1;
	return -1;
}



int isFoCard(int * recordNum) {

	for (int i = 0; i < 13; i++) {
		if (recordNum[i] == 4) {
			//printf("%c ��ī��\n", NumToChar(i+1));
			//printf("%d", pairHighcard(recordNum));
			//printf("��ī��\n");
			return 1;
		}
	}
	return -1;
}

int isTriple(int* recordNum) {

	for (int i = 0; i < 13; i++) {
		if (recordNum[i] == 3) {
			//printf("%c Ʈ����\n", NumToChar(i + 1));
			return 1;
		}
	}
	return -1;
}

// Pair �Լ��� ���� ��°��� ����� ����, ��� ���� �� 0
int Pair(int* recordNum) {
	int cnt = 0;
	//char highcard;

	for (int i = 0; i < 13; i++) {
		if (recordNum[i] == 2) {
			//printf("%c ���\n", NumToChar(i + 1));
			//highcard = NumToChar(i + 1);
			cnt++;
			//printf("%c ���\n", highcard);
		}
	}
	return cnt;
}

int isStraight(int* recordNum) {
	// ��Ʈ����Ʈ�� ���� ����ī�嵵 �ʿ�
	// isStraight �� ���, ��Ʈ����Ʈ�� �ƴ� ��� -1�� ��ȯ������, ���� ��� ���� ī�� ���� ��ȯ!
	if (recordNum[0] == 1 && recordNum[1] == 1 && recordNum[2] == 1 && recordNum[3] == 1 && recordNum[4] == 1)
		return 5;
	else if (recordNum[1] == 1 && recordNum[2] == 1 && recordNum[3] == 1 && recordNum[4] == 1 && recordNum[5] == 1)
		return 6;
	else if (recordNum[2] == 1 && recordNum[3] == 1 && recordNum[4] == 1 && recordNum[5] == 1 && recordNum[6] == 1)
		return 7;
	else if (recordNum[3] == 1 && recordNum[4] == 1 && recordNum[5] == 1 && recordNum[6] == 1 && recordNum[7] == 1)
		return 8;
	else if (recordNum[4] == 1 && recordNum[5] == 1 && recordNum[6] == 1 && recordNum[7] == 1 && recordNum[8] == 1)
		return 9;
	else if (recordNum[5] == 1 && recordNum[6] == 1 && recordNum[7] == 1 && recordNum[8] == 1 && recordNum[9] == 1)
		return 10;
	else if (recordNum[6] == 1 && recordNum[7] == 1 && recordNum[8] == 1 && recordNum[9] == 1 && recordNum[10] == 1)
		return 11;
	else if (recordNum[7] == 1 && recordNum[8] == 1 && recordNum[9] == 1 && recordNum[10] == 1 && recordNum[11] == 1)
		return 12;
	else if (recordNum[8] == 1 && recordNum[9] == 1 && recordNum[10] == 1 && recordNum[11] == 1 && recordNum[12] == 1)
		return 13;
	else if (recordNum[9] == 1 && recordNum[10] == 1 && recordNum[11] == 1 && recordNum[12] == 1 && recordNum[0] == 1)
		return 1;		// A-K-Q-J-10 ���̽� ���� ��Ʈ����Ʈ�� ���
	else
		return -1;		// -1�� ��Ʈ����Ʈ�� �ƴ�
}


// ����ī�� ��ȯ �Լ�. ��, ���(Ʈ����, ��ī�带 ������) ������ ��츸
int pairHighcard(int* recordNum) {

	if (recordNum[0] == 4)
		return 1;
	else {
		for (int i = 12; i > 0; i--) {
			if (recordNum[i] == 4)
				return i + 1;
		}
	}

	if (recordNum[0] == 3)
		return 1;
	else {
		for (int i = 12; i > 0; i--) {
			if (recordNum[i] == 3)
				return i + 1;
		}
	}

	if (recordNum[0] == 2)
		return 1;
	else {
		for (int i = 12; i > 0; i--) {
			if (recordNum[i] == 2)
				return i + 1;
		}
	}

	if (recordNum[0] == 1)
		return 1;
	else {
		for (int i = 12; i > 0; i--) {
			if (recordNum[i] == 1)
				return i + 1;
		}
	}
}


// ��Ʈ����Ʈ�� ����� ����ī�� Ž���� ACE�� ���� ����ó���� �߿�
int straightHighcard(int* recordNum) {
	// ���̽��� ���Ե� ��Ʈ����Ʈ�� ���� �� �ΰ���. 1 - ���̽� ���̰ų�, 2 - 5 ��Ʈ����Ʈ
	if (recordNum[0] == 1) {
		if (recordNum[12] == 1)
			return 1;	// ���̽� ���� ��Ʈ����Ʈ
		else if (recordNum[4] == 1)
			return 5;	// 5 ���� ��Ʈ����Ʈ
	}
	else {
		// ���̽� ī�尡 ���Ե��� ���� ��Ʈ����Ʈ. ��, K ���� ~ 6 ���� ��Ʈ����Ʈ����
		for (int i = 12; i > 4; i--) {
			if (recordNum[i] == 1)
				return i + 1;
		}
	}
}





int Rank(int (* cards)[2], int* recordNum) {
	// �ش��ϴ� ������ ���� ���� �ű��, ����ī�� ������ ����

	// �� 10������ ����
	// 1. �ο� ��Ʈ����Ʈ �÷���
	if (isFlush(cards) == 1
		&& isStraight(recordNum) == 1) {
		return 1;
	}
	// 2. ��Ʈ����Ʈ �÷���
	else if (isFlush(cards) == 1
		&& isStraight(recordNum) != -1) {
		return 2;
	}
	// 3. ��ī��
	else if (isFoCard(recordNum) == 1) {
		return 3;
	}
	// 4. Ǯ�Ͽ콺
	else if (isTriple(recordNum) == 1
		&& Pair(recordNum) == 1) {
		return 4;
	}
	// 5. �÷���
	else if (isFlush(cards) == 1) {
		return 5;
	}
	// 6. ��Ʈ����Ʈ
	else if (isStraight(recordNum) != -1) {
		return 6;
	}
	// 7. Ʈ����
	else if (isTriple(recordNum) == 1) {
		return 7;
	}
	// 8. �����
	else if (Pair(recordNum) == 2) {
		return 8;
	}
	// 9. �����
	else if (Pair(recordNum) == 1) {
		return 9;
	}
	// 10. ����ī��
	else {
		return 10;
	}
}


void ShowRank(int(*cards)[2], int* recordNum) {
	int rank = Rank(cards, recordNum);
	char highC;
	
	if (isStraight(recordNum) != -1)
		highC = NumToChar(straightHighcard(recordNum));
	else
		highC = NumToChar(pairHighcard(recordNum));


	if (rank == 1) {
		printf("A �ο� ��Ʈ����Ʈ �÷���\n");
	}
	else if (rank == 2) {
		printf("%c ��Ʈ����Ʈ �÷���\n", highC);
	}
	else if (rank == 3) {
		printf("%c ��ī��\n", highC);
	}
	else if (rank == 4) {
		printf("%c Ǯ�Ͽ콺\n", highC);
	}
	else if (rank == 5) {
		printf("%c �÷���\n", highC);
	}
	else if (rank == 6) {
		printf("%c ��Ʈ����Ʈ\n", highC);
	}
	else if (rank == 7) {
		printf("%c Ʈ����\n", highC);
	}
	else if (rank == 8) {
		printf("%c �����\n", highC);
	}
	else if (rank == 9) {
		printf("%c �����\n", highC);
	}
	else if (rank == 10) {
		printf("%c ����ī��\n", highC);
	}
}






