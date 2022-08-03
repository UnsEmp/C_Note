#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    priority_queue<int, vector<int>, greater<int>> q1, q2;
    int cnt = 0;
    for(int i = 0;i < n;++i) {
        cin >> arr[i];
        if(!arr[i]) cnt ++;
        else {
            q1.push(arr[i]);
        }
    }
    // cout << "Ok" << "\n";
    while(q1.size() + cnt > 1) {
        if(cnt) {
            cnt --;
            int t = 0;
            while(q1.size()) {
                if(q1.top() == t) cnt ++;
                else q2.push(q1.top() - t);
                t = q1.top();
                q1.pop();
            }
        }
        else {
            int t = q1.top();
            q1.pop();
            while(q1.size()) {
                if(q1.top() == t) cnt ++;
                else q2.push(q1.top() - t);
                t = q1.top();
                q1.pop();
            }
        }
        
        q1.swap(q2);
    }
    if(q1.size()) cout << q1.top() << "\n";
    else cout << "0" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}