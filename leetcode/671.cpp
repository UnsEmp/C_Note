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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> nums;
        map<int, int> mp;
        q.push(root);
        while(!q.empty()) {
            TreeNode *r = q.front();
            q.pop();
            if(!mp[r->val]) {
                nums.push_back(r->val);
                mp[r->val]++;
            }
            if(r->left != nullptr) {
                q.push(r->left);
                q.push(r->right);
            }
            
        }
        sort(nums.begin(), nums.end());
        if(nums.size() == 1)
            return -1;
        return nums[1];
    }
};