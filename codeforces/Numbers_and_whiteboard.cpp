#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>

int main() {
    int _;
    cin >> _;
    while(_--) {
        int n;
        cin >> n;
        stack<int> q;
        for(int i = 1;i <= n;++i) {
            q.push(i);
        }
        cout << "2" << "\n";
        while(q.size() > 1) {
            int a, b;
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            if((a + b) % 2 == 0) {
                cout << b << " " << a << "\n";
                q.push((a + b) / 2);
            }
            else {
                if(!q.empty()) {
                    cout << q.top() << " " << a << "\n";
                    int t = q.top();
                    q.pop();
                    q.push(b);
                    q.push(b);
                }
                else {
                    cout << b << " " << a << "\n";
                }
            }
        }
    }
    return 0;
}