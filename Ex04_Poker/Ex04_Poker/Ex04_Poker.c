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




int SuitToNum(char suit) {				// 카드 문양을 읽어내어 해당 문양의 시리얼넘버로 바꿈. 클로버->1, 하트->2, 다이아->3, 스페이드->4
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


int CharToNum(char cnum) {				// 카드의 숫자,글자를 정수 숫자로 변환
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
	int cards[5][2];						// cards 배열은 플레이어의 족보에 대해, id0엔 문양정보, id1엔 숫자정보
	int recordNum[13] = {0,};

	for (int i = 0; i < 5; i++) {
		cards[i][0] = SuitToNum(str[3*i]);				// 2차원 배열 cards에 문양정보
		cards[i][1] = CharToNum(str[3*i + 1]);			// 2차원 배열 cards에 숫자글자정보
	}
	
	// cards 배열 검출용 더미
	printf("2차원 배열 cards 출력\n");
	for (int j = 0; j < 5; j++) {
		printf("cards[%d][0] = %d		cards[%d][1] = %d\n", j, cards[j][0], j, cards[j][1]);
	}

	for (int k = 0; k < 13; k++) {						// recordNum 배열에 같은 숫자를 가진 카드 장수 기록
		for (int m = 0; m < 5; m++) {
			if (cards[m][1] == k + 1) {
				recordNum[k]++;
			}
		}
	}

	// recordNum 배열 검출용 더미
	for (int p = 0; p < 13; p++) {
		printf("recordNum[%2d] :: 숫자 %2d 카드는 %d 장\n", p, p+1, recordNum[p]);
	}


	/*
		isFoCard(recordNum);
	isTriple(recordNum);
	Pair(recordNum);

	printf("isFlush값은 %d\n", isFlush(cards));
	if (isFlush(cards) == 1) {
		printf("플러시\n");
	}

	printf("isStraight값은 %d\n", isStraight(recordNum));

	if (isFlush(cards) != -1) {
		printf("%d 스트레이트\n", isStraight(recordNum));
	}
	*/

	ShowRank(cards, recordNum);


	printf("\n\nEnd\n");
}


// 플러시가 맞다면 1, 플러시가 아닌 경우는 -1
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
			//printf("%c 포카드\n", NumToChar(i+1));
			//printf("%d", pairHighcard(recordNum));
			//printf("포카드\n");
			return 1;
		}
	}
	return -1;
}

int isTriple(int* recordNum) {

	for (int i = 0; i < 13; i++) {
		if (recordNum[i] == 3) {
			//printf("%c 트리플\n", NumToChar(i + 1));
			return 1;
		}
	}
	return -1;
}

// Pair 함수의 경우는 출력값은 페어의 개수, 페어 없을 시 0
int Pair(int* recordNum) {
	int cnt = 0;
	//char highcard;

	for (int i = 0; i < 13; i++) {
		if (recordNum[i] == 2) {
			//printf("%c 페어\n", NumToChar(i + 1));
			//highcard = NumToChar(i + 1);
			cnt++;
			//printf("%c 페어\n", highcard);
		}
	}
	return cnt;
}

int isStraight(int* recordNum) {
	// 스트레이트의 경우는 하이카드도 필요
	// isStraight 의 경우, 스트레이트가 아닐 경우 -1을 반환하지만, 맞을 경우 하이 카드 값을 반환!
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
		return 1;		// A-K-Q-J-10 에이스 하이 스트레이트의 경우
	else
		return -1;		// -1은 스트레이트가 아님
}


// 하이카드 반환 함수. 단, 페어(트리플, 포카드를 포함한) 족보의 경우만
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


// 스트레이트일 경우의 하이카드 탐색은 ACE에 관한 예외처리가 중요
int straightHighcard(int* recordNum) {
	// 에이스가 포함된 스트레이트인 경우는 단 두가지. 1 - 에이스 하이거나, 2 - 5 스트레이트
	if (recordNum[0] == 1) {
		if (recordNum[12] == 1)
			return 1;	// 에이스 하이 스트레이트
		else if (recordNum[4] == 1)
			return 5;	// 5 하이 스트레이트
	}
	else {
		// 에이스 카드가 포함되지 않은 스트레이트. 즉, K 하이 ~ 6 하이 스트레이트까지
		for (int i = 12; i > 4; i--) {
			if (recordNum[i] == 1)
				return i + 1;
		}
	}
}





int Rank(int (* cards)[2], int* recordNum) {
	// 해당하는 족보에 따라 값을 매기고, 하이카드 정보도 저장

	// 총 10가지의 족보
	// 1. 로열 스트레이트 플러시
	if (isFlush(cards) == 1
		&& isStraight(recordNum) == 1) {
		return 1;
	}
	// 2. 스트레이트 플러시
	else if (isFlush(cards) == 1
		&& isStraight(recordNum) != -1) {
		return 2;
	}
	// 3. 포카드
	else if (isFoCard(recordNum) == 1) {
		return 3;
	}
	// 4. 풀하우스
	else if (isTriple(recordNum) == 1
		&& Pair(recordNum) == 1) {
		return 4;
	}
	// 5. 플러시
	else if (isFlush(cards) == 1) {
		return 5;
	}
	// 6. 스트레이트
	else if (isStraight(recordNum) != -1) {
		return 6;
	}
	// 7. 트리플
	else if (isTriple(recordNum) == 1) {
		return 7;
	}
	// 8. 투페어
	else if (Pair(recordNum) == 2) {
		return 8;
	}
	// 9. 원페어
	else if (Pair(recordNum) == 1) {
		return 9;
	}
	// 10. 하이카드
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
		printf("A 로열 스트레이트 플러쉬\n");
	}
	else if (rank == 2) {
		printf("%c 스트레이트 플러쉬\n", highC);
	}
	else if (rank == 3) {
		printf("%c 포카드\n", highC);
	}
	else if (rank == 4) {
		printf("%c 풀하우스\n", highC);
	}
	else if (rank == 5) {
		printf("%c 플러쉬\n", highC);
	}
	else if (rank == 6) {
		printf("%c 스트레이트\n", highC);
	}
	else if (rank == 7) {
		printf("%c 트리플\n", highC);
	}
	else if (rank == 8) {
		printf("%c 투페어\n", highC);
	}
	else if (rank == 9) {
		printf("%c 원페어\n", highC);
	}
	else if (rank == 10) {
		printf("%c 하이카드\n", highC);
	}
}






