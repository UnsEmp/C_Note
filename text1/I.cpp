#include <cstdio>
#include <cstdlib>
#include <cstdbool>

#define NoInfo 0
typedef struct TNode* BinTree;
typedef int ElementType;

struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatTree();
bool IsEmpty(BinTree BT);
void Traversal(BinTree BT);

int main()
{
    return 0;
}

 
BinTree CreatBinTree() //层序生成二叉树的算法
{
    ElementType Data;
    BinTree T,BT;
    Queue Q = CreatQueue();

    scanf("%d",&Data);

    if(Data != NoInfon){
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q,BT);
    }
    else 
    return NULL;

    while( IsEmpty( Q ) ){
        scanf("%d",&Data);
        T = Delete( Q );
        if(Data == NoInfo)
        T->Left = NULL;
        else{
            T->Left = (BinTree)malloc(sizeof(struct Tn=Node));
            T->Left->Data = Data;
            T->Left->Left = NULL;
            T->Left->Right = NULL;
            AddQ(Q,T->Left);
        }
        scanf("%d",&Data);
        if(Data == NoInfo)
        return NULL;
        else{
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Right = T->Right->Left = NULL;
            AddQ(Q,T->Right);
        }
    }
    return BT;
}
bool IsEmpty(BinTree BT);
void Traversal(BinTree BT);