#include <cstdio> //堆栈的实现
#include <cstdlib>
#include <cstdbool>


typedef int Position;
typedef int ElementType;
typedef struct SNode * PtrToSNode;
struct SNode
{
    ElementType *Data; //存储数组元素
    Position Top; //表示当前栈顶元素的下标值
    int MaxSize;  //存储表示堆栈的最大容量
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize); //生成一个空的堆栈，其最大长度为MaxSize
bool IsFull(Stack S); //判断堆栈是否是满的
bool Push(Stack S,ElementType X); //将元素X压入栈底。若堆栈已满，返回false，否则将元素X插入栈顶返回true
bool Isempty(Stack S); //判断堆栈是否为空，若是返回true，否则返回false
ElementType Pop(Stack S); //删除并返回栈顶元素
int main()
{
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

bool IsFull(Stack S,int MaxSize) //判断堆栈是否是满的
{
    return (S->Top == MaxSize - 1);
}

bool Push(Stack S,ElementType X) //将元素X压入栈底。若堆栈已满，返回false，否则将元素X插入栈顶返回true
{
    if(IsFull(S)){
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
