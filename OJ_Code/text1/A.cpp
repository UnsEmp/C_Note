#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define error -1

typedef int ElementType;
typedef struct SNode* PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

Stack CreatStack();//创建一个链式堆栈
bool IsEmpty(Stack S); //判断堆栈空不空
bool Push(Stack S, ElementType x);//将元素压入堆栈中
ElementType Pop(Stack S);//删除栈顶的元素，并返回值

int main() {
    return 0;
}

Stack CreatStack() //创建一个链式堆栈
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->next = NULL;
    return S;
}
bool IsEmpty(Stack S) //判断堆栈空不空
{
    return S->next == NULL;
}
bool Push(Stack S, ElementType x) //将元素压入堆栈中
{
    PtrToSNode tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = x;
    tmp->next = S->next;
    S->next = tmp;
    return true;
}
ElementType Pop(Stack S) //删除栈顶的元素，并返回值
{
    PtrToSNode tmp;
    ElementType topelment;
    if(IsEmpty(S)) return error;
    else {
        tmp = S->next;
        topelment = tmp->Data;
        S->next = tmp->next;
        free(tmp);
        return topelment;
    }
}
