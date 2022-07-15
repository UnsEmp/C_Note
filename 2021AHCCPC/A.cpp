#include <bits/stdc++.h>
using namespace std;
const int inf = -0x3f3f3f3f;

vector<vector<int>> id;
int f[101][101][101];
int n;
void init() {
    for(int i = 0;i <= 7;++i) {
        for(int j = 0;j <= 7;++j) {
            for(int k = 0;k <= 7;++k) {
                if(!i  && !j && !k) continue;
                if((i + 2 * j + 3 * k) % 7 == 0) {
                    vector<int> arr{i, j, k};
                    id.push_back(arr);
                }
            }
        } 
    }  
}


void solve() {
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0;
    for(int i = 0;i <= x;++i) {
        for(int j = 0;j <= y;++j) {
            for(int k = 0;k <= z;++k) {
                for(int t = 0;t < id.size();++t) {
                    if(i >= id[t][0] && j >= id[t][1] && k >= id[t][2]) {
                        f[i][j][k] = max(f[i][j][k], f[i - id[t][0]][j - id[t][1]][k - id[t][2]] + 1);
                    }
                }
            }
        } 
    }
    if(f[x][y][z] <= 0) cout << "0" << "\n";
    else cout << f[x][y][z] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}