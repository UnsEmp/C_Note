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



class DiscountSystem {
public:
    struct Node {
        int actId;
        int priceLimit;
        int discount;
        int number;
        int userLimit;
    };
    map<int, Node> mp;
    map<pair<int, int>, int> sign;
    unordered_map<int, int> usernum;
    DiscountSystem() {

    }
    
    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
        Node N;
        N.actId = actId, N.discount = discount, N.number = number, N.userLimit = userLimit, N.priceLimit = priceLimit;
        mp[actId] = N;
    }
    
    void removeActivity(int actId) {
        mp.erase(mp.find(actId));
    }
    
    int consume(int userId, int cost) {
        int ans = cost, id = -1;
        for(auto m : mp) {
            // cout << m.first << "\n";
            cout << cost << " " << m.second.priceLimit << "\n";
            if(cost >= m.second.priceLimit && sign[{userId, m.first}] < m.second.userLimit && m.second.number > 0) {
                if(ans > (cost - m.second.discount)) {
                    id = m.first;
                    ans = cost - m.second.discount;
                    // cout << ans << endl;
                }
            }
        }
        // cout << id << "\n";
        if(id == -1) return cost;
        // if(!usernum[userId]) {
        //     usernum[userId] ++;
            mp[id].number --;
        // }
        sign[{userId, id}] ++;
        return ans;
    }
};

/**
 * Your DiscountSystem object will be instantiated and called as such:
 * DiscountSystem* obj = new DiscountSystem();
 * obj->addActivity(actId,priceLimit,discount,number,userLimit);
 * obj->removeActivity(actId);
 * int param_3 = obj->consume(userId,cost);
 */