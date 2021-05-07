#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Merge( List L1, List L2 )
{
    List L;
    L = (List)malloc(sizeof(struct Node));
    List pa = L1->Next,pb = L2->Next;
    List p = L;
    while(pa && pb){
        if(pa->Data < pb->Data){
           p->Next = pa;
           p = pa;
           pa = pa->Next;
        }
        else{
            p->Next = pb;
            p = pb;
            pb = pb->Next;
        }
    }
    p->Next = pa?pa:pb;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}