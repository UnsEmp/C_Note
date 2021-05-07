#include <cstdio>
#include <cstdlib>
#include <cstdbool>

typedef int ElementType;
typedef struct Node* List;

struct Node
{
    ElementType coef;
    ElementType expon;
    List next;
};

List CreatData();
List InputData(List L);
List AddData(List p1,List p2);
void Attach(ElementType coef,ElementType expon,List *rear);
List MulData(List p1,List p2);
void PrintData(List L);

int main()
{
    List L,L1,L2;
    L1 = CreatData();
    L2 = CreatData();
    L1 = InputData(L1);
    L2 = InputData(L2);
    L = MulData(L1,L2);
    PrintData(L);
    printf("\n");
    L = AddData(L1,L2);
    PrintData(L);
    return 0;
}

List CreatData()
{
    List L;
    L = (List)malloc(sizeof(struct Node));
    L->next = NULL;
    return L;
}

List InputData(List L)
{
    int temp,coef,expon;
    List rear = L,P;
    scanf("%d",&temp);
    for(int i = 0;i < temp;i++){
        scanf("%d %d",&coef,&expon);
        Attach(coef,expon,&rear);
    }
    P = L;
    L = L->next;
    free(P);
    return L;
}

List AddData(List p1,List p2)
{
    List L,rear,temp;
    ElementType sum;
    L = (List)malloc(sizeof(struct Node));
    L->next = NULL;
    rear = L;
    while(p1 && p2){
        if(p1->expon > p2->expon){
            Attach(p1->coef,p1->expon,&rear);
            p1 = p1->next;
        }
        else if(p1->expon < p2->expon){
            Attach(p2->coef,p2->expon,&rear);
            p2 = p2->next;
        }
        else{
            sum = p1->coef + p2->coef;
            if(sum){
                Attach(sum,p1->expon,&rear);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    for(;p1;p1 = p1->next)Attach(p1->coef,p1->expon,&rear);
    for(;p2;p2 = p2->next)Attach(p2->coef,p2->expon,&rear);
    temp = L;
    L = L->next;
    free(temp);
    return L;
}
void Attach(ElementType coef,ElementType expon,List *rear)
{
    List L;
    L = (List)malloc(sizeof(struct Node));
    L->coef = coef;
    L->expon = expon;
    L->next = NULL;
    (*rear)->next = L;
    (*rear) = (*rear)->next;
}
List MulData(List p1,List p2)
{
    if(!p1 || !p2)
    return NULL;
    List p,rear,t1,t2,temp;
    ElementType coef,expon;
    p = (List)malloc(sizeof(struct Node));
    p->next = NULL;
    t1 = p1;
    t2 = p2;
    rear = p;

    while(t2){
        Attach(t1->coef * t2->coef,t1->expon + t2->expon,&rear);
        t2 = t2->next;
    }
    t1 = t1->next;
    while(t1){
        t2 = p2;
        rear = p;
        while(t2){
            coef = t1->coef * t2->coef;
            expon = t1->expon + t2->expon;
            while(rear->next && expon < rear->next->expon)
            rear = rear->next;
            if(rear->next && (expon == rear->next->expon)){
                if((coef + rear->next->coef) == 0){
                    temp = rear->next;
                    rear->next = rear->next->next;
                    free(temp);
                }
                else{
                    rear->next->coef = coef + rear->next->coef;
                }
            }
            else{
                List L;
                L = (List)malloc(sizeof(struct Node));
                L->coef = coef;
                L->expon = expon;
                L->next = rear->next;
                rear->next = L;
                rear = rear->next;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    temp = p;
    p = p->next;
    free(temp);
    return p;
}

void PrintData(List L)
{
    if(!L)
        printf("0 0");
    else{
        printf("%d %d",L->coef,L->expon);
        L = L->next;
        while(L){
            printf(" %d %d",L->coef,L->expon);
            L = L->next;
        }
    }
}