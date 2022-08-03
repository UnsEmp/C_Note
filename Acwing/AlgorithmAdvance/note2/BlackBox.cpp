#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 1e5 + 10;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), u(m);
    priority_queue<int> hma;
    priority_queue<int, vector<int>, greater<int>> hmi;
    for(int i = 0;i < n;++i) cin >> a[i], hmi.push(a[i]);
    for(int i = 0;i < m;++i) cin >> u[i];
    int i = 0, j = 0;
    cout << hmi.top() << "\n";
    for(i = 0;i < n;++i) {
        // hma.push(hmi.top());
        // hmi.pop();
        // if(hmi.empty()) {
        //     hmi.push(a[i]);
        // }
        // else {

        // }
        // hmi.push(a[i]);
        // hma.push(hmi.top());
        // hmi.pop();

        if(hma.empty()) hma.push(a[i]);
        else {
            if(a[i] > hma.top()) {
                hmi.push(a[i]);
            }
            else {
                hma.push(a[i]);
            }
            
        }


        while(j < m && u[j] == i) {
            cout << hmi.top() << "\n";

            hma.push(hmi.top());
            hmi.pop();

            j ++;
        }

        if(hma.empty() || a[i] >= hma.top()) hmi.push(a[i]);
        else {
            hma.push(a[i]);
        }

    }
    // int i = 0, j = 0;
    // while(i < n || j < m) {
    //     while(j < m && u[j] == i) {
    //         cout << hmi.top() << "\n";

    //         hma.push()
    //     }
    // }
    return 0;
}