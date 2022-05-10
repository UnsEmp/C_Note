#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;




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
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 != 0) return {};
        vector<long long> ans;
        long long n = 2;
        while(finalSum >= n) {
            ans.push_back(n);
            finalSum -= n;
            n += 2;
        }
        if(finalSum > 0) ans.back() += finalSum;
        return ans;
    }
};


int main() {
    int n;
    cout << 5555555550 / 90 << endl;
    return 0;
}

