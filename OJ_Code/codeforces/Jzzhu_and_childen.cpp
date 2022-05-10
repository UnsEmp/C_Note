#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;

int main() {
    PII p;
    queue<PII> q;
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        cin >> p.first;
        p.second = i;
        q.push(p); 
    }
    while(!q.empty()) {
        p = q.front();
        q.pop();
        if(p.first > m) {
            p.first -= m;
            q.push(p);
        }
    }
    cout << p.second + 1 << endl;
}

