#include <bits/stdc++.h>
using namespace std;

#define Nofind -1

int findnum(vector<vector<char>> & arr, pair<int, int> & pli, int  n, int  m) {
    int time = 0;
    int top = 0;
    bool flag = false;
    queue<pair<int, int>> q;
    map<pair<int, int>, int> mp;
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    q.push(pli);
    mp[pli]++;
    while(!q.empty()) {
        int len = q.size();
        for(int i = 0;i < len;i++) {
            pair<int, int> tmp = q.front();
            q.pop();
            for(int j = 0;j < 4;j++) {
                pair<int, int> newposition;
                newposition.first = tmp.first + direction[j][0];
                newposition.second = tmp.second + direction[j][1];
                if((newposition.first >= 0) && (newposition.first < n) && (newposition.second >= 0) && (newposition.second < m) && (arr[newposition.first][newposition.second] == 'T' || arr[newposition.first][newposition.second] == 'E')) {
                    return time + 1;
                }
                if((newposition.first >= 0) && (newposition.first < n) && (newposition.second >= 0) && (newposition.second < m) && (arr[newposition.first][newposition.second] != '#') && (!mp[newposition])   ) {
                    mp[newposition]++;
                    q.push(newposition);
                }
            }
        }
        time++;
    }
    return Nofind;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n, m, T = 0, sum = 0;
    bool flag = true;
    cin >> k >> n >> m;
    vector<pair<int, int>> plies;
    vector<vector<vector<char>>> arr(k, vector<vector<char>>(n, vector<char>(m)));
    for(int i = 0;i < k;i++) {
        for(int j = 0;j < n;j++) {
            for(int k = 0;k < m;k++) {
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 'S' || arr[i][j][k] == 't') plies.push_back({j, k});
            }
        }
        if(!flag) continue;
        int tmp = findnum(arr[i], plies[i], n, m);
        if(tmp != Nofind) {
            sum += tmp;
        }
        else {
            flag = false;
        }
        
    }
    if(flag) cout << sum << endl;
    else cout << "Trapped Maze!!!" << endl;
    return 0;
}
