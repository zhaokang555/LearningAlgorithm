typedef struct BTNode {
    int data;
    struct BTNode *lchild, *rchild;
} BTNode;

//插入关键字的算法
bool BSTInsert(BTNode *&bt, int newData) {

    if (bt == NULL) { 
        // 二叉树为空，创建一个节点并放入地址
        // bt = (BTNode *)malloc(sizeof(BTNode));
        bt = new BTNode;
        bt->lchild = bt->rchild = NULL;
        bt->data = newData;
        return true;
    } else {
        // 存在相等的data, 插入失败
        if (newData == bt->data) 
            return false;
        // 递归
        else if (newData < bt->data)
            return BSTInsert(bt->lchild, newData);
        else
            return BSTInsert(bt->rchild, newData);
    }
}

