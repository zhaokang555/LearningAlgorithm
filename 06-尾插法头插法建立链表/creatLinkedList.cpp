#include <cstdlib>

typedef struct LinkedNode
{
	int data;
	struct LinkedNode *next;
} LinkedNode;

//尾插法建立链表，其中数组a中存放的是数据，n是数组的大小
void creatLinkedListInTheRear(LinkedNode *&newList, int a[], int n)
{
	// 申请新链表的头结点
	newList = (LinkedNode *)malloc(sizeof(LinkedNode)); 
	newList -> next = NULL;

	// rear始终指向新链表的终端节点
	LinkedNode *rear = newList; 

	// 不断地新建节点，从数组中读取数据，尾插
	for(int i = 0; i < n; i++)
	{
		// 申请一个新节点。存入数据
		LinkedNode *tempNode = (LinkedNode *)malloc(sizeof(LinkedNode)); 
		tempNode -> data = a[i];

		// 把新节点插入新链表。更新尾指针
		// =======尾插的关键步骤==========
		rear -> next = tempNode;
		rear = rear -> next; 
		// ===============================
	}

	rear -> next = NULL;
}

//头插法建立链表，其中数组a中存放的是数据，n是数组的大小
void creatLinkedListInTheFront(LinkedNode *&newList, int a[], int n)
{
	// 申请新链表的头结点
	newList = (LinkedNode *)malloc(sizeof(LinkedNode)); 
	newList -> next = NULL;

	// 不断地新建节点，从数组中读取数据，头插
	for(int i = 0; i < n; i++)
	{
		// 申请一个新节点。存入数据
		LinkedNode *tempNode = (LinkedNode *)malloc(sizeof(LinkedNode)); 
		tempNode -> data = a[i];

		// ========头插的关键步骤==========
		tempNode -> next = newList -> next;
		newList -> next = tempNode;
		// ================================
	}
}

