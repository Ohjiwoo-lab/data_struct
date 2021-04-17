//������ �̿��� ������ ��ȣ �� �˻��ϱ�

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element; //���� ���(element)�� �ڷ����� char�� ����

typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;

int isEmpty();
void push(element item);
element pop();
int testPair(char* exp);

int main()
{
	char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);

	if (testPair(express) == 1)
		printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�! \n");
	else
		printf("\n\n ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");

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

int testPair(char* exp) //�Ű������� ���ڿ�(char�� ������)�� ����
{
	char symbol, open_pair;
	int length = strlen(exp); //���ڿ��� ���̸� ����Ͽ� length�� ����
	top = NULL;

	for (int i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) { //���ڴ� �ƽ�Ű ���� ����
			//���� ��ȣ�� ���ÿ� ����
		case '(':
		case '[':
		case '{':
			push(symbol); break;

			//������ ��ȣ�� ���ÿ��� ���� ���� ��ȣ�� ��ȣ���� �´��� ����
		case ')':
		case ']':
		case '}':
			if (isEmpty()) return 0;
			else {
				open_pair = pop(); //���� �ֱٿ� ���� ���� ��ȣ ����

				if ((open_pair == '(' && symbol != ')') || (open_pair == '[' && symbol != ']') || (open_pair == '{' && symbol != '}'))
					return 0; //��ȣ���� ���� �ʴ� ���

				else break; //��ȣ���� �´� ���
			}
		}
	}
	if (isEmpty()) return 1; //���� �˻縦 ��ģ �� ������ �����̸� ���� ��ȣ�� �����Ƿ� 1�� ����
	else return 0; //������ �ƴϸ� ���� ��ȣ�� Ʋ�����Ƿ� 0�� ����
}
