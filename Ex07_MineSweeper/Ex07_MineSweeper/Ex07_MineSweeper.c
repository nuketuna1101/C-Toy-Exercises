#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void MineLocate(int randnum, int s, int **map) {
	int x, y;
	x = randnum / s;
	y = randnum % s;
	map[x][y] = 9;			// map�� 9��� ���� mine�̶�� ��
}

int hasMine(int x, int y, int s, int **map) {
	// x, y ��ǥ�� ���ڰ� �ִ���
	// ���� �ش� x, y��ǥ�� valid�� ��ǥ���� ����
	// ����Ǹ� ���ٰ� ����
	if (x < 0 || y < 0 || x > s - 1 || y > s - 1)
		return 0;
	// ���� �� �� ���, ��¥ ���ڰ� �ִ���, ������ 1, ������ 0
	if (map[x][y] == 9)
		return 1;
	else
		return 0;

}


int AdjacentNumb(int x, int y, int s, int **map) {
	int cnt = 0;			// cnt�� �ش� ��ġ���� �������ִ� ������ ������ �� ����. �ʱ�ȭ 0

	if (map[x][y] == 9)		// �ش� ��ġ ��ü�� ������ ���, ������ �� �ʿ���� ����������.
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
	// 0�� . ����, 9�� @��, �� �� ���ڴ� ���ڷ�
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

	int s, n;		// ���� ũ�� s, ���� ���� n
	int** map;		// map�� ������ ��Ÿ���� ������ �迭, �����Ҵ� �� ����
	int* mines;		// mines�� �������� ������ ���ڵ��� ������ ��Ÿ�� �迭�� 
	int q;			// ���� �ε��� q
	srand(time(NULL));

	// ��Ʈ�� ����, ���� ũ��� ���� ���� �Է¹ޱ�
	printf("*** ���� ã�� ***\n");
	printf("���� ũ��? ");
	scanf_s("%d", &s);
	printf("���� ����? ");
	scanf_s("%d", &n);

	// �Է¹��� ���� ũ�⸦ ���� �����迭 �������迭 �����Ҵ��ϱ�
	map = (int**)malloc(sizeof(int*) * s);
	for (int i = 0; i < s; i++) {
		map[i] = (int*)malloc(sizeof(int) * s);
	}

	// map �������迭 ���� ��� 0���� �ʱ�ȭ
	for (int a = 0; a < s; a++) {
		for (int b = 0; b < s; b++) {
			map[a][b] = 0;
		}
	}

	// ���� ������ ���� ���� ���� - ���������� 0 ~ s*s-1
	mines = (int)malloc(sizeof(int) * n);
	mines[0] = rand() % (s * s);
	for (int j = 1; j < n; j++) {
		mines[j] = rand() % (s * s);
		while (mines[j] == mines[0]) {
			mines[j] = rand() % (s * s);
		}
	}


	// �̰� �׳� ����� mines ���
	printf("mines[%d] => ", n);
	for (int j = 0; j < n; j++) {
		printf("%d ", mines[j]);
	}
	printf("\n");

	// ������ mines ������ ���� ���� ��ġ��Ű��
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