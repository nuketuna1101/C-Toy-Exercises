#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void MineLocate(int randnum, int s, int **map) {
	int x, y;
	x = randnum / s;
	y = randnum % s;
	map[x][y] = 9;			// map이 9라는 것은 mine이라는 뜻
}

int hasMine(int x, int y, int s, int **map) {
	// x, y 좌표에 지뢰가 있는지
	// 먼저 해당 x, y좌표가 valid한 좌표인지 부터
	// 위배되면 없다고 리턴
	if (x < 0 || y < 0 || x > s - 1 || y > s - 1)
		return 0;
	// 위배 안 될 경우, 진짜 지뢰가 있는지, 있으면 1, 없으면 0
	if (map[x][y] == 9)
		return 1;
	else
		return 0;

}


int AdjacentNumb(int x, int y, int s, int **map) {
	int cnt = 0;			// cnt는 해당 위치에서 인접해있는 지뢰의 개수를 셀 것임. 초기화 0

	if (map[x][y] == 9)		// 해당 위치 자체가 지뢰일 경우, 인접을 볼 필요없이 끝내버린다.
		return 9;
	
	cnt = hasMine(x - 1, y - 1, s, map)
		+ hasMine(x - 1, y    , s, map)
		+ hasMine(x - 1, y + 1, s, map)
		+ hasMine(x    , y - 1, s, map)
		+ hasMine(x    , y + 1, s, map)
		+ hasMine(x + 1, y - 1, s, map)
		+ hasMine(x + 1, y    , s, map)
		+ hasMine(x + 1, y + 1, s, map);
	return cnt;
}

char showDisplay(int num) {
	// 0은 . 으로, 9는 @로, 그 외 숫자는 숫자로
	if (num == 0) {
		return '.';
	}
	else if (num == 9) {
		return '@';
	}
	else if (num > 0 && num < 9) {
		return '0' + num;
	}
	else
		return '!';
}


void wallDisplay(int s) {
	printf("+");
	for (int i = 0; i < s; i++) {
		printf("--");
	}
	printf("+\n");
}



int main() {

	int s, n;		// 지도 크기 s, 지뢰 개수 n
	int** map;		// map은 지도를 나타내는 이차원 배열, 동적할당 될 거임
	int* mines;		// mines는 무작위로 생성된 지뢰들의 집합을 나타낸 배열임 
	int q;			// 루프 인덱스 q
	srand(time(NULL));

	// 인트로 시작, 지도 크기와 지뢰 개수 입력받기
	printf("*** 지뢰 찾기 ***\n");
	printf("지도 크기? ");
	scanf_s("%d", &s);
	printf("지뢰 개수? ");
	scanf_s("%d", &n);

	// 입력받은 지도 크기를 통해 지도배열 이차원배열 동적할당하기
	map = (int**)malloc(sizeof(int*) * s);
	for (int i = 0; i < s; i++) {
		map[i] = (int*)malloc(sizeof(int) * s);
	}

	// map 이차원배열 값을 모두 0으로 초기화
	for (int a = 0; a < s; a++) {
		for (int b = 0; b < s; b++) {
			map[a][b] = 0;
		}
	}

	// 지뢰 개수를 토대로 난수 생성 - 생성범위는 0 ~ s*s-1
	mines = (int)malloc(sizeof(int) * n);
	mines[0] = rand() % (s * s);
	for (int j = 1; j < n; j++) {
		mines[j] = rand() % (s * s);
		while (mines[j] == mines[0]) {
			mines[j] = rand() % (s * s);
		}
	}


	// 이건 그냥 검출용 mines 출력
	printf("mines[%d] => ", n);
	for (int j = 0; j < n; j++) {
		printf("%d ", mines[j]);
	}
	printf("\n");

	// 생성된 mines 난수를 통해 지뢰 위치시키기
	for (int m = 0; m < n; m++) {
		MineLocate(mines[m], s, map);
	}


	wallDisplay(s);
	for (int c = 0; c < s; c++) {
		printf("|");
		for (int d = 0; d < s; d++) {
			printf("%c ", showDisplay(map[c][d]));
		}
		printf("|");
		printf("\n");
	}
	wallDisplay(s);
	wallDisplay(s);
	for (int e = 0; e < s; e++) {
		printf("|");
		for (int f = 0; f < s; f++) {
			printf("%c ", showDisplay(AdjacentNumb(e, f, s, map)));
		}
		printf("|");
		printf("\n");
	}
	wallDisplay(s);

	return 0;
}