//���Ḯ��Ʈ�� ���� ����

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
		top = temp->link; //top ��ġ�� ���� ��� �Ʒ��� �̵�
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
		return top->data; //���� top�� ���� ��ȯ
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
