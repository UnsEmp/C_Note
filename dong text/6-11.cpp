#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );
int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));
    return 0;
}
ElementType Median( ElementType A[], int N )
{
    for(int i = N/2;i > 0;i/=2){
        ElementType temp;
        int j,t;
        for(j = i;j < N;j++){
            temp = A[j];
            for(t = j - i;t >= 0;t -= i){
                if(A[t + i] < A[t]){
                    temp = A[t + i];
                    A[t + i] = A[t];
                    A[t] = temp;
                }
                else{
                    break;
                }
            }
        }
    }
    return A[N/2];
}
