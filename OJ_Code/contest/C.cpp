#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char op[4] = {'+', '-', '^'};
    int minimumOperations(vector<int>& nums, int start, int goal) {
        long long st = start, go = goal;
        queue<long long> q;
        int n = nums.size();
        unordered_map<long long , long long> mp;
        mp[st]++;
        q.push(st);
        int step = 0;
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0;i < len;i++) {
                long long tmp = q.front();
                // cout << tmp << endl;
                if(tmp == go) return step;
                q.pop();

                for(int i = 0;i < n;i++) {
                    for(int j = 0;j < 3;j++) {
                        long long num;
                        // if(abs(go - tmp) < abs(go - (tmp + nums[i])) && op[j] == '+') continue;
                        // if(abs(go - tmp) < abs(go - (tmp - nums[i])) && op[j] == '-') continue;
                        // if(nums[i] > 0 && tmp > 0) {
                        //     if(tmp > go && nums[i] == '^') continue;
                        // }
                        // else {
                        //     if(tmp )
                        // }
                        // if(tmp > go && nums[i] > tmp && tmp > 0 )
                        switch(op[j]) {
                            case '+':num = tmp + nums[i];break;
                            case '-':num = tmp - nums[i];break;
                            case '^':num = tmp ^ nums[i];break;
                        }
                        if(!mp[num]) {
                            q.push(num);
                            mp[num]++;
                        }
                    }
                }
            }
            step++;
            if(step >= 1000) return -1;
        }
        return -1;
    }
};


int main() {
    return 0;
}