#include <cstdlib>

typedef struct LinkedNode
{
	int data;
	struct LinkedNode *next;
} LinkedNode;

// 将两个升序链表A和B 按照升序归并（尾插法）
void merge(LinkedNode *ListA, LinkedNode *ListB, LinkedNode *&newList)
{
	// 创建新链表的头结点
	newList = (LinkedNode *)malloc(sizeof(LinkedNode));
	newList -> next = NULL;
	// 新建一个指针rearOfNewList 来跟踪新链表的末端节点
	LinkedNode *rearOfNewList = newList;

	// 新建两个指针 frontA frontB 来跟踪两个链表AB的第一个节点。
	LinkedNode *frontA = ListA -> next;
	LinkedNode *frontB = ListB -> next;
	// 释放掉两个链表AB的头结点
	free(ListA); free(ListB);
	
	// 当两个链表都不为空时循环
	while (frontA != NULL && frontB != NULL) {
		// ====================尾插法========================
		// 取 较小的数据 所在的节点，放入新链表中
		if (frontA -> data <= frontB -> data) {
			rearOfNewList -> next = frontA;	
			frontA = frontA -> next;
		} else {
			rearOfNewList -> next = frontB;	
			frontB = frontB -> next;
		}
		// 新链表的末端指针后移一位
		rearOfNewList = rearOfNewList -> next; 
		// ====================尾插法========================
	}

	// 如果某个链表还有剩余的话，将其链接在新链表的尾部。以下两个if语句最多执行一个
	if (frontA != NULL) 
		rearOfNewList -> next = frontA;
	if (frontB != NULL) 
		rearOfNewList -> next = frontB;
}

// 将两个升序链表A和B 按照降序归并（头插法）
void mergeInOppositeOrder(LinkedNode *ListA, LinkedNode *ListB, LinkedNode *&newList)
{
	// 创建新链表的头结点
	newList = (LinkedNode *)malloc(sizeof(LinkedNode));
	newList -> next = NULL;

	// 新建两个指针 frontA frontB 来跟踪两个链表AB的第一个节点。
	LinkedNode *frontA = ListA -> next;
	LinkedNode *frontB = ListB -> next;
	// 释放掉两个链表AB的头结点
	free(ListA); free(ListB);

	// 当两个链表都不为空时循环
	while (frontA != NULL && frontB != NULL) {
		// 取 较小的数据 所在的节点，放入新链表中
		if (frontA -> data <= frontB -> data) {
			// 头插
			frontA -> next = newList -> next;
			newList -> next = frontA;

			frontA = frontA -> next;
		} else {
			// 头插
			frontB -> next = newList -> next;
			newList -> next = frontB;

			frontB = frontB -> next;
		}
	}

	// 如果某个链表还有剩余的话，将其头插在新链表。以下两个while语句最多执行一个
	while (frontA != NULL) {
		// 头插
		frontA -> next = newList -> next;
		newList -> next = frontA;

		frontA = frontA -> next;
	}
	while (frontB != NULL) {
		// 头插
		frontB -> next = newList -> next;
		newList -> next = frontB;

		frontB = frontB -> next;
	}
}

