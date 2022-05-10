#include <stdio.h>
#define MAX 100010

struct Node {
    double price;
    double cap;
    double sumprice;
};



int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    // struct Node s[MAX];
    double cap[n], sumprice[n], price[n];
    for(int i = 0;i < n;i++) {
        scanf("%lf", &cap[i]);
    }
    for(int i = 0;i < n;i++) {
        scanf("%lf", &sumprice[i]);
        price[i] = sumprice[i] / cap[i];
    }

    for(int i = n - 1;i > 0;i--) {
        for(int j = 1;j <= i;j++) {
            if(price[j - 1] > price[j]) {
                double tmp = price[j - 1];
                price[j - 1] = price[j];
                price[j] = tmp;
                tmp = cap[j - 1];
                cap[j - 1] = cap[j];
                cap[j] = tmp;
            }
        }
    }
    double sum = 0;
    for(int i = n - 1;m > 0 && i >= 0;i--) {
        m -= cap[i];
        if(m >= 0) {
            sum += cap[i] * price[i];
        }
        else {
            sum += (cap[i] + m) * price[i];
            break;
        }
    }
    printf("%.2lf", sum);
    return 0;
}