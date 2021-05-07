#include <stdio.h>
#include <stdlib.h>
typedef struct sumber
{
    int a;
    struct sumber *address;
}sub;
sub *creat()
{
    sub *head,*p1,*p2;
    p1=p2=(sub*)malloc(sizeof(sub));
    head=NULL;
    scanf("%d",&p1->a);
    p1->address=NULL;
    while(p1->a!=-1){
        p2=p1;
        p1=(sub*)malloc(sizeof(sub));
        p1->address=p2;
        scanf("%d",&p1->a);
    }
    head=p2;
    return (head);
}
int main()
{
    sub *pt;
    pt=creat();
    while(pt->address!=NULL){
        printf("%d ",pt->a);
        pt=pt->address;
    }
    printf("%d ",pt->a);
    return 0;
}
