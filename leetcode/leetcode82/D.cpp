#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 10;
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int th) {
        int n = nums.size();
        int left[n], right[n];
        stack<int> st;
        for(int i = 0;i < n;++i) {
            while(st.size() && nums[i] <= nums[st.top()]) st.pop();
            left[i] = st.size()?st.top() - 1:-1;
            st.push(i);
        }
        stack<int> ().swap(st);
        for(int i = n - 1;i >= 0;--i) {
            while(st.size() && nums[i] <= nums[st.top()]) st.pop();
            right[i] = st.size()?st.top() + 1:n;
            st.push(i);
        }

        // for(int i = 0;i < n;++i) cout << left[i] << " ";
        // cout << "\n";

        // for(int i = 0;i < n;++i) cout << right[i] << " ";
        // cout << "\n";
        
        for(int i = 0;i < n;++i) {
            int l = left[i], r = right[i];
            int k = (r - l - 1);
            if(nums[i] > th / k) return k;
        }
        return -1;
    }
};