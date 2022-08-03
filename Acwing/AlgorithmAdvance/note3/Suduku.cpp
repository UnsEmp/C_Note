#include <iostream>
#include <cstring>
using namespace std;
const int N = 9;
int col[N], row[N], cnt[N];
int ones[1 << N], mp[1 << N];
int sum;
int x, y, z, t, p;
string s;

int lowerbit(int x) {
    return x & -x;
}

void init() {
    sum = 0;
    for(int i = 0;i < N;++i) col[i] = row[i] = cnt[i] = (1 << N) - 1;
    for(int i = 0;i < 1 << N;++i) {
        int s = 0;
        for(int j = i;j;j -= lowerbit(j)) s++;
        ones[i] = s;
    }
    for(int i = 0;i < N;++i) mp[1 << i] = i;
}

int get(int x, int y) {
    return row[x] & col[y] & cnt[x / 3 * 3 + y / 3];
}

bool dfs(int count) {
    if(count == sum) {
        return true;
    }


    int x, y, z = 10, t, p;
    for(int i = 0;i < N;++i) {
        for(int j = 0;j < N;++j) {
            if(s[i * 9 + j] != '.') continue; 
            int t = ones[get(i, j)];
            if(z > t) {
                z = t;
                x = i, y = j;
            }
        }
    }
    for(int i = get(x, y);i;i -= lowerbit(i)) {
        t = mp[lowerbit(i)], p = x / 3 * 3 + y / 3;
        row[x] -= (1 << t);
        col[y] -= (1 << t);
        cnt[p] -= (1 << t);
        s[x * 9 + y] = '1' + t;
        if(dfs(count + 1)) return true;

        s[x * 9 + y] = '.';
        row[x] += (1 << t);
        col[y] += (1 << t);
        cnt[p] += (1 << t);
    }

    return false;
}


int main() {
    while(cin >> s, s != "end") {
        init();

        for(int i = 0;i < N;++i) {
            for(int j = 0;j < N;++j) {
                int t = i * 9 + j;
                if(s[t] != '.') {
                    int u = s[t] - '1';
                    row[i] -= (1 << u);
                    col[j] -= (1 << u);
                    cnt[i / 3 * 3 + j / 3] -= (1 << u);

                }
                else sum ++;
            }
        }
        dfs(0);
        cout << s << "\n";
    }
    return 0;
}