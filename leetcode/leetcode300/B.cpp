#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<int> nums(n * m, - 1);
        // int nums[n * m];
        // memset(nums, -1, sizeof nums);
        int cnt = 0;
        while(head != nullptr) {
            nums[cnt++] = head->val;
            head = head->next;
        }
        int pos = 0;
        vector<vector<int>> a(n, vector<int>(m, -1));
        int x = 0, y = -1;
        while (pos < n * m)
        {
            // cout << pos << "\n";
            while(y<m - 1&&a[x][y+1] == -2)a[x][++y]=nums[pos++];
            while(x<n - 1&&a[x+1][y] == -2)a[++x][y]=nums[pos++];
            while(y>0&&a[x][y-1] == -2)a[x][--y]=nums[pos++];
            while(x>0&&a[x-1][y] == -2)a[--x][y]=nums[pos++];
        }
        return a;
    }
};