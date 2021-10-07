#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct LNode* Polynomial;

struct LNode {
	int coef;
	int expon;
	struct LNode* next;
};

Polynomial ReadPolynomial();
void PrintPolynomial(Polynomial p);
void Attach(int coef, int expon, Polynomial *p);
Polynomial AddPolynomial(Polynomial p1, Polynomial p2);

int main() {
	Polynomial p, p1, p2;
	p1 = ReadPolynomial();
	p2 = ReadPolynomial();
	p = AddPolynomial(p1, p2);
	PrintPolynomial(p);
	return 0;
}

Polynomial AddPolynomial(Polynomial p1, Polynomial p2) {
	int sum;
    Polynomial pa,front,rear,temp;
    pa = (Polynomial)malloc(sizeof(struct LNode));
    pa->next = NULL; 
    rear = pa;
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
            if((p1->coef + p2->coef) != 0){
                sum = p1->coef + p2->coef;
                Attach(sum,p1->expon,&rear);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    for(;p1;p1 = p1->next)Attach(p1->coef,p1->expon,&rear); 
    for(;p2;p2 = p2->next)Attach(p2->coef,p2->expon,&rear);
    temp = pa;
    pa = pa->next;
    free(temp);
    return pa;
}
void Attach(int coef, int expon, Polynomial *p) {
	Polynomial tmp = (Polynomial)malloc(sizeof(struct LNode));
	tmp->coef = coef;
	tmp->expon = expon;
	tmp->next = NULL;
	(*p)->next = tmp;
	(*p) = tmp;
}
Polynomial ReadPolynomial() {
	Polynomial head, p, p1;
	head = p = (Polynomial)malloc(sizeof(struct LNode));
	p->next = NULL;
	int n, coef, expon;
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &coef, &expon);
		Attach(coef, expon, &p);
	}
	return head->next;
}
void PrintPolynomial(Polynomial p) {
	while(p) {
		printf("%d %d ", p->coef, p->expon);
		p = p->next;
	}
}