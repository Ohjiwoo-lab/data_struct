//선형리스트로 스택 구현
 
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE]; //1차원 배열 스택 선언
int top = -1; //top 초기화

int isEmpty();
int isFull();
void push(element item);
element pop();
element peek();
void printStack();

int main()
{
	element item;
	printf("\n** 순차 스택 연산 **\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek => %d", item); //현재 top에 있는 아이템

	item = pop(); printStack(); //삭제
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	return 0;
}

int isEmpty()
{
	if (top == -1) return 1; //stack이 초기상태(빈 상태)
	else return 0;
}

int isFull()
{
	if (top == STACK_SIZE - 1) return 1; //스택이 마지막 인덱스까지 꽉 차있음
	else return 0;
}

void push(element item)
{
	if (isFull()) {
		printf("\n\n Stack is Full! \n");
		return;
	}
	else stack[++top] = item; //top을 증가시킨 후 top에 원소 삽입
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
	else return stack[top]; //현재 top의 원소를 확인
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
