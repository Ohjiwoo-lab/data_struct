//��������Ʈ�� �̿��� ���� ť ����

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

	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n ���� B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n ���� C>>"); enQueue(cQ, 'C'); printQ(cQ);
	
	data = peek(cQ); printf(" peek item : %c \n", data);

	printf("\n ����  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t\t���� ������ : %c", data);

	printf("\n ���� D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n ���� E>>"); enQueue(cQ, 'E'); printQ(cQ);

	return 0;
}

//���� ���� ť ����
QueueType* createQueue()
{
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

//�������� �˻�
int isEmpty(QueueType* cQ)
{
	if (cQ->front == cQ->rear) {
		printf(" Circular Queue is empty! ");
		return 1; //�����̸� True ����
	}
	else return 0; //������ �ƴϸ� False ����
}

//��ȭ�������� �˻�
int isFull(QueueType* cQ)
{
	if (((cQ->rear+1) % cQ_SIZE) == cQ->front) {
		printf(" Circular Queue is full! ");
		return 1; //��ȭ�� True ����
	}
	else return 0; //��ȭ�� �ƴϸ� False ����
}

//���� ����
void enQueue(QueueType* cQ, element item)
{
	if (isFull(cQ)) return;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

//���� ���� �� ��ȯ
element deQueue(QueueType* cQ)
{
	if (isEmpty(cQ)) return;
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front]; //front�� ������Ų �� ��ȯ
	}
}

//���� �˻�
element peek(QueueType* cQ)
{
	if (isEmpty(cQ)) exit(1);
	else return cQ->queue[(cQ->front + 1)%cQ_SIZE]; //front�� ������ ������Ű�� ����
}

//ť ���
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