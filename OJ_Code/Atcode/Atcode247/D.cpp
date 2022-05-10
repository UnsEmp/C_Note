#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    queue<pair<long long, long long>> q;
    cin >> _;
    while(_--) {
        int n;
        cin >> n;
        if(n == 1) {
            long long x, c;
            cin >> x >> c;
            q.push({x, c});
        }
        else {
            long long c;
            cin >> c;
            long long sum = 0;
            while(c > 0) {
                if(c > q.front().second) {
                    sum += q.front().second * q.front().first;
                    c -= q.front().second;
                    q.pop();
                }
                else {
                    sum += c * q.front().first;
                    q.front().second -= c;
                    break;
                }
            }
            cout << sum << "\n";
        }
    }
    return 0;
}























