//선형리스트로 순차 큐 구현

#include<stdio.h>
#include<stdlib.h>
#define Q_SIZE 4

typedef char element;
typedef struct {
	element queue[Q_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue();
int isEmpty(QueueType* Q);
int isFull(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQueue(QueueType* Q);
element peek(QueueType* Q);
void printQ(QueueType* Q);

int main()
{
	QueueType* Q1 = createQueue();
	element data;

	printf("\n ***** 순차 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n 삽입 B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n 삽입 C>>"); enQueue(Q1, 'C'); printQ(Q1);
	
	data = peek(Q1); printf(" peek item : %c \n", data);

	printf("\n 삭제  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t\t삭제 데이터 : %c", data);

	printf("\n 삽입 D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n 삽입 E>>"); enQueue(Q1, 'E'); printQ(Q1);

	return 0;
}

//공백 순차 큐 생성
QueueType* createQueue()
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

//공백인지 검사
int isEmpty(QueueType* Q)
{
	if (Q->front == Q->rear) {
		printf(" Queue is empty! ");
		return 1; //공백이면 True 리턴
	}
	else return 0; //공백이 아니면 False 리턴
}

//포화상태인지 검사
int isFull(QueueType* Q)
{
	if (Q->rear == Q_SIZE - 1) {
		printf(" Queue is full! ");
		return 1; //포화면 True 리턴
	}
	else return 0; //포화가 아니면 False 리턴
}

//원소 삽입
void enQueue(QueueType* Q, element item)
{
	if (isFull(Q)) return;
	else {
		Q->queue[++Q->rear] = item;
	}
}

//원소 삭제 후 반환
element deQueue(QueueType* Q)
{
	if (isEmpty(Q)) return;
	else return Q->queue[++Q->front]; //front를 증가시킨 후 반환
}

//원소 검색
element peek(QueueType* Q)
{
	if (isEmpty(Q)) exit(1);
	else return Q->queue[Q->front + 1]; //front를 실제로 증가시키지 않음
}

//큐 출력
void printQ(QueueType* Q)
{
	printf(" Queue : [");
	for (int i = Q->front + 1; i <= Q->rear; i++) {
		printf("%3c", Q->queue[i]);
	}
	printf(" ]");
}
