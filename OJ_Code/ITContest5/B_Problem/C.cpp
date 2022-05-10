#include <stdio.h>
#include <string.h>
typedef long long ll;

ll bit = 63;
ll prime=1000000007; 

ll hs[10010];
char s[1510];
ll hash(char s[], int len) {
    ll sum = 0;
    for(int i = 0;i < len;i++) {
        if(s[i] >= '0' && s[i] <= '9') sum = sum * 63 + (s[i] - '0');
        else if(s[i] >= 'A' && s[i] <= 'Z') sum = sum * 63 + (s[i] - 'A' + 10);
        else sum = sum * 63 + (s[i] - 'a' + 36);
        sum %= 1000000007;
    }
    return sum;
}

void quick_sort(ll a[], ll l, ll r) {
    if(l >= r) return ;
    ll x = a[(l + r) / 2], i = l - 1, j = r + 1;
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%s", s);
        getchar();
        hs[i] = hash(s, strlen(s));
    }
    quick_sort(hs, 0, n - 1);
    int count = 1;
    for(int i = 1;i < n;i++) {
        if(hs[i] != hs[i - 1]) count++;
    }
    printf("%d", count);
    return 0;
}