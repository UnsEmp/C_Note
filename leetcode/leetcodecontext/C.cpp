#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    const int N = 1e5 + 10;
class Solution {
public:

    using ll = long long;

    // vector<ll> a(N), tree(N), mark(N);
    // int a[N]
    int tree[N], mark[N];
    ll n, m;
    void build(ll l, ll r, ll p) {
        if(l >= r) {
            tree[p] = 0;
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
            tree[p * 2] = (mid - s + 1) * mark[p], tree[p * 2 + 1] = (t - mid) * mark[p];
            mark[p * 2] = mark[p], mark[p * 2 + 1] = mark[p];
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
            tree[p * 2] = (mid - s + 1) * mark[p], tree[p * 2 + 1] = (t - mid) * mark[p];
            mark[p * 2] = mark[p], mark[p * 2 + 1] = mark[p];
            mark[p] = 0;
        }
        ll sum = 0;
        if(l <= mid) sum += getsum(l, r, s, mid, p * 2);
        if(mid < r) sum += getsum(l, r, mid + 1, t, p * 2 + 1);
        return sum; 
    }
    vector<int> arr;
    void dfs(TreeNode* root) {
        if(root) {
            dfs(root->left);
            arr.push_back(root->val);
            dfs(root->right);
        }
    }
    // void print() {
    //     for(int i = 1;i <= n;++i) cout << tree[i] << " ";
    //     cout << "\n";
    // }
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        int n = arr.size(), ans = 0;
        memset(tree, 0, sizeof tree);
        memset(mark, 0, sizeof mark);
        for(int i = 0;i < ops.size();++i) {
            int l = ops[i][1], r = ops[i][2];
            int a = lower_bound(arr.begin(), arr.end(), l) - arr.begin() + 1, b = lower_bound(arr.begin(), arr.end(), r) - arr.begin() + 1;
            if(ops[i][0] == 1) update(a, b, 1, 1, n, 1);
            else update(a, b, 0, 1, n, 1);
            for(int j = 1;j <= n;++j) cout << getsum(j, j, 1, n, 1) << " ";
            cout << "\n";
        }
        for(int i = 1;i <= n;++i) {
            if(getsum(i, i, 1, n, 1) == 1) ans ++;
        }
        // cout << "ok";
        return ans;
    }
};