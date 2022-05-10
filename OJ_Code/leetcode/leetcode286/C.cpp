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


class Solution {
public:
    long long query(int k, int len) {
        long long sum = 0;
        vector<long long> arr(len);
        if(len >= 2) {
            arr[0] ++;
            arr[len - 1] ++;
            k --;
        }
        
        for(int i = len / 2;i < len && k;++i) {
            arr[i] += (k % 10);
            k /= 10;    
        }
        // cout << arr[len - 1] << "\n";
        if(k || arr[len - 1] > 9) return -1;
        int l = 0, r = len - 1;
        while(l < r) {
            arr[l++] = arr[r--];
        }
        for(int i = 0;i < len;++i) {
            sum = sum * 10 + arr[i];
        }
        return sum;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        for(int i = 0;i < queries.size();++i) {
            ans.push_back(query(queries[i], intLength));
        } 
        return ans;
    }
};