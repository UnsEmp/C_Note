#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 1e5 + 10;
vector<int> a;

int main() {
    cin >> k;
    int i = 0, t;
    while(cin >> t) {
        a.push_back(t);
    }
    n = a.size();
    deque<int> q;
    for(int i = 0;i < n;i++) {
        if(!q.empty() && q.front() < i - k + 1) q.pop_front();
        while(!q.empty() && a[q.back()] <= a[i]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1) 
        cout << a[q.front()] << " ";
    }
    return 0;
}