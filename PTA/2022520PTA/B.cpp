#include <bits/stdc++.h>
using namespace std;


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    while(n > 0 && m > 0) {
        n --;
        m -= k;
    }
    // if(n > 0) {

    // }
    if(m > n * k) printf("hai sheng %d!\n", m - n * k);
    else if(m < n * k) printf("hai cha %d!\n", n * k - m);
    else printf("zheng hao mei ren %d!", k);
    return 0;
}