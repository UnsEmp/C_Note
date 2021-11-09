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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        vector<int> ans;
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
        int point = 1;
        for(int i = 1;i < arr.size() - 1;i++) {
           if((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
               ans.push_back(point++);
               // cout << arr[i] << endl;
           }
        }
        if(ans.size() < 2) return {-1, -1};
        int Mindistance = INT_MIN;
        for(int i = 1;i < ans.size();i++) Mindistance = min(Mindistance, ans[i] - ans[i - 1]);
        return {Mindistance, ans[ans.size() - 1] - ans[0]};
    }
};

int main() {
    return 0;
}