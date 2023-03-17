#include <stdio.h>
#include <stdlib.h>

void doKthMove(int cntKthMove, int n, int k, int current, int* arr);

int main() {
	int n, k;			// 입력 인자
	int* arr;			// arr는 n 크기의 배열, 해당 값은 1 ~ n의 정수. 이후 pop될 시엔 -1 값으로 수정
	int cntKthMove;			// cnt는 카운터변수, 킬링시퀀스에서 반복값을 위해
	int current = -1;		// current는 킬링시퀀스에서 현재 가리키는 위치 인덱스를 지정
	int cntTry;				// 시행의 횟수는 n-1번 해야지

	//step 1 : n과 k 입력
	printf("Enter n and k ?  ");
	scanf_s("%d %d", &n, &k);

	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	//step 2 : Killing Sequence 출력 - 단, 마지막 하나는 별도로 출력
	printf("Killing Sequence   ");

	cntTry = n - 1;
	while (cntTry != 0) {	
		cntKthMove = k;
		while (cntKthMove != 0) {		// 시행 1회에서 k번 <이동>. 그런데 <이동>이란 시행은 비어있는 칸에 대해선 카운트되면 안되기에 진위확인 필요.
			current = (current + 1) % n;
			if (arr[current] != -1) {			// 값이 -1이 아니면, 정상적인 이동 -> 이를 반영하기 위해 카운트 줄임 
				cntKthMove--;
			}
		}
		printf("%d  ", arr[current]);
		arr[current] = -1;
		cntTry--;
	}
	printf("\n");

	printf("Remain   ");
	for (int j = 0; j < n; j++) {
		if (arr[j] != -1)
			printf("%d\n", arr[j]);
	}
	return 0;
}


