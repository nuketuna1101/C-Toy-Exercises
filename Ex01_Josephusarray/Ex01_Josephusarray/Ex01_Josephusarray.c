#include <stdio.h>
#include <stdlib.h>

void doKthMove(int cntKthMove, int n, int k, int current, int* arr);

int main() {
	int n, k;			// �Է� ����
	int* arr;			// arr�� n ũ���� �迭, �ش� ���� 1 ~ n�� ����. ���� pop�� �ÿ� -1 ������ ����
	int cntKthMove;			// cnt�� ī���ͺ���, ų������������ �ݺ����� ����
	int current = -1;		// current�� ų������������ ���� ����Ű�� ��ġ �ε����� ����
	int cntTry;				// ������ Ƚ���� n-1�� �ؾ���

	//step 1 : n�� k �Է�
	printf("Enter n and k ?  ");
	scanf_s("%d %d", &n, &k);

	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	//step 2 : Killing Sequence ��� - ��, ������ �ϳ��� ������ ���
	printf("Killing Sequence   ");

	cntTry = n - 1;
	while (cntTry != 0) {	
		cntKthMove = k;
		while (cntKthMove != 0) {		// ���� 1ȸ���� k�� <�̵�>. �׷��� <�̵�>�̶� ������ ����ִ� ĭ�� ���ؼ� ī��Ʈ�Ǹ� �ȵǱ⿡ ����Ȯ�� �ʿ�.
			current = (current + 1) % n;
			if (arr[current] != -1) {			// ���� -1�� �ƴϸ�, �������� �̵� -> �̸� �ݿ��ϱ� ���� ī��Ʈ ���� 
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


