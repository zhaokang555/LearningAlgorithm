typedef struct BTNode {
    int data;
    struct BTNode *lchild, *rchild;
} BTNode;

// 二叉排序树的构造算法
void CreatBST(BTNode *&bt, int data[], int n) {
    bt = NULL;
    // 调用插入函数，逐个插入关键字
    for (int i = 0; i < n; i++) 
        BSTInsert(bt, data[i]);
}

