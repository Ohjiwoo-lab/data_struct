//재귀함수를 이용한 이진트리 순회

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct treeNode {
	char data;
	struct treeNode* leftchild, * rightchild;
}treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode);
void preorder(treeNode* root);
void inorder(treeNode* root);
void postorder(treeNode* root);


int main()
{
	//트리의 높이가 3인 포화 이진 트리, n1~n7이 각각 1~7로 대응되는 완전 이진트리

	//단말노드(레벨3)
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	
	//비단말노드(레벨2)
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);

	//루트노드(레벨1)
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("\n preorder : ");
	preorder(n1);

	printf("\n inorder : ");
	inorder(n1);

	printf("\n postorder : ");
	postorder(n1);

	return 0;
}

//data를 루트노드로 하여 왼쪽 서브트리와 오른쪽 서브트리 연결
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->leftchild = leftNode;
	root->rightchild = rightNode;
	return root;
}

//전위 순회
void preorder(treeNode* root)
{
	if (root) //tree가 NULL이 아닌동안
	{
		printf("%c", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}

//중위 순회
void inorder(treeNode* root)
{
	if (root) //tree가 NULL이 아닌동안
	{
		inorder(root->leftchild);
		printf("%c", root->data);
		inorder(root->rightchild);
	}
}

//후위 순회
void postorder(treeNode* root)
{
	if (root) //tree가 NULL이 아닌동안
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%c", root->data);
	}
}
