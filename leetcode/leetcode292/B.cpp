#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0, cnt;
    unordered_map<TreeNode*, int> mpc, mpn;
    int cal(TreeNode* r) {
        if(mpc[r]) return mpc[r];
        int sum = r->val;
        if(r->left) {
            // cnt ++;
            sum += cal(r->left);
        }
        if(r->right) {
            // cnt ++;
            sum += cal(r->right);
        }
        mpc[r] = sum;
        return sum;
    }
    int calnum(TreeNode* r) {
        if(mpn[r]) return mpn[r];
        int num = 1;
        if(r->left) {
            num = num + calnum(r->left);
        }
        if(r->right) {
            num = num + calnum(r->right);
        }
        mpn[r] = num;
        return num;
    }
    void dfs(TreeNode* r) {
        if(r) {
            cnt = 1;
            if(r->val == cal(r) / calnum(r)) {
                ans ++;
            }    
            dfs(r->left);
            dfs(r->right);
        }
    }
    int averageOfSubtree(TreeNode* root) {
        // int ans = 0;
        dfs(root);
        return ans;
    }
};