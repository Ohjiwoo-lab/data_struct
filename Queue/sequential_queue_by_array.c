//��������Ʈ�� ���� ť ����

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

	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n ���� B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n ���� C>>"); enQueue(Q1, 'C'); printQ(Q1);
	
	data = peek(Q1); printf(" peek item : %c \n", data);

	printf("\n ����  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t\t���� ������ : %c", data);

	printf("\n ���� D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n ���� E>>"); enQueue(Q1, 'E'); printQ(Q1);

	return 0;
}

//���� ���� ť ����
QueueType* createQueue()
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

//�������� �˻�
int isEmpty(QueueType* Q)
{
	if (Q->front == Q->rear) {
		printf(" Queue is empty! ");
		return 1; //�����̸� True ����
	}
	else return 0; //������ �ƴϸ� False ����
}

//��ȭ�������� �˻�
int isFull(QueueType* Q)
{
	if (Q->rear == Q_SIZE - 1) {
		printf(" Queue is full! ");
		return 1; //��ȭ�� True ����
	}
	else return 0; //��ȭ�� �ƴϸ� False ����
}

//���� ����
void enQueue(QueueType* Q, element item)
{
	if (isFull(Q)) return;
	else {
		Q->queue[++Q->rear] = item;
	}
}

//���� ���� �� ��ȯ
element deQueue(QueueType* Q)
{
	if (isEmpty(Q)) return;
	else return Q->queue[++Q->front]; //front�� ������Ų �� ��ȯ
}

//���� �˻�
element peek(QueueType* Q)
{
	if (isEmpty(Q)) exit(1);
	else return Q->queue[Q->front + 1]; //front�� ������ ������Ű�� ����
}

//ť ���
void printQ(QueueType* Q)
{
	printf(" Queue : [");
	for (int i = Q->front + 1; i <= Q->rear; i++) {
		printf("%3c", Q->queue[i]);
	}
	printf(" ]");
}
