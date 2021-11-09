#include <stdio.h>
#define MAX 100010


int main() {
    int arr[MAX] = {0};   //arr[3] += 65;
    int n;
    scanf("%d", &n);
    int index, score;
    for(int i = 0;i < n;i++) {
        scanf("%d %d", &index, &score);
        arr[index] += score;
    }
    int I = 1, S = 0;
    for(int i = 1;i <= 100000;i++) {
        if(arr[i] > S) {
            S = arr[i];
            I = i;
        }
    }
    printf("%d %d", I, S);
    return 0;
}



// #include <stdio.h>
// #include <stdbool.h>

// struct Price
// {
//     double sum;
//     double sumprice;
//     double unitprice;
// };

// void Bubble_sort(struct Price P[], int n) {
//     for(int i = n - 1;i > 0;i--) {
//         for(int j = 1;j <= i;j++) {
//             if(P[j - 1].unitprice > P[j].unitprice) {
//                 struct Price *P = &P[j];
//                 P[j] = P[j - 1];
//                 P[j - 1] = *P;
//             }
//         }
//     }
// }

// int main()
// {
//     int N,D;
//     scanf("%d %d",&N,&D);
//     struct Price P[N];
//     for(int i = 0;i < N;i++){
//         scanf("%lf",&P[i].sum);
//     }
//     for(int i = 0;i < N;i++){
//         scanf("%lf",&P[i].sumprice);
//     }
//     for(int i = 0;i < N;i++){
//         P[i].unitprice = P[i].sumprice/P[i].sum;
//     }

//     for(int i = N - 1;i > 0;i--) {
//         for(int j = 1;j <= i;j++) {
//             if(P[j - 1].unitprice > P[j].unitprice) {
//                 struct Price p = P[j - 1];
//                 P[j - 1] = P[j];
//                 P[j] = p;
//             }
//         }
//     }

//     double money = 0;
//     for(int i = N-1;i >= 0;i--){
//         if(D > P[i].sum){
//             money += P[i].sumprice;
//             D -= P[i].sum;
//         }
//         else if(D < P[i].sum){
//             money += D * P[i].unitprice;
//             break;
//         }
//         else{
//             money += P[i].sumprice;
//             break;
//         }
//     }
//     printf("%.2lf",money);
//     return 0;
// }