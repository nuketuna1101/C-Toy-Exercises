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
Node* PopNode(Linkedlist* list, Node* nodemarker, int k);


int main() {
	int n, k;
	Linkedlist* list = InitList();
	Node* nodemarker = (Node *)malloc(sizeof(Node));							// �۾� �̷����� ���� ��� ����
	Node* deletenode = (Node *)malloc(sizeof(Node));


	printf("Enter n and k ?  ");
	scanf_s("%d %d", &n, &k);


	for (int i = 0; i < n; i++) {				// �Է¹��� n, k�� ���Ḯ��Ʈ ����
		InsertNode(list, i+1);
	}
	MakeitCircular(list);

	nodemarker->link = list->head;					// ��� ��Ŀ �ʱ�ȭ --- ����Ʈ ������� ����Ŵ


	printf("Killing sequence   \n");


	
	for (int j = 0; j < n - 1; j++) {
		nodemarker = PopNode(list, nodemarker, k);
	}
	printf("\n");

	printf("Remain   ");
	printf("%d\n", list->head->data); 
	printf("\n");
	return 0;
}

Linkedlist* InitList() {											// ���Ḯ��Ʈ �ʱ�ȭ
	Linkedlist* newlist = (Linkedlist*)malloc(sizeof(Linkedlist));

	newlist->head = NULL;
	newlist->size = 0;

	return newlist;
}

void InsertNode(Linkedlist * list, int data) {									// ���Ḯ��Ʈ�� ��� �߰�
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


Node* PopNode(Linkedlist * list, Node * nodemarker, int k) {							// ���κ��� ������ ��� ����
	Node* currentnode = nodemarker;
	Node* deletenode;			// ������ ���

	for (int i = 0; i < k - 1; i++) {
		currentnode = currentnode->link;
	}
	deletenode = currentnode->link;
	printf("%d  ", deletenode->data);
	if (deletenode == list->head) {
		list->head = (currentnode->link)->link;
	}
	currentnode->link = (currentnode->link)->link;
	free(deletenode);
	list->size--;

	return currentnode;
}
