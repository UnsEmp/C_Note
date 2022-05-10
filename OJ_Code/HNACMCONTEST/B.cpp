#include <bits/stdc++.h>
using namespace std;

// constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

const int N = 100;
int w, h, n, ex, ey;
bool flag;
vector<vector<char>> arr(N, vector<char>(N));
vector<vector<int>> ans;
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
void dfs(int idx, string & s, int x, int y, int x1, int y1) {
    if(x < 1 || x > h || y < 1 || y > w) return ;
    if(s[idx] != arr[x][y]) return ;
    if(idx >= s.size()) return ;
    if(idx == s.size() - 1 && s[idx] == arr[x][y]) {
        flag = true;
        ex = x, ey = y;
        return ;
    }
    dfs(idx + 1, s, x + x1, y + y1, x1, y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while((cin >> w)) {
        cin >> h;
        map<char, vector<pair<int, int>>> mp;
        for(int i = 1;i <= h;++i) {
            for(int j = 1;j <= w;++j) {
                cin >> arr[i][j];
                mp[arr[i][j]].push_back({i, j});
            }
        }
        cin >> n;
        string s;
        for(int k = 0;k < n;++k) {
            cin >> s;
            for(int i = 0;i < mp[s[0]].size();++i) {
                for(int t = 0;t < 8;++t) {
                    flag = false;
                    dfs(0, s, mp[s[0]][i].first, mp[s[0]][i].second, dir[t][0], dir[t][1]);
                    if(flag) {
                        ans.push_back({mp[s[0]][i].second, mp[s[0]][i].first, ey, ex});
                    }
                }
            }
            sort(ans.begin(), ans.end());
            if(ans.size())
            cout << "(" << ans[0][0] << "," << ans[0][1] << ")->" << "(" << ans[0][2] << "," << ans[0][3] << ")" << "\n";
            ans.clear();
        }
    }
    return 0;
}