typedef struct BTNode {
    int data;
    struct BTNode *lchild, *rchild;
} BTNode;

//查找关键字的算法
BTNode * BSTSearch(BTNode *bt, int key) {
    // 查找失败，跳出递归
    if (bt==NULL)
        return NULL;
    // 查找成功，返回节点的指针
    if (key == bt->data)
        return bt;
    // 递归
    else if (key < bt->data)
        return BSTSearch(bt->lchild, key);
    else
        return BSTSearch(bt->rchild, key);
}

