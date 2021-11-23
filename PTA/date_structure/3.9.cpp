#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>

#define MAXSIZE 100
typedef char ElementType;
typedef struct SNode* Stack;
typedef int Position;

struct SNode
{
    ElementType * Data;
    Position Top;
    int Max;
};

Stack CreatStack(int Max);
bool IsFull(Stack S,int Max);
bool IsEmpty(Stack S);
bool Push(Stack S);
bool Pop(Stack S);
bool JudgeStack(Stack S,ElementType *arr);


int main()
{
    Stack S;
    int N,M;
    scanf("%d %d",&N,&M);
    S = CreatStack(M);
    char arr[MAXSIZE];
    while(N--){
        scanf("%s",arr);
        S->Top = -1;
        if(JudgeStack(S,arr))
        printf("YES\n");
        else
        printf("NO\n");
    }
    
    return 0;
}

Stack CreatStack(int Max)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(sizeof(ElementType) * Max);
    S->Top = -1;
    S->Max = Max;
    return S;
}

bool IsFull(Stack S,int Max)
{
    return S->Top == Max - 1;
}

bool IsEmpty(Stack S)
{
    return S->Top == -1;
}

bool Push(Stack S,ElementType s)
{
    if(IsFull(S,S->Max)){
        return false;
    }
    else{
        S->Data[++(S->Top)] = s;
        return true;
    }
}

bool Pop(Stack S)
{
    if(IsEmpty(S))
    return false;
    else{
        (S->Top)--;
        return true;
    }
}

bool JudgeStack(Stack S,ElementType *arr)
{
    for(int i = 0;i < strlen(arr);i++){
        if(*(arr+i) == 'S'){
            if(!Push(S,'S'))
            return false;
        }
        else{
            if(!Pop(S))
            return false;
        }
    }
    if(S->Top == -1)
    return true;
    else
    return false;
}