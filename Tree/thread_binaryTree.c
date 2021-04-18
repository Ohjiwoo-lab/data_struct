//스레드 이진 트리로 트리 순회(중위 순회) 구현

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct treeNode {
	char data;
	struct treeNode* leftchild, * rightchild;
	int isThreadRight; //후속자에 대한 스레드 태그
}treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode, int isThreadRight);
treeNode* findThreadSuccessor(treeNode* p);
void threadInorder(treeNode* root);

int main()
{
	//트리의 높이가 3인 포화 이진 트리, n1~n7이 각각 1~7로 대응되는 완전 이진트리

	//단말노드(레벨3)
	treeNode* n7 = makeRootNode('D', NULL, NULL, 0);
	treeNode* n6 = makeRootNode('C', NULL, NULL, 1); //스레드
	treeNode* n5 = makeRootNode('B', NULL, NULL, 1); //스레드
	treeNode* n4 = makeRootNode('A', NULL, NULL, 1); //스레드

	//비단말노드(레벨2)
	treeNode* n3 = makeRootNode('/', n6, n7, 0);
	treeNode* n2 = makeRootNode('*', n4, n5, 0);

	//루트노드(레벨1)
	treeNode* n1 = makeRootNode('-', n2, n3, 0);

	n4->rightchild = n2;
	n5->rightchild = n1;
	n6->rightchild = n3;

	printf("\n 스레드 이진 트리의 중위 순회 : ");
	threadInorder(n1);

	return 0;
}

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode, int isThreadRight)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->leftchild = leftNode;
	root->rightchild = rightNode;
	root->isThreadRight = isThreadRight;
	return root;
}

treeNode* findThreadSuccessor(treeNode* p)
{
	treeNode* q = p->rightchild;
	if (q == NULL) return q;
	if (p->isThreadRight == 1) return q;
	while (q->leftchild != NULL) q = q->leftchild;
	return q;
}

void threadInorder(treeNode* root)
{
	treeNode* q;
	q = root;
	while (q->leftchild)
		q = q->leftchild;
	do {
		printf("%3c", q->data);
		q = findThreadSuccessor(q);
	} while (q);
}
