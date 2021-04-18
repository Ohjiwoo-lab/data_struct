//이진 탐색 트리의 연산 프로그램

#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct treeNode {
	char key;
	struct treeNode* leftchild, * rightchild;
}treeNode;

void menu();
treeNode* searchBST(treeNode* root, char x);
treeNode* insertNode(treeNode* p, char x);
void deleteNode(treeNode* root, element key);
void displayInorder(treeNode* root);

int main()
{
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char key;
	int choice;

	//초기 트리 세팅
	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');

	while (1) {
		menu();
		scanf(" %d", &choice);

		switch (choice) {
		case 1:
			printf("\t[이진 트리 출력]  ");
			displayInorder(root); printf("\n");
			break;

		case 2:
			printf("삽입할 문자를 입력하세요 : ");
			scanf(" %c", &key);
			insertNode(root, key); break;

		case 3:
			printf("찾을 문자를 입력하세요 : ");
			scanf(" %c", &key);
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL)
				printf("\n %c를 찾았습니다! \n", foundedNode->key);
			else printf("\n 문자를 찾지 못했습니다. \n");
			break;

		case 4:
			printf("삭제할 문자를 입력하세요 : ");
			scanf(" %c", &key);
			deleteNode(root, key); break;

		case 5:
			return 0;

		default:
			printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}
	}
	return 0;
}

void menu()
{
	printf("\n*--------------------------*");
	printf("\n\t 1 : 트리 출력");
	printf("\n\t 2 : 문자 삽입");
	printf("\n\t 3 : 문자 검색");
	printf("\n\t 4 : 문자 삭제");
	printf("\n\t 5 : 종료");
	printf("\n*--------------------------*");
	printf("\n 메뉴 입력 >> ");
}

//탐색
treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->leftchild;
		else if (x == p->key) return p;
		else p = p->rightchild;
	}
	printf("\n 찾는 키가 없습니다! ");
	return p; //NULL을 리턴
}

//삽입
treeNode* insertNode(treeNode* p, char x)
{
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->leftchild = NULL;
		newNode->rightchild = NULL;
		return newNode;
	}
	else if (x < p->key) p->leftchild = insertNode(p->leftchild, x);
	else if (x > p->key) p->rightchild = insertNode(p->rightchild, x);
	else printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

//삭제
void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;

	//삭제할 노드의 위치 탐색
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key) p = p->leftchild;
		else p = p->rightchild;
	}

	//p가 NULL이어서 while 루프 탈출
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!! ");
		return;
	}

	//key의 위치를 찾음

	//1. 삭제할 노드가 단말 노드인 경우
	if ((p->leftchild == NULL) && (p->rightchild == NULL)) {
		if (parent != NULL) {
			if (parent->leftchild == p) parent->leftchild = NULL;
			else parent->rightchild = NULL;
		}
		else root = NULL; //삭제할 노드가 자식노드가 없는 root 노드(한개의 노드만 존재)
	}

	//2. 삭제할 노드가 자식 노드를 한 개 가지는 경우
	else if ((p->leftchild == NULL) || (p->rightchild == NULL)) {
		//p의 자식노드를 child에 넣음
		if (p->leftchild != NULL) child = p->leftchild;
		else child = p->rightchild;

		if (parent != NULL) {
			if (parent->leftchild == p) parent->leftchild = child;
			else parent->rightchild = child;
		}
		else root = child; //삭제할 노드가 루트 노드인 경우(자식 노드 하나를 root로 만듦)
	}

	//3. 삭제할 노드가 자식 노드를 두 개 가지는 경우
	else {
		succ_parent = p;

		//왼쪽 서브 트리에서 후계자 찾기(왼쪽 서브 트리에서 가장 큰 값 찾기)
		succ = p->leftchild;
		while (succ->rightchild != NULL) //큰 값을 찾아야하므로 오른쪽 서브 트리 탐색
		{
			succ_parent = succ;
			succ = succ->rightchild;
		}
		if (succ_parent->leftchild == succ) succ_parent->leftchild = succ->leftchild;
		else succ_parent->rightchild = succ->leftchild;

		p->key = succ->key;
		p = succ;
	}
	free(p);
}

//중위 순회하면서 출력
void displayInorder(treeNode* root)
{
	if (root) {
		displayInorder(root->leftchild);
		printf("%c_", root->key);
		displayInorder(root->rightchild);
	}
}
