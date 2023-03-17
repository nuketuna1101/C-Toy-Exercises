#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Linklist {
	Node* head;
	int size;
}Linkedlist;


Linkedlist* InitList();
void InsertNode(Linkedlist* list, int data);
void MakeitCircular(Linkedlist* list);
//void ViewList(Linkedlist* list);
void PopNode(Linkedlist* list, Node* nodemarker, int k);



int main() {
	int n, k;
	Linkedlist* list = InitList();
	Node* nodemarker = (Node*)malloc(sizeof(Node));							// �۾� �̷����� ���� ��� ����

	printf("Enter n and k ?  ");
	scanf_s("%d %d", &n, &k);


	for (int i = 0; i < n; i++) {				// �Է¹��� n, k�� ���Ḯ��Ʈ ����
		InsertNode(list, i + 1);
	}
	MakeitCircular(list);

	nodemarker->link = list->head;					// ��� ��Ŀ �ʱ�ȭ --- ����Ʈ ������� ����Ŵ

	//ViewList(list);

	printf("Killing sequence   \n");


	for (int j = 0; j < n - 1; j++) {
		PopNode(list, nodemarker, k);
		for (int m = 0; m < k - 1; m++) {
			nodemarker = nodemarker->link;
		}
		//ViewList(list);
	}


	printf("Remain   ");

	printf("\n");
	return 0;
}

Linkedlist* InitList() {											// ���Ḯ��Ʈ �ʱ�ȭ
	Linkedlist* newlist = (Linkedlist*)malloc(sizeof(Linkedlist));

	newlist->head = NULL;
	newlist->size = 0;

	return newlist;
}

void InsertNode(Linkedlist* list, int data) {									// ���Ḯ��Ʈ�� ��� �߰�
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* currentnode = list->head;				// ��忡������ Ž���ϱ� ���� 

	newnode->data = data;
	newnode->link = NULL;

	if (list->head == NULL) {			// 1) ���� ���Ḯ��Ʈ�� ��尡 ���� ���
		list->head = newnode;
	}
	else {								// 2) ���� ���Ḯ��Ʈ�� ��尡 �̹� ����
		while (currentnode->link != NULL) {
			currentnode = currentnode->link;
		}
		currentnode->link = newnode;
	}
	list->size++;
}

void MakeitCircular(Linkedlist* list) {
	Node* currentnode = list->head;

	if (currentnode == NULL)
		return;
	else {
		for (int i = 0; i < list->size - 1; i++) {
			currentnode = currentnode->link;
		}
		currentnode->link = list->head;
	}
}

/*
void ViewList(Linkedlist * list) {												// ������ ���Ḯ��Ʈ ���� �׽�Ʈ��
	Node* currentnode = list->head;
	do {
		printf("[ %d ]  ", currentnode->data);
		currentnode = currentnode->link;
	} while (currentnode != NULL && currentnode != list->head);
	printf("\n");
}
*/

void PopNode(Linkedlist* list, Node* nodemarker, int k) {							// ���κ��� ������ ��� ����
	Node* currentnode = nodemarker;
	Node* deletenode;
	// 3���� ���̽� - 1) �� ����Ʈ�� ��� / 2) ���� ��� ����Ʈ�� ��� / 3) 2�� �̻��� ��尡 �ִ� ����Ʈ�� ���
	/*
	if (list->head == NULL) {
		return;			// �� ����Ʈ�̸� �״�� �Լ� ����
	}

	if (k == 0) {			// ��带 ����
		printf("%d  ", (list->head)->data);
		list->head = (list->head)->link;
		free(currentnode);
		list->size--;
	}
	else {
		for (int i = 0; i < k - 1; i++) {
			currentnode = currentnode->link;
			//printf("currentnode = %d\n", currentnode->data);
		}
		deletenode = currentnode->link;
		printf("%d  ", deletenode->data);
		currentnode->link = (currentnode->link)->link;
		free(deletenode);
		list->size--;
	}
	*/
	for (int i = 0; i < k - 1; i++) {
		currentnode = currentnode->link;
	}
	deletenode = currentnode->link;
	printf("%d  ", deletenode->data);
	currentnode->link = (currentnode->link)->link;
	free(deletenode);
	list->size--;
}