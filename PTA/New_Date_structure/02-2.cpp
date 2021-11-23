#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct PloyNode* Ploynomial;

struct PloyNode
{
    int coef;
    int expon;
    Ploynomial link;
};

Ploynomial ReadPloynomial();
void PrintPloynomial(Ploynomial p);
void Attach(int coef,int expon,Ploynomial *p);
Ploynomial PloyAdd(Ploynomial p1,Ploynomial p2);
Ploynomial PloyMul(Ploynomial p1,Ploynomial p2);


int main()
{
    Ploynomial p,p1,p2;
    p1 = ReadPloynomial();
    p2 = ReadPloynomial();
    p = PloyMul(p1,p2);
    PrintPloynomial(p);
    printf("\n");
    p = PloyAdd(p1,p2);
    PrintPloynomial(p);
    return 0;
}
Ploynomial ReadPloynomial() //进行多项式的读入
{
    int n,coef,expon;
    Ploynomial p,t,rear;
    p = (Ploynomial)malloc(sizeof(struct PloyNode));
    p->link = NULL;
    rear = p;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&coef,&expon);
        Attach(coef,expon,&rear);
    }
    t = p;
    p = p->link;
    free(t);
    return p;
}
void PrintPloynomial(Ploynomial p) //多项式的输出
{
    Ploynomial Rear = p;
    if(!Rear){
        printf("0 0");
        return ;
    }
    else{
        printf("%d %d",Rear->coef,Rear->expon);
        Rear = Rear->link;
        while(Rear){
            printf(" %d %d",Rear->coef,Rear->expon);
            Rear = Rear->link;
        }
    }
}

void Attach(int coef,int expon,Ploynomial *p)
{
    Ploynomial pa;
    pa = (Ploynomial)malloc(sizeof(struct PloyNode));
    pa->coef = coef;
    pa->expon = expon;
    pa->link = NULL;
    (*p)->link = pa;
    (*p) = pa;
}

Ploynomial PloyAdd(Ploynomial p1,Ploynomial p2)
{
    int sum;
    Ploynomial pa,front,rear,temp;
    pa = (Ploynomial)malloc(sizeof(struct PloyNode));
    pa->link = NULL; //创建一个新链表放求和后的多项式
    rear = pa;
    while(p1 && p2){
        if(p1->expon > p2->expon){
            Attach(p1->coef,p1->expon,&rear);
            p1 = p1->link;
        }
        else if(p1->expon < p2->expon){
            Attach(p2->coef,p2->expon,&rear);
            p2 = p2->link;
        }
        else{
            if((p1->coef + p2->coef) != 0){
                sum = p1->coef + p2->coef;
                Attach(sum,p1->expon,&rear);
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    for(;p1;p1 = p1->link)Attach(p1->coef,p1->expon,&rear); //若p1或p2中有一个不为空则将其插入链表的末尾
    for(;p2;p2 = p2->link)Attach(p2->coef,p2->expon,&rear);
    temp = pa;
    pa = pa->link;
    free(temp);
    return pa;
}
Ploynomial PloyMul(Ploynomial p1,Ploynomial p2)
{
    Ploynomial pa,pb,front,rear,temp,ready; 
    ElementType coef,expon;
    front = (Ploynomial)malloc(sizeof(struct PloyNode));
    front->link = NULL;
    pa = p1;
    pb = p2;
    rear = front;
    if(pa){
        while(pb){
            coef = pa->coef * pb->coef;
            expon = pa->expon + pb->expon;
            Attach(coef,expon,&rear);
            pb = pb->link;
        }
        pb = p2;
        pa = pa->link;
        temp = front;
        front = front->link;
        free(temp);
    }
    else{
        return 0;
    }
    while(pa){
        ready = (Ploynomial)malloc(sizeof(struct PloyNode));
        rear = ready;
        while(pb){
            coef = pa->coef * pb->coef;
            expon = pa->expon + pb->expon;
            Attach(coef,expon,&rear);
            pb = pb->link;
        }
        pb = p2;
        pa = pa->link;
        temp = ready;
        ready = ready->link;
        free(temp);
        front = PloyAdd(front,ready);
    }
    return front;
}