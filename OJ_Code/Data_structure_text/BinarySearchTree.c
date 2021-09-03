#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define error NULL

typedef struct TNode* Position;
typedef Position BinaryTree;
typedef int ElementType;
typedef struct QNode* PtrToQNode; //队列
typedef struct Node* PtrToNode; //链式队列

struct Node
{
    BinaryTree Data;
    PtrToNode next;
};

typedef PtrToNode Address;

struct QNode
{
    Address front, rear;
};

typedef PtrToQNode Queue;

struct TNode
{
    ElementType Data;
    BinaryTree left;
    BinaryTree right;
};



Queue CreatQueue();
bool IsEmpty(Queue Q);
BinaryTree DeleteQ(Queue Q);
void AddQ(Queue Q, BinaryTree x);

Position CreatBinaryTree();
Position Find(BinaryTree BT, ElementType x);
Position FindMin(BinaryTree BT);
Position FindMax(BinaryTree BT);
void PrintBinaryTree(BinaryTree BT);


int main()
{
    BinaryTree BT = CreatBinaryTree();
    PrintBinaryTree(BT);
    return 0;
}

/* Queue */

Queue CreatQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = Q->rear = NULL;
    return Q;
}

bool IsEmpty(Queue Q)
{
    return Q->front == NULL;
}
BinaryTree DeleteQ(Queue Q)
{
    Address temp;
    BinaryTree x;
    if(IsEmpty(Q)) return error;
    else {
        temp = Q->front;
        if(Q->front == Q->rear) {
            Q->front = Q->rear = NULL;
        }
        else {
            Q->front = Q->front->next;
        }
        x = temp->Data;
        free(temp);
        return x;
    }
}

void AddQ(Queue Q, BinaryTree x)
{
    Address Ar = (Address)malloc(sizeof(struct Node));
    Ar->Data = x;
    Ar->next = NULL;
    if(!IsEmpty(Q)) {
        Q->rear->next = Ar;
        Q->rear = Ar;
    }
    else {
        Q->front = Q->rear = Ar;
    }
}

Position CreatBinaryTree()
{
    ElementType Data;
    BinaryTree BT, T;
    Queue Q = CreatQueue();
    scanf("%d", &Data);
    if(Data != error) {
        BT = (BinaryTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->left = BT->right = NULL;
        AddQ(Q, BT);
    }
    else
        return NULL;
    while(!IsEmpty(Q)) {
        T = DeleteQ(Q);
        scanf("%d", &Data);
        if(Data == error) T->left = NULL;
        else {
            T->left = (BinaryTree)malloc(sizeof(struct TNode));
            T->left->Data = Data;
            T->left->left = T->left->right = NULL;
            AddQ(Q, T->left);
        }
        scanf("%d", &Data);
        if(Data == error) T->right = NULL;
        else {
            T->right = (BinaryTree)malloc(sizeof(struct TNode));
            T->right->Data = Data;
            T->right->right = T->right->left = NULL;
            AddQ(Q, T->right);
        }
    }
    return BT;
}


/* BinaryTree */

Position Find(BinaryTree BT, ElementType x)
{
    if(!BT) return NULL;
    else if(x < BT->Data) {
        return Find(BT->left, x);
    }
    else if(x > BT->Data) {
        return Find(BT->right, x);
    }
    else {
        return BT; //找到 x 返回结果值
    }
    return NULL; //没有找到
}

Position FindMin(BinaryTree BT)
{
    if(!BT->left) return BT;
    return FindMin(BT->left);
}

Position FindMax(BinaryTree BT)
{
    if(!BT->right) return BT;
    return FindMax(BT->right);
}

void PrintBinaryTree(BinaryTree BT)
{
    if(BT) {
        PrintBinaryTree(BT->left);
        printf("%d ", BT->Data);
        PrintBinaryTree(BT->right);
    }
}

