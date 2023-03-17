#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* NumToRSP(int num) {
	// 받은 숫자코드를 통해 가위, 바위, 보로 변환하여 반환해주는 함수
	if (num == 1)
		return "가위";
	else if (num == 2)
		return "바위";
	else if (num == 3)
		return "보";
}


char* NumToPlayer(int num) {
	// 받은 숫자코드를 통해, A, B, C, D, User로 변환하여 반환
	if (num == 0)
		return "A";
	else if (num == 1)
		return "B";
	else if (num == 2)
		return "C";
	else if (num == 3)
		return "D";
	else if (num == 4)
		return "User";
}


int WinnerRSP(int *numcode) {
	// 승패 판정해서, 이기는 쪽의 심볼을 반환해주자!
	// 비길 경우 4를 반환하자
	// 판정은? 가위, 바위, 보의 개수를 보고 판단하자!
	int RSP[3] = {0, };

	for (int i = 0; i < 5; i++) {
		if (numcode[i] == 1)
			RSP[0]++;
		else if (numcode[i] == 2)
			RSP[1]++;
		else if (numcode[i] == 3)
			RSP[2]++;
	}

	if (RSP[0] != 0 && RSP[1] != 0 && RSP[2] != 0)
		return 4;
	else if (RSP[0] == 5 || RSP[1] == 5 || RSP[2] == 5)
		return 4;
	else if (RSP[0] == 0)
		return 3;
	else if (RSP[1] == 0)
		return 1;
	else if (RSP[2] == 0)
		return 2;
}


void printWinners(int *numcode, int winSymbol) {

	printf("승자는 ");
	for (int i = 0; i < 5; i++) {
		if (numcode[i] == winSymbol) {
			printf("%s ", NumToPlayer(i));
		}
	}
	printf("입니다.\n");
}



int main() {
	// 정수형 숫자코드, 문자열은 심볼 출력 문자열
	int numcode[5];
	char* sym[5];
	int winners[5] = {0, };
	int winSymbol;
	srand(time(NULL));


	while (1) {
		// 인트로 텍스트 출력, 유저 입력 받기, escape 코드 0 입력 시 탈출
		printf("가위(1)-바위(2)-보(3)? ");
		scanf_s("%d", &numcode[4]);
		if (numcode[4] == 0) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		// 컴퓨터 A,B,C,D의 난수 생성, 참여자 5의 심볼 출력
		for (int i = 0; i < 4; i++) {
			numcode[i] = rand() % 3 + 1;
		}
		for (int j = 0; j < 5; j++) {
			sym[j] = NumToRSP(numcode[j]);
		}
		printf("A:%s B:%s C:%s D:%s User:%s \n", sym[0], sym[1], sym[2], sym[3], sym[4]);
		// 승패 결과 판정 텍스트 출력
		winSymbol = WinnerRSP(numcode);
		if (winSymbol == 4) {
			printf("비겼습니다.\n");
		}
		else {
			printWinners(numcode, winSymbol);
		}
	}

	return 0;
}
