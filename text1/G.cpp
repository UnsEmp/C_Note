#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Position;
typedef struct QNode* Queue;
typedef int ElementType;

struct QNode  //队列
{
    ElementType *Data; //存储元素的数组
    Position front,rear; //指向队列头和尾的指针
    int MaxSize; //队列最大容量
};


#define Null -1
#define MaxTree 10
typedef int BinTree;
typedef char TElementType;

struct TNode  //二叉树的顺序存储
{
    TElementType Element;
    ElementType left;
    ElementType right;
}T1[MaxTree],T2[MaxTree];

BinTree TreeBuild(struct TNode T[]);
void UnInordertraversal();

//------------------------------

Queue CreatQueue(int MaxSize); //生成一个空队列，其中最大长度为MaxSize
bool IsFull(Queue Q);
bool IsEmptyQ(Queue Q);
bool AddQ(Queue Q,ElementType X);
ElementType DeleteQ(Queue Q);

//------------------------------

int main()
{
    return 0;
}

//------------------------------

Queue CreatQueue(int MaxSize) //生成一个空队列，其中最大长度为MaxSize
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*)malloc(sizeof(ElementType) * MaxSize);
    Q->rear = Q->front = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull(Queue Q)
{
    return (Q->rear + 1) % Q->MaxSize == Q->front;
}

bool IsEmptyQ(Queue Q)
{
    return Q->front == Q->rear;
}

bool AddQ(Queue Q,ElementType X)
{
    if( IsFull(Q) ){
        return false;
    }
    else{
        Q->rear = (Q->rear + 1) % Q->MaxSize;
        Q->Data[Q->rear] = X;
        return true;
    }
}

ElementType DeleteQ(Queue Q) 
{
    if( IsEmptyQ(Q) ){
        return false;
    }
    else{
        Q->front = (Q->front + 1) % Q->MaxSize;
        return Q->Data[Q->front];
    }
}

//------------------------------



BinTree TreeBuild(struct TNode T[])
{
    int N,i;
    BinTree root;
    int check[MaxTree];
    char cl,cr;
    scanf("%d",&N);
    if( N ){
        for(i = 0;i < N;i++)
        check[i] = 0;
        for(i = 0;i < N;i++){
            scanf("%c %c %c",&T[i].Element,&cl,&cr);
            if(cl != '-'){
                T[i].left = cl - '0';
                check[i] = 1;
            }
            else{
                T[i].left = Null;
            }
            if(cr != '-'){
                T[i].right = cr - '0';
                check[i] = 1;
            }
            else{
                T[i].right = Null;
            }
        }
        for(i = 0;i < N;i++){
            if( !check[i] )
            break;
        }
        root = i;
    }
    return root;
}

void UnInordertraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreatStack();
    T = BT;
    while( T || !IsEmpty(S) ){
        while( T ){
            Push(S,T);
            T = T->Left;
        }
        T = Pop(S);
        printf("%d",T->Data);
        T = T->Right
    }
}


