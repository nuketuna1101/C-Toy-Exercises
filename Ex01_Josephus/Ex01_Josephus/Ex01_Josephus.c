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
	Node* nodemarker = (Node*)malloc(sizeof(Node));							// 작업 이뤄지는 현재 노드 지정

	printf("Enter n and k ?  ");
	scanf_s("%d %d", &n, &k);


	for (int i = 0; i < n; i++) {				// 입력받은 n, k로 연결리스트 생성
		InsertNode(list, i + 1);
	}
	MakeitCircular(list);

	nodemarker->link = list->head;					// 노드 마커 초기화 --- 리스트 헤더부터 가리킴

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

Linkedlist* InitList() {											// 연결리스트 초기화
	Linkedlist* newlist = (Linkedlist*)malloc(sizeof(Linkedlist));

	newlist->head = NULL;
	newlist->size = 0;

	return newlist;
}

void InsertNode(Linkedlist* list, int data) {									// 연결리스트에 노드 추가
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

/*
void ViewList(Linkedlist * list) {												// 생성된 연결리스트 검출 테스트용
	Node* currentnode = list->head;
	do {
		printf("[ %d ]  ", currentnode->data);
		currentnode = currentnode->link;
	} while (currentnode != NULL && currentnode != list->head);
	printf("\n");
}
*/

void PopNode(Linkedlist* list, Node* nodemarker, int k) {							// 헤드로부터 떨어진 노드 삭제
	Node* currentnode = nodemarker;
	Node* deletenode;
	// 3가지 케이스 - 1) 공 리스트인 경우 / 2) 단일 노드 리스트인 경우 / 3) 2개 이상의 노드가 있는 리스트인 경우
	/*
	if (list->head == NULL) {
		return;			// 공 리스트이면 그대로 함수 종료
	}

	if (k == 0) {			// 헤드를 제거
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