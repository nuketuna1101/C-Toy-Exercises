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
	Node* nodemarker = (Node *)malloc(sizeof(Node));							// 작업 이뤄지는 현재 노드 지정
	Node* deletenode = (Node *)malloc(sizeof(Node));


	printf("Enter n and k ?  ");
	scanf_s("%d %d", &n, &k);


	for (int i = 0; i < n; i++) {				// 입력받은 n, k로 연결리스트 생성
		InsertNode(list, i+1);
	}
	MakeitCircular(list);

	nodemarker->link = list->head;					// 노드 마커 초기화 --- 리스트 헤더부터 가리킴


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

Linkedlist* InitList() {											// 연결리스트 초기화
	Linkedlist* newlist = (Linkedlist*)malloc(sizeof(Linkedlist));

	newlist->head = NULL;
	newlist->size = 0;

	return newlist;
}

void InsertNode(Linkedlist * list, int data) {									// 연결리스트에 노드 추가
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* currentnode = list->head;				// 헤드에서부터 탐색하기 위해 

	newnode->data = data;
	newnode->link = NULL;

	if (list->head == NULL) {			// 1) 기존 연결리스트에 노드가 없는 경우
		list->head = newnode;
	}
	else {								// 2) 기존 연결리스트에 노드가 이미 존재
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


Node* PopNode(Linkedlist * list, Node * nodemarker, int k) {							// 헤드로부터 떨어진 노드 삭제
	Node* currentnode = nodemarker;
	Node* deletenode;			// 삭제할 노드

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
