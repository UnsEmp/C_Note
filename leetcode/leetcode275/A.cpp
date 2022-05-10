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
    int ans = 0;
    unordered_map<int, int> s, x;
    bool check(vector<int> & nums, int idx) {
        int i = idx - 1, j = idx + 1;
        int n = nums.size();
        while(i >= 0 && nums[i] == nums[idx]) i--;
        while(j < n && nums[j] == nums[idx]) j++;
        // cout << i << " " << j << "\n";
        if(i >= 0 && j < n && ((nums[idx] < nums[i] && nums[idx] < nums[j]))) {
            if(!x[i]) {
                x[i] ++;
                ans ++;
            }
        }
        else if(i >= 0 && j < n && (nums[idx] > nums[i] && nums[idx] > nums[j])) {
            if(!s[i]) {
                s[i] ++;
                ans ++;
            }
        }
        else return false;
    }
};


#define mod 1000000007
class Solution {
public:
    vector<vector<int>> ca = vector<vector<int>>(110, vector<int>(110, -1));
    int dfs(vector<int> & locations, int start, int finish, int fuel, int n) {
        if(ca[start][fuel] != -1) return ca[start][fuel];

        int need = abs(locations[start] - locations[finish]);
        
        if(need > fuel) {
            ca[start][fuel] = 0;
            return 0;
        }
        int sum = 0;
        if(start == finish) sum ++;
        for(int i = 0;i < n;++i) {
            if(i != start) {
                if(abs(locations[start] - locations[i]) <= fuel) {
                    sum += dfs(locations, i, finish, fuel - abs(locations[start] - locations[i]), n);
                    sum %= mod;
                }   
            }
        } 
        ca[start][fuel] = sum;
        return sum;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        return dfs(locations, start, finish, fuel, n);
        // return ans;
    }
};