#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Strike(int * target, int * digit) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (digit[i] == target[i])
			cnt++;
	}
	return cnt;
}

int Ball(int* target, int* digit) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (digit[i] == target[0]
			|| digit[i] == target[1]
			|| digit[i] == target[2]
			|| digit[i] == target[3])
			cnt++;
	}
	return cnt - Strike(target, digit);
}


int main() {

	int target[4] = { 0, };
	int input = 1;
	int digit[4] = { 0, };
	int try = 1;
	int Strikenum, Ballnum;
	srand(time(NULL));


	// 목표 난수 생성 - 중복 없이 네 자리
	target[0] = rand() % 10;
	do {
		target[1] = rand() % 10;
	} while (target[1] == target[0]);
	do {
		target[2] = rand() % 10;
	} while (target[2] == target[0]
		|| target[2] == target[1]);
	do {
		target[3] = rand() % 10;
	} while (target[3] == target[0]
		|| target[3] == target[1]
		|| target[3] == target[2]);



	// 인트로 메시지 고정
	printf("<<< 숫자야구 게임 >>>\n");
	printf("네 자리 숫자를 입력하시오. (0 = 포기)\n");

	printf("\t\t관리자모드: 답은 %d%d%d%d\n", target[0], target[1], target[2], target[3]);


	while (1) {
		// 입력 받아서 할당해주기
		printf("%d번째 시도: ", try);
		scanf_s("%d", &input);
		// 종료조건 1 - 0 입력
		if (input == 0) {
			printf("게임을 포기하였습니다.\n");
			printf("정답은 %d%d%d%d 입니다.\n", target[0], target[1], target[2], target[3]);
			break;
		}
		// 정상적인 입력 시의 처리 - 입력 받은 것을 통해 digit이란 입력 배열에 저장
		for (int j = 0; j < 4; j++) {
			digit[3 - j] = input % 10;
			input /= 10;
		}
		// 입력에 따라, S와 B 계산! - 함수 콜을 통해
		Strikenum = Strike(target, digit);
		Ballnum = Ball(target, digit);
		printf("%d%d%d%d is %dS %dB\n", digit[0], digit[1], digit[2], digit[3], Strikenum, Ballnum);

		// 종료조건 2 - 정답 
		if (Strikenum == 4) {
			printf("축하합니다.\n");
			printf("정답을 맞췄습니다.\n");
			break;
		}

		// 종료조건 3 - 10번의 기회 모두 사용, 오답
		if (try == 10) {
			printf("더 이상 기회가 없습니다.\n");
			printf("정답은 %d%d%d%d 입니다.\n", target[0], target[1], target[2], target[3]);
			break;
		}
		// 시행횟수 증가
		try++;
	}


	return 0;
}

