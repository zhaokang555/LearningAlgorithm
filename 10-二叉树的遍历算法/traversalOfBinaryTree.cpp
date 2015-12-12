#include <iostream>

const int MaxSize = 100;

typedef struct BTNode {
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode;

void visit(BTNode *tree)
{
	std::cout << tree -> data;
	return;
}

void preOrder(BTNode *tree)
{
	if (tree != NULL) {
		visit(tree);
		preOrder(tree -> lchild);
		preOrder(tree -> rchild);
	}
}

void inOrder(BTNode *tree)
{
	if (tree != NULL) {
		inOrder(tree -> lchild);
		visit(tree);
		inOrder(tree -> rchild);
	}
}

void postOrder(BTNode *tree)
{
	if (tree != NULL) {
		postOrder(tree -> lchild);
		postOrder(tree -> rchild);
		visit(tree);
	}
}

void levelOrder(BTNode *tree)
{
	// 定义一个循环队列que
	BTNode *que[MaxSize];
	int front = 0, rear = 0; 

	if (tree != NULL) {
		// 根节点入队
		rear = (rear + 1) % MaxSize;
		que[rear] = tree; 

		while (front != rear) {
			front = (front + 1) % MaxSize; // 队头结点出队
			BTNode *tempNode = que[front]; // 将刚刚出队的这个节点记为tempNode
			visit(tempNode);

			if (tempNode -> lchild != NULL){ // 如果tempNode 的左子树不空，则左子树的根节点入队
				rear = (rear + 1) % MaxSize;
				que[rear] = tempNode -> lchild;
			}

			if (tempNode -> rchild != NULL){
				rear = (rear + 1) % MaxSize;
				que[rear] = tempNode -> rchild;
			}
		}
	}
}