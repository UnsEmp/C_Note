#include <stdio.h> //堆栈的实现
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#define SIZE 100

typedef enum {zero, one, two, tree, four, five, six, seven, eight, night} Precedence;

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
char* ToPostfix(char* expr, char* Postfix); //后缀表达式
bool IsSign(char *expr, int i); //判断符号是否是运算符
char GetOp(char *expr, int *i, char *Postfix, int *j); //获取运算符
Precedence GetPriority(char op); //返回运输优先级


int main()
{
    char *Post;
    char Postfix[2 * SIZE];
    Stack S;
    S = CreateStack(SIZE);
    gets(S->Data);
    Post = ToPostfix(S->Data, Postfix);
    printf("%s\n", Post);
    return 0;
}

ElementType ConculateExpression(char* Postfix) {
    Stack S;
    S = CreateStack(SIZE);
    int len = strlen(Postfix);
    for(int i = 0;i < len;i++) {
        char arr[20];
        if(*(Postfix + i) == ' ') continue;
        if(GetPriority(*(Postfix + i)) == eight) {
            int count = 0;
            while(*(Postfix + i) != ' ') arr[count++] = *(Postfix + i);
        }
        else {

        }
    }
}


Precedence GetPriority(char op) {
    switch(op) {
        case '(':return one;
        case ')':return two;
        case '+':return tree;
        case '-':return four;
        case '*':return five;
        case '/':return six;
        case '\0':return seven;
        default:return eight;
    }
}

bool IsSign(char *expr, int i) {
    if(!i || (!isdigit(expr[i - 1]) && (expr[i - 1] != ')')) )
        return true;
    else 
        return false;
}

char* ToPostfix(char *expr, char *Postfix) {
    int i, j, L;
    char op;
    Stack S;
    Precedence token;
    S = CreateStack(SIZE);
    L = strlen(expr);
    j = 0;
    for(i = 0;i < L;i++) {
        op = GetOp(expr, &i, Postfix, &j);
        token = GetPriority(op);
        if(token == eight) continue;
        switch(token) {
            case one:Push(S, '(');break;
            case two:
            while(Peek(S) != '(') {
                Postfix[j++] = Pop(S);
                Postfix[j++] = ' ';
            }
            Pop(S);
            break;
            default:
            while(!IsEmpty(S) && Peek(S) != '(' && token <= GetPriority(Peek(S))) {
                Postfix[j++] = Pop(S);
                Postfix[j++] = ' ';
            }
            Push(S, op);
            break;
        }
    }
    while(!IsEmpty(S)) {
        Postfix[j++] = Pop(S);
        Postfix[j++] = ' ';
    }
    Postfix[j - 1] = '\0';
    // printf("%s\n", Postfix);
    return Postfix;
}

char GetOp(char *expr, int *i, char *Postfix, int *j) {
    if(isdigit(expr[(*i)])) {
        while(isdigit(expr[*i]) || (expr[(*i)] == '.')) {
            Postfix[(*j)++] = expr[(*i)++];
        }
        Postfix[(*j)++] = ' ';
        (*i)--;
        return '0';
    }
    switch(expr[(*i)]) {
        case '+':
        if(IsSign(expr, (*i))) {
            (*i)++;
            return GetOp(expr, i, Postfix, j);
        }
        else return '+';
        case '-':
        if(IsSign(expr, (*i))) {
            Postfix[(*j)++] = '-';
            (*i)++;
            return GetOp(expr, i, Postfix, j);
        }
        else return '-';
        default:return expr[(*i)];
    }
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
    else{
        S->Data[++(S->Top)] = X;
        return true;
    }
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
