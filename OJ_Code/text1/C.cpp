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
    if(!p1 || !p2)
    return NULL;
    Ploynomial p,rear,t1,t2,temp;
    ElementType coef,expon;
    p = (Ploynomial)malloc(sizeof(struct PloyNode));
    p->link = NULL;
    t1 = p1;
    t2 = p2;
    rear = p;

    while(t2){
        Attach(t1->coef * t2->coef,t1->expon + t2->expon,&rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while(t1){
        t2 = p2;
        rear = p;
        while(t2){
            coef = t1->coef * t2->coef;
            expon = t1->expon + t2->expon;
            while(rear->link && expon < rear->link->expon)
            rear = rear->link;
            if(rear->link && (expon == rear->link->expon)){
                if((coef + rear->link->coef) == 0){
                    temp = rear->link;
                    rear->link = rear->link->link;
                    free(temp);
                }
                else{
                    rear->link->coef = coef + rear->link->coef;
                }
            }
            else{
                Ploynomial L;
                L = (Ploynomial)malloc(sizeof(struct PloyNode));
                L->coef = coef;
                L->expon = expon;
                L->link = rear->link;
                rear->link = L;
                rear = rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    temp = p;
    p = p->link;
    free(temp);
    return p;
}