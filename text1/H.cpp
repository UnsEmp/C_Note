#include <cstdio>

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
typedef struct SNode* Stack;

struct SNode
{
    ElementType Data;
    Position Top;
    int MaxSize;
};

struct TNode 
{
    ElementType *Data; //节点的数据
    BinTree Left; //指向左子树
    BinTree right; //指向右子树
};

void RecursionInOrderTraversal(BinTree BT);
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);
bool IsEmpty(BinTree BT);
bool IsFull(BinTree BT);
Stack Push(Stack S,ElementType X);
void PostOrderTraversal(BinTree BT)
Stack CreatStack();

int main()
{
    return 0;
}


void RecursionInOrderTraversal(BinTree BT)
{
    
}

void PreOrderTraversal(BinTree BT)
{
    if(BT){
        printf("%d\n",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->right);
    }
}
void InOrderTraversal(BinTree BT);




void PostOrderTraversal(BinTree BT)
{
	BinTree T=BT;
    BinTree Exist=NULL;
	StackS=CreatStack(MaxSize);//初始化堆
	while(T||!IsEmpty(S)){
		while(T&&T->Left!=Exist&&T->Right!=Exist){//是否遍历完，左孩子或右孩子是否已入栈
		Push(S,T);//从(子)树根向左将结点入栈
		T=T->Left;
		}
		if(!IsEmpty(S)){
            T=GetTop(S);//获取栈顶元素
            if(T->Right&&T->Right!=Exist){//右孩子存在且未入过栈
                T=T->Right;//如果左边最后的结点有右子树,继续上述入栈操作
            }
            else{
                T=Pop(S);//没有右子树了，就出栈
                printf("%5d",T->Data);//读根
                Exist=T;//存放已读根的左孩子
                T=GetTop(S);//获取栈顶元素，即返回已读根的父结点
            }
		}
	}
}//难点在于对根的左右孩子是否曾经入过栈的判定，以及栈顶元素的返回时机
