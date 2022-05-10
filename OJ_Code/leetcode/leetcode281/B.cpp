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
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}


class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                if(nums[i] == nums[j] && (i * j) % k == 0) ans ++; 
            }
        }
        return ans;
    }
};



//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1, *p2;
        // if(head->val == 0) head = head->nextf;
        p1 = p2 = head;
        while(p2) {
            if(p2->val == 0) {
                p1 = p2;
            }
            else {
                p1->val += p2->val;
            }
            p2->next;
        }
        return head;

    }
};
