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
            // cout << i - j << ' ';
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

#define eps 1e-6
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q;
        double sum = 0;
        // for()
        for(auto n : nums) {
            q.push((double)n);
            sum += (double)n;
        }
        sum /= 2;
        int count = 0;
        double ans = 0;
        while(ans - sum <= eps) {
            auto t = q.top();
            q.push(t / 2);
            ans += t / 2;
            count ++;
        }
        return count;

    }
};

typedef long long ll;
class Solution {
public:
    vector<ll> arr = vector<ll>(1010);
    ll section(int l, int r) {
        return arr[l + 1] - arr[r];
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        for(int i = 1;i <= n;++i) {
            arr[i] = arr[i - 1] + (floor[i - 1] - '0');
        }
        // for(int i = 1;i <= n;++i) cout << arr[i] << " ";
        ll Max = section(n - 1, 0);
        ll ans = INT_MAX;
        for(int i = 0;i < carpetLen;++i) {
            vector<ll> num;
            int j;
            num.push_back(section(0, i));
            for(j = i + carpetLen;j < n;j += carpetLen) {
                num.push_back(section(j - carpetLen, j));
            }
            num.push_back(section(j - carpetLen, n - 1));
            sort(num.begin(), num.end(), greater<ll>());
            ll res = 0;
            for(int k = 0;k < numCarpets && k < num.size();++k) {
                res += num[k];
            }
            ans = min(ans, Max - res);
        }
        return ans;
    }
};