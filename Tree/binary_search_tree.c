//���� Ž�� Ʈ���� ���� ���α׷�

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

	//�ʱ� Ʈ�� ����
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
			printf("\t[���� Ʈ�� ���]  ");
			displayInorder(root); printf("\n");
			break;
		case 2:
			printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			insertNode(root, key); break;
		case 3:
			printf("ã�� ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			foundedNode = searchBST(root, key); 
			if (foundedNode != NULL)
				printf("\n %c�� ã�ҽ��ϴ�! \n", foundedNode->key);
			else printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
			break;
		case 4:
			return 0;
		default:
			printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}
	}
}

void menu()
{
	printf("\n*--------------------------*");
	printf("\n\t 1 : Ʈ�� ���");
	printf("\n\t 2 : ���� ����");
	printf("\n\t 3 : ���� �˻�");
	printf("\n\t 4 : ����");
	printf("\n*--------------------------*");
	printf("\n �޴� �Է� >> ");
}

//Ž��
treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->leftchild;
		else if (x == p->key) return p;
		else p = p->rightchild;
	}
	printf("\n ã�� Ű�� �����ϴ�! ");
	return p; //NULL�� ����
}

//����
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
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;
}

//���� ��ȸ�ϸ鼭 ���
void displayInorder(treeNode* root)
{
	if (root) {
		displayInorder(root->leftchild);
		printf("%c_", root->key);
		displayInorder(root->rightchild);
	}
}
