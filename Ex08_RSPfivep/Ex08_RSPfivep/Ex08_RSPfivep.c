#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* NumToRSP(int num) {
	// ���� �����ڵ带 ���� ����, ����, ���� ��ȯ�Ͽ� ��ȯ���ִ� �Լ�
	if (num == 1)
		return "����";
	else if (num == 2)
		return "����";
	else if (num == 3)
		return "��";
}


char* NumToPlayer(int num) {
	// ���� �����ڵ带 ����, A, B, C, D, User�� ��ȯ�Ͽ� ��ȯ
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
	// ���� �����ؼ�, �̱�� ���� �ɺ��� ��ȯ������!
	// ��� ��� 4�� ��ȯ����
	// ������? ����, ����, ���� ������ ���� �Ǵ�����!
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

	printf("���ڴ� ");
	for (int i = 0; i < 5; i++) {
		if (numcode[i] == winSymbol) {
			printf("%s ", NumToPlayer(i));
		}
	}
	printf("�Դϴ�.\n");
}



int main() {
	// ������ �����ڵ�, ���ڿ��� �ɺ� ��� ���ڿ�
	int numcode[5];
	char* sym[5];
	int winners[5] = {0, };
	int winSymbol;
	srand(time(NULL));


	while (1) {
		// ��Ʈ�� �ؽ�Ʈ ���, ���� �Է� �ޱ�, escape �ڵ� 0 �Է� �� Ż��
		printf("����(1)-����(2)-��(3)? ");
		scanf_s("%d", &numcode[4]);
		if (numcode[4] == 0) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		// ��ǻ�� A,B,C,D�� ���� ����, ������ 5�� �ɺ� ���
		for (int i = 0; i < 4; i++) {
			numcode[i] = rand() % 3 + 1;
		}
		for (int j = 0; j < 5; j++) {
			sym[j] = NumToRSP(numcode[j]);
		}
		printf("A:%s B:%s C:%s D:%s User:%s \n", sym[0], sym[1], sym[2], sym[3], sym[4]);
		// ���� ��� ���� �ؽ�Ʈ ���
		winSymbol = WinnerRSP(numcode);
		if (winSymbol == 4) {
			printf("�����ϴ�.\n");
		}
		else {
			printWinners(numcode, winSymbol);
		}
	}

	return 0;
}
