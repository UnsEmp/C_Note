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
class Solution {
public:
    vector<int> arr;
    map<int, TreeNode*> mp;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent(root);
        dfs(target, nullptr, 0, k);
        return arr;
    }
    void parent(TreeNode* root) {
        if(root->left != nullptr) {
            mp[root->left->val] = root;
            parent(root->left);
        }
        if(root->right != nullptr) {
            mp[root->right->val] = root;
            parent(root->right);
        }
    }
    void dfs(TreeNode* target, TreeNode* original, int index, int k) {
        if(target == nullptr) {
            return ;
        }
        if(index == k) {
            arr.emplace_back(target->val);
            return ;
        }
        if(target->left != original) {
            dfs(target->left, target, index + 1, k);
        }
        if(target->right != original) {
            dfs(target->right, target, index + 1, k);
        }
        if(mp[target->val] != original) {
            dfs(mp[target->val], target, index + 1, k);
        }
    }
};