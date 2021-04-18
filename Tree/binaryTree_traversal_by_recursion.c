//����Լ��� �̿��� ����Ʈ�� ��ȸ

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
	//Ʈ���� ���̰� 3�� ��ȭ ���� Ʈ��, n1~n7�� ���� 1~7�� �����Ǵ� ���� ����Ʈ��

	//�ܸ����(����3)
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	
	//��ܸ����(����2)
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);

	//��Ʈ���(����1)
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("\n preorder : ");
	preorder(n1);

	printf("\n inorder : ");
	inorder(n1);

	printf("\n postorder : ");
	postorder(n1);

	return 0;
}

//data�� ��Ʈ���� �Ͽ� ���� ����Ʈ���� ������ ����Ʈ�� ����
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->leftchild = leftNode;
	root->rightchild = rightNode;
	return root;
}

//���� ��ȸ
void preorder(treeNode* root)
{
	if (root) //tree�� NULL�� �ƴѵ���
	{
		printf("%c", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}

//���� ��ȸ
void inorder(treeNode* root)
{
	if (root) //tree�� NULL�� �ƴѵ���
	{
		inorder(root->leftchild);
		printf("%c", root->data);
		inorder(root->rightchild);
	}
}

//���� ��ȸ
void postorder(treeNode* root)
{
	if (root) //tree�� NULL�� �ƴѵ���
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%c", root->data);
	}
}
