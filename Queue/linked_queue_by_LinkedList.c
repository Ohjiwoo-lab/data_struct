//���Ḯ��Ʈ�� �̿��� ���� ť ����

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
	
	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n ���� B>>"); enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n ���� C>>"); enQueue(LQ, 'C'); printLQ(LQ);
		
	data = peek(LQ); printf(" peek item : %c \n", data);
	
	printf("\n ����  >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t\t���� ������ : %c", data);
	
	printf("\n ���� D>>"); enQueue(LQ, 'D'); printLQ(LQ);
	printf("\n ���� E>>"); enQueue(LQ, 'E'); printLQ(LQ);
	printf("\n ���� F>>"); enQueue(LQ, 'F'); printLQ(LQ);

	
	return 0;
}

//���� ���� ť ����
LQueueType* createLinkedQueue()
{
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

//���� �������� �˻�
int isEmpty(LQueueType* LQ)
{
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1; //�����̸� True ����
	}
	else return 0; //������ �ƴϸ� False ����
}

//���� ����
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

//���� ����
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

//���� �˻�
element peek(LQueueType* LQ)
{
	if (isEmpty(LQ)) return 0;
	else {
		return LQ->front->data;
	}
}

//���� ť ���
void printLQ(LQueueType* LQ)
{
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) //temp�� NULL�� �ƴ� ������(ť�� ���Ұ� ������ ������) �ݺ�
	{
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}
