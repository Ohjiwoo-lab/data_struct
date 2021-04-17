//��������Ʈ�� ���� ����
 
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE]; //1���� �迭 ���� ����
int top = -1; //top �ʱ�ȭ

int isEmpty();
int isFull();
void push(element item);
element pop();
element peek();
void printStack();

int main()
{
	element item;
	printf("\n** ���� ���� ���� **\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek => %d", item); //���� top�� �ִ� ������

	item = pop(); printStack(); //����
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	return 0;
}

int isEmpty()
{
	if (top == -1) return 1; //stack�� �ʱ����(�� ����)
	else return 0;
}

int isFull()
{
	if (top == STACK_SIZE - 1) return 1; //������ ������ �ε������� �� ������
	else return 0;
}

void push(element item)
{
	if (isFull()) {
		printf("\n\n Stack is Full! \n");
		return;
	}
	else stack[++top] = item; //top�� ������Ų �� top�� ���� ����
}

element pop()
{
	if (isEmpty()) {
		printf("\n\n Stack is Empty!! \n");
		return 0;
	}
	else return stack[top--];
}

element peek()
{
	if (isEmpty()) {
		printf("\n\n Stack is Empty!! \n");
		exit(1);
	}
	else return stack[top]; //���� top�� ���Ҹ� Ȯ��
}

void printStack()
{
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf("] ");
}
