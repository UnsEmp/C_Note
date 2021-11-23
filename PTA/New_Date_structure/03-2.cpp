#include <cstdio>
#include <cstdlib>
#include <cstdbool>

#define Null -1
#define MAX 10
typedef char ElementType;
typedef struct TNode* BinTree;
typedef int Tree;
typedef int Position;
typedef struct QNode* Queue;

struct QNode
{
    int *Data;
    Position front,rear;
    int Max;
};


struct TNode
{
    Tree Left;
    Tree Right;
}T[MAX];

Tree InputTree(struct TNode T[]);
void LevelnorderTraversal(struct TNode T[],Tree root);

Queue CreatQueue();
bool IsEmpty( Queue Q );
bool IsFull( Queue Q );
bool AddQ( Queue Q,int X);
int Delete( Queue Q );

int main()
{
    Tree R1;
    R1 = InputTree( T );
    LevelnorderTraversal( T , R1);
    return 0;
}

Tree InputTree(struct TNode T[])
{
    int N,i,root;
    ElementType cl,cr;
    scanf("%d",&N);
    getchar();
    int check[N];
    for(i = 0;i < N;i++){
        check[i] = 0;
    }
    for(i = 0;i < N;i++){
        scanf("%c %c",&cl,&cr);
        getchar();
        if(cl != '-'){
            T[i].Left = cl - '0';
            check[T[i].Left] = 1;
        }
        else{
            T[i].Left = Null;
        }
        if(cr != '-'){
            T[i].Right = cr - '0';
            check[T[i].Right] = 1;
        }
        else{
            T[i].Right = Null;
        }
    }
    for(i = 0;i < N;i++)
    if( !check[i] )
    break;
    root = i;
    return root;
}

void LevelnorderTraversal(struct TNode T[],Tree root)
{
    if(T[root].Left == Null && T[root].Right == Null){
        printf("0");
        return ;
    }
    Queue Q;
    int temp,count = 0;
    Q = CreatQueue();
    AddQ(Q,root);
    while( !IsEmpty( Q ) ){
        temp = Delete( Q );
        if(T[temp].Left == Null && T[temp].Right == Null){
            if(!count){
                printf("%d",temp);
                count++;
            }
            else{
                printf(" %d",temp);
            }
            
        }
        if( T[temp].Left != Null ){
            AddQ(Q,T[temp].Left);
        }
        if( T[temp].Right != Null ){
            AddQ(Q,T[temp].Right);
        }
    }
}

Queue CreatQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (int*)malloc(sizeof(int) * MAX);
    Q->front = 0;
    Q->rear = 0;
    Q->Max = MAX;
    return Q;
}

bool IsEmpty( Queue Q )
{
    return Q->front == Q->rear;
}

bool IsFull( Queue Q )
{
    return ((Q->rear + 1) % Q->Max) ==  Q->front;
}

bool AddQ( Queue Q,int X)
{
    if(IsFull(Q))
    return false;
    else{
        Q->rear = (Q->rear + 1) % Q->Max;
        Q->Data[Q->rear] = X;
        return true;
    }
}
int Delete( Queue Q )
{
    if(IsEmpty(Q))
    return false;
    else{
        Q->front = (Q->front + 1)  % Q->Max;
        return Q->Data[Q->front];
    }
}