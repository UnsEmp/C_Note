#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define error NULL

// typedef char ElementType;
typedef struct TNode* BTNode;
struct TNode {
    char Date;
    struct TNode* left;
    struct TNode* right;
};

typedef BTNode ElementType;
typedef struct Node* PtrToNode;
struct Node { //存放数据的节点
    ElementType Data;
    PtrToNode next;
};

typedef PtrToNode Position;
// typedef struct QNode* PtrToNode;
struct QNode {
    Position front, rear; //表示队列的头尾指针
};
typedef struct QNode* Queue;

BTNode CreatBTNode();
void InOrderTraversal(BTNode T);
void PreOrderTraversal(BTNode T);
void PostOrderTraversal(BTNode T);

Queue CreatQueue();
bool IsEmpty(Queue Q);
ElementType DeleteQ(Queue Q);
bool IsFull(Queue Q);
void Push(Queue Q, ElementType X);
ElementType Peek(Queue Q);

int main() {
    BTNode T = CreatBTNode();
    InOrderTraversal(T);
    return 0;
}

BTNode CreatBTNode() {
    char Date;
    BTNode T, tmp;
    Queue Q;
    T = (BTNode)malloc(sizeof(struct TNode));
    T->left = T->right = NULL;
    scanf("%c", &Date);
    if(Date != '#') {
        T->Date = Date;
        Push(Q, T);
    }
    while(!IsEmpty(Q)) {
        BTNode BT;
        BTNode tmp = DeleteQ(Q);
        scanf("%c", &Date);
        if(Date != '#') {
            BT = (BTNode)malloc(sizeof(struct TNode));
            BT->Date = Date;
            BT->left = BT->right = NULL;
            tmp->left = BT;
            Push(Q, BT);
        }
        scanf("%c", &Date);
        if(Date != '#') {
            BT = (BTNode)malloc(sizeof(struct TNode));
            BT->Date = Date;
            BT->left = BT->right = NULL;
            tmp->right = BT;
            Push(Q, BT);
        }
    }
    return T;
}
void InOrderTraversal(BTNode T) {
    if(T) {
        if(T->Date != '-') printf("%c", T->Date);
        InOrderTraversal(T->left);
        InOrderTraversal(T->right);
    }
}
void PreOrderTraversal(BTNode T);
void PostOrderTraversal(BTNode T);

bool IsEmpty(Queue Q) { //判断队列是否为空
    return Q->front == NULL;    
}

ElementType DeleteQ(Queue Q) { //删除队首的元素，并返回该元素的值
    Position FrontCell;
    ElementType FrontEle;
    if(IsEmpty(Q)) return error;
    else {
        FrontCell = Q->front;
        if(Q->front == Q->rear) Q->front = Q->rear = NULL;
        else Q->front = Q->front->next;
    }
    FrontEle = FrontCell->Data;
    free(FrontCell);
    return FrontEle;
}
void Push(Queue Q, ElementType X) { //将元素 `X`加入入队尾中 
    struct Node* N = (struct Node*)malloc(sizeof(struct Node));
    N->Data = X;
    N->next = NULL;
    if(IsEmpty(Q)) Q->front->next = Q->rear->next = N;
    else Q->rear->next = N;
}
ElementType Peek(Queue Q) { //查看队首的元素
    if(IsEmpty(Q)) return error;
    else return Q->front->Data;
}