#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int SumMoney = 0;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        for(int i = 0;i < n;i++) {
            SumMoney += (price[i] * needs[i]);
        }
        for(int i = 0;i < special.size();i++) {
            dfs(price, special, needs, n, i, 0);
        }
        return SumMoney;
    }
    bool judge(vector<int> & need, vector<vector<int>> special, int index) {
        for(int i = 0;i < special[index].size() - 1;i++) {
            if(need[i] - special[index][i] < 0) return false;
        }
        for(int i = 0;i < special[index].size() - 1;i++) {
            need[i] -= special[index][i];
        }
        return true;
    }

    void dfs(vector<int> price, vector<vector<int>> special, vector<int> needs, int n, int index, int MaxMoney) {
        if(index >= special.size()) return ;
        if(!judge(needs, special, index)) {
            for(int i = 0;i < needs.size();i++) {
                MaxMoney += needs[i] * price[i];
            }
            SumMoney = min(SumMoney, MaxMoney);
            return ;
        }
        // for(int i = index;i < special.size();i++) {
            dfs(price, special, needs, n, index, MaxMoney + special[index][n]);
            dfs(price, special, needs, n, index + 1, MaxMoney + special[index][n]);
        // }
    }
};

int main() {
    Solution so;
    vector<int> price = {2,5};
    vector<vector<int>> special = {{3,0,5}, {1,2,10}};
    vector<int> needs = {3,2};
    cout << so.shoppingOffers(price, special, needs) << endl;
    return 0;
}