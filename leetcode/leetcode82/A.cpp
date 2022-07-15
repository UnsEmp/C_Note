#include <bits/stdc++.h>
using namespace std;

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
    bool dfs(TreeNode* root) {
        // if(root) {
            if(root->left && root->right) {
                if(root->val == 2) return dfs(root->left) | dfs(root->right);
                else return dfs(root->left) & dfs(root->right);
            }
            else if(root->left) {
                return dfs(root->left);
            }
            else if(root->right){
                return dfs(root->right);
            }
            else {
                return root->val;
            }
        // }
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};