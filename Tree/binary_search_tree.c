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
			return 0;
		default:
			printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}
	}
}

void menu()
{
	printf("\n*--------------------------*");
	printf("\n\t 1 : 트리 출력");
	printf("\n\t 2 : 문자 삽입");
	printf("\n\t 3 : 문자 검색");
	printf("\n\t 4 : 종료");
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

//중위 순회하면서 출력
void displayInorder(treeNode* root)
{
	if (root) {
		displayInorder(root->leftchild);
		printf("%c_", root->key);
		displayInorder(root->rightchild);
	}
}
