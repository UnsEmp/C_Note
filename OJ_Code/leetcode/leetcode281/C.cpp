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
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                if(nums[i] == nums[j] && (i * j) % k == 0) ans ++; 
            }
        }
        return ans;
    }
};

class Solution {
public:
    priority_queue<char> q;
    string ans, res;
    unordered_map<char, int> mp;
    void add(string & res, int & top, int & repeatLimit) {
        unordered_map<char, int> sign;
        while(top < res.size()) {
            if(sign[res[top]] < repeatLimit) {
                sign[res[top]] ++;
                ans += res[top++];
            }
            else {
                break;
            }
        }
    }
    string repeatLimitedString(string s, int repeatLimit) {
        
        for(int i = 0;i < s.size();i++) q.push(s[i]);
        int top = 0;
        while(!q.empty()) {
            auto t = q.top();
            q.pop();
            mp[t] ++;
            if(mp[t] < repeatLimit) {
                if(top < res.size()) {
                    add(res, top, repeatLimit);
                }
                ans += t;
            }
            else {
                res += t;
            }

        }
        return ans;
    }
};




int main() {
    int n;
    cout << 5555555550 / 90 << endl;
    return 0;
}

