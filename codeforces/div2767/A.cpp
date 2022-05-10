#include <bits/stdc++.h>
#include <queue>
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

int main() {
    int _;
    cin >> _;
    while(_--) {
        int n;
        cin >> n;
        vector<int> arr1(n);
        vector<int> arr2(n);
        for(int i = 0;i < n;i++) cin >> arr1[i];
        // sort(arr1.begin(), arr1.end());
        for(int i = 0;i < n;i++) {
            cin >> arr2[i];

        }
        for(int i = n - 1;i >= 0;i--) {
            if(arr1[i] > arr2[i]) swap(arr1[i], arr2[i]);
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        cout << arr1[n - 1] * arr2[n - 1] << endl;;
    }
    return 0;
}