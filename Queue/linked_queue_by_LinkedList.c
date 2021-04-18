//연결리스트를 이용한 연결 큐 구현

#include<stdio.h>
#include<malloc.h>

typedef char element;
typedef struct QNode {
	element data;
	struct QNode* link;
}QNode;

typedef struct {
	QNode* front;
	QNode* rear;
}LQueueType;

LQueueType* createLinkedQueue();
int isEmpty(LQueueType* LQ);
void enQueue(LQueueType* LQ, element item);
element deQueue(LQueueType* LQ);
element peek(LQueueType* LQ);
void printLQ(LQueueType* LQ);

int main()
{
	LQueueType* LQ = createLinkedQueue();
	element data;
	
	printf("\n ***** 순차 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n 삽입 B>>"); enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n 삽입 C>>"); enQueue(LQ, 'C'); printLQ(LQ);
		
	data = peek(LQ); printf(" peek item : %c \n", data);
	
	printf("\n 삭제  >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t\t삭제 데이터 : %c", data);
	
	printf("\n 삽입 D>>"); enQueue(LQ, 'D'); printLQ(LQ);
	printf("\n 삽입 E>>"); enQueue(LQ, 'E'); printLQ(LQ);
	printf("\n 삽입 F>>"); enQueue(LQ, 'F'); printLQ(LQ);

	
	return 0;
}

//공백 연결 큐 생성
LQueueType* createLinkedQueue()
{
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

//공백 상태인지 검사
int isEmpty(LQueueType* LQ)
{
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1; //공백이면 True 리턴
	}
	else return 0; //공백이 아니면 False 리턴
}

//원소 삽입
void enQueue(LQueueType* LQ, element item)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

//원소 삭제
element deQueue(LQueueType* LQ)
{
	QNode* old = LQ->front;
	element item;

	if (isEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

//원소 검색
element peek(LQueueType* LQ)
{
	if (isEmpty(LQ)) return 0;
	else {
		return LQ->front->data;
	}
}

//연결 큐 출력
void printLQ(LQueueType* LQ)
{
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) //temp가 NULL이 아닐 때까지(큐에 원소가 존재할 때까지) 반복
	{
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}
