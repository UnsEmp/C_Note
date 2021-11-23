#include <cstdio>
#include <cstdlib>
#include <cstdbool>


typedef struct SNode* Stack;
typedef int ElementType;
typedef int Position;

struct SNode
{
    ElementType *Data;
    Position Top = -1;
    int Max;
};

Stack CreatStack(int max);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
Stack Push(Stack S,ElementType X);
Stack Pop(Stack S);

bool judge(Stack S,int Arr[],int N);

int main()
{
    Stack S;
    int M,N,K,i,j;
    scanf("%d %d %d",&M,&N,&K);
    int Arr[N];
    S = CreatStack( M );
    for(i = 0;i < K;i++){
        for(j = 0;j < N;j++){
            scanf("%d",&Arr[j]);
        }    
        S->Top = -1;
        if( judge(S,Arr,N) )
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}

Stack CreatStack(int max)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(sizeof(ElementType) * max);
    S->Max = max;
    S->Top = -1;
    return S;
}

bool IsEmpty(Stack S)
{
    return S->Top == -1;
}

bool IsFull(Stack S)
{
    return S->Top == S->Max - 1;
}

Stack Push(Stack S,ElementType X)
{
    if( IsFull(S) )
    return NULL;
    else{
        S->Data[++S->Top] = X;
        return S;
    }
}

Stack Pop(Stack S)
{
    if( IsEmpty(S) )
    return NULL;
    else{
        S->Top--;
        return S;
    }
}

bool judge(Stack S,int *Arr,int N)
{
    int count = 0;
    for(int i = 1;i <= N;i++){
        S = Push(S,i);
        if( !S ){
            return false;
        }
        while((S->Top != -1) && (S->Data[S->Top] == *(Arr + count)) && (count < N)){
            S = Pop(S);
            if( !S ){
                return false;
            }
            count++;
        }
    }
    if(S->Top == -1){
        return true;
    }
    else{
        return false;
    }
}