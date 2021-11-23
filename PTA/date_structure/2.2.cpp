#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LEN sizeof(struct number)
typedef struct number
{
    int  number;
    struct number *next;
}data;
data *creat(int n,int m);
int main()
{
    int n,m;
    data *pt;
    scanf("%d %d",&n,&m);
    pt = creat(n,m);
    while(--n){
        printf("%d",pt->number);
        pt = pt->next;
        printf(" "); 
    }
    printf("%d",pt->number);

}
data *creat(int n,int m)
{
    int count = 1;
    data *head,*middle;
    data *p1,*p2;
    p2 = p1 = (data*)malloc(LEN);
    scanf("%d",&p1->number);
    head = p1;
    middle = p1;
    while(count != n){
        p1 = (data*)malloc(LEN);
        scanf("%d",&p1->number);
        count++;
        if(count == m%n + 1){
            middle = p1;
        }
        p2->next = p1;
        p2 = p1;
    }
    p2->next = head;
    return middle;
}