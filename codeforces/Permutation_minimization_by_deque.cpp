#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>

const int N = 2e5 + 10;

void solve() {
    int _;
    cin >> _;
    while(_--) {
        int n;
        cin >> n; 
        vector<int> arr(N);
        deque<int> q;
        for(int i = 0;i < n;++i) {
            int t;
            cin >> t;
            if(q.empty()) {
                q.push_back(t);
            }
            else {
                if(t < q.front()) q.push_front(t);
                else q.push_back(t);
            }
        }
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
