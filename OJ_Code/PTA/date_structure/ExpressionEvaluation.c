#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#define SIZE 100


// typedef enum { false, true } bool;
typedef enum {one, tow, tree, four, five, six, seven} Pori;

typedef int Position;
typedef char ElementType;
typedef struct SNode * PtrToSNode;
struct SNode
{
    ElementType *Data; //存储数组元素
    Position Top; //表示当前栈顶元素的下标值
    int MaxSize;  //存储表示堆栈的最大容量
};
typedef PtrToSNode Stack;

ElementType Peek(Stack S);
Stack CreateStack(int MaxSize); //生成一个空的堆栈，其最大长度为MaxSize
bool IsFull(Stack S, int MaxSize); //判断堆栈是否是满的
bool Push(Stack S,ElementType X); //将元素X压入栈底。若堆栈已满，返回false，否则将元素X插入栈顶返回true
bool IsEmpty(Stack S); //判断堆栈是否为空，若是返回true，否则返回false
ElementType Pop(Stack S); //删除并返回栈顶元素
Pori GetPori(char ch) {
    switch(ch) {
        case '(':return one;
        case ')':return tow;
        case '-':return tree;
        case '+':return four;
        case '*':return five;
        case '/':return six;
        default:return seven;
    }
}


int main() {
    char arr[21];
    char ans[21];
    scanf("%s",arr);
    Stack S;
    Pori p;
    S = CreateStack(SIZE);
    int len = strlen(arr);
    int i = 0, j = 0;
    for(i = 0;i < len;i++) {
        if(isdigit(arr[i])) {
            ans[j++] = arr[i];
            ans[j++] = ' ';
        }
        else {
            switch(arr[i]) {
                case '(':Push(S, arr[i]);break;
                case ')':
                while(!IsEmpty(S) && Peek(S) != '(') {
                    ans[j++] = Peek(S);
                    ans[j++] = ' ';
                    Pop(S);
                    // break;
                }
                Pop(S);
                break;
                default:
                p = GetPori(arr[i]);
                if(IsEmpty(S)) {
                    Push(S, arr[i]);
                    break;
                }
                if(!IsEmpty(S) && GetPori(Peek(S)) < p) {
                    Push(S, arr[i]);
                }
                else {
                    while(!IsEmpty(S) && GetPori(Peek(S)) >= p) {
                        ans[j++] = Peek(S);
                        ans[j++] = ' ';
                        Pop(S);
                    }
                    Push(S, arr[i]);
                }
            }

        }
    }
    while(!IsEmpty(S)) {
        ans[j++] = Peek(S);
        ans[j++] = ' ';
        Pop(S);
    }
    ans[j - 1] = '\0';
    printf("%s",ans);
    return 0;
}

Stack CreateStack(int MaxSize) //生成一个空的堆栈，其最大长度为MaxSize
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(sizeof(ElementType) * MaxSize);
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

ElementType Peek(Stack S) {
    if(IsEmpty(S)) return -1;
    return S->Data[S->Top];
}

bool IsFull(Stack S,int MaxSize) //判断堆栈是否是满的
{
    return (S->Top == MaxSize - 1);
}

bool Push(Stack S,ElementType X) //将元素X压入栈底。若堆栈已满，返回false，否则将元素X插入栈顶返回true
{
    if(IsFull(S, SIZE)){
        printf("堆栈已满\n");
        return false;
    }
    S->Data[++(S->Top)] = X;
    return true;

}

bool IsEmpty(Stack S) //判断堆栈是否为空，若是返回true，否则返回false
{
    return (S->Top == -1);
}

ElementType Pop(Stack S)
{
    if(IsEmpty(S)){
        printf("堆栈为空\n");
        return false;
    }
    else{
        return S->Data[(S->Top)--];
    }
}

