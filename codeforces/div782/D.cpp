#include <bits/stdc++.h>
using namespace std;



using ll = long long;
class Solution {
public:
    
    vector<ll> a, tree, mark;
    ll n, m;
    void build(ll l, ll r, ll p) {
        if(l >= r) {
            tree[p] = a[l];
            return ;
        }
        ll mid = l + (r - l) / 2;
        build(l, mid, p * 2), build(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2 + 1] + tree[p * 2];
    }

    void update(ll l, ll r, ll c, ll s, ll t, ll p) {
        if(l <= s && t <= r) {
            tree[p] += (t - s + 1) * c, mark[p] += c; 
            return ;
        }
        ll mid = s + (t - s) / 2;
        if(mark[p]) {
            tree[p * 2] += (mid - s + 1) * mark[p], tree[p * 2 + 1] += (t - mid) * mark[p];
            mark[p * 2] += mark[p], mark[p * 2 + 1] += mark[p];
            mark[p] = 0;
        }
        if(l <= mid) update(l, r, c, s, mid, p * 2);
        if(mid < r) update(l, r, c, mid + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    ll getsum(ll l, ll r, ll s, ll t, ll p) {
        if(l <= s && t <= r) {
            return tree[p];
        }
        ll mid = s + (t - s) / 2;
        if(mark[p]) {
            tree[p * 2] += (mid - s + 1) * mark[p], tree[p * 2 + 1] += (t - mid) * mark[p];
            mark[p * 2] += mark[p], mark[p * 2 + 1] += mark[p];
            mark[p] = 0;
        }
        ll sum = 0;
        if(l <= mid) sum += getsum(l, r, s, mid, p * 2);
        if(mid < r) sum += getsum(l, r, mid + 1, t, p * 2 + 1);
        return sum; 
    }


    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        n = flowers.size();
        a.resize(n + 1);
        tree.resize((n + 1) << 2);
        mark.resize((n + 1) << 2);
        fill(a.begin() ,a.end(), 0);
        fill(tree.begin(), tree.end(), 0);
        fill(mark.begin() ,mark.end(), 0);
        build(1, n, 1);
        vector<int> ans;
        for(int i = 0;i < n;++i) {
            update(flowers[i][0], flowers[i][1], 1, 1, n, 1);
        }
        for(int i = 0;i < persons.size();++i) {
            ans.push_back(getsum(persons[i], persons[i], 1, n, 1));
        }
        return ans;
    }
};