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


	// ��ǥ ���� ���� - �ߺ� ���� �� �ڸ�
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



	// ��Ʈ�� �޽��� ����
	printf("<<< ���ھ߱� ���� >>>\n");
	printf("�� �ڸ� ���ڸ� �Է��Ͻÿ�. (0 = ����)\n");

	printf("\t\t�����ڸ��: ���� %d%d%d%d\n", target[0], target[1], target[2], target[3]);


	while (1) {
		// �Է� �޾Ƽ� �Ҵ����ֱ�
		printf("%d��° �õ�: ", try);
		scanf_s("%d", &input);
		// �������� 1 - 0 �Է�
		if (input == 0) {
			printf("������ �����Ͽ����ϴ�.\n");
			printf("������ %d%d%d%d �Դϴ�.\n", target[0], target[1], target[2], target[3]);
			break;
		}
		// �������� �Է� ���� ó�� - �Է� ���� ���� ���� digit�̶� �Է� �迭�� ����
		for (int j = 0; j < 4; j++) {
			digit[3 - j] = input % 10;
			input /= 10;
		}
		// �Է¿� ����, S�� B ���! - �Լ� ���� ����
		Strikenum = Strike(target, digit);
		Ballnum = Ball(target, digit);
		printf("%d%d%d%d is %dS %dB\n", digit[0], digit[1], digit[2], digit[3], Strikenum, Ballnum);

		// �������� 2 - ���� 
		if (Strikenum == 4) {
			printf("�����մϴ�.\n");
			printf("������ ������ϴ�.\n");
			break;
		}

		// �������� 3 - 10���� ��ȸ ��� ���, ����
		if (try == 10) {
			printf("�� �̻� ��ȸ�� �����ϴ�.\n");
			printf("������ %d%d%d%d �Դϴ�.\n", target[0], target[1], target[2], target[3]);
			break;
		}
		// ����Ƚ�� ����
		try++;
	}


	return 0;
}

