#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode next;
};
typedef PtrToNode List;

List CreatEmpty();
bool IsEmpty(List L);
void Insert(List L,ElementType x);
bool Delet(ElementType x);
void Print(List L);
void InputList(List L,ElementType N);

int main()
{
    List L;
    int n;
    scanf("%d",&n);
    L = CreatEmpty();
    InputList(L,n);
    Print(L);
    return 0;
}

List CreatEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct Node));
    L->next = NULL;
    return L;
}

bool IsEmpty(List L)
{
    return L->next == NULL;
}

void Insert(List L,ElementType x)
{
    List p,temp;
    p = (List)malloc(sizeof(struct Node));
    p->Data = x;
    p->next = L->next;
    L->next = p;
}

bool Delet(List L,ElementType x)
{
    List p;
    while(L->next){
        if(L->next->Data == x){
            p = L->next;
            L->next = L->next->next;
            free(p);
            return true;
        }
    }
    return false;
}

void Print(List L)
{
    List Rear = L->next;
    while(Rear){
        printf("%d ",Rear->Data);
        Rear = Rear->next;
    }
}

void InputList(List L,ElementType N)
{
    int x;
    for(int i = 0;i < N;i++){
        scanf("%d",&x);
        Insert(L,x);
    }
}