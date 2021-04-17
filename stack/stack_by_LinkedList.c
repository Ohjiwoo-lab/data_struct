//연결리스트로 스택 구현

#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;

int isEmpty();
void push(element item);
element pop();
element peek();
void printStack();

int main()
{
	element item;
	top = NULL;

	printf("\n** 연결 스택 연산 **\n");
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
	if (top == NULL) return 1;
	else return 0;
}

void push(element item)
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()
{
	element item;
	stackNode* temp = top;

	if (isEmpty()) {
		printf("\n\n Stack is empty! \n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link; //top 위치를 삭제 노드 아래로 이동
		free(temp);
		return item;
	}
}

element peek()
{
	if (isEmpty()) {
		printf("\n\n Stack is empty! \n");
		return 0;
	}
	else {
		return top->data; //현재 top의 원소 반환
	}
}

void printStack()
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}
