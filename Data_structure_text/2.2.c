#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef int Position;
typedef struct SNode* PtrToNode;

struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
};
typedef PtrToNode Stack;

Stack CreatStack(int MaxSize);
bool IsFull(Stack S);
bool Push(Stack S,ElementType X);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);

int main()
{
    return 0;
}

Stack CreatStack(int Max)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(sizeof(ElementType) * Max);
    S->Top = -1;
    S->MaxSize = Max;
    return S;
}

bool IsFull(Stack S)
{
    return S->Top == S->MaxSize - 1;
}
bool Push(Stack S,ElementType X)
{
    if(IsFull(S) == 0){
        printf("Full!");
        return false;
    }
    else{
        S->Data[++S->Top] = X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return S->Top == -1;
}

ElementType Pop(Stack S)
{
    if(IsEmpty(S)){
        printf("Empty!");
        return false;
    }
    else{
        return S->Data[S->Top--];
    }
}