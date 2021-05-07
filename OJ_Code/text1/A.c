#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode * PtrToPolyNode;
struct PolyNode {
    int coef, expon;
    PtrToPolyNode Next;
};

typedef PtrToPolyNode Polynomial;

void Attach(int coef, int expon, Polynomial * pRear)
{
    Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = coef;
    P->expon = expon;
    P->Next = NULL;
    (*pRear)->Next = P;
    *pRear = P;
}

Polynomial ReadPoly()
{
    int n, c, e;
    scanf("%d", &n);
    Polynomial P, Rear;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->Next = NULL; Rear = P;
    while (n--) {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    Rear = P; P = P->Next; free(Rear);
    return P;
}

void PrintPoly(Polynomial P)
{
    if (P == NULL) {printf("0 0\n"); return;}
    while (P) {
        printf("%d %d", P->coef, P->expon);
        printf("%c", P->Next != NULL ? ' ' : '\n');
        P = P->Next;
    }
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    if (P1 == NULL || P2 == NULL) return NULL;
    Polynomial P, Rear, t1 = P1, t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->Next = NULL; Rear = P;
    while (t2) {
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->Next;
    }
    while (t1 = t1->Next)
    {
        t2 = P2; Rear = P;
        while (t2) {
            int c = t1->coef * t2->coef;
            int e = t1->expon + t2->expon;
            while (Rear->Next && Rear->Next->expon > e)
                Rear = Rear->Next;
            if (Rear->Next && Rear->Next->expon == e) {
                if (c + Rear->Next->coef != 0)
                    Rear->Next->coef += c;
                else {
                    Polynomial temp = Rear->Next;
                    Rear->Next = temp->Next;
                    free(temp);
                }
            }
            else {
                Polynomial temp = (Polynomial)malloc(sizeof(struct PolyNode));
                temp->coef = c; temp->expon = e;
                temp->Next = Rear->Next;
                Rear->Next = temp;
                Rear = Rear->Next;
            }
            t2 = t2->Next;
        }
    }
    Rear = P; P = P->Next; free(Rear);
    return P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
    Polynomial P, Rear, t1 = P1, t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->Next = NULL; Rear = P;
    while (t1 && t2) {
        if (t1->expon > t2->expon) {
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->Next;
        }
        else if (t1->expon < t2->expon) {
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->Next;
        }
        else {
            if ((t1->coef + t2->coef) != 0)
                Attach(t1->coef + t2->coef, t1->expon, &Rear);
            t1 = t1->Next; t2 = t2->Next;
        }
    }
    while (t1) {Attach(t1->coef, t1->expon, &Rear); t1 = t1->Next;}
    while (t2) {Attach(t2->coef, t2->expon, &Rear); t2 = t2->Next;}
    Rear = P; P = P->Next; free(Rear);
    return P;
}

int main()
{
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1, P2);
    PrintPoly(PP);
    PS = Add(P1, P2);
    PrintPoly(PS);
    return 0; 
}