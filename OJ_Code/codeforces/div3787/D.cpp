#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> st(n + 1);
    vector<int> parent(n + 1);
    vector<vector<int>> child(n + 1);
    for(int i = 1;i <= n;++i) {
        cin >> parent[i];
        if(parent[i] != i)
        child[parent[i]].push_back(i);
    }
    vector<vector<int>> paths;
    for(int i = 1;i <= n;++i) {
            int t = i;
            if(child[t].size() == 0 && !st[t]) {
                vector<int> path;
                st[t] = 1;
                path.push_back(t);
                while(parent[t] != t && !st[parent[t]]) {
                    t = parent[t];
                    path.push_back(t);
                    st[t] = 1;
                }  
                paths.push_back(path); 
            }
    }
    cout << paths.size() << "\n";
    for(int i = 0;i < paths.size();++i) {
        cout << paths[i].size() << "\n";
        for(int j = paths[i].size() - 1;j >= 0;--j) {
            cout << paths[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
        cout << "\n";
    }
    return 0;
}