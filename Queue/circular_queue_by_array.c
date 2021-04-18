//선형리스트를 이용한 원형 큐 구현

#include<stdio.h>
#include<stdlib.h>
#define cQ_SIZE 4

typedef char element;
typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue();
int isEmpty(QueueType* cQ);
int isFull(QueueType* cQ);
void enQueue(QueueType* cQ, element item);
element deQueue(QueueType* cQ);
element peek(QueueType* cQ);
void printQ(QueueType* cQ);

int main()
{
	QueueType* cQ = createQueue();
	element data;

	printf("\n ***** 순차 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n 삽입 B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n 삽입 C>>"); enQueue(cQ, 'C'); printQ(cQ);
	
	data = peek(cQ); printf(" peek item : %c \n", data);

	printf("\n 삭제  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t\t삭제 데이터 : %c", data);

	printf("\n 삽입 D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n 삽입 E>>"); enQueue(cQ, 'E'); printQ(cQ);

	return 0;
}

//공백 순차 큐 생성
QueueType* createQueue()
{
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

//공백인지 검사
int isEmpty(QueueType* cQ)
{
	if (cQ->front == cQ->rear) {
		printf(" Circular Queue is empty! ");
		return 1; //공백이면 True 리턴
	}
	else return 0; //공백이 아니면 False 리턴
}

//포화상태인지 검사
int isFull(QueueType* cQ)
{
	if (((cQ->rear+1) % cQ_SIZE) == cQ->front) {
		printf(" Circular Queue is full! ");
		return 1; //포화면 True 리턴
	}
	else return 0; //포화가 아니면 False 리턴
}

//원소 삽입
void enQueue(QueueType* cQ, element item)
{
	if (isFull(cQ)) return;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

//원소 삭제 후 반환
element deQueue(QueueType* cQ)
{
	if (isEmpty(cQ)) return;
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front]; //front를 증가시킨 후 반환
	}
}

//원소 검색
element peek(QueueType* cQ)
{
	if (isEmpty(cQ)) exit(1);
	else return cQ->queue[(cQ->front + 1)%cQ_SIZE]; //front를 실제로 증가시키지 않음
}

//큐 출력
void printQ(QueueType* cQ)
{
	int first, last;
	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;

	printf(" Circular Queue : [");
	for (int i = first; i != last; i = ((i + 1) % cQ_SIZE)) {
		printf("%3c", cQ->queue[i]);
	}
	printf(" ]");
}
