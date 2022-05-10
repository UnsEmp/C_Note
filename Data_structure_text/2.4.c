#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct PolyNode
{
    int coef; //系数
    int expon; //指数
    struct PolyNode* link; //指向下一个结点的指针
};
typedef int ElementType;
typedef struct PolyNode *Polynomial;
Polynomial PolyAdd(Polynomial p1,Polynomial p2);
void Attach(ElementType x,ElementType y,Polynomial* p);
int compare(int x,int y);

int main()
{
    Polynomial p1,p2;
    return 0;
}

Polynomial PolyAdd(Polynomial p1,Polynomial p2)
{
    Polynomial front,rear,temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;
    while(p1 && p2){
        switch(compare(p1->expon,p2->expon)){
            case 1:
            Attach(p1->coef,p1->expon,&rear);
            p1 = p1->link;
            break;
            case -1:
            Attach(p2->coef,p2->expon,&rear);
            p2 = p2->link;
            break;
            case 0:
            sum = p1->coef + p2->coef;
            Attach(sum,p1->expon,&rear);
            break;
        }
    }
    for(;p1;p1 = p1->link)Attach(p1->coef,p1->expon,&rear);
    for(;p2;p2 = p2->link)Attach(p2->coef,p2->expon,&rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;
}

void Attach(ElementType x,ElementType y,Polynomial* p)
{
    Polynomial pa;
    pa = (Polynomial)malloc(sizeof(struct PolyNode));
    pa->coef = x;
    pa->expon = y;
    pa->link = NULL;
    (*p)->link = pa;
    (*p) = pa;
}

int compare(int x,int y)
{
    if(x > y)
    return 1;
    else if(x < y)
    return -1;
    else
    return 0;
}