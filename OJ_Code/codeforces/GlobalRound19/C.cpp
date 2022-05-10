#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int ,int>;
using VI = vector<int>;
using VII = vector<vector<int>>;
using VL = vector<ll>;
using VLL = vector<vector<ll>>;


template <typename T, typename W>
vector<int> KMP(T &p, T &s, W m, W n) {
    unordered_map<W, W> ne;
    vector<W> ans;
    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m - 1)
        {
            // cout << i - j << ' ';
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

const int N = 1e5 + 10;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        ll n;
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        ll sumeve = 0, sumodd = 0, count = 0, numeve = 0, numodd = 0;
        for(int i = 1;i < n - 1;i++) {
            if(a[i] == 0) continue;
            if(a[i] % 2 == 0) {
                count += a[i] / 2;
                sumeve += a[i];
                numeve ++;
            }
            else {
                count += a[i] / 2;
                sumodd += a[i] - (a[i] % 2);
                numodd ++;
            }
        }
        if(sumodd >= numodd - 1) {
            numodd = 1;
            numeve += sumodd;
            sumeve += sumodd * 2;
        } 
        else {
            numodd -= sumodd / 2;
            numeve += sumodd;
            sumeve += sumodd * 2;
        }
        if(sumeve >= numodd) {
            cout << sumeve / 2 + numodd << "\n";
        }
        else {
            cout << "-1" << "\n";
        }

    }
    return 0;
}