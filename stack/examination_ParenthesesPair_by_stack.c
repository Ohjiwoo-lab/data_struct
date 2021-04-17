//스택을 이용해 수식의 괄호 쌍 검사하기

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element; //스택 요소(element)의 자료형을 char로 정의

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
		printf("\n\n 수식의 괄호가 맞게 사용되었습니다! \n");
	else
		printf("\n\n 수식이 괄호가 틀렸습니다!\n");

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

int testPair(char* exp) //매개변수로 문자열(char형 포인터)을 받음
{
	char symbol, open_pair;
	int length = strlen(exp); //문자열의 길이를 계산하여 length에 저장
	top = NULL;

	for (int i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) { //문자는 아스키 값을 가짐
			//왼쪽 괄호는 스택에 삽입
		case '(':
		case '[':
		case '{':
			push(symbol); break;

			//오른쪽 괄호는 스택에서 꺼낸 왼쪽 괄호와 괄호쌍이 맞는지 비교함
		case ')':
		case ']':
		case '}':
			if (isEmpty()) return 0;
			else {
				open_pair = pop(); //가장 최근에 넣은 왼쪽 괄호 꺼냄

				if ((open_pair == '(' && symbol != ')') || (open_pair == '[' && symbol != ']') || (open_pair == '{' && symbol != '}'))
					return 0; //괄호쌍이 맞지 않는 경우

				else break; //괄호쌍이 맞는 경우
			}
		}
	}
	if (isEmpty()) return 1; //수식 검사를 마친 후 스택이 공백이면 수식 괄호가 맞으므로 1을 리턴
	else return 0; //공백이 아니면 수식 괄호가 틀렸으므로 0을 리턴
}
