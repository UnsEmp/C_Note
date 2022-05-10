#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<int>(m));
    queue<pair<int, int>> q; 
    map<pair<int, int>, int> mp;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'S') {
                q.push({i, j});
                mp[{i, j}];
            }
        }
    }
    int key = 0;
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int step = 0;
    while(!q.empty()) {
        int len = q.size();
        for(int i = 0;i < len;i++) {
            pair<int, int> top = q.front();
            q.pop();
            for(int j = 0;j < 4;j++) {
                pair<int, int> newtop;
                newtop.first = top.first + direction[j][0];
                newtop.second = top.second + direction[j][1];
                if(!mp[newtop] && newtop.first >= 0 && newtop.first < n && newtop.second >= 0 && newtop.second < m) {
                    q.push(newtop);
                } 
            }
        }
        step++;
    }
    return 0;
}

